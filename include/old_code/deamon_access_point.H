# ifndef DEAMON_ACCESS_POINT_H
# define DEAMON_ACCESS_POINT_H

# include "loccom_message_header.H"
// # include <ahExceptions.H>
# include <aleph.H>
# include <tpl_lhash.H>

# ifdef New
# define OLDNEW New
# define OLDDELETE Delete
# undef New
# undef Delete
# endif

class Deamon_Access_Point 
{
  static int client_socket_descriptor;

  GenAlloc& alloc;

  // TODO: check for hash function consistency. It is probably 
  // given out of order table addresses.

  static unsigned long hashFct(const long int& key)
    {
      return (unsigned long) key;
    }

  class Register_Table_Entry : public LhashTable<long>::Bucket
  {
    char service_name[80];

  public:
    Register_Table_Entry(const long service_code, 
			 const char * src_serv_name) :
      LhashTable<long>::Bucket(service_code)
      {
	strcpy(service_name, src_serv_name);
      }

    // TODO:
    // it seems like it is not necessary to register the
    // "service_name" in the table.

    char * get_service_name () 
      {
	return service_name;
      }
  };
  
  // TODO:
  // check for staticness and the allocator
  static LhashTable<long> registered_services_table;

public:

  Deamon_Access_Point(const char *, 
		      unsigned int, 
		      GenAlloc & _alloc = *objectAlloc);
 
  void send(const Deamon_Msg_Entry_Header *, const size_t) const;
  //throw (NoRegisteredService);
  
  void receive(Deamon_Msg_Exit_Header &, const size_t);
  
  void receive(Deamon_Msg_Exit_Header &, 
	       const size_t, 
	       void *, 
	       const size_t);
  
  void add_service(const long service_code, char name[]);
  //throw (AlreadyRegistered);

  void delete_service(long); // TODO: 2daversion
  
  void shutdown();

  ~Deamon_Access_Point();
};

# endif // DEAMON_ACCESS_POINT_H













