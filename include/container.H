# ifndef CONTAINER_H
# define CONTAINER_H

# include <stdlib.h>
# include "locator_calls.H"
# include <pthread.h>
# include <fstream>
# include <base_message_header.H>
# include <remote_multiserver_point.H>
# include <useMutex.H>
 
# define PRINT_PORT(the_port, type) {\
                     FILE * port_log = fopen("port_log","a");\
                     char port_str[Port::stringSize];\
                     the_port.getStringPort(port_str, Port::stringSize);\
                     fprintf(port_log, "%s:line %i: file %s:type %s\n",\
		     port_str, __LINE__, __FILE__, type);\
                     fclose(port_log);\
                     }

// usage: container <number of iterations> <number of objects> <Site_Id_1>
//                  <Object_Id_1> <number of iter>

Site_Id   this_site(INVALID_SITE_ID);

Container_Id this_container;

Dlink objs_list;

Dlink cnt_list;

Locator * array_of_refs;

int n_objs, n_refs, n_cnts = 0;

FILE * objs_file, * cnt_file;

class Migration_Service;

Remote_Multiserver_Point<Migration_Service> * migration_thread;

pthread_mutex_t mutex_for_migration = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t wait_for_unregistration = PTHREAD_COND_INITIALIZER;

bool object_migrating = false;

int reinvocations = 0;
int invocations = 0;

template<class Node_Type>
Node_Type * get_ith_elem(Dlink & centinel_node, unsigned i)
{
  ASSERT(i > 0);
  
  Dlink * cursor = centinel_node.getNext();
  
  for (unsigned pos = 1; (pos < i) && (cursor != &centinel_node); pos ++)
    cursor = cursor->getNext();

  if (cursor == &centinel_node)
    return NULL;

  return static_cast<Node_Type *>(cursor);
}

template<class Node_Type, class Key_Type>
Node_Type * search_elem(Dlink & centinel_node,
			const Key_Type & key)
{
  Dlink * cursor = & centinel_node;
  
  for (cursor = cursor->getNext(); 
       cursor != &centinel_node; 
       cursor = cursor->getNext())
    {
      char * key_inside_node = 
	reinterpret_cast<char *>(cursor) + sizeof(Dlink); 

      if (key == *reinterpret_cast<Key_Type*>(key_inside_node))
	return static_cast<Node_Type*>(cursor);
    }

  return NULL;
}


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


class Locator_Node : public Dlink
{
  Locator locator;

public:
  Locator_Node(const Locator & _locator) :
    locator(_locator)  
  {
    // empty
  }

  const Locator & get_locator() const
  {
    return locator;
  }
};

class Container_Node : public Dlink
{
  Container_Id container_id;
  Port container_port;

public:

  Container_Node(const Container_Id & _container_id,
		 const Port & _container_port) :
    container_id(_container_id),
    container_port(_container_port)
  {
    // empty
  }  

  const Container_Id & get_container_id() const 
  {
    return container_id;
  }
  
  const Port & get_container_port() const
  {
    return container_port;
  }
};

class Object_Node : public Dlink
{
  Object_Id object_id;
  Logical_Timestamp logical_timestamp;
  bool allowed_to_migrate;

public:
  
  Object_Node(const Object_Id & _obj_id,
	      Logical_Timestamp _timestamp = 0,
	      const bool _allowed = true) :
    object_id(_obj_id),
    logical_timestamp(_timestamp),
    allowed_to_migrate(_allowed)
  {
    // empty
  }

  const Object_Id & get_object_id() const
  {
    return object_id;
  }

  const bool get_allowed_to_migrate() const
  {
    return allowed_to_migrate;
  }

  const Logical_Timestamp get_logical_timestamp() const
  {
    return logical_timestamp;
  }

  void set_allowed_to_migrate(bool _allowed)
  {
    allowed_to_migrate = _allowed;
  }
};


# endif
