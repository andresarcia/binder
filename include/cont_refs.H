#ifndef CONT_REFS_H
#define CONT_REFS_H
/*
struct Reference_Args
{
  Binding binding;
  unsigned n_times;
  
  Reference_Args(const Binding & _binding, unsigned iter) :
    binding(_binding),
    n_times(iter)
  {
    // empty
  }
};
*/

void * references_function(void * arg)
{
  int n_times = *reinterpret_cast<int*>(arg);
  
  int rand_number;

  char tmp_string[Uid::stringSize];

  char request[256];
  
  Message_Id msg_id;
      
  int random_ref;

  Binding binding;

  long wait_between_events;

  Container_Node * cont_node;

  Object_Node * obj;

  for (int i = 0 ; i < n_times; i++)
    { 
      rand_number = get_rand(1, 100);

      ASSERT(rand_number >= 1 && rand_number <= 100);

      if (rand_number <= 10) // migration probability
	{
	  CRITICAL_SECTION(&mutex_for_migration);
	  
	  if (n_objs == 0)
	    continue;
	  
	  rand_number = get_rand(1, n_objs);
	  
	  ASSERT(rand_number >= 1 && rand_number <= n_objs);
	  
	  obj = get_ith_elem<Object_Node>(objs_list, rand_number);
	  
	  ASSERT(obj != NULL);
	  
	  if (obj->get_allowed_to_migrate() == true)
	    {
	      obj->set_allowed_to_migrate(false);
	      
	      do
		{ 
		  rand_number = get_rand(1, n_cnts);
		  
		  cont_node = get_ith_elem<Container_Node>
		    (cnt_list, rand_number);
		  
		  ASSERT(cont_node != NULL);
		  
		} while (cont_node->get_container_port() ==
			 migration_thread->get_port());
	      
	      Do_Tgt_Registration reg_msg(obj->get_object_id(),
					  cont_node->get_container_id(),
					  obj->get_logical_timestamp() + 1);
	      
	      migration_thread->rpc_send(cont_node->get_container_port(),
					&reg_msg, sizeof(reg_msg));
	    }
	}
      else // execute a reference, probability = 0.9
	{
	  MESSAGE("Normal reference");
  
	  invocations++;
	  //	  MESSAGE("Invocations: %i, Reinvocations %i", 
	  //      invocations, reinvocations);
	  // choose a random locator to assign it as a reference.
	  random_ref = get_rand(0, n_refs - 1);
	  
	  ASSERT(random_ref >= 0 && random_ref <= n_refs-1);

	  binding = Binding(array_of_refs[random_ref],
			    this_container,
			    this_site); 	
	  
	  sprintf(request,"%s :: REQUEST #%i",
		  binding.get_source_container_id().
		  getStringUid(tmp_string,Uid::stringSize), i);
	  MESSAGE("REQUEST SIZE: %i", strlen(request));
	  try
	    {
	      msg_id = clt_invoke_send(binding,request,strlen(request)+1);  
	    }      
	  catch(NotFound)
	    {
	      ERROR("*** ERROR: El objeto no se encontro.");
	    }

	  // TODO: Find a better way to communicate a RECENT_BINDING state
	  // TODO: to the client.
	  if (binding.get_locator() > array_of_refs[random_ref])
	    array_of_refs[random_ref] = binding.get_locator();
	}
      
      wait_between_events = get_rand(300000, 500000);

      usleep(wait_between_events);
    }  

  MESSAGE("****************************************");
  MESSAGE("Numero de invocaciones: %i", invocations);
  MESSAGE("Numero de fallas: %i", reinvocations);
  MESSAGE("****************************************");

  return NULL;
}

#endif // CONT_REFS_H
