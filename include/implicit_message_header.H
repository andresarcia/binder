# ifndef IMPLICTI_MESSAGE_HEADER
# define IMPLICTI_MESSAGE_HEADER

# include <binder.H>

enum Implicit_Msg_Type
{
  IMPLICIT_LOCATOR_ANOUNCE,
  IMPLICIT_FIND,
  IMPLICIT_DEATH_ANOUNCE,

  IMPLICIT_LAST
};

# define INITIAL_AGE 0

class Implicit_Msg_Header 
{
  Implicit_Msg_Type message_type;

  Site_Id source_site_id;

  Logical_Timestamp message_age;  

  size_t message_size;

public:
  Implicit_Msg_Header(const Implicit_Msg_Type _msg_type,
		      const Site_Id & _src_site,
		      const size_t _msg_size) :
    message_type(_msg_type),
    source_site_id(_src_site),
    message_age(INITIAL_AGE),
    message_size(_msg_size)
  {
    // empty
  }
    

  const Implicit_Msg_Type get_message_type() const
  {
    return message_type;
  }

  void increase_message_age()
  {
    message_age ++;
  }

  const Logical_Timestamp get_message_age() const
  {
    return message_age;
  }

  const size_t get_message_size() const
  {
    return message_size;
  }

  const Site_Id & get_source_site_id() const
  {
    return source_site_id;
  }

  virtual const Object_Id & get_object_id() const = 0;
};

# undef INITIAL_AGE


class Implicit_Locator_Anounce_Msg : public Implicit_Msg_Header
{

  Locator locator;

public:
  Implicit_Locator_Anounce_Msg(const Locator & _locator,
			       const Site_Id & _src_site) :
    Implicit_Msg_Header(IMPLICIT_LOCATOR_ANOUNCE,
			_src_site,
			sizeof(*this)),
    locator(_locator)
  {
    // empty
  }
    
  const Locator & get_locator() const
  {
    return locator;
  }

  Locator & get_locator()
  {
    return locator;
  }

  virtual const Object_Id & get_object_id() const
  {
    return locator.get_object_id();
  }
};

class Implicit_Find_Msg : public Implicit_Msg_Header
{

  Binding binding;

public:
  Implicit_Find_Msg(const Binding & _binding,
		    const Site_Id & _src_site) :
    Implicit_Msg_Header(IMPLICIT_FIND,
			_src_site,
			sizeof(*this)),
    binding(_binding)
  {
    // empty
  }

  const Binding & get_binding() const
  {
    return binding;
  }
  
  Binding & get_binding() 
  {
    return binding;
  }

  virtual const Object_Id & get_object_id() const
  {
    return binding.get_object_id();
  }
};

class Implicit_Death_Anounce_Msg : public Implicit_Msg_Header
{

  Object_Id dead_object_id;

public:
  Implicit_Death_Anounce_Msg(const Object_Id & _obj_id,
			     const Site_Id & _src_site) :
    Implicit_Msg_Header(IMPLICIT_DEATH_ANOUNCE,
			_src_site,
			sizeof(*this)),
    dead_object_id(_obj_id)
  {
    // empty
  }

  virtual const Object_Id & get_object_id() const
  {
    return dead_object_id;
  }
};

# endif // IMPLICIT_MESSAGE_HEADER






















