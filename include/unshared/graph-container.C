namespace Aleph_Container {
static bool shutdown = false;
}

# include <aleph.H>
# include "graph-container.H"
# include "gcontainer.H"
# include "gcont_mig.H"
# include "gcont_refs.H"
# include "gcont_objs.H"

using namespace std;

void create_random_ref_set()
{
  // Obtain a random set of references.
  
  objs_file = fopen("../objects", "r");
  
  int n_obj_in_container, total_objects = 0;

  Site_Id site_id;

  Object_Id object_id;

  Locator_Node *loc_node;

  char read_string[80];

  Dlink locator_list;

  while (fscanf(objs_file, "%i", &n_obj_in_container) != EOF)
    {
      fscanf(objs_file, "%s", read_string);

      site_id = Site_Id(read_string);

      for (int obj = 0; obj < n_obj_in_container; obj ++)
	{
	  fscanf(objs_file, "%s", read_string);

	  object_id = Object_Id(read_string);

	  loc_node = AllocNew(*objectAlloc, Locator_Node)
	    (Locator(object_id, site_id));
	  
	  locator_list.insert(loc_node);
	  
	  total_objects ++;
	}
    }

  fclose(objs_file);

  int random_reference;

  char tmp_string[Uid::stringSize];

  for (int ref = 0; ref < n_refs; ref++)
    {
      random_reference = get_rand(1, total_objects);

      ASSERT(random_reference > 0 && random_reference <= total_objects);

      Dlink * cursor = locator_list.getNext();

      for (int node = 1; node < random_reference; node++)
	cursor = cursor->getNext();
     
      array_of_refs[ref] = static_cast<Locator_Node*>(cursor)->get_locator(); 

      prc_window->
	insert_reference(object_id.getStringUid(tmp_string, Uid::stringSize),
			 &array_of_refs[ref], "INVOCANDO");
      
      object_id = 
      	static_cast<Locator_Node*>(cursor)->get_locator().get_object_id();
    }

  while (locator_list.isEmpty() == false)
    AllocDelete(*objectAlloc, locator_list.removeNext());
}

void create_cnt_list()
{
  cnt_file = fopen("../containers", "r");
  
  Container_Id container_id;
 
  Port container_port;

  Container_Node * cnt_node;

  char read_string[80];

  while (fscanf(cnt_file, "%s", read_string) != EOF)
    {
      container_id = Container_Id(read_string);

      fscanf(cnt_file, "%s", read_string);

      container_port = Port(read_string);
      
      cnt_node = AllocNew(*objectAlloc, Container_Node)
	(container_id, container_port);
      
      cnt_list.append(cnt_node);
      
      ++n_cnts;
    }
}

void do_randomize()
{
  struct timeval current_time;

  gettimeofday(&current_time, NULL);

  srand(current_time.tv_usec);
}


void button_start_clicked()
{
  do_randomize();
    
  create_random_ref_set();

  create_cnt_list();

  // Launch threads
  pthread_t objects_thread, references_thread;

  pthread_create(&references_thread, NULL, references_function, &total_tries);

  pthread_create(&objects_thread, NULL, objects_function, NULL);
}


gint timer_callback()
  {
    prc_window->update_process(n_tries);

    prc_window->update_statistics(invocations, reinvocations);

    return n_tries < total_tries;
  }


int main(int argc, char *argv[])
{
  Gtk::Main container_main(argc, argv);
  
  total_tries = atoi(argv[4]);

  static Event_Window ew(total_tries);
  
  //  Gtk::Main::idle.connect(SigC::slot(idle_callback));
  Gtk::Main::timeout.connect(SigC::slot(timer_callback), 100);

  prc_window = &ew;
  
  
  // prc_window->show_all();
  if (argc == 1)
    {
      cout << "usage: container <#objs> <#refs> [first | no] <#times>" << endl;
      exit(0);
    }
  
  if (strcmp(argv[3], "first") == 0)
    {
      objs_file = fopen("../objects", "w");
      cnt_file = fopen("../containers", "w");
    }
  else
    {
      objs_file = fopen("../objects", "a");
      cnt_file = fopen("../containers", "a");
    }
  
  n_objs = atoi(argv[1]);
  
  n_refs = atoi(argv[2]);

  

  ASSERT (argc == 5);

  bootstrap_services(); // should be bootstrap_loc_client_services()

  array_of_refs = AllocNew(*objectAlloc, Locator) [n_refs];

  char tmp_string[Uid::stringSize];

  get_site_id(this_site);

  MESSAGE("Site ID: %s", this_site.getStringUid(tmp_string, 
						Uid::stringSize));

  fprintf(objs_file, "%i\n", n_objs);

  fprintf(objs_file, "%s\n", 
	  this_site.getStringUid(tmp_string, Uid::stringSize));
  
  Object_Id this_object;

  // REGISTRATION STAGE
  register_cnt(this_container);

  for (int obj_index = 0; obj_index < n_objs; obj_index ++)
    {
      register_obj(this_object, this_container);
      
      MESSAGE("Object #%i ID: %s", 
	      obj_index,
	      this_object.getStringUid(tmp_string, Uid::stringSize));
      
      fprintf(objs_file, "%s\n", 
	      this_object.getStringUid(tmp_string, Uid::stringSize));
      
      Object_Node * new_obj = 
	AllocNew(*objectAlloc, Object_Node) (this_object);
      
      objs_list.append(static_cast<Dlink*>(new_obj));

      prc_window->
	insert_object(this_object.getStringUid(tmp_string, Uid::stringSize),
		      new_obj, "ESPERANDO", 0);
      
    }

  fclose(objs_file);

  Migration_Service migration_service;

  migration_thread = migration_service.get_migration_point();

  fprintf(cnt_file, "%s\n", 
	  this_container.getStringUid(tmp_string, Uid::stringSize));
  
  fprintf(cnt_file, "%s\n", 
  	  migration_thread->
	  get_port().getStringUid(tmp_string, Uid::stringSize));

  fclose(cnt_file);


  // Wait for events to happen
  container_main.run();

  Aleph_Container::shutdown = true;

  // wait for container termination
  /*
    pthread_join(objects_thread, NULL);
  
    pthread_join(references_thread, NULL);
    
    migration_service.join_migration_service();
  */
  unregister_cnt(this_container);
  
  AllocDeleteArray(*objectAlloc, array_of_refs);

  return 0;
}
