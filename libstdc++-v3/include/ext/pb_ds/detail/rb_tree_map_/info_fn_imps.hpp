// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file rb_tree_map_/info_fn_imps.hpp
 * Contains an implementation for rb_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline bool
PB_DS_CLASS_C_DEC::
is_effectively_black(const node_pointer p_nd)
{ return (p_nd == 0 || !p_nd->m_red); }

#endif
