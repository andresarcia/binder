# include "timeoutQueue.H"
# include <time.h>
# include <aleph.H>

enum Event_Code
{
  GROUP_ANSWER_TIME_EXPIRED,

  GROUP_LAST
};


class Group_Timeout_Event : public TimeoutQueue::Event
{
  Event_Code event_code;

  MsgId msg_id;

public:
  Group_Timeout_Event(const Event_Code _event_code,
		      const struct timespec & _exec_time,
		      const MsgId & _msg_id) :
    TimeoutQueue::Event(_exec_time),
		  event_code(_event_code),
		  msg_id(_msg_id)
  {
    // empty
  }

  const Event_Code get_event_code() const
  {
    return event_code;
  }

  const MsgId get_msg_id() const
  {
    return msg_id;
  }
};

//TODO: TEST THIS
class Group_Answer_Time_Expired : public Group_Timeout_Event
{
public:
  Group_Answer_Time_Expired(const struct timespec & _exec_time
			    const MsgId & _msg_id) :
    Group_Timeout_Event(GROUP_ANSWER_TIME_EXPIRED, _exec_time, _msg_id)
  {
    // empty
  }

  virtual void EventFct()
  {
    CRITICAL_SECTION(GROUP_MUTEX);

    // search msg_id entry in message table
    Msg_Id_Sqc_Nbr_Map_Bucket * 
      searched_msg = static_cast<Msg_Id_Sqc_Nbr_Map_Bucket*>
      (msg_id_sqc_nbr_map_table.search(msg_id));
    
    if (searched_msg == NULL) 
      // response is late and it was taken by "group_receive_response"
      return;

    searched_msg->unLock();

    // search waiting_response entry and update lost response counter
    Wait_For_Responses_Bucket * 
      searched_bucket = static_cast<Wait_For_Responses_Bucket *>
      (client_response_table.search(searched_msg->get_sequence_number()));
    
    // remove msg_id entry 
    msg_id_sqc_nbr_map_table.remove(searched_msg);

    // the expired event is deleted in searched_msg destructor 
    AllocDelete(*objectAlloc, searched_msg);
    
    searched_bucket->unLock();
  
    searched_bucket->add_lost_response();

    // check if deamon is ready to respond to client and respond if necesary
    if (searched_bucket->ready_to_respond())
    {
      Responses_RetMsg 
	return_msg(searched_bucket->get_client_return_service_code(),
		   GRP_OK,
		   searched_bucket->get_total_members_snapshot(),
		   searched_bucket->get_number_of_expected_responses(),
		   searched_bucket->get_current_number_of_responses(),
		   searched_bucket->get_current_buffer_size());

      Msg_Entry_Header * msg_to_return = 
	static_cast<Msg_Entry_Header *>(&return_msg);

      searched_bucket->get_waiting_client_port()->
	rpc_reply(msg_to_return,
		  sizeof(Responses_RetMsg),
		  searched_bucket->get_buffer_for_response(),
		  searched_bucket->get_current_buffer_size());

      client_response_table.remove(searched_bucket);

      AllocDelete(*objectAlloc, searched_bucket);
    }
  }
};










