# include <aleph.H>
# include "local_access_point.H"
# include "local_message_header.H"
# include "locator_calls.H"
# include "basic_defs.H"

# define NO_OF_SERVICES 17

Local_Access_Point * clt_services_access;

Local_Access_Point * srv_services_access;

void bootstrap_services()
{
  Local_Locator      services_locator("/tmp/.locatorPath");

  static Local_Access_Point clt_sa(services_locator, NO_OF_SERVICES);
   
  static Local_Access_Point srv_sa(services_locator, NO_OF_SERVICES);
 
  clt_services_access = &clt_sa;

  srv_services_access = &srv_sa;
  
  // The separation of services in client and server is due to the 
  // need to have two different threads: one for invocations (references) and
  // the other for receiving invocations (objects) in the same container.

  // Registering of services with server perspective.
  srv_services_access->
    add_service(REGISTER_CONTAINER, "register container");
  srv_services_access->
    add_service(UNREGISTER_CONTAINER, "unregister container");
  srv_services_access->
    add_service(REGISTER_OBJECT, "register object");
  srv_services_access->
    add_service(UNREGISTER_OBJECT, "unregister object");
  srv_services_access->
    add_service(LOCATOR_SUPER_RECEIVE, "locator super receive");
  srv_services_access->
    add_service(SERVER_INVOKE_REPLY, "server invoke reply");
  
  // Registering of services with client perspective.
  clt_services_access->
    add_service(GET_SITE_ID, "get site id");
  clt_services_access->
    add_service(TARGET_REG_MIG_OBJECT, "target reg mig object");
  clt_services_access->
    add_service(SOURCE_UNREG_MIG_OBJECT, "source unreg mig object");
  clt_services_access->
    add_service(TARGET_REG_MIG_CONTAINER, "target reg mig container");
  clt_services_access->
    add_service(SOURCE_UNREG_MIG_CONTAINER, "source reg mig container");
  clt_services_access->
    add_service(STRONG_LOCATE, "strong locate");
  clt_services_access->
    add_service(WEAK_LOCATE, "weak locate");
  clt_services_access->
    add_service(IMPLICIT_LOCATE, "implicit locate");
  clt_services_access->
    add_service(CLIENT_INVOKE_SEND, "client invoke send");
  clt_services_access->
    add_service(TEST_OBJECT_LOCATION, "test object location");
  clt_services_access->
    add_service(PING_N_OBJECTS, "ping n objects");
}

Locator_Call_Exit_Code get_site_id(Site_Id & site_id)
throw(std::exception)
{
  Site_Id_CallMsg      entry_msg;
  Site_Id_RetMsg       reply_msg;
  
  clt_services_access->send(&entry_msg);
  clt_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  site_id = reply_msg.get_site_id();

  return static_cast<Locator_Call_Exit_Code>(reply_msg.get_response_code());
}

void register_cnt(Container_Id & cnt_id) 
  throw (std::exception, Duplicated, Panic)
{
  Register_Cnt_CallMsg entry_msg;
  Register_Cnt_RetMsg  reply_msg;
  
  srv_services_access->send(&entry_msg);
  srv_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  cnt_id = reply_msg.get_container_id();
  
  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      // everything went ok
      break;
    case LOCEXIT_INTENDED_DUPLICATION:
      Static_Throw (Duplicated) ();
      break;
    default:
      Static_Throw (Panic) ();
    }
}


void  unregister_cnt(const Container_Id & cnt_id)
  throw (std::exception, NotFound, RefusedService, Panic)
{
  Unregister_Cnt_CallMsg entry_msg(cnt_id);
  Unregister_Cnt_RetMsg  reply_msg;
  
  srv_services_access->send(&entry_msg);
  srv_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      // everything went ok
      break;
    case LOCEXIT_CONTAINER_UNKNOWN:
      Static_Throw (NotFound) ();
      break;
    case LOCEXIT_CONTAINER_STILL_WORKING:
      Static_Throw (RefusedService) ();
      break;
    default:
      Static_Throw (Panic) ();
    }
}


void register_obj(Object_Id & obj_id, const Container_Id & cnt_id) 
  throw(std::exception, Duplicated, NotFound, Panic)
{
  Register_Obj_CallMsg entry_msg(cnt_id);
  Register_Obj_RetMsg  reply_msg;
  
  srv_services_access->send(&entry_msg);
  srv_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  obj_id = reply_msg.get_object_id();

  switch ((reply_msg.get_response_code()))
    {
    case LOCEXIT_OK:
      // everything went ok
      break;
    case LOCEXIT_INTENDED_DUPLICATION:
      Static_Throw (Duplicated) ();
      break;
    case LOCEXIT_CONTAINER_UNKNOWN:
      Static_Throw (NotFound) ();
      break;
    default:
      Static_Throw (Panic) ();
    }
}


void unregister_obj(const Object_Id & obj_id) 
  throw(std::exception, NotFound, RefusedService, Panic)
{ 
  Unregister_Obj_CallMsg entry_msg(obj_id);
  Unregister_Obj_RetMsg  reply_msg;
  
  srv_services_access->send(&entry_msg);
  srv_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      // everything went ok
      break;
    case LOCEXIT_OBJECT_UNKNOWN:
      Static_Throw (NotFound) ();
      break;
    case LOCEXIT_OBJECT_BUSY:
      Static_Throw (RefusedService) ();
      break;
    default:
      Static_Throw (Panic) ();
    }
}


void tgt_reg_mig_obj(const Object_Id & obj_id, 
		     const Container_Id & cnt_id,
		     const Logical_Timestamp new_timestamp) 
  throw(std::exception, NotFound, Duplicated, Panic)
{
  Tgt_Reg_Mig_Obj_CallMsg entry_msg(obj_id, cnt_id, new_timestamp);
  Tgt_Reg_Mig_Obj_RetMsg  reply_msg;

  clt_services_access->send(&entry_msg);
  clt_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      // everything went ok
      break;
    case LOCEXIT_INTENDED_DUPLICATION:
      Static_Throw (Duplicated) ();
      break;
    case LOCEXIT_CONTAINER_UNKNOWN:
      Static_Throw (NotFound) ();
    default:
      Static_Throw (Panic) ();
    }
}

void src_unreg_mig_obj(const Object_Id & obj_id, const Site_Id & tgt_site_id) 
  throw(std::exception, NotFound, ObjectBusy, Panic)
{
  Src_Unreg_Mig_Obj_CallMsg entry_msg(obj_id, tgt_site_id);
  Src_Unreg_Mig_Obj_RetMsg  reply_msg;

  clt_services_access->send(&entry_msg);
  clt_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      // everything went ok
      break;
    case LOCEXIT_OBJECT_UNKNOWN:
      Static_Throw (NotFound) ();
      break;
    case LOCEXIT_OBJECT_BUSY:
      Static_Throw (ObjectBusy) ();
    default:
      Static_Throw (Panic) ();
    }
}

void tgt_reg_mig_cnt(const Container_Id & cnt_id)
  throw(std::exception, Duplicated, Panic)
{
  Static_Throw(Panic) ();
}

void src_unreg_mig_cnt(const Container_Id & cnt_id, 
		       const Site_Id & tgt_site_id) 
  throw(std::exception, NotFound, RefusedService, Panic)
{ 
  Static_Throw(Panic) ();
}

Message_Id clt_invoke_send(Binding & binding, 
			   const void * request, 
			   size_t request_size) 
  throw (std::exception, ObjectDead, Panic)
{
  // Prepare the message in which will travel the invocation
  Clt_Invoke_Send_CallMsg 
    req_msg(binding, request_size);
  
  Clt_Invoke_Send_RetMsg reply_msg;

  // Send the message.
  clt_services_access->send(&req_msg, request, request_size);
  // Get the response for the message just sent.
  clt_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  if (reply_msg.get_response_code() == LOCEXIT_OBJECT_DEAD)
    Static_Throw (ObjectDead)(); 
  
  if (reply_msg.get_response_code() == LOCEXIT_OBJECT_RECENT_BINDING)
    binding.update_locator(reply_msg.get_locator());
    
  // return the message unique identification that will be used lately when
  // the invocation returns.

  return (reply_msg.get_message_id());
}


Message_Id multi_receive(Binding & binding,
			 const Container_Id & receiving_container_id,
			 void * data,
			 size_t & maxima_data_size,
			 Reception_Type & reception_type) 
  throw (std::exception, NotFound, ObjectDead, RecentBinding, Panic)
{
  // Prepare the invocation receive message. It shows the willingness
  // to receive an invocation.
  Locator_Super_Receive_CallMsg entry_msg(maxima_data_size, 
					  binding, 
					  receiving_container_id);
  
  // Send the message.
  srv_services_access->send(&entry_msg);

  // Wait for reply.
  Locator_Super_Receive_RetMsg reply_msg;
  
  srv_services_access->receive(&reply_msg, sizeof(reply_msg), 
			       data, maxima_data_size);
  
  // Compare incomming and waited sizes.
  ASSERT(maxima_data_size >= reply_msg.get_message_size());
  
  maxima_data_size = reply_msg.get_message_size();

  reception_type = reply_msg.get_reception_type(); 
  
  // Updating the binding, so that when replying the answer is
  // directed exactly to where it came from.
  binding = reply_msg.get_binding();

  if (reception_type == RECTYPE_INVOCATION_REPLY)
    switch (reply_msg.get_response_code())
      {
      case LOCEXIT_OK:
	break;
      case LOCEXIT_OBJECT_NOT_FOUND:
	Static_Throw (NotFound) ();
	break;
      case LOCEXIT_OBJECT_DEAD:
	Static_Throw (ObjectDead) ();
	break;
      case LOCEXIT_OBJECT_RECENT_BINDING:
	Static_Throw (RecentBinding) (binding);
	break;
      default:
	Static_Throw (Panic) ();
      }
  else
    switch (reply_msg.get_response_code())
      {
      case LOCEXIT_OK:
	break;
      default:
	Static_Throw (Panic) ();
      }

  return reply_msg.get_message_id();
}



void srv_invoke_reply(const Message_Id & msg_id, 
		      const Binding & binding,
		      const Container_Id & replying_cnt_id,
		      const void * reply,  
		      size_t reply_size) 
  throw (std::exception, Panic)
{
  // Prepare the reply message.
  Srv_Invoke_Reply_CallMsg 
    rep_msg(msg_id, binding, replying_cnt_id, reply_size);
  
  // Send the message.
  srv_services_access->send(&rep_msg, reply, reply_size); 

  // Wait for the message indicating that the sending status.
  Srv_Invoke_Reply_RetMsg  reply_msg;

  srv_services_access->receive(&reply_msg, sizeof(reply_msg));

  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      break;
    default:
      Static_Throw (Panic) ();
    }
}


Locator strong_locate(const Object_Id & obj_id)
  throw(std::exception, ObjectDead, Panic)
{
  Strong_Locate_CallMsg entry_msg(obj_id);
  Strong_Locate_RetMsg  reply_msg;
  
  clt_services_access->send(&entry_msg);

  clt_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      break;
    case LOCEXIT_OBJECT_NOT_FOUND:
      Static_Throw (Panic)();
      break;
    case LOCEXIT_OBJECT_DEAD:
      Static_Throw (ObjectDead)();
      break;
    case LOCEXIT_OBJECT_RECENT_BINDING:
      break;
    default:
      Static_Throw (Panic)();
    }

  return reply_msg.get_locator();
}

Locator weak_locate(const Object_Id & obj_id)
  throw(std::exception, NotFound, ObjectDead, Panic)
{
  Weak_Locate_CallMsg entry_msg(obj_id);
  Weak_Locate_RetMsg  reply_msg;
  
  clt_services_access->send(&entry_msg);
  
  clt_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      break;
    case LOCEXIT_OBJECT_NOT_FOUND:
      Static_Throw (NotFound)();
      break;
    case LOCEXIT_OBJECT_DEAD:
      Static_Throw (ObjectDead)();
      break;
    case LOCEXIT_OBJECT_RECENT_BINDING:
      break;
    default:
      Static_Throw (Panic)();
    }
  
  return reply_msg.get_locator();
}

void implicit_locate(const Binding & old_binding) 
  throw (std::exception, Panic)
{
  Implicit_Locate_CallMsg entry_msg(old_binding);
  Implicit_Locate_RetMsg  reply_msg;
  
  clt_services_access->send(&entry_msg);
  clt_services_access->receive(&reply_msg, sizeof(reply_msg));
  
  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      break;
    default:
      Static_Throw (Panic) ();
    }
}



void test_location(Locator & locator)
  throw (std::exception, NotFound, ObjectDead, Panic)
{  
  Test_Object_Location_CallMsg entry_msg(locator);

  Test_Object_Location_RetMsg  reply_msg;
  
  clt_services_access->send(&entry_msg);

  clt_services_access->receive(&reply_msg, sizeof(reply_msg));

  switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      locator = reply_msg.get_new_locator();
      break;
    case LOCEXIT_OBJECT_NOT_FOUND:
      Static_Throw (NotFound)();
      break;
    case LOCEXIT_OBJECT_DEAD:
      Static_Throw (ObjectDead)();
      break;
    case LOCEXIT_OBJECT_RECENT_BINDING:
      MESSAGE("Object has a more recent binding!");
      locator = reply_msg.get_new_locator();
      break;
    default:
      Static_Throw (Panic)();
    }
}


void ping(unsigned int number_of_entries, const Cache_Update_Policy policy)
   throw (std::exception, NotFound, Panic)
 {
   Ping_N_Objects_CallMsg entry_msg(number_of_entries, policy);
   Ping_N_Objects_RetMsg reply_msg;

   clt_services_access->send(&entry_msg);

   clt_services_access->receive(&reply_msg, sizeof(reply_msg));

   switch (reply_msg.get_response_code())
    {
    case LOCEXIT_OK:
      break;
    case LOCEXIT_OBJECT_NOT_FOUND:
      Static_Throw (NotFound) ();
      break;
    default:
      Static_Throw (Panic) ();
    }
}



