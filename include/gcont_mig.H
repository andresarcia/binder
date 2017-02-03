#ifndef CONT_MIG_H
#define CONT_MIG_H


enum Migration_Services
{
  MIGRATION_TGT_REG,
  MIGRATION_SRC_UNREG,
  MIGRATION_ENABLE_TGT_OBJECT,

  MIGRATION_LAST
};

class Do_Tgt_Registration : public Msg_Entry_Header
{
  Object_Id object_id;
  Container_Id container_id;
  Logical_Timestamp logical_timestamp;

public:

  Do_Tgt_Registration(const Object_Id & _object_id,
		      const Container_Id & _container_id,
		      Logical_Timestamp _logical_timestamp) :
    Msg_Entry_Header(MIGRATION_TGT_REG, sizeof(*this)),
    object_id(_object_id),
    container_id(_container_id),
    logical_timestamp(_logical_timestamp)
  {
    // empty
  }  

  const Object_Id & get_object_id() const
  {
    return object_id;
  }

  const Container_Id & get_container_id() const
  {
    return container_id;
  }

  const Logical_Timestamp & get_logical_timestamp() const
  {
    return logical_timestamp;
  }
};

class Do_Src_Unregistration : public Msg_Entry_Header
{
  Object_Id object_id;
  Site_Id   tgt_site_id;
  Port      tgt_port;

public:
  Do_Src_Unregistration(const Object_Id & _object_id,
			const Site_Id & _tgt_site_id,
			const Port & _tgt_port) :
    Msg_Entry_Header(MIGRATION_SRC_UNREG, sizeof(*this)),
    object_id(_object_id),
    tgt_site_id(_tgt_site_id),
    tgt_port(_tgt_port)
  {
    // empty
  }
  
  const Object_Id & get_object_id() const
  {
    return object_id;
  }
  
  const Site_Id & get_tgt_site_id() const
  {
    return tgt_site_id;
  }

  const Port & get_tgt_port() const
  {
    return tgt_port;
  }
};

class Enable_Tgt_Object : public Msg_Entry_Header
{
  Object_Id object_id;

public:
  Enable_Tgt_Object(const Object_Id & _obj_id) :
    Msg_Entry_Header(MIGRATION_ENABLE_TGT_OBJECT, sizeof(*this)),
    object_id(_obj_id)
  {
    // empty
  }

  const Object_Id & get_object_id() const 
  {
    return object_id;
  }
};


# define NO_OF_SERVICES 3

class Migration_Service
{
  Remote_Multiserver_Point<Migration_Service> migration_control;

  pthread_t * migration_thread;


  int 
  migration_tgt_reg(Msg_Entry_Header * entry_msg,
		    Remote_Multiserver_Binding<Migration_Service> * return_point)
  {
    CRITICAL_SECTION(&mutex_for_migration);
    
    MESSAGE("*** Migration Tgt ***");
    
    Do_Tgt_Registration * casted_input_msg =
      static_cast<Do_Tgt_Registration *>(entry_msg);
    
    try
      {
	tgt_reg_mig_obj(casted_input_msg->get_object_id(),
			casted_input_msg->get_container_id(),
			casted_input_msg->get_logical_timestamp());
      }
    catch (NotFound)
      {
	ERROR("*** ERROR: The specified container was not found.");
      }
    catch (Duplicated)
      {
	ERROR("*** ERROR: Intended object duplication.");
      }
  
    Do_Src_Unregistration reply_msg(casted_input_msg->get_object_id(),
				    this_site,
				    migration_control.get_port());

# define NOT_ALLOWED_TO_MIGRATE false

    Object_Node * new_obj = AllocNew(*objectAlloc, Object_Node) 
      (casted_input_msg->get_object_id(),
       casted_input_msg->get_logical_timestamp(),
       NOT_ALLOWED_TO_MIGRATE);

# undef NOT_ALLOWED_TO_MIGRATE

    char tmp_string[Uid::stringSize];

    prc_window->
	insert_object(casted_input_msg->get_object_id().
		      getStringUid(tmp_string, Uid::stringSize),
		      new_obj, "-> LLEGANDO",
		      casted_input_msg->get_logical_timestamp());

    objs_list.append(new_obj);

    ++n_objs;

    return_point->rpc_reply(&reply_msg, sizeof(reply_msg));
  
    return 0;
  }


  int migration_src_unreg(Msg_Entry_Header * entry_msg)
  {
    USE_MUTEX(mutex, &mutex_for_migration);

    MESSAGE("*** Migration Src ***");

    Do_Src_Unregistration * casted_input_msg = 
      static_cast<Do_Src_Unregistration *>(entry_msg);

    object_migrating = true;

    mutex.leave();

    bool busy;
  
  loop:
  
    try
      {
	busy = false;
	src_unreg_mig_obj(casted_input_msg->get_object_id(), 
			  casted_input_msg->get_tgt_site_id());
      }
    catch (ObjectBusy)
      {
	busy = true;

	// give time to the object, so that it can finish.
	usleep(get_rand(300000, 450000)); 
      }
    catch (...)
      {
	ERROR("*** ERROR: Inconsistency in the experiment. Probably "
	      "the object was not found.");
      }
  
    if (busy) goto loop;
  
    mutex.enter();

    Object_Node * obj_to_delete = 
      search_elem<Object_Node, Object_Id>
      (objs_list, casted_input_msg->get_object_id());
  
    prc_window->delete_object(obj_to_delete);

    obj_to_delete->del();
  
    AllocDelete(*objectAlloc, obj_to_delete);
  
    --n_objs;
  
    Enable_Tgt_Object enable_msg(casted_input_msg->get_object_id());

    PRINT_PORT(casted_input_msg->get_tgt_port(), "async");

    migration_control.async_send(casted_input_msg->get_tgt_port(),
				 &enable_msg);

    object_migrating = false;

    pthread_cond_signal(&wait_for_unregistration);

    return 0;
  }


  int enable_tgt_object(Msg_Entry_Header * entry_msg) 
  {
    CRITICAL_SECTION(&mutex_for_migration);
  
    MESSAGE("*** *** Enable Object *** ***");

    Enable_Tgt_Object * casted_input_msg =
      static_cast<Enable_Tgt_Object *>(entry_msg);

    Object_Node * obj_to_activate = 
      search_elem<Object_Node, Object_Id>
      (objs_list, casted_input_msg->get_object_id());

    prc_window->change_obj_state(obj_to_activate, "ESPERANDO");
    
    ASSERT(obj_to_activate != NULL);

    obj_to_activate->set_allowed_to_migrate(true);
  
    return 0;
  }


public:
  
  Migration_Service() :
    migration_control(NO_OF_SERVICES, this)
  {
    migration_thread = migration_control.start_deamon();
    
    migration_control.add_service(MIGRATION_TGT_REG, 
				  "migration_tgt_reg", 
				  &Migration_Service::migration_tgt_reg);
    
    migration_control.add_service(MIGRATION_SRC_UNREG, 
				  "migration_src_unreg", 
				  &Migration_Service::migration_src_unreg);
    
    migration_control.add_service(MIGRATION_ENABLE_TGT_OBJECT,
				  "enable_tgt_object", 
				  &Migration_Service::enable_tgt_object);
  }


  void join_migration_service()
  {
    pthread_join(*migration_thread, NULL);
  }  

  Remote_Multiserver_Point<Migration_Service> * get_migration_point() 
  {
    return &migration_control;
  }

  ~Migration_Service()
  {
    // empty
  }
};

# undef NO_OF_SERVICES




# endif // CONT_MIG_H
