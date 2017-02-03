# include <aleph.H>
# include "locator_calls.H"
# include "port.H"
# include <now.h>
# include <cycles.h>
# include <math.h>


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


int main(int argc, char ** argv)
{ 
  if (argc == 1)
    {
      cout << "usage: client_prof <Site_Id> <Obj_Id> <#invocations> <invocation_size>" << endl;
      exit(0);
    }

  bootstrap_services();

  Object_Id rem_obj(argv[2]);
  
  int n_times = atoi(argv[3]);
  
  // Especification of local data.  
  Site_Id   rem_site(argv[1]), this_site(INVALID_SITE_ID);
  get_site_id(this_site);

  Locator remote_object_loc(rem_obj, rem_site);

  Container_Id this_container;

  register_cnt(this_container);

  char strtmp[Uid::stringSize];

  MESSAGE("Container ID: %s", this_container.getStringUid(strtmp,
							   Uid::stringSize));

  Binding binding(remote_object_loc, this_container, this_site);
  
  //  size_t request_size = 13;

  Message_Id msg_id;

  Reception_Type reception_type;

  size_t invocation_size = atoi(argv[4]);

  size_t reply_size;

  char * invocation = new char [invocation_size];

  char * reply = new char [invocation_size];

  invocation[invocation_size - 1] = '\0'; 

  for (int j=0; j<=invocation_size-2; j++)
    invocation[j] = get_rand(65,91);
  
  double elapsed_time, start_time, acc=0, sqrXi=0;

  cycles_per_second(1, 10);
  
  long long start_cycle, end_cycle;
  double min = 0, max = 0;
  acc = 0;

  //  FILE * output_file;
  //  output_file = fopen("data.out","w");
 
  for (int i=0; i < n_times; i++)
    { 
      start_cycle = cycles();
      msg_id = clt_invoke_send(binding, invocation, invocation_size);

      msg_id = multi_receive(binding, this_container, reply, reply_size,
			     reception_type);
      end_cycle = cycles();

      elapsed_time = cycles_diff(start_cycle, end_cycle);
      
      if (i==0) min = elapsed_time;
      else
	if (elapsed_time < min) 
	  min = elapsed_time;
      
      if (elapsed_time > max)
	max = elapsed_time;
      
      //      fprintf(output_file, "%f\n",elapsed_time);
      
      acc += elapsed_time;
      sqrXi += elapsed_time*elapsed_time;

      ASSERT(reply_size == invocation_size); // doing an echo

      MESSAGE("Response for invocation: %s", reply);
    }  

  unregister_cnt(this_container);

  //  fclose(output_file);
  
  //output_file = fopen("data.out","r");

  double avg = acc/n_times;
  double dev = sqrXi - n_times*(avg*avg);
  dev/=n_times-1; //n-1
  
  //while(!feof(output_file))
  // {
  //   fscanf(output_file, "%lf",  &elapsed_time);
  //   dev+=pow(elapsed_time - acc/n_times, 2); // (Xi - Xmed)^2
  // }

  //  printf("Con localizador:");
  printf("%5i \t %5i \t %f \t %f \t %f \t %f\n", n_times, invocation_size, avg, min, max, sqrt(dev));
  //  printf("Tiempo promedio en useg: %f\n", avg);
  //printf("Minimo tiempo: %f\n", min);
  //printf("Maximo tiempo: %f\n", max);
  //printf("Desviacion estandar: %f\n\n", sqrt(dev));

  delete [] invocation;

  return 0;
}
