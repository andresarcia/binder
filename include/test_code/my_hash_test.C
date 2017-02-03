#include "my_tpl_lhash.H"

struct data : public tplLhashTable<int>::Bucket
{
  int data;

  data(int _key, int _data) : 
    tplLhashTable<int>::Bucket(_key),
			data(_data)
  {
    // empty
  }
};

unsigned long hash_fct(unsigned long key)
{
  return key;
}

int main()
{
  lhashTable<int> table(hash_fct);

  for (int i=0; i<1000; i++)
    {
      Data data((i%2)+1, i);
      
      table.insert(data);
    }

  Data * searched_data = table.search(1),
    * cursor;

  cursor = searched_data;
  
  while (cursor != NULL)
    {
      cout << "Key: 1 " << "Data: " << cursor->data << endl;
      cursor = table.get_next(cursor);
    }

  return 0;
}



