# ifndef GROUP_CLIENT_H
# define GROUP_CLIENT_H


# include "protected_lhash.H"
# include "group_message_header.H"
# include "remote_multiserver_point.H"
# include "local_binding.H"
# include "basic_defs.H"


# define DEFAULT_TABLE_SIZE 101

class Group_Client 
{
  Remote_Multiserver_Point * client_port;

  Port group_daemon_port;

  // This class is used to respond to containers waiting for an object
  // look up. So, the call to the group daemon is blocked till the response
  // arrives.
  class Return_Point : public ProtectedLhashTable<Message_Id>::Bucket
  {
    Binding_Point * return_point;
    
  public:
    Return_Point(Binding_Point * _return_point) :
      return_point(_return_point)
    {
      // empty
    }
  };
  
  ProtectedLhashTable<Message_Id> waiting_for_response_table;

  static unsigned long group_hash_fct(const Message_Id & key)
  {
    return static_cast<unsigned long>(key.get_random_number());
  }

public:
  
  Group_Client(Remote_Multiserver_Point * _client_port,
	       const Port & _group_daemon_port) :
    client_port(_client_port),
    group_daemon_port(_group_daemon_port),
    waiting_for_response_table(group_hash_fct,
			       DEFAULT_TABLE_SIZE)
  {
    // empty
  }
  
  // TODO:
  void create_group(Uid & group_uid);

  void join_group(const Port & /*listening_port*/) 
    throw (std::exception, Duplicated);

  void strong_send_to_group(const long /*return_service_code*/,
			    void * /*message*/,
			    const size_t /*message_size*/);
  
  void weak_send_to_group(const long /*return_service_code*/,
			  const long /*timeout*/,
			  const void * /*message*/,
			  const size_t /*message_size*/); 

  void strong_send_to_some(const long /*return_service_code*/,
			   const void * /*message*/,
			   const size_t /*message_size*/);
  
  void weak_send_to_some(const long /*return_service_code*/,
			 const long /*timeout*/,
			 const void * /*message*/,
			 const size_t /*message_size*/); 

  
  void leave_group(const Port & /*listening_port*/) 
    throw (std::exception, NotFound);

  // TODO:
  void delete_group(const Uid & group_uid) 
    throw (std::exception, NotFound);

};

# undef DEFAULT_TABLE_SIZE

# endif //GROUP_CLIENT_H

