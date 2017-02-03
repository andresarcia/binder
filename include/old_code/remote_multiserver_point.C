# include "remote_multiserver_point.H"
# include <pthread.h>

Remote_Multiserver_Point::
Remote_Multiserver_Point(unsigned int no_of_services, 
			 GenAlloc & _alloc = *objectAlloc) :
  is_shutdown(false),
  active_services(0),
  number_of_services(no_of_services),
  registered_services(0),
  alloc(_alloc)
{
 table = AllocNew (alloc, Service *) [no_of_services];

  for (size_t i = 0; i < no_of_services; i++)
    table[i] = NULL;

  pthread_mutex_init(&shutdown_lock, NULL);  
  
  pthread_mutex_init(&lock_send, NULL);

  pthread_cond_init(&wait_for_shutdown, NULL);

  ptr_reception_deamon = AllocNew(alloc, Ipc_MultiClient_Server);

  char strP[Port::stringSize];
  
  MESSAGE("Locator Port: %s", ptr_reception_deamon 
	   ->get_port().getStringPort(strP, Port::stringSize));
}


pthread_t * Remote_Multiserver_Point::start_deamon()
  throw (std::exception, UnexpectedException)
{
  if (pthread_create(&deamon_thread, NULL, locator_deamon_engine, this) != 0)
    Throw (UnexpectedException) ();
  
  return &deamon_thread;
}


# define RECEPTION_BUFFER_SIZE 4096

void * 
Remote_Multiserver_Point::locator_deamon_engine(void * _loc_com_point_addr)
  throw(std::exception, SizeFault)
{
  typedef Msg_Entry_Header  DMEH; 
  Remote_Multiserver_Point   * ptr_loc_comm_point = 
    static_cast<Remote_Multiserver_Point *>(_loc_com_point_addr);

  char                     message_buffer[RECEPTION_BUFFER_SIZE]; 

  RawMsg                   incomming_message(&message_buffer[0], 
					     RECEPTION_BUFFER_SIZE,
					     RawMsg::DEFAULT_FLAG);

  Remote_Multiserver_Binding     * ptr_client_binding;

  // this message is going to be freed later on other rutine.  
  void                     * message_to_dispatcher;

  // while is not required to be shutdow
  for ( ; !ptr_loc_comm_point->is_shutdown ;  ) 
    {
      MESSAGE("*** Waiting for Remote Requests ***");
      
      incomming_message.setBodySize(RECEPTION_BUFFER_SIZE);

      // Wait for incoming message
      ptr_loc_comm_point->dispatched_message_id = ptr_loc_comm_point->
	ptr_reception_deamon->receive(incomming_message);
      
      if (incomming_message.getBodySize() > RECEPTION_BUFFER_SIZE)
	Throw (SizeFault) (incomming_message.getBodySize());

      //    take off the system message from ipc message
      message_to_dispatcher = Malloc(incomming_message.getBodySize());

      //    copy the system message into new location
      memcpy(message_to_dispatcher, 
	     incomming_message.getBodyAddr(), 
	     incomming_message.getBodySize());

      // Ask for message type: is it rpc_send or single_message.
      // Depending on that, it will be seen whether it is  necesary 
      // or not to allocate a remote_binding.
      switch (incomming_message.getFlags())
	{
	case RawMsg::RPC_REQUEST :
	  //    put into the binding list the new request for service.
	  //    It will be freed later at destruction time.
	  ptr_client_binding = AllocNew(ptr_loc_comm_point->alloc, 
					Remote_Multiserver_Binding) 
	    (ptr_loc_comm_point, ptr_loc_comm_point->dispatched_message_id);   
	  ptr_loc_comm_point->
	    binding_list.append(AllocNew(ptr_loc_comm_point->alloc, 
					 Binding_Node)
				(ptr_client_binding));
	  break;
	case RawMsg::RPC_REPLY :
	  //   MESSAGE("An RPC_REPLY");
	  //   for this type of message it is necesary an asyncronous service.
	  ptr_client_binding = NULL;
	  break;
	case RawMsg::SINGLE_MESSAGE :
	  //   for this type of message it is necesary an asyncronous service.
	  MESSAGE("A SINGLE_MESSAGE");
	  ptr_client_binding = NULL;
	  break;
	default:
	  ERROR("Panic: Receiving unidentified message!");
	}
      
      //    check for binding-list entries ready to be freed.
      ptr_loc_comm_point->binding_list_freeing_fct(); 

      //    pass it to the dispatcher
      ptr_loc_comm_point->dispatcher(reinterpret_cast<DMEH*>
				     (message_to_dispatcher),
				     ptr_client_binding); 
    }
  return 0;
}
# undef RECEPTION_BUFFER_SIZE

void 
Remote_Multiserver_Point::include_service(long servc_code, Service * service)
  throw (std::exception, Duplicated)
{
  ASSERT(servc_code < number_of_services);

  if (table[servc_code] == NULL)
    {
      ASSERT(registered_services < number_of_services);

      /* service not found, therefore register it */
      table[servc_code] = service;
      
      registered_services++;

      // MESSAGE("Service %s registered.", service->get_service_name());
    }
  else
    {
      MESSAGE("ERROR: It seems that you intended a duplicated insertion!");
      
      AllocDelete(alloc, service);
      
      Throw (Duplicated) ();
    }
}


void  Remote_Multiserver_Point::add_service(long servc_code, 
					    char * _serv_name, 
					    Async_Service_Fct a_service)
{
  Service * serv = AllocNew(alloc, Async_Service)(_serv_name, a_service);
  
  include_service(servc_code, serv);
}

void  Remote_Multiserver_Point::add_service(long servc_code, 
					    char * _serv_name, 
					    Sync_Service_Fct s_service)
{
  Service * serv = AllocNew(alloc, Sync_Service)(_serv_name, s_service);
  
  include_service(servc_code, serv);
}


void Remote_Multiserver_Point::sending_check(const Port & target_port,
					     Msg_Entry_Header * request,
					     size_t request_size,
					     Sending_Type type)
  throw (std::exception, NotFound)
{  
  switch (request->get_deamon_service_code())
    {
    case DEMSERV_SEND :
      if (table[request->get_client_service_code()] == NULL)
	{
	  MESSAGE("Not registered service!");
	  Throw (NotFound) ();
	}
      break;
    case DEMSERV_SHUTDOWN :
      MESSAGE("Request for internal service");
      break;
    default:
      ERROR("*** ERROR: Unexpected service header");
      break;
    }
  
  ASSERT(request->get_parameters_size() >= 0);

  RawMsg request_message(request, request_size);
  
  switch (type)
    {
    case LOCCOM_RPC:
      ptr_reception_deamon->rpc_send_request(target_port, request_message);
      break;
    case LOCCOM_ASYNC:
      ptr_reception_deamon->send_message(target_port, request_message);
      break;
    default:
      ERROR("Error: Unexpected type of function.");
    }
}

void Remote_Multiserver_Point::async_send(const Port & target_port,
					  Msg_Entry_Header * request) 
  throw (std::exception, NotFound)
{
  ASSERT((request->get_deamon_service_code() == DEMSERV_SHUTDOWN) ||
	 (table[request->get_client_service_code()]->who_am_i() == 
	  LOCCOM_ASYNC));
	
  pthread_mutex_lock(&lock_send);
  try 
    {
      sending_check(target_port, 
		    request, 
		    // TODO: check this:
		    sizeof(Msg_Entry_Header) + request->get_parameters_size(), 
		    LOCCOM_ASYNC);
    }
  catch (...)
    {
      throw;
    }
  pthread_mutex_unlock(&lock_send);
}

void Remote_Multiserver_Point::rpc_send(const Port & target_port,
					Msg_Entry_Header * request,
					size_t request_size) 
  throw (std::exception, NotFound)
{
  ASSERT(table[request->get_client_service_code()]->who_am_i() == 
	 LOCCOM_RPC);

  pthread_mutex_lock(&lock_send);
  try 
    {
      sending_check(target_port, request, request_size, LOCCOM_RPC);
    }
  catch (...)
    {
      throw;
    }
  pthread_mutex_unlock(&lock_send);
}


void Remote_Multiserver_Point::rpc_send(const Port & target_port,
					Msg_Entry_Header * request,
					size_t request_size,
					void * invocation, 
					size_t invocation_size) 
  throw (std::exception, NotFound)
{
  ASSERT(table[request->get_client_service_code()]->who_am_i() == 
	 LOCCOM_RPC);

  pthread_mutex_lock(&lock_send);
  
  // size_t size = sizeof(Msg_Entry_Header) + request->get_parameters_size(); 
  size_t message_size = request_size + invocation_size;

  void * message = Malloc(message_size);

  // copy the first part of the message
  memcpy(message, request, request_size);
  
  // copy the second part of the message
  memcpy(static_cast<char*>(message) + request_size, 
	 invocation, invocation_size);

  // write it to the correspondent reception point
  try 
    {
      sending_check(target_port, 
		    reinterpret_cast<Msg_Entry_Header *>(message),
		    message_size,
		    LOCCOM_RPC);
    }
  catch (...)
    {
      throw;
    }

  Free(message);
  
  pthread_mutex_unlock(&lock_send);
}


// BE AWARE OF THIS:
// The correctness responsability belongs to the client, for this 
// method. The service being invoked in completly unknown by this
// class.

MsgId 
Remote_Multiserver_Point::rpc_send_to_other_server(const Port & target_port,
						   Msg_Entry_Header * request,
						   size_t request_size,
						   void * invocation, 
						   size_t invocation_size) 
{
  pthread_mutex_lock(&lock_send);
  
  // size_t size = sizeof(Msg_Entry_Header) + request->get_parameters_size(); 
  size_t message_size = request_size + invocation_size;
  
  void * message = Malloc(message_size);
  
  // copy the first part of the message
  memcpy(message, request, request_size);

  ASSERT(invocation != NULL);

  ASSERT(invocation_size > 0);

  // copy the second part of the message
  memcpy(static_cast<char*>(message) + request_size, 
	 invocation, invocation_size);
  
  ASSERT(reinterpret_cast<Msg_Entry_Header*>(message)->
	 get_parameters_size() >= 0);
  
  RawMsg request_message(message, message_size);
  
  MsgId msg_id = 
    ptr_reception_deamon->rpc_send_request(target_port, request_message);
  
  Free(message);
  
  pthread_mutex_unlock(&lock_send);

  return msg_id;
}

MsgId 
Remote_Multiserver_Point::rpc_send_to_other_server(const Port & target_port,
						   Msg_Entry_Header * request,
						   size_t request_size)
{
  pthread_mutex_lock(&lock_send);
  
  ASSERT(request->get_parameters_size() >= 0);
  
  RawMsg request_message(request, request_size);
  
  MsgId msg_id = 
    ptr_reception_deamon->rpc_send_request(target_port, request_message); 
  
  pthread_mutex_unlock(&lock_send);

  return msg_id;
}


void Remote_Multiserver_Point::delete_service(const long service_code)
  throw (std::exception, NotFound)
{
  if (table[service_code] == NULL)
    Throw (NotFound) ();
  else
    {
      AllocDelete (alloc, table[service_code]);
      table[service_code] = NULL;
    }
}


void Remote_Multiserver_Point::dispatcher(Msg_Entry_Header * in_message,
				    Remote_Multiserver_Binding  * to_whom)
{
  switch (in_message->get_deamon_service_code())
    {
    case DEMSERV_SEND:
      ASSERT(registered_services == number_of_services);

      if (table[in_message->get_client_service_code()] == NULL)
	ERROR("Wrong service requested");
      else
	{
	  /*
	    either run the service in the same server's thread or 
	    in a different one.
	  */
	  table[in_message->get_client_service_code()]->
	    execute_service(in_message, to_whom);
	  
	  Free(in_message);
	}
      break;

    case DEMSERV_SHUTDOWN:
      MESSAGE("A SHUTDOWN message has arrived (Remote_Access_Point)");

      pthread_mutex_lock(&shutdown_lock);
      
      Free(in_message);
      
      // activate the shutdown flag.
      is_shutdown = true;

      pthread_mutex_unlock(&shutdown_lock);

      pthread_cond_signal(&wait_for_shutdown);
      break;

    case DEMSERV_INVALID:
      MESSAGE("PANIC: An invalid message appeared");
      break;

    default:
      MESSAGE("PANIC: Check the code, a message with an unknown code arrived.");
      break;
    }
}


void Remote_Multiserver_Point::shutdown()
{
  ASSERT(is_shutdown == false);
  
  //  void * result;
  
  Shutdown_Message shutdown_msg;
  
  // sending the shutdown message.
  Port this_port(ptr_reception_deamon->get_port());

  // self sending of a message.  
  async_send(this_port, &shutdown_msg);

  pthread_mutex_lock(&shutdown_lock);
  
  if (!is_shutdown)
    pthread_cond_wait(&wait_for_shutdown, &shutdown_lock);
  
  pthread_mutex_unlock(&shutdown_lock);

  MESSAGE("Out shutdown waiting");

  // waiting for normal termination (through shutdown flag).
  // pthread_join(deamon_thread, (void **)&result);

  // free the registering table  
  for (size_t i=0; i < number_of_services; i++)
    if (table[i] != NULL)
      AllocDelete (alloc, table[i]);
  
  AllocDeleteArray (alloc, table);
  
  /* destoy mutex and condition variable */
  
  pthread_mutex_destroy(&shutdown_lock);
  
  pthread_cond_destroy(&wait_for_shutdown);

  // Destroy the binding points who last from the last freeing burst. 
  binding_list_freeing_fct();

  AllocDelete(alloc, ptr_reception_deamon);

  MESSAGE("The Remote Communication Thread has been shut down...");
}


void Remote_Multiserver_Point::binding_list_freeing_fct()
{
  Dlink * list_cursor;
 
  for ( list_cursor = binding_list.getNext(); 
	list_cursor != &binding_list && !binding_list.isEmpty(); )
    {
      if (static_cast<Binding_Node *>(list_cursor)->
	  binding_point->get_still_busy() == false || is_shutdown)
	{
	  AllocDelete(alloc, static_cast<Binding_Node *>
		      (list_cursor)->binding_point);
	  
	  list_cursor = list_cursor->getNext();
	  
	  AllocDelete(alloc, static_cast<Binding_Node *>
		      (list_cursor->removePrev()));
	}
      else 
	list_cursor = list_cursor->getNext();
    }
}



