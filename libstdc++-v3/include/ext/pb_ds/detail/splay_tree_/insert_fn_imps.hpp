// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file splay_tree_/insert_fn_imps.hpp
 * Contains an implementation class for splay_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline std::pair<typename PB_DS_CLASS_C_DEC::point_iterator, bool>
PB_DS_CLASS_C_DEC::
insert(const_reference r_value)
{
  PB_DS_ASSERT_VALID((*this))
  std::pair<point_iterator, bool> ins_pair = insert_leaf_imp(r_value);
  ins_pair.first.m_p_nd->m_special = false;
  PB_DS_ASSERT_VALID((*this))
  splay(ins_pair.first.m_p_nd);
  PB_DS_ASSERT_VALID((*this))
  return ins_pair;
}

PB_DS_CLASS_T_DEC
inline std::pair<typename PB_DS_CLASS_C_DEC::point_iterator, bool>
PB_DS_CLASS_C_DEC::
insert_leaf_imp(const_reference r_value)
{
  _GLIBCXX_DEBUG_ONLY(base_type::structure_only_assert_valid(__FILE__,
							     __LINE__);)
  if (base_type::m_size == 0)
    return std::make_pair(base_type::insert_imp_empty(r_value), true);

  node_pointer p_nd = base_type::m_p_head->m_p_parent;
  node_pointer p_pot = base_type::m_p_head;

  while (p_nd != 0)
    if (!Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value), PB_DS_V2F(r_value)))
      {
	if (!Cmp_Fn::operator()(PB_DS_V2F(r_value), PB_DS_V2F(p_nd->m_value)))
	  {
	    return std::make_pair(point_iterator(p_nd), false);
	  }
	p_pot = p_nd;
	p_nd = p_nd->m_p_left;
      }
    else
      p_nd = p_nd->m_p_right;

  if (p_pot == base_type::m_p_head)
    return std::make_pair(base_type::insert_leaf_new(r_value, base_type::m_p_head->m_p_right, false), true);

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(PB_DS_V2F(r_value))

  p_nd = p_pot->m_p_left;
  if (p_nd == 0)
    return (std::make_pair(base_type::insert_leaf_new(r_value, p_pot, true), true));

  while (p_nd->m_p_right != 0)
    p_nd = p_nd->m_p_right;

  return std::make_pair(this->insert_leaf_new(r_value, p_nd, false), true);
}
#endif
