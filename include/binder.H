# ifndef BINDER_H
# define BINDER_H


//# include <aleph.H>
# include <unistd.h>
//# include "uid.H" 
# include "port.H"
# include "basic_defs.H"

/*
class Site_Id 
{ 
  Ip_Address ip;

  Site_Id(Ip_Address ip_address)
    : ip(ip_address)
    {
      // empty
    }

public:

  Site_Id()
    {
      char string_ip[ 2*sizeof(Ip_Address)+1 ];

      // TODO: This implies a system call. So reconsider putting the hostid
      // TODO: as a static variable.
      ip = gethostid();

      sprintf(string_ip,"%X",ip);

      for (char * char_iter = string_ip;
	   *char_iter != '\0';
	   char_iter ++)
	*char_iter = *char_iter - '0' + 'A';
      
      // MESSAGE("-- Site ID: %s", string_ip);
    }

  const Ip_Address& get_ip() const  
    {
      return ip;
    }

  bool operator == (const Site_Id & site) 
    { 
      return (ip == site.get_ip());
    }
};
*/

// typedef Port Site_Id;

class Site_Id : public Port
{
  
public:  
  //TODO: uint32_t _ipAddr; uint64_t _counter; uint32_t _port_number
  Site_Id(unsigned int _ipAddr, 
	  unsigned int _counter, 
	  unsigned int _port_number)
    : Port(_ipAddr, _counter, _port_number)
  {
    // empty
  }

  // default constructor with invalid values.
  Site_Id() :
    Port(0, 0, 0)
  {
    // empty
  }

  Site_Id(Port _port) :
    Port(_port)
  {
    // empty
  }

  Site_Id(char * _str) : 
    Port(_str)
  {
    // empty
  }
};

typedef Uid Container_Id; 

typedef Uid Object_Id;

class Locator 
{
  Object_Id         object_id;
  Site_Id           target_site_id;
  Logical_Timestamp logical_timestamp;

public:

  Locator (const Object_Id & obj_id, const Site_Id & sit_id,
	   Logical_Timestamp _timestamp = 0) : 
    object_id(obj_id), 
    target_site_id(sit_id),
    logical_timestamp(_timestamp)
  {
    //empty
  }
  
  Locator() :
    object_id(0, 0, 0),
    target_site_id(0, 0, 0),
    logical_timestamp(-1)
  {
    // empty
  }
  
  const Object_Id & get_object_id() const
    {
      return object_id;
    }

  const Site_Id & get_target_site_id() const
    {
      return target_site_id;
    }

  Logical_Timestamp get_logical_timestamp() const 
    {
      return logical_timestamp;
    } 

  void set_logical_timestamp(Logical_Timestamp _new_timestamp)
  {
    logical_timestamp = _new_timestamp;
  }

  // updating of propietary's logical timestamp 
  void increase_logical_timestamp()
    {
      logical_timestamp++;
    }  
   
  /*
  // updating of any entity logical timestamp 
  void update_logical_timestamp(const Locator &newer_locator)
    {
      ASSERT(newer_locator.logical_timestamp > logical_timestamp);
      logical_timestamp = newer_locator.logical_timestamp;
    }
  */

  void update_locator(const Locator & newer_locator)
  {
    ASSERT(newer_locator.logical_timestamp > logical_timestamp);
    target_site_id = newer_locator.target_site_id;
    logical_timestamp = newer_locator.logical_timestamp;
  }

  bool operator == (const Locator & locator) const 
    {
      return ((object_id == locator.object_id) &&
	      (target_site_id == locator.target_site_id));
      //TODO: Think about this:
      //TODO: (logical_timestamp == locator.logical_timestamp));
    }
  
  Locator & operator = (const Locator & _loc)
  {
    // Watch the assignation of logical_timestamp from one locator
    // to another.
    object_id = _loc.object_id;
    target_site_id = _loc.target_site_id;
    logical_timestamp = _loc.logical_timestamp;
    return *this;
  }

  bool operator > (const Locator & _loc) const
  {
    ASSERT (object_id == _loc.object_id);

# ifdef DEBUG
    if (logical_timestamp == _loc.logical_timestamp)
      ASSERT(target_site_id == _loc.target_site_id);
# endif     

    return (logical_timestamp > _loc.logical_timestamp);
  }
};


class Binding : public Locator
{
  Container_Id source_container_id;  
  Site_Id      source_site_id;

public:

  Binding(const Locator &      locator, 
	  const Container_Id & src_cnt_id, 
	  const Site_Id &      src_site_id)
    : Locator(locator),
      source_container_id(src_cnt_id),
      source_site_id(src_site_id)
    {
      // empty
    }   
  
  Binding() : 
    source_container_id(0, 0, 0),
    source_site_id(0, 0, 0)
  {
    //empty
  }
  
  const Container_Id & get_source_container_id() const
    {
      return source_container_id;
    }

  const Site_Id & get_source_site_id() const
    {
      return source_site_id;
    }

  Locator & get_locator() const
  {
    return *const_cast<Locator *>(static_cast<const Locator *>(this));
  }

  Binding & operator=(const Binding & _bind)
  {
    source_container_id = _bind.source_container_id;

    source_site_id = _bind.source_site_id;

    *static_cast<Locator *>(this) = _bind.get_locator();

    return *this;
  }

};

// Invalid object type.

const Logical_Timestamp INVALID_LOGICAL_TIMESTAMP = -1;

const Object_Id INVALID_OBJECT_ID(0,0,
				  INVALID_LOGICAL_TIMESTAMP);

const Container_Id INVALID_CONTAINER_ID(0,0,0);

const Site_Id INVALID_SITE_ID(0,0,0);

const Message_Id INVALID_MESSAGE_ID(0, 0, 0);

const Locator INVALID_LOCATOR;

const Binding INVALID_BINDING;


# endif // BINDER_H









