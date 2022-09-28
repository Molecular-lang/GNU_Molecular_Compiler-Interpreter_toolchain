// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pat_trie_/update_fn_imps.hpp
 * Contains an implementation class for pat_trie_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
apply_update(node_pointer, null_node_update_pointer)
{ }

PB_DS_CLASS_T_DEC
template<typename Node_Update_>
inline void
PB_DS_CLASS_C_DEC::
apply_update(node_pointer p_nd, Node_Update_*)
{
  Node_Update_::operator()(node_iterator(p_nd, this),
			   node_const_iterator(0, this));
}
#endif
