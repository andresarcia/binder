# include "locator_local_services.H"
# include "locator_boot.H"
# include "locator_pars.H"
# include "locator_tables.H"
# include "local_message_header.H"
# include "local_reception_point.H"
# include "remote_multiserver_point.H"
# include "remote_message_header.H"
# include "locator_remote_services.H"
# include <useMutex.H>


int local_service_strong_locate (Binding_Point * return_point, 
				 Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Strong Locate ***");

  if (attach_to_broadcast_group)
    {
      CRITICAL_SECTION(&mutex_for_client_fcnt);
      
      Strong_Locate_CallMsg * casted_input_msg =
	static_cast<Strong_Locate_CallMsg *>(input_msg);
      
      Find_Owner_CallMsg find_owner(casted_input_msg->get_object_id());
      
# define JUST_OWNER_RESPONDS 1
      
      MsgId message_id =
	remote_server_id->strong_send_to_some(RESPONSE_FROM_STRONG_FIND_OWNER,
					      &find_owner,
					      sizeof(Find_Owner_CallMsg),
					      JUST_OWNER_RESPONDS);
# undef JUST_OWNER_RESPONDS
      
      Wait_Broadcast_Resp_Bucket * new_bucket;
      
      new_bucket = AllocNew(*objectAlloc, Wait_Broadcast_Resp_Bucket) 
	(message_id, return_point, casted_input_msg->get_object_id());
      
      ptr_wait_broadcast_resp_table->insert(new_bucket);
    }
  else
    ERROR("*** ERROR: Locator is not attached to a broadcast group. Use -G option");    
  
  return 0;
}


int local_service_weak_locate (Binding_Point * return_point, 
			       Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Weak Locate ***");
  
  if (attach_to_broadcast_group)
    {
      CRITICAL_SECTION(&mutex_for_client_fcnt);
      
      Weak_Locate_CallMsg * casted_input_msg =
	static_cast<Weak_Locate_CallMsg *>(input_msg);
      
      // first stage 
      
      Find_Owner_CallMsg find_owner(casted_input_msg->get_object_id());
      
# define JUST_OWNER_RESPONDS 1
      
      // TODO: Change strong by weak.
      MsgId message_id =
	remote_server_id->strong_send_to_some(RESPONSE_FROM_WEAK_FIND_OWNER,
					      &find_owner,
					      sizeof(Find_Owner_CallMsg),
					      JUST_OWNER_RESPONDS);
# undef JUST_OWNER_RESPONDS
      
      Wait_Broadcast_Resp_Bucket * new_bucket;
      
      new_bucket = AllocNew(*objectAlloc, Wait_Broadcast_Resp_Bucket) 
	(message_id, return_point, casted_input_msg->get_object_id());
      
      ptr_wait_broadcast_resp_table->insert(new_bucket);
    }
  else
    ERROR("*** ERROR: Locator is not attached to a broadcast group. Use -G option");

  return 0;
}


int local_service_implicit_locate (Binding_Point * return_point, 
				   Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Implicit Locate ***");

# ifdef WITH_IMPLICIT_MSGS
  
  Implicit_Locate_CallMsg * casted_input_msg = 
    static_cast<Implicit_Locate_CallMsg *>(input_msg);

  Implicit_Find_Msg implicit_find(casted_input_msg->get_binding(),
				  casted_input_msg->get_binding().
				  get_source_site_id());

  ptr_implicit_cnt->add_implicit_msg(implicit_find);

# endif

  Implicit_Locate_RetMsg return_msg(LOCEXIT_OK);

  return_point->respond(&return_msg, sizeof(return_msg));
  
  return 0;
}




int Locator_Remote_Services::remote_service_find_owner(Msg_Entry_Header * 
						       input_msg)
{
  MESSAGE("*** Find Owner ***");
 
  CRITICAL_SECTION(&mutex_for_client_fcnt);
  
  Find_Owner_CallMsg * casted_input_msg =
    static_cast<Find_Owner_CallMsg *>(input_msg);
  
  // find object in registered_object_table
  Registered_Object_Bucket * searched_bucket;
  
#define OBJECT_ID casted_input_msg->get_object_id()
  
  searched_bucket = static_cast<Registered_Object_Bucket*>
    (ptr_registered_object_table->search(OBJECT_ID));
  
  if (searched_bucket != NULL)
    {   
      searched_bucket->unLock();
      
      Locator locator(OBJECT_ID, 
		      static_cast<Site_Id>(remote_server_id->get_port()),
		      searched_bucket->get_logical_timestamp());

      Find_RetMsg success_reply(locator, 
				LOCREPLY_SUCCESS);

      Single_Response_From_Some_RetMsg 
	return_msg(remote_server_id->get_dispatched_message_id(),
		   sizeof(Find_RetMsg));

      remote_server_id->
	async_send_to_other_server(broadcast_daemon_port,
				   &return_msg, 
				   sizeof(Single_Response_From_Some_RetMsg),
				   &success_reply,
				   sizeof(Find_RetMsg));
    } 

# undef OBJECT_ID
   
  return 0;
}

int Locator_Remote_Services::
remote_service_response_from_weak_find_owner(Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Response from Weak Find Owner ***");

  CRITICAL_SECTION(&mutex_for_client_fcnt);

  Responses_RetMsg * 
    casted_input_msg = static_cast<Responses_RetMsg *>(input_msg);

  Wait_Broadcast_Resp_Bucket * searched_bucket =
    static_cast<Wait_Broadcast_Resp_Bucket *>
    (ptr_wait_broadcast_resp_table->search(get_dispatched_message_id()));
  
  ASSERT(searched_bucket != NULL);
  
  searched_bucket->unLock();
  
  if (casted_input_msg->get_current_number_of_responses() == 0)
    {
      // second stage
      Gather_Object_CallMsg gather(searched_bucket->get_searched_object_id());

      // TODO: Change strong by weak.
      // send the message to the group
      MsgId out_msg_id = 
	remote_server_id->strong_send_to_group(RESPONSE_FROM_GATHER,
					       &gather,
					       sizeof(Gather_Object_CallMsg));
      
      // insert new wait-for-broadcast bucket 
      
      Wait_Broadcast_Resp_Bucket * new_bucket;
      
      new_bucket = AllocNew(*objectAlloc, Wait_Broadcast_Resp_Bucket) 
	(out_msg_id, 
	 searched_bucket->get_return_point(),
	 searched_bucket->get_searched_object_id());

      ptr_wait_broadcast_resp_table->insert(new_bucket);
    }
  else
    {
      // get response message out of input message
      Find_RetMsg * find_retmsg = reinterpret_cast<Find_RetMsg *>
	(const_cast<char *>(casted_input_msg->get_responses()));

      // prepare response to client
      Weak_Locate_RetMsg local_reply_msg(LOCEXIT_OK, 
					 find_retmsg->get_locator());

      // process locator as a "Locator Announce"
      process_locator_anounce(find_retmsg->get_locator());
      
      // give response to client
      searched_bucket->
	get_return_point()->respond(&local_reply_msg,
				    sizeof(Weak_Locate_RetMsg));
    }
  
  ptr_wait_broadcast_resp_table->remove(searched_bucket);
      
  return 0;
}

int Locator_Remote_Services::
remote_service_response_from_strong_find_owner(Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Response from Strong Find Owner ***");

  CRITICAL_SECTION(&mutex_for_client_fcnt);
  
  Responses_RetMsg * 
    casted_input_msg = static_cast<Responses_RetMsg *>(input_msg);

  Wait_Broadcast_Resp_Bucket * searched_bucket =
    static_cast<Wait_Broadcast_Resp_Bucket *>
    (ptr_wait_broadcast_resp_table->search(get_dispatched_message_id()));
  
  ASSERT(searched_bucket != NULL);
  
  searched_bucket->unLock();
  
  if (casted_input_msg->get_current_number_of_responses() == 0)
    {
      Locator locator_for_dead_obj(searched_bucket->get_searched_object_id(),
				   INVALID_SITE_ID,
				   INVALID_LOGICAL_TIMESTAMP);

      // object is dead
      Strong_Locate_RetMsg local_reply_msg(LOCEXIT_OBJECT_DEAD, 
					   locator_for_dead_obj);

      update_caches_with_response(LOCREPLY_DEAD, locator_for_dead_obj);

      // notify it to client
      searched_bucket->
	get_return_point()->respond(&local_reply_msg,
				    sizeof(Strong_Locate_RetMsg));
    }
  else
    {
      // get response message out of input message
      Find_RetMsg * find_retmsg = reinterpret_cast<Find_RetMsg *>
	(const_cast<char *>(casted_input_msg->get_responses()));
      
      // prepare response to client
      Strong_Locate_RetMsg local_reply_msg(LOCEXIT_OK, 
					   find_retmsg->get_locator());
      
      // process locator as a "Locator Announce"
      process_locator_anounce(find_retmsg->get_locator());
      
      // give response to client
      searched_bucket->
	get_return_point()->respond(&local_reply_msg,
				    sizeof(Strong_Locate_RetMsg));
    }
  
  ptr_wait_broadcast_resp_table->remove(searched_bucket);
      
  return 0;
}


int Locator_Remote_Services::remote_service_gather_object_information
(Msg_Entry_Header * input_msg,
 Remote_Multiserver_Binding<Locator_Remote_Services> * return_point)
{
  MESSAGE("*** Gather Object Information ***");

  CRITICAL_SECTION(&mutex_for_client_fcnt);
  
  Gather_Object_CallMsg * casted_input_msg =
    static_cast<Gather_Object_CallMsg *>(input_msg);
  
#define OBJECT_ID casted_input_msg->get_object_id()
    
  // find it in caches: out, mig, new_bnds and garbage.
  
  Locator gathered_locator(OBJECT_ID, 
			   INVALID_SITE_ID, 
			   INVALID_LOGICAL_TIMESTAMP);

  Invocation_Reply_Type reply_hdr = 
    look_up_in_caches(OBJECT_ID, gathered_locator);
  
  Find_RetMsg reply_msg(gathered_locator, reply_hdr);
  
  Single_Response_From_All_RetMsg 
    ret_msg_to_daemon_group(sizeof(Find_RetMsg));

  return_point->rpc_reply(&ret_msg_to_daemon_group, 
			  sizeof(Single_Response_From_All_RetMsg),
			  &reply_msg,
			  sizeof(Find_RetMsg));
  
  return 0;
}
# undef OBJECT_ID

int Locator_Remote_Services::
remote_service_response_from_gather(Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Response from Gather ***");
  
  CRITICAL_SECTION(&mutex_for_client_fcnt);
  
  Responses_RetMsg * reply_msg = static_cast<Responses_RetMsg *>(input_msg);
  
  ASSERT (reply_msg->get_current_number_of_responses() >= 0);

  if (reply_msg->get_current_number_of_responses() == 0)
    EXIT("Check locator system. Nobody is responding.");
  
  int r_size = reply_msg->get_responses_size() / 
    reply_msg->get_current_number_of_responses();
  
  Find_RetMsg * find_retmsg = reinterpret_cast<Find_RetMsg *>
    (const_cast<char*>(reply_msg->get_responses()));
  
  Wait_Broadcast_Resp_Bucket * searched_bucket =
    static_cast<Wait_Broadcast_Resp_Bucket *>
    (ptr_wait_broadcast_resp_table->search(get_dispatched_message_id()));

  ASSERT(searched_bucket != NULL);
  
  // extract all responses from the message. And process each one.
    
  for (int j = 0; j <  reply_msg->get_current_number_of_responses(); j++)
    {
      find_retmsg = reinterpret_cast<Find_RetMsg *>
	(const_cast<char*>(reply_msg->get_responses()) + j*r_size);
      
      update_caches_with_response(find_retmsg->get_reply_type(),
				  find_retmsg->get_locator());
    }

  // look up for the conclusion

  Locator locator_response(find_retmsg->get_locator());

  Invocation_Reply_Type reply_hdr = 
    look_up_in_caches(locator_response.get_object_id(),
		      locator_response);
  
  Weak_Locate_RetMsg local_reply_msg(LOCEXIT_OK, locator_response);

  switch (reply_hdr)
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

  searched_bucket->unLock();

  searched_bucket->
    get_return_point()->respond(&local_reply_msg, sizeof(Weak_Locate_RetMsg));

  ptr_wait_broadcast_resp_table->remove(searched_bucket);
  
  return 0;
}


// It is prohibited to explicitly send a dead_anounce
int Locator_Remote_Services::
remote_service_dead_anounce (Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Dead Anounce ***");
  return 0;
}


void process_locator_anounce(const Locator & locator)
{
  Locator * locator_from_cache =
    ptr_cache_out->find_data_ptr(locator.get_object_id());
  
  if (locator_from_cache != NULL)
    {
      if (locator > *locator_from_cache)
	locator_from_cache->update_locator(locator);
    }
  else
    // Try to find it in ptr_cache_new_bnds and if it is not there, insert it.
    {
      locator_from_cache =
	ptr_cache_new_bnds->find_data_ptr(locator.get_object_id());
      
      ptr_cache_new_bnds->cache_unlock();
      
      if (locator_from_cache != NULL)
	{
	  if (locator > *locator_from_cache)
	    locator_from_cache->update_locator(locator);
	}
      else
	ptr_cache_new_bnds->insert(locator.get_object_id(), locator);
    }
  
  ptr_cache_out->cache_unlock();
}


int Locator_Remote_Services::
remote_service_locator_anounce (Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Locator anounce ***");
  
  Locator_Anounce * casted_input_msg =
    static_cast<Locator_Anounce *>(input_msg);

  process_locator_anounce(casted_input_msg->get_locator());
  
  return 0;
}


int local_service_test_object_location (Binding_Point * return_point, 
					Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Test Location Service ***");

  Test_Object_Location_CallMsg * casted_input_msg =
    static_cast<Test_Object_Location_CallMsg *>(input_msg);

  Invocation_Reply_Type reply_hdr = 
    look_up_in_caches(casted_input_msg->get_locator().get_object_id(),
		      casted_input_msg->get_locator());

  Test_Object_Location_RetMsg  
    local_reply_msg(casted_input_msg->get_locator(),
		    LOCEXIT_OK);
  
  switch (reply_hdr)
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

  return_point->respond(&local_reply_msg, sizeof(local_reply_msg));
  
  return 0;
}

class List_Node : public Dlink
{
  Locator locator;
  
public:
  List_Node(const Locator & _locator) :
    locator(_locator)
  {
    // empty
  }

  const Locator & get_locator() const
  {
    return locator;
  }
};
  

int local_service_ping_n_objects(Binding_Point * return_point, 
				 Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Ping N objects ***");

  Ping_N_Objects_CallMsg * casted_entry_msg =
    static_cast<Ping_N_Objects_CallMsg *>(input_msg);

  Dlink locators_to_ping_list;

  unsigned number_of_obj_to_ping = 0;

  // Make a sorted list of locators
  try
    {
      Cache_Out::Protected_Policy_Iterator 
	iter(ptr_cache_out,
	     casted_entry_msg->get_number_of_objects(),
	     casted_entry_msg->get_policy());
      
      while (iter.get_current() != NULL)
	{
	  Locator * locator = iter.get_current();

	  List_Node * node = AllocNew(*objectAlloc, List_Node) (*locator);
	  
	  locators_to_ping_list.append(node);
	  
	  iter.move_next();
	  
	  number_of_obj_to_ping ++;
	}
    }    
  catch (NotFound) // No entries to ping
    {
      Ping_N_Objects_RetMsg return_msg(LOCEXIT_OBJECT_NOT_FOUND);

      return_point->respond(&return_msg, sizeof(return_msg));

      return 0;
    }

  size_t ping_message_size = 
    sizeof(Ping_N_Objects_Request) + sizeof(Locator) * number_of_obj_to_ping;
  
  // Create ping message.
  void * memory_space = Malloc(ping_message_size);
  
  Ping_N_Objects_Request spaceless_ping_msg(number_of_obj_to_ping);
  
  Ping_N_Objects_Request * ping_msg = 
    reinterpret_cast<Ping_N_Objects_Request *>(memory_space);
  
  memcpy(ping_msg,  &spaceless_ping_msg, sizeof(Ping_N_Objects_Request));
  
  Dlink * cursor;

#define LIST_NODE(ptr_dlink) static_cast<List_Node*>(ptr_dlink)
  
  // Make as much messages as different sites in list
  while (!locators_to_ping_list.isEmpty())
    {
      Dlink * group_leader = locators_to_ping_list.getNext();
	      
      cursor = group_leader;
      
      ping_msg->reset_locators_counter();
      
      ping_msg->add_locator(LIST_NODE(group_leader)->get_locator());
      
      while (cursor->getNext() != &locators_to_ping_list)
	{	
	  cursor = cursor->getNext();
	  
	  if (LIST_NODE(cursor)->get_locator().get_target_site_id() ==
	      LIST_NODE(group_leader)->get_locator().get_target_site_id())
	    {
	      ping_msg->add_locator(LIST_NODE(cursor)->get_locator());
	      
	      cursor = cursor->getPrev();

	      AllocDelete(*objectAlloc, cursor->removeNext());
	    } 
	}

      group_leader->del();

      // Send each of the messages to the target site.
      /* TODO: WATCH AND TEST THIS: 27/09/01 */
      ping_message_size = 
	sizeof(Ping_N_Objects_Request) + 
	sizeof(Locator) * ping_msg->get_number_of_objects();
      
      remote_server_id->
	rpc_send(LIST_NODE(group_leader)->get_locator().get_target_site_id(), 
		 ping_msg, 
		 /*sizeof(ping_msg)*/
		 ping_message_size);

      AllocDelete(*objectAlloc, LIST_NODE(group_leader));
    }
  
#undef LIST_NODE  
  
  Ping_N_Objects_RetMsg return_msg(LOCEXIT_OK);
  
  return_point->respond(&return_msg, sizeof(return_msg));
  
  return 0;
}


int Locator_Remote_Services::remote_service_ping_n_objects_request
(Msg_Entry_Header * input_msg,
 Remote_Multiserver_Binding<Locator_Remote_Services> * return_point)
{
  MESSAGE("*** Ping request for N objects ***");
  
  CRITICAL_SECTION(&mutex_for_client_fcnt);
  
  Ping_N_Objects_Request * casted_input_msg =
    static_cast<Ping_N_Objects_Request *>(input_msg);
  
  // find object in registered_object_table
  Registered_Object_Bucket * searched_bucket;
  
  unsigned reply_size = sizeof(Ping_Reply_For_N_Objects) + 
    casted_input_msg->get_number_of_objects() *
    (sizeof(Locator) + sizeof(Invocation_Reply_Type));
  
  Ping_Reply_For_N_Objects * 
    ping_reply = reinterpret_cast<Ping_Reply_For_N_Objects*>
    (Malloc(reply_size));  

  Ping_Reply_For_N_Objects 
    spaceless_reply(casted_input_msg->get_number_of_objects());
  
  memcpy(ping_reply, &spaceless_reply, sizeof(spaceless_reply));
  
#define OBJECT_ID(n) (*casted_input_msg)[n].get_object_id()
#define LOCATOR(n) (*casted_input_msg)[n]

  for (unsigned obj_index = 0; 
       obj_index < casted_input_msg->get_number_of_objects();
       obj_index ++)
    {
      searched_bucket = static_cast<Registered_Object_Bucket*>
	(ptr_registered_object_table->search(OBJECT_ID(obj_index)));
	 
      if (searched_bucket != NULL)
	{   
	  searched_bucket->unLock();
	  
	  ping_reply->add_response(LOCATOR(obj_index), LOCREPLY_SUCCESS);
	}
      else
	{
	  // if not found, then find it in caches.
	  Invocation_Reply_Type reply_hdr = 
	    look_up_in_caches(OBJECT_ID(obj_index), LOCATOR(obj_index));
	  
	  ping_reply->add_response(LOCATOR(obj_index), reply_hdr);
	}
    }
  
  return_point->rpc_reply(ping_reply, reply_size);
  
  Free(ping_reply);
  
  return 0;

#undef OBJECT_ID
#undef LOCATOR
}

int Locator_Remote_Services:: 
remote_service_ping_reply_for_n_objects(Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Ping reply for N objects ***");
  
  CRITICAL_SECTION(&mutex_for_client_fcnt);
  
  Ping_Reply_For_N_Objects * casted_input_msg =
    static_cast<Ping_Reply_For_N_Objects *>(input_msg);
  
  for (unsigned response_index = 0;
       response_index < casted_input_msg->get_number_of_responses();
       response_index ++)
    update_caches_with_response(casted_input_msg->
				get_reply_type(response_index),
				casted_input_msg->
				get_locator(response_index));
  
  return 0;
}





