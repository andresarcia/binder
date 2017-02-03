void Server_Communication::service_create_unique_id(int & output_socket)
{ 
  Random_Number rand_num;
  const Random_Number Max_Numb = 0xFFFFFFFFFFFFFFFFll; 

  rand_num = static_cast<Random_Number> (static_cast<float>(Max_Numb) * 
					 rand() / (RAND_MAX+1.0));   
  
  Unique_Id_Message unique_id(get_global_timestamp(), rand_num);

  MESSAGE (("Global Timestamp: %llu \n Random Number: %llu", 
	    unique_id.get_logical_timestamp(), unique_id.get_random_number()))

    writen(output_socket, &unique_id, sizeof(Unique_Id_Message));
}

void Server_Communication::service_register_container(int & output_socket, 
						      void * parameters, 
						      size_t missing_size) 
{
  Register_Container_Message reg_cnt_msg;

  char * where_to_place = reinterpret_cast<char*>(&reg_cnt_msg) + 
    sizeof(Locator_Call_Header);    

  memcpy(where_to_place, parameters, missing_size);
 
  // process request ...
  
  Status_Reply_Message status_msg(OK); // testing ...

  writen(output_socket, &status_msg, sizeof(Status_Reply_Message));

  // the memory that was allocated at the dispatcher has to be freed.
  free(parameters);
}

