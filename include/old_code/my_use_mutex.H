#ifndef MY_USEMUTEX_H
#define MY_USEMUTEX_H

#include <pthread.h>
#include <ahExceptions.H>
#include <errno.h>
class My_UseMutex
{
private:

  pthread_mutex_t *mutex;

  void take_lock(pthread_mutex_t *m) throw  (exception, AlephExc, Lock)
  {
    int m_error = pthread_mutex_trylock(m);
    
    if (m_error == EBUSY)
      Throw (Lock)();
  }

public:

  My_UseMutex(pthread_mutex_t *m)
    throw (exception, AlephExc, Lock) :
    mutex (m)
    {
      take_lock(m);
    }
	
  My_UseMutex(pthread_mutex_t& m) 
    throw (exception, AlephExc, Lock) :
    mutex (&m)
    {
      take_lock(&m);
    }

  void unLock()
    {
      pthread_mutex_unlock(mutex);
    }

  void lock() throw (exception, AlephExc, Lock) 
    {
      take_lock(mutex);
    }

  void enter() { lock(); }

  void leave() { unLock(); }
	
  ~My_UseMutex()
    {
      pthread_mutex_unlock(mutex);
    }
};
#endif // USEMUTEX_H

