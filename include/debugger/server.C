# include <aleph.H>
# include "locator_calls.H"

// usage: server <number of iterations> <number of objects>

# define RECEPTION_BUFFER_SIZE 65535

int main(int argc, char ** argv)
{
  if (argc == 1)
    {
      cout << " usage: server <number of iterations> <number of objects>" 
	   << endl;
      exit(0);
    }

  bootstrap_services();

  char tmp_string[Uid::stringSize];

  char reception_buffer[RECEPTION_BUFFER_SIZE];

  Site_Id   this_site(INVALID_SITE_ID);

  get_site_id(this_site);

  cout << "Site ID: " 
       << this_site.getStringUid(tmp_string, Uid::stringSize)
       << endl;
  
  Object_Id this_object;

  Container_Id this_container;

  // REGISTRATION STAGE
  register_cnt(this_container);

  int number_of_objects = atoi(argv[2]);

  Object_Id * 
    array_of_objs = AllocNew(*objectAlloc, Object_Id) [number_of_objects];

  for (int obj_index = 0; obj_index < number_of_objects; obj_index ++)
    {
      register_obj(this_object, this_container);
      
      cout << "Object #"
	   << obj_index 
	   << " ID: "
	   << this_object.getStringUid(tmp_string, Uid::stringSize) << endl;
    }

  // TODO: missing an empty constructor for binding (or so).
  Binding binding;

  Message_Id msg_id;

  int n_times = argc == 3 ? atoi(argv[1]) : -1;

  Reception_Type reception_type;

  size_t reception_size;

  for (int services = -1; 
       (services < n_times - 1) || (n_times == -1); 
       n_times==-1 ? n_times = -1 : services++)
    {
      MESSAGE("Waiting for a service request");
      
      reception_size = RECEPTION_BUFFER_SIZE;

      msg_id = multi_receive(binding, this_container, reception_buffer, 
			     reception_size, reception_type);

      ASSERT(reception_type == RECTYPE_INVOCATION_REQUEST);

      // processing of the invocation
      MESSAGE("Invocation to Object %s",
	       binding.get_object_id().
	       getStringUid(tmp_string, Uid::stringSize));
      MESSAGE("The invocation was: %s", reception_buffer);
      MESSAGE("The invocation size: %i", reception_size);
      MESSAGE("Replying to the request");

      srv_invoke_reply(msg_id, binding, this_container, reception_buffer, 
		       reception_size);
    }

  unregister_cnt(this_container);

  AllocDeleteArray(*objectAlloc, array_of_objs);

  return 0;
}







