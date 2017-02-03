#include "uid.H"
#include <aleph.H>
#include "protected_lhash.H"

class Uid_Bucket : 
  public ProtectedLhashTable<Uid>::Bucket
{
  // The container that is waiting for the response.
  // Remember that just one thread at time can do an invocation,
  // therefore the source container ID is always unique.
  Uid  otro_uid;

public:
  Uid_Bucket (Uid uid1, Uid uid2) :
    ProtectedLhashTable<Uid>::Bucket(uid1),
			      otro_uid(uid2)
  {
    // empty
  }
};

unsigned long my_hash_fct(const Uid & key)
{
  return static_cast<unsigned long>(key.get_random_number());
}

int main()
{
  Uid uid1, uid2;
  char strtmp[Uid::stringSize];

  MESSAGE("The bucket key: %s", uid1.getStringUid(strtmp, 
						   Uid::stringSize));

  ProtectedLhashTable<Uid> 
    protected_table(my_hash_fct);

  Uid_Bucket * a_bucket = AllocNew(*objectAlloc, Uid_Bucket)
    (uid1, uid2);

  protected_table.insert(a_bucket);

  a_bucket = static_cast<Uid_Bucket *>(protected_table.search(uid1));
  
  
  MESSAGE("The bucket key: %s", a_bucket->getKey().getStringUid(strtmp, 
								 Uid::stringSize));

  try 
    {
      a_bucket = static_cast<Uid_Bucket *>(protected_table.search(uid1));
    }
  catch (Lock)
    {
      a_bucket->unLock();
    }


  return 0;
}

