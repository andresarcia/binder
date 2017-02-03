# include <pthread.h>
# include "signal.H"
# include "locator_boot.H"
# include "locator_pars.H"
# include "local_reception_point.H"
# include "locator_local_services.H"
# include "locator_remote_services.H"

pthread_t main_thread_id;

void sig_term(int signo)
{
  if (pthread_self() == main_thread_id)
    {
      MESSAGE("*** Shutting down the Locator Daemon!");
      shutdown_locator();
    }
}

int main(int argc, char * argv[])
{
  parameters_decode(argc, argv);

  locator_is_shutdown = false;

  main_thread_id = pthread_self();

  // This is the locator bootstraping (data structures initialization).
  locator_bootstrap();

  //TODO: verify if should be ommited now. 4/10/2002
  //TODO: Bootstrapper::bootstrap();

  Signal signalHandler(SIGTERM, sig_term);
  
  local_server_id = bootstrap_local_services();

  Port broadcast_port;

  // Initialize Locator_Remote_Services
  if (attach_to_broadcast_group)
    {
      FILE * broad_port_file = fopen(Default_Broadcast_Port_Path, "r");
      
      char str_broadcast_port[Port::stringSize + 1];
      
      fscanf(broad_port_file, "%s", str_broadcast_port);
      
      broadcast_port = Port(str_broadcast_port);
      
      fclose(broad_port_file);
    }
  
  static Locator_Remote_Services remote_services(broadcast_port,
						 attach_to_broadcast_group); 

  remote_server_id = &remote_services;

  pthread_t *local_front_thread;
  
  local_front_thread = local_server_id -> start_deamon();

  // pthread_join is necesary so that acquired resources are freed.
  // It also works for making the deamon run in the thread of reception_point,
  // which waits on a select system call (it makes the process idle when idle).

  pthread_join(*local_front_thread, NULL);
  
  remote_services.join_remote_services();

  return 0;
}

