# include <iostream>
#include "ipcClient.H"

#define	SA	struct sockaddr

MsgId msgid;

# define BUFFER_SIZE 65535

char * received_string;

char str[80];

Ipc_MultiClient_Server * ptr_server;

char request_buffer[BUFFER_SIZE];

RawMsg request_message(&request_buffer[0], BUFFER_SIZE);




ssize_t readn(int fd, void *vptr, size_t n)
{
  size_t	nleft;
  ssize_t	nread;
  char	*ptr;
  
  ptr = static_cast< char*>(vptr);
  nleft = n;
  while (nleft > 0) {
    if ( (nread = read(fd, ptr, nleft)) < 0) {
      if (errno == EINTR)
	nread = 0;		/* and call read() again */
      else
	return(-1);
    } else if (nread == 0)
      break;				/* EOF */
    
    nleft -= nread;
    ptr   += nread;
  }
  return(n - nleft);		/* return >= 0 */
}


ssize_t writen(int fd, const void *vptr, size_t n)
{
  size_t		nleft;
  ssize_t		nwritten;
  const char	*ptr;
  
  ptr = static_cast<const char*>(vptr);
  nleft = n;
  while (nleft > 0) {
    if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
      if (errno == EINTR)
	nwritten = 0;		/* and call write() again */
      else
	return(-1);			/* error */
    }
    
    nleft -= nwritten;
    ptr   += nwritten;
  }
  return(n);
}


int sockfd;
struct sockaddr_un servaddr;

void connect_socket()
{
  sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
  
  bzero(&servaddr, sizeof(servaddr));
 
  servaddr.sun_family = AF_LOCAL;
 
  strcpy(servaddr.sun_path, "/tmp/test_profile");
  
  connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
}



void * receiver(void * arg)
{
 for ( ; ; )
    {
      request_message.setBodySize(BUFFER_SIZE);
      
      msgid = ptr_server->receive(request_message); 

      writen(sockfd, request_message.getBodyAddr(), 
	     request_message.getBodySize());

      readn(sockfd, request_buffer, request_message.getBodySize());

#ifdef DEBUG
      received_string = static_cast<char*>(request_message.getBodyAddr());

      MESSAGE("Mensaje es %s :: %s", 
	      received_string, 
	      msgid.msgid_to_char(str));
#endif

      // reply_message.setBodySize(16);

      ptr_server->rpc_send_reply(request_message, msgid);
    }
}

int main()
{
  char stringPort[Port::stringSize];

  Ipc_MultiClient_Server server;
  
  connect_socket();
  
  printf("SERVER PORT %s\n", server.get_port().
	 getStringPort(stringPort, Port::stringSize));

  ptr_server = &server;

  pthread_t t;

  pthread_create(&t, NULL, receiver, NULL);

  pthread_join(t, NULL);

  return 0;
}
