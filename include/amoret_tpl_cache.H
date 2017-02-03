# ifndef TPL_CACHE_H
# define TPL_CACHE_H

#include <aleph.H>
#include <tpl_dnode.H>
#include <tpl_lhash.H>


# ifdef New
# define OLDNEW New
# define OLDDELETE Delete
# undef New
# undef Delete
# endif


template <class Key, class Data> 
class Cache
{
protected:

  friend class Cache_Entry : private LhashTable<Key>::Bucket
  { 
    friend class Cache<Key, Data>;

  private:
    Data   data;  // associated data
    Dlink  dlink; // lru link 

#   ifdef DEBUG    
    long long age_counter;
    static long long global_age_counter;

  public:

    /* Verify age_counter of "this" to be less than the previous node's
       age_counter. This policy stablishes the sense of LRU. If we were to
       have a centinel node as a list's head, then the head's previous node
       is the LRU and of course the head's next node is mean to be the MRU.  */
    bool verify_age_counter() 
    {
      Cache_Entry *previous_cache_entry = 
	dlink_to_cache_entry(dlink.getPrev());

      return age_counter < previous_cache_entry->age_counter;
    }

    /* touche (increments) age_counter */
    void touch_age_counter()
    {
      age_counter = global_age_counter++;
    }

  private:
#   else  /* DEBUG */

#   define verify_age_counter()
#   define touch_age_counter()

#   endif /* DEBUG */
         
  public:

    Cache_Entry(const Key& k, const Data& d) 
      : LhashTable<Key>::Bucket(k), data(d)
    {
# ifdef DEBUG
      touch_age_counter();
# endif
    }
    
    Cache_Entry() 
    {
# ifdef DEBUG
      touch_age_counter();
# endif
    }

    Data& getData() 
    { 
      return data; 
    }

    Dlink* link() { return &dlink; }
  };

  /* Least recently used queue.

     For Each access in cache:

         head_lru.getNext() is the most recently used
	 head_lru.getPrev() is the least recently used

     Thus, for any referenced entry

         entry->del();
	 head_lru.insert(entry); *** MUST BE DONE ALWAYS! ***
  */	 
  Dlink head_lru;

  /* hash table for fast searching.

     hash_table.getNumEntries() gets current number of entries
     inserted in the cache 

  */
  LhashTable<Key> hash_table;

  unsigned long cache_size;  // maximum number of entries in the cache 

  typedef Dnode<Cache_Entry*> Chunk_Descriptor;

  /* List of chunks 

     This is a list of chunks of memory. Each one is added to the list
     while requiered during the cache lifetime.

     A chunk of memory has the interesting property of being continuous
     in memory, therefore can be cached by the computer. 
   	
  */
  Chunk_Descriptor chunk_list;

protected:  
  /// Allocator for the array. It is used at construction and resizing time
  GenAlloc&   alloc; 

  static Cache_Entry* dlink_to_cache_entry(Dlink * p)
  {
    Cache_Entry*  zero_pointer = 0;

    int offset_dlink = reinterpret_cast<int>(zero_pointer->link());

    int cache_entry_address = reinterpret_cast<int>(p) - offset_dlink;

    return reinterpret_cast<Cache_Entry*>(cache_entry_address);
  }

  void move_to_lru_front(Cache_Entry* cache_entry)
  {
    cache_entry->link()->del();
    head_lru.insert(cache_entry->link());
# ifdef DEBUG
    cache_entry->touch_age_counter();
# endif
  }

  void remove_entry(Cache_Entry* cache_entry)
  {
    hash_table.remove(cache_entry);
  
    /* This entry needs to be urgently reused. Thus, it is convenient
       to move it to the end of the LRU list */  

    cache_entry->link()->del();
    
    head_lru.append(cache_entry->link()); 
  }

  /* 
     getEntry gets the LRU entry in the pool of CacheEntries
     then moves it to the front of the LRU list (now being the MRU).
  */ 
  Cache_Entry* get_lru_entry()
  {
    ASSERT(hash_table.get_num_items() <= cache_size);

    Dlink *lru_entry_link = head_lru.getPrev();
    Cache_Entry * cache_entry = dlink_to_cache_entry(lru_entry_link);

    move_to_lru_front(cache_entry);

    /* The Hash Table is full, and I'm needing space to insert a new
       cache_entry */
    if (hash_table.get_num_items() == cache_size) 
      hash_table.remove(cache_entry);
	  
    return cache_entry;
  }

# ifdef DEBUG
  bool verify_age_counter(Cache_Entry * cache_entry)
  {
    Cache_Entry * next_cache_entry;
    if (cache_entry->link() != head_lru.getPrev())
      { 
	next_cache_entry = 
	  dlink_to_cache_entry(cache_entry->link()->getNext());
	if (cache_entry->age_counter <= next_cache_entry->age_counter)
	  return false;
      }

    if (cache_entry->link() == head_lru.getNext())
      return true;

    Cache_Entry * prev_cache_entry = 
      dlink_to_cache_entry(cache_entry->link()->getPrev());

    if (cache_entry->age_counter >= prev_cache_entry->age_counter)
      return false;
    else
      return true; 
  }
# else
# define verify_age_counter(x) true 
  //#  void verify_age_counter(x) {}
# endif


  Cache_Entry * find_cache_entry(const Key &key)
  {
    ASSERT(hash_table.get_num_items() <= cache_size);
    
    Cache_Entry *cache_entry = 
      static_cast<Cache_Entry*>(hash_table.search(key));
    
    if (cache_entry != NULL)
      {
	ASSERT(verify_age_counter(cache_entry)); 
	move_to_lru_front(cache_entry);
      }
    
    return cache_entry;
  }
  
public:

  Cache(unsigned long (*hash_fct)(const Key&), 
	size_t          size,
	GenAlloc&       _alloc = *objectAlloc) : 
    hash_table(hash_fct, 
	       static_cast<unsigned int>(13*size/10), _alloc, false),
    cache_size(size),
    alloc(_alloc)
  {
    ASSERT(size > 1);
    ASSERT(hash_fct != NULL);

    Cache_Entry * entries_array = AllocNew(alloc, Cache_Entry) [cache_size];

    Chunk_Descriptor * chunk_descriptor;
    try 
      {
	chunk_descriptor = 
	  AllocNew (alloc, Chunk_Descriptor) (entries_array);
      }
    catch (...)
      {
	AllocDeleteArray(alloc, entries_array);
	throw;
      }

    /* the following line saves the chunk in the list for using in 
       memory deallocation at desturction time */
    chunk_list.insert(chunk_descriptor);

    /* insert each entry in LRU list. No matter if there are not
       inserted entries yet */
    for (unsigned j = 0; j < cache_size; j++)
      {
	head_lru.insert(entries_array[j].link());
      }
  }

  virtual ~Cache() 
  {
    ASSERT(hash_table.get_num_items() <= cache_size);

    Chunk_Descriptor * current_chunk;
	
    while (!chunk_list.isEmpty())
      {
	current_chunk = chunk_list.removeNext();
	AllocDeleteArray(alloc, current_chunk->getData());
	AllocDelete(alloc, current_chunk);
      }
  }      

  /*
    Finds an iterator 
   */
  friend class Cache_Iterator 
  {
  protected:
    Cache<Key, Data> * ptr_cache;

  private:
    enum Address 
    {
      FORWARD,
      BACKWARD,
      LAST
    };

    Cache_Entry * current_entry;

    Cache_Entry * head_entry;

    Cache_Entry * get_follows(Address addr)
    {
      LhashTable<Key>::Bucket * bucket = NULL;

      switch (addr)
	{
	case FORWARD :
	  bucket = ptr_cache->hash_table.
	    searchNext(static_cast<LhashTable<Key>::Bucket*>
		       (current_entry));
	  break;
	case BACKWARD :
	  bucket = ptr_cache->hash_table.
	    searchPrev(static_cast<LhashTable<Key>::Bucket*>
		       (current_entry));
	  break;
	default:
	  ERROR("Bad argument in get_follows");
	}
      
      // if it is not itself.
      if (static_cast<Cache_Entry *>(bucket) != current_entry)
	{
	  ptr_cache->move_to_lru_front(static_cast<Cache_Entry *>(bucket));
	  current_entry = static_cast<Cache_Entry *>(bucket);
	}
      
      return current_entry; 
    }

  public:
    Cache_Iterator(Cache<Key,Data> * _ptr_cache,
		   const Key & _wanted_key)
      throw (std::exception, NotFound) :
      ptr_cache(_ptr_cache)
    {
      current_entry = head_entry = ptr_cache->find_cache_entry(_wanted_key); 

      if (current_entry == NULL)
	Throw (NotFound) ();
    }

       /// Sets current to first element
    void reset_first()
      {
	current_entry = head_entry;	
      }

    /// Sets current to last element
    void reset_last()
      {
	current_entry = head_entry;

	current_entry = get_follows(BACKWARD);
      }

    unsigned count()
    {
      ASSERT(current_entry != NULL);
      Data * initial_ref = get_current();

      unsigned n = 1;

      while(initial_ref != get_next())
	n++;
      
      return n;
    }

    /// get current element
    Data * get_current() 
      {
	ASSERT(current_entry != NULL);
	
	ptr_cache->move_to_lru_front(current_entry);

	return &current_entry->getData();
      }

    /// Advances to previous element
    Data * get_prev()
      {
	Cache_Entry * entry = get_follows(BACKWARD);

	return &entry->getData(); 
      }

    /// Advances to next element
    Data * get_next()
      {
	Cache_Entry * entry = get_follows(FORWARD);

	return &entry->getData(); 
      }

    // Delete the current element. Return NULL when done and return
    // next element address when there are some left
    Data * delete_current()
    {
      Cache_Entry * entry_to_delete = current_entry;
      
      move_next();
      
      ptr_cache->remove_entry(entry_to_delete);
      
      if (current_entry == entry_to_delete)
	return NULL;
      else
	return &current_entry->getData();
    }

    void move_next()
    {
      get_follows(FORWARD);
    }

    void move_prev()
    {
      get_follows(BACKWARD);
    }
  };

  /* insert(key, data) insters a Cache_Entry type into the cache. It
     also manages the LRU policy and the reusability of the cache
     entries. */
  void insert(const Key& key, const Data& data)
  {
    ASSERT(hash_table.get_num_items() <= cache_size);
    // Now, duplicated keys are accepted
    // ASSERT(hash_table.search(key) == NULL);

    try
      {
	Cache_Iterator iter(this, key);
	
	Data * first_elem = iter.get_current();

	do 
	  {
	    if (data == *iter.get_current())
	      return;
	  } while (iter.get_next() != first_elem);
	
	Throw (NotFound)();
      }

    catch (NotFound)
      {
	Cache_Entry *cache_entry = get_lru_entry();
	
	cache_entry->getKey()  = key;
	cache_entry->getData() = data;
	
	hash_table.insert(cache_entry);
      }
  }


  /* Finds a key into the cache returning NULL in case of failure and 
     the data address if success. */   
  Data* find_data_ptr(const Key &key)
  {
    Cache_Entry *cache_entry = find_cache_entry(key); 
    
    if (cache_entry != NULL)
      return &cache_entry->getData();
    
    return NULL;
  }

  /* Finds a key into the cache, but managing exceptions. In case of failure
     a NotFount exception is thrown otherwise the data reference is
     returned. */    
  Data& find_data_ref(const Key &key) throw (std::exception, NotFound)
  {
    Data* data_ptr = find_data_ptr(key);

    if (data_ptr == NULL)
      Throw (NotFound) ();

    return *data_ptr;
  }

  /* Removes a Cache_Entry from the cache, so that it appears no
     more...  Although it sounds weard to erase a cache entry (if you
     look at the definition of a cache), in a specific implementation it
     actually was required. So we had to implement the following
     "remove(const Key &key)" */
  void remove(const Key &key) throw (std::exception, NotFound)
  {
    ASSERT(hash_table.get_num_items() <= cache_size);
      
    Cache_Entry *cache_entry = 
      static_cast<Cache_Entry*>(hash_table.search(key));
      
    if (cache_entry == NULL)
      Throw (NotFound) ();

    hash_table.remove(cache_entry);
  
    /* This entry needs to be urgently reused. Thus, it is convenient
       to move it to the end of the LRU list */  
    cache_entry->link()->del();
    head_lru.append(cache_entry->link()); 
  }

  /* Expands the cache in plus_size items, also calculates the new hash_table
     size which still follows the principle 1.3 * new_cache_size. */
  void expand(size_t plus_size) 
    throw(std::exception, SizeFault, Nomem)
  {
    ASSERT(hash_table.get_num_items() <= cache_size);

    if (plus_size == 0)
      Throw (SizeFault) (plus_size);

    unsigned long new_cache_size = cache_size + plus_size;

    Cache_Entry * entries_array = AllocNew(alloc, Cache_Entry) [plus_size];

    Chunk_Descriptor * chunk_descriptor;
    try
      {
	chunk_descriptor = 
	  AllocNew (alloc, Chunk_Descriptor) (entries_array);
      }
    catch (...)
      {
	AllocDeleteArray(alloc, entries_array);
	throw;
      }

    try
      {
	ID(unsigned long old_num_items = hash_table.get_num_items());

	hash_table.resize(13*(new_cache_size)/10);

	ASSERT(old_num_items == hash_table.get_num_items());
      }
    catch (...)
      {
	AllocDeleteArray(alloc, entries_array);
	AllocDelete(alloc, chunk_descriptor);
	throw;
      }

#ifdef DEBUG
    ID(long long min_age_counter 
       = dlink_to_cache_entry(head_lru.getPrev())->age_counter);
# endif

    for (unsigned j = 0; j < (plus_size); j++)
      {
	head_lru.append(entries_array[j].link());
# ifdef DEBUG
	IS(entries_array[j].age_counter = --min_age_counter);
# endif
      }
           
    chunk_list.insert(chunk_descriptor);

    cache_size = new_cache_size;
  }

  size_t get_size() const
  {
    return cache_size;
  }

  size_t get_num_items() const { return hash_table.get_num_items(); }

# ifdef DEBUG

  /* Verify the cache integrity. It checks for the LRU condition through
     verify_age_counter for each Cache_Entry; returns false in case of an
     inconsistency. */

  bool verify_cache()
  {
    Cache_Entry * cache_entry;
      
    Dlink *current_link = head_lru.getNext();
    while (current_link != &head_lru)
      {
	cache_entry = dlink_to_cache_entry(current_link);
	if (!verify_age_counter(cache_entry))
	  return false;
	current_link = current_link->getNext();
      }
    return true;
  }

  /* FOR DEBUGGING PURPOSE, it prints all the cache elements on the screen */ 

  void print_list()
  {
    MESSAGE("Orden de lru\n"
	      "    mru = %llu\n"
	      "    lru = %llu\n",
	      dlink_to_cache_entry(head_lru.getNext())->age_counter,
	      dlink_to_cache_entry(head_lru.getPrev())->age_counter);

    Cache_Entry * cache_entry;
      
    Dlink *current_link = head_lru.getNext();
    while (current_link != &head_lru)
      {
	cache_entry = dlink_to_cache_entry(current_link);
	MESSAGE("key = %i, age_counter = %llu", 
		  cache_entry->getKey(), cache_entry->age_counter);
	current_link = current_link->getNext();
      }
  }
# else

# define verify_cache()
# define print_list()

# endif /* DEBUG */
};



# ifdef DEBUG
template <class Key, class Data> 
long long Cache<Key, Data>::Cache_Entry::global_age_counter = 0;
# endif// DEBUG



# ifdef OLDNEW
# define New OLDNEW
# define Delete OLDDELETE
# endif


# endif /* TPL_CACHE_H */




