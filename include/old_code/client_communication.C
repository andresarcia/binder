# include <message_header.H>
# include <local_communication.H>
# include <pthread.h>
# include <client_communication.H>
# include <ahExceptions.H>

int Client_Communication::client_socket_descriptor = 0;

pthread_mutex_t Client_Communication::lock_send = PTHREAD_MUTEX_INITIALIZER;

Client_Communication::Client_Communication()
{
  int			status;  
  struct sockaddr_un	server_address; 

  ASSERT (client_socket_descriptor == 0);

  client_socket_descriptor = socket(AF_LOCAL, SOCK_STREAM, 0); 

  ASSERT (client_socket_descriptor > 0);  
 
  bzero(&server_address, sizeof(server_address));

  server_address.sun_family = AF_LOCAL;
  strcpy(server_address.sun_path, LOCATOR_PATH);
 
  status = connect(client_socket_descriptor, (SA *) &server_address, 
		   sizeof(server_address)); 

  MESSAGE ( ("connect status: %i", status) );
  ASSERT (status >= 0);
}

void Client_Communication::send_request(const Locator_Call_Header &
					message_to_send,
					size_t size)   
{
  pthread_mutex_lock(&lock_send);
  writen(client_socket_descriptor, &message_to_send, size); 
}


void Client_Communication::receive_reply(Locator_Reply_Header &
					 message_received,
					 size_t size)    
{
  if (readn(client_socket_descriptor, &message_received, size) == 0)
    ERROR( ("Unexpected closing of socket") );

  pthread_mutex_unlock(&lock_send);
}


void Client_Communication::receive_reply(Locator_Reply_Header &
					 message_received, 
					 size_t size,
					 void * buffer_addr,
					 size_t buffer_size)
{
}
