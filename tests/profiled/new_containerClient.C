
# include <unistd.h>
# include <iostream>
# include "ipcClient.H"
# include <now.h>
# include <cycles.h>
# include <math.h>

# define NUM_MESSAGES 1000
# define MIN_MSG_SIZE 16
# define BUFFER_SIZE 65536


int get_rand(int min_number, int max_number)
{
  ASSERT((max_number - min_number) >= 0);

  if (max_number == min_number)
    return max_number;

  max_number = max_number - min_number + 1;

  int ret_val = min_number;
  
  float value = static_cast<float>(max_number)*rand()/(RAND_MAX+1.0);
  
  ret_val += static_cast<int>(value);
  
  ASSERT(ret_val >= min_number && ret_val <= (min_number + max_number - 1));

  return ret_val; 
}


void clock_tuning(IpcRemoteClient * client)
{
  double elapsed_time, start_time, acc=0;

  char buffer[16];
  strcpy(buffer, "XXXXXXXXXXXXXXX");
  RawMsg calibrate_message(&buffer[0], 16);

  // CALCULATING CLOCK SPEED
# define SAMPLE_LENGTH 100

  for (int i = 0; i < SAMPLE_LENGTH; i++)
    {
      start_time = now();

      client->send_request(calibrate_message);	
      calibrate_message.setBodySize(16);
      client->receive_reply(calibrate_message);

      elapsed_time = now_delta(&start_time);
      acc += elapsed_time;
    }

  cycles_per_second(acc, SAMPLE_LENGTH);
}


int main(int argc, char* argv[])
{
  //  char a[Uid::stringSize];

  // USAGE: new_containerClient <target port> <# messages> <message size>

  //Here you define the ip address and the containerId.
  if (argc == 1)
    {
      cout << "USAGE: new_containerClient <target port> <# messages>" <<
	" <message size>" << endl;
      exit(0);
    }

  Port port(argv[1]);
  
  IpcRemoteClient client(port);

  int n_msgs = argc >= 3 ? atoi(argv[2]) : NUM_MESSAGES;

  int msg_length = (argc == 4) ?  atoi(argv[3]) : MIN_MSG_SIZE;

  if (msg_length > BUFFER_SIZE-1)
    {
      cout << "Length error!" << endl;
      exit(0);
    }

  MsgId msgid_sent;

  cout << "Message size: " << msg_length << endl;
  cout << "Number of messages: " << n_msgs << endl;

  long long start_cycle, end_cycle;
  double elapsed_time, start_time;
  double acc = 0;

  clock_tuning(&client);

  char msg_buffer[BUFFER_SIZE];

  RawMsg message(&msg_buffer[0], msg_length);

  MESSAGE("message.getBodySize()=%d", message.getBodySize());

  fill(msg_buffer, &msg_buffer[msg_length - 2], 'X');
  msg_buffer[msg_length - 1] = '\0';    

  double min = 0, max = 0;
  acc = 0;

  FILE * output_file;
  output_file = fopen("data.out","w");

  // MEASURING SEND-MESSAGE DELAY
  for(int i = 0; i < n_msgs; i++)
    {
      fill(msg_buffer, &msg_buffer[msg_length - 2], get_rand(65,91));
      msg_buffer[msg_length - 1] = '\0';

      start_cycle = cycles();
      
      msgid_sent = client.send_request(message);	

      message.setBodySize(BUFFER_SIZE);
      client.receive_reply(message);
      
      end_cycle = cycles();
      elapsed_time = cycles_diff(start_cycle, end_cycle);

      if (i==0) min = elapsed_time;
      else
	if (elapsed_time < min) 
	  min = elapsed_time;

      if (elapsed_time > max)
	max = elapsed_time;

      fprintf(output_file, "%f\n",elapsed_time);

      acc += elapsed_time;

      MESSAGE("Recibi: %s",(char*) message.getBodyAddr());
    }

  fclose(output_file);

  output_file = fopen("data.out","r");
  
  double dev = 0;

  while(!feof(output_file))
    {
      fscanf(output_file, "%lf",  &elapsed_time);
      dev+=pow(elapsed_time - acc/n_msgs, 2); // (Xi - Xmed)^2
    }

  dev/=n_msgs-1; //n-1

  printf("*** Cliente que utiliza el IPC y sin dispatcher ***\n");
  printf("tiempo total en seg: %f\n", acc);
  printf("minimo tiempo: %f\n", min);
  printf("maximo tiempo: %f\n", max);
  printf("desviacion estandar: %f\n", sqrt(dev));

  return 0;
}
