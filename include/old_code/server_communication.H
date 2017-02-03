# ifndef SERVER_COMMUNICATION_H 
# define SERVER_COMMUNICATION_H

# include <message_header.H> 

class Server_Communication 
{
private:

  static int global_timestamp;

  static int listen_descriptor;

  Logical_Timestamp get_global_timestamp();

  void service_create_unique_id(int & output_socket);

  void service_register_container(int & output_socket, 
				  void * parameters, 
				  size_t missing_size); 

  void locator_deamon_dispatcher(int & sockfd,
				 int * client, 
				 fd_set & allset);
public:

  Server_Communication();

  void locator_deamon_blocked_waiting();
 
  ~Server_Communication();

};

# endif // SERVER_COMMUNICATION_H



