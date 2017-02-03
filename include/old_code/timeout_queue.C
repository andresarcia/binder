
# include "errno.h"
# include <string.h>
# include <ahNew.H>
# include "timeoutQueue.H"
# include "boot.H"

int Timeout_Queue::instanceCounter = 0;

inline bool operator < (const struct timespec& l, const struct timespec& r)
{
  long timeL = (l.tv_sec + l.tv_nsec/1000000000);
  long timeR = (r.tv_sec + r.tv_nsec/1000000000);

  if (timeL != timeR)
    return timeL < timeR;

  return ((l.tv_nsec%1000000000) < (r.tv_nsec%1000000000));
}

    
inline bool operator <= (const struct timespec& l, const struct timespec& r)
{
  long timeL = (l.tv_sec + l.tv_nsec/1000000000);
  long timeR = (r.tv_sec + r.tv_nsec/1000000000);

  if (timeL != timeR)
    return timeL < timeR; // <==> timeL <= timeR

  return ((l.tv_nsec%1000000000) <= (r.tv_nsec%1000000000));
}


inline bool operator > (const struct timespec& l, const struct timespec& r)
{
  return ! (l <= r);
}


inline bool operator >= (const struct timespec& l, const struct timespec& r)
{
  return ! (l < r);
}


Timeout_Queue::Timeout_Queue() : isShutdown(false)
{
  if (instanceCounter >= 1)
    TERMINATE("Double instantiation (%d) of Timeout_Queue", instanceCounter);

  instanceCounter++;

  pthread_mutex_init(&mutex, NULL);

  pthread_cond_init(&cond, NULL);
  
}


pthread_t * Timeout_Queue::start_thread()
  throw (exception, AlephExc, UnexpectedException)
{
  if (pthread_create(&threadId, NULL, triggerEventThread, this) != 0)
    Throw (UnexpectedException) ();
  
  return &threadId;
}


Timeout_Queue::~Timeout_Queue()
{
  if (!isShutdown)
    TERMINATE("Timeout_Queue is not shut down");

  int status = pthread_mutex_destroy(&mutex);

  pthread_mutex_destroy(&mutex);

  pthread_cond_destroy(&cond);

  status = pthread_cond_destroy(&cond);
}


void Timeout_Queue::insertEvent(Timeout_Queue::Event *event) throw (Overflow)
{
  ASSERT(event != NULL);
  {
    UseMutex CRITICAL_SECTION(mutex);

    ASSERT(event->get_execution_status() != Event::In_Queue);

    if (isShutdown)
      return;

    event->set_execution_status(Event::In_Queue);

    prioQueue.insert(event);
  }
  
  pthread_cond_signal(&cond);
}


void Timeout_Queue::cancelEvent(Timeout_Queue::Event* event) 
{
  UseMutex CRITICAL_SECTION(mutex);

  if (isShutdown)
    return;

  if (event->get_execution_status() != Event::In_Queue)
    return;

  event->set_execution_status(Event::Canceled);

  prioQueue.remove(event);

  pthread_cond_signal(&cond);
}


void *Timeout_Queue::triggerEvent()
{
  Event *event_to_schedule;
  Event *event_to_execute;
  struct timespec t;
  int status = 0;

  UseMutex CRITICAL_SECTION(mutex);

  while (1)
    {
      /* sleep if there is no events */ 
      while ((prioQueue.get_num_nodes() == 0) && (!isShutdown))
	pthread_cond_wait(&cond, &mutex);

      if (isShutdown)
	goto end; /* if shutdown is activated, get out */

	/* read the soonest event */ 
      event_to_schedule = static_cast<Event*>(prioQueue.lookAt());
	    
      /* compute time when the event must triggered */ 
      t.tv_sec = event_to_schedule->getAbsoluteTime().tv_sec;
      t.tv_nsec = event_to_schedule->getAbsoluteTime().tv_nsec;
	
      do
	{ /* sleep during t units of time, but be immune to signals
	     interruptions (status will be EINTR in the case where
	     the thread was signalized) */
	  status = pthread_cond_timedwait(&cond, &mutex, &t);
	} while (status == EINTR);

      if (isShutdown) /* perhaps shutdown was requested */ 
	goto end;

      if (status == ETIMEDOUT) /* event execution */
	{ 
	  /* event to execute could be changed if it was canceled */
	  event_to_execute = static_cast<Event*>(prioQueue.lookAt());
	  if (event_to_execute != event_to_schedule)
	    { /* events differ ==> event_to_schedule must be canceled */
	      ASSERT(event_to_schedule->get_execution_status() == 
		     Event::Canceled);
	      /* goto to either scheduled soonest event or wait for
		 priority queue insertion */
	      continue; 
	    }
	  /* event must be extracted from priority queue before its
             execution because event function could self insert again
             in the queue */
	  prioQueue.getMin();  
	  event_to_execute->set_execution_status(Event::Executing); 
	  CRITICAL_SECTION.unLock();	 
	  event_to_execute->EventFct(); 
	  CRITICAL_SECTION.lock(); 
	  event_to_execute->set_execution_status(Event::Executed); 
	} /* posix threads only returns two error values. For that
	     reason, there is not else case */
    }

 end: /* shutdown has been requested */

    /* extract and free all events */ 
  while (prioQueue.get_num_nodes() != 0)
    prioQueue.getMin();

  EXIT_THREAD("Terminating timeoutQueue thread %ld", pthread_self();
}


void Timeout_Queue::shutdown()
{
  UseMutex CRITICAL_SECTION(mutex);

  isShutdown = true;

  pthread_cond_signal(&cond);
}


void* Timeout_Queue::triggerEventThread(void *obj)
{
  Timeout_Queue *timeoutQueue = static_cast<Timeout_Queue*>(obj);

  return timeoutQueue->triggerEvent();
}

