# include "locator_local_services.H"
# include "locator_boot.H"
# include "locator_tables.H"
# include "local_message_header.H"
# include "local_reception_point.H"
# include "remote_multiserver_point.H"
# include "remote_message_header.H"
# include "locator_remote_services.H"
# include <useMutex.H>


# define MAX_SIZE_OF_CHUNK 2048

//static int _message_counter = 0;

void remote_reply(const Message_Id & message_id,
		  Invocation_Reply_Msg * reply_msg,
		  void * reply_buffer,
		  size_t reply_size)
{
  // Look up in the srv_response_point_table the tuple <Message_Id,
  // Binding_Point*>
  Srv_Response_Point_Bucket * searched_bucket;
  
  searched_bucket = 
    static_cast<Srv_Response_Point_Bucket *>
    (ptr_srv_response_point_table->search(message_id));
  
  ASSERT(searched_bucket != NULL);

# ifdef WITH_IMPLICIT_MSGS

  void * invoc_plus_implicit_chunk = Malloc(reply_size + MAX_SIZE_OF_CHUNK);

  if (reply_size > 0)
    memcpy(invoc_plus_implicit_chunk, reply_buffer, reply_size);

  char * implicit_chunk = 
    reinterpret_cast<char*>(invoc_plus_implicit_chunk) + reply_size;

  unsigned chunk_size = ptr_implicit_cnt->
    get_implicit_chunk(reply_msg->get_binding().get_source_site_id(),
		       implicit_chunk,
		       MAX_SIZE_OF_CHUNK);

  MESSAGE("Replying CHUNK SIZE = %i",chunk_size);

  MESSAGE("Number of msgs: %i", *reinterpret_cast<unsigned*>(implicit_chunk));

  ASSERT (chunk_size >= sizeof(unsigned));

  unsigned total_size = chunk_size + reply_size;

  searched_bucket->get_return_point()->
    rpc_reply(reply_msg, sizeof(*reply_msg), 
	      invoc_plus_implicit_chunk, total_size);  
  
  Free(invoc_plus_implicit_chunk);
  
# else // WITH_IMPLICIT_MSGS

  if (reply_size == 0)
    searched_bucket->get_return_point()->
      rpc_reply(reply_msg, sizeof(*reply_msg));
  else
    searched_bucket->get_return_point()->
      rpc_reply(reply_msg, sizeof(*reply_msg), reply_buffer, reply_size);

# endif // WITH_IMPLICIT_MSGS

  // Delete the entry from the srv_response_point_table
  searched_bucket->unLock();
  
  ptr_srv_response_point_table->remove(searched_bucket);
  
  AllocDelete(*objectAlloc, searched_bucket);
}


void check_container(Locator_Super_Receive_RetMsg * local_ret_msg,
		     const void * buffer,
		     size_t buffer_size,
		     Reception_Type reception_type,
		     Registered_Object_Bucket * object_bucket,
		     Msg_Entry_Header * input_msg)
{        
  Registered_Container_Bucket * container_bucket = NULL;

  if (reception_type == RECTYPE_INVOCATION_REQUEST)
    {
      ASSERT(object_bucket != NULL);
      
      container_bucket = static_cast<Registered_Container_Bucket *>
	(ptr_registered_container_table->
	 search(object_bucket->get_associated_container_id()));  
    }
  else
    if (reception_type == RECTYPE_INVOCATION_REPLY)
      {
	ASSERT(object_bucket == NULL);
	
	container_bucket = static_cast<Registered_Container_Bucket *>
	  (ptr_registered_container_table->
	   search(local_ret_msg->get_binding().get_source_container_id()));
      }
    else
	ERROR("*** ERROR: Unexpected message header. Check the code.");

  ASSERT(container_bucket != NULL);

  switch (container_bucket->get_current_state())
    {
    case CNT_READY:      
      container_bucket->set_current_state(CNT_PROCESSING_INVOCATION);
      
      ASSERT(container_bucket->get_invocation_return_point() != NULL);
      
      // send the invocation to the Binding_Point found in the table
      // handled in the last step.
      if (buffer_size > 0)
	container_bucket->get_invocation_return_point()->
	  respond(local_ret_msg, 
		  sizeof(Locator_Super_Receive_RetMsg),
		  buffer, 
		  buffer_size);
      else
	container_bucket->get_invocation_return_point()->
	  respond(local_ret_msg, sizeof(Locator_Super_Receive_RetMsg));

      if (reception_type == RECTYPE_INVOCATION_REQUEST)
	object_bucket->set_current_state(OBJ_PROCESSING_INVOCATION);
      else
	container_bucket->decrease_pending_replys();
      
      // Once no one is waiting for response, the waiting_invocation_
      // return_point should be NULL.
      container_bucket->set_invocation_return_point(NULL);
      break;
      
    case CNT_PROCESSING_INVOCATION:
    case CNT_NOT_RECEIVING:
      {
	if (reception_type == RECTYPE_INVOCATION_REQUEST)
	  {
	    // prepare the node for the waiting list.
	    Delayed_Invocation_Node * new_node = 
	      AllocNew(*objectAlloc, Delayed_Invocation_Node)
	      (*static_cast<Invocation_Request_Msg*>(input_msg));
	    // append the invocation to a waiting list.
	    container_bucket->get_waiting_invocation_list().append(new_node);
	    //	    _message_counter ++;
	  }
	else if (reception_type == RECTYPE_INVOCATION_REPLY)
	  {
	    // prepare the node for the waiting list.
	    Delayed_Answer_Node * new_node = 
	      AllocNew(*objectAlloc, Delayed_Answer_Node) 
	      (*static_cast<Invocation_Reply_Msg*>(input_msg));
	    // append the invocation to a waiting list.
	    container_bucket->get_waiting_invocation_list().append(new_node);
	    //	    _message_counter ++;
	  }
	else
	  {
	    ERROR("*** ERROR: Unexpected message header. Check the code.");
	  }
      }
      break;
    default:
      ERROR("*** ERROR: Unexpected message header. Check the code.");
    }

  container_bucket->unLock();
}

		     

void srv_receive
(Msg_Entry_Header * input_msg,
 Remote_Multiserver_Binding<Locator_Remote_Services> * return_point,
 Registered_Object_Bucket * object_bucket)
{
  Invocation_Request_Msg * 
    casted_input_msg = static_cast<Invocation_Request_Msg *>(input_msg);


#ifdef WITH_IMPLICIT_MSGS

  const char * chunk_address = static_cast<const char*>
    (casted_input_msg->get_request()) + casted_input_msg->get_request_size();
    
  MESSAGE("INVOCAITION request_size %i", casted_input_msg->get_request_size());
  
  ptr_implicit_cnt->process_chunk(casted_input_msg->get_binding().
				  get_source_site_id(),
				  chunk_address);
					   
#endif

  // Prepare the Srv_Invoke_Receive_RetMsg with the invocation
  Locator_Super_Receive_RetMsg 
    return_message(casted_input_msg->get_message_id(),
		   casted_input_msg->get_binding(),
		   casted_input_msg->get_request_size(),
		   RECTYPE_INVOCATION_REQUEST,
		   LOCEXIT_OK);	

  check_container(&return_message, 
		  casted_input_msg->get_request(),
		  casted_input_msg->get_request_size(),
		  RECTYPE_INVOCATION_REQUEST,
		  object_bucket,
		  input_msg);
		  
#ifdef DEBUG
  
  Srv_Response_Point_Bucket * search_resp_bucket;
  
  search_resp_bucket = static_cast<Srv_Response_Point_Bucket *>
    (ptr_srv_response_point_table->
     search(casted_input_msg->get_message_id()));

  if (search_resp_bucket == NULL)
    PRINT_ID(casted_input_msg->get_message_id());
  
  ASSERT(search_resp_bucket == NULL);
  
#endif // DEBUG
  
  // Store the tuple <Message_Id, return_point> in srv_response_point_table.
  Srv_Response_Point_Bucket * new_bucket;
  
  new_bucket = static_cast<Srv_Response_Point_Bucket *>
    (AllocNew(*objectAlloc, Srv_Response_Point_Bucket)
     (casted_input_msg->get_message_id(),
      casted_input_msg->get_binding().get_source_container_id(),
      return_point));
  
  ptr_srv_response_point_table->insert(new_bucket);
}



int Locator_Remote_Services::
remote_service_receive_invocation 
(Msg_Entry_Header * input_msg,
 Remote_Multiserver_Binding<Locator_Remote_Services> * return_point)
{
  CRITICAL_SECTION(&mutex_for_server_fcnt);
  
  MESSAGE("*** Receiving Remote Invocation ***");
  
  // Unmarshall the the incomming invocation.
  Invocation_Request_Msg * 
    casted_input_msg = static_cast<Invocation_Request_Msg *>(input_msg);  
  
  // Find binding.get_object_id() in ptr_registered_object_table.  
  Registered_Object_Bucket * object_bucket;
  
#define OBJECT_ID casted_input_msg->get_binding().get_object_id()
#define NEW_LOCATOR casted_input_msg->get_binding().get_locator()
  
  // Check if the object is busy
  object_bucket = static_cast<Registered_Object_Bucket *>
    (ptr_registered_object_table->search(OBJECT_ID));
  
  if (object_bucket != NULL)
    {
      object_bucket->unLock();
      // Handle the invocation reception
      srv_receive(input_msg, return_point, object_bucket);
    }
  else
    {
      // Prepare the response to the source locator.
      Invocation_Reply_Type result_from_searching = 
	look_up_in_caches(OBJECT_ID, NEW_LOCATOR);
      
      const int ZERO_SIZE_REPLY = 0;
      
      Invocation_Reply_Msg reply_msg(ZERO_SIZE_REPLY, 
				     casted_input_msg->get_binding(),
				     casted_input_msg->get_message_id(),
				     result_from_searching);
# ifdef WITH_IMPLICIT_MSGS

      void * implicit_chunk = Malloc(MAX_SIZE_OF_CHUNK);
      
      unsigned chunk_size = ptr_implicit_cnt->
	get_implicit_chunk(reply_msg.get_binding().get_source_site_id(),
			   implicit_chunk,
			   MAX_SIZE_OF_CHUNK);
      
      MESSAGE("Replying CHUNK SIZE = %i",chunk_size);
      
      MESSAGE("Number of msgs: %i", *reinterpret_cast<unsigned*>(implicit_chunk));
      
      ASSERT (chunk_size >= sizeof(unsigned));

      return_point->rpc_reply(&reply_msg, sizeof(reply_msg), 
			      implicit_chunk, chunk_size);  
  
      Free(implicit_chunk);
  
# else

      // Send response back to client
      return_point->rpc_reply(&reply_msg, sizeof(reply_msg));

# endif 
    }
  
  return 0;
  
#undef OBJECT_ID
#undef NEW_LOCATOR
}


Invocation_Reply_Type look_up_in_caches(const Object_Id & object_id,
					Locator & new_locator)
{
  CRITICAL_SECTION(&look_up_in_caches_mutex);

  // Find binding.object_id() in Cache_Garbage
  if (ptr_cache_garbage->find_key(object_id) == true)
    {
      ptr_cache_garbage->cache_unlock();
      
      return LOCREPLY_DEAD;
    }
  else
    {
      ptr_cache_garbage->cache_unlock();
    
      Locator * cached_locator = ptr_cache_out->find_data_ptr(object_id);
      
      ptr_cache_out->cache_unlock();

      if ((cached_locator != NULL) && (*cached_locator > new_locator)) 
	{
	  new_locator.update_locator(*cached_locator);
	  
	  return LOCREPLY_RECENT_BINDING;
	}
      else
	{
	  // look for the most recent between cache_mig and cache_new_bnds
	  Locator * from_cache_mig = ptr_cache_mig->find_data_ptr(object_id);
	  
	  ptr_cache_mig->cache_unlock();

	  // Find binding.object_id() in Cache_New_Bnds 
	  Locator * from_cache_new_bnds = 
	    ptr_cache_new_bnds->find_data_ptr(object_id);
	  
	  ptr_cache_new_bnds->cache_unlock();
	  
	  bool more_recent_binding = false;

	  // If it is newer than the incomming locator, then return the new
	  // binding and set the reply_type in LOCREPLY_RECENT_BINDING
	  if (from_cache_new_bnds != NULL)
	    if (*from_cache_new_bnds > new_locator) 
	      {
		new_locator.update_locator(*from_cache_new_bnds);
		more_recent_binding = true;
	      }
	  
	  // If it is newer than the incomming locator, then return the new
	  // binding and set the reply_type in LOCREPLY_RECENT_BINDING
	  if (from_cache_mig != NULL)
	    if (*from_cache_mig > new_locator)
	      {
		new_locator.update_locator(*from_cache_mig);
		return LOCREPLY_RECENT_BINDING;
	      }
	  
	  if (more_recent_binding)
	    return LOCREPLY_RECENT_BINDING;	  
	}
    } 

# ifdef WITH_IMPLICIT_MSGS
  // TODO: It is suppose that if an object is not found in caches, an
  // TODO: invocation to that object will fail. Then, it is a good
  // TODO: idea to include an implicit message, this early. However,
  // TODO: this responsability is going to be left to the client through
  // TODO: implicit_locate call.
# endif 

  return LOCREPLY_NOT_FOUND;  
}



void clt_receive(Msg_Entry_Header * input_msg) 
{
  MESSAGE("*** Remote Invocation Reply ***");

  Invocation_Reply_Msg * 
    casted_input_msg = static_cast<Invocation_Reply_Msg *>(input_msg);

# ifdef WITH_IMPLICIT_MSGS

  const char * chunk_address = static_cast<const char*>
    (casted_input_msg->get_reply()) + casted_input_msg->get_reply_size();
    
  
  ptr_implicit_cnt->process_chunk(casted_input_msg->get_binding().
				  get_target_site_id(),
				  chunk_address);
					   
# endif

  // Prepare the Srv_Invoke_Receive_RetMsg with the invocation
  Locator_Super_Receive_RetMsg
    local_reply_msg(casted_input_msg->get_message_id(),
		    casted_input_msg->get_binding(),
		    casted_input_msg->get_reply_size(),
		    RECTYPE_INVOCATION_REPLY,
		    LOCEXIT_OK);
  
  switch (casted_input_msg->get_reply_type())
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
      ERROR("*** ERROR: Unexpected message header. Check the code.");
    }

  check_container(&local_reply_msg, 
		  casted_input_msg->get_reply(),
		  casted_input_msg->get_reply_size(),
		  RECTYPE_INVOCATION_REPLY,
		  NULL,
		  input_msg);

#ifdef DEBUG
  if (casted_input_msg->get_reply_type() == LOCREPLY_SUCCESS)
      {
	MESSAGE("A reply arrived: %s, SIZE: %i", 
		  casted_input_msg->get_reply(), 
		  casted_input_msg->get_reply_size());
      }
#endif 

}

void
update_caches_with_response(const Invocation_Reply_Type reply_type, 
			    const Locator & locator)
{ 
  Locator * locator_from_cache =
    ptr_cache_out->find_data_ptr(locator.get_object_id());
  
  // Unlock the cache
  ptr_cache_out->cache_unlock();
  
  switch (reply_type)
    {
      // the both following headers cause ptr_cache_out to be updated.
    case LOCREPLY_RECENT_BINDING :
    case LOCREPLY_SUCCESS :
      if (locator_from_cache != NULL)
	{
	  if (locator > *locator_from_cache)
	    locator_from_cache->update_locator(locator);
	}
      else
	// At the very first invocation result, write it in Cache_Out. 
	ptr_cache_out->insert(locator.get_object_id(), locator);
      break;

    case LOCREPLY_NOT_FOUND :
      // If still the same, the delete it from Cache_Out.
      if ((locator_from_cache != NULL) && (*locator_from_cache == locator))
	ptr_cache_out->remove(locator.get_object_id());

      // TODO: Same as above (refer to implicit msg inclusion responsability)
      break;

    case LOCREPLY_DEAD :
      // Delete from Cache_Out if proceed 
      if (locator_from_cache != NULL)
	ptr_cache_out->remove(locator.get_object_id());
      
      // Delete from Cache_New_Bnds if proceed
      locator_from_cache = 
	ptr_cache_new_bnds->find_data_ptr(locator.get_object_id());
      
      ptr_cache_new_bnds->cache_unlock();
      
      if (locator_from_cache != NULL)
	ptr_cache_new_bnds->remove(locator.get_object_id());

      // Delete from Cache_Mig if proceed
      locator_from_cache = 
	ptr_cache_mig->find_data_ptr(locator.get_object_id());
      
      ptr_cache_mig->cache_unlock();
      
      if (locator_from_cache != NULL)
	ptr_cache_mig->remove(locator.get_object_id());

      // Insert it in Cache_Garbage
      ptr_cache_garbage->insert(locator.get_object_id());
      break;

    default:
      ERROR("*** ERROR: Unexpected message header. Check the code.");
    }
}


int Locator_Remote_Services::
remote_service_receive_reply (Msg_Entry_Header * input_msg)
{
  CRITICAL_SECTION(&mutex_for_server_fcnt);
    
  clt_receive(input_msg);
  
  Invocation_Reply_Msg * 
    casted_input_msg = static_cast<Invocation_Reply_Msg *>(input_msg);
  
  // update caches
  update_caches_with_response(casted_input_msg->get_reply_type(),
			      casted_input_msg->get_binding().
			      get_locator());
  
  return 0;
}


Message_Id clt_send(Msg_Entry_Header * input_msg)
{
  // prepare remote message  
  Clt_Invoke_Send_CallMsg * 
    casted_input_msg = static_cast<Clt_Invoke_Send_CallMsg *>(input_msg);
  
  // ask for a unique identifier.
  Message_Id msg_id;

  createUid(&msg_id);

  // Make the remote message  
  Invocation_Request_Msg request_msg(casted_input_msg->get_request_size(),
				     casted_input_msg->get_binding(),
				     msg_id);

# ifdef WITH_IMPLICIT_MSGS

  void * invoc_plus_implicit_chunk = Malloc(casted_input_msg->
					    get_request_size() +
					    MAX_SIZE_OF_CHUNK);

  if (casted_input_msg->get_request_size() > 0)
    memcpy(invoc_plus_implicit_chunk, casted_input_msg->request, 
	   casted_input_msg->get_request_size());

  char * implicit_chunk = 
    reinterpret_cast<char*>(invoc_plus_implicit_chunk) + 
    casted_input_msg->get_request_size();

  unsigned chunk_size = ptr_implicit_cnt->
    get_implicit_chunk(casted_input_msg->get_binding().get_target_site_id(),
		       implicit_chunk,
		       MAX_SIZE_OF_CHUNK);
  
  // check that the first element of the chunk is an unsigned telling the
  // total messages in chunk.

  MESSAGE("Request CHUNK SIZE = %i",chunk_size);

  MESSAGE("Number of msgs: %i", *reinterpret_cast<unsigned*>(implicit_chunk));

  ASSERT (chunk_size >= sizeof(unsigned));
  
  unsigned total_size = chunk_size + casted_input_msg->get_request_size();

  // TODO: delete next:
  //PRINT_PORT(casted_input_msg->get_binding().get_target_site_id(), "rpcsen");

  remote_server_id->rpc_send(casted_input_msg->
			     get_binding().get_target_site_id(),
			     &request_msg,
			     sizeof(request_msg),
			     invoc_plus_implicit_chunk, 
			     total_size);  
  
  Free(invoc_plus_implicit_chunk);
  
# else // WITH_IMPLICIT_MSGS
 
  //TODO: delete
  //PRINT_PORT(casted_input_msg->get_binding().get_target_site_id(), "rpcsen");

  // send the request to the target locator
  remote_server_id->rpc_send(casted_input_msg->
			     get_binding().get_target_site_id(),
			     &request_msg,
			     sizeof(request_msg),
			     casted_input_msg->request, 
			     casted_input_msg->get_request_size());  
# endif

  
  Registered_Container_Bucket * container_bucket;
  
  container_bucket = static_cast<Registered_Container_Bucket *>
    (ptr_registered_container_table->
     search(casted_input_msg->get_binding().get_source_container_id()));
  
  ASSERT(container_bucket != NULL);  
  
  container_bucket->increase_pending_replys();
  
  container_bucket->unLock();

  return msg_id;
}


int local_service_clt_invoke_send (Binding_Point * return_point, 
				   Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Client Invoke Send ***");

  CRITICAL_SECTION(&mutex_for_server_fcnt);

  Clt_Invoke_Send_CallMsg * 
    casted_input_msg = static_cast<Clt_Invoke_Send_CallMsg *>(input_msg);

  Invocation_Reply_Type result_from_caches =
    look_up_in_caches(casted_input_msg->get_binding().get_object_id(),
		      casted_input_msg->get_binding().get_locator());

  if (result_from_caches != LOCREPLY_DEAD)
    {
      Message_Id msg_id = clt_send(input_msg);
      
      // prepare the local respond message
      Clt_Invoke_Send_RetMsg 
	returning_msg(msg_id, 
		      casted_input_msg->get_binding().get_locator(),
		      LOCEXIT_OK);
      
      switch (result_from_caches)
	{
	case (LOCREPLY_SUCCESS):
	  // empty
	  break;
	case (LOCREPLY_NOT_FOUND):
	  returning_msg.set_response_code(LOCEXIT_OBJECT_NOT_FOUND);
	  break;
	case (LOCREPLY_RECENT_BINDING):
	  returning_msg.set_response_code(LOCEXIT_OBJECT_RECENT_BINDING);
	  break;
	default:
	  ERROR("*** Exit message header unknown! ***"); 
	}
      
      // respond status to local client
      return_point->respond(&returning_msg, sizeof(returning_msg));     
    }
  else
    {
      Clt_Invoke_Send_RetMsg 
	returning_msg(INVALID_MESSAGE_ID,
		      casted_input_msg->get_binding().get_locator(),
		      LOCEXIT_OBJECT_DEAD);
      
      // respond status to local client
      return_point->respond(&returning_msg, sizeof(returning_msg));
    }
  
  return 0;
}


void clt_invoke_receive (Binding_Point * return_point,
			 Delayed_Answer_Node * answer_node)
{
#define REPLY_MSG answer_node->get_reply_msg()

  MESSAGE("*** Client Invoke Receive ***");

  Locator_Super_Receive_RetMsg 
    return_message(REPLY_MSG.get_message_id(),
		   REPLY_MSG.get_binding(),
		   REPLY_MSG.get_reply_size(),
		   RECTYPE_INVOCATION_REPLY,
		   LOCEXIT_OK);
  
  // delete invocation from the list. The casting to Delayed_Invocation_
  // Node is because, it seems like the destructor of such an object was
  // not being called.
  
  // switch type of response.
  switch (REPLY_MSG.get_reply_type())
    {
    case (LOCREPLY_SUCCESS):
      // empty
      break;
    case (LOCREPLY_NOT_FOUND):
      return_message.set_response_code(LOCEXIT_OBJECT_NOT_FOUND);
      break;
    case (LOCREPLY_DEAD):
      return_message.set_response_code(LOCEXIT_OBJECT_DEAD);
      break;
    case (LOCREPLY_RECENT_BINDING):
      return_message.set_response_code(LOCEXIT_OBJECT_RECENT_BINDING);
      break;
    default:
      ERROR("*** ERROR: Unexpected message header. Check the code.");
    }
  
  // Answer to the client through binding_point.respond().
  if (REPLY_MSG.get_reply_size() > 0)
    return_point->respond(&return_message, 
			  sizeof(return_message),
			  answer_node->get_delayed_reply(),
			  REPLY_MSG.get_reply_size());
  else
    return_point->respond(&return_message, 
			  sizeof(return_message));
  
#undef REPLY_MSG
}


void srv_invoke_receive (Binding_Point * return_point,
			 Delayed_Invocation_Node * invocation_node)
{
#define REQUEST_MSG invocation_node->get_request_message()

  Registered_Object_Bucket * object_bucket;

  object_bucket = static_cast<Registered_Object_Bucket *>
    (ptr_registered_object_table->
     search(REQUEST_MSG.get_binding().get_object_id()));
  
  ASSERT(object_bucket != NULL); 
  
  object_bucket->unLock();
  
  object_bucket->set_current_state(OBJ_PROCESSING_INVOCATION);

  // Prepare the Srv_Invoke_Receive_RetMsg with the invocation
  Locator_Super_Receive_RetMsg 
    return_message(REQUEST_MSG.get_message_id(),
		   REQUEST_MSG.get_binding(),
		   REQUEST_MSG.get_request_size(),
		   RECTYPE_INVOCATION_REQUEST,
		   LOCEXIT_OK);
  
  // return the invocation to the client, as done in the
  // remote_service_receive_invocation.  
  return_point->respond(&return_message, 
			sizeof(return_message),
			invocation_node->get_delayed_request(),
			REQUEST_MSG.get_request_size());

#undef REQUEST_MSG
}


int local_service_locator_super_receive (Binding_Point * return_point, 
					 Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Locator SUPER-RECEIVE ***");
  
  CRITICAL_SECTION(&mutex_for_server_fcnt);

  Locator_Super_Receive_CallMsg * casted_input_msg = 
    static_cast<Locator_Super_Receive_CallMsg *>(input_msg);  
    
  Registered_Container_Bucket * container_bucket;
  
  // Check if the container is busy
  container_bucket = static_cast<Registered_Container_Bucket *>
    (ptr_registered_container_table->
     search(casted_input_msg->get_receiving_container_id()));
  
  ASSERT(container_bucket != NULL);
  
  // It is safe to unlock the bucket this early. That is because
  // we are already protected by a mutex.
  container_bucket->unLock();
  
  // if the invocation list is empty, that means that there is
  // no pending invocation to process. Therefore, we can set
  // the object state as CNT_READY

  if (container_bucket->get_waiting_invocation_list().isEmpty() == true)
    {
      container_bucket->set_current_state(CNT_READY);
      
      container_bucket->set_invocation_return_point(return_point);	
    }
  else
    {
      container_bucket->set_current_state(CNT_PROCESSING_INVOCATION);
      
      container_bucket->set_invocation_return_point(NULL);	
      
      // take an element from the waiting list
      Dnode<Reception_Type> * node_to_process = 
	container_bucket->get_waiting_invocation_list().removeNext();

      if (node_to_process->getData() == RECTYPE_INVOCATION_REQUEST)
	{
	  Delayed_Invocation_Node * request = 
	    static_cast<Delayed_Invocation_Node *>(node_to_process);
	  
	  srv_invoke_receive(return_point, request);

	  AllocDelete(*objectAlloc, request);

	  //	  _message_counter--;
	  //MESSAGE("Number of Messages: %i",_message_counter);
	}
      else
	if (node_to_process->getData() == RECTYPE_INVOCATION_REPLY)
	  {
	    Delayed_Answer_Node * reply = 
	      static_cast<Delayed_Answer_Node *>(node_to_process);
	    
	    clt_invoke_receive(return_point, reply);

	    container_bucket->decrease_pending_replys();

	    AllocDelete(*objectAlloc, reply);

	    //	    _message_counter--;
	    //MESSAGE("Number of Messages: %i",_message_counter);
	  }
	else 
	  {
	    ERROR("*** ERROR: Unexpected message header. Check the code.");
	  }
    }
  
  return 0;  
}


int local_service_srv_invoke_reply (Binding_Point * return_point, 
				    Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Server Invoke Reply ***");

  CRITICAL_SECTION(&mutex_for_server_fcnt);

  Srv_Invoke_Reply_CallMsg * 
    casted_input_msg = static_cast<Srv_Invoke_Reply_CallMsg *>(input_msg);
  

  Registered_Container_Bucket * container_bucket;
  

  // find the container and check the status
  container_bucket = static_cast<Registered_Container_Bucket *>
    (ptr_registered_container_table->
     search(casted_input_msg->get_replying_container_id()));
  
  ASSERT(container_bucket != NULL); 
  
  container_bucket->unLock();
  
  container_bucket->set_current_state(CNT_NOT_RECEIVING);
  
  container_bucket->set_invocation_return_point(NULL);	
  
  // find the object and set new status
  Registered_Object_Bucket * object_bucket;
  
  object_bucket = static_cast<Registered_Object_Bucket *>
    (ptr_registered_object_table->
     search(casted_input_msg->get_binding().get_object_id()));
  
  ASSERT(object_bucket != NULL); 
  
  object_bucket->unLock();
  
  object_bucket->set_current_state(OBJ_IDLE);
  
  // Update binding.get_object_id() in Cache_In
  Cache_In_Data cache_in_data(casted_input_msg->
			      get_binding().get_source_site_id(),
			      casted_input_msg->
			      get_binding().get_logical_timestamp());
  
  ptr_cache_in->insert(casted_input_msg->get_binding().get_object_id(),
			   cache_in_data);
  
  // Prepare the remote message with the reply.  
  Invocation_Reply_Msg reply_msg(casted_input_msg->get_reply_size(),
				 casted_input_msg->get_binding(),
				 casted_input_msg->get_message_id(),
				 LOCREPLY_SUCCESS);

  // Send the remote reply through the return_point found in the last step    
  remote_reply(casted_input_msg->get_message_id(),
	       &reply_msg,
	       casted_input_msg->get_reply_buffer(),
	       casted_input_msg->get_reply_size());

  MESSAGE("Invocation response size: %i", casted_input_msg->get_reply_size());
  
  // Repond to the client, who is waiting for the execution of the 
  // response.
  Srv_Invoke_Reply_RetMsg ret_msg(LOCEXIT_OK); 
  
  return_point->respond(&ret_msg, sizeof(ret_msg));
  
  return 0;
}


# undef MAX_SIZE_OF_CHUNK

