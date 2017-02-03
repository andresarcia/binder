# include "locator_comm_binding.H"
# include "locator_comm_point.H"
# include "base_message_header.H"
# include <pthread.h>

void Locator_Comm_Binding::write_to_client(void * data, size_t data_size)
{
  RawMsg reply_msg(data, data_size);
  
  MESSAGE("responding data_size %i", data_size);
  
  link_to_locator_comm_point->
    ptr_reception_deamon->rpc_send_reply(reply_msg, message_id);
}

ssize_t Locator_Comm_Binding::rpc_reply (Msg_Entry_Header * data, 
					 const size_t data_size)  
{
  ASSERT (data_size >= sizeof(Msg_Entry_Header));
  
  write_to_client(data, data_size);
  
  // Now, the service has been accomplished.
  set_still_busy(false);
  
  return 0; 
}

ssize_t Locator_Comm_Binding::rpc_reply (Msg_Entry_Header * data, 
					 const size_t data_size,
					 void * buffer,
					 const size_t buffer_size)  
{
  ASSERT (data_size >= sizeof(Msg_Entry_Header));

  ASSERT (buffer != NULL || buffer_size == 0);
  
  // data_size accounts for sizeof(Msg_Exit_Header) + sizeof(data).
  void * message = Malloc(data_size + buffer_size);

  // copy the first part of the message
  memcpy(message, data, data_size);
  
  // copy the second part of the message
  if ((buffer_size > 0) && (buffer != NULL))
    memcpy(static_cast<char*>(message) + data_size, buffer, buffer_size);

  // write it to the correspondant reception point
  write_to_client(message, data_size + buffer_size);
  
  Free(message);

  // Now, the service has been accomplished.
  set_still_busy(false);

  return 0;
}



