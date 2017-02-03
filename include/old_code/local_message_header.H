# ifndef  LOCAL_MESSAGE_HEADER_H
# define  LOCAL_MESSAGE_HEADER_H

# define SA	struct sockaddr
# define LISTENQ		1024	/* 2nd argument to listen() */

# ifndef BZERO
# define BZERO
# define	bzero(ptr,n)		memset(ptr, 0, n)
# endif

# include <sys/types.h>	        /* basic system data types */
# include <sys/socket.h>	/* basic socket definitions */
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/un.h>		/* for Unix domain sockets */
# include <sys/select.h>	/* for convenience */
# include <ostream.h>
# include <unistd.h>

# ifndef AF_LOCAL
# define AF_LOCAL	AF_UNIX
# endif

/**
   Response codes that goes from the server to the client. 
   Normally, DERESP_RESPONSE_TO_SERVICE is the one used for
   communicate the answer to a service request. 
*/
enum Local_Response_Code
{
  DEMRESP_REGISTRATION_OK,
  DEMRESP_INTENDED_DOUBLE_REGISTRATION,
  DEMRESP_SERVICE_NOT_FOUND,
  DEMRESP_RESPONSE_TO_SERVICE,
  
  DEMRESP_INVALID,
  
  DEMRESP_LAST
};


/// Service codes for the server operation

enum Local_Service_Code
{
  /// Verifies if a proposed service exists at servers side  
  DEMSERV_ADD, 
  /// The message contains a request for a service
  DEMSERV_SEND,

  // The server's shutdown is requiered, only used at servers' side 
  DEMSERV_SHUTDOWN, 
  
  DEMSERV_INVALID, 

  DEMSERV_LAST
};


/**
  Local_Locator defines an especific location of the server at
  client's side.  At construction time, the only parameter is the path
  of the file which serves as access point for the server. Later the
  socket is set at client's construction time through the function
  set_deamon_socket(int).
*/
class Local_Locator 
{
  char deamon_location[255];
  int deamon_socket; 

public:
  Local_Locator(const char * dem_loc)
  {
    strcpy(deamon_location, dem_loc);
  }

  const char * stringficate() const
  {
    return deamon_location;
  }

  void set_deamon_socket(int sock_id) 
  {
    deamon_socket = sock_id;
  }

  int get_deamon_socket() const
  {
    return deamon_socket;
  }
    
};


/**
   Header, which stablishes the difference between system messages and
   client messages (those whose Local_Response_Code is 
   DEMRESP_RESPONSE_TO_SERVICE). It is forbidden to directly use it.
   Client must work with  Local_Msg_Exit_Header.
*/
class Local_Response_Header
{
  Local_Response_Code local_response_code;
  size_t local_response_size;

protected:

  Local_Response_Header(Local_Response_Code response_code) : 
    local_response_code(response_code),
    local_response_size(0)
  {
    // Empty
  }

  Local_Response_Header() : 
    local_response_code(DEMRESP_INVALID),
    local_response_size(0)
  {
    // Empty
  }

public:
  Local_Response_Code get_local_response_code() const
  {
    return local_response_code;
  }

  void set_local_response_size(const size_t size) 
  {
    local_response_size = size;
  }

  size_t get_local_response_size() const
  {
    return local_response_size;
  }

};

/** 
   Header, which stablishes the difference between system messages and
   client messages (those whose Local_Service_Code is 
   DEMSERV_SEND). It is forbidden to directly use it.
   Client must work with  Local_Msg_Entry_Header.
*/
class Local_Service_Header
{
  Local_Service_Code local_service_code;

protected:

  Local_Service_Header(Local_Service_Code service_code) : 
    local_service_code(service_code)
  {
    // Empty
  }

  Local_Service_Header() : 
    local_service_code(DEMSERV_INVALID)
  {
    // Empty
  }

public:
  Local_Service_Code get_local_service_code() const
  {
    return local_service_code;
  }

};

/**
  Message used as identifier of client requests for service.
  It is used in the following way:

  class User_Message : public Local_Msg_Entry_Header
  {
  private:
    // this will be the data to be transmitted to the server.
    type_1 var1, var2 ... var_m
    ...
    type_n var_n_1, var_n_2, ... var_n_m;

  public:
    User_Message(User_Service_Codes u_s_c, others) : 
      Local_Msg_Entry_Header(u_s_c, sizeof(*this)) 
      {
       // whatever it takes to initialize your parameters.
      }

      ... other functions.
  }

  Remember then to have a class User_Service_Codes where you especify which
  services you actually have. This is the only way you have to differenciate
  your services. 

*/
class Local_Msg_Entry_Header : public Local_Service_Header
{
  friend class Register_Message;
  friend class Shutdown_Message;

  long   service_code;
  size_t parameters_size;
  
private:
  
  Local_Msg_Entry_Header() :
    service_code(0),
    parameters_size(0)
  {
    // empty
  }
  
  Local_Msg_Entry_Header(const Local_Service_Code serv_code,
			  const long srvc_code,
			  const size_t param_size = 0) :
    Local_Service_Header(serv_code),
    service_code(srvc_code),
    parameters_size(param_size)
  {
    // empty
  }
  
protected:
  
  Local_Msg_Entry_Header(const long srvc_code,
			  const size_t param_size = 0) :
    Local_Service_Header(DEMSERV_SEND),
    service_code(srvc_code),
    parameters_size(param_size - sizeof(Local_Msg_Entry_Header))
  {
    // empty
  }

public:

  long get_service_code() const
  {
    return service_code;
  }

  void set_parameters_size(const size_t size)
  {
    parameters_size = size;
  }

  size_t get_parameters_size() const
  {
    return parameters_size;
  }
};

/**
  
  Message used as identifier of client replys from services.  It is used
  in the following way:
  
  class User_Message_Response : public Local_Msg_Exit_Header
  {
  private:
  // this will be the response from the server.
  type_1 var1, var2 ... var_k;
  ...
  type_i var_i_1, var_i_2, ... var_i_j;
  
  public:
  User_Message_Response(User_Response_Codes u_r_c, others) : 
  Local_Msg_Exit_Header(USER_RESPONSE_CODES_LAST)
  {
  // whatever it takes to initialize your parameters.
  }
  
  ... other functions.
  }
  
  Remember then to have a class User_Response_Codes where you especify
  which response types you actually have. This is the only way you
  have to differenciate your reply's type.
  
  Also, look at the Local_Msg_Exit_Header initialization parameter
  (USER_RESPONSE_CODES_LAST). It means that at the time you are using
  a enumerative type User_Response_Codes, you must always initialize
  with at least a don't care value. This don't care value is used at
  clients side in which you don't care at the construction time of the
  reply_message. Later you will have fixed your answer when receiving
  the message.  

  At server's side you have to initialize Local_Msg_Exit_Header with
  the apropriate type. That will indicate to the client the status of
  the answer.
*/
class Local_Msg_Exit_Header : public Local_Response_Header
{
  friend class Response_For_Registration;

  long response_code;
  
private:  
  
  Local_Msg_Exit_Header(const Local_Response_Code resp_type,
			 const long & resp_code) :
    Local_Response_Header(resp_type),
    response_code(resp_code)
  {
    // empty
  }

  Local_Msg_Exit_Header() :
    response_code(DEMRESP_INVALID)
  {
    // empty
  }
  
protected:
  
  Local_Msg_Exit_Header(const long & resp_code) :
    Local_Response_Header(DEMRESP_RESPONSE_TO_SERVICE),
    response_code(resp_code)
  {
    // empty
  }
  
public:

  void set_response_code(const long resp_code)
  {
    response_code = resp_code;
  }

  long get_response_code() const
  {
    return response_code;
  }
};



class Register_Message : public Local_Msg_Entry_Header 
{
  friend class Local_Msg_Entry_Header;

  char service_name[80];

public:
  Register_Message(const long srvc_code, 
		   const char * src_serv_name) :
    Local_Msg_Entry_Header(DEMSERV_ADD, srvc_code, 
			    sizeof(*this) - sizeof(Local_Msg_Entry_Header))
  {
    strcpy(service_name, src_serv_name);
  }
  
  Register_Message()
  {
    // empty
  }
  
  char * get_service_name () const
  {
    return const_cast<char *>(service_name);
  }
};


class Response_For_Registration : public Local_Msg_Exit_Header
{
  
public:
  /* 
     there are various kind of response:

     DEMRESP_REGISTRATION_OK,
     DEMRESP_INTENDED_DOUBLE_REGISTRATION,
     DEMRESP_SERVICE_NOT_FOUND,
     DEMRESP_RESPONSE_TO_SERVICE,
     
     DEMRESP_INVALID,
     
     those responses account for the action of validating certain
     service at client side. 
  */
      
  Response_For_Registration(const Local_Response_Code deam_resp_code,
			    const long resp_type = 0) :
    Local_Msg_Exit_Header(deam_resp_code, resp_type)
  {
    // empty
  }
  
  Response_For_Registration() :
    Local_Msg_Exit_Header()
  {
    // empty
  }
  
};

class Shutdown_Message : public Local_Msg_Entry_Header
{
public:
  Shutdown_Message() :
    Local_Msg_Entry_Header(DEMSERV_SHUTDOWN, DEMSERV_INVALID, 0)
  {
    // empty
  }
};

# endif // LOCCOM_MESSAGE_HEADER_H











