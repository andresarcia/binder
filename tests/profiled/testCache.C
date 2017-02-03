# include <iostream>
# include <aleph.H>
//# include <tpl_cache.H>
//#include "my_tpl_cache.H" 
#include "protected_cache.H"

static unsigned long hashFct(const unsigned &i)
{
  return i;
}

class Empty_Class 
{
  // empty
  //public:
  

};

bool operator == (const Empty_Class & lho,
		  const Empty_Class & rho)
{
  return true;
}
  
int main(int argn, char *argc[])
{
  Bootstrapper::bootstrap();

  int n = 16;
  unsigned int t = time(0);

  if (argn > 1)
    n = atoi(argc[1]);

  if (argn > 2)
    t = atoi(argc[2]);

  srand(t);

  cout << "testCache " << n << " " << t << endl;

  Protected_Cache<unsigned,int> cache(&hashFct, n);

  Empty_Class empty_object;

  int i;
  for (i = 0; i < n; i++)
    {
      cache.insert(i, i);
      //cache.insert(i, empty_object);
    }

  int value;
  for (i = 0; i < n; i++)
    {
      //key =(int) (1.0*n*rand()/(RAND_MAX+1.0));
      value = cache.find_data_ref(i);
      cache.cache_unlock();

      // empty_object = cache.find_data_ref(i);

      ASSERT(value == i);
    }

  ASSERT(cache.verify_cache());

  cache.expand(n/2);
//  n += n/2;

  for (i = n; i < 2*n; i++)
    {
      //      cache.insert(i, i);
       cache.insert((i%2)+1, i);
      //cache.insert((i%2)+1, empty_object);
    }
  /*  
  for (i = 2*n-1; i >=n ; i--)
    {
        try
  	{
	  key =(int) (1.0*n*rand()/(RAND_MAX+1.0));
	  value = cache.find_data_ref(key);

	  cout << "valor " << key << " encontrado con " << value << endl;

	  ASSERT(value == key);
  	}
            catch (NotFound)
	{
	  cout << "valor " << key << " no encontrado" << endl;
	}
      
    }
  */

  cache.print_list();

  ASSERT(cache.verify_cache());

  /*
  for (i = n; i < 2*n; i+=2)
    {
      try{
      cache.remove(i);
      } 
       catch (NotFound)
	{
	  cout << "valor " << i << " no encontrado" << endl;
	}
    }
  */  
  cache.print_list();
  
  // int e=n;

   /*
     try
     {
     cache.remove(e);
     } 
     catch (NotFound)
     {
     cout << "valor " << e << " no encontrado" << endl;
     }
   */
  
  unsigned par=1;
  {  
    Protected_Cache<unsigned,int>::Protected_Cache_Iterator 
      iter(&cache, par);
    
    int * pint = iter.get_current();
    //Empty_Class * pint = iter.get_current();

    cout << "Number of entries: " << iter.count() << endl;
    
    do
      {
	int elem = *iter.get_current();
	//Empty_Class elem = *iter.get_current();
	cout << "(" << par << "," << elem << ")" << endl;
      } while (iter.delete_current() != NULL);
    // while (iter.get_next() != pint);
  }

  {  
    Protected_Cache<unsigned,int>::Protected_Cache_Iterator 
      iter(&cache, par);
  }
  //  cache.insert(par, par);
}
