# include <pthread.h>
# include "ipcClient.H"
# include <aleph.H>
# include <now.h>
# include <cycles.h>
# include <math.h>
# define NUM_MESSAGES 1
# define BUFFER_SIZE 65535

FILE * output_file;
int my_n = 0, counter = 0;
bool real_measure = false;
long long cycles = 0, start_cycle, end_cycle;
double elapsed_time, start_time;
double acc = 0;
double sqrXi = 0;  


double mmin = 0, mmax = 0;
pthread_cond_t wait_to_finish = PTHREAD_COND_INITIALIZER;
pthread_mutex_t my_lock = PTHREAD_MUTEX_INITIALIZER;

Ipc_MultiClient_Server * ptr_client;

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
      elapsed_time = now_delta(&start_time);
      end_cycle = cycles();
      
      if (!real_measure)
	{
	  acc += elapsed_time;
	  pthread_cond_signal(&wait_to_finish);
	}
      else
	{
	  double elapsed_time_2 = cycles_diff(start_cycle, end_cycle);

	  sqrXi += elapsed_time_2*elapsed_time_2;

	  pthread_mutex_lock(&my_lock);
	  pthread_cond_signal(&wait_to_finish);
	  pthread_mutex_unlock(&my_lock);
	  
	  acc+=elapsed_time_2;
	  
	  if (counter==0) mmin = elapsed_time_2;
	  else
	    if (elapsed_time_2 < mmin) 
	      mmin = elapsed_time_2;
	  
	  if (elapsed_time_2 > mmax)
	    mmax = elapsed_time_2;
	  
	  //fprintf(output_file, "%lf ",elapsed_time_2);
	}
      
      if (real_measure) counter++;
      
      if (counter == my_n)
	pthread_cond_signal(&wait_to_finish);
      
      MESSAGE("Recibi: %s", static_cast<char*>(reply_msg.getBodyAddr()));
    }
  
  return NULL;
}


# define REPLY_SIZE 16

int main(int argv, char* argc[])
{
  Bootstrapper::bootstrap();
 
  //Here you define the ip address and the containerId.
  Port port(argc[1]);
   
  Ipc_MultiClient_Server client;
  
  ptr_client=&client;

  int n_msgs = atoi(argc[2]);

  int msg_size = atoi(argc[3]);

  MsgId msgid_sent;
  
  pthread_t ptr_receive_th;
  pthread_create(&ptr_receive_th, NULL, receive_thread, &client);

  // sending the port by which the server will respond to the client.
  char stringPort[Port::stringSize];
  
  char msg_buffer[BUFFER_SIZE];
  RawMsg reply_msg(&msg_buffer[0], msg_size);

  MESSAGE("msg_buffer.getBodySize()=%d", reply_msg.getBodySize());
 
  msg_buffer[msg_size - 1] = '\0'; 
  for (int j=0; j<=msg_size-2; j++)
    msg_buffer[j] = get_rand(65,91);
 
  cycles_per_second(1, 10);

  acc = 0;
  real_measure = true;
  //  output_file = fopen("data.out","w");

  for(int i = 0; i < n_msgs; i++)
    {
      MESSAGE("%s\n", msg_buffer);
      start_cycle = cycles();
      client.rpc_send_request(port, reply_msg);	
      pthread_cond_wait(&wait_to_finish, &my_lock);
    }
  
  pthread_mutex_unlock(&my_lock);

  //  fclose(output_file);
  //  output_file = fopen("data.out","r");
  
  double avg = acc/n_msgs;
  double dev = sqrXi - n_msgs*(avg*avg);
  
  dev/=n_msgs-1; //n-1

  //  while(!feof(output_file))
  // {
  //  fscanf(output_file, "%lf",  &elapsed_time);
  //  dev+=pow(elapsed_time - acc/n_msgs, 2); // (Xi - Xmed)^2
  //}
  
  printf("%5i \t %5i \t %f \t %f \t %f \t %f\n", 
	 n_msgs, msg_size, avg, mmin, mmax, sqrt(dev));
  //printf("Cliente con IPC, y NO dispatcher (Ipc_Multiclient_Server)\n");
  //printf("Mensajes: %i, Tama#o: %i",n_msgs, msg_size); 
  //printf("tiempo promedio en useg %f\n", avg);
  //printf("minimo tiempo %f\n", mmin);
  //printf("maximo tiempo %f\n", mmax);
  //printf("desviacion estandar %f\n\n", sqrt(dev));

  //  pthread_join(ptr_receive_th, NULL);

  return 0;
}





