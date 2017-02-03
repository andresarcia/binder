# ifndef  LOCCOM_MESSAGE_HEADER_H
# define  LOCCOM_MESSAGE_HEADER_H

# define REGISTERING true
# define GENERAL_SERVICE false

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

enum Internal_Deamon_Response
{
  LOCCOM_REGISTRATION_OK,
  LOCCOM_INTENDED_DOUBLE_REGISTRATION,
  LOCCOM_SERVICE_NOT_FOUND,
  
  LOCCOM_LAST
};


class Client_Id
{
  int client_socket;

public:

  Client_Id(const int cli_sock) :
    client_socket(cli_sock)
    {
      // empty
    }

  int get_client_socket() const
    {
      return client_socket;
    }
};

enum Deamon_Service_Code
{
  DEAMON_CLIENT_CTOR,
  DEAMON_ADD,
  DEAMON_DELETE,
  DEAMON_SEND,

  DEAMON_INVALID,

  DEAMON_LAST
};

class Deamon_Service_Header
{
  Deamon_Service_Codes deamon_service_code;

protected:

  Deamon_Service_Header(Deamon_Service_Codes service_code) : 
    deamon_service_code(service_code)
  {
    // Empty
  }

  Deamon_Service_Header() : deamon_service_code(DEAMON_INVALID)
  {
    // Empty
  }

};

class Deamon_Msg_Entry_Header : private Deamon_Service_Header
{
  long   service_code;
  size_t parameters_size;

protected:

  Deamon_Msg_Entry_Header() :
    service_code(0),
    parameters_size(0)
    {
      // empty
    }

  Deamon_Msg_Entry_Header(const long srvc_code,
			  const size_t param_size) :
    service_code(srvc_code),
    parameters_size(param_size)
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


class Deamon_Msg_Exit_Header 
{
  long response_code;

public:
  
  Deamon_Msg_Exit_Header(const long & resp_code) :
    response_code(resp_code)
    {
      // empty
    }

  Deamon_Msg_Exit_Header() :
    response_code(LOCCOM_LAST)
    {
      // empty
    }

  void set_response_code(const long resp_code)
    {
      response_code = resp_code;
    }

  long get_response_code() const
    {
      return response_code;
    }
};


class Register_Message : public Deamon_Msg_Entry_Header 
{
  char service_name[80];

public:
  Register_Message(const long srvc_code, 
		   const char * src_serv_name) :
    Deamon_Msg_Entry_Header(REGISTERING, srvc_code)
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

class Response_For_Registration : public Deamon_Msg_Exit_Header
{

public:
  /* 
     there are two kinds of responses:
     LOCCOM_REGISTRATION_OK,
     LOCCOM_INTENDED_DOUBLE_RESGISTRATION
      
     those responses account for the action of validating certain
     service at client side 
  */
      
  Response_For_Registration(const long & resp_type) :
    Deamon_Msg_Exit_Header(resp_type)
    {
      // empty
    }

  Response_For_Registration() :
    Deamon_Msg_Exit_Header(LOCCOM_LAST)
    {
      // empty
    }

};




# endif // LOCCOM_MESSAGE_HEADER_H


