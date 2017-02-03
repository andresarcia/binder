#include <iostream>
#include <fstream>
#include <map>
//#include "uid.H"

char * input_code = "GJJLDIEOKAKBAAAAIAAAAAAAAAAAAAAANIAJMCDCAAAAAAAA";

using namespace std;

map<string, string> host_name;

void get_host_name(char * host_name, const char * input_code)
{
  string site(input_code, 4, 4);
  
  strcpy(host_name, "host");
}

# define MAX_HOST_NAME_SIZE 20

void get_uid_name(char * short_uid_str, const char * input_code)
{
  char host_name[MAX_HOST_NAME_SIZE];
  
  get_host_name(host_name, input_code);
  
  //  Uid uid(const_cast<char*>(input_code));

  string out_str(host_name);
  
  char str_num[20];
  
  long counter = 19;

  sprintf(str_num,"%i",counter);
  
  out_str+=string(str_num);
  
  strcpy(short_uid_str, out_str.c_str());
}

# undef MAX_HOST_NAME_SIZE

int main()
{
  ifstream name_map("name_map.txt");

  string code, name;

  while(!name_map.eof())
    {
      name_map >> name >> code;
      host_name[code] = name;
      cout << code << " " << name << endl;
    }

  string site(input_code, 4, 4);

  char uid_name[30];

  get_uid_name(uid_name, input_code);

  cout << uid_name << endl;

  cout << host_name[site];
}
