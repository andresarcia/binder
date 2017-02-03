# include <aleph.H> 
# include "locator_calls.H"

int main(int argc, char ** argv)
{
  bootstrap_services();

  // Especification of local data.  
  Site_Id   rem_site(argv[1]), 
            this_site(INVALID_SITE_ID);

  get_site_id(this_site);

  Object_Id    rem_obj(argv[2]);
  
  Locator remote_object_loc(rem_obj, rem_site);

  Container_Id this_container;

  register_cnt(this_container);

  char strtmp[Uid::stringSize];

  MESSAGE("Container ID: %s", this_container.getStringUid(strtmp,
							   Uid::stringSize));

  Binding binding(remote_object_loc, this_container, this_site);

  char * request = "Hello world!";

  char reply[13];

  size_t request_size = 13;

  Message_Id 
    msg_id = clt_invoke_send(binding, request, request_size);

  Reception_Type reception_type; 

  msg_id = multi_receive(binding, this_container, reply,  request_size,
			 reception_type);
  
  MESSAGE("Response for invocation: %s", reply);

  return 0;
}





