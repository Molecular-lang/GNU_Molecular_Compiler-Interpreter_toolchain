// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/policy_access_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s policy agpess
 * functions.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
Hash_Fn& 
PB_DS_CLASS_C_DEC::
get_hash_fn()
{ return *this; }

PB_DS_CLASS_T_DEC
const Hash_Fn& 
PB_DS_CLASS_C_DEC::
get_hash_fn() const
{ return *this; }

PB_DS_CLASS_T_DEC
Eq_Fn& 
PB_DS_CLASS_C_DEC::
get_eq_fn()
{ return *this; }

PB_DS_CLASS_T_DEC
const Eq_Fn& 
PB_DS_CLASS_C_DEC::
get_eq_fn() const
{ return *this; }

PB_DS_CLASS_T_DEC
Probe_Fn& 
PB_DS_CLASS_C_DEC::
get_probe_fn()
{ return *this; }

PB_DS_CLASS_T_DEC
const Probe_Fn& 
PB_DS_CLASS_C_DEC::
get_probe_fn() const
{ return *this; }

PB_DS_CLASS_T_DEC
Comb_Probe_Fn& 
PB_DS_CLASS_C_DEC::
get_comb_probe_fn()
{ return *this; }

PB_DS_CLASS_T_DEC
const Comb_Probe_Fn& 
PB_DS_CLASS_C_DEC::
get_comb_probe_fn() const
{ return *this; }

PB_DS_CLASS_T_DEC
Resize_Policy& 
PB_DS_CLASS_C_DEC::
get_resize_policy()
{ return *this; }

PB_DS_CLASS_T_DEC
const Resize_Policy& 
PB_DS_CLASS_C_DEC::
get_resize_policy() const
{ return *this; }
#endif
