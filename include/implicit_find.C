# include "locator_calls.H"
# include "port.H"

int main(int argc, char ** argv)
{
  if (argc == 1)
    {
      cout << "usage: implicit_find <site_id> <object_id> " 
	      "<logical_timestamp>" << endl;
      exit(0);
    }

  bootstrap_services();

  Site_Id rem_site_id(argv[1]);

  Object_Id rem_obj(argv[2]);

  Logical_Timestamp timestamp(atoi(argv[3]));

  Locator old_locator(rem_obj, rem_site_id, timestamp);

  Site_Id this_site_id(INVALID_SITE_ID);

  get_site_id(this_site_id);

  Container_Id this_container_id;

  register_cnt(this_container_id);

  Binding binding_to_update(old_locator, this_container_id, this_site_id);

  implicit_locate(binding_to_update);
  
  return 0;
}


