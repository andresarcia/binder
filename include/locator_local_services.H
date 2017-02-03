# ifndef LOCATOR_LOCAL_SERVICES_H
# define LOCATOR_LOCAL_SERVICES_H

# include "binding_point.H"
# include "local_reception_point.H"
# include "locator_tables.H"

extern int local_service_get_site_id(Binding_Point * return_point, 
				     Msg_Entry_Header * input_msg);

extern int local_service_register_cnt(Binding_Point * return_point, 
				      Msg_Entry_Header * input_msg);

extern int local_service_unregister_cnt(Binding_Point * return_point, 
					Msg_Entry_Header * input_msg);

extern int local_service_register_obj(Binding_Point * return_point, 
				      Msg_Entry_Header * input_msg);

extern int local_service_unregister_obj (Binding_Point * return_point, 
					 Msg_Entry_Header * input_msg);

extern int local_service_tgt_reg_mig_obj (Binding_Point * return_point, 
					  Msg_Entry_Header * input_msg);

extern int local_service_src_unreg_mig_obj (Binding_Point * return_point, 
					    Msg_Entry_Header * input_msg);

extern int local_service_tgt_reg_mig_cnt (Binding_Point * return_point, 
					  Msg_Entry_Header * input_msg);

extern int local_service_src_unreg_mig_cnt (Binding_Point * return_point, 
					    Msg_Entry_Header * input_msg);

extern int local_service_strong_locate (Binding_Point * return_point, 
					Msg_Entry_Header * input_msg);

extern int local_service_weak_locate (Binding_Point * return_point, 
				      Msg_Entry_Header * input_msg);

extern int local_service_implicit_locate (Binding_Point * return_point, 
					  Msg_Entry_Header * input_msg);

extern int local_service_clt_invoke_send (Binding_Point * return_point, 
					  Msg_Entry_Header * input_msg);

extern int local_service_locator_super_receive (Binding_Point * return_point, 
						Msg_Entry_Header * input_msg);

extern int local_service_srv_invoke_reply (Binding_Point * return_point, 
					   Msg_Entry_Header * input_msg);

extern int local_service_test_object_location (Binding_Point * return_point, 
					       Msg_Entry_Header * input_msg);

extern int local_service_ping_n_objects (Binding_Point * return_point, 
					 Msg_Entry_Header * input_msg);

// complementary functions

extern void 
delete_entries_from_cache_in(const Object_Id & object_id);

extern void 
answer_all_pending_replys_and_delete(Registered_Object_Bucket * object_bucket);

extern Invocation_Reply_Type 
look_up_in_caches(const Object_Id & object_id, Locator & new_locator);

extern void
update_caches_with_response(const Invocation_Reply_Type, const Locator &);

# endif // LOCATOR_LOCAL_SERVICES_H
