// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file bin_search_tree_/rotate_fn_imps.hpp
 * Contains imps for rotating nodes.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
rotate_left(node_pointer p_x)
{
  node_pointer p_y = p_x->m_p_right;

  p_x->m_p_right = p_y->m_p_left;

  if (p_y->m_p_left != 0)
    p_y->m_p_left->m_p_parent = p_x;

  p_y->m_p_parent = p_x->m_p_parent;

  if (p_x == m_p_head->m_p_parent)
    m_p_head->m_p_parent = p_y;
  else if (p_x == p_x->m_p_parent->m_p_left)
    p_x->m_p_parent->m_p_left = p_y;
  else
    p_x->m_p_parent->m_p_right = p_y;

  p_y->m_p_left = p_x;
  p_x->m_p_parent = p_y;

  PB_DS_ASSERT_NODE_CONSISTENT(p_x)
  PB_DS_ASSERT_NODE_CONSISTENT(p_y)

  apply_update(p_x, (node_update* )this);
  apply_update(p_x->m_p_parent, (node_update* )this);
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
rotate_right(node_pointer p_x)
{
  node_pointer p_y = p_x->m_p_left;

  p_x->m_p_left = p_y->m_p_right;

  if (p_y->m_p_right != 0)
    p_y->m_p_right->m_p_parent = p_x;

  p_y->m_p_parent = p_x->m_p_parent;

  if (p_x == m_p_head->m_p_parent)
    m_p_head->m_p_parent = p_y;
  else if (p_x == p_x->m_p_parent->m_p_right)
    p_x->m_p_parent->m_p_right = p_y;
  else
    p_x->m_p_parent->m_p_left = p_y;

  p_y->m_p_right = p_x;
  p_x->m_p_parent = p_y;

  PB_DS_ASSERT_NODE_CONSISTENT(p_x)
  PB_DS_ASSERT_NODE_CONSISTENT(p_y)

  apply_update(p_x, (node_update* )this);
  apply_update(p_x->m_p_parent, (node_update* )this);
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
rotate_parent(node_pointer p_nd)
{
  node_pointer p_parent = p_nd->m_p_parent;

  if (p_nd == p_parent->m_p_left)
    rotate_right(p_parent);
  else
    rotate_left(p_parent);

  _GLIBCXX_DEBUG_ASSERT(p_parent->m_p_parent = p_nd);
  _GLIBCXX_DEBUG_ASSERT(p_nd->m_p_left == p_parent ||
		   p_nd->m_p_right == p_parent);
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
apply_update(node_pointer /*p_nd*/, null_node_update_pointer /*p_update*/)
{ }

PB_DS_CLASS_T_DEC
template<typename Node_Update_>
inline void
PB_DS_CLASS_C_DEC::
apply_update(node_pointer p_nd, Node_Update_*  /*p_update*/)
{
  node_update::operator()(node_iterator(p_nd),
			  node_const_iterator(static_cast<node_pointer>(0)));
}

PB_DS_CLASS_T_DEC
template<typename Node_Update_>
inline void
PB_DS_CLASS_C_DEC::
update_to_top(node_pointer p_nd, Node_Update_* p_update)
{
  while (p_nd != m_p_head)
    {
      apply_update(p_nd, p_update);

      p_nd = p_nd->m_p_parent;
    }
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
update_to_top(node_pointer /*p_nd*/, null_node_update_pointer /*p_update*/)
{ }

#endif
