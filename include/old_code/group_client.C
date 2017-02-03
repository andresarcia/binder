# include "group_client.H"

void Group_Client::join_group(const Port & listening_port) 
  throw (std::exception, Duplicated)
{
  Ipc_MultiClient_Server join_client;

  Join_Group_CallMsg join_msg(listening_port);

  RawMsg rpc_msg(&join_msg, sizeof(join_msg)); 

  MsgId send_msg_id = join_client.rpc_send_request(group_daemon_port,rpc_msg);

# define BUFFER_SIZE 512

  char message_buffer[BUFFER_SIZE];
  
  RawMsg incomming_message(&message_buffer[0], BUFFER_SIZE,
			   RawMsg::DEFAULT_FLAG);
  
  MsgId reply_msg_id = join_client.receive(incomming_message);

  ASSERT(send_msg_id == reply_msg_id);

  Join_Group_RetMsg * return_msg = reinterpret_cast<Join_Group_RetMsg *>
    (incomming_message.getBodyAddr()); 
  
  ASSERT(return_msg->get_response_code() == GRP_RESPONSE_TO_JOIN);

  if (return_msg->get_error_code() == GRP_INTENDED_DOUBLE_SUSCRIPTION)
    Throw (Duplicated)();

  ASSERT(return_msg->get_error_code() == GRP_OK);
}

# undef BUFFER_SIZE

# define TIMEOUT_NOT_NECESARY -1

void Group_Client::strong_send_to_group(const long return_service_code,
					void * message,
					const size_t message_size)
{
  Send_And_Receive_From_All_CallMsg request(client_port->get_port(),
					    return_service_code,
					    GRP_RELIABLE_SEND,
					    TIMEOUT_NOT_NECESARY,
					    message_size);

  client_port->
    rpc_send_to_other_server(group_daemon_port,
			     &request,
			     sizeof(Send_And_Receive_From_All_CallMsg),
			     message,
			     message_size);
}

# undef TIMEOUT_NOT_NECESARY
  
void Group_Client::weak_send_to_group(const long return_service_code,
				      const long timeout,
				      const void * message,
				      const size_t message_size)
{
}

void Group_Client::strong_send_to_some(const long return_service_code,
				       const void * message,
				       const size_t message_size)
{
}
  
void Group_Client::weak_send_to_some(const long return_service_code,
				     const long timeout,
				     const void * message,
				     const size_t message_size)
{
}

  
void Group_Client::leave_group(const Port & listening_port) 
  throw (std::exception, NotFound)
{
  Ipc_MultiClient_Server leave_client;

  Leave_Group_CallMsg leave_msg(listening_port);

  RawMsg rpc_msg(&leave_msg, sizeof(leave_msg)); 

  MsgId send_msg_id = leave_client.rpc_send_request(group_daemon_port,rpc_msg);

# define BUFFER_SIZE 512

  char message_buffer[BUFFER_SIZE];
  
  RawMsg incomming_message(&message_buffer[0], BUFFER_SIZE,
			   RawMsg::DEFAULT_FLAG);
  
  MsgId reply_msg_id = leave_client.receive(incomming_message);

  ASSERT(send_msg_id == reply_msg_id);

  Leave_Group_RetMsg * return_msg = reinterpret_cast<Leave_Group_RetMsg *>
    (incomming_message.getBodyAddr()); 
  
  ASSERT(return_msg->get_response_code() == GRP_RESPONSE_TO_LEAVE);

  if (return_msg->get_error_code() == GRP_MEMBER_NOT_SUSCRIBED)
    Throw (NotFound)();

  ASSERT(return_msg->get_error_code() == GRP_OK);
}





