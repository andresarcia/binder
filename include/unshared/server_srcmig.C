# include <aleph.H>
# include "locator_calls.H"

// USAGE:
// server_srcmig <target_site_id> <n_times in service loop>

# define RECEPTION_BUFFER_SIZE 4096

int main(int argc, char ** argv)
{
  if (argc == 1)
    {
      cout << "usage: server_srcmig <tgt_site_id> <number of services>" << endl;
      exit(0);
    }
  
  bootstrap_services();

  char tmp_string[Uid::stringSize];

  char reception_buffer[RECEPTION_BUFFER_SIZE];

  ASSERT(argc >= 2);

  Site_Id   this_site(INVALID_SITE_ID);

  get_site_id(this_site);
  
  Object_Id this_object;

  Container_Id this_container;

  // REGISTRATION STAGE
  register_cnt(this_container);

  register_obj(this_object, this_container);

  Locator   this_object_loc(this_object, this_site);

  MESSAGE("Site ID: %s", this_site.getStringUid(tmp_string, 
						 Uid::stringSize));
  MESSAGE("Object ID: %s", this_object.getStringUid(tmp_string, 
						     Uid::stringSize));
  
  Binding binding(this_object_loc, this_container, this_site);

  Message_Id msg_id;

  int n_times = argc == 3 ? atoi(argv[2]) : -1;

  // the target_site_id is the future place of this object.
  Site_Id target_site_id(argv[1]);

  Reception_Type reception_type;

  size_t reception_size;

  for (int i = -1; 
       (i < n_times - 1) || (n_times == -1); 
       n_times==-1 ? n_times = -1 : i++)
    {
      MESSAGE("SERVER SAYS: Waiting for a service request");
      
      reception_size = RECEPTION_BUFFER_SIZE;

      msg_id = multi_receive(binding, this_container, reception_buffer, 
			     reception_size, reception_type);

      ASSERT(reception_type == RECTYPE_INVOCATION_REQUEST);

      // processing of the invocation
      MESSAGE("SERVER SAYS: The invocation was: %s", reception_buffer);
      /*
	strcpy(reception_buffer, "answer2hello");
	MESSAGE("The reply is: %s", reception_buffer);
      
	sleep(3);
      */
      MESSAGE("SERVER SAYS: Replying to the request");
      srv_invoke_reply(msg_id, 
		       binding, 
		       this_container, 
		       reception_buffer, 
		       reception_size);
    }

  src_unreg_mig_obj(this_object, target_site_id);

  unregister_cnt(this_container);

  return 0;
}

