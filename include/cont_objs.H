#ifndef CONT_OBJS_H
#define CONT_OBJS_H

# define RECEPTION_BUFFER_SIZE 4096

void * objects_function(void * arg)
{
  //  int n_times = *reinterpret_cast<int*>(arg);
  int n_times = -1; // forever

  char reception_buffer[RECEPTION_BUFFER_SIZE];

  char tmp_string[Uid::stringSize];

  Binding binding;

  Message_Id msg_id;
  
  Reception_Type reception_type;

  //  long service_time_usec;

  size_t reception_size;

  for (int services = -1; 
       (services < n_times - 1) || (n_times == -1); 
       n_times==-1 ? n_times = -1 : services++)
    {
      try
	{
	  {
	    CRITICAL_SECTION(&mutex_for_migration);
	    
	    if (object_migrating)
	      pthread_cond_wait(&wait_for_unregistration, 
				&mutex_for_migration);
	  }

	  reception_size = RECEPTION_BUFFER_SIZE;

	  msg_id = multi_receive(binding, this_container, reception_buffer, 
				 reception_size, reception_type);
	}
      catch (NotFound)
	{
	  ERROR("*** ERROR: Invalid reference, object not found.");
	}
      catch (ObjectDead)
	{
	  ERROR("*** ERROR: Object is dead.");
	  // TODO: Delete reference.
	}
      catch (RecentBinding new_binding)
	{
	  MESSAGE ("*** Reinvoking ***");

	  reinvocations++;

	  // Update reference
	  for (int j = 0; j < n_refs; j++)
	    if (array_of_refs[j].get_object_id() == 
		binding.get_object_id())
	      array_of_refs[j] = new_binding.get_binding().get_locator();
	  
	  implicit_locate(binding);

	  // Invoke again
	  sprintf(reception_buffer,"%s :: REINVOKING ",
		  binding.get_source_container_id().
		  getStringUid(tmp_string,Uid::stringSize));
	  
	  try
	    {
	      msg_id = clt_invoke_send(binding, 
				       reception_buffer, 
				       strlen(reception_buffer) + 1);	  
	    }      
	  catch(NotFound)
	    {
	      ERROR("*** ERROR: El objeto no se encontro.");
	    }	  
	  
	  continue;
	}

      if (reception_type == RECTYPE_INVOCATION_REQUEST)
	{
	  // processing of the invocation. Dispatcher.
	  MESSAGE("Invocation to Object %s",
		   binding.get_object_id().
		   getStringUid(tmp_string, Uid::stringSize));
	  MESSAGE("The invocation was: %s", reception_buffer);
	  MESSAGE("with size: %i", reception_size);
	  
	  //service_time_usec = get_rand(100000, 350000);
	  //service_time_usec = get_rand(50000, 100000);
	  //usleep(service_time_usec);

	  MESSAGE("Replying to the request");
	  srv_invoke_reply(msg_id, binding, 
			   this_container, 
			   reception_buffer, 
			   reception_size);
	}
      else
	if (reception_type == RECTYPE_INVOCATION_REPLY)
	  MESSAGE("Response to an invocation: %s", reception_buffer);
	else
	  ERROR("*** ERROR: Unknown type of message. Check the code.");
    }

  return NULL;
}

# endif //CONT_OBJS_H

