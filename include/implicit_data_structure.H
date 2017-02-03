# ifndef IMPLICIT_DATA_STRUCTURE
# define IMPLICIT_DATA_STRUCTURE

# include <tpl_avlTreeTh.H>

class Implicit_Msg_Bucket : public ProtectedLhashTable<Object_Id>::Bucket
{
  Implicit_Msg_Header * implicit_message;

  Dlink same_age_link;
  
  Dlink known_site_list;

public:
  
  Implicit_Msg_Bucket(const Implicit_Msg_Header * _implicit_msg) :
    ProtectedLhashTable<Object_Id>::Bucket(_implicit_msg->get_object_id()),
				    implicit_message(_implicit_msg)
  {
    // empty
  }
  
  const Implicit_Msg_Header * get_implicit_message() const
  {
    return implicit_message;
  }

  const Implicit_Msg_Type get_implicit_msg_type() const
  {
    return implicit_message->message_type;
  }

  const Dlink & get_known_site_list() const
  {
    return known_site_list;
  }

  Dlink & get_same_age_link()
  {
    return same_age_link;
  }

  bool is_updatable(const Implicit_Msg_Header & new_implicit_msg) const
  {
    ASSERT(new_implicit_msg.get_object_id() == 
	   implicit_message->get_object_id());

    switch (new_implicit_msg.get_message_type())
      {
      case IMPLICIT_DEATH :
	if (implicit_message->get_message_type() == IMPLICIT_DEATH)
	  return false;
	else
	  return true;
	break;
      case IMPLICIT_FIND :
	if (implicit_message->get_message_type() == IMPLICIT_LOCATOR_ANOUNCE)
	  return true;
	else
	  if (implicit_message->get_message_type() == IMPLICIT_FIND)
	    {
	      if (new_implicit_msg.get_binding().get_locator() >
		  implicit_message->get_binding.get_locator())
		return true;
	      else
		return false;
	    }
	  else
	    return false;
	break;
      case IMPLICIT_LOCATOR_ANOUNCE :
	if (implicit_message->get_message_type() == IMPLICIT_LOCATOR_ANOUNCE)
	  {
	    if (new_implicit_msg.get_locator() >
		implicit_message->get_locator())
	      return true;
	    else 
	      return false;
	  }
	else
	  if (implicit_message->get_message_type() == IMPLICIT_FIND)
	    return true;
	  else
	    return false;
	break;
      default:
	ERROR("*** ERROR: Unexpected message type. Check the code.");
      }
  }

}; 

Implicit_Msg_Bucket * same_age_link_to_msg_bucket(Dlink * age_dlink)
{
  Implicit_Msg_Bucket * zero_pointer = 0;
  
  int offset = reinterpret_cast<char*>(&zero_pointer->get_same_age_link());
  
  ASSERT(same_age_msg_list->getNext() - offset > 0);
  
  return reinterpret_cast<Implicit_Msg_Bucket *>
    (reinterpret_cast<char*>(age_dlink) - offset);
}

class Implicit_Node 
{
  Dlink same_age_msg_list;
  
public:
  Implicit_Node(Implicit_Msg_Bucket * node_data_ptr) :
    message_age(_age)
  {
    same_age_msg_list.append(node_data_ptr->get_same_age_link());
  }

  Implicit_Node(const Implicit_Node & src_node)
  {
    ASSERT(same_age_msg_list->getNext()->getNext() == &same_age_msg_list);

    same_age_msg_list.append(src_node.get_same_age_msg_list()->getNext());
  }

  Dlink & get_same_age_msg_list() const 
  {
    return same_age_msg_list;
  }  

  // the age of the first message is same for all the message in list
  // "same_age_msg_list".
  const Logical_Timestamp get_first_msg_age() 
  {
    Logical_Timestamp age = 
      same_age_link_to_msg_bucket(same_age_msg_list->getNext())->
      get_implicit_message()->get_message_age();
    
    ASSERT(age >= 0);

    return age;
  }

  const bool operator == (const Implicit_Node & other_node) const 
  {
    return (other_node.get_first_message_age() == get_first_msg_age());
  } 
};



class Implicit_Msg_Tree 
{
  AvlTreeTh<Implicit_Node> implicit_msg_tree;

  pthread_mutex_t mutex;

  unsigned max_nodes;

  unsigned num_of_nodes;

  void remove_last_msg()
  {
    AvlTreeTh<Implict_Node>::Node * searched_node;
    
    searched_node = get_last_node();
    
    Implicit_Msg_Bucket * msg_bucket = 
      same_age_link_to_msg_bucket(searched_node->
				  get_same_age_list().removeNext());
    
    AllocDelete(msg_bucket);
    
    // if there is just one message in queue
    if (searched_node->get_same_age_list().getNext() == 
	&searched_node->get_same_age_list())
      implicit_msg_tree.remove(searched_node);

    num_of_nodes--;
  }

public:
  
  Implicit_Msg_Tree(unsigned _max_nodes) :
    max_nodes(_max_nodes),
    num_of_nodes(0)
  {
    ASSERT(max_nodes > 0);
  }

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

  void add_implicit_msg(const Implicit_Msg_Bucket * new_message)
  {
    UseMutex CRITICAL_SECTION(&mutex);

    AvlTreeTh<Implict_Node>::Node * searched_node;
    
    Implicit_Node comparison_node(new_message);

    searched_node = implicit_msg_tree.search(comparison_node);

    if (num_of_nodes == max_nodes)
      remove_last_msg();
  
    if (searched_node == NULL)
      {
	AvlTreeTh<Implict_Node>::Node * ins_node =
	  AllocNew(*objectAlloc, AvlTreeTh<Implict_Node>::Node) 
	  (comparison_node);

	implicit_msg_tree.insert(ins_node);
      }
    else
      {
	searched_node->get_same_age_list().
	  append(new_message->get_same_age_link());
      }

    num_of_nodes++;
  } 
  
  // Returns the buffer size that was actually written in "buffer".
  // It means that not all the buffer_size is usable. There will eventually
  // be a gap, which is buffer_size - get_implicit_chunk(...).
  size_t get_implicit_chunk(const Site_Id & target_site_id,
			    void * out_buffer,
			    size_t out_buffer_size)
  {
    // take lock to protect the tree against insertion of new messages.
    UseMutex CRITICAL_SECTION(&mutex);

    // do an ordered walk in the tree
    AvlTreeTh<Implicit_Node>::Iterator itor(implicit_msg_tree);

    unsigned current_size = 0;

    while (itor.getCurr() != NULL && current_size <= out_buffer_size)
      {
	// increase the logical_timestamp of each of the messages  

	// and pack each of the nodes in the "out_buffer" variable
	memcpy(out_buffer + current_size,
	       itor.getCurr(),
	       sizeof(/* calculated size */));

	current_size += /* calculated size */;

	// then insert them again in the tree (they already have the apropriate 
	// logical timestamp).
	
	itor.getNext();
      }

  }

  void process_chunk(void * in_buffer, size_t in_buffer_size);
  
  void remove_all_and_delete();

  ~Implicit_Msg_Tree()
  {
    remove_all_and_delete();
  }
};

# endif // IMPLICIT_DATA_STRUCTURE

