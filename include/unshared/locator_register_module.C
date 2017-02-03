# include "locator_local_services.H"
# include "locator_boot.H"
# include "locator_tables.H"
# include "local_message_header.H"
# include "local_reception_point.H"
# include "remote_multiserver_point.H"
# include "remote_message_header.H"
# include "locator_remote_services.H"
# include <useMutex.H>


int local_service_get_site_id(Binding_Point * return_point, 
			      Msg_Entry_Header * input_msg)
{ 
  MESSAGE("*** Get Site Id ***");
  
  Site_Id_RetMsg reply_msg(LOCEXIT_OK, 
			   static_cast<Site_Id>(remote_server_id->get_port()));

  return_point->respond(&reply_msg, sizeof(reply_msg));

  return 0;
}

int local_service_register_cnt(Binding_Point * return_point, 
			       Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Register Container ***");
  
  Register_Cnt_CallMsg * 
    casted_input_msg = static_cast<Register_Cnt_CallMsg *>(input_msg);
  
  Container_Id container_id;

  // This call is to the ipc_deamon to generate the Uid.
  createUid(&container_id);

  // insert container_id into a table indexed by containerID.
  Registered_Container_Bucket * new_bucket, * searched_bucket;

  MESSAGE("sizeof(Registerd_Container_Bucket) = %i",
	  sizeof(Registered_Container_Bucket));

  // find the bucket to see if there is an intended double registration.
  searched_bucket = static_cast<Registered_Container_Bucket *>
    (ptr_registered_container_table->search(container_id));

  Register_Cnt_RetMsg reply(LOCEXIT_OK, container_id);

  if (searched_bucket == NULL)
    {
      MESSAGE("New Container REGISTERED");
      new_bucket = AllocNew(*objectAlloc, Registered_Container_Bucket)
	(container_id, 
	 casted_input_msg->get_pid());

      ptr_registered_container_table->insert(new_bucket); 
    }
  else
    {
      reply.set_response_code(LOCEXIT_INTENDED_DUPLICATION);
    }
 
  return_point->respond(&reply, sizeof(reply));

  return 0;
}

Registered_Object_Bucket * 
container_link_to_object_bucket(Dlink * link_to_container)
{
  Registered_Object_Bucket * object_bucket = 0;

  int object_address;

  int dlink_position = reinterpret_cast<int>
    (&(object_bucket->get_link_to_container()));  

  object_address = (reinterpret_cast<int>(link_to_container) - dlink_position);

  return reinterpret_cast<Registered_Object_Bucket *>(object_address);
}

void delete_entries_from_cache_in(const Object_Id & object_id)
{
  // Delete entries from Cache_In.
  {
    try
      {
	Cache_In::Cache_In_Iterator iter(ptr_cache_in, object_id);
	
	while (iter.delete_current() != NULL);
      }
    catch (NotFound)
      {
	return;
      }           
  } // End of iterator region.
}


void update_caches_with_dead_object(const Object_Id & object_id)
{
  // Write on Cache_Garbage.
  ptr_cache_garbage->insert(object_id);
  
  delete_entries_from_cache_in(object_id);

  try
    {
      ptr_cache_mig->remove(object_id);
    }
  catch (NotFound)
    {
      // empty
    }
}


void
answer_all_pending_replys_and_delete(Registered_Object_Bucket * object_bucket)
{
  Registered_Container_Bucket * container_bucket;
  
  container_bucket = static_cast<Registered_Container_Bucket *>
    (ptr_registered_container_table->
     search(object_bucket->get_associated_container_id())); 

  ASSERT(container_bucket != NULL);

  container_bucket->unLock();
     
  const int ZERO_SIZE = 0;

  // Check if whether the Waiting_Invocation_List is empty.
  if (container_bucket->get_waiting_invocation_list().isEmpty() == false)
    {
      // If it is NOT empty.
      
      // Respond to each of the invocations waiting in line for being served.
      // Remember to include in the response the indication to the state
      // of the object being invoked (DEAD, RECENT_BINDING, NOT_FOUND, ...)
      // For the unregister operation it has to be known whether it was 
      // issued by a pure unregister operation or a src_obj_migrate.
 
#define OBJECT_ID request_msg.get_binding().get_object_id()

      Dnode<Reception_Type> * cursor = 
	container_bucket->get_waiting_invocation_list().getNext();

      while (cursor != &container_bucket->get_waiting_invocation_list())
	{
	  if (cursor->getData() == RECTYPE_INVOCATION_REPLY)
	    {
	      cursor = cursor->getNext();
	      continue;
	    }

	  Invocation_Request_Msg & request_msg = 
	    static_cast<Delayed_Invocation_Node *>(cursor)->
	    get_request_message();
	  
	  if (object_bucket->getKey() == OBJECT_ID)
	    {
	      Invocation_Reply_Type reply_type =
		look_up_in_caches(object_bucket->getKey(), 
				  request_msg.get_binding().get_locator());
	  
	      {
		Invocation_Reply_Msg reply_msg(ZERO_SIZE, 
					       request_msg.get_binding(),
					       request_msg.get_message_id(),
					       reply_type);
		
		remote_reply(request_msg.get_message_id(),
			     &reply_msg, 
			     NULL, 
			     ZERO_SIZE);
	      }

	      cursor = cursor->getNext();

	      AllocDelete(*objectAlloc, 
			  static_cast<Delayed_Invocation_Node*>
			  (cursor->removePrev()));
	    } // END IF 
	  else
	    cursor = cursor->getNext();

	} // END WHILE
    
    }
#undef OBJECT_ID
  
  // Delete object from container list of objects.
  object_bucket->get_link_to_container().del();
  
  // Delete object from Registered_Object_Table.
  if (object_bucket->isLock())
    object_bucket->unLock();
  
  ptr_registered_object_table->remove(object_bucket);
  
  AllocDelete(*objectAlloc, object_bucket);
}



int local_service_unregister_cnt(Binding_Point * return_point, 
				 Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Unregister Container ***");

  CRITICAL_SECTION(&mutex_for_server_fcnt);
    
  Unregister_Cnt_CallMsg * 
    casted_input_msg = static_cast<Unregister_Cnt_CallMsg *>(input_msg);

  // Find the container in the Registered_Container_Table
  Registered_Container_Bucket * 
    searched_bucket = static_cast<Registered_Container_Bucket *>
    (ptr_registered_container_table->
    search(casted_input_msg->get_container_id()));

  if (searched_bucket == NULL)
    {
      Unregister_Cnt_RetMsg return_message(LOCEXIT_CONTAINER_UNKNOWN);
      
      return_point->respond(&return_message, sizeof(return_message));
      
      return 0;
    }

  searched_bucket->unLock();

  if (searched_bucket->get_current_state() != CNT_NOT_RECEIVING)
    {
      // Container can't be moved until all the replys and invocations are
      // completly processed.
      Unregister_Cnt_RetMsg return_message(LOCEXIT_CONTAINER_STILL_WORKING);
      
      return_point->respond(&return_message, sizeof(return_message));

      return 0;
    }

  // Unregister every object associated with this container.
  while (searched_bucket->get_associated_objects_list().isEmpty() == false)
    {
      Registered_Object_Bucket * object_bucket = 
      container_link_to_object_bucket(searched_bucket->
				      get_associated_objects_list().getNext());
      
      update_caches_with_dead_object(object_bucket->getKey());
  
      answer_all_pending_replys_and_delete(object_bucket);

# ifdef WITH_IMPLICIT_MSGS

      Implicit_Death_Anounce_Msg 
	implicit_death(object_bucket->getKey(),
		       static_cast<Site_Id>(remote_server_id->get_port()));

      ptr_implicit_cnt->add_implicit_msg(implicit_death);

# endif
    }

  // Delete container from table
  ptr_registered_container_table->remove(searched_bucket);

  AllocDelete(*objectAlloc, searched_bucket);

  // Respond to local client waiting for the status of the locator_call.
  Unregister_Cnt_RetMsg return_message(LOCEXIT_OK);
  
  return_point->respond(&return_message, sizeof(return_message));
  
  return 0;
}



int local_service_register_obj(Binding_Point * return_point, 
			       Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Register Object ***");
  
  Register_Obj_CallMsg * 
    casted_input_msg = static_cast<Register_Obj_CallMsg *>(input_msg);
  
  // Add the object to the Associated_Object_List to the correspondant 
  // container.

  Registered_Container_Bucket * container_bucket = 
    static_cast<Registered_Container_Bucket *>
    (ptr_registered_container_table->
     search(casted_input_msg->get_container_id()));

  if (container_bucket == NULL)
    {
      MESSAGE("CONTAINER UNKNOWN");
      // container not registered

      Register_Obj_RetMsg reply(LOCEXIT_CONTAINER_UNKNOWN, INVALID_OBJECT_ID);
        
      return_point->respond(&reply, sizeof(reply));
      
      return 0;
    }

  container_bucket->unLock();

  // The container is a valid container. So, proceed to register the
  // object.

  Object_Id object_id;
  
  createUid(&object_id);

  char tmp_string[Uid::stringSize];

  MESSAGE("Object ID: %s", object_id.getStringUid(tmp_string, 
						   Uid::stringSize));
  
  Registered_Object_Bucket * new_bucket, * searched_bucket;
  
  // find the bucket to see if there is an intended double registration.
  searched_bucket = static_cast<Registered_Object_Bucket *>
    (ptr_registered_object_table->search(object_id));
  
  if (searched_bucket == NULL)
    {
      const long long unsigned TIMESTAMP = 0;

      new_bucket = AllocNew(*objectAlloc, Registered_Object_Bucket)
	(object_id,
	 casted_input_msg->get_container_id(),
	 TIMESTAMP);

      MESSAGE("sizeof(Registerd_Object_Bucket) = %i",
	      sizeof(Registered_Object_Bucket));

      ptr_registered_object_table->insert(new_bucket);
    }
  else
    {
      searched_bucket->unLock();

      Register_Obj_RetMsg reply(LOCEXIT_INTENDED_DUPLICATION, 
				INVALID_OBJECT_ID);
            
      return_point->respond(&reply, sizeof(reply));
      
      return 0;
    }
  
  // Insert the object into the container list.
  container_bucket->get_associated_objects_list().
    append(&new_bucket->get_link_to_container());
  
  // If everything is OK...
  Register_Obj_RetMsg reply(LOCEXIT_OK, object_id);
  
  return_point->respond(&reply, sizeof(reply));

  return 0;
}


int local_service_unregister_obj (Binding_Point * return_point, 
				  Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Unregister Object ***");
  
  CRITICAL_SECTION(&mutex_for_server_fcnt);
  
  Unregister_Obj_CallMsg * 
    casted_input_msg = static_cast<Unregister_Obj_CallMsg *>(input_msg);
  
  // Find the object in Registered_Object_Table.
  
  Registered_Object_Bucket * object_bucket;
  
  // Check if the object is busy
  object_bucket = static_cast<Registered_Object_Bucket *>
    (ptr_registered_object_table->
     search(casted_input_msg->get_object_id()));
  
  ASSERT(object_bucket != NULL);
  
  ASSERT(object_bucket->get_current_state() == OBJ_IDLE);

  Unregister_Obj_RetMsg return_message(LOCEXIT_OK);
  
  if (object_bucket == NULL) // object not found, so report it back...
    return_message.set_response_code(LOCEXIT_OBJECT_UNKNOWN);
  else
    {
      update_caches_with_dead_object(casted_input_msg->get_object_id());

      answer_all_pending_replys_and_delete(object_bucket);

# ifdef WITH_IMPLICIT_MSGS

      Implicit_Death_Anounce_Msg 
	implicit_death(casted_input_msg->get_object_id(),
		       static_cast<Site_Id>(remote_server_id->get_port()));

      ptr_implicit_cnt->add_implicit_msg(implicit_death);

# endif
    }
  
  return_point->respond(&return_message, sizeof(return_message));
  
  // TODO: report the event to implicit message module.
  
  return 0;
}


