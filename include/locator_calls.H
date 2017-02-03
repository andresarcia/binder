# ifndef LOCATOR_CALLS_H
# define LOCATOR_CALLS_H

# include <aleph.H>
# include "locator_exceptions.H"
# include "local_access_point.H"
# include "binder.H"
# include "basic_defs.H"
# include "local_message_header.H"

extern Local_Access_Point * clt_services_access; 

extern Local_Access_Point * srv_services_access;

extern void bootstrap_services();

extern Locator_Call_Exit_Code get_site_id(Site_Id & site_id)
throw(std::exception);

// REGISTERING SYSTEM CALLS.
extern void register_cnt(Container_Id & cnt_id) 
  throw (std::exception, Duplicated, Panic);

extern void unregister_cnt(const Container_Id & cnt_id) 
  throw(std::exception, NotFound, RefusedService, Panic);

extern void register_obj(Object_Id & obj_id, const Container_Id & cnt_id) 
  throw(std::exception, Duplicated, NotFound, Panic);

extern void unregister_obj(const Object_Id & obj_id) 
  throw(std::exception, NotFound, RefusedService, Panic);

// MIGRATION SYSTEM CALLS.
extern void src_unreg_mig_obj(const Object_Id & obj_id, 
			      const Site_Id & tgt_site_id) 
  throw(std::exception, NotFound, ObjectBusy, Panic);

extern void tgt_reg_mig_obj(const Object_Id & obj_id, 
			    const Container_Id & cnt_id,
			    const Logical_Timestamp timestamp) 
  throw(std::exception, NotFound, Duplicated, Panic);

extern void src_unreg_mig_cnt(const Container_Id & cnt_id, 
			      const Site_Id & tgt_site_id) 
  throw(std::exception, NotFound, RefusedService, Panic);

extern void tgt_reg_mig_cnt(const Container_Id & cnt_id) 
  throw(std::exception, Duplicated, Panic);


// INVOCATION SYSTEM CALLS.
extern Message_Id clt_invoke_send(Binding & binding, 
				  const void * request,
				  size_t request_size)
  throw (std::exception, ObjectDead, Panic);

extern Message_Id multi_receive(Binding & binding, 
				const Container_Id & receiving_container_id,
				void * data,
				size_t & data_size,
				Reception_Type & reception_type)
  throw (std::exception, NotFound, ObjectDead, RecentBinding, Panic);

extern void srv_invoke_reply(const Message_Id & msg_id, 
			     const Binding & binding,
			     const Container_Id & replying_cnt_id,
			     const void * reply,
			     size_t reply_size)
  throw (std::exception, Panic);

// LOCATION SYSTEM CALLS.
extern Locator strong_locate(const Object_Id & obj_id)
  throw(std::exception, ObjectDead, Panic);

extern Locator weak_locate(const Object_Id & obj_id)
  throw(std::exception, NotFound, ObjectDead, Panic);  

// this call introduce an implicit find message in this locator, which will
// propagate with time.
extern void implicit_locate(const Binding & old_binding) 
  throw (std::exception, Panic);

// LOCATOR UPDATING CALLS.

void test_location(Locator & locator)
  throw (std::exception, NotFound, ObjectDead, Panic);

void ping(unsigned int number_of_entries, const Cache_Update_Policy policy)
  throw (std::exception, NotFound, Panic);

# endif //  LOCATOR_CALLS_H
