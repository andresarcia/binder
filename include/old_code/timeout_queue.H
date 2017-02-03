
# ifndef TIMEOUTQUEUE_H
# define TIMEOUTQUEUE_H

# include <pthread.h>
# include <tpl_binHeap.H>
# include <useMutex.H>
# include "ipcPars.H"

class Timeout_Queue 
{
public:

  static const size_t MaxNumberOfEvents = 2048;

  friend class Event : private BinHeapVtl<struct timespec>::Node
  {
    friend class Timeout_Queue;
  private:
    
    friend bool operator < (const struct timespec&, const struct timespec&);
    friend bool operator <= (const struct timespec&, const struct timespec&);
    friend bool operator > (const struct timespec&, const struct timespec&);
    friend bool operator >= (const struct timespec&, const struct timespec&);

    enum Execution_Status { Out_Queue, 
			    In_Queue, 
			    Canceled, 
			    Executing, 
			    Executed };

    struct timespec  absoluteTime;
    Execution_Status execution_status;

  protected:

    Event(struct timespec t) : 
      absoluteTime(t), execution_status(Out_Queue)
    {
      // Empty 
    }

    Event(long seconds, long nseconds) :
      execution_status(Out_Queue)
    {
      absoluteTime.tv_sec  = seconds;
      absoluteTime.tv_nsec = nseconds;
    }

  public:

    virtual ~Event()
    {
      //EMPTY 
    }

    Execution_Status get_execution_status() const { return execution_status; }

    void set_execution_status(Execution_Status status)
    {
      execution_status = status;
    }    

    struct timespec getAbsoluteTime() { return absoluteTime; }

    void setAbsoluteTime(struct timespec _t)
    {
      absoluteTime = _t;
    }
	
    virtual void EventFct() = 0;
  };

private:

  //ArrayHeap<Event*, MaxNumberOfEvents> prioQueue;
  BinHeapVtl<struct timespec> prioQueue;

  pthread_mutex_t    mutex;

  pthread_cond_t     cond;

  pthread_t          threadId;

  bool               isShutdown;

  static int         instanceCounter;
  
  void *triggerEvent();

  static void* triggerEventThread(void*);

public:

  Timeout_Queue();

  ~Timeout_Queue();

  void insertEvent(Event*) 
    throw (exception, AlephExc, Overflow);

  void cancelEvent(Event*); 

  pthread_t * start_thread()
    throw (std::exception, UnexpectedException);

  void shutdown();

  pthread_t getThreadId() const { return threadId; }
};

# endif /* TIMEOUTQUEUE_H */

