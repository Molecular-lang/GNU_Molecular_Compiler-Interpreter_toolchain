// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file splay_tree_/split_join_fn_imps.hpp
 * Contains an implementation class for splay_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
join(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
  if (base_type::join_prep(other) == false)
    {
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return;
    }

  node_pointer p_target_r = other.leftmost(other.m_p_head);
  _GLIBCXX_DEBUG_ASSERT(p_target_r != 0);
  other.splay(p_target_r);

  _GLIBCXX_DEBUG_ASSERT(p_target_r == other.m_p_head->m_p_parent);
  _GLIBCXX_DEBUG_ASSERT(p_target_r->m_p_left == 0);

  p_target_r->m_p_left = base_type::m_p_head->m_p_parent;

  _GLIBCXX_DEBUG_ASSERT(p_target_r->m_p_left != 0);
  p_target_r->m_p_left->m_p_parent = p_target_r;

  base_type::m_p_head->m_p_parent = p_target_r;
  p_target_r->m_p_parent = base_type::m_p_head;

  this->apply_update(p_target_r, (node_update*)this);
  base_type::join_finish(other);

  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
split(key_const_reference r_key, PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)

  if (base_type::split_prep(r_key, other) == false)
    {
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return;
    }

  node_pointer p_upper_bound = this->upper_bound(r_key).m_p_nd;
  _GLIBCXX_DEBUG_ASSERT(p_upper_bound != 0);

  splay(p_upper_bound);
  _GLIBCXX_DEBUG_ASSERT(p_upper_bound->m_p_parent == this->m_p_head);

  node_pointer p_new_root = p_upper_bound->m_p_left;
  _GLIBCXX_DEBUG_ASSERT(p_new_root != 0);

  base_type::m_p_head->m_p_parent = p_new_root;
  p_new_root->m_p_parent = base_type::m_p_head;
  other.m_p_head->m_p_parent = p_upper_bound;
  p_upper_bound->m_p_parent = other.m_p_head;
  p_upper_bound->m_p_left = 0;
  this->apply_update(p_upper_bound, (node_update*)this);
  base_type::split_finish(other);

  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

#endif
