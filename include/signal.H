
# ifndef SIGNAL_H
# define SIGNAL_H

#include <signal.h>
#include <aleph.H>

/** 
	Signal

	Signal sets the signal handler for a particular signal when
	it's created and restore the old signal handler when it's
	destroyed. 

	@autor Carlos Nava <navac@ula.ve>
*/
class Signal
{
public:

  typedef void Sigfunc(int);

private:

  /// Stored the old signal handler
  struct sigaction	oldSigaction;

  /// Signal number
  int				signalNumber;

  /* If this flag is set, a system call interrupted by the signal
     signalNumber will be automatically restarted by the kernel */
  bool				restartCalls;

public:

  Signal(int signo, Sigfunc *func, bool _restartcalls = true):
    restartCalls(_restartcalls)
  {
    struct sigaction    act, oact;
	  
    signalNumber = signo;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if (signo == SIGALRM) 
      {
#ifdef  SA_INTERRUPT
	act.sa_flags |= SA_INTERRUPT;   
#endif
      } 
    else 
      {
	if (restartCalls)
	  {
#ifdef  SA_RESTART
	    act.sa_flags |= SA_RESTART;    
#endif
	  }
      }

    if (sigaction(signo, &act, &oact) < 0)
      ERROR("Cannot modify the action associated with the %d signal",
	     signo); 
    oldSigaction = oact;
  }

  ~Signal()
  {
    if (sigaction(signalNumber, &oldSigaction, NULL) < 0)
      ERROR("Cannot modify the action associated with the %d signal",
	     signalNumber); 
  }

};

# endif //SIGANL_H

