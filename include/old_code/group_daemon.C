# include "protected_lhash.H"
# include "remote_multiserver_point.H"
# include "group_message_header.H"
# include "group_daemon.H"

Group_Daemon * ptr_group_daemon;

pthread_t main_thread_id;

void sig_term(int signo)
{
  if (pthread_self() == main_thread_id)
    {
      MESSAGE("Main Thread got SIGTERM");
      ptr_group_daemon->shutdown_group_daemon();
    }
}

int main()
{
  main_thread_id = pthread_self();

  Group_Daemon group_daemon;
  
  ptr_group_daemon = &group_daemon;

  Signal signalHandler(SIGTERM, sig_term);

  group_daemon.join_group_daemon();

  return 0;
}

# undef DEFAULT_TABLE_SIZE





