/*

----------------------------------------------------------------


int local_service_test_object_location (Binding_Point * return_point, 
					Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Test Location Service ***");

  Test_Object_Location_CallMsg * casted_input_msg =
    static_cast<Test_Object_Location_CallMsg *>(input_msg);

  Locator * locator;

  locator = ptr_cache_out->find_data_ptr(casted_input_msg->get_object_id());
  
  ptr_cache_out->cache_unlock();
  

  if (locator != NULL)
    {
      Message_Id msg_id;
      
      createUid(&msg_id);

      Clt_Wait_Resp_Bucket * new_bucket;
      
      new_bucket = AllocNew(*objectAlloc, Clt_Wait_Resp_Bucket) 
	(msg_id, return_point);

      ptr_clt_wait_resp_table->insert(new_bucket);

      Ping_Object_Request ping_msg(msg_id, *locator);

      remote_server_id->rpc_send(locator->get_target_site_id(),
				 &ping_msg,
				 sizeof(ping_msg));
    }
  else
    {
      if (ptr_cache_garbage->
	  find_key(casted_input_msg->get_object_id()) == true)
	{
	  Test_Object_Location_RetMsg response(LOCEXIT_OBJECT_DEAD);
	  
	  ptr_cache_garbage->cache_unlock();

	  return_point->respond(&response, sizeof(response));
	}
      else
	{	  
	  Test_Object_Location_RetMsg response(LOCEXIT_OBJECT_NOT_FOUND);
	  
	  return_point->respond(&response, sizeof(response));
	}
    }
  
  return 0;
}

int remote_service_ping_request (Msg_Entry_Header * input_msg,
				 Remote_Multiserver_Binding * return_point)
{
  MESSAGE("*** Ping Request ***");

  CRITICAL_SECTION(&mutex_for_client_fcnt);
  
  Ping_Object_Request * casted_input_msg =
    static_cast<Ping_Object_Request *>(input_msg);
  
  // find object in registered_object_table
  Registered_Object_Bucket * searched_bucket;
  
#define OBJECT_ID casted_input_msg->get_locator().get_object_id()
  
  searched_bucket = static_cast<Registered_Object_Bucket*>
    (ptr_registered_object_table->search(OBJECT_ID));
  
  Ping_Object_Reply * ping_reply;
  
  if (searched_bucket != NULL)
    {   
      searched_bucket->unLock();
      
      ping_reply = AllocNew(*objectAlloc, Ping_Object_Reply)
	(casted_input_msg->get_message_id(),
	 casted_input_msg->get_locator(), 
	 LOCREPLY_SUCCESS);
    }
  else
    {
      // if not found, then find it in caches: out, mig, new_bnds and garbage.

      Invocation_Reply_Type reply_hdr = 
	look_up_in_caches(OBJECT_ID, casted_input_msg->get_locator());

      ping_reply = AllocNew(*objectAlloc, Ping_Object_Reply)
	(casted_input_msg->get_message_id(),
	 casted_input_msg->get_locator(), 
	 reply_hdr);
    }
  
  return_point->rpc_reply(ping_reply, sizeof(*ping_reply));
  
  AllocDelete(*objectAlloc, ping_reply);
  
  return 0;

#undef OBJECT_ID
}


int remote_service_ping_reply (Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Ping Reply ***");

  UseMutex client_critical_section(&mutex_for_client_fcnt);

  Ping_Object_Reply * casted_input_msg =
    static_cast<Ping_Object_Reply *>(input_msg);
  
  Clt_Wait_Resp_Bucket * searched_bucket =
    static_cast<Clt_Wait_Resp_Bucket *>
    (ptr_clt_wait_resp_table->search(casted_input_msg->get_message_id()));

  ASSERT(searched_bucket != NULL);

  update_caches_with_response(casted_input_msg->get_ping_reply_type(),
			      casted_input_msg->get_locator());
  
  Test_Object_Location_RetMsg  local_reply_msg(LOCEXIT_OK);
		    
  switch (casted_input_msg->get_ping_reply_type())
    {
    case (LOCREPLY_SUCCESS):
      // empty
      break;
    case (LOCREPLY_NOT_FOUND):
      local_reply_msg.set_response_code(LOCEXIT_OBJECT_NOT_FOUND);
      break;
    case (LOCREPLY_DEAD):
      local_reply_msg.set_response_code(LOCEXIT_OBJECT_DEAD);
      break;
    case (LOCREPLY_RECENT_BINDING):
      local_reply_msg.set_response_code(LOCEXIT_OBJECT_RECENT_BINDING);
      break;
    default:
      ERROR("*** Exit message header unknown! ***");
    }
  
  searched_bucket->
    get_return_point()->respond(&local_reply_msg, 
				sizeof(local_reply_msg));

  searched_bucket->unLock();

  ptr_clt_wait_resp_table->remove(searched_bucket);
  
  return 0;
}
*/

 /*
    There will be three types of find messages all grouped into one single
    find message.

    The types are according to the serial protocol of strong finding.

    Stages of the protocol are:
    
    - Stage 1: in which no locator responds to a find request, but the owner
    of the object.

    - Stage 2: in which every locator will be asked for the sought object.
    A response for every of the asked locators will be waited. So it can be
    concluded whether or not the sought object is dead.

    How is this protocol going to stop?

    - At the arriving of a dead message for the sought object.

    - At the end of the stage 2.
    
  */
  

/*

class Find_Request : public Msg_Entry_Header 
{
  Binding binding;
};

class Object_Dead_Anounce : public Msg_Entry_Header
{
  Object_Id object_id;
};

*/
