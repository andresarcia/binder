# include "ipcClient.H"
# include "remote_access_point.H"

static ssize_t readn_f(Deamon_Locator * deamon_loc, void *in_buffer, size_t n)
{
  char  incomming_buffer[4096];

  RawMsg incomming_message(&incomming_buffer[0], 4096, 
			   RawMsg::DEFAULT_FLAG, 10000);

  MsgId reply_msg_id = static_cast<Remote_Locator *>(deamon_loc)->
    get_deamon_link()->receive_reply(incomming_message);

  MESSAGE("n = %i, BodySize = %i", n, incomming_message.getBodySize()); 

  ASSERT(n == incomming_message.getBodySize());

  memcpy(in_buffer, incomming_message.getBodyAddr(), n);

  return incomming_message.getBodySize();
}

static 
ssize_t writen_f(Deamon_Locator * deamon_loc, const void *out_buffer, size_t n)
{
  RawMsg outgoing_message(const_cast<void*>(out_buffer), n, 
			  RawMsg::DEFAULT_FLAG, 10000);

  static_cast<Remote_Locator *>(deamon_loc)->    
    get_deamon_link()->send_request(outgoing_message);

  return(n);
}


Remote_Access_Point::Remote_Access_Point(Remote_Locator & _deamon_loc,
					 unsigned int _no_of_services,
					 GenAlloc&    _alloc)
  : Access_Point(_no_of_services, readn_f, writen_f, _alloc)
{
  ASSERT(number_of_services > 0);

  ptr_access_point = AllocNew(alloc, IpcRemoteClient)
    (_deamon_loc.get_remote_server_port());

  link_to_deamon = AllocNew(alloc, Remote_Locator)
    (_deamon_loc);

  static_cast<Remote_Locator *>(link_to_deamon)
    ->set_deamon_link(ptr_access_point);

  MESSAGE("Client has made a connection");
}

Remote_Access_Point::Remote_Access_Point(Remote_Locator _deamon_loc,
					 unsigned int _no_of_services,
					 GenAlloc&    _alloc)
  : Access_Point(_no_of_services, readn_f, writen_f, _alloc)
{
  ASSERT(number_of_services > 0);

  ptr_access_point = AllocNew(alloc, IpcRemoteClient)
    (_deamon_loc.get_remote_server_port());

  link_to_deamon = AllocNew(alloc, Remote_Locator)
    (_deamon_loc);

  static_cast<Remote_Locator *>(link_to_deamon)
    ->set_deamon_link(ptr_access_point);

  MESSAGE("Client has made a connection");
}


void Remote_Access_Point::shutdown()
{
  MESSAGE("destroying remote access point");
  AllocDelete(alloc, ptr_access_point);  
  AllocDelete(alloc, link_to_deamon);
}

Remote_Access_Point::~Remote_Access_Point()
{
  shutdown();
}












