# include "locator_calls.H"
# include "port.H"

int main(int argc, char ** argv)
{
  if (argc == 1)
    {
      cout << "usage: ping_object <site_id> <object_id>" << endl;
      exit(0);
    }

  bootstrap_services();

  Site_Id rem_site_id(argv[1]);

  Object_Id rem_obj(argv[2]);

  Locator locator_to_test(rem_obj, rem_site_id);

  try
    {
      test_location(locator_to_test);
    }
  catch (NotFound)
    {
      MESSAGE(">>> The Object was not found <<<");
    }
  catch (ObjectDead)
    {
      MESSAGE(">>> The Object is dead <<<");
    }
  catch (...)
    {
      MESSAGE(">>> Unexpected exception <<<");
    }

  return 0;
}


