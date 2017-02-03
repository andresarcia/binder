void button_start_clicked()
{
  cout << "start clicked" << endl;
}

class Event_Window 
{
  static const gchar *objects_title[] = 
  { "Objeto", "Estado", NULL };
  static const gchar *references_title[] = 
  { "Referencia", "Sitio", "# Invocaciones", "# Fallas", NULL};
  
  Gtk::CList * obj_list;
  Gtk::CList * ref_list;
  Gtk::ScrolledWindow * obj_scrl_wnd;
  Gtk::ScrolledWindow * ref_scrl_wnd;
  Gtk::VBox *vbox;
  Gtk::Button *start_button;
  Gtk::Window *container;


public:
  Event_Window() :
    obj_list(manage(new Gtk::CList(objects_title))),
    ref_list(manage(new Gtk::CList(references_title))),
    obj_scrl_wnd(manage(new Gtk::ScrolledWindow())),
    ref_scrl_wnd(manage(new Gtk::ScrolledWindow()))
    vbox(manage(new Gtk::VBox(false, 5))),
    start_button(manage(new Gtk::Button("Empezar"))),
    container(manage(new Gtk::Window(GTK_WINDOW_TOPLEVEL)))
  {
    obj_list->set_shadow_type(GTK_SHADOW_OUT);
    obj_list->set_column_width(0, 100);
    obj_list->set_column_width(1, 100);
    
    ref_list->set_shadow_type(GTK_SHADOW_OUT);
    ref_list->set_column_width(0, 150);
    ref_list->set_column_width(1, 150);
    ref_list->set_column_width(2, 100);
    ref_list->set_column_width(3, 50);
    
    obj_scrl_wnd->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    ref_scrl_wnd->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    
    obj_scrl_wnd->add(*obj_list);
    ref_scrl_wnd->add(*ref_list);
    
    vbox->set_border_width(5);
    vbox->pack_start(*obj_scrl_wnd);
    vbox->pack_start(*ref_scrl_wnd);
   
    start_button->clicked.connect(SigC::slot(button_start_clicked));
    start_button->set_usize(20,12);
    
    vbox->pack_start(*start_button);
    
    container->destroy.connect(Gtk::Main::quit.slot());
    container->set_usize(300, 150);
    container->set_title("Informacion del Proceso");
    container->add(*vbox);

    container->set_usize (500, 300);
  }

};

static Event_Window * prc_window;
