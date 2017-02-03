
# include <iostream>
#include "ipcClient.H"

int main()
{
  char request_buffer[81];
  RawMsg request_message(&request_buffer[0], 81);

  char reply_buffer[81];
  RawMsg reply_message(&reply_buffer[0], 81);

  char stringPort[Port::stringSize];

  MsgId msgid;

  char * received_string;

  IpcServer server;
  printf("SERVER PORT %s\n", 
	 server.getServerPort().getStringPort(stringPort, 
					      Port::stringSize
					      )
	 );
  char str[80];

  for (int i = 0; true; i++)
    {
      msgid = server.receive_request(request_message); 

      received_string = static_cast<char*>(request_message.getBodyAddr());

      cout << "Mensaje es \"" << received_string << "\" (" 
	   << msgid.msgid_to_char(str) << endl; 

      sprintf(reply_buffer, "Reply %i", i);

      reply_message.setBodySize(strlen(reply_buffer) + 1);

      server.send_reply(reply_message, msgid);
    }
	
  //shutDownClientIpcSystem();
  return 0;
}
