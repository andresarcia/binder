# ifndef DEAMON_RECEPTION_POINT
# define DEAMON_RECEPTION_POINT

# include "loccom_message_header.H"
# include <aleph.H>
# include <tpl_lhash.H>

typedef int (*Deamon_Service) (Client_Id, Deamon_Msg_Entry_Header*); 

class Deamon_Reception_Point 
{

  static int listen_descriptor;

  GenAlloc & alloc;

  // TODO: check for hash function consistency. It is probably 
  // given out of order table addresses.
  static unsigned long hashFct(const long &);

  void reply(const Client_Id, Deamon_Msg_Exit_Header &, const size_t) const;

  void reply(Client_Id, Deamon_Msg_Exit_Header &, void * buffer_addr, size_t);

  void dispatcher(Client_Id, int *, fd_set); 


  class Services_Table_Entry : public LhashTable<long>::Bucket
  {
    char           service_name[80];
    Deamon_Service service_function;
    size_t         response_size;

  public:
    Services_Table_Entry(long service_code, char * servc_name,
			Deamon_Service dmn_servc, size_t resp_size) :
      LhashTable<long>::Bucket(service_code),
      service_function(dmn_servc),
      response_size(resp_size)
      {
	strcpy(service_name, servc_name);
      }

    Deamon_Service get_service_function() const 
      {
	return service_function;
      }
    
    size_t get_response_size() const
      {
	return response_size;
      }

    char * get_service_name() const
      {
	return const_cast<char*>(service_name);
      }
  };

  // TODO:
  // check for staticness
  static LhashTable<long> services_table;

public:

  Deamon_Reception_Point(const char *, 
			 unsigned int, 
			 GenAlloc & _alloc = *objectAlloc);
  
  //TODO:
  // throw ();
  void start_deamon(); 
  
  void add_service(long, char *, Deamon_Service, size_t);
    //    throw (AlreadyRegistered);

  void delete_service(long); // TODO: 2daversion

  void shutdown();

  ~Deamon_Reception_Point();

};

# endif // DEAMON_RECEPTION_POINT



