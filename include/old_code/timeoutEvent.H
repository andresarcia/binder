# ifndef TIMEOUTEVENT_H
# define TIMEOUTEVENT_H

# include <time.h>
# include <aleph.H>
# include <dlink.H>
# include "timeoutQueue.H"
# include "msgId.H"
# include "messages.H"
# include "connectionTable.H"

enum eventCode {
  REPEATREQUEST,
  SENDLONGSERVICE,
  SENDAREYOUALIVE,
  CLIENTEXPIRED,
  REPLYEXPIRED,
  REPEAT_MESSAGE,
  MESSAGE_EXPIRED,
  ACK_EXPIRED
};

class TimeoutEvent : public TimeoutQueue::Event
{
protected:

  eventCode           code;
  MsgId               msgId;

  Client_Descriptor * client_descriptor;

public:

  TimeoutEvent(Client_Descriptor * _client_descriptor,
	       eventCode           _code, 
	       const MsgId &       _msgid, 
	       struct timespec &   t);

  virtual ~TimeoutEvent() ;

  eventCode getEventCode()
  {
    return code;
  }

  MsgId& getMsgId()
  {
    return msgId;
  }

  Client_Descriptor * get_client_descriptor() { return client_descriptor; }

  void reschedule(float time_in_msecs)
  {
    struct timespec sched_time;
    
    sched_time.tv_sec = absTime.tv_sec + time_in_msecs/1000;
    
    sched_time.tv_nsec = absTime.tv_usec*1000 + 
      (time_in_msecs*1000000)%1000000000;
    
    TimeoutQueue::Event::setAbsoluteTime(sched_time);
    
    timeoutQueuePtr->insertEvent(this);
  }
  
};


class RepeatRequest : public TimeoutEvent
{
public:

  RepeatRequest(Client_Descriptor * _client_descriptor,
		MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, REPEATREQUEST, _msgid, t)
  {
    //EMPTY
  }

  ~RepeatRequest() 
  {
    //EMPTY
  }

  virtual void EventFct();
};

class SendLongService : public TimeoutEvent
{
public:

  SendLongService(Client_Descriptor * _client_descriptor,
		  MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, SENDLONGSERVICE, _msgid, t)
  {
    //EMPTY
  }

  ~SendLongService() 
  {
    //EMPTY
  }

  virtual void EventFct();
};
	

class SendAreYouAlive : public TimeoutEvent
{
public:

  SendAreYouAlive(Client_Descriptor * _client_descriptor,
		  MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, SENDAREYOUALIVE, _msgid, t)
  {
    //EMPTY
  }

  ~SendAreYouAlive() 
  {
    //EMPTY
  }

  virtual void EventFct();
};
	
class ClientExpired : public TimeoutEvent
{
public:

  ClientExpired(Client_Descriptor * _client_descriptor,
		MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, CLIENTEXPIRED, _msgid, t)
  {
    //EMPTY
  }

  ~ClientExpired()
  {
    //EMPTY
  }

  virtual void EventFct();
};

class ReplyExpired : public TimeoutEvent
{
public:

  ReplyExpired(Client_Descriptor * _client_descriptor,
	       MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, REPLYEXPIRED, _msgid, t)
  {
    //EMPTY
  }

  ~ReplyExpired()
  {
    //EMPTY
  }

  virtual void EventFct();
};



class Repeat_Message_Event : public TimeoutEvent
{
public:

  Repeat_Message_Event(Client_Descriptor * _client_descriptor,
		       MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, REPEAT_MESSAGE, _msgid, t)
  {
    //EMPTY
  }

  ~Repeat_Message_Event()
  {
    //EMPTY
  }

  virtual void EventFct();
};


# endif // TIMEOUTEVENT_H

