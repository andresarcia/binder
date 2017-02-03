# ifndef LOCATOR_TABLES_H
# define LOCATOR_TABLES_H

/******************************
    Global Table Definitions
******************************/
# include "binding_point.H"
# include "protected_lhash.H"
# include "remote_message_header.H"
# include "local_message_header.H"
# include "remote_multiserver_binding.H"
# include "ipcClient.H"
# include <unistd.h>


// Waiting_For_Remote_Response_Table
// This table stores the tuple <Message_Id, Binding_Point *>, which
// serves as a reception point to the invocation being processed.
// Once the processed invocation is ready at server's side, then it
// will be sent through the "Binding_Point *" stored in this table.

// The change for a Message_Id as a key of the bucket is because it 
// garantees the uniqueness of the bucket identification. This also 
// could later be used for a simultaneous invocation from the same 
// container. Let's say several threads are running in a container. 
// In the old way, with a container_id as a key, it wouldn't have 
// been possible for two or more threads to simultaneously send 
// invocations to a server, because the container_id would have been
// the same. It could lead to confusion when delivering the answers.


class Locator_Remote_Services;


class Wait_Broadcast_Resp_Bucket : public ProtectedLhashTable<MsgId>::Bucket
{
  Binding_Point * return_point;

  Object_Id searched_object_id;
  
  Wait_Broadcast_Resp_Bucket()
  {
    // empty
  }
  
public:

  Wait_Broadcast_Resp_Bucket(const MsgId & _msg_id,
			     Binding_Point * const _return_point,
			     const Object_Id & _object_id) :
    ProtectedLhashTable<MsgId>::Bucket(_msg_id),
				return_point(_return_point),
				searched_object_id(_object_id)
  {
    // empty
  }
  
  Binding_Point * get_return_point() 
  {
    return return_point;
  }

  const Object_Id & get_searched_object_id() const
  {
    return searched_object_id;
  }
};



class Srv_Response_Point_Bucket : 
  public ProtectedLhashTable<Message_Id>::Bucket
{
  // The container that is waiting for the response.
  // Remember that just one thread at time can do an invocation,
  // therefore the source container ID is always unique.
  Container_Id  source_container_id;

  // Remote return point.
  Remote_Multiserver_Binding<Locator_Remote_Services> * return_point;

public:
  Srv_Response_Point_Bucket
  (const Message_Id & _msg_id, 
   const Container_Id & _source_cnt_id, 
   Remote_Multiserver_Binding<Locator_Remote_Services> * _bp_ptr) :
    ProtectedLhashTable<Container_Id>::Bucket(_msg_id),
				       source_container_id(_source_cnt_id),
				       return_point(_bp_ptr)
  {
    // empty
  }

  Remote_Multiserver_Binding<Locator_Remote_Services> * 
  get_return_point() const
  {
    return return_point;
  }
  
  const Container_Id & get_container_id() const
  {
    return source_container_id;
  }
};

// Bucket for the object table. In this table all the object within the site
// are registered. To each object it is associated a state and a container.

enum State_Of_Container
{
  CNT_READY,
  CNT_PROCESSING_INVOCATION,
  CNT_NOT_RECEIVING,

  CNT_LAST
};

enum State_Of_Object
{
  OBJ_IDLE,
  OBJ_PROCESSING_INVOCATION,
  OBJ_MIGRATING, // TODO: NEW!
  
  OBJ_LAST
};

class Registered_Object_Bucket  : 
  public ProtectedLhashTable<Object_Id>::Bucket
{
  // double link to the object list in the container table entry. 
  Dlink link_to_container;

  Container_Id associated_container_id;

  // The logical_timestamp determines the number of times the object
  // has moved around in the system. This number can be compared with
  // other logical_timestamp in order to stablish the validity of the
  // position (Locator) in certain moment.  
  Logical_Timestamp logical_timestamp;

  State_Of_Object current_state;

public:
  Registered_Object_Bucket(const Object_Id & _the_object,
			   const Container_Id & _assoc_container,
			   const Logical_Timestamp _timestamp) :
    ProtectedLhashTable<Object_Id>::Bucket(_the_object),
				    associated_container_id(_assoc_container),
				    logical_timestamp(_timestamp),
				    current_state(OBJ_IDLE)
  {
    // empty
  }

  State_Of_Object get_current_state() const
  {
    return current_state;
  }
  
  void set_current_state(State_Of_Object _new_state) 
  {
    current_state = _new_state;
  }

  const Container_Id & get_associated_container_id() const
  {
    return associated_container_id;
  }
  
  Dlink & get_link_to_container() 
  {
    return link_to_container;
  }

  Logical_Timestamp get_logical_timestamp() const
  {
    return logical_timestamp;
  }
};


// Node for the delayed invocation list. The list function is to
// receive request and replys that can not be inmediately taken and
// processed. So, when the object is finished with a request or a
// reply, it can look up for another one into this list.

class Delayed_Invocation_Node : public Dnode<Reception_Type>
{
  Invocation_Request_Msg request_message;

  void * delayed_request;
  
public:
  Delayed_Invocation_Node(const Invocation_Request_Msg & _request_msg) :
    Dnode<Reception_Type>(RECTYPE_INVOCATION_REQUEST),
    request_message(_request_msg)
  {
    if (request_message.get_request_size() > 0)
      {
	delayed_request = Malloc(request_message.get_request_size());
	memcpy(delayed_request, 
	       _request_msg.get_request(), 
	       request_message.get_request_size());
      }
    else
      if (request_message.get_request_size() == 0)
	delayed_request = NULL;
      else
	ERROR("*** ERROR: In Delayed_Invocation_Node constructor");
  }

  Invocation_Request_Msg & get_request_message()  
  {
    return request_message;
  }

  void * get_delayed_request() const
  {
    return delayed_request;
  }

  virtual ~Delayed_Invocation_Node()
  {
    if (request_message.get_request_size() > 0)
      Free(delayed_request);
  }
};

// Node for the delayed invocation list. The list function is to
// receive request and replys that can not be inmediately taken and
// processed. So, when the object is finished with a request or a
// reply, it can look up for another one into this list.

class Delayed_Answer_Node : public Dnode<Reception_Type>
{
  Invocation_Reply_Msg reply_msg;

  void *  delayed_reply;

public:

  Delayed_Answer_Node(const Invocation_Reply_Msg & _reply_msg) :
    Dnode<Reception_Type>(RECTYPE_INVOCATION_REPLY),
    reply_msg(_reply_msg)
  {
    if (reply_msg.get_reply_size() > 0)
      {
	delayed_reply = Malloc(reply_msg.get_reply_size());
	memcpy(delayed_reply, 
	       _reply_msg.get_reply(), 
	       reply_msg.get_reply_size());
      }
    else
      if (reply_msg.get_reply_size() == 0)
	delayed_reply = NULL;
      else
	ERROR("*** ERROR: In Delayed_Answer_Node constructor");
  }
  
  const Invocation_Reply_Msg & get_reply_msg() const
  {
    return reply_msg;
  }
  
  void * get_delayed_reply() const
  {
    return delayed_reply;
  }

  virtual ~Delayed_Answer_Node()
  {
    if (reply_msg.get_reply_size() > 0)
      Free(delayed_reply);
  }
};




// Bucket for the container table. This table registers all the containers
// within a site.

class Registered_Container_Bucket  : 
  public ProtectedLhashTable<Container_Id>::Bucket
{
  pid_t container_pid;
  
  Dlink associated_objects_list;

  State_Of_Container current_state;

  // Through waiting_invocation_return_point I can communicate with 
  // a container waiting for an invocation. This variable is going
  // to be used iff the container is in CNT_READY and an invocation
  // is arriving and need to be served.
  Binding_Point * waiting_invocation_return_point;

  // The delayed invocation list, which functions as a container for 
  // not processed invocations.
  Dnode<Reception_Type> waiting_invocation_list;

  unsigned long long pending_replys;

public:

  Registered_Container_Bucket(const Container_Id & _container_uid,
			      const pid_t _container_pid) :
    ProtectedLhashTable<Container_Id>::Bucket(_container_uid),
				       container_pid(_container_pid),
				       current_state(CNT_NOT_RECEIVING),
				       waiting_invocation_return_point(NULL),
				       pending_replys(0)
  {
    // empty
  }

  Dlink & get_associated_objects_list() 
  {
    return associated_objects_list;
  }

  void set_invocation_return_point(Binding_Point * _return_point)
  {
    waiting_invocation_return_point = _return_point;
  }
  
  Binding_Point * get_invocation_return_point() const 
  {
    return waiting_invocation_return_point;
  }

  State_Of_Container get_current_state() const
  {
    return current_state;
  }
  
  void set_current_state(State_Of_Container _new_state) 
  {
    current_state = _new_state;
  }
  
  Dnode<Reception_Type> & get_waiting_invocation_list() 
  {
    return waiting_invocation_list;
  }

  void increase_pending_replys() 
  {
    ASSERT(pending_replys >= 0);
    pending_replys++;
  }

  void decrease_pending_replys()
  {
    ASSERT(pending_replys > 0);
  
    pending_replys--;
  
    if (get_waiting_invocation_list().isEmpty() && pending_replys == 0)
      current_state = CNT_NOT_RECEIVING;
  }
  
  ~Registered_Container_Bucket()
  {
    Dnode<Reception_Type> *current;
    
    while(!waiting_invocation_list.isEmpty())
      {
	current = waiting_invocation_list.removeNext();

	switch(current->getData())
	  {
	  case RECTYPE_INVOCATION_REQUEST :
	    AllocDelete(*objectAlloc, 
			static_cast<Delayed_Invocation_Node *>(current));
	    break;
	  case RECTYPE_INVOCATION_REPLY :
	    AllocDelete(*objectAlloc, 
			static_cast<Delayed_Answer_Node *>(current));
	    break;
	  default:
	    ERROR("*** ERROR: Unknown message type in container");
	  }
      }
  }
  
};

# endif // LOCATOR_TABLES_H
