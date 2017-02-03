# ifndef TPL_PROTECTED_CACHE_H
# define TPL_PROTECTED_CACHE_H

# include "tpl_cache.H"
# include "useMutex.H"
# include <pthread.h>

template <class Key, class Data>
class Protected_Cache : protected Cache<Key, Data>
{
  pthread_mutex_t cache_lock;

  void lock_cache()
  {
#ifdef DEBUG
    if (pthread_mutex_trylock(&cache_lock) == EBUSY)
      {
	MESSAGE("The LOCK of the cache is already taken");
	pthread_mutex_lock(&cache_lock);
	MESSAGE("LOCK released and taken again");
      }
#else
    pthread_mutex_lock(&cache_lock);
#endif
  }

  Dlink & get_head_lru(Protected_Cache<Key,Data> * ptr_cache)
  {
    return ptr_cache->head_lru;
  }

public:
  
  Protected_Cache(unsigned long (*hash_fct)(const Key&), 
		  size_t          size,
		  GenAlloc&       _alloc = *objectAlloc) : 
    Cache<Key,Data>(hash_fct, size, _alloc)
  {
    pthread_mutex_init(&cache_lock, NULL);
  }

  friend class Protected_Cache_Iterator : 
    public Cache<Key,Data>::Cache_Iterator
  {
    UseMutex use_mutex;
    
    GenAlloc & local_alloc;

  public:
    Protected_Cache_Iterator(Protected_Cache<Key,Data> * _ptr_cache, 
			     const Key & key) 
      throw (std::exception, NotFound) :
      Cache<Key,Data>::Cache_Iterator(_ptr_cache, key),
      CTOR_USE_MUTEX(use_mutex, 
                     (&static_cast<Protected_Cache<Key,Data> *>
		      (ptr_cache)->cache_lock)),
      local_alloc(_ptr_cache->alloc)
    {
      // empty
    } 

    virtual ~Protected_Cache_Iterator()
    {
      // empty
    }
  };

  
  friend class Protected_Policy_Iterator
  {
    UseMutex use_mutex;

    Protected_Cache<Key,Data> * ptr_cache;

    unsigned int number_of_objects;

    unsigned int entry_number;

    Cache_Entry * current_entry;
    
  public:
    Protected_Policy_Iterator(Protected_Cache<Key,Data> * _ptr_cache,
			      unsigned int _n_objects,
			      Cache_Update_Policy _policy)
      throw (std::exception, NotFound) :
      CTOR_USE_MUTEX
      (use_mutex,
       (&static_cast<Protected_Cache<Key,Data> *>(_ptr_cache)->cache_lock)),
      ptr_cache(_ptr_cache),
      number_of_objects(_n_objects),
      entry_number(0)
    {
      unsigned number_of_steps = 0;
      
      current_entry = ptr_cache->
	dlink_to_cache_entry((ptr_cache->get_head_lru(ptr_cache)).getNext());
      
      if (number_of_objects <= ptr_cache->get_num_items())
	number_of_steps = 0;
      else
	switch (_policy)
	  {
	  case LOCCACHE_LRU :
	    number_of_steps = ptr_cache->get_num_items() - number_of_objects;
	    break;
	  case LOCCACHE_MRU :
	    number_of_steps = 0;	    
	    break;
	  case LOCCACHE_MIDDLE :
	    number_of_steps = (ptr_cache->get_num_items()-number_of_objects)/2;
	    break;
	  default:
	    ERROR("Bad cache policy!");
	  }

      for (unsigned int entry_counter = 0; 
	   entry_counter < number_of_steps; 
	   entry_counter ++)
	current_entry = ptr_cache->
	  dlink_to_cache_entry(current_entry->link()->getNext());
      
    } 
    
    void move_next()
    {
      if (entry_number < number_of_objects &&
	  entry_number < ptr_cache->get_num_items())
	{
	  current_entry = ptr_cache->
	    dlink_to_cache_entry(current_entry->link()->getNext());
	  entry_number++;
	}
    }
    
    Data * get_current()
    {
      if (entry_number == number_of_objects ||
	  entry_number == ptr_cache->get_num_items())
	return NULL;
      else
	return &current_entry->getData();
    }
    
    virtual ~Protected_Policy_Iterator()
    {
      // empty
    }
  };



  void insert(const Key& key, const Data& data)
  {
    CRITICAL_SECTION(&cache_lock);
    Cache<Key,Data>::insert(key, data);
  }

  Data* find_data_ptr(const Key &key)
  {
    lock_cache();
    return Cache<Key,Data>::find_data_ptr(key);
  }

  Data& find_data_ref(const Key &key) throw (std::exception, NotFound)
  {
    lock_cache();
    return Cache<Key,Data>::find_data_ref(key); 
  }

  // Once the finding functions are used, the cache must be unlocked
  void cache_unlock()
  {
    pthread_mutex_unlock(&cache_lock);
  }

  void remove(const Key &key) throw (std::exception, NotFound)
  {
    CRITICAL_SECTION(&cache_lock);
    try
      {
	Cache<Key,Data>::remove(key);
      }
    catch (NotFound)
      {
	cache_unlock();
	Throw (NotFound)(); 
      }
  }
  
  void expand(size_t plus_size) 
    throw(std::exception, SizeFault, Nomem)
  {
    CRITICAL_SECTION(&cache_lock);
    Cache<Key,Data>::expand(plus_size);
  }
  
  size_t get_size() const
  {
    return Cache<Key,Data>::get_size();
  }

  size_t get_num_items() const
  {
    return Cache<Key,Data>::get_num_items();
  }

#ifdef DEBUG

  bool verify_cache()
  {
    return Cache<Key,Data>::verify_cache();
  }

  void print_list()
  {
    Cache<Key,Data>::print_list();
  }

#endif

  virtual ~Protected_Cache()
  {
    pthread_mutex_destroy(&cache_lock);
  }
};

# endif  // TPL_PROTECTED_CACHE_H


