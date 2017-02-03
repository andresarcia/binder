# include <aleph.H>
# include <implicit_message_header.H>
# include <implicit_messages_module.H>

# define TREE_SIZE 15
# define TOTAL_MSGS 2000
# define TOTAL_POOL_ELEMS 20
# define DEAD_AGE 10
# define CHUNK_SIZE 1024


Implicit_Msg_Container msg_tree(TREE_SIZE, DEAD_AGE);

char chunk_of_messages[CHUNK_SIZE];

int get_rand(int min_number, int max_number)
{
  ASSERT((max_number - min_number) >= 0);

  if (max_number == min_number)
    return max_number;

  max_number = max_number - min_number + 1;

  int ret_val = min_number;
  
  const long long MY_DOUBLE_RAND_MAX = RAND_MAX;
  
  uint64_t random_number = random() ;

  uint64_t value = max_number*random_number/MY_DOUBLE_RAND_MAX;
  
  ret_val += value;
  
  ASSERT(ret_val >= min_number && ret_val <= (min_number + max_number - 1));

  return ret_val; 
} 


char * object_pool[] = 
{
  "GJJLDIEOKAKBOBJAFBAAAAAAAAAAAAAAAAAUNOXXXAAAAAAA",
  "GJJLDIEOKAKBOBJAGBAAAAAAAAAAAAAAAAADOSXXXAAAAAAA",
  "GJJLDIEOKAKBOBJAHBAAAAAAAAAAAAAAAAATRESXXXAAAAAA",
  "GJJLDIEOKAKBOBJAIBAAAAAAAAAAAAAAAAACUATROXXXAAAA",
  "GJJLDIEOKAKBOBJAJBAAAAAAAAAAAAACINCOAKLBAAAAAAAA",
  "GJJLDIEOKAKBOBJAKBAAAAAAAAAAAAAASEISHNHEAAAAAAAA",
  "GJJLDIEOKAKBOBJALBAAAAAAAAAAAAAASIETENDHAAAAAAAA",
  "GJJLDIEOKAKBAAAAMBOBJAAAAAAAAAAAOCHOLLHCAAAAAAAA",
  "GJJLDIEOKAKBAAAANBOBJAAAAAAAAAAANUEVEMOAAAAAAAAA",
  "GJJLDIEOKAKBAAAAOBOBJAAAAAAAAAAADIEZGFNCAAAAAAAA",
  "GJJLDIEOKAKBAAAAPBAAAAAAOBJAAAAAONCEHPBGAAAAAAAA",
  "GJJLDIEOKAKBAAAAACAAAAAAOBJAAAAADOCECKEBAAAAAAAA",
  "GJJLDIEOKAKBAAAABCAAAAAAOBJAAAAATRECEKAGAAAAAAAA",
  "GJJLDIEOKAKBAAAACCAAAAAAOBJAAAAACATORCEDAAAAAAAA",
  "GJJLDIEOKAKBAAAADCAAAAAAAAAOBJAAQUINCEMBAAAAAAAA",
  "GJJLDIEOKAKBAAAAECAAAAAAAAAAAAAADIECISEISOBJAAAA",
  "GJJLDIEOKAKBOBJAFCAAAAAAAAAAAAAADIECISIETEXAAAAA",
  "GJJLDIEOKAKBOBJAGCAAAAAAAAAAAAAADIECIOCHOAAAAAAA",
  "GJJLDIEOKAKBOBJAHCAAAAAAAAAAAAAADIECINUEVEAAAAAA",
  "GJJLDIEOKAKBOBJAICAAAAAAAAAAAAAAVEINTEBEAAAAAAAA"
};

char * site_pool[] = 
{
  "GJJLDIEOKAKBAAAAFBAAAAAAAAAAAAAAAAAUNOXXXAAAAAAA",
  "GJJLDIEOKAKBAAAAGBAAAAAAAAAAAAAAAAADOSXXXAAAAAAA",
  "GJJLDIEOKAKBAAAAHBAAAAAAAAAAAAAAAAATRESXXXAAAAAA",
  "GJJLDIEOKAKBAAAAIBAAAAAAAAAAAAAAAAACUATROXXXAAAA",
  "GJJLDIEOKAKBAAAAJBAAAAAAAAAAAAACINCOAKLBAAAAAAAA",
  "GJJLDIEOKAKBAAAAKBAAAAAAAAAAAAAASEISHNHEAAAAAAAA",
  "GJJLDIEOKAKBAAAALBAAAAAAAAAAAAAASIETENDHAAAAAAAA",
  "GJJLDIEOKAKBAAAAMBAAAAAAAAAAAAAAOCHOLLHCAAAAAAAA",
  "GJJLDIEOKAKBAAAANBAAAAAAAAAAAAAANUEVEMOAAAAAAAAA",
  "GJJLDIEOKAKBAAAAOBAAAAAAAAAAAAAADIEZGFNCAAAAAAAA",
  "GJJLDIEOKAKBAAAAPBAAAAAAAAAAAAAAONCEHPBGAAAAAAAA",
  "GJJLDIEOKAKBAAAAACAAAAAAAAAAAAAADOCECKEBAAAAAAAA",
  "GJJLDIEOKAKBAAAABCAAAAAAAAAAAAAATRECEKAGAAAAAAAA",
  "GJJLDIEOKAKBAAAACCAAAAAAAAAAAAAACATORCEDAAAAAAAA",
  "GJJLDIEOKAKBAAAADCAAAAAAAAAAAAAAQUINCEMBAAAAAAAA",
  "GJJLDIEOKAKBAAAAECAAAAAAAAAAAAAADIECISEISAAAAAAA",
  "GJJLDIEOKAKBAAAAFCAAAAAAAAAAAAAADIECISIETEXAAAAA",
  "GJJLDIEOKAKBAAAAGCAAAAAAAAAAAAAADIECIOCHOAAAAAAA",
  "GJJLDIEOKAKBAAAAHCAAAAAAAAAAAAAADIECINUEVEAAAAAA",
  "GJJLDIEOKAKBAAAAICAAAAAAAAAAAAAAVEINTEBEAAAAAAAA"
};




int main()
{
 
  Bootstrapper::bootstrap();

  Site_Id 
    tgt_site_id_1(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
  
  msg_tree.get_implicit_chunk(tgt_site_id_1, chunk_of_messages, CHUNK_SIZE);

  // insert messages
  for (int n_msg = 0; n_msg < TOTAL_MSGS; n_msg ++)
    {
      switch (get_rand(IMPLICIT_LOCATOR_ANOUNCE, 
		       IMPLICIT_DEATH_ANOUNCE))
	{
	case IMPLICIT_LOCATOR_ANOUNCE :
	  {
	    // Object_Id obj_id(object_pool[1]);
	    Object_Id obj_id(object_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);	  
	    	    
	    Site_Id obj_site_id(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Site_Id 
	      msgsrc_site_id(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Locator locator(obj_id, obj_site_id, get_rand(0, 100));
	    
	    Implicit_Locator_Anounce_Msg
	      locator_anounce(locator, msgsrc_site_id);
	    
	    msg_tree.add_implicit_msg(locator_anounce);
	  }	    
	  break;

	case  IMPLICIT_FIND :
	  {
	    //Object_Id obj_id(object_pool[1]);
	    Object_Id obj_id(object_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Site_Id obj_site_id(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Locator locator(obj_id, obj_site_id, get_rand(0, 100));
	    
	    Site_Id src_site_id(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Container_Id 
	      src_container_id(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Binding binding(locator, src_container_id, src_site_id);
	    
	    Site_Id 
	      msgsrc_site_id(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Implicit_Find_Msg find(binding, msgsrc_site_id);
	    
	    msg_tree.add_implicit_msg(find);
	  }
	  
	  break;
	  
	case IMPLICIT_DEATH_ANOUNCE :
	  {
	    //Object_Id obj_id(object_pool[1]);
	    Object_Id obj_id(object_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Site_Id 
	      msgsrc_site_id(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
	    
	    Implicit_Death_Anounce_Msg death(obj_id, msgsrc_site_id);
	    
	    msg_tree.add_implicit_msg(death);
 	  }
	  
	  break;
	default:
	  ERROR("*** ERROR: out of range!");
	}

    }
  
  // while there is messages in container to send.
  
  unsigned chunk_size;

  do
    {
      Site_Id 
	tgt_site_id(site_pool[get_rand(0,TOTAL_POOL_ELEMS - 1)]);
      
      chunk_size =  msg_tree.
	get_implicit_chunk(tgt_site_id, chunk_of_messages, CHUNK_SIZE);
      
      MESSAGE("chunk size = %i", chunk_size);
    }  while (*reinterpret_cast<unsigned*>(chunk_of_messages) != 0);


  return 0;
}
