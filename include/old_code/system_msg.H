# ifndef SYSTEM_MSG_H
# define SYSTEM_MSG_H

# include <message_header.H>

# ifdef CODE_FOR_CLIENT
# include <client_communication.H>
# endif // CODE_FOR_CLIENT

class Create_Unique_Id_Message : public Locator_Call_Header
{
 public:
 Create_Unique_Id_Message () :
  Locator_Call_Header(CREATE_UNIQUE_ID)
   {
     // empty
   }
};


class Unique_Id_Message : public Locator_Reply_Header
{
  Logical_Timestamp logical_timestamp;
  Random_Number     random_num;

 public:
  
  // TODO: cambiar a referencia
  Unique_Id_Message (Logical_Timestamp time_st,  // it's not a reference! 
		    Random_Number & rand_num) :
    Locator_Reply_Header(OK),
    logical_timestamp(time_st),
    random_num(rand_num)
   {
     // empty
   }

 Unique_Id_Message ()
    {
      // empty
    }

 Logical_Timestamp get_logical_timestamp() const
   { 
     return logical_timestamp; 
   }

 Random_Number get_random_number() const
   {
     return random_num;
   }
};
 
# endif //SYSTEM_MSG_H

















