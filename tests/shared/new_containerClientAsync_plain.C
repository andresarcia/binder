# include <pthread.h>
# include "ipcClient.H"
# include <aleph.H>

# define NUM_MESSAGES 1
# define BUFFER_SIZE 65535

pthread_cond_t wait_to_finish = PTHREAD_COND_INITIALIZER;
pthread_mutex_t my_lock = PTHREAD_MUTEX_INITIALIZER;
static Ipc_MultiClient_Server * ptr_client;

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

void * receive_thread (void * client)
{
  char msg_buffer[BUFFER_SIZE];
 
  RawMsg reply_msg(&msg_buffer[0], BUFFER_SIZE);

  for ( ; ; )
    {
      reply_msg.setBodySize(BUFFER_SIZE);

      ptr_client->receive(reply_msg);
      
      pthread_mutex_lock(&my_lock);
      pthread_cond_signal(&wait_to_finish);
      pthread_mutex_unlock(&my_lock);
	  
      MESSAGE("Recibi: %s", static_cast<char*>(reply_msg.getBodyAddr()));
    }
  
  return NULL;
}

#define MIN_MSG_SIZE 128


int main(int argc, char* argv[])
{
  Bootstrapper::bootstrap();
 
  //Here you define the ip address and the containerId.
  Port port(argv[1]);
   
  Ipc_MultiClient_Server client;
  
  ptr_client=&client;

  int n_msgs = atoi(argv[2]);
  
  int msg_length = atoi(argv[3]);

  MsgId msgid_sent;
  
  pthread_t ptr_receive_th;
  
  pthread_create(&ptr_receive_th, NULL, receive_thread, NULL);

  char msg_buffer[BUFFER_SIZE];

  // sending the port by which the server will respond to the client.
  //  char stringPort[Port::stringSize];
  
  RawMsg message(&msg_buffer[0], msg_length);

  msg_buffer[msg_length - 1] = '\0'; 
  for (int j=0; j<=msg_length-2; j++)
    msg_buffer[j] = get_rand(65,91);

  cout << n_msgs << " " << msg_length << endl;

  for(int i = 0; i < n_msgs; i++)
    {
      msgid_sent = client.rpc_send_request(port, message);	
      pthread_cond_wait(&wait_to_finish, &my_lock);
    }
  
  pthread_mutex_unlock(&my_lock);

  return 0;
}








