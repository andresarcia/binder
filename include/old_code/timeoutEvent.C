
# include <sys/time.h>
# include <unistd.h>
# include "timeoutEvent.H"
# include "boot.H"

TimeoutEvent::TimeoutEvent(Client_Descriptor * _client_descriptor,
			   eventCode           _code, 
			   const MsgId&        _msgid, 
			   struct timespec &   t) :
  Event(t), code(_code), msgId(_msgid),
  client_descriptor(_client_descriptor)
{
  /* Empty */
}

TimeoutEvent::~TimeoutEvent() 
{
  /* Empty */
}

void RepeatRequest::EventFct()
{
  LOG("Repeat request expired: %ld", time(NULL));

  UseMutex critical_section(get_client_descriptor()->get_mutex());

  RequestDataEntry* request_data_entry = requestTablePtr->search(msgId);

  if (request_data_entry == NULL)
    return;

  int n = request_data_entry->getn_time();

  if (n == 0) 
    { /* Maximum retry counter reached; message will be canceled */
      LOG("Timeout expired %d", msgId.getAddress()); 

      try /* prepare upcall notifying to client that timeout has expired */
	{
	  Client_Descriptor::Timeout_Expired_Upcall * upcall =
	    New (Client_Descriptor::Timeout_Expired_Upcall) 
	    (client_descriptor);
	  client_descriptor->insert_pending_upcall(upcall);
	}
      catch (Nomem)
	{
	  client_descriptor->set_panic_mode(IpcD_Exit_Header::Out_Memory);
	}

      request_data_entry->unLock();

      /* free request (network message and events are freed by the
         request_data_entry destructor) */
      requestTablePtr->remove(request_data_entry);
      Delete(request_data_entry);

      client_descriptor->try_to_perform_first_upcall();

      return;
    }

  /* resend message */
  sendQueuePtr->put(request_data_entry->getRequestMsg());
  
  request_data_entry->setn_time(n - 1); /* decrease resending counter */

  /* read request time computed when the request was originally performed */
  unsigned tq = (request_data_entry->getRequestMsg())->getRelayTime();
  request_data_entry->unLock();

  /* read current physical time */
  struct timeval absTime;
  gettimeofday(&absTime,NULL);

  /* create the event of resending message when tq expires */
  struct timespec _t;
  _t.tv_sec = absTime.tv_sec + tq/1000;
  _t.tv_nsec = absTime.tv_usec*1000 + (tq*1000000)%1000000000;
  TimeoutQueue::Event::setAbsoluteTime(_t);
  timeoutQueuePtr->insertEvent(this);
};



/* This function has to insert a LongService in the sendQ
 * (this or another(receive) thread has to insert in the reply
 * table the enough information to indicate that the request
 * is in progress)*/
void SendLongService::EventFct()
{
  LOG("Send LongService expired: %ld", time(NULL));

  UseMutex critical_section(get_client_descriptor()->get_mutex());

  ReplyDataEntry* replyEntry = replyTablePtr->search(msgId);

  if (replyEntry == NULL)
    return;

  replyEntry->unLock();

  unsigned int dirip = (replyEntry->get_source_ip());

  LongServiceMsg *message = New (LongServiceMsg)(msgId, siteEpoch, dirip);
  replyEntry->longServiceWasSent(true);
  
  sendQueuePtr->put(message);		
};


/* This function has to insert a AreYouAlive in the sendQ,
 * decrement m in the clientRequest table and if m>0 
 * has to insert another SendAreYouAlive */
void SendAreYouAlive::EventFct()
{
  LOG("Are You Alive expired: %ld", time(NULL));

  UseMutex critical_section(get_client_descriptor()->get_mutex());

  RequestDataEntry* request_data_entry = requestTablePtr->search(msgId);

  if (request_data_entry == NULL)
    return;

  request_data_entry->unLock();

  int n = request_data_entry->getn_time();

  if (n == 0)
    {
      LOG("Timeout target server crash expired %d", msgId.getAddress()); 
      try 
	{ /* prepare upcall notifying to client that server has crashed */
	  Client_Descriptor::Server_Crash_Upcall * upcall =
	    New (Client_Descriptor::Server_Crash_Upcall) 
	    (client_descriptor);
	  client_descriptor->insert_pending_upcall(upcall);
	}
      catch (Nomem)
	{
	  client_descriptor->set_panic_mode(IpcD_Exit_Header::Out_Memory);
	}      
      
      request_data_entry->unLock();
      requestTablePtr->remove(request_data_entry);
      Delete(request_data_entry);

      client_descriptor->try_to_perform_first_upcall();

      return;
    }

  unsigned int epoch = (request_data_entry->getRequestMsg())->getEpoch();

  unsigned int dirip = (request_data_entry->getRequestMsg())->getAddress();

  AreYouAliveMsg* alive = New (AreYouAliveMsg)(msgId, epoch, dirip); 

  sendQueuePtr->put(alive);

  request_data_entry->setn_time(n-1);

  unsigned int tv = (request_data_entry->getRequestMsg())->getRelayTime();
  request_data_entry->unLock();
	
  struct timeval absTime;

  gettimeofday(&absTime,NULL);

  struct timespec _t;
  _t.tv_sec = absTime.tv_sec + tv/1000;
  _t.tv_nsec = absTime.tv_usec*1000 + (tv*1000000)%1000000000;

  TimeoutQueue::Event::setAbsoluteTime(_t);

  timeoutQueuePtr->insertEvent(this);
};


void ClientExpired::EventFct()
{
  LOG("Client timeout expired: %ld", time(NULL));

  UseMutex critical_section(get_client_descriptor()->get_mutex());

  RequestDataEntry* request_data_entry = requestTablePtr->search(msgId);

  if (request_data_entry == NULL)
    return;

  try /* prepare upcall notifying to client that server has crashed */
    {
      Client_Descriptor::Timeout_Expired_Upcall * upcall =
	New (Client_Descriptor::Timeout_Expired_Upcall) 
	(client_descriptor);
      client_descriptor->insert_pending_upcall(upcall);
    }
  catch (Nomem)
    {
      client_descriptor->set_panic_mode(IpcD_Exit_Header::Out_Memory);
    }      

  request_data_entry->unLock();
  requestTablePtr->remove(request_data_entry);
  Delete(request_data_entry);

  client_descriptor->try_to_perform_first_upcall();
}


void ReplyExpired::EventFct()
{
  LOG("Reply timeout expired: %ld", time(NULL));

  UseMutex critical_section(get_client_descriptor()->get_mutex());

  ReplyDataEntry* replyEntry = replyTablePtr->search(msgId);

  if (replyEntry == NULL)
    return;

  replyEntry->unLock();

  replyTablePtr->remove(replyEntry);
  Delete(replyEntry);
  Delete(this);
}


void Repeat_Message_Event::EventFct()
{
  UseMutex critical_section(get_client_descriptor()->get_mutex());

  Single_Message_Data_Entry * single_message_data_entry =
    single_message_table_ptr->search(msgId);

  if (single_message_data_entry == NULL)
    return;

  single_message_data_entry->unLock();

  int n = single_message_data_entry->getn_time();

  if (n == 0) 
    { /* Maximum retry counter reached; message will be canceled */
      LOG("Single message timeout expired %d", msgId.getAddress()); 

      try /* prepare upcall notifying to client that timeout has expired */
	{
	  Client_Descriptor::Timeout_Expired_Upcall * upcall =
	    New (Client_Descriptor::Timeout_Expired_Upcall) 
	    (client_descriptor);
	  client_descriptor->insert_pending_upcall(upcall);
	}
      catch (Nomem)
	{
	  client_descriptor->set_panic_mode(IpcD_Exit_Header::Out_Memory);
	}

      /* free request (network message and events are freed by the
         request_data_entry destructor) */
      single_message_table_ptr->remove(single_message_data_entry);
      Delete(single_message_data_entry);

      client_descriptor->try_to_perform_first_upcall();

      return;
    }

  single_message_data_entry->setn_time(n - 1); /* decrease resending counter */

  Single_Message * net_message = 
    single_message_data_entry->get_single_message();

  sendQueuePtr->put(net_message);
}


