# ifndef LOCATOR_REMOTE_ROUTINES
# define LOCATOR_REMOTE_ROUTINES

# include "remote_multiserver_point.H"
# include "remote_message_header.H"
# include "broadcast_client.H"

# define NO_OF_REMOTE_SERVICES 12
// Internal service functions
extern void remote_reply(const Message_Id & /*message_id*/,
			 Invocation_Reply_Msg * /*reply_msg*/,
			 void * /*reply_buffer*/,
			 size_t /*reply_size*/);

class Locator_Remote_Services : 
  public Remote_Multiserver_Point<Locator_Remote_Services>,
  public Broadcast_Client<Locator_Remote_Services>
{
  Port broadcast_daemon_port;

  pthread_t * ptr_comm_thread;
  
  static int instance_counter;

  bool attach_to_broadcast_group;

  // Functions to be registered to work with modules.
  int remote_service_receive_reply(Msg_Entry_Header *);
  
  int remote_service_receive_invocation
  (Msg_Entry_Header *,
   Remote_Multiserver_Binding<Locator_Remote_Services> *);
  
  int remote_service_find_owner(Msg_Entry_Header *);

  int remote_service_gather_object_information
  (Msg_Entry_Header *,
   Remote_Multiserver_Binding<Locator_Remote_Services> * return_point);

  int remote_service_locator_anounce(Msg_Entry_Header *);

  int remote_service_dead_anounce(Msg_Entry_Header *);

  int remote_service_response_from_weak_find_owner(Msg_Entry_Header *);
  
  int remote_service_response_from_strong_find_owner(Msg_Entry_Header *);
  
  int remote_service_response_from_gather(Msg_Entry_Header *);

  int remote_service_receive_cache_in(Msg_Entry_Header *);

  int remote_service_ping_n_objects_request
  (Msg_Entry_Header *,
   Remote_Multiserver_Binding<Locator_Remote_Services> *);

  int remote_service_ping_reply_for_n_objects(Msg_Entry_Header *);

public:
  
  Locator_Remote_Services(const Port & _broadcast_port,
			  bool _attach_to_broad_group) :
    Remote_Multiserver_Point<Locator_Remote_Services>
                    (NO_OF_REMOTE_SERVICES, this),
    Broadcast_Client<Locator_Remote_Services>
                    (this, _broadcast_port),
    broadcast_daemon_port(_broadcast_port),
    attach_to_broadcast_group(_attach_to_broad_group)    
  {
    instance_counter ++; 

    ASSERT(instance_counter == 1);

    if (attach_to_broadcast_group)
      {
	try
	  {
	    join_group(get_port());
	  }
	catch (Duplicated)
	  {
	    MESSAGE("Intended duplication...");
	  }
      }

    ptr_comm_thread = start_deamon();

    add_service(INVOCATION_REQUEST, "invocation request", 
		&Locator_Remote_Services::remote_service_receive_invocation);
    
    add_service(INVOCATION_REPLY, "invocation reply",
		&Locator_Remote_Services::remote_service_receive_reply);


    add_service(FIND_OWNER, "find owner", 
		&Locator_Remote_Services::remote_service_find_owner);

    add_service(GATHER_OBJECT_INFORMATION, "gather object information", 
		&Locator_Remote_Services::remote_service_gather_object_information);
    
    add_service(RESPONSE_FROM_WEAK_FIND_OWNER, 
		"response from weak find owner", 
		&Locator_Remote_Services::
		remote_service_response_from_weak_find_owner);
    
    add_service(RESPONSE_FROM_STRONG_FIND_OWNER, 
		"response from strong find owner", 
		&Locator_Remote_Services::
		remote_service_response_from_strong_find_owner);
    
    add_service(RESPONSE_FROM_GATHER, "response from gather", 
		&Locator_Remote_Services::
		remote_service_response_from_gather);
    
    add_service(LOCATOR_ANOUNCE, "locator anounce", 
		&Locator_Remote_Services::remote_service_locator_anounce);
    
    add_service(DEAD_ANOUNCE, "dead anunce", 
		&Locator_Remote_Services::remote_service_dead_anounce);

    add_service(RECEIVE_CACHE_IN, 
		"receive cache in", 
		&Locator_Remote_Services::remote_service_receive_cache_in);
    
    add_service(PING_N_OBJECTS_REQUEST, 
		"ping n objects request",
		&Locator_Remote_Services::
		remote_service_ping_n_objects_request);
    
    add_service(PING_REPLY_FOR_N_OBJECTS,
		"ping reply for n objects",
		&Locator_Remote_Services::
		remote_service_ping_reply_for_n_objects);
  }

  void join_remote_services()
  {
    pthread_join(*ptr_comm_thread, NULL);
  }

  ~Locator_Remote_Services()
  {
    if (attach_to_broadcast_group)
      {
	try
	  {
	    leave_group(get_port());
	  }
	catch (NotFound)
	  {
	    MESSAGE("Not registered member");
	  }
      }

    MESSAGE("Locator Remote Services has been shutdown.");
  }
};

# undef NO_OF_REMOTE_SERVICES

# endif // LOCATOR_REMOTE_ROUTINES

