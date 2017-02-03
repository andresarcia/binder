# ifndef LOCATOR_COMM_BINDING_H
# define LOCATOR_COMM_BINDING_H

# include "base_message_header.H"
# include <pthread.h>
# include "ipcClient.H"

class Locator_Comm_Point;

class Locator_Comm_Binding
{
  Locator_Comm_Binding()
    {
      // empty
    }

  /*
    Determines wheter the service has been accomplish (false) or not (true). 
    This information is used when shutting down the Locator_Comm_Point. 
  */

  bool still_busy; 

  Locator_Comm_Point        * link_to_locator_comm_point;
 
  /**
    To be constructed Locator_Comm_Binding needs a Locator_Comm_Point
    pointer. The Local_Reception_Point works as a communication link
    to the Server attending the services.  This link is important
    because it helps with the control of the active services.  
  */

  MsgId message_id;

  void write_to_client(void *, size_t);

public:

  Locator_Comm_Binding(Locator_Comm_Point * dem_rec_point, 
		       MsgId _message_id ) :
    // It is true because the service hasn't been accomplished 
    still_busy(true),
    link_to_locator_comm_point(dem_rec_point),
    message_id(_message_id)
  {
    // Empty 
  }

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

  void increase_active_services();
  
  void decrease_active_services();

  void set_still_busy(const bool _still_busy)
    {
      still_busy = _still_busy;
    }

  const bool get_still_busy() const
    {
      return still_busy;
    }
  
  ssize_t rpc_reply (Msg_Entry_Header * /* response_message */, 
		     const size_t /* Size of the message, it will generally
				     be sizeof(response_message) */);
  
  ssize_t rpc_reply (Msg_Entry_Header * /* response_message */, 
		     const size_t /* Size of the message, it will generally
				     be sizeof(response_message) */,
		     void * /* Invocation Reply */, 
		     const size_t /* Invocation Reply Size*/ );

  ~Locator_Comm_Binding()
  {
    // empty
  }
};

# endif // LOCATOR_COMM_BINDING_H












