# ifndef LOCATOR_CACHES_H
# define LOCATOR_CACHES_H

# include "protected_cache.H"
# include "binder.H"
# include "remote_message_header.H"

class Garanteed_Uniqueness 
{
protected:

  Garanteed_Uniqueness(unsigned & _instance_counter)
  {
    // This means that the derived object has never been created.
    ASSERT(_instance_counter == 0);
    _instance_counter++;
  }
};

// Object_Id stands for local object_id being invoked.
class Cache_In : public Protected_Cache<Object_Id, Cache_In_Data>,
		 public Garanteed_Uniqueness
{
  static unsigned instance_counter;

public:

  Cache_In(unsigned long (*_hash_fct)(const Object_Id&), size_t _cache_size) :
    Protected_Cache<Object_Id, Cache_In_Data>(_hash_fct, _cache_size),
    Garanteed_Uniqueness(instance_counter)
  {
    // empty
  }

  class Cache_In_Iterator :
    public Protected_Cache<Object_Id, Cache_In_Data>::Protected_Cache_Iterator
  {
  
  public: 
    Cache_In_Iterator(Protected_Cache<Object_Id, Cache_In_Data> * _ptr_cache,
		      const Object_Id & object_id) 
      throw (std::exception, NotFound) :
      Protected_Cache<Object_Id, Cache_In_Data>::
    Protected_Cache_Iterator(_ptr_cache, object_id)
    {
      // empty
    }
  };

};

// Object_Id stands for remote object_id to invoke.
class Cache_Out : public Protected_Cache<Object_Id, Locator>,
		  public Garanteed_Uniqueness
{
  static unsigned instance_counter;
  
public:
  Cache_Out(unsigned long (*_hash_fct)(const Object_Id&), size_t _cache_size) :
    Protected_Cache<Object_Id, Locator>(_hash_fct, _cache_size),
    Garanteed_Uniqueness(instance_counter)
  {
    // empty
  }
};

// Object_Id stands for migrated object_id, and Locator is the last site
// in which the object was seen. The Locator class functions better than
// just the Site_Id, because the logical timestamp can be tracked and compared.
class Cache_Mig : public Protected_Cache<Object_Id, Locator>,
		  public Garanteed_Uniqueness
{
   static unsigned instance_counter;
  
public:
  Cache_Mig(unsigned long (*_hash_fct)(const Object_Id&), size_t _cache_size) :
    Protected_Cache<Object_Id, Locator>(_hash_fct, _cache_size), 
    Garanteed_Uniqueness(instance_counter)
  {
    // empty
  }
};

// Object_Id stands for the new object which Locator is recently known and
// not registered in Cache_Out.
class Cache_New_Bnds : public Protected_Cache<Object_Id, Locator>,
		       public Garanteed_Uniqueness
{
  static unsigned instance_counter;
  
public:
  Cache_New_Bnds(unsigned long (*_hash_fct)(const Object_Id&), 
		 size_t _cache_size) :
    Protected_Cache<Object_Id, Locator>(_hash_fct, _cache_size), 
    Garanteed_Uniqueness(instance_counter)
  {
    // empty
  } 
};

/*
class Empty_Class 
{
  // empty
public:
  bool operator == (const Empty_Class & right_hand_op) const
  {
    return true;
  }
};
*/

class Cache_Garbage : public Garanteed_Uniqueness
{
private:
  static unsigned instance_counter;

  Protected_Cache<Object_Id, Empty_Class> p_cache;

public:
  Cache_Garbage(unsigned long (*_hash_fct)(const Object_Id&), 
		size_t _cache_size) :
    Garanteed_Uniqueness(instance_counter),
    p_cache(_hash_fct, _cache_size)
  {
    // empty
  }

  void insert(const Object_Id& key)
  {
    Empty_Class empty_object;

    p_cache.insert(key, empty_object);
  }

  bool find_key(const Object_Id & key)
  {
    if (p_cache.find_data_ptr(key) == NULL)
      return false;
    else
      return true;
  }

  void remove(const Object_Id & key) throw (std::exception, NotFound)
  {
    p_cache.remove(key);
  }
  
  void expand(size_t plus_size) 
    throw(std::exception, SizeFault, Nomem)
  {
    p_cache.expand(plus_size);
  }
  
  size_t get_size() const
  {
    return p_cache.get_size();
  }

  size_t get_num_items() const
  {
    return p_cache.get_num_items();
  }

  void cache_unlock()
  {
    p_cache.cache_unlock();
  }
};

# endif // LOCATOR_CACHES_H



