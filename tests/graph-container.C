# include <gtk--/window.h>
# include <gtk--/scrolledwindow.h>
# include <gtk--/clist.h>
# include <gtk--/box.h>
# include <gtk--/button.h>
# include <gtk--/main.h>
# include <iostream>

# include "graph-container.H"
# include "gcontainer.H"
# include "gcont_mig.H"
# include "gcont_refs.H"
# include "gcont_objs.H"

using namespace std;

int main(int argc, char *argv[])
{
  Gtk::Main main(argc, argv);

  Event_Window ew;

  prc_window = &ew;

  prc_window->show_all();
  
  main.run();
  return 0;
}
