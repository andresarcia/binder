# include "deamon_reception_point.H"
# include "loccom_message_header.H"
# include "loccom_readwrite.H"
# include <aleph.H>
# include <tpl_lhash.H>


int Deamon_Reception_Point::listen_descriptor = 0;

unsigned long Deamon_Reception_Point::hashFct(const long & key)
{
  return (unsigned long) key;
}

// TODO: check for greater table length, which it is passed through 
// no_of_services.
LhashTable<long> 
Deamon_Reception_Point::services_table(hashFct);

Deamon_Reception_Point::
Deamon_Reception_Point(const char *access_path, 
		       unsigned int no_of_services,
		       GenAlloc & _alloc = *objectAlloc) :
  // TODO: check for greater table length, which it is passed through 
  // no_of_services.
  alloc(_alloc)
{
  int		        status;
  struct sockaddr_un	server_address;

  services_table.resize(no_of_services);
  
  listen_descriptor = socket(AF_LOCAL, SOCK_STREAM, 0);
  ASSERT(listen_descriptor > 0);

  unlink(access_path);
  //    ERROR ( ("Can not execute unlink propertly") );

  bzero(&server_address, sizeof(server_address));

  server_address.sun_family      = AF_LOCAL;
  strcpy(server_address.sun_path, access_path);

  status = bind(listen_descriptor, (SA *) &server_address,
		sizeof(server_address));
  ASSERT(status >= 0);

  status = listen(listen_descriptor, LISTENQ);  // LISTENQ = 1024
  ASSERT(status >= 0);
}


void Deamon_Reception_Point::dispatcher(Client_Id to_whom, 
					int *     client_array_ref, 
					fd_set    allset)
{
  Deamon_Msg_Entry_Header   entry_msg;
  int                       missing_size;
  void                    * where_to_place; 
  void                    * request_msg;
  Services_Table_Entry    * entry;
  Response_For_Registration resp_for_reg;

  if (Loccom_Readwrite::readn(to_whom.get_client_socket(), 
			      &entry_msg, 
			      sizeof(Deamon_Msg_Entry_Header)) == 0) 
    {
      /* connection closed by client */
      close(to_whom.get_client_socket());
      FD_CLR(to_whom.get_client_socket(), &allset);
      *client_array_ref = -1;
      return;
    }
  
  if (entry_msg.get_is_from_deamon() == REGISTERING)
    {
      /*
	Client wants to register a service
      */
      Register_Message reg_msg;

      where_to_place = reinterpret_cast<char*>(&reg_msg) +
	sizeof(Deamon_Msg_Entry_Header);

      missing_size = sizeof(reg_msg) -
	sizeof(Deamon_Msg_Entry_Header);

      Loccom_Readwrite::readn(to_whom.get_client_socket(), where_to_place,
			      missing_size);
      
      entry = static_cast<Services_Table_Entry *>
	(services_table.search(entry_msg.get_service_code()));
      
      if ((entry == NULL) ||
	  (strcmp(entry->get_service_name(), reg_msg.get_service_name()) != 0))
	{
	  /* 
	     service not found, therefore report it back to client 
	  */
	  resp_for_reg.set_response_code(LOCCOM_SERVICE_NOT_FOUND);
	  MESSAGE ( ("Service not found!") );
	}
      else
	{
	  resp_for_reg.set_response_code(LOCCOM_REGISTRATION_OK);
	  MESSAGE ( ("I've got that service.") );
	}
	      
      reply(to_whom.get_client_socket(), resp_for_reg, sizeof(resp_for_reg));
    }
  else
    {
    /* 
       For sure, it is a request for a service.
    */
      // TODO: check the following procedure
      request_msg = malloc( sizeof(Deamon_Msg_Entry_Header) + 
			   entry_msg.get_parameters_size() );
      
      memcpy(request_msg, &entry_msg,
	     sizeof(Deamon_Msg_Entry_Header));
 
      where_to_place = static_cast<char*>(request_msg) + 
	sizeof(Deamon_Msg_Entry_Header);
 
      Loccom_Readwrite::readn(to_whom.get_client_socket(), where_to_place, 
			      entry_msg.get_parameters_size());
      
      entry = static_cast<Services_Table_Entry*>
	(services_table.search(entry_msg.get_service_code()));

      if (entry == NULL)
	  /* 
	     service not found, therefore ERROR 
	  */
	ERROR ( ("Wrong service request") )
      else
	// TODO: could be a thread!
	(entry->get_service_function())(to_whom.get_client_socket(),
					reinterpret_cast
					<
					Deamon_Msg_Entry_Header *
					> (request_msg) );   
    }
}

void Deamon_Reception_Point::start_deamon()
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
	    dispatcher(sockfd, &client[i], allset);

	  if (--nready <= 0) /* no more readable descriptors */
	    break;  
	} 
    } /* end of main for( ; ; ) */  
}

void Deamon_Reception_Point::add_service(long servc_code, 
					 char * servc_name,
					 Deamon_Service service, 
					 size_t response_size)
  // TODO: check for throw.
  //  throw (AlreadyRegistered)
{
  Services_Table_Entry * entry;

  entry = static_cast<Services_Table_Entry*>
    (services_table.search(servc_code));

  if (entry == NULL)
    {
      /* 
	 service not found, therefore register it 
      */
      entry = AllocNew (alloc, Services_Table_Entry) (servc_code, servc_name,
						      service, response_size);
      services_table.insert(entry);
      MESSAGE( ("Service %s registered.", servc_name) )
    }
  else
    MESSAGE ( ("Service was alredy there?") );
  // TODO: Check for throw.
  // Throw (AlreadyRegistered);
}

void Deamon_Reception_Point::reply(const Client_Id cli_id, 
				   Deamon_Msg_Exit_Header &exit_msg, 
				   const size_t size) const
{
  if (Loccom_Readwrite::writen(cli_id.get_client_socket(), 
			       &exit_msg, size) < 0)
    ERROR ( ("Unexpected error") ); 
}

void Deamon_Reception_Point::shutdown()
{
  close(listen_descriptor);
  services_table.removeAllAndDelete(alloc);
}

Deamon_Reception_Point::~Deamon_Reception_Point()
{
  shutdown();
}




