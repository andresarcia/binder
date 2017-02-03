# include "useMutex.H"
# include "signal.H"
# include "basic_defs.H"
# include "timeoutQueue.H"

# define NUMBER_OF_SRVCS 7

# define RESPONSE_BUFFER_SIZE 4096

# define DEFAULT_TABLE_SIZE 101

# define WAITING_TIME_FOR_RESPONSE_MSEC 5000

template<class Node_Type, class Key_Type>
Node_Type * search_elem(Dlink & centinel_node,
			const Key_Type & key)
{
  Dlink * cursor = &centinel_node;
  
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


class Msg_Id_Sqc_Nbr_Map_Bucket : 
  public ProtectedLhashTable<MsgId>::Bucket
{
  long sequence_number;

  Group_Answer_Time_Expired * ptr_time_expired_event;

public:
  
  Msg_Id_Sqc_Nbr_Map_Bucket(const MsgId & _msg_id,
			    const long _sqc_number,
			    const Group_Answer_Time_Expired * _event) :
    ProtectedLhashTable<MsgId>::Bucket(_msg_id),
				sequence_number(_sqc_number),
				ptr_time_expired_event(_event)
  {
    // empty
  }

  const long get_sequence_number() const
  {
    return sequence_number;
  }

  const Group_Answer_Time_Expired * get_ptr_time_expired_event() const
  {
    return ptr_time_expired_event;
  }

  ~Msg_Id_Sqc_Nbr_Map_Bucket()
  {
    AllocDelete(*objectAlloc, ptr_time_expired_event);
  }
};

class Wait_For_Responses_Bucket : 
  public ProtectedLhashTable<long>::Bucket
{
  long client_return_service_code;

  long total_members_snapshot;

  long number_of_expected_responses;

  long current_number_of_responses;

  long current_number_of_lost_responses;

  char buffer_for_response[RESPONSE_BUFFER_SIZE];

  size_t current_buffer_size;

  Remote_Multiserver_Binding * waiting_client_port;
  
public:
  Wait_For_Responses_Bucket(const long _client_return_service_code,
			    const long _total_members_snapshot,
			    const long _sequence_number,
			    const long _exp_resp,
			    Remote_Multiserver_Binding * _client) :
    ProtectedLhashTable<long>::Bucket(_sequence_number),
		 client_return_service_code(_client_return_service_code),
		 total_members_snapshot(_total_members_snapshot),
		 number_of_expected_responses(_exp_resp),
		 current_number_of_responses(0),
		 current_number_of_lost_responses(0),
		 current_buffer_size(0),
		 waiting_client_port(_client)
  {
    ASSERT(number_of_expected_responses > 0);
    ASSERT(waiting_client_port != NULL);
  }
  
  const long get_total_members_snapshot() const 
  {
    return total_members_snapshot;
  }

  const long get_number_of_expected_responses() const 
  {
    return number_of_expected_responses;
  }

  const long get_current_number_of_responses() const
  {
    return current_number_of_responses;
  }

  const long get_current_number_lost_of_responses() const
  {
    return current_number_of_lost_responses;
  }

  const size_t get_current_buffer_size() const
  {
    return current_buffer_size;
  }
  
  char * get_buffer_for_response() 
  {
    return buffer_for_response;
  }

  const long get_client_return_service_code() const
  {
    return client_return_service_code;
  }

  Remote_Multiserver_Binding * get_waiting_client_port() const
  {
    return waiting_client_port;
  }

  void add_lost_response() 
  {
    current_number_of_los_responses++;
  }

  void add_new_response(const void * response, size_t response_size)
  {
    ASSERT(response != NULL);
    ASSERT(response_size > 0);
    ASSERT(current_buffer_size + response_size <= RESPONSE_BUFFER_SIZE);

    memcpy(buffer_for_response + current_buffer_size,
	   response,
	   response_size);

    current_buffer_size += response_size;

    current_number_of_responses++;
  }

  bool ready_to_respond() const
  {
    ASSERT(current_number_of_responses +
	   current_number_of_lost_responses <= number_of_expected_responses);

    return ((current_number_of_responses + current_number_of_lost_responses) 
	    == number_of_expected_responses);
  }
};


class Group_Daemon 
{
  Remote_Multiserver_Point reception_point;
  
  Dlink clients;
  
  pthread_t * ptr_reception_thread;
  
  pthread_t * ptr_timeout_thread;
  // this table stores all the information related to a multicast query.
  // Once the request is completed, all the collected information will be
  // handled to the correspondant client.
  ProtectedLhashTable<long> client_response_table;
  
  // hash table that maps message ids to sequence numbers. That means, that
  // every message sent to avery group member is associated to a secuence 
  // number, so that multiple resquests to group members can be simultaniously
  // done by many clients.
  ProtectedLhashTable<MsgId> msg_id_sqc_nbr_map_table;
  
  pthread_mutex_t GROUP_MUTEX;
  
  long current_number_of_clients;
  
  long sequence_number;
  
  TimeoutQueue timeout_queue;

  static int daemon_instances = 0;
  
  unsigned long long_hash_fct(const long & key)
  {
    return static_cast<unsigned long>(key);
  }
  
  unsigned long group_hash_fct(const MsgId & key)
  {
    return static_cast<unsigned long>(key.getTimeNsec());
  }

  long get_new_sequence_number()
  {
    return sequence_number++;
  }
  
  class Group_Client : public Dlink
  {
    Port client_port;
    
  public:
    
    Group_Client(const Port & _port_id) :
      client_port(_port_id)
    {
      // empty
    }
    
    const Port & get_client_port() const
    {
      return client_port;
    }
  };


  static int grp_create_group(Msg_Entry_Header * entry_msg,
			    Remote_Multiserver_Binding * return_point);

  static int grp_delete_group(Msg_Entry_Header * entry_msg,
			      Remote_Multiserver_Binding * return_point);
  
  static int grp_join_group(Msg_Entry_Header * entry_msg,
			    Remote_Multiserver_Binding * return_point);
  
  static int grp_leave_group(Msg_Entry_Header * entry_msg,
			   Remote_Multiserver_Binding * return_point);

  static int 
  grp_requieres_all_group_responses(Msg_Entry_Header * entry_msg,
				    Remote_Multiserver_Binding * return_point);
  
  
  static int grp_requieres_counted_responses(Msg_Entry_Header * entry_msg,
					     Remote_Multiserver_Binding *);
  
  static int grp_receive_response(Msg_Entry_Header * entry_msg);
  
  
  
public:
  Group_Daemon() :
    reception_point(NUMBER_OF_SRVCS),
    client_response_table(long_hash_fct, DEFAULT_TABLE_SIZE),
    msg_id_sqc_nbr_map_table(group_hash_fct, DEFAULT_TABLE_SIZE),
    GROUP_MUTEX(PTHREAD_MUTEX_INITIALIZER),
    current_number_of_clients(0),
    sequence_number(0)    
  {
    daemon_instances ++; 

    ASSERT(daemons_instances == 1);

    ptr_timeout_thread = timeout_queue.start_thread();

    ptr_reception_thread = reception_point.start_deamon();

    reception_point.
      add_service(GRP_CREATE_GROUP, "grp create group", grp_create_group);
    
    reception_point.
      add_service(GRP_JOIN_GROUP, "grp join group", grp_join_group);
    
    reception_point.
      add_service(GRP_LEAVE_GROUP, "grp leave group", grp_leave_group);
    
    reception_point.add_service(GRP_REQUIERES_ALL_GROUP_RESPONSES,
				"grp requieres all group responses", 
				grp_requieres_all_group_responses);
    
    reception_point.add_service(GRP_REQUIERES_COUNTED_RESPONSES,
				"grp requieres counted responses", 
				grp_requieres_counted_responses);
    
    reception_point.add_service(GRP_RECEIVE_RESPONSE,
				"grp receive response",
				grp_receive_response);
    
    reception_point.
      add_service(GRP_DELETE_GROUP, "grp delete group", grp_delete_group);
  }

  void join_group_daemon()
  {
    pthread_join(*ptr_timeout_thread, NULL);
    
    pthread_join(*ptr_reception_thread, NULL);    
  }

  void shutdown_group_daemon()
  {
    ptr_timeout_thread->shutdown();

    ptr_reception_thread->shutdown();
  }

  ~Group_Daemon()
  {
    MESSAGE("Group Daemon has been shutdown!");

    // Delete all members from registering list.
    while (!clients.isEmpty())
      AllocDelete(*objectAlloc, 
		  static_cast<Group_Client*>(clients.removeNext()));
    
    pthread_mutex_destroy(&GROUP_MUTEX);
  }
};




