# include <iostream>
#include "ipcClient.H"

MsgId msgid;

# define BUFFER_SIZE 65535

char * received_string;

char str[80];

Ipc_MultiClient_Server * ptr_server;

char request_buffer[BUFFER_SIZE];

RawMsg request_message(&request_buffer[0], BUFFER_SIZE);


void * receiver(void * arg)
{
 for ( ; ; )
    {
      request_message.setBodySize(BUFFER_SIZE);
      
      msgid = ptr_server->receive(request_message); 

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
  
  printf("SERVER PORT %s\n", server.get_port().
	 getStringPort(stringPort, Port::stringSize));

  ptr_server = &server;

  pthread_t t;

  pthread_create(&t, NULL, receiver, NULL);

  pthread_join(t, NULL);

  return 0;
}
