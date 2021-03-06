# ifndef CLIENT_BINDING_H
# define CLIENT_BINDING_H


# include "base_message_header.H"
# include <pthread.h>

class Reception_Point;

class Client_Binding
{
  friend class Reception_Point;

protected:

  Reception_Point        * link_to_reception_point;
 
  void                   * request_message;
  
  static pthread_mutex_t   free_mutex;

  /**
    To be constructed Local_Binding needs a client socket and a 
    Local_Reception_Point pointer. The client socket is the way Local_Binding
    will communicate the reply to the client. And Local_Reception_Point
    works as a communication link to the Server attending the services.
    This link is important because it helps with the control of the active
    services.
  */
  Client_Binding(Reception_Point * dem_rec_point) :
    link_to_reception_point(dem_rec_point)
  {
    // empty
  }
  
  void set_request_message(void *ptr)
  {
    request_message = ptr;
  }

public:
  /**
     Remember from loccom_message_header.H the response class has the form:
     class Your_Inherited_Class : public Local_Msg_Exit_Header
     {
     ...
     };
     
     Since you already have a Response class which has inherited  
     Local_Msg_Exit_Header, then you simply 
     respond(your_inherited_class, sizeof(your_inherited_class)).
     
     this is because your_inherited_class is_a Local_Msg_Exit_Header.
  */
  
  virtual ssize_t respond (Msg_Exit_Header *, const size_t);  
  
  virtual ssize_t respond (Msg_Exit_Header *, const size_t,
			   void *, const size_t);
};

# endif // CLIENT_BINDING_H
