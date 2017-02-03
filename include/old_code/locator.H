# ifndef LOCATOR_CALLS_H
# define LOCATOR_CALLS_H

# include <ahExceptions.H>
# include <binder.H>

extern status register_cnt(const CntId & cnt_id) throw (lista);

unregister_cnt(const CntId & cnt_id);

register_obj(ObjId obj_id, CntId cnt_id);

unregister_obj(ObjId obj_id);
tgt_reg_mig_obj(ObjId obj_id, CntId cnt_id);
src_unreg_mig_obj(ObjId obj_id, SiteId tgt_site_id);
tgt_reg_mig_cnt(CntId cnt_id);
src_unreg_mig_cnt(CntId cnt_id, SiteId tgt_site_id);

Locator strong_locate(ObjId obj_id);
Locator weak_locate(ObjId obj_id, Binding old_binding);
Locator implicit_locate(ObjId obj_id, Binding old_binding);

MsgId clt_invoke_send(Binding binding, RawMsg request);
clt_invoke_receive(MsgId msg_id, Binding& binding, RawMsg& reply);
srv_invoke_receive(Binding binding, RawMsg request);
srv_invoke_reply(Binding binding, RawMsg reply);
};


# endif //  LOCATOR_CALLS_H
