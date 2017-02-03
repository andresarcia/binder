# include "group_client.H"
# include "remote_multiserver_point.H"

# define NUMBER_OF_SRVCS 2

Remote_Multiserver_Point services_thread(NUMBER_OF_SRVCS);

enum Test_Services_Codes
{
  RECEIVE_FROM_GROUP_DAEMON,
  COOPERATIVE_SERVICE,
  COOPERATIVE_SERVICE_RESPONSE,  
  SERVICE_THREE,
  SERVICE_FOUR,
    
  LAST
};

class Cooperative_Question : public Msg_Entry_Header
{
public:
  Cooperative_Question() :
    Msg_Entry_Header(COOPERATIVE_SERVICE, sizeof(*this))
  {
    // empty
  }
};

class Cooperative_Response : public Msg_Entry_Header
{
public:
  Cooperative_Response() :
    Msg_Entry_Header(COOPERATIVE_SERVICE_RESPONSE, sizeof(*this))
  {
    // empty
  }
};

int receive_from_group_daemon(Msg_Entry_Header * entry_msg)
{
  MESSAGE(">>>> RECEIVING MULTICAST REQUEST <<<<");
  
  Responses_RetMsg * reply_msg = static_cast<Responses_RetMsg *>(entry_msg);
  
  MESSAGE("total members in group %i", 
	  reply_msg->get_total_members_in_group());

  MESSAGE("expected responses %i", 
	  reply_msg->get_expected_responses());

  MESSAGE("current_number_of_responses %i", 
	  reply_msg->get_current_number_of_responses());

  MESSAGE("responses_size %i", reply_msg->get_responses_size());
  
  return 0;
}

int cooperative_service(Msg_Entry_Header * entry_msg,
			Remote_Multiserver_Binding * return_point)
{
  Cooperative_Response response;
  
  Single_Response_RetMsg ret_msg_to_daemon_group(sizeof(Cooperative_Response));
  
  MESSAGE(">>> COOPERATIVE SERVICE <<<");
  
  return_point->rpc_reply(&ret_msg_to_daemon_group, 
			  sizeof(Single_Response_RetMsg),
			  &response,
			  sizeof(Cooperative_Response));
  
  return 0;
}

int main(int argc, char * argv[])
{
  if (argc == 0)
    {
      MESSAGE("usage: test_group_client <GROUP PORT STRING>");
      exit(0);
    }
  
  services_thread.add_service(RECEIVE_FROM_GROUP_DAEMON,
			      "receive_from_group_daemon", 
			      receive_from_group_daemon);
  
  services_thread.add_service(COOPERATIVE_SERVICE,
			      "cooperative_service", 
			      cooperative_service);
  pthread_t * t;
 
  t = services_thread.start_deamon();

  Port group_daemon_port(argv[1]);

  Group_Client group_client(&services_thread, group_daemon_port);

  group_client.join_group(services_thread.get_port());

  pthread_join(*t, NULL);

  return 0;
}

