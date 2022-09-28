// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pairing_heap_/insert_fn_imps.hpp
 * Contains an implementation class for a pairing heap.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
push(const_reference r_val)
{
  PB_DS_ASSERT_VALID((*this))
  node_pointer p_new_nd = base_type::get_new_node_for_insert(r_val);
  push_imp(p_new_nd);
  PB_DS_ASSERT_VALID((*this))
  return point_iterator(p_new_nd);
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
push_imp(node_pointer p_nd)
{
  p_nd->m_p_l_child = 0;
  if (base_type::m_p_root == 0)
    {
      p_nd->m_p_next_sibling = p_nd->m_p_prev_or_parent = 0;
      base_type::m_p_root = p_nd;
    }
  else if (Cmp_Fn::operator()(base_type::m_p_root->m_value, p_nd->m_value))
    {
      p_nd->m_p_next_sibling = p_nd->m_p_prev_or_parent = 0;
      base_type::make_child_of(base_type::m_p_root, p_nd);
      PB_DS_ASSERT_NODE_CONSISTENT(p_nd, false)
      base_type::m_p_root = p_nd;
    }
  else
    {
      base_type::make_child_of(p_nd, base_type::m_p_root);
      PB_DS_ASSERT_NODE_CONSISTENT(base_type::m_p_root, false)
    }
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
modify(point_iterator it, const_reference r_new_val)
{
  PB_DS_ASSERT_VALID((*this))
  remove_node(it.m_p_nd);
  it.m_p_nd->m_value = r_new_val;
  push_imp(it.m_p_nd);
  PB_DS_ASSERT_VALID((*this))
}
#endif
