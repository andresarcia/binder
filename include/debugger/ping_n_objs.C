# include "locator_calls.H"
# include "port.H"

int main(int argc, char ** argv)
{
  if (argc != 3)
    {
      cout << "usage: ping_n_objs <# objects> <LRU | MRU | MIDDLE>" << endl;
      exit(0);
    }
  
  bootstrap_services();
  
  unsigned number_of_objects = atoi(argv[1]);
  
  try
    {
      if (strcmp(argv[2], "LRU") == 0)
	ping(number_of_objects, LOCCACHE_LRU);
      else
	if (strcmp(argv[2], "MRU") == 0)
	  ping(number_of_objects, LOCCACHE_MRU);
	else
	  if (strcmp(argv[2], "MIDDLE") == 0)
	    ping(number_of_objects, LOCCACHE_MIDDLE);
	  else
	    ERROR("Policy argument must be one of these: (LRU, MRU or MIDDLE)");
    }
  catch (NotFound)
    {
      MESSAGE("There were no cache entries to ping");
    }
	 
  return 0;
}


