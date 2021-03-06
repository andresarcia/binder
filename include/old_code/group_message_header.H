# ifndef GROUP_MESSAGE_HEADER
# define GROUP_MESSAGE_HEADER

# include "base_message_header.H"
# include "port.H"
# include "basic_defs.H"

enum Group_Daemon_Codes
{
  GRP_CREATE_GROUP,
  GRP_JOIN_GROUP,
  GRP_LEAVE_GROUP,
  GRP_REQUIERES_ALL_GROUP_RESPONSES,
  GRP_REQUIERES_COUNTED_RESPONSES,
  GRP_RECEIVE_RESPONSE,
  GRP_DELETE_GROUP,

  GRP_SERV_LAST  
};

enum Group_Daemon_Responses
{
  GRP_RESPONSE_TO_CREATE,
  GRP_RESPONSE_TO_JOIN,
  GRP_RESPONSE_TO_LEAVE,
  GRP_RESPONSE_TO_GROUP,
  GRP_RESPONSE_TO_DELETE,

  GRP_RESPONSE_LAST  
};

enum Group_Daemon_Error_Codes
{
  GRP_OK,
  GRP_INTENDED_DOUBLE_SUSCRIPTION,
  GRP_MEMBER_NOT_SUSCRIBED,
  GRP_INCOMPLETE_REPLYS,
  
  GRP_RESP_LAST
};

enum Sending_Reliability
{
  GRP_NON_RELIABLE_SEND,
  GRP_RELIABLE_SEND,
  
  GRP_REL_LAST
};


class Group_Return_Msg_Header : public Msg_Entry_Header
{
  Group_Daemon_Error_Codes error_code;
  
  Group_Daemon_Responses response_code;
  
protected:
  Group_Return_Msg_Header(const long _client_return_service_code,
			  const Group_Daemon_Responses _response_code,
			  const Group_Daemon_Error_Codes _error_code,
			  const size_t _message_size) :
    // The client has to tell the group daemon which code (long) he/she
    // wants to be returned when the group daemon finishes processing 
    // a request. "_client_return_service_code" activates a service at
    // client's side, soo be careful which code it is passed.
    Msg_Entry_Header(_client_return_service_code, _message_size),
    error_code(_error_code),
    response_code(_response_code)
  {
    ASSERT(_message_size >= sizeof(*this));
  }

public:
  const Group_Daemon_Error_Codes get_error_code() const
  {
    return error_code;
  }

  const Group_Daemon_Responses get_response_code() const
  {
    return response_code;
  }
};


class Group_Entry_Msg_Header : public Msg_Entry_Header
{
  long client_return_service_code;

protected:

  Group_Entry_Msg_Header(const long _client_return_service_code,
			 const long _daemon_group_service,
			 const size_t _message_size) :
    Msg_Entry_Header(_daemon_group_service, _message_size),
    client_return_service_code(_client_return_service_code)
  {
    // empty
  }

public:

  const long get_client_return_service_code() const
  {
    return client_return_service_code;
  }
  
};

# define INVALID_CODE -1

class Join_Group_CallMsg : public Group_Entry_Msg_Header
{
  Port listening_port_id;

public:
  Join_Group_CallMsg(const Port & _listening_port) :
    Group_Entry_Msg_Header(INVALID_CODE,
			   GRP_JOIN_GROUP, 
			   sizeof(*this)),
    listening_port_id(_listening_port)
  {
    // empty
  }

  const Port & get_listening_port_id() const
  {
    return listening_port_id;
  }  
};



class Join_Group_RetMsg : public Group_Return_Msg_Header
{
public:

  Join_Group_RetMsg(const Group_Daemon_Error_Codes _error_code) :
    Group_Return_Msg_Header(INVALID_CODE,
			    GRP_RESPONSE_TO_JOIN,
			    _error_code, 
			    sizeof(*this))
  {
    // empty
  }
};


class Leave_Group_CallMsg : public Group_Entry_Msg_Header
{
  Port suscribed_port_id;

public:
  Leave_Group_CallMsg(const Port & _port_id) :
    Group_Entry_Msg_Header(INVALID_CODE,
			   GRP_LEAVE_GROUP, 
			   sizeof(*this)),
    suscribed_port_id(_port_id)
  {
    // empty
  }

  const Port & get_suscribed_port_id() const
  {
    return suscribed_port_id;
  }  
};

class Leave_Group_RetMsg : public Group_Return_Msg_Header
{
public:

  Leave_Group_RetMsg(const Group_Daemon_Error_Codes _error_code) :
    Group_Return_Msg_Header(INVALID_CODE,
			    GRP_RESPONSE_TO_LEAVE, 
			    _error_code, 
			    sizeof(*this))
  {
    // empty
  }
};

# undef INVALID_CODE 

class Send_And_Receive_From_All_CallMsg : public Group_Entry_Msg_Header
{
  Port source_port;
  
  Sending_Reliability reliability;

  long timeout_to_give_up;
  
  size_t message_to_send_size;

  char message_to_send[0];

public:
  
  Send_And_Receive_From_All_CallMsg(const Port & _source_port,
				    const long _client_return_service_code,
				    const Sending_Reliability _reliability,
				    const long _timeout, 
				    const size_t _message_size) :
    Group_Entry_Msg_Header(_client_return_service_code,
			   GRP_REQUIERES_ALL_GROUP_RESPONSES, 
			   sizeof(*this) + _message_size),
    source_port(_source_port),
    reliability(_reliability),
    timeout_to_give_up(_timeout),
    message_to_send_size(_message_size)
  {
    // empty
  }

  const Port & get_source_port() const
  {
    return source_port;
  }

  const Sending_Reliability get_reliability() const
  {
    return reliability;
  }

  const long get_timeout_to_give_up() const
  {
    return timeout_to_give_up;
  }

  const size_t get_message_to_send_size() const
  {
    return message_to_send_size;
  }

  char * get_message_to_send() 
  {
    if (message_to_send_size > 0)
      return message_to_send;
    else
      return NULL;
  }
};

// from group daemon to container asking for a multicast 
class Responses_RetMsg : public Group_Return_Msg_Header
{
  long total_members_in_group;
  
  long expected_responses;

  long current_number_of_responses;

  size_t responses_size;

  char responses[0];

public:
  Responses_RetMsg (const long _client_return_service_code,
		    const Group_Daemon_Error_Codes _error_code,
		    const long _total_members,
		    const long _expected_resp,
		    const long _current_no_resp,
		    const size_t _resp_size) :
    Group_Return_Msg_Header(_client_return_service_code,
			    GRP_RESPONSE_TO_GROUP,
			    _error_code, 
			    sizeof(*this) + _resp_size),
    total_members_in_group(_total_members),
    expected_responses(_expected_resp),
    current_number_of_responses(_current_no_resp),
    responses_size(_resp_size)
  {
    // empty
  }
  
  const long get_total_members_in_group() const
  {
    return total_members_in_group;
  } 
  
  const long get_current_number_of_responses() const
  {
    return current_number_of_responses;
  }

  const long get_expected_responses() const
  {
    return expected_responses;
  }
  
  const size_t get_responses_size() const
  {
    return responses_size;
  }
  
  const char * get_responses() const
  {
    if (responses_size > 0)
      return responses;
    else
      return NULL;
  }
};


// from containers to group daemon.
class Single_Response_RetMsg : public Msg_Entry_Header
{
  size_t response_size;
  
  char response[0];
  
public:
  
  Single_Response_RetMsg(const size_t _response_size) :
    Msg_Entry_Header(GRP_RECEIVE_RESPONSE, sizeof(*this) + _response_size),
    response_size(_response_size)
  {
    ASSERT(response_size >= sizeof(Msg_Entry_Header));
  }

  const size_t get_response_size() const
  {
    return response_size;
  }
  
  const char * get_response() const
  {
    if (response_size > 0)
      return response;
    else
      return NULL;
  }
};

class Send_And_Receive_From_Some_CallMsg : public Group_Entry_Msg_Header
{
  Port source_port;

  Sending_Reliability reliability;
  
  long number_of_expected_responses;
  
  long timeout_to_give_up;
  
  size_t message_to_send_size;

  char message_to_send[0];

public:
  
  Send_And_Receive_From_Some_CallMsg(const Port & _source_port,
				     const long _client_return_service_code,
				     const Sending_Reliability _reliability, 
				     const long _expected_resp,
				     const long _timeout, 
				     const size_t _message_size) :
    Group_Entry_Msg_Header(_client_return_service_code,
			   GRP_REQUIERES_COUNTED_RESPONSES,
			   sizeof(*this) + _message_size),
    reliability(_reliability),
    number_of_expected_responses(_expected_resp),
    timeout_to_give_up(_timeout),
    message_to_send_size(_message_size)
  {
    // empty
  }
  
  const Port & get_source_port() const
  {
    return source_port;
  }
 
  const Sending_Reliability get_reliability() const
  {
    return reliability;
  }

  const long get_number_of_expected_responses() const
  {
    return number_of_expected_responses;
  }

  const long get_timeout_to_give_up() const
  {
    return timeout_to_give_up;
  }

  const size_t get_message_to_send_size() const
  {
    return message_to_send_size;
  }

  char * get_message_to_send() 
  {
    if (message_to_send_size > 0)
      return message_to_send;
    else
      return NULL;
  }
};
 

# endif  // GROUP_MESSAGE_HEADER




