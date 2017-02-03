# include <client_msg.H>
# include <system_msg.H>
# include <local_communication.H>
# include <server_communication.H>
# include <ahExceptions.H>

int Server_Communication::global_timestamp = 0;

int Server_Communication::listen_descriptor = 0;

Logical_Timestamp Server_Communication::get_global_timestamp()
{
  return ++global_timestamp;
}

/* 
   Initializes the socket in which the locator deamon listens to
   serializable requests of clients. Those requests are the 
   sincronized ones.
*/

Server_Communication::Server_Communication()
{
  int		        status;
 
  struct sockaddr_un	server_address;

  listen_descriptor = socket(AF_LOCAL, SOCK_STREAM, 0);

  ASSERT(listen_descriptor > 0);

  unlink(LOCATOR_PATH);

  bzero(&server_address, sizeof(server_address));

  server_address.sun_family      = AF_LOCAL;
  strcpy(server_address.sun_path, LOCATOR_PATH);

  status = bind(listen_descriptor, (SA *) &server_address,
		sizeof(server_address));

  ASSERT(status >= 0);

  status = listen(listen_descriptor, LISTENQ);  // LISTENQ = 1024
  ASSERT(status >= 0);
}


void Server_Communication::service_create_unique_id(int & output_socket)
{ 
  Random_Number rand_num;
  const Random_Number Max_Numb = 0xFFFFFFFFFFFFFFFFll; 

  rand_num = static_cast<Random_Number> (static_cast<float>(Max_Numb) * 
					 rand() / (RAND_MAX+1.0));   
  
  Unique_Id_Message unique_id(get_global_timestamp(), rand_num);

  MESSAGE (("Global Timestamp: %llu \n Random Number: %llu", 
	    unique_id.get_logical_timestamp(), unique_id.get_random_number()))

    writen(output_socket, &unique_id, sizeof(Unique_Id_Message));
}

/*
  This routine registers in the system the container passed 
  in "parameters". 
*/

void Server_Communication::service_register_container(int & output_socket, 
						      void * parameters, 
						      size_t missing_size) 
{
  Register_Container_Message reg_cnt_msg;

  char * where_to_place = reinterpret_cast<char*>(&reg_cnt_msg) + 
    sizeof(Locator_Call_Header);    

  memcpy(where_to_place, parameters, missing_size);
 
  // process request ...
  
  Status_Reply_Message status_msg(OK); // testing ...

  writen(output_socket, &status_msg, sizeof(Status_Reply_Message));

  // the memory that was allocated at the dispatcher has to be freed.
  free(parameters);
}


void Server_Communication::locator_deamon_dispatcher(int & sockfd, 
						     int * client, 
						     fd_set & allset)
{
  unsigned int        missing_size;
  Locator_Call_Header message_received; 
  void                * rest_of_the_message;


  if (readn(sockfd, &message_received, sizeof(Locator_Call_Header)) == 0) 
    {
      /* connection closed by client */
      close(sockfd);
      FD_CLR(sockfd, &allset);
      *client = -1;
      return;
    }

  /* calculating the missing size of the request */       
  switch (message_received.get_service_code())
    {
    case REGISTER_CONTAINER :
      missing_size = sizeof(Register_Container_Message) -
	sizeof(Locator_Call_Header);  
      break;
    case UNREGISTER_CONTAINER : break;
    case REGISTER_OBJECT : break;
    case UNREGISTER_OBJECT : break;
    case TARGET_REG_MIG_OBJECT : break;
    case SOURCE_UNREG_MIG_OBJECT : break;
    case TARGET_REG_MIG_CONTAINER : break;
    case SOURCE_UNREG_MIG_CONTAINER : break;
    case STRONG_LOCATE : break;
    case WEAK_LOCATE : break;
    case IMPLICIT_LOCATE : break;
    case CLIENT_INVOKE_SEND : break;
    case CLIENT_INVOKE_RECEIVE : break;
    case SERVER_INVOKE_RECEIVE : break;
    case SERVER_INVOKE_REPLY : break;
    case CREATE_UNIQUE_ID :
      missing_size = sizeof(Create_Unique_Id_Message) - 
	sizeof(Locator_Call_Header);
      break;
 
    }
  
  if (missing_size > 0) 
    {
      // TODO: check for changing of malloc to new 
      rest_of_the_message = malloc(sizeof(missing_size));      
             
      if (readn(sockfd, rest_of_the_message, missing_size) == 0) 
	ERROR( ("ERROR: readn returned 0 when missing_size > 0") )
	  } 

  /* calls to services */
  switch (message_received.get_service_code())
    {
    case CREATE_UNIQUE_ID :
      service_create_unique_id(sockfd);
      break;
    case REGISTER_CONTAINER :
      service_register_container(sockfd, rest_of_the_message, missing_size);
      break;
    case UNREGISTER_CONTAINER : break;
    case REGISTER_OBJECT : break;
    case UNREGISTER_OBJECT : break;
    case TARGET_REG_MIG_OBJECT : break;
    case SOURCE_UNREG_MIG_OBJECT : break;
    case TARGET_REG_MIG_CONTAINER : break;
    case SOURCE_UNREG_MIG_CONTAINER : break;
    case STRONG_LOCATE : break;
    case WEAK_LOCATE : break;
    case IMPLICIT_LOCATE : break;
    case CLIENT_INVOKE_SEND : break;
    case CLIENT_INVOKE_RECEIVE : break;
    case SERVER_INVOKE_RECEIVE : break;
    case SERVER_INVOKE_REPLY : break;
    }
}


void Server_Communication::locator_deamon_blocked_waiting()
{
  int		i, maxi, maxfd, connfd, sockfd;

  int		nready, client[FD_SETSIZE]; // FD_SETSIZE = 1024

  fd_set	rset, allset;

  struct sockaddr_un	client_address;
  
  socklen_t	clilen;


  maxfd = listen_descriptor;	/* initialize */
  maxi = -1;		        /* index into client[] array */


  for (i = 0; i < FD_SETSIZE; i++)
    client[i] = -1;		/* -1 indicates available entry */

  FD_ZERO(&allset);
  FD_SET(listen_descriptor, &allset);

  for ( ; ; ) 
    {
      /* structure assignment */
      rset = allset;
      nready = select(maxfd+1, &rset, NULL, NULL, NULL);

      /* new client connection */
      if (FD_ISSET(listen_descriptor, &rset)) 
	{	
	  clilen = sizeof(client_address);
	  connfd = accept(listen_descriptor, (SA *) &client_address,
			  &clilen);

	  ASSERT(connfd >= 0);

	  for (i = 0; i < FD_SETSIZE; i++) 
	    if (client[i] < 0) 
	      {
		client[i] = connfd;	/* save descriptor */
		break;
	      }

	  ASSERT (i < FD_SETSIZE);          /* too many clients */

	  FD_SET(connfd, &allset);	        /* add new descriptor to set */
	  if (connfd > maxfd)
	    maxfd = connfd;		/* for select */
	  if (i > maxi)
	    maxi = i;			/* max index in client[] array */

          if (--nready <= 0)
	    continue;			/* no more readable descriptors */
	}

      for (i = 0; i <= maxi; i++) 
	{	
	  /* check all clients for data */
   	  if ( (sockfd = client[i]) < 0)
	    continue;

	  if (FD_ISSET(sockfd, &rset)) 
	    locator_deamon_dispatcher(sockfd, &client[i], allset);

	  if (--nready <= 0) /* no more readable descriptors */
	    break;  
	} 
    } /* end of main for( ; ; ) */
}

Server_Communication::~Server_Communication()
{
  close(listen_descriptor);
}
