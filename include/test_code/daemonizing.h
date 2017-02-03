# ifdef DAEMONIZED_PROCESS

# include <syslog.h>
# include <signal.H>

# define MAXIMUN_FILE_DESC 64

/*
  This function has been taken from The Unix Netwrok Programmin, volume 1
  by Richard Stevens. Page 336.
*/

void daemon_init(const char * pname, int facility)
{
  int i;
  pid_t pid;

  if ( (pid = fork()) == -1)
    {
      Throw (UnexpectedException)();
    }
  else 
    if (pid != 0)
      exit(0);       // parent terminates  

  /* 1st child continues and become sesion leader */
  setsid();
  
  Signal signalHandler(SIGHUP, SIG_IGN);

  if ( (pid = fork()) == -1)
    {
      Throw (UnexpectedException)();
    }
  else 
    if (pid != 0)
      exit(0);       // 1st child terminates

  chdir("/tmp");   // change the working directory

  umask(0);        // clear our file mode creation mask

  for (i = 0; i < MAXIMUM_FILE_DESC; i++)
    close(i);

  openlog(pname, LOG_PID, facility);
}

# else

void daemon_init(const char *, int);

# endif // DAEMONIZED_PROCESS






