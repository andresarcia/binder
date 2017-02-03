# include <pthread.h>
# include <syslog.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
#include        <sys/types.h>   /* basic system data types */
#include <sys/stat.h>


static pthread_t main_thread_id;

void sig_term(int signo)
{
  if (pthread_self() == main_thread_id)
    {
      exit(0);
    }
}

typedef   void    Sigfunc(int);

Sigfunc *
signal(int signo, Sigfunc *func)
{
        struct sigaction        act, oact;

        act.sa_handler = func;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        if (signo == SIGALRM) {
#ifdef  SA_INTERRUPT
                act.sa_flags |= SA_INTERRUPT;   /* SunOS 4.x */
#endif
        } else {
#ifdef  SA_RESTART
                act.sa_flags |= SA_RESTART;             /* SVR4, 44BSD */
#endif
        }
        if (sigaction(signo, &act, &oact) < 0)
                return(SIG_ERR);
        return(oact.sa_handler);
}
/* end signal */

Sigfunc *
Signal(int signo, Sigfunc *func)        /* for our signal() function */
{
        Sigfunc *sigfunc;

        if ( (sigfunc = signal(signo, func)) == SIG_ERR)
	  abort();
	
        return(sigfunc);
}

void daemon_init(const char * pname, int facility)
{
  int i;
  pid_t pid;

  if ( (pid = fork()) == -1)
    abort();
  else 
    if (pid != 0)
      exit(0);       // parent terminates  

  /* 1st child continues and become sesion leader */
  setsid();
  
  Signal(SIGHUP, SIG_IGN);

  if ((pid = fork()) == -1)
    abort();
  else 
    if (pid != 0)
      exit(0);       // 1st child terminates

  if (chdir("/tmp") < 0)   // change the working directory
    syslog(LOG_NOTICE, "ERROR %m");

  umask(0);        // clear our file mode creation mask

  for (i = 0; i < 64; i++)
    close(i);

  openlog(pname, LOG_PID, facility);
}

void * routine1 (void * arg)
{
  FILE * r1_out = fopen("routine1.out", "w");
  
  for (int j = 0; j < 1000; j++)
    {
      //syslog(LOG_NOTICE, "routine1: %i", j);
      fprintf(r1_out, "routine1: %i", j);
      usleep(500000);
    }

  fclose(r1_out);
}

void * routine2 (void * arg)
{
  FILE * r2_out = fopen("routine2.out", "w");
  
  for (int j = 0; j < 1000; j++)
    {
      //syslog(LOG_NOTICE, "routine2: %i", j);
      fprintf(r2_out, "routine1: %i", j);
      usleep(500000);
    }

  fclose(r2_out);
}

int main(int argc, char * argv[])
{
  daemon_init(argv[0], LOG_LOCAL6);
    
  main_thread_id = pthread_self();

  pthread_t local_front_thread, remote_front_thread;
  
  Signal(SIGTERM, sig_term);

  pthread_create(&local_front_thread, NULL, routine1, NULL);

  pthread_create(&remote_front_thread, NULL, routine2, NULL);  
  
  // pthread_join is necesary so that acquired resources are freed.
  // It also works for making the deamon run in the thread of reception_point,
  // which waits on a select system call (it makes the process idle when idle).

  pthread_join(local_front_thread, NULL);
  
  pthread_join(remote_front_thread, NULL);
  
  return 0;
}





