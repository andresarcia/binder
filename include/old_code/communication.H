# define LOCATOR_PATH "/tmp/.LocatorCommPath"
# define SA	struct sockaddr
# define LISTENQ		1024	/* 2nd argument to listen() */

# ifndef BZERO
# define BZERO
# define	bzero(ptr,n)		memset(ptr, 0, n)
# endif

# include <sys/types.h>	        /* basic system data types */
# include <sys/socket.h>	/* basic socket definitions */
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/un.h>		/* for Unix domain sockets */
# include <sys/select.h>	/* for convenience */
# include <ostream.h>
# include <unistd.h>

# ifndef AF_LOCAL
# define AF_LOCAL	AF_UNIX
# endif





