# include "client_binding.H"
# include <pthread.H>

pthread_mutex_t Local_Binding::free_mutex = PTHREAD_MUTEX_INITIALIZER;

