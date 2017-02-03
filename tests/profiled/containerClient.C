
# include <unistd.h>
# include <iostream>
# include "ipcClient.H"

# define NUM_MESSAGES 1

int main(int argv, char* argc[])
{
  char a[Uid::stringSize];

  //Here you define the ip address and the containerId.
  Port port(argc[1]);

  char buffer[81];
  RawMsg message(&buffer[0], 81);

  MESSAGE( ("message.getBodySize()=%d", message.getBodySize()));

  IpcRemoteClient client(port);

  int num_messages = argv == 3 ? atoi(argc[2]) : NUM_MESSAGES;

  for(int i = 0; i < num_messages; i++)
    {
      sprintf(buffer, "Send Mensaje %d", i);
      cout << buffer << endl;
      //      message.setBodySize(strlen(buffer) + 1);

      client.send_request(message);	

      char msg_buffer[81];
      msg_buffer[80] = '\0';
      RawMsg reply_msg(&msg_buffer[0], 81);

      client.receive_reply(reply_msg);

      cout << "Recibi: \"" << (char*) reply_msg.getBodyAddr() << endl;
      cout << static_cast<char*>(reply_msg.getBodyAddr()) << endl;
    }

  Uid uid;

  createUid(&uid);

  return 0;
}
