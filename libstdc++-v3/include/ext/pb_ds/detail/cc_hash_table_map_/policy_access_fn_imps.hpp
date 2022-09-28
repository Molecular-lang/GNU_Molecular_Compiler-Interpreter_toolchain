// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/policy_access_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s policy access
 *    functions.
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
Comb_Hash_Fn& 
PB_DS_CLASS_C_DEC::
get_comb_hash_fn()
{ return *this; }

PB_DS_CLASS_T_DEC
const Comb_Hash_Fn& 
PB_DS_CLASS_C_DEC::
get_comb_hash_fn() const
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
