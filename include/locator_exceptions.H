# ifndef LOCATOR_EXCEPTIONS
# define LOCATOR_EXCEPTIONS

# include <ahExceptions.H>
# include "binder.H"


/**
   Object dead exception. Use this exception when an object is known
   not to be in the system. This occurs after destroying or unregistering
   such object.
*/

class ObjectDead : public AlephExc
{
public:

  ObjectDead() : AlephExc("Object dead", OTHER) 
  { /* Empty */ }

  ObjectDead(const char* _file, int _line)
    : AlephExc("Object dead", _file, _line, OTHER) 
  { /* Empty */ }
};

/**
  Recent binding exception. Use this exception to update tables at
  client's side when an invocation results in a more recent binding, due
  to the migration of the invoked object.
*/

class RecentBinding : public AlephExc
{
  Binding binding;
  
public:
  
  RecentBinding(const Binding & _binding) : 
    AlephExc("Recent binding", OTHER),
    binding(_binding)
  { 
    /* Empty */ 
  }
  
  RecentBinding(const Binding & _binding, const char* _file, int _line) : 
    AlephExc("Recent binding", _file, _line, OTHER),
    binding(_binding)
  { 
    /* Empty */ 
  }

  const Binding & get_binding() const
  {
    return binding;
  }
};

/**
   Object busy exception. Use this exception when an object that is going
   to be unregistered, is still processing an invocation at the time of the
   unregistering process.
*/

class ObjectBusy : public AlephExc
{
public:

  ObjectBusy() : AlephExc("Object busy", OTHER) 
  { /* Empty */ }

  ObjectBusy(const char* _file, int _line)
    : AlephExc("Object busy", _file, _line, OTHER) 
  { /* Empty */ }
};

# endif //LOCATOR_EXCEPTIONS
