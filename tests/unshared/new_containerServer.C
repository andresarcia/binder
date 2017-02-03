# include <iostream>
# include "ipcClient.H"


# define BUFFER_SIZE 65536

MsgId msgid;

char * received_string;

char str[80];

char * reply_buffer = "XXXXXXXXXXXXXXX";

RawMsg reply_message(&reply_buffer[0], 16);

IpcServer * ptr_server;

char request_buffer[BUFFER_SIZE];
RawMsg request_message(&request_buffer[0], BUFFER_SIZE);


void * receiver(void * arg)
{
 for (int i = 0; true; i++)
    {
      request_message.setBodySize(BUFFER_SIZE);
      
      msgid = ptr_server->receive_request(request_message); 

      received_string = static_cast<char*>(request_message.getBodyAddr());

      MESSAGE("Mensaje es %s :: %s", received_string, msgid.msgid_to_char(str));

      //reply_message.setBodySize(strlen(reply_buffer) + 1);
      
      ptr_server->send_reply(request_message, msgid);
    }
}

int main()
{
  char stringPort[Port::stringSize];

  IpcServer server;

  printf("SERVER PORT %s\n",server.getServerPort().
	 getStringPort(stringPort,Port::stringSize));

  ptr_server = &server;

  pthread_t t;

  pthread_create(&t, NULL, receiver, NULL);

  pthread_join(t, NULL);

  return 0;
}
