# include <aleph.H>
# include "locator_calls.H"

int main(int argc, char ** argv)
{
  bootstrap_services();

  // Initialization from remote data.
  Object_Id rem_obj_one(argv[2]),
            rem_obj_two(argv[3]);

  int n_times = atoi(argv[4]);
  
  // Especification of local data.  
  Site_Id   rem_site(argv[1]), this_site(INVALID_SITE_ID);

  get_site_id(this_site);

  Locator remote_object_loc_one(rem_obj_one, rem_site),
    remote_object_loc_two(rem_obj_two, rem_site);

  Container_Id this_container;

  Reception_Type reception_type;

  register_cnt(this_container);

  char strtmp[Port::stringSize];

  MESSAGE("Container ID: %s", this_container.getStringUid(strtmp,
							   Port::stringSize));

  Binding binding_one(remote_object_loc_one, this_container, this_site),
    binding_two(remote_object_loc_two, this_container, this_site);
  
  char request[100];
  
  char reply[100];
      
  size_t reply_request_size = 70;

  Message_Id msg_id;


  for (int i=0; i < n_times; i++)
    { 
      sprintf(request,"%s :: PAIRS   # %2i",
	      this_container.getStringUid(strtmp, 
					  Port::stringSize), i*2);

      msg_id = clt_invoke_send(binding_one, request, reply_request_size);
      
      multi_receive(binding_one, this_container, reply, reply_request_size, 
		    reception_type);
      
      MESSAGE("Response for pair invoc.: %s", reply);
	
      sprintf(request,"%s :: ODDS    # %2i",
	      this_container.getStringUid(strtmp, 
					  Port::stringSize), i*2+1);

      msg_id = clt_invoke_send(binding_two, request, reply_request_size);
      
      multi_receive(binding_two, this_container, reply, reply_request_size, 
		    reception_type);
      
      MESSAGE("Response for odd invoc.: %s", reply);
    }  
  return 0;
}


