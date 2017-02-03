# include <aleph.H>
# include "port.H"
# include <iostream.h>
# include <ipcClient.H>


using namespace Aleph;

int main(int argc, char ** argv)
{
  Port port_id;

  char str[Port::stringSize];

  for (int i = 0; i < 40; i++)
    {
      createUid(&port_id);
      
      cout << "\"" << port_id.getStringUid(str, Port::stringSize) << "\"" << endl;
    }

  return 0;
}
