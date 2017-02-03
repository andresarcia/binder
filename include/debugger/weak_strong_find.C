# include "locator_calls.H"
# include "port.H"

int main(int argc, char ** argv)
{
  if (argc != 2)
    {
      cout << "usage: ping_n_objs <# objects> <LRU | MRU | MIDDLE>" << endl;
      exit(0);
    }

  bootstrap_services();

  Object_Id searched_obj(argv[1]);

  Locator obj_location;

  try
    {
      obj_location = strong_locate(searched_obj);
    }
  catch (NotFound)
    {
      EXIT("The object was not found");
    }
  catch (ObjectDead)
    {
      EXIT("The object is dead");
    }

  char tmp_string[Uid::stringSize];

  MESSAGE("The object location: %s", obj_location.get_target_site_id().
	  getStringUid(tmp_string, Uid::stringSize));
}

