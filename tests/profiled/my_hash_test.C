#include "my_tpl_lhash.H"
#include <iostream>

struct Data : public LhashBucket<int>
{
  int data_member;

  Data(int _key, int _data) : 
    LhashBucket<int>(_key),
    data_member(_data)
  {
    // empty
  }
};

unsigned long hash_fct(const int & key)
{
  return key;
}

int main()
{
  LhashTable<int> table(hash_fct);
  
  int i;

  for (i=0; i<1000; i++)
    {
      Data * data = AllocNew(*objectAlloc, Data) ((i%2)+1, i);

      table.insert(data);

      data = AllocNew(*objectAlloc, Data) (12, i);      
      
      table.insert(data);
    }

 
  int counter = 0;

  for (i=1; i<=2; i++)
    {
      Data * searched_data = static_cast<Data*>(table.search(12)),
	* cursor;
      
      cursor = searched_data;
      
      do
	{
	  counter++;
	  
	  cout << "Key: <" << cursor->getKey() << "> Data: " << 
	    cursor->data_member << endl;
	 
	  cursor = static_cast<Data*>(table.searchPrev(cursor));
	
	}  while (cursor != searched_data);
    }

  cout << "Total number of records: " << counter << endl;
  return 0;
}


