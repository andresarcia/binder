# ifndef CLIENT_COMMUNICATION_H
# define CLIENT_COMMUNICATION_H

# include <message_header.H>
# include <pthread.h>

class Client_Communication
{

private:

  static int client_socket_descriptor;

  static pthread_mutex_t lock_send;

public:

  Client_Communication();

  static void send_request(const Locator_Call_Header &, size_t);  

  static void receive_reply(Locator_Reply_Header &, size_t); 

  // special case only for invocation replys

  static void receive_reply(Locator_Reply_Header & message_received,
			    size_t size,
			    void * buffer_addr,
			    size_t buffer_size);

  ~Client_Communication()
  {
    close(client_socket_descriptor);
    pthread_mutex_destroy(&lock_send); // OJO 
  }
};

# endif // CLIENT_COMMUNICATION_H 








