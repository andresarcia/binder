# ifndef TPL_LHASH_H
# define TPL_LHASH_H

# include <ahNew.H>
# include <primes.H>
//# include <tpl_dlist.H>
//# include <primes.H>
# include <tpl_dlist.H>
// # include <ahNew.H>

using namespace Primes;

template <class Key, class BucketType>
class GenLhashTable
{
public:

  typedef BucketType Bucket;

private:

  typedef unsigned long (*HashFctType)(const Key&);

  bool FREE_MEMORY_MNG;

protected: 

  typedef Dlist<Key> BucketList;
          
  typedef Dlist<Key>::Iterator BucketItor;

private:

  BucketList* bucket_table;

  size_t table_size;        

  size_t busy_slots_counter;

  size_t num_items;

  HashFctType hashFct;

  enum Address 
  {
    FORWARD,
    BACKWARD,
    
    LAST
  };

protected:
  GenAlloc&   alloc;

protected:

protected:

  GenLhashTable(HashFctType _hashFct, 
		size_t      _table_size, 
		GenAlloc&   _alloc,
		bool _FREE_MEMORY_MNG = true) 
    Exception_Prototypes(SizeFault, Nomem) :
      FREE_MEMORY_MNG    (_FREE_MEMORY_MNG),
      table_size         (_table_size), 
      busy_slots_counter (0),
      num_items          (0), 
      hashFct            (_hashFct), 
      alloc              (_alloc)
  {
    table_size = next_prime(table_size);

    bucket_table = AllocNew(alloc, BucketList) [table_size];
  }

public:

public:

  void removeAllAndDelete()
  {
    size_t i;
    Bucket *node;

    for (i = 0; i < table_size; i++)
      {
	BucketList::Iterator itor(bucket_table[i]);
	while (itor.hasCurr())
	  {
	    node = static_cast<Bucket*>(itor.getCurr());
	    ASSERT(node != 0);
	    itor.next();
	    node->del();
	    AllocDelete(alloc, node);
	  }
      }
  }
  virtual ~GenLhashTable()
  {
    if (FREE_MEMORY_MNG)
      removeAllAndDelete();
    AllocDeleteArray(alloc, bucket_table); 
  }
  Bucket* insert(Bucket* bucket) 
  {
    size_t bucket_index = (*hashFct)(bucket->getKey()) % table_size;
      
    MESSAGE("bucket index: %i", bucket_index);

    if (bucket_table[bucket_index].isEmpty())
      busy_slots_counter++; 

    bucket_table[bucket_index].append(bucket);

    ++num_items;

    return bucket;
  }
  Bucket* search(const Key& key) const
  {
    size_t bucket_index = (*hashFct)(key) % table_size;

    if (bucket_table[bucket_index].isEmpty())
      return NULL;

    for (BucketList::Iterator itor(bucket_table[bucket_index]);
	 itor.hasCurr();
	 itor.next()
	 )
      {
	Bucket* node = static_cast<Bucket*>(itor.getCurr());

	if (key == node->getKey())
	  return node;
      }
    
    return NULL;
  }

  // gets the next bucket with repeated key available. Returns its own
  // address in the case that there is no next repeated key. This
  // routine is not protected against undefined memory addresses.
  
  Bucket* searchFollowing(Address addr, Bucket* bucket) const 
  {
    ASSERT(bucket != NULL);
 
    Dlist<Key>::Item * node = static_cast<Dlist<Key>::Item *>(bucket);

    for (node = (addr == FORWARD) ? 
	   static_cast<Dlist<Key>::Item *>(bucket)->getNext() :
	   static_cast<Dlist<Key>::Item *>(bucket)->getPrev(); 
	 
	 node != static_cast<Dlist<Key>::Item *>(bucket); 
	 
	 node = (addr == FORWARD) ?
	   node->getNext() :
	   node->getPrev())
      {
	if (bucket->getKey() == static_cast<Bucket*>(node)->getKey())
	  return static_cast<Bucket*>(node);
      }
    
    return bucket;
  }
  
  Bucket* searchNext(Bucket* bucket) const 
  {
    ASSERT(bucket != NULL);
    
    Dlist<Key>::Item * node = static_cast<Dlist<Key>::Item *>(bucket);
    
    for (node = static_cast<Dlist<Key>::Item *>(bucket)->getNext();
	 node != static_cast<Dlist<Key>::Item *>(bucket); 	 
	 node = node->getNext())
      {
	if (bucket->getKey() == static_cast<Bucket*>(node)->getKey())
	  return static_cast<Bucket*>(node);
      }
    
    return bucket;
  }

  Bucket* searchPrev(Bucket* bucket) const 
  {
    ASSERT(bucket != NULL);
    
    Dlist<Key>::Item * node = static_cast<Dlist<Key>::Item *>(bucket);
    
    for (node = static_cast<Dlist<Key>::Item *>(bucket)->getPrev();
	 node != static_cast<Dlist<Key>::Item *>(bucket); 	 
	 node = node->getPrev())
      {
	if (bucket->getKey() == static_cast<Bucket*>(node)->getKey())
	  return static_cast<Bucket*>(node);
      }
    
    return bucket;
  }

  Bucket* remove(Bucket* bucket) 
  {
    ASSERT(search(bucket->getKey()) == bucket); // Searches itself
    
    Bucket* next = static_cast<Bucket*>(bucket->getNext());
    
    bucket->del();
    
    if (next->isEmpty())
      busy_slots_counter--;
    
    --num_items;
    
    return bucket;
  }
  size_t resize(size_t new_size) 
    Exception_Prototypes (SizeFault, Nomem)
  {
    new_size = next_prime(new_size);
    
    if (new_size == table_size)
      return table_size;
    
    BucketList* new_table = AllocNew(alloc, BucketList) [new_size];
    
    /* Saves state of old table */
    BucketList* old_table = bucket_table;
     size_t old_size = table_size;

     ID(size_t old_num_items = num_items);
     ID(size_t insertions_counter = 0);

         /* reset to an empty table */
     bucket_table        = new_table;
     table_size          = new_size;
     busy_slots_counter  = 0;
     num_items           = 0;

     for (size_t i = 0; i < old_size; i++)
       {
             /* go through all items of i-th list */
         for (BucketList::Iterator itor(old_table[i]); 
              itor.hasCurr(); /* Nothing */)
           {
             Bucket* node = static_cast<Bucket*>(itor.getCurr());
             itor.next();  /* before deletion, advance iterator */
             node->del();  /* deletes from old list */
             insert(node); /* insert in new array */

             IS(insertions_counter++);
           }
       }
     AllocDeleteArray(alloc, old_table);

     ASSERT(insertions_counter == old_num_items);
     ASSERT(insertions_counter == num_items);

     return table_size;
   }
    size_t resize_next() throw (std::exception, SizeFault, Nomem)
    {
      return resize(table_size + 1);
    }

    size_t resize_prev() throw (std::exception, SizeFault, Nomem)
    {
      return resize(table_size - 1);
    }

    size_t get_table_size() const 
    {
      return table_size;
    }

    size_t get_num_items() const
    {
      return num_items;
    }

    size_t get_num_busy_slots() const
    {
      return busy_slots_counter;
    }
};

    template <class Key>
class LhashBucket : public Dlist<Key>::Item
{
private:
   
  LhashBucket(const LhashBucket&);
  LhashBucket& operator = (const LhashBucket&);

public:

  LhashBucket() { /* Empty */ }

  LhashBucket(const Key& key) : Dlist<Key>::Item(key) { /* Empty */ }

  ~LhashBucket() { /* Empty */ }

  const Key& getKey() const { return getData(); }

  Key& getKey() { return getData(); }
};

    template <class Key>
class LhashBucketVtl : public LhashBucket<Key>
{
private:
   
  LhashBucketVtl(const LhashBucketVtl&);
  LhashBucketVtl& operator = (const LhashBucketVtl&);

public:

  LhashBucketVtl() { /* Empty */ }

  virtual ~LhashBucketVtl() { /* Empty */ }

  LhashBucketVtl(const Key& key) : LhashBucket<Key>(key) { /* Empty */ }
};

    template <class Key> 
class LhashTable :  public GenLhashTable<Key, LhashBucket<Key> >
{
public:

    LhashTable(HashFctType  _hashFct, 
               const size_t _table_size = DefaultPrime, 
               GenAlloc&    _alloc      = *objectAlloc,
	       bool         _FREE_MEM_MNG = true) 
      Exception_Prototypes (SizeFault, Nomem) : 
        GenLhashTable<Key, LhashBucket<Key> >(_hashFct, _table_size, 
					      _alloc, _FREE_MEM_MNG)
    {
      // Empty
    }
};

template <class Key> 
class LhashTableVtl :  public GenLhashTable<Key, LhashBucketVtl<Key> >
{
public:

    LhashTableVtl(HashFctType  _hashFct, 
                  const size_t _table_size = DefaultPrime, 
                  GenAlloc&    _alloc     = *objectAlloc) 
      Exception_Prototypes (SizeFault, Nomem) : 
        GenLhashTable<Key, LhashBucketVtl<Key> >(_hashFct, _table_size, _alloc)
    {
      // Empty
    }
};

# endif/* TPL_LHASH_H */

