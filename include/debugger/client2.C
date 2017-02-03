# include <aleph.H>
# include "locator_calls.H"
# include "port.H"

# define RECEIVE_BUFFER_SIZE 65535

int get_rand(int min_number, int max_number)
{
  ASSERT((max_number - min_number) >= 0);

  if (max_number == min_number)
    return max_number;

  max_number = max_number - min_number + 1;

  int ret_val = min_number;
  
  float value = static_cast<float>(max_number)*rand()/(RAND_MAX+1.0);
  
  ret_val += static_cast<int>(value);
  
  ASSERT(ret_val >= min_number && ret_val <= (min_number + max_number - 1));

  return ret_val; 
}


int main(int argc, char ** argv)
{ 
  if (argc == 1)
    {
      cout << "usage: client2 <Site_Id> <Obj_Id> <#invocations> <invocation_size> <pause_time (usec)>" << endl;
      exit(0);
    }

  bootstrap_services();

  Object_Id rem_obj(argv[2]);
  
  int n_times = atoi(argv[3]);
  
  // Especification of local data.  
  Site_Id   rem_site(argv[1]), this_site(INVALID_SITE_ID);
  get_site_id(this_site);

  Locator remote_object_loc(rem_obj, rem_site);

  Container_Id this_container;

  register_cnt(this_container);

  char strtmp[Uid::stringSize];

  MESSAGE("Container ID: %s", this_container.getStringUid(strtmp,
							   Uid::stringSize));

  Binding binding(remote_object_loc, this_container, this_site);
  
  //  int request_size = 13;

  Message_Id msg_id;

  Reception_Type reception_type;

  size_t invocation_size = atoi(argv[4]);

  size_t reply_size;

  char * invocation = new char [invocation_size];

  char * reply = new char [invocation_size];

  //fill(invocation, &invocation[invocation_size - 2], 'X');
  invocation[invocation_size - 1] = '\0'; 
  for (int j=0; j<=invocation_size-2; j++)
    invocation[j] = get_rand(65,91);
 
  
  //invocation[invocation_size - 1] = '\0';
  // cout << invocation_size;

  for (int i=0; i < n_times; i++)
    { 
      //      sprintf(request,"%s :: ReQuEsT # %3i",
      //      this_container.getStringUid(strtmp,Uid::stringSize), i);

      reply_size = RECEIVE_BUFFER_SIZE;

      try
	{
	  msg_id = clt_invoke_send(binding, invocation, invocation_size);
	}      
      catch(NotFound)
	{
	  ERROR("*** ERROR: Debe buscar un nuevo binding para el objeto");
	}

      msg_id = multi_receive(binding, this_container, reply, reply_size,
			     reception_type);

      ASSERT(reply_size == invocation_size); // doing an echo

      MESSAGE("Response for invocation: %s", reply);
      
      if (argc == 6)
	usleep(atol(argv[5]));
    }  

  unregister_cnt(this_container);

  delete [] invocation;

  return 0;
}





