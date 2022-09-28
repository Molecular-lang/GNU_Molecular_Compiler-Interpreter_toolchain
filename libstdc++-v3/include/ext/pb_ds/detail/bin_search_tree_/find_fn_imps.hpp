// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file bin_search_tree_/find_fn_imps.hpp
 * Contains an implementation class for bin_search_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
lower_bound(key_const_reference r_key) const
{
  node_pointer p_pot = m_p_head;
  node_pointer p_nd = m_p_head->m_p_parent;

  while (p_nd != 0)
    if (Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value), r_key))
      p_nd = p_nd->m_p_right;
    else
      {
	p_pot = p_nd;
	p_nd = p_nd->m_p_left;
      }
  return iterator(p_pot);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
lower_bound(key_const_reference r_key)
{
  node_pointer p_pot = m_p_head;
  node_pointer p_nd = m_p_head->m_p_parent;

  while (p_nd != 0)
    if (Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value), r_key))
      p_nd = p_nd->m_p_right;
    else
      {
	p_pot = p_nd;
	p_nd = p_nd->m_p_left;
      }
  return iterator(p_pot);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
upper_bound(key_const_reference r_key) const
{
  node_pointer p_pot = m_p_head;
  node_pointer p_nd = m_p_head->m_p_parent;

  while (p_nd != 0)
    if (Cmp_Fn::operator()(r_key, PB_DS_V2F(p_nd->m_value)))
      {
	p_pot = p_nd;
	p_nd = p_nd->m_p_left;
      }
    else
      p_nd = p_nd->m_p_right;
  return const_iterator(p_pot);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
upper_bound(key_const_reference r_key)
{
  node_pointer p_pot = m_p_head;
  node_pointer p_nd = m_p_head->m_p_parent;

  while (p_nd != 0)
    if (Cmp_Fn::operator()(r_key, PB_DS_V2F(p_nd->m_value)))
      {
	p_pot = p_nd;
	p_nd = p_nd->m_p_left;
      }
    else
      p_nd = p_nd->m_p_right;
  return point_iterator(p_pot);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
find(key_const_reference r_key)
{
  PB_DS_STRUCT_ONLY_ASSERT_VALID((*this))
  node_pointer p_pot = m_p_head;
  node_pointer p_nd = m_p_head->m_p_parent;

  while (p_nd != 0)
    if (!Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value), r_key))
      {
	p_pot = p_nd;
	p_nd = p_nd->m_p_left;
      }
    else
      p_nd = p_nd->m_p_right;

  node_pointer ret = p_pot;
  if (p_pot != m_p_head)
    {
      const bool __cmp = Cmp_Fn::operator()(r_key, PB_DS_V2F(p_pot->m_value));
      if (__cmp)
	ret = m_p_head;
    }
  return point_iterator(ret);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
find(key_const_reference r_key) const
{
  PB_DS_STRUCT_ONLY_ASSERT_VALID((*this))
  node_pointer p_pot = m_p_head;
  node_pointer p_nd = m_p_head->m_p_parent;

  while (p_nd != 0)
    if (!Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value), r_key))
      {
	p_pot = p_nd;
	p_nd = p_nd->m_p_left;
      }
    else
      p_nd = p_nd->m_p_right;

  node_pointer ret = p_pot;
  if (p_pot != m_p_head)
    {
      const bool __cmp = Cmp_Fn::operator()(r_key, PB_DS_V2F(p_pot->m_value));
      if (__cmp)
	ret = m_p_head;
    }
  return point_const_iterator(ret);
}
#endif
