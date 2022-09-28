// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file ov_tree_map_/policy_access_fn_imps.hpp
 * Contains an implementation class for ov_tree.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
Cmp_Fn& 
PB_DS_CLASS_C_DEC::
get_cmp_fn()
{ return *this; }

PB_DS_CLASS_T_DEC
const Cmp_Fn& 
PB_DS_CLASS_C_DEC::
get_cmp_fn() const
{ return *this; }
#endif
