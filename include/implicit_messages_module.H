# ifndef IMPLICIT_DATA_STRUCTURE
# define IMPLICIT_DATA_STRUCTURE

# include <aleph.H>
# include <tpl_avlTreeTh.H>
# include <protected_lhash.H>
# include <implicit_message_header.H>

using namespace std;

class Implicit_Msg_Bucket : 
  public ProtectedLhashTable<Object_Id>::Bucket
{
  Implicit_Msg_Header * implicit_message;

  Dlink same_age_link;
  
  Dlink known_site_list;

  class Known_Site_Node : public Dlink
  {
    Site_Id known_site;
  
  public:
    Known_Site_Node(const Site_Id & _site_id) :
      known_site(_site_id)
    {
      // empty
    }

    const Site_Id & get_known_site() const
    {
      return known_site;
    }
  };

#ifdef DEBUG
  unsigned n_sites;
#endif

  void alloc_implicit_message(const Implicit_Msg_Header & msg)
  {
    switch (msg.get_message_type())
      {
      case IMPLICIT_DEATH_ANOUNCE :
	implicit_message = new (Implicit_Death_Anounce_Msg)
	  (*static_cast<const Implicit_Death_Anounce_Msg *>(&msg));
	break;
      case IMPLICIT_FIND :
	implicit_message = new (Implicit_Find_Msg)
	  (*static_cast<const Implicit_Find_Msg *>(&msg));
	break;
      case IMPLICIT_LOCATOR_ANOUNCE :
	implicit_message = 
	  new (Implicit_Locator_Anounce_Msg)
	  (*static_cast<const Implicit_Locator_Anounce_Msg *>(&msg));
	break;
      default:
	ERROR("***ERROR: Unknown implicit message");
      }
  }

public:
  
  Implicit_Msg_Bucket(const Implicit_Msg_Header & _implicit_msg) :
    ProtectedLhashTable<Object_Id>::Bucket(_implicit_msg.get_object_id())
  {
#ifdef DEBUG
    n_sites = 1; 
#endif
    
    Known_Site_Node * src_site = new (Known_Site_Node)
      (_implicit_msg.get_source_site_id());
    
    known_site_list.append(src_site);
    
    alloc_implicit_message(_implicit_msg);
  }
  
  const Implicit_Msg_Header * get_implicit_message() const
  {
    return implicit_message;
  }

  void set_implicit_message(const Implicit_Msg_Header & new_message)
  {
    delete (implicit_message);

    alloc_implicit_message(new_message);
  }

  Implicit_Msg_Header * get_implicit_message() 
  {
    return implicit_message;
  }

  const Implicit_Msg_Type get_implicit_msg_type() const
  {
    return implicit_message->get_message_type();
  }

  const Dlink & get_known_site_list() const
  {
    return known_site_list;
  }

  Dlink & get_same_age_link()
  {
    return same_age_link;
  }

  bool site_is_not_known(const Site_Id & site_id)
  {
    if (known_site_list.isEmpty())
      return true;
    
    Dlink * current = known_site_list.getNext();

    while (current != &known_site_list &&
	   !(static_cast<Known_Site_Node *>(current)->
	     get_known_site() == site_id))
      current = current->getNext();

    if (current == &known_site_list)
      return true;  // current at list's end, then site is not known (true)
    else
      return false;
  }

  void add_known_site(const Site_Id & new_site)
  {
    Known_Site_Node * node = new (Known_Site_Node) (new_site);
    
    ASSERT(node);

    known_site_list.append(node);

#ifdef DEBUG 
    n_sites ++;
#endif
  }

  void empty_known_site_list() 
  {
#ifdef DEBUG
    unsigned node_counter = 0;
#endif

    while (!known_site_list.isEmpty())
      {
#ifdef DEBUG
	node_counter++;
#endif
	delete (static_cast<Known_Site_Node*> (known_site_list.removeNext()));
      }

#ifdef DEBUG
    ASSERT(node_counter == n_sites);
    n_sites = 0;
#endif

  }
  
  bool is_updatable(const Implicit_Msg_Header * new_implicit_msg) const 
  {

# define CASTED_DEATH_MSG(msg)\
  static_cast<const Implicit_Death_Anounce_Msg *>(msg)

# define CASTED_LOCATOR_MSG(msg)\
  static_cast<const Implicit_Locator_Anounce_Msg *>(msg)

# define CASTED_FIND_MSG(msg)\
  static_cast<const Implicit_Find_Msg *>(msg)
    
    
    ASSERT(new_implicit_msg->get_object_id() == 
	   implicit_message->get_object_id());
    
    switch (new_implicit_msg->get_message_type())
      {
      case IMPLICIT_DEATH_ANOUNCE :
	if (implicit_message->get_message_type() == IMPLICIT_DEATH_ANOUNCE)
	  return false;
	else
	  return true;
	break;

      case IMPLICIT_FIND :
	if (implicit_message->get_message_type() == IMPLICIT_LOCATOR_ANOUNCE)
	  {
	    if (CASTED_FIND_MSG(new_implicit_msg)->
		get_binding().get_locator() >
		CASTED_LOCATOR_MSG(implicit_message)->get_locator())
	      return true;
	    else
	      return false;
	  }
	else
	  if (implicit_message->get_message_type() == IMPLICIT_FIND)
	    {
	      if (CASTED_FIND_MSG(new_implicit_msg)->
		  get_binding().get_locator() >
		  CASTED_FIND_MSG(implicit_message)->
		  get_binding().get_locator())
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
	    if (CASTED_LOCATOR_MSG(new_implicit_msg)->get_locator() >
		CASTED_LOCATOR_MSG(implicit_message)->get_locator())
	      return true;
	    else
	      return false;
	  }
	else
	  if (implicit_message->get_message_type() == IMPLICIT_FIND)
	    {
	      if (CASTED_LOCATOR_MSG(new_implicit_msg)->
		  get_locator() >
		  CASTED_FIND_MSG(implicit_message)->
		  get_binding().get_locator())
		return true;
	      else
		return false;
	    }
	  else
	    return false;
	break;

      default:
	ERROR("*** ERROR: Unexpected message type. Check the code.");
      }
    return false;
  }

  ~Implicit_Msg_Bucket()
  {
    empty_known_site_list();

    switch (implicit_message->get_message_type())
      {
      case IMPLICIT_DEATH_ANOUNCE :
	delete (static_cast<Implicit_Death_Anounce_Msg *> (implicit_message));
	break;
      case IMPLICIT_FIND :
	delete (static_cast<Implicit_Find_Msg *> (implicit_message));
	break;
      case IMPLICIT_LOCATOR_ANOUNCE :
	delete (static_cast<Implicit_Locator_Anounce_Msg *> (implicit_message));
	break;
      default:
	ERROR("***ERROR: Unknown implicit message");
      }
  }
}; 


extern 
Implicit_Msg_Bucket * same_age_link_to_msg_bucket(const Dlink * age_dlink);


# define MESSAGES_AGE unsigned

class Implicit_Node : public AvlTreeTh<MESSAGES_AGE>::Node
{
  Dlink same_age_msg_list;
  
public:
  Implicit_Node(Implicit_Msg_Bucket * message_bucket) :
    AvlTreeTh<MESSAGES_AGE>::Node 
  (message_bucket->get_implicit_message()->get_message_age())
  {
    ASSERT(message_bucket != NULL);
    
    same_age_msg_list.append(&message_bucket->get_same_age_link());
  }
  
  Dlink & get_same_age_msg_list() 
  {
    return same_age_msg_list;
  } 
  
  const Dlink & get_same_age_msg_list() const
  {
    return same_age_msg_list;
  } 
};

# undef MESSAGES_AGE


class Implicit_Msg_Container
{
  AvlTreeTh<unsigned> implicit_msg_tree;

  static unsigned long hash_fct(const Uid & key)
  {
    return static_cast<unsigned long>(key.get_random_number());
  }

  ProtectedLhashTable<Object_Id> * messages_table;

  pthread_mutex_t mutex;

  unsigned max_nodes;

  unsigned num_of_msgs;

  unsigned dead_age;

  bool is_shutdown;

  // waiting list keeps messages while preparing the outgoing chunk and
  // once the chunk is finished, messages are put back from this list
  // to container.
  Dlink waiting_list;

  void remove_last_msg();

  void add_implicit_msg_bucket(Implicit_Msg_Bucket *);
  
  void process_one_incomming_message(const Site_Id &, 
				     const Implicit_Msg_Header *);

public:
  
  Implicit_Msg_Container(unsigned _max_nodes, unsigned _dead_age) :
    max_nodes(_max_nodes),
    num_of_msgs(0),
    dead_age(_dead_age),
    is_shutdown(false)
  {
    ASSERT(max_nodes > 0);    
    
    ASSERT(dead_age > 0);

    messages_table = new (ProtectedLhashTable<Object_Id>) (hash_fct, max_nodes);

    ASSERT(messages_table);
  }

  void add_implicit_msg(const Implicit_Msg_Header &);

  // Returns the buffer size that was actually written in "buffer".
  // It means that not all the buffer_size is usable. There will eventually
  // be a gap, which is buffer_size - get_implicit_chunk(...).
  size_t get_implicit_chunk(const Site_Id & target_site_id,
			    void * out_buffer,
			    size_t out_buffer_size);
  

  void process_chunk(const Site_Id & src_site_id,
		     const void * in_buffer);
  
  void remove_all_and_delete();

  ~Implicit_Msg_Container()
  {
    remove_all_and_delete();
  }
};

# undef CASTED_DEATH_MSG

# undef CASTED_LOCATOR_MSG

# undef CASTED_FIND_MSG

# endif // IMPLICIT_DATA_STRUCTURE

/*
	    Locator tmp_loc(CASTED_FIND_MSG(new_implicit_msg)->get_binding().get_locator());
	    Locator tmp_loc1(CASTED_FIND_MSG(implicit_message)->get_binding().get_locator());	    
*/
