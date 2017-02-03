# include "loccom_message_header.H"
# include "loccom_readwrite.H"
# include "deamon_access_point.H"
# include <ahExceptions.H>
# include <aleph.H>
# include <tpl_lhash.H>

int Deamon_Access_Point::client_socket_descriptor = 0;

// TODO: check for greater table length, which it is passed through 
// no_of_services.
LhashTable<long> 
Deamon_Access_Point::registered_services_table(hashFct);

Deamon_Access_Point::Deamon_Access_Point(const char * access_path, 
					 unsigned int no_of_services,
					 GenAlloc&    _alloc)
  : alloc(_alloc)
{
  int			status;  
  struct sockaddr_un	server_address; 

  // resizing the has table 
  registered_services_table.resize(no_of_services);

  ASSERT (client_socket_descriptor == 0);

  client_socket_descriptor = socket(AF_LOCAL, SOCK_STREAM, 0); 

  ASSERT (client_socket_descriptor > 0);  
 
  bzero(&server_address, sizeof(server_address));

  server_address.sun_family = AF_LOCAL;
  strcpy(server_address.sun_path, access_path);
 
  status = connect(client_socket_descriptor, (SA *) &server_address, 
		   sizeof(server_address)); 

  MESSAGE ( ("connect status: %i", status) );
  ASSERT (status >= 0);
}


void Deamon_Access_Point::send(const Deamon_Msg_Entry_Header
			       *request, const size_t size) const  
  //  throw (NoRegisteredService)
{
  Register_Table_Entry * entry;

  entry = static_cast<Register_Table_Entry*> 
    (registered_services_table.search(request->get_service_code()));

  if ((entry == NULL) && (request->get_is_from_deamon() == GENERAL_SERVICE))
    //    Throw (NoRegisteredService);
    ERROR( ("Not registered service!") );

  if (Loccom_Readwrite::writen(client_socket_descriptor, request, size) < 0)
    ERROR ( ("Unexpected error") );
}


void Deamon_Access_Point::receive(Deamon_Msg_Exit_Header & reply, 
				  const size_t size) 
{
  if (Loccom_Readwrite::readn(client_socket_descriptor, &reply, size) == 0)
    ERROR( ("Unexpected closing of socket") );
}


void Deamon_Access_Point::receive(Deamon_Msg_Exit_Header & reply, 
				  const size_t size_msg, 
				  void *buffer_addr, 
				  const size_t size_buf) 
{
  if (Loccom_Readwrite::readn(client_socket_descriptor, &reply, size_msg) == 0)
    ERROR( ("Unexpected closing of socket") );

  if (Loccom_Readwrite::readn(client_socket_descriptor, buffer_addr,
			      size_buf) == 0)  
    ERROR( ("Unexpected closing of socket") );
}  

 
void Deamon_Access_Point::add_service(const long service_code,
				      char name[]) 
  //      throw (AlreadyRegistered)
{
  Register_Message reg_msg(service_code, name);
  Response_For_Registration response_msg;
  Register_Table_Entry * entry;

  send(&reg_msg, sizeof(reg_msg));
  receive(response_msg, sizeof(response_msg));

  switch (response_msg.get_response_code())
    {
    case LOCCOM_REGISTRATION_OK :
      entry = AllocNew (alloc, Register_Table_Entry) (service_code, name);
      registered_services_table.insert(entry);     
      MESSAGE ( ("Registration of %s was OK", name) );
      break;
    case LOCCOM_SERVICE_NOT_FOUND:
      MESSAGE ( ("Service requiered was not found!") );
      // TODO: to include the exceptions
      //Throw (AlreadyRegistered);
      break;
    default : 
      MESSAGE ( ("Something weard is happening") );
    }
}
 
void Deamon_Access_Point::shutdown()
{
  close(client_socket_descriptor);
  registered_services_table.removeAllAndDelete(alloc);
  // TODO:
  // may be I should also free the mutexes.
}

Deamon_Access_Point::~Deamon_Access_Point()
{
  shutdown();
}











