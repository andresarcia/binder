# include "locator_boot.H"
# include "locator_tables.H"
# include "locator_caches.H"
# include "implicit_messages_module.H"
# include "locator_remote_services.H"
# include "locator_pars.H"

# define NO_OF_LOCAL_SERVICES 17

// Waiting_For_Remote_Response_Table
// This table stores the tuple <Message_Id, Binding_Point *>, which
// serves as a reception point to the invocation being processed.
// Once the processed invocation is ready at server's side, then it
// will be sent through the "Binding_Point *" stored in this table.

ProtectedLhashTable<Message_Id> * ptr_srv_response_point_table;

ProtectedLhashTable<MsgId> * ptr_wait_broadcast_resp_table;

ProtectedLhashTable<Object_Id> * ptr_registered_object_table;

ProtectedLhashTable<Container_Id> * ptr_registered_container_table;

unsigned long locator_hash_fct(const Uid & key)
{
  return static_cast<unsigned long>(key.get_random_number());
}

unsigned long msgid_hash_fct(const MsgId & key)
{
  return static_cast<unsigned long>(key.getTimeSec());
}

// Caches 

unsigned Cache_In::instance_counter = 0;
unsigned Cache_Out::instance_counter = 0;
unsigned Cache_Mig::instance_counter = 0;
unsigned Cache_New_Bnds::instance_counter = 0;
unsigned Cache_Garbage::instance_counter = 0;
int Locator_Remote_Services::instance_counter = 0;


Cache_In * ptr_cache_in;

Cache_Out * ptr_cache_out;

Cache_Mig * ptr_cache_mig;

Cache_New_Bnds * ptr_cache_new_bnds;

Cache_Garbage * ptr_cache_garbage;

pthread_mutex_t mutex_for_server_fcnt;

pthread_mutex_t mutex_for_client_fcnt;

pthread_mutex_t look_up_in_caches_mutex;

bool locator_is_shutdown;

# ifdef WITH_IMPLICIT_MSGS
Implicit_Msg_Container * ptr_implicit_cnt; 
# endif

// This is the variable which identifies the locator from within the site.
// Many container could be accessing simultaniously the Locator through
// this identifier.

Local_Reception_Point * local_server_id;

Locator_Remote_Services * remote_server_id;

void locator_bootstrap()
{
  static ProtectedLhashTable<Message_Id> 
    srv_response_point_table(locator_hash_fct, wait_response_table_size);
  // The broadcast response hash table
  static ProtectedLhashTable<MsgId> 
    wait_broadcast_resp_table(msgid_hash_fct, wait_broadcast_resp_table_size);
  // The registered objects table:
  static ProtectedLhashTable<Object_Id>  
    registered_object_table(locator_hash_fct, object_table_size);
  // The registered containers table:
  static ProtectedLhashTable<Container_Id>  
    registered_container_table(locator_hash_fct, container_table_size);

  // Table initilization
  ptr_srv_response_point_table = &srv_response_point_table;
  ptr_registered_object_table = &registered_object_table;
  ptr_registered_container_table = &registered_container_table;
  ptr_wait_broadcast_resp_table = &wait_broadcast_resp_table;
 
  // Cache initilization
  static Cache_In cache_in(locator_hash_fct, cache_in_size);
  static Cache_Out cache_out(locator_hash_fct, cache_out_size);
  static Cache_Mig cache_mig(locator_hash_fct, cache_migration_size);
  static Cache_New_Bnds cache_new_bnds(locator_hash_fct, 
				       cache_new_bindings_size);
  static Cache_Garbage cache_garbage(locator_hash_fct, cache_garbage_size);

  ptr_cache_in = &cache_in;
  ptr_cache_out = &cache_out;
  ptr_cache_mig = &cache_mig;
  ptr_cache_new_bnds = &cache_new_bnds;
  ptr_cache_garbage = &cache_garbage;

  // Initialization of implicit message container
# ifdef WITH_IMPLICIT_MSGS
  static Implicit_Msg_Container implicit_cnt(implicit_message_cnt_size, 
					     implicit_msg_dead_age);

  ptr_implicit_cnt = &implicit_cnt;
# endif

  // Locks initialization
  pthread_mutex_init(&mutex_for_server_fcnt, NULL);
  pthread_mutex_init(&mutex_for_client_fcnt, NULL);
  pthread_mutex_init(&look_up_in_caches_mutex, NULL);
}


void shutdown_locator()
{
  MESSAGE("Shutting down the Locator...");

  local_server_id -> shutdown();

  remote_server_id -> shutdown();

  pthread_mutex_destroy(&mutex_for_server_fcnt);
  
  pthread_mutex_destroy(&mutex_for_client_fcnt);
  
  pthread_mutex_destroy(&look_up_in_caches_mutex);

  locator_is_shutdown = true;
}



Local_Reception_Point * bootstrap_local_services()
{
  Local_Locator      services_locator(Default_Local_Services_File_Path);

  static Local_Reception_Point 
    local_locator_point(services_locator, NO_OF_LOCAL_SERVICES);
  
  // Registering Of Services.
  local_locator_point.add_service(GET_SITE_ID, "get site id", 
				  local_service_get_site_id);
  local_locator_point.add_service(REGISTER_CONTAINER, "register container", 
				  local_service_register_cnt);
  local_locator_point.add_service(UNREGISTER_CONTAINER, "unregister container",
				  local_service_unregister_cnt);
  local_locator_point.add_service(REGISTER_OBJECT, "register object",
				  local_service_register_obj);
  local_locator_point.add_service(UNREGISTER_OBJECT, "unregister object",
				  local_service_unregister_obj);
  local_locator_point.add_service(TARGET_REG_MIG_OBJECT, 
				  "target reg mig object",
				  local_service_tgt_reg_mig_obj);
  local_locator_point.add_service(SOURCE_UNREG_MIG_OBJECT, 
				  "source unreg mig object",
				  local_service_src_unreg_mig_obj);
  local_locator_point.add_service(TARGET_REG_MIG_CONTAINER, 
				  "target reg mig container",
				  local_service_tgt_reg_mig_cnt);
  local_locator_point.add_service(SOURCE_UNREG_MIG_CONTAINER, 
				  "source reg mig container",
				  local_service_src_unreg_mig_cnt);
  local_locator_point.add_service(STRONG_LOCATE, "strong locate", 
				  local_service_strong_locate);
  local_locator_point.add_service(WEAK_LOCATE, "weak locate", 
				  local_service_weak_locate);
  local_locator_point.add_service(IMPLICIT_LOCATE, "implicit locate", 
				  local_service_implicit_locate);
  local_locator_point.add_service(CLIENT_INVOKE_SEND, "client invoke send", 
				  local_service_clt_invoke_send);
  local_locator_point.add_service(LOCATOR_SUPER_RECEIVE, 
				  "locator super receive",
				  local_service_locator_super_receive);
  local_locator_point.add_service(SERVER_INVOKE_REPLY, 
				  "server invoke reply",
				  local_service_srv_invoke_reply);  
  local_locator_point.add_service(TEST_OBJECT_LOCATION,
				  "test object location",
				  local_service_test_object_location);
  local_locator_point.add_service(PING_N_OBJECTS,
				  "ping n objects",
				  local_service_ping_n_objects);

  return &local_locator_point;
}

# undef NO_OF_LOCAL_SERVICES

