// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file bin_search_tree_/insert_fn_imps.hpp
 * Contains an implementation class for bin_search_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline std::pair<typename PB_DS_CLASS_C_DEC::point_iterator, bool>
PB_DS_CLASS_C_DEC::
insert_leaf(const_reference r_value)
{
  PB_DS_STRUCT_ONLY_ASSERT_VALID((*this))

  if (m_size == 0)
    return std::make_pair(insert_imp_empty(r_value),
			  true);

  node_pointer p_nd = m_p_head->m_p_parent;
  node_pointer p_pot = m_p_head;

  while (p_nd != 0)
    if (!Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value),
			    PB_DS_V2F(r_value)))
      {
	p_pot = p_nd;

	p_nd = p_nd->m_p_left;
      }
    else
      p_nd = p_nd->m_p_right;

  if (p_pot == m_p_head)
    return std::make_pair(insert_leaf_new(r_value, m_p_head->m_p_right, false),
			  true);

  if (!Cmp_Fn::operator()(PB_DS_V2F(r_value),
			  PB_DS_V2F(p_pot->m_value)))
    {
      PB_DS_STRUCT_ONLY_ASSERT_VALID((*this))
      PB_DS_CHECK_KEY_EXISTS(PB_DS_V2F(r_value))
      return std::make_pair(p_pot, false);
    }

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(PB_DS_V2F(r_value))

  p_nd = p_pot->m_p_left;
  if (p_nd == 0)
    return std::make_pair(insert_leaf_new(r_value, p_pot, true),
			  true);

  while (p_nd->m_p_right != 0)
    p_nd = p_nd->m_p_right;

  return std::make_pair(insert_leaf_new(r_value, p_nd, false),
			true);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
insert_leaf_new(const_reference r_value, node_pointer p_nd, bool left_nd)
{
  node_pointer p_new_nd =
    get_new_node_for_leaf_insert(r_value,
				 traits_base::m_no_throw_copies_indicator);

  if (left_nd)
    {
      _GLIBCXX_DEBUG_ASSERT(p_nd->m_p_left == 0);
      _GLIBCXX_DEBUG_ASSERT(Cmp_Fn::operator()(PB_DS_V2F(r_value),
					       PB_DS_V2F(p_nd->m_value)));

      p_nd->m_p_left = p_new_nd;
      if (m_p_head->m_p_left == p_nd)
	m_p_head->m_p_left = p_new_nd;
    }
  else
    {
      _GLIBCXX_DEBUG_ASSERT(p_nd->m_p_right == 0);
      _GLIBCXX_DEBUG_ASSERT(Cmp_Fn::operator()(PB_DS_V2F(p_nd->m_value),
					       PB_DS_V2F(r_value)));

      p_nd->m_p_right = p_new_nd;
      if (m_p_head->m_p_right == p_nd)
	m_p_head->m_p_right = p_new_nd;
    }

  p_new_nd->m_p_parent = p_nd;
  p_new_nd->m_p_left = p_new_nd->m_p_right = 0;
  PB_DS_ASSERT_NODE_CONSISTENT(p_nd)

  update_to_top(p_new_nd, (node_update* )this);
  _GLIBCXX_DEBUG_ONLY(debug_base::insert_new(PB_DS_V2F(r_value));)
  return iterator(p_new_nd);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
insert_imp_empty(const_reference r_value)
{
  node_pointer p_new_node =
    get_new_node_for_leaf_insert(r_value, traits_base::m_no_throw_copies_indicator);

  m_p_head->m_p_left = m_p_head->m_p_right =
    m_p_head->m_p_parent = p_new_node;

  p_new_node->m_p_parent = m_p_head;
  p_new_node->m_p_left = p_new_node->m_p_right = 0;
  _GLIBCXX_DEBUG_ONLY(debug_base::insert_new(PB_DS_V2F(r_value));)

  update_to_top(m_p_head->m_p_parent, (node_update*)this);
  return iterator(p_new_node);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_pointer
PB_DS_CLASS_C_DEC::
get_new_node_for_leaf_insert(const_reference r_val, false_type)
{
  node_pointer p_new_nd = s_node_allocator.allocate(1);
  cond_dealtor_t cond(p_new_nd);

  new (const_cast<void* >(static_cast<const void* >(&p_new_nd->m_value)))
    typename node::value_type(r_val);

  cond.set_no_action();
  p_new_nd->m_p_left = p_new_nd->m_p_right = 0;
  ++m_size;
  return p_new_nd;
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_pointer
PB_DS_CLASS_C_DEC::
get_new_node_for_leaf_insert(const_reference r_val, true_type)
{
  node_pointer p_new_nd = s_node_allocator.allocate(1);

  new (const_cast<void* >(static_cast<const void* >(&p_new_nd->m_value)))
    typename node::value_type(r_val);

  p_new_nd->m_p_left = p_new_nd->m_p_right = 0;
  ++m_size;
  return p_new_nd;
}
#endif
