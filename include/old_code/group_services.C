# include "group_daemon.H"

int Group_Daemon::grp_create_group(Msg_Entry_Header * entry_msg,
		   Remote_Multiserver_Binding * return_point)
{
  ERROR("*** Create Service not developed yet");

  return 0;
}

int Group_Daemon::grp_delete_group(Msg_Entry_Header * entry_msg,
		   Remote_Multiserver_Binding * return_point)
{
  ERROR("*** Delete Service not developed yet");

  return 0;
}

int Group_Daemon::grp_join_group(Msg_Entry_Header * entry_msg,
		   Remote_Multiserver_Binding * return_point)
{
  // annotate client on the table
  CRITICAL_SECTION(GROUP_MUTEX);

  Join_Group_CallMsg * casted_input_msg =
    static_cast<Join_Group_CallMsg *>(entry_msg);

  Group_Client * new_client =
    AllocNew(*objectAlloc, Group_Client)
    (casted_input_msg->get_listening_port_id());

  Group_Client * searched_client =
    search_elem<Group_Client, Port>(clients, new_client->get_client_port());
  
  if (searched_client == NULL)
    {
      clients.append(new_client);
      
      Join_Group_RetMsg 
	return_msg(GRP_OK);

      return_point->rpc_reply(&return_msg, sizeof(Join_Group_RetMsg));
      
      current_number_of_clients++;
    }
  else
    {
      AllocDelete(*objectAlloc, new_client);
      
      Join_Group_RetMsg 
	return_msg(GRP_INTENDED_DOUBLE_SUSCRIPTION);
      
      return_point->rpc_reply(&return_msg, sizeof(Join_Group_RetMsg));
    }
  
  return 0;
}		

int Group_Daemon::grp_leave_group(Msg_Entry_Header * entry_msg,
			      Remote_Multiserver_Binding * return_point)
{
  // delete client from the table
  CRITICAL_SECTION(GROUP_MUTEX);
  
  Leave_Group_CallMsg * casted_input_msg =
    static_cast<Leave_Group_CallMsg *>(entry_msg);

  Group_Client * searched_client =
    search_elem<Group_Client, Port>(clients, 
				    casted_input_msg->get_suscribed_port_id());
  
  if (searched_client == NULL)
    {
      Leave_Group_RetMsg 
	return_msg(GRP_MEMBER_NOT_SUSCRIBED);
      
      return_point->rpc_reply(&return_msg, sizeof(Leave_Group_RetMsg));
    }
  else
    {
      // TODO: check other structures' consistency

      searched_client->del();

      AllocDelete(*objectAlloc, searched_client);      
      
      current_number_of_clients--;

      Leave_Group_RetMsg 
	return_msg(GRP_OK);
      
      return_point->rpc_reply(&return_msg, sizeof(Leave_Group_RetMsg));
    }

  return 0;
}

int Group_Daemon::
grp_requieres_all_group_responses(Msg_Entry_Header * entry_msg,
				  Remote_Multiserver_Binding * return_point)
{
  CRITICAL_SECTION(GROUP_MUTEX);
  
  Send_And_Receive_From_All_CallMsg * casted_input_msg =
    static_cast<Send_And_Receive_From_All_CallMsg *>(entry_msg);

  long total_queries = current_number_of_clients - 1;

  long working_seq_numb = get_new_sequence_number();

  if (current_number_of_clients > 1)
    {
      Wait_For_Responses_Bucket * wait_bucket = 
	AllocNew(*objectAlloc, Wait_For_Responses_Bucket)
	(casted_input_msg->get_client_return_service_code(),
	 current_number_of_clients,
	 working_seq_numb,
	 total_queries,
	 return_point);
      
# ifdef DEBUG
      
      Wait_For_Responses_Bucket * 
	searched_bucket = static_cast<Wait_For_Responses_Bucket *>
	(client_response_table.search(sequence_number));
      
      ASSERT(searched_bucket == NULL);
      
# endif

      client_response_table.insert(wait_bucket);
    }
  else
    {
      ASSERT(current_number_of_clients == 1);
      
# define ZERO_SIZE 0 
      Responses_RetMsg 
	return_msg(casted_input_msg->get_client_return_service_code(),
		   GRP_OK,
		   current_number_of_clients,
		   current_number_of_clients, 
		   total_queries,
		   ZERO_SIZE);
# undef ZERO_SIZE     
      Msg_Entry_Header * msg_to_return = 
	static_cast<Msg_Entry_Header *>(&return_msg);
      
      return_point->rpc_reply(msg_to_return, sizeof(Responses_RetMsg));

      return 0;
    }

  Group_Client * cursor = static_cast<Group_Client *>(clients.getNext());
  
  while (cursor != &clients)
    {
      if (!(cursor->get_client_port() == casted_input_msg->get_source_port()))
	switch (casted_input_msg->get_reliability())
	  {
	  case GRP_NON_RELIABLE_SEND:
	    break;
	  case GRP_RELIABLE_SEND:
	    {
	      MsgId send_msg_id = 
		reception_point.rpc_send_to_other_server
		(cursor->get_client_port(),
		 reinterpret_cast<Msg_Entry_Header*>
		 (casted_input_msg->get_message_to_send()),
		 casted_input_msg->get_message_to_send_size());
	      
	      timespec exec_time =
		timespec_plus_msec(read_current_time(), 
				   WAITING_TIME_FOR_RESPONSE_MSEC);
	      
	      Group_Answer_Time_Expired * time_expired_event =
		AllocNew(*objectAlloc, Group_Answer_Time_Expired) 
		(exec_time, send_msg_id);
	      
	      timeout_queue.insertEvent(time_expired_event);

	      Msg_Id_Sqc_Nbr_Map_Bucket * new_bucket = 
		AllocNew(*objectAlloc, Msg_Id_Sqc_Nbr_Map_Bucket)
		(send_msg_id, working_seq_numb, time_expired_event);
	      
	      msg_id_sqc_nbr_map_table.insert(new_bucket);
	    }
	    break;
	  default:
	    ERROR("*** ERROR: Unknown sending reliability");
	  }
      
      cursor = static_cast<Group_Client *>(cursor->getNext());
    }

  // TODO: if there were sendings add the timeout event.

  return 0;
}

// TODO:
// THIS HAS TO BE CORRECTED
int Group_Daemon::grp_requieres_counted_responses(Msg_Entry_Header * entry_msg,
				    Remote_Multiserver_Binding * return_point)
{
  CRITICAL_SECTION(GROUP_MUTEX);
  
  // same as before but with less number of expected responses.
  Send_And_Receive_From_Some_CallMsg * casted_input_msg =
    static_cast<Send_And_Receive_From_Some_CallMsg *>(entry_msg);

  if (current_number_of_clients > 1)
    {
      Wait_For_Responses_Bucket * wait_bucket = 
	AllocNew(*objectAlloc, Wait_For_Responses_Bucket)
	(casted_input_msg->get_client_return_service_code(),
	 current_number_of_clients,
	 get_new_sequence_number(), 
	 casted_input_msg->get_number_of_expected_responses(), 
	 return_point);
      
# ifdef DEBUG
      
      Wait_For_Responses_Bucket * 
	searched_bucket = static_cast<Wait_For_Responses_Bucket *>
	(client_response_table.search(sequence_number));
      
      ASSERT(searched_bucket == NULL);
      
# endif
      
      client_response_table.insert(wait_bucket);
    }  
  else
    {
      ASSERT(current_number_of_clients == 1);
# define ZERO_SIZE 0 
      Responses_RetMsg 
	return_msg(casted_input_msg->get_client_return_service_code(),
		   GRP_OK,
		   current_number_of_clients,
		   current_number_of_clients, 
		   current_number_of_clients - 1,
		   ZERO_SIZE);
      
      Msg_Entry_Header * msg_to_return = 
	static_cast<Msg_Entry_Header *>(&return_msg);
      
      return_point->rpc_reply(msg_to_return, sizeof(Responses_RetMsg));  
      
      return 0;
# undef ZERO_SIZE
    }

  Group_Client * cursor = static_cast<Group_Client*>(clients.getNext());
  
  while (cursor != &clients)
    {
      if (!(cursor->get_client_port() == casted_input_msg->get_source_port())) 
	switch (casted_input_msg->get_reliability())
	  {
	  case GRP_NON_RELIABLE_SEND:
	    break;
	  case GRP_RELIABLE_SEND:
	    reception_point.
	      async_send(cursor->get_client_port(),
			 reinterpret_cast<Msg_Entry_Header*>
			 (casted_input_msg->get_message_to_send()));
	    break;
	  default:
	    ERROR("*** ERROR: Unknown sending reliability");
	  }
      
      cursor = static_cast<Group_Client*>(cursor->getNext());
    }

  // TODO: if there were sendings add the timeout event.

  return 0;
}

//TODO: TEST THIS
int Group_Daemon::grp_receive_response(Msg_Entry_Header * entry_msg)
{
  CRITICAL_SECTION(GROUP_MUTEX);

  Single_Response_RetMsg * casted_input_msg =
    static_cast<Single_Response_RetMsg *>(entry_msg);

  MsgId msg_id = reception_point.get_dispatched_message_id();

  Msg_Id_Sqc_Nbr_Map_Bucket * 
    searched_msg = static_cast<Msg_Id_Sqc_Nbr_Map_Bucket*>
    (msg_id_sqc_nbr_map_table.search(msg_id));

  if (searched_msg == NULL) 
    // response is late and it was cancelled by timeout event
    return 0;
  
  searched_msg->unLock();

  timeout_queue.cancelEvent(searched_msg->get_ptr_time_expired_event());

  Wait_For_Responses_Bucket * 
    searched_bucket = static_cast<Wait_For_Responses_Bucket *>
    (client_response_table.search(searched_msg->get_sequence_number()));

  msg_id_sqc_nbr_map_table.remove(searched_msg);

  // the expired event is deleted in searched_msg destructor 
  AllocDelete(*objectAlloc, searched_msg);

  searched_bucket->unLock();
  
  searched_bucket->add_new_response(casted_input_msg->get_response(), 
				    casted_input_msg->get_response_size());

  // check if deamon is ready to respond to client and respond if necesary
  if (searched_bucket->ready_to_respond())
    {
      Responses_RetMsg 
	return_msg(searched_bucket->get_client_return_service_code(),
		   GRP_OK,
		   searched_bucket->get_total_members_snapshot(),
		   searched_bucket->get_number_of_expected_responses(),
		   searched_bucket->get_current_number_of_responses(),
		   searched_bucket->get_current_buffer_size());

      Msg_Entry_Header * msg_to_return = 
	static_cast<Msg_Entry_Header *>(&return_msg);

      searched_bucket->get_waiting_client_port()->
	rpc_reply(msg_to_return,
		  sizeof(Responses_RetMsg),
		  searched_bucket->get_buffer_for_response(),
		  searched_bucket->get_current_buffer_size());

      client_response_table.remove(searched_bucket);

      AllocDelete(*objectAlloc, searched_bucket);
    }
  
  return 0;
}
