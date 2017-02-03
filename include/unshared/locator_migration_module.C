# include "locator_local_services.H"
# include "locator_boot.H"
# include "locator_tables.H"
# include "local_message_header.H"
# include "local_reception_point.H"
# include "remote_multiserver_point.H"
# include "remote_message_header.H"
# include "locator_remote_services.H"
# include <useMutex.H>

void send_cache_in(const Object_Id & object_id,
		   const Site_Id & tgt_site_id)
{
  try
    {
      // Find all entries in ptr_cache_in concerning to object_id
      Cache_In::Cache_In_Iterator iter(ptr_cache_in, object_id);
      
      unsigned position = 0, numb_of_entries = iter.count();
      
      void * entries_message = 
	Malloc(sizeof(struct Cache_In_Entries) + 
	       numb_of_entries * sizeof(struct Cache_In_Data));
      
      Cache_In_Entries message(object_id, numb_of_entries);
      
      memcpy(entries_message,
	     reinterpret_cast<void *>(&message), sizeof(message));
      
      // pack them all in the message 	
      struct Cache_In_Data * ptr_data = iter.get_current();
      
      do
	{
	  memcpy(static_cast<char*>(entries_message) + 
		 sizeof(message) + (position*sizeof(struct Cache_In_Data)),
		 ptr_data,
		 sizeof(struct Cache_In_Data));
	  position++;
	} while ((ptr_data = iter.delete_current()) != NULL);

      //TODO: delete it
      //PRINT_PORT(tgt_site_id, "async");
      
      // send asynchronoud  message to tgt_site_id.
      remote_server_id->async_send(tgt_site_id, 
				   reinterpret_cast<Msg_Entry_Header*>
				   (entries_message));
      
      Free(entries_message);
    }
  catch (NotFound)
    {
      // Cache_In_Entries message(object_id, 0 /*number of entries*/);
      
      // send asynchronous  message to tgt_site_id.
      // remote_server_id->async_send(tgt_site_id, &message);
    }           

  return;
}

void send_locator_anounce(const Site_Id & receiving_site, 
			  const Locator & locator)
{
  Locator_Anounce anounce_message(locator);

  //TODO: delete it
  //PRINT_PORT(receiving_site, "async");

  remote_server_id->async_send(receiving_site, &anounce_message);
}

void prefetching_with_cache_in(const Locator & new_locator)
{
  try
    {
      Cache_In::Cache_In_Iterator iter(ptr_cache_in, 
				       new_locator.get_object_id());
      
      struct Cache_In_Data * ptr_data = iter.get_current();
      
      do
	{
	  send_locator_anounce(ptr_data->source_site_id, new_locator);
	} while ((ptr_data = iter.delete_current()) != NULL);

# ifdef WITH_IMPLICIT_MSGS

      Implicit_Locator_Anounce_Msg 
	implicit_anounce(new_locator, new_locator.get_target_site_id());
    
      ptr_implicit_cnt->add_implicit_msg(implicit_anounce);

# endif 
    }
  catch(NotFound)
    {
      // empty
    }
}


int local_service_src_unreg_mig_obj (Binding_Point * return_point, 
				     Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Source Unregister Migratting Object ***");

  // Take the server lock
  CRITICAL_SECTION(&mutex_for_server_fcnt);
 
  // cast the input message
  Src_Unreg_Mig_Obj_CallMsg * casted_input_msg = 
    static_cast<Src_Unreg_Mig_Obj_CallMsg *>(input_msg);

  // unregister object procedure
  Src_Unreg_Mig_Obj_RetMsg return_message(LOCEXIT_OK);

  // Erase object_id from registered_object_table
  Registered_Object_Bucket * object_bucket;
  
  object_bucket = static_cast<Registered_Object_Bucket *>
    (ptr_registered_object_table->
     search(casted_input_msg->get_object_id()));

  if (object_bucket == NULL) // object not found, so report it back...
    {
      return_message.set_response_code(LOCEXIT_OBJECT_UNKNOWN);
      return_point->respond(&return_message, sizeof(return_message));
      return 0;
    }

  object_bucket->unLock();
  
  if (object_bucket->get_current_state() == OBJ_PROCESSING_INVOCATION)
    {
      return_message.set_response_code(LOCEXIT_OBJECT_BUSY);
      return_point->respond(&return_message, sizeof(return_message));
      
      // TODO: Mark the intention to migrate the object in a field of container
      // table, so that next inspection to the object lead to migration. 

      return 0;
    }

  // Prepare the ptr_cache_mig entry
  Locator lctor_for_cache_mig(casted_input_msg->get_object_id(),
			      casted_input_msg->get_tgt_site_id());
  
  // set and update the logical_timestamp
  lctor_for_cache_mig.
    set_logical_timestamp(object_bucket->get_logical_timestamp());
  
  lctor_for_cache_mig.increase_logical_timestamp();

  // Annotate the migration action in ptr_cache_mig. 
  
  Locator * searched_locator = 
    ptr_cache_mig->find_data_ptr(casted_input_msg->get_object_id());

  ptr_cache_mig->cache_unlock();

  if (searched_locator == NULL)
    ptr_cache_mig->insert(casted_input_msg->get_object_id(),
			  lctor_for_cache_mig);
  else
    // the lcto_for_cache_mig has to be newer that searched_locator
    // otherwise, inside update_locator method an exception will be thrown.
    searched_locator->update_locator(lctor_for_cache_mig);

  // Update cache out in case there is local invocation, that now becomes
  // remote invocation. The operation to perform is just update. This is 
  // in case you're thinking that an insertion could be posible. But, this
  // case is replaced by the searching in ptr_cache_mig when appropriate.
  Locator * 
    locator = ptr_cache_out->find_data_ptr(casted_input_msg->get_object_id());
  
  if (locator != NULL)
    locator->update_locator(lctor_for_cache_mig);

  ptr_cache_out->cache_unlock();

  answer_all_pending_replys_and_delete(object_bucket);
  
  return_point->respond(&return_message, sizeof(return_message));
  
  // Start doing prefetching with ptr_cache_in: tell the locators
  // from where invocation were made, the new target site. This action
  // could be done later if put as a future event. This prevents 
  // from not finding the cache_entries (due to a delay). This also
  // give freedom to the client to do prefetching whenever he wants.
  prefetching_with_cache_in(lctor_for_cache_mig);
  
  // Send the entries in ptr_cache_in concerning object_id to target site.
  send_cache_in(casted_input_msg->get_object_id(),
		casted_input_msg->get_tgt_site_id());
  
  // Erase the object_id entry from ptr_cache_in
  delete_entries_from_cache_in(casted_input_msg->get_object_id());

  return 0;
}


int local_service_tgt_reg_mig_obj (Binding_Point * return_point, 
				   Msg_Entry_Header * input_msg)
{
  MESSAGE("*** Target Register Migratting Object ***");
  
  // THE SYNCHRONIZATION BETWEEN SOURCE AND TARGET SITES ARE LEFT
  // TO THE CLIENT.

  // take the client lock, just in case some object, being in the
  // same locator, tries to invoke the migrated object.
  
  USE_MUTEX(mutex_clt, &mutex_for_client_fcnt);

  USE_MUTEX(mutex_srv, &mutex_for_server_fcnt);

  // cast the input message
  Tgt_Reg_Mig_Obj_CallMsg * casted_input_msg =
    static_cast<Tgt_Reg_Mig_Obj_CallMsg *>(input_msg);

  // write the object in registered_object_table
  Tgt_Reg_Mig_Obj_RetMsg reply(LOCEXIT_OK);
 
    
  Registered_Container_Bucket * container_bucket = 
    static_cast<Registered_Container_Bucket *>
    (ptr_registered_container_table->
     search(casted_input_msg->get_container_id()));
  
  if (container_bucket == NULL)
    {
      MESSAGE("*** CONTAINER UNKNOWN ***");
      // container not registered
      reply.set_response_code(LOCEXIT_CONTAINER_UNKNOWN);
      
      return_point->respond(&reply, sizeof(reply));
      
      return 0;
    }
  
  container_bucket->unLock();
  
  // The container is a valid container. So, proceed to register the
  // object.

  Registered_Object_Bucket * new_bucket, * searched_bucket;
  
  // find the bucket to see if there is an intended double registration.
  searched_bucket = static_cast<Registered_Object_Bucket *>
    (ptr_registered_object_table->
     search(casted_input_msg->get_object_id()));
  
  if (searched_bucket == NULL)
    {
      const long long unsigned TIMESTAMP = 
	casted_input_msg->get_logical_timestamp();

      new_bucket = AllocNew(*objectAlloc, Registered_Object_Bucket)
	(casted_input_msg->get_object_id(),
	 casted_input_msg->get_container_id(),
	 TIMESTAMP);
      
      ptr_registered_object_table->insert(new_bucket);
    }
  else
    {
      searched_bucket->unLock();
      
      MESSAGE("*** ERROR: Intended object duplication");
      
      reply.set_response_code(LOCEXIT_INTENDED_DUPLICATION);
      
      return_point->respond(&reply, sizeof(reply));
      
      return 0;
    }

  // Insert the object into the container list.
  container_bucket->get_associated_objects_list().
    append(&new_bucket->get_link_to_container());
  
  // If everything is OK...
  return_point->respond(&reply, sizeof(reply));
  
  // Update the object_id entry from ptr_cache_out 
  Locator * locator_from_cache_out =
    ptr_cache_out->find_data_ptr(casted_input_msg->get_object_id());

  ptr_cache_out->cache_unlock();

  if (locator_from_cache_out != NULL)
    {
      Locator new_locator(casted_input_msg->get_object_id(),
			  static_cast<Site_Id>(remote_server_id->get_port()),
			  casted_input_msg->get_logical_timestamp());
      
      if (new_locator > *locator_from_cache_out)
	locator_from_cache_out->update_locator(new_locator);
    }

  return 0;
}

int Locator_Remote_Services::
remote_service_receive_cache_in (Msg_Entry_Header * input_msg)
{
  MESSAGE("CACHE_IN entries arrival");
  
  Cache_In_Entries * casted_input_msg =
    static_cast<Cache_In_Entries *>(input_msg);

  // take a lock which excludes local_tgt_reg_mig_obj and this 
  // routine.
  
  // take out all the entries from the message and insert them in 
  // ptr_cache_in
  
  ASSERT(casted_input_msg->get_number_of_entries() >= 0);
  
  for (unsigned n = 0; n < casted_input_msg->get_number_of_entries(); n++)
    {
      const struct Cache_In_Data * data = 
	reinterpret_cast<const struct Cache_In_Data *>
	(static_cast<const char*>(casted_input_msg->get_entries()) +
	 n * sizeof(struct Cache_In_Data));
      
      ptr_cache_in->insert(casted_input_msg->get_object_id(), *data);	   
    }
  
  return 0;
}


int local_service_tgt_reg_mig_cnt (Binding_Point * return_point, 
				   Msg_Entry_Header * input_msg)
{
  MESSAGE("target register migrating container");
  return 0;
}

int local_service_src_unreg_mig_cnt (Binding_Point * return_point, 
				     Msg_Entry_Header * input_msg)
{
  MESSAGE("source unregister migratting container");
  return 0;
}

