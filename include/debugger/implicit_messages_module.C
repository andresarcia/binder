# include <implicit_messages_module.H>
# include <locator_boot.H>
# include "remote_message_header.H"

Implicit_Msg_Bucket * same_age_link_to_msg_bucket(Dlink * age_dlink)
{
  Implicit_Msg_Bucket * zero_pointer = 0;

  ASSERT(age_dlink != NULL);
  
  int offset = reinterpret_cast<int>(&zero_pointer->get_same_age_link());

  return reinterpret_cast<Implicit_Msg_Bucket *>
    (reinterpret_cast<char*>(age_dlink) - offset);
}


void Implicit_Msg_Container::remove_last_msg()
{
  AvlTreeTh<unsigned>::Node * last_node;
  
  AvlTreeTh<unsigned>::Iterator itor(implicit_msg_tree);

  itor.resetLast();
 
  last_node = itor.getCurr();

# define LAST_IMP_NODE static_cast<Implicit_Node *>(last_node)

  ASSERT(!LAST_IMP_NODE->get_same_age_msg_list().isEmpty());

  Implicit_Msg_Bucket * msg_bucket = 
    same_age_link_to_msg_bucket(LAST_IMP_NODE->
				get_same_age_msg_list().removeNext());
  
  ASSERT(msg_bucket);

  messages_table->remove(msg_bucket);

  AllocDelete(*objectAlloc, msg_bucket);
  
  // if there are no more messages in list.
  if (LAST_IMP_NODE->get_same_age_msg_list().isEmpty())
    {
      last_node = implicit_msg_tree.remove(LAST_IMP_NODE->getKey());
      
      ASSERT(last_node);

      AllocDelete(*objectAlloc, last_node);
    }

# undef LAST_IMP_NODE

  num_of_msgs--;
}


void Implicit_Msg_Container::
add_implicit_msg_bucket(Implicit_Msg_Bucket * message_bucket)
{
  if (num_of_msgs == max_nodes)
    remove_last_msg();

  AvlTreeTh<unsigned>::Node * searched_node;
  
  searched_node = implicit_msg_tree.
    search(message_bucket->get_implicit_message()->get_message_age());
  
  if (searched_node == NULL)
    {
      AvlTreeTh<unsigned>::Node * ins_node =
	AllocNew(*objectAlloc, Implicit_Node) (message_bucket);
      
      implicit_msg_tree.insert(ins_node);
    }
  else
    static_cast<Implicit_Node *>(searched_node)->get_same_age_msg_list().
      append(&message_bucket->get_same_age_link());
}


void Implicit_Msg_Container::
add_implicit_msg(const Implicit_Msg_Header & new_implicit_msg)
{
  CRITICAL_SECTION(&mutex);

  if (is_shutdown) 
    return;
 
  // insert the message in message table
  Implicit_Msg_Bucket * searched_bucket = static_cast<Implicit_Msg_Bucket *>
    (messages_table->search(new_implicit_msg.get_object_id()));

    if (searched_bucket == NULL)
    {
      Implicit_Msg_Bucket * new_bucket = 
	AllocNew(*objectAlloc, Implicit_Msg_Bucket) (new_implicit_msg);
      
      messages_table->insert(new_bucket);

      // process it in the tree
      add_implicit_msg_bucket(new_bucket);
      
      num_of_msgs++;
    }
  else
    {
      searched_bucket->unLock();  

# define MSG_IN_TABLE searched_bucket->get_implicit_message()->\
                      get_message_type()
      
      if (searched_bucket->is_updatable(&new_implicit_msg))
	{
	  searched_bucket->empty_known_site_list();

	  switch (new_implicit_msg.get_message_type())
	    {
	    case IMPLICIT_DEATH_ANOUNCE :
	      if (MSG_IN_TABLE != IMPLICIT_DEATH_ANOUNCE)
		searched_bucket->set_implicit_message(new_implicit_msg);
	      break;
	      
	    case IMPLICIT_FIND :
	      if (MSG_IN_TABLE == IMPLICIT_LOCATOR_ANOUNCE)
		searched_bucket->set_implicit_message(new_implicit_msg);
	      else
		if (MSG_IN_TABLE == IMPLICIT_FIND)
		  static_cast<Implicit_Find_Msg *>
		    (searched_bucket->get_implicit_message())->get_binding().
		    update_locator
		    (static_cast<const Implicit_Find_Msg *>(&new_implicit_msg)
		     ->get_binding().get_locator());
	      break;
	      
	    case IMPLICIT_LOCATOR_ANOUNCE :
	      if (MSG_IN_TABLE == IMPLICIT_LOCATOR_ANOUNCE)
		static_cast<Implicit_Locator_Anounce_Msg *>
		  (searched_bucket->get_implicit_message())->get_locator().
		  update_locator
		  (static_cast<const Implicit_Locator_Anounce_Msg *>
		   (&new_implicit_msg)->get_locator());
	      else
		if (MSG_IN_TABLE == IMPLICIT_FIND)
		  static_cast<Implicit_Locator_Anounce_Msg *>
		    (searched_bucket->get_implicit_message())->get_locator().
		    update_locator
		    (static_cast<const Implicit_Find_Msg *>
		     (&new_implicit_msg)->get_binding().get_locator());
	      break;
	      
	    default:
	      ERROR("*** ERROR: Unexpected message type. Check the code.");
	    }
	}

      if (searched_bucket->
	  site_is_not_known(new_implicit_msg.get_source_site_id()))
	searched_bucket->add_known_site(new_implicit_msg.get_source_site_id());
    }
} 
# undef MSG_IN_TABLE


size_t Implicit_Msg_Container::
get_implicit_chunk(const Site_Id & target_site_id,
		   void * out_buffer,
		   size_t out_buffer_size)  
{
  // take lock to protect the tree against insertion of new messages.
  CRITICAL_SECTION(&mutex);
  
  ASSERT(waiting_list.isEmpty());

  if (is_shutdown) 
    return 0;
  
  // do an ordered walk in the tree
  AvlTreeTh<unsigned>::Iterator itor(implicit_msg_tree);
  
  unsigned current_size = 0;
  
# define GET_MSG_FROM_LIST same_age_link_to_msg_bucket\
                           (static_cast<Implicit_Node*>(itor.getCurr())->\
                            get_same_age_msg_list().removeNext())
  
# define SIZE_OF_NEXT same_age_link_to_msg_bucket\
                      (static_cast<Implicit_Node*>(itor.getCurr())->\
                      get_same_age_msg_list().getNext())->\
                      get_implicit_message()->get_message_size()
  
  Implicit_Msg_Bucket * msg_to_process;
  
  itor.resetFirst();
  
  unsigned total_msgs_in_chunk = 0;

# ifdef DEBUG

  if (itor.hasCurr())
    ASSERT(out_buffer_size >= sizeof(unsigned) + SIZE_OF_NEXT);

# endif  

  current_size += sizeof(unsigned); // total_msgs_in_chunk
  
  while (itor.hasCurr() && 
	 current_size + SIZE_OF_NEXT <= out_buffer_size)
    {
      ASSERT(num_of_msgs > 0);

      msg_to_process = GET_MSG_FROM_LIST;
      
      // increase the logical_timestamp of each of the messages  
      msg_to_process->get_implicit_message()->increase_message_age();
      
      // check if the message is already known by target site
      if (msg_to_process->site_is_not_known(target_site_id) &&
	  (msg_to_process->get_implicit_message()->
	   get_message_age() <= dead_age))
	{
	  msg_to_process->add_known_site(target_site_id);
	  
	  // and pack each of the nodes in the "out_buffer" variable
	  memcpy(reinterpret_cast<char*>(out_buffer) + current_size,
		 msg_to_process->get_implicit_message(),
		 msg_to_process->get_implicit_message()->get_message_size());
	  
	  current_size += msg_to_process->get_implicit_message()
	    ->get_message_size();
	  
	  total_msgs_in_chunk++;

	  // Although same_age_link was intended to link messages with
	  // same age, is going to be temporarily used in waiting list.
	  waiting_list.append(&msg_to_process->get_same_age_link());
	}
      else
	if (msg_to_process->get_implicit_message()->
	    get_message_age() > dead_age)
	  {
	    messages_table->remove(msg_to_process);

	    AllocDelete(*objectAlloc, msg_to_process);
	  }
	else // not going in the chunk
	  // Although same_age_link was intended to link messages with
	  // same age, is going to be temporarily used in waiting list.
	  waiting_list.append(&msg_to_process->get_same_age_link());
      
      num_of_msgs--;
      
      if (static_cast<Implicit_Node *>(itor.getCurr())->
	  get_same_age_msg_list().isEmpty())
	{
	  AvlTreeTh<unsigned>::Node * node_to_remove = itor.getCurr();
	  
	  itor.next();
	  
	  node_to_remove = 
	    implicit_msg_tree.remove(node_to_remove->getKey());
	  
	  ASSERT(node_to_remove);
	  
	  AllocDelete(*objectAlloc, node_to_remove);
	}
    }

  while (!waiting_list.isEmpty())
    {
      msg_to_process = same_age_link_to_msg_bucket(waiting_list.removeNext());

      // insert them again in the tree (they already have the
      // apropriate logical timestamp).
      add_implicit_msg_bucket(msg_to_process);
      
      num_of_msgs++;
    }
  
  memcpy(out_buffer, &total_msgs_in_chunk, sizeof(unsigned));
  
  // consider all messages are already known by the site,
  // so the chunk size is sizeof(unsigned) (4). Then, be aware
  // of asking how many messages are in chunk at process time.
  
  return current_size;
}


void Implicit_Msg_Container::
process_one_incomming_message(const Site_Id & src_site_id,
			      const Implicit_Msg_Header * msg_to_process)
{
  // if it is already registered and is updatable or is not registered, 
  // then process the information, update or insert the message and
  // continue, else return.
  ASSERT(msg_to_process != NULL);

  Implicit_Msg_Bucket * searched_bucket = static_cast<Implicit_Msg_Bucket *>
    (messages_table->search(msg_to_process->get_object_id()));
  
  if (searched_bucket != NULL)
    searched_bucket->unLock();

  if (searched_bucket != NULL && 
      !searched_bucket->is_updatable(msg_to_process) &&
      msg_to_process->get_message_type() != IMPLICIT_FIND)
    return;

  switch (msg_to_process->get_message_type())
    {
    case IMPLICIT_LOCATOR_ANOUNCE:
      add_implicit_msg(*msg_to_process);

      process_locator_anounce
	(static_cast<const Implicit_Locator_Anounce_Msg *>
	 (msg_to_process)->get_locator());
      break;

    case IMPLICIT_FIND:
      // if the site sending the invocation (whether request or reply)
      // == site asking for an update and if this loc_daemon is the
      // object's owner then respond with an explicit locator anounce
      // message to the binding-update-request site and include an
      // implicit locanounce message.  It doesn't matter whether the
      // implicit message is included, remember we're dealing with a
      // non-reliable way to find objects.

      if (src_site_id == 
	  static_cast<const Implicit_Find_Msg *>
	  (msg_to_process)->get_binding().get_source_site_id())
	{
	  Registered_Object_Bucket * searched_object;
	  
	  searched_object = static_cast<Registered_Object_Bucket *>
	    (ptr_registered_object_table->
	     search(msg_to_process->get_object_id()));
	  
	  if (searched_object != NULL)
	    {
	      searched_object->unLock();

	      Locator 
		locator(msg_to_process->get_object_id(),
			static_cast<Site_Id>(remote_server_id->get_port()),
			searched_object->get_logical_timestamp());

	      Locator_Anounce explicit_anounce_msg(locator);

	      Implicit_Locator_Anounce_Msg 
		implicit_anounce_msg(locator, 
				     static_cast<Site_Id>
				     (remote_server_id->get_port()));

	      add_implicit_msg(implicit_anounce_msg);

	      remote_server_id->async_send(src_site_id, &explicit_anounce_msg);
	    }
	}

      // if this locator knows anything about the object, including its death
      // it will generate another implicit message telling obout it.
      if (searched_bucket != NULL &&
	  searched_bucket->is_updatable(msg_to_process))
	add_implicit_msg(*msg_to_process);
      else
	if (searched_bucket == NULL)
	  add_implicit_msg(*msg_to_process);
				   
      break;

    case IMPLICIT_DEATH_ANOUNCE:
      {
#ifdef DEBUG
	Registered_Object_Bucket * searched_object;
	
	searched_object = static_cast<Registered_Object_Bucket *>
	  (ptr_registered_object_table->
	   search(msg_to_process->get_object_id())); 
	
	ASSERT(searched_object == NULL);
#endif
	add_implicit_msg(*msg_to_process);
	
	// Locator that works only to pass an object_id.
	Locator 
	  locator(msg_to_process->get_object_id(), INVALID_SITE_ID, 0);
	
	update_caches_with_response(LOCREPLY_DEAD, locator);
      }
		  
      break;

    default:
      ERROR("***ERROR: Unknown implicit message header");
    }
}




void Implicit_Msg_Container::
process_chunk(const Site_Id & src_site_id,
	      const void * in_buffer)
{
  // take a message out the input chunk
  unsigned total_msgs = *reinterpret_cast<const unsigned*>(in_buffer);

  if (total_msgs == 0)
    return;

  MESSAGE("total implicit msgs: %i", total_msgs);

  const char * next_message = reinterpret_cast<const char*>(in_buffer) + 
    sizeof(unsigned);
  
  const Implicit_Msg_Header * implicit_msg;

  for (unsigned i = 0; i < total_msgs; i++)
    {
      implicit_msg = 
	reinterpret_cast<const Implicit_Msg_Header*>(next_message);
      
      process_one_incomming_message(src_site_id, implicit_msg);

      next_message += implicit_msg->get_message_size();
    }
}

# undef SIZE_OF_NEXT

void Implicit_Msg_Container::remove_all_and_delete()
{
  CRITICAL_SECTION(&mutex);
  
  is_shutdown = true;
  
  AvlTreeTh<unsigned>::Iterator itor(implicit_msg_tree);

  itor.resetFirst();

  Implicit_Msg_Bucket * msg_to_delete;

  while (itor.hasCurr())
    {
      msg_to_delete = GET_MSG_FROM_LIST;

      messages_table->remove(msg_to_delete);

      AllocDelete(*objectAlloc, msg_to_delete);
      
      if (static_cast<Implicit_Node *>(itor.getCurr())->
	  get_same_age_msg_list().isEmpty())
	{
	  AvlTreeTh<unsigned>::Node * node_to_remove = itor.getCurr();
	  
	  itor.next();
	  
	  node_to_remove = implicit_msg_tree.remove(node_to_remove->getKey());

	  AllocDelete(*objectAlloc, node_to_remove);  
	}
    }

  AllocDelete(*objectAlloc, messages_table);
}

# undef GET_MSG_FROM_LIST
    
/*
  void add_node_to_tree(AvlTreeTh<Implict_Node>::Node * node)
  {
  AvlTreeTh<Implict_Node>::Node * searched_node;
  searched_node = implicit_msg_tree.
  search(static_cast<Implict_Node>(node->getData()));
  if (searched_node == NULL)
  implicit_msg_tree.insert(node);
  else
  while (node->get_same_age_list().getNext() != &node->get_same_age_list())
  searched_node->get_same_age_list().append
  (node->get_same_age_list().removeNext());
  }
*/
