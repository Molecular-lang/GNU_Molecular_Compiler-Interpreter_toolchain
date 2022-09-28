// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file splay_tree_/find_fn_imps.hpp
 * Contains an implementation class for splay_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
find(key_const_reference r_key)
{
  node_pointer p_found = find_imp(r_key);
  if (p_found != base_type::m_p_head)
    splay(p_found);
  return point_iterator(p_found);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
find(key_const_reference r_key) const
{
  const node_pointer p_found = find_imp(r_key);
  if (p_found != base_type::m_p_head)
    const_cast<PB_DS_CLASS_C_DEC* >(this)->splay(p_found);
  return point_iterator(p_found);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_pointer
PB_DS_CLASS_C_DEC::
find_imp(key_const_reference r_key)
{
  _GLIBCXX_DEBUG_ONLY(base_type::structure_only_assert_valid(__FILE__,
							     __LINE__);)
  node_pointer p_nd = base_type::m_p_head->m_p_parent;
  while (p_nd != 0)
    if (!Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value), r_key))
      {
	if (!Cmp_Fn::operator()(r_key, PB_DS_V2F(p_nd->m_value)))
	  return p_nd;
	p_nd = p_nd->m_p_left;
      }
    else
      p_nd = p_nd->m_p_right;
  return base_type::m_p_head;
}

PB_DS_CLASS_T_DEC
inline const typename PB_DS_CLASS_C_DEC::node_pointer
PB_DS_CLASS_C_DEC::
find_imp(key_const_reference r_key) const
{
  PB_DS_ASSERT_VALID((*this))
  node_pointer p_nd = base_type::m_p_head->m_p_parent;
  while (p_nd != 0)
    if (!Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value), r_key))
      {
	if (!Cmp_Fn::operator()(r_key, PB_DS_V2F(p_nd->m_value)))
	  return p_nd;
	p_nd = p_nd->m_p_left;
      }
    else
      p_nd = p_nd->m_p_right;
  return base_type::m_p_head;
}
#endif
