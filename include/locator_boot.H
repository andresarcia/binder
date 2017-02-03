# ifndef LOCATOR_BOOT_H
# define LOCATOR_BOOT_H

# include "aleph.H"
# include "binder.H"
# include "protected_lhash.H"
# include "remote_multiserver_point.H"
# include "local_reception_point.H"
# include "locator_local_services.H"
# include "locator_remote_services.H"
# include "local_message_header.H"
# include "locator_caches.H"
# include "implicit_messages_module.H"


# define PRINT_PORT(the_port, type) {\
                     FILE * port_log = fopen("port_log","a");\
                     char port_str[Port::stringSize];\
                     the_port.getStringPort(port_str, Port::stringSize);\
                     fprintf(port_log, "%s:line %i: file %s:type %s\n",\
		     port_str, __LINE__, __FILE__, type);\
                     fclose(port_log);\
                     }

# define PRINT_ID(der_uid) {\
                        Uid &__uid(const_cast<Uid&>(der_uid));\
                        MESSAGE("ip: %X, port: %i, seqN: %i, ran: %i",\
				__uid.getIpAddr(),\
				__uid.get_port_number(),\
				__uid.get_counter(),\
				__uid.get_random_number());\
							    }
         
// Waiting_For_Remote_Response_Table
// This table stores the tuple <Message_Id, Binding_Point *>, which
// serves as a reception point to the invocation being processed.
// Once the processed invocation is ready at server's side, then it
// will be sent through the "Binding_Point *" stored in this table.

extern ProtectedLhashTable<Message_Id> * ptr_srv_response_point_table;

extern ProtectedLhashTable<MsgId> * ptr_wait_broadcast_resp_table;

// registered_object_table: keeps all the objects available within the site.

extern ProtectedLhashTable<Object_Id> * ptr_registered_object_table;

// registered_container_table: keeps all the containers living within a site.

extern ProtectedLhashTable<Container_Id> * ptr_registered_container_table;

// This mutex protects the server against multiple clients requesting the
// exact same service. It works as a way to serialize all the incomming 
// requests, when the server is busy processing a request.

extern pthread_mutex_t mutex_for_server_fcnt;

// This mutex protects the routines clt_invoke_receive and remote_service_
// receive_reply, both of them manage common tables, so that a client can
// pick up the answer (whether or not it is ready).

extern pthread_mutex_t mutex_for_client_fcnt;

extern pthread_mutex_t look_up_in_caches_mutex;


// This routine bootstraps the locator. The bootstraping is the initialization
// of all tables and data structures concerning the system (in this case the
// locator).

extern void locator_bootstrap(); 

// This routine shuts down the locator. Its function is to invoke 
// shutdown routines in each of the threads.

extern void shutdown_locator();

// This is the variable which identifies the locator seen from any other
// site.
extern Locator_Remote_Services * remote_server_id;

// This is the variable which identifies the locator from within the site.
// Many container could be accessing simultaniously the Locator through
// this identifier.
extern Local_Reception_Point * local_server_id;

// TODO: leave this OUT as soon as posible.
extern bool locator_is_shutdown;

extern Local_Reception_Point * bootstrap_local_services();

// Caches 

extern Cache_In * ptr_cache_in;

extern Cache_Out * ptr_cache_out;

extern Cache_Mig * ptr_cache_mig;

extern Cache_New_Bnds * ptr_cache_new_bnds;

extern Cache_Garbage * ptr_cache_garbage;

// defined in locator_location_module.C
extern void process_locator_anounce(const Locator &);


# ifdef WITH_IMPLICIT_MSGS
extern Implicit_Msg_Container * ptr_implicit_cnt; 
# endif

# endif // LOCATOR_BOOT_H


