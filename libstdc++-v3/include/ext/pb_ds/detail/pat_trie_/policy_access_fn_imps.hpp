// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pat_trie_/policy_access_fn_imps.hpp
 * Contains an implementation class for pat_trie.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::access_traits& 
PB_DS_CLASS_C_DEC::
get_access_traits()
{ return *this; }

PB_DS_CLASS_T_DEC
const typename PB_DS_CLASS_C_DEC::access_traits& 
PB_DS_CLASS_C_DEC::
get_access_traits() const
{ return *this; }

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::node_update& 
PB_DS_CLASS_C_DEC::
get_node_update()
{ return *this; }

PB_DS_CLASS_T_DEC
const typename PB_DS_CLASS_C_DEC::node_update& 
PB_DS_CLASS_C_DEC::
get_node_update() const
{ return *this; }
#endif
