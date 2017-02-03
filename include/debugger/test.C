#include <iostream>
#include "base_message_header.H"

using namespace std;
/*
typedef int (*fct_t)();

fct_t t;

class A 
{
 char data;

 public:
	static int f()
	{ 
		cout << "invoking f()" << " data =" << endl; 
	  	return 0; 
	}

   	A(char _data) :
	data(_data)
    {
		// empty
    }
};

int foo()
{
	cout << "foo";
}
*/
int main()
{
  /*	A a(1);

	t = A::f;

	(*t)();
  */
	cout << "Msg_Entry_Header =" << sizeof(Msg_Entry_Header) << endl;

	cout << "size_t =" << sizeof(size_t) << endl;

	cout << "unsigned int" << sizeof(unsigned int) << endl;

	cout << "unsigned" << sizeof(unsigned) << endl;

	cout << "long" << sizeof(long) << endl;
     
}

