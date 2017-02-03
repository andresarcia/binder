# include <aleph.H>
# include "locator_calls.H"

// USAGE:
// server_tgtmig <Object_Id> <Logical_Timestamp> <n_times in service loop>

# define RECEPTION_BUFFER_SIZE 4096

int main(int argc, char ** argv)
{
  if (argc == 1)
    {
      cout << "usage: server_tgtmig <object_id> <timestamp> <number of services>" << endl;
      exit(0);
    }

  bootstrap_services();

  ASSERT(argc >= 3);

  char tmp_string[Uid::stringSize];

  char reception_buffer[RECEPTION_BUFFER_SIZE];

  Site_Id   this_site(INVALID_SITE_ID);
  get_site_id(this_site);

  MESSAGE("MIGRATED OBJ SAYS: Site ID: %s", 
	   this_site.getStringUid(tmp_string, Uid::stringSize));
  
  MESSAGE("Press enter-key to continue...");
  char key;
  read(0, &key, 1);

  Object_Id migrated_object(argv[1]);

  Container_Id this_container;

  // REGISTRATION STAGE
  register_cnt(this_container);

  long logical_timestamp = atol(argv[2]);

  tgt_reg_mig_obj(migrated_object, this_container, logical_timestamp);

  Locator   migrated_object_loc(migrated_object, this_site);

  MESSAGE("Object ID: %s", migrated_object.getStringUid(tmp_string, 
						     Uid::stringSize));
  
  Binding binding(migrated_object_loc, this_container, this_site);

  Message_Id msg_id;

  Reception_Type reception_type;

  int n_times = argc == 4 ? atoi(argv[3]) : -1;

  size_t reception_size;

  for (int i = -1; 
       (i < n_times - 1) || (n_times == -1); 
       n_times==-1 ? n_times = -1 : i++)
    {
      reception_size = RECEPTION_BUFFER_SIZE;

      MESSAGE("MIGRATED OBJ SAYS: Waiting for a service request");
      msg_id = multi_receive(binding, this_container, reception_buffer, 
			     reception_size, reception_type);

      ASSERT(reception_type == RECTYPE_INVOCATION_REQUEST);

      // processing of the invocation
      MESSAGE("MIGRATED OBJ SAYS: The invocation was: %s", reception_buffer);
      /*
	strcpy(reception_buffer, "answer2hello");
	MESSAGE("The reply is: %s", reception_buffer);
      
	sleep(3);
      */
      MESSAGE("MIGRATED OBJ SAYS: Replying to the request");
      srv_invoke_reply(msg_id, binding, this_container, reception_buffer, 70);
    }

  unregister_cnt(this_container);

  return 0;
}
