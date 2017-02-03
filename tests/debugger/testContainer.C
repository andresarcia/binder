# include "binder.H"
# include "message_header.H"
# include "locator_calls.H"

int main()
{
  Container_Id this_container;
  
  bootstrap_services();
  register_cnt(this_container);
}


