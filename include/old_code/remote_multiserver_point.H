#ifndef LOCATOR_COMM_POINT
#define LOCATOR_COMM_POINT

/*
  This is a class which serves as a client and server at the same time.
  So, it will take advantage of both the rpc-semantic and single-message
  semantic to solve efficiently the problem of sending messages.
 */

# include <aleph.H>
# include <pthread.h>
# include <slink.H>
# include "ipcClient.H"
# include "base_message_header.H"
# include "remote_multiserver_binding.H"


typedef int (*Sync_Service_Fct) (Msg_Entry_Header *, 
				 Remote_Multiserver_Binding *);

typedef int (*Async_Service_Fct) (Msg_Entry_Header *);

class Remote_Multiserver_Point
{
   /// Client_Binding needs to access some of the private members. 
  friend class Remote_Multiserver_Binding;

  Ipc_MultiClient_Server * ptr_reception_deamon;

  enum Sending_Type
  {
    LOCCOM_RPC,
    LOCCOM_ASYNC,
  };

  void sending_check (const Port & target_port,
		      Msg_Entry_Header * request,
		      size_t request_size,
		      Sending_Type)
    throw (std::exception, NotFound);
  
  /** 
      This variable indicates whether the server is requested 
      to be shutdown or not.
  */
  bool is_shutdown;

  /// main receiving thread for the deamon.
  pthread_t deamon_thread;

  /** 
      Number of actual active services. It has to be 0 so that the server
      can safely be shutdown.
  */
  size_t active_services;

  /**
     This mutex helps in keeping safe the critical sections of code
     which has to do with shutdown procedure.
  */
  pthread_mutex_t shutdown_lock;

  pthread_cond_t wait_for_shutdown;

  /** 
      This mutex helps whenever this class is intended for multiple 
      clients using. So, it is possible for several clients to simultaneously
      send a message. 
  */
  pthread_mutex_t lock_send;

  /**
     Condition variable in which the system waits until there are no more
     active services.
  */
  pthread_cond_t exists_act_serv;

  /** 
      This routine deciphers the message and either invokes the service
      or takes the corresponding system action.
  */  

  void dispatcher(Msg_Entry_Header *, Remote_Multiserver_Binding *); 

  /**
     This is the receiving function. It is static because it is going to 
     execute in a separate thread.
  */
  static void * locator_deamon_engine(void *) 
    throw (std::exception, SizeFault);

  class Service
  {    
    char             service_name[80];

    Service()
    {
      // empty
    }
    
  protected:
    Service(char * _service_name)
    {
      strcpy(service_name, _service_name);
    }
    
  public:
    char * get_service_name() const
    {
      return const_cast<char*>(service_name);
    }

    virtual long who_am_i() = 0;

    virtual int execute_service(Msg_Entry_Header *, 
				Remote_Multiserver_Binding *) = 0;
  };

  class Async_Service : public Service
  {
    Async_Service_Fct async_fct;
  
  public:
    Async_Service(char * _serv_name,
		  Async_Service_Fct _async_fct) :
      Service(_serv_name),
      async_fct(_async_fct)
    {
      // empty
    }
      
    virtual int execute_service(Msg_Entry_Header * ptr_entry_header,
				Remote_Multiserver_Binding * return_point = NULL)
    {
      ASSERT(return_point == NULL);

      return (*async_fct)(ptr_entry_header);
    }    

    virtual long who_am_i()
    {
      return LOCCOM_ASYNC;
    }
  };
  
  class Sync_Service : public Service
  {
    Sync_Service_Fct sync_fct;
    
  public:
    Sync_Service(char * _serv_name,
		 Sync_Service_Fct _sync_fct) :
      Service(_serv_name),
      sync_fct(_sync_fct)
    {
      // empty
    }
      
    virtual int execute_service(Msg_Entry_Header * ptr_entry_header,
				Remote_Multiserver_Binding * return_point)
    {
      ASSERT(return_point != NULL);

      return (*sync_fct)(ptr_entry_header, return_point);
    }

    virtual long who_am_i()
    {
      return LOCCOM_RPC;
    }
  };

  Dlink binding_list;
  
  struct Binding_Node : public Dlink 
  {
    Remote_Multiserver_Binding * binding_point;
    
    Binding_Node(Remote_Multiserver_Binding * _binding_point) :
      binding_point(_binding_point)
      {
	// empty
      }
  };

  void binding_list_freeing_fct();

  /// number of services you pretend to have in your server.
  size_t   number_of_services;

  /** 
      Number of services you have actually registered. It is going to be
      incremented as services are being registered.
  */
  size_t   registered_services;

  GenAlloc & alloc;

  /**
     Table of services.
  */

  Service ** table;


  /**
     The following two routines manages the variable
     active_services. This is done in order to have a proper shutting
     down of the server when required.  
  */
  void increase_active_services();
  
  void decrease_active_services();

  MsgId dispatched_message_id;

public:  
  /**
     This constructs a reception point at server's side.

     @param local_locator is the common point between the client
     and the server. Remember to specify the same path and file in the
     access point and the reception point.
     @param no_of_services especifies the number of services at server's side.
  */
  Remote_Multiserver_Point(unsigned int /* no_of_services */, 
		     GenAlloc & _alloc = *objectAlloc);
    
  /** 
     Starts the deamon in a separate thread. So, remember the
     call to start_deamon() is a non-blocking one. You could also
     save the address of the thread in case you want to join it
     later.
  */
  pthread_t * start_deamon()
    throw (std::exception, UnexpectedException);
  
  /**
    This routine registers a service at server side.
    You have to be coherent with User_Service_Codes, and the string
    which helps to indentify a service specified in Service_Fct.

    Also remember that Service_Fct is of the type:
    typedef int (*Service_Fct) (Local_Binding, Local_Msg_Entry_Header *);

    See also the example testServer.C which shows the form of the service
    routine.    
  */
  
  void include_service(long, Service *)
    throw (std::exception, Duplicated);
  
  void add_service(long, char *, Async_Service_Fct);
  
  void add_service(long, char *, Sync_Service_Fct);
  
  /** 
      Sending functions.
  */
  void rpc_send(const Port & target_port,
		Msg_Entry_Header * request,
		size_t request_size) 
    throw (std::exception, NotFound);
  
  void rpc_send(const Port & target_port,
		Msg_Entry_Header * request,
		size_t request_size,
		void * invocation, 
		size_t invocation_size) 
    throw (std::exception, NotFound); 
  
  MsgId rpc_send_to_other_server(const Port & /*target_port*/,
				 Msg_Entry_Header * /*request*/,
				 size_t /*request_size*/,
				 void * /*invocation*/, 
				 size_t /*invocation_size*/);
  
  MsgId rpc_send_to_other_server(const Port & /*target_port*/,
				 Msg_Entry_Header * /*request*/,
				 size_t /*request_size*/);
  
  void async_send(const Port & target_port,
		  Msg_Entry_Header * request) 
    throw (std::exception, NotFound);
  
  /** 
      Deletes a service at server's side, so that a new request after
      the deletion can be completed.
  */
  void delete_service(long)
    throw (std::exception, NotFound);

  /// Invokes shutdown()
  const Port & get_port() const
  {
    return  ptr_reception_deamon->get_port();
  }

  const MsgId get_dispatched_message_id() const
  {
    return dispatched_message_id;
  }

  /**
    It Shuts down the server. Before the complete shutting down, the server
    accomplish all the pending requests and then disapears.
    Future client requests are going to get a non-reachable server
    error, that must be handled at clients side.
  */
  void shutdown();
    
  /// Invokes shutdown() 
  ~Remote_Multiserver_Point()
  {
    MESSAGE("Entering to destructor");
    if (!is_shutdown)
      shutdown();
  }
  
};

#endif // LOCATOR_COMM_POINT






