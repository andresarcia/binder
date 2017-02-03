# ifndef LOCATOR_PARS
# define LOCATOR_PARS

extern const int Default_Cache_Out_Size;

extern const int Default_Cache_In_Size;

extern const int Default_Cache_Migration_Size;

extern const int Default_Cache_Garbage_Size;

extern const int Default_Cache_New_Bindings_Size;

extern const int Default_Implicit_Message_Cnt_Size;

extern const int Default_Object_Table_Size;

extern const int Default_Container_Table_Size;

extern const int Default_Wait_Response_Table_Size;

extern const int Default_Wait_Broadcast_Resp_Table_Size;

extern const int Default_MTU_Size;

extern const int Default_Implicit_Msgs_Per_Chunck;

extern const int Default_Implicit_Msg_Dead_Age;

extern const bool Default_Chunk_Size_Depends_On_MTU;

extern const char * Default_Local_Services_File_Path;

extern const char * Default_Broadcast_Port_Path;

extern const bool Default_Attach_To_Broadcast_Group;

extern int cache_out_size;

extern int cache_in_size;

extern int cache_migration_size;

extern int cache_garbage_size;

extern int cache_new_bindings_size;

extern int implicit_message_cnt_size;

extern int object_table_size;

extern int container_table_size;

extern int wait_response_table_size;

extern int wait_broadcast_resp_table_size;

extern int mtu_size;

extern int implicit_msgs_per_chunck;

extern int implicit_msg_dead_age;

extern bool chunk_size_depends_on_mtu;

extern bool attach_to_broadcast_group;

extern void parameters_decode(int /*argc*/, char * argv[]);
# endif // LOCATOR_PARS 
