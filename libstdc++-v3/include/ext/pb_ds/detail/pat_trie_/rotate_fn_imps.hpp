// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pat_trie_/rotate_fn_imps.hpp
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

  _GLIBCXX_DEBUG_ONLY(assert_node_consistent(p_x);)
  _GLIBCXX_DEBUG_ONLY(assert_node_consistent(p_y);)

  apply_update(p_x, (Node_Update*)this);
  apply_update(p_x->m_p_parent, (Node_Update*)this);
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

  _GLIBCXX_DEBUG_ONLY(assert_node_consistent(p_x);)
  _GLIBCXX_DEBUG_ONLY(assert_node_consistent(p_y);)

  apply_update(p_x, (Node_Update*)this);
  apply_update(p_x->m_p_parent, (Node_Update*)this);
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
  _GLIBCXX_DEBUG_ASSERT(p_nd->m_p_left == p_parent || p_nd->m_p_right == p_parent);
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
apply_update(node_pointer /*p_nd*/, __gnu_pbds::null_node_update*  /*p_update*/)
{ }

PB_DS_CLASS_T_DEC
template<typename Node_Update_>
inline void
PB_DS_CLASS_C_DEC::
apply_update(node_pointer p_nd, Node_Update_* p_update)
{
  p_update->operator()(& PB_DS_V2F(p_nd->m_value),(p_nd->m_p_left == 0) ?
			0 :
			& PB_DS_V2F(p_nd->m_p_left->m_value),(p_nd->m_p_right == 0) ?
			0 :
			& PB_DS_V2F(p_nd->m_p_right->m_value));
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
update_to_top(node_pointer /*p_nd*/, __gnu_pbds::null_node_update*  /*p_update*/)
{ }

#endif
