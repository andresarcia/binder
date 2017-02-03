# ifndef GRAPH_CONTANIER
# define GRAPH_CONTANIER

# define STR_SIZE_FOR_CODES 20

# include <gtk--/window.h>
# include <gtk--/scrolledwindow.h>
# include <gtk--/clist.h>
# include <gtk--/box.h>
# include <gtk--/adjustment.h>
# include <gtk--/progressbar.h>
# include <gtk--/button.h>
# include <gtk--/label.h>
# include <gtk--/main.h>
# include <iostream>
# include <map>
# include <fstream>
# include <vector>
# include <unistd.h>
# include "uid.H"
# include <useMutex.H>

void button_start_clicked();

static const gchar *objects_title[] = 
 { "Objeto", "Estado", "# Invocaciones", "Estampilla", NULL};

static const gchar *references_title[] = 
 { "Referencia", "Sitio", "# Invocaciones", "# Fallas", NULL};

using namespace std;  

class Event_Window : public Gtk::Window
{
  Gtk::CList * obj_list;
  Gtk::CList * ref_list;
  Gtk::ScrolledWindow * obj_scrl_wnd;
  Gtk::ScrolledWindow * ref_scrl_wnd;
  Gtk::VBox *vbox;
  Gtk::VBox *vbox_labels;
  Gtk::HBox *hbox;
  Gtk::Button *start_button;
  Gtk::Label cont_name, fallas, invoc;
  Gtk::Adjustment  process_perc;
  Gtk::ProgressBar process_bar;
  int total_tries;
  pthread_mutex_t window_mutex;

  map<string, string> host_name_map;
  
  void insert_row(Gtk::CList * clist, 
		  void * row_code, 
		  vector<Gtk::string> & row_data)
  {
    CRITICAL_SECTION(window_mutex);

    ASSERT(clist != NULL);
    ASSERT(row_code != NULL);
    
    clist->rows().push_back(row_data);
    clist->rows().back().set_data(row_code);
  }
  
  void delete_row(Gtk::CList * clist, 
		  void * row_code)
  {
    CRITICAL_SECTION(window_mutex);

    ASSERT(clist->rows().find_data(row_code) != clist->rows().end());
    
    clist->rows().erase(clist->rows().find_data(row_code));
  }

  void modify_field(Gtk::CList * clist, 
		    void * row_code,
		    const int field_number,
		    const char * new_text)
  {
    ASSERT(clist->rows().find_data(row_code) != clist->rows().end());
    
    Gtk::CList_Helpers::RowIterator 
      iter =  clist->rows().find_data(row_code);
    
    int row = iter->get_row_num();

    ASSERT(row >= 0);

    clist->cell(row,field_number).set_text(const_cast<char*>(new_text));
  }

  void add_one(Gtk::CList * clist, 
	       void * row_code,
	       const int field_number)
  {
    CRITICAL_SECTION(window_mutex);

    ASSERT(row_code != NULL);

    char str_num_inv[10];

    get_field(clist, row_code, field_number, str_num_inv);

    int plus_inv = atoi(str_num_inv) + 1;

    sprintf(str_num_inv, "%i", plus_inv);

    modify_field(clist, row_code, field_number, str_num_inv);
  }

  void get_field(Gtk::CList * clist, 
		 void * row_code,
		 const int field_number,
		 char * out_text)
  {
    ASSERT(clist->rows().find_data(row_code) != clist->rows().end());
    
    Gtk::CList_Helpers::RowIterator iter = 
      clist->rows().find_data(row_code);
    
    int row = iter->get_row_num();
    
    ASSERT(row >= 0);
    
    string text = clist->cell(row,field_number).get_text();
    
    strcpy(out_text, text.c_str());
  }		

  void get_host_name(char * host_name, const char * input_code)
  {
    string site(input_code, 4, 4);

    strcpy(host_name, host_name_map[site].c_str());
  }

# define MAX_HOST_NAME_SIZE 20

  void get_uid_name(char * short_uid_str, const char * input_code)
  {
    char host_name[MAX_HOST_NAME_SIZE];

    get_host_name(host_name, input_code);

    Uid uid(const_cast<char*>(input_code));

    string out_str(host_name);
    
    char str_num[20];

    sprintf(str_num,"%li",static_cast<long>(uid.get_counter()));
    
    out_str+=string(str_num);

    strcpy(short_uid_str, out_str.c_str());
  }

# undef MAX_HOST_NAME_SIZE

  void empty_fct()
  {
    // empty
  }

public:
  Event_Window(const int _total_tries) :
    Gtk::Window(GTK_WINDOW_TOPLEVEL),
    obj_list(manage(new Gtk::CList(objects_title))),
    ref_list(manage(new Gtk::CList(references_title))),
    obj_scrl_wnd(manage(new Gtk::ScrolledWindow())),
    ref_scrl_wnd(manage(new Gtk::ScrolledWindow())),
    vbox(manage(new Gtk::VBox(false, 5))),
    vbox_labels(manage(new Gtk::VBox(false))),
    hbox(manage(new Gtk::HBox(false))),
    start_button(manage(new Gtk::Button("Empezar"))),
    process_perc(0,0,1000,1.0),
    process_bar(process_perc),
    total_tries(_total_tries)
  {
    pthread_mutex_init(&window_mutex, NULL);

    obj_list->set_shadow_type(GTK_SHADOW_OUT);
    obj_list->set_column_width(0, 100);
    obj_list->set_column_width(1, 100);
    obj_list->set_column_width(2, 100);
    obj_list->set_column_width(3, 100);
    
    ref_list->set_shadow_type(GTK_SHADOW_OUT);
    ref_list->set_column_width(0, 150);
    ref_list->set_column_width(1, 150);
    ref_list->set_column_width(2, 100);
    ref_list->set_column_width(3, 50);
    
    obj_scrl_wnd->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    ref_scrl_wnd->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    
    obj_scrl_wnd->add(*obj_list);
    ref_scrl_wnd->add(*ref_list);
 
    char host_name[50];
    gethostname(host_name, 50);
    cout << host_name << endl;
    cont_name.set_text(host_name);
        
    vbox->set_border_width(5);
    vbox->pack_start(cont_name);
    vbox->pack_start(*obj_scrl_wnd);
    vbox->pack_start(*ref_scrl_wnd);
   
    start_button->clicked.connect(SigC::slot(button_start_clicked));
    start_button->set_usize(20,12);
  
    fallas.set_text("Fallas: 0");
    invoc.set_text("Invoc: 0");
    vbox_labels->pack_start(invoc);
    vbox_labels->pack_start(fallas);

    hbox->pack_start(*start_button);
    hbox->pack_start(*vbox_labels);
    hbox->pack_start(process_bar);

    process_bar.set_show_text(true);
    process_bar.set_activity_step(1);

    float ti = total_tries;
    
    process_perc.set_upper(ti);

    vbox->pack_start(*hbox);

    destroy.connect(Gtk::Main::quit.slot());
    set_usize(300, 150);
    set_policy(FALSE, FALSE, TRUE); // no user resizable
    add(*vbox);

    set_usize (550, 300);

    show_all();
    
    ifstream name_map("../name_map.txt");

    string code, name;
    
    while(!name_map.eof())
      {
	name_map >> name >> code;
	host_name_map[code] = name;
      }
  }

  void insert_object(const char * unique_object_name, 
		     void * row_code,
		     const char * state,
		     const int timestamp)
		     
  {
    vector<Gtk::string> row_v;

    ASSERT(unique_object_name != NULL);
    ASSERT(state != NULL);
    ASSERT(row_code != NULL);

    char obj_code[STR_SIZE_FOR_CODES];

    char txt_int[10];

    sprintf(txt_int,"%i",timestamp);

    get_uid_name(obj_code, unique_object_name);

    row_v.push_back(obj_code);
    row_v.push_back(state);
    row_v.push_back("0");
    row_v.push_back(txt_int);

    insert_row(obj_list, row_code, row_v);
  }

  void insert_reference(const char * unique_reference_name, 
			void * row_code,
			const char * state)
  {
    vector<Gtk::string> row_v;

    ASSERT(unique_reference_name != NULL);
    ASSERT(state != NULL);
    ASSERT(row_code != NULL);
   
    char ref_code[STR_SIZE_FOR_CODES];

    get_uid_name(ref_code, unique_reference_name);

    row_v.push_back(ref_code);
    row_v.push_back(state);
    row_v.push_back("0");
    row_v.push_back("0");

    insert_row(ref_list, row_code, row_v);
  }

  void change_obj_state(void * row_code,
			const char * new_state)
  {
    ASSERT(row_code != NULL);

    modify_field(obj_list, row_code, 1, new_state);
  }

  void add_obj_invocation(void * row_code)
  {
    add_one(obj_list, row_code, 2);
  }

  void change_ref_state(void * row_code,
			const char * new_state)
  {
    ASSERT(row_code != NULL);

    modify_field(ref_list, row_code, 1, new_state);
  }

  void add_ref_invocation(void * row_code)
  {
    add_one(ref_list, row_code, 2);
  }

  void add_ref_fail(void * row_code)
  {
    add_one(ref_list, row_code, 3);
  }

  void delete_object(void * row_code)
  {
    ASSERT(row_code != NULL);

    delete_row(obj_list, row_code);
  }

  void update_process(const int curr_tries)
  {
    ASSERT(curr_tries >= 0);
    ASSERT(curr_tries <= total_tries);

    float ct = curr_tries;
    
    process_perc.set_value(ct);
    
    //container->show_all();
  }
  
  void update_statistics(const int n_invoc, const int n_fails)
  {
    char text[50];
    
    sprintf(text, "Fallas: %i", n_fails);
    fallas.set_text(text);

    sprintf(text, "Invoc: %i", n_invoc);
    invoc.set_text(text);
  }
  
  void disable_button()
  {
    start_button->clicked.connect(SigC::slot(this,&Event_Window::empty_fct));
  }
};


Event_Window * prc_window;

# undef STR_SIZE_FOR_CODES

#endif


