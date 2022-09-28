// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binomial_heap_base_/erase_fn_imps.hpp
 * Contains an implementation class for a base of binomial heaps.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
pop()
{
  PB_DS_ASSERT_VALID_COND((*this),true)
  _GLIBCXX_DEBUG_ASSERT(!base_type::empty());

  if (m_p_max == 0)
    find_max();

  _GLIBCXX_DEBUG_ASSERT(m_p_max != 0);
  node_pointer p_nd = m_p_max;
  remove_parentless_node(m_p_max);
  base_type::actual_erase_node(p_nd);
  m_p_max = 0;
  PB_DS_ASSERT_VALID_COND((*this),true)
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
remove_parentless_node(node_pointer p_nd)
{
  _GLIBCXX_DEBUG_ASSERT(p_nd != 0);
  _GLIBCXX_DEBUG_ASSERT(base_type::parent(p_nd) == 0);

  node_pointer p_cur_root = p_nd == base_type::m_p_root?
    p_nd->m_p_next_sibling : base_type::m_p_root;

  if (p_cur_root != 0)
    p_cur_root->m_p_prev_or_parent = 0;

  if (p_nd->m_p_prev_or_parent != 0)
    p_nd->m_p_prev_or_parent->m_p_next_sibling = p_nd->m_p_next_sibling;

  if (p_nd->m_p_next_sibling != 0)
    p_nd->m_p_next_sibling->m_p_prev_or_parent = p_nd->m_p_prev_or_parent;

  node_pointer p_child = p_nd->m_p_l_child;
  if (p_child != 0)
    {
      p_child->m_p_prev_or_parent = 0;
      while (p_child->m_p_next_sibling != 0)
	p_child = p_child->m_p_next_sibling;
    }

  m_p_max = 0;
  base_type::m_p_root = join(p_cur_root, p_child);
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
clear()
{
  base_type::clear();
  m_p_max = 0;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
erase(point_iterator it)
{
  PB_DS_ASSERT_VALID_COND((*this),true)
  _GLIBCXX_DEBUG_ASSERT(!base_type::empty());

  base_type::bubble_to_top(it.m_p_nd);
  remove_parentless_node(it.m_p_nd);
  base_type::actual_erase_node(it.m_p_nd);
  m_p_max = 0;
  PB_DS_ASSERT_VALID_COND((*this),true)
}

PB_DS_CLASS_T_DEC
template<typename Pred>
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
erase_if(Pred pred)
{
  PB_DS_ASSERT_VALID_COND((*this),true)

  if (base_type::empty())
    {
      PB_DS_ASSERT_VALID_COND((*this),true)
      return 0;
    }

  base_type::to_linked_list();
  node_pointer p_out = base_type::prune(pred);
  size_type ersd = 0;
  while (p_out != 0)
    {
      ++ersd;
      node_pointer p_next = p_out->m_p_next_sibling;
      base_type::actual_erase_node(p_out);
      p_out = p_next;
    }

  node_pointer p_cur = base_type::m_p_root;
  base_type::m_p_root = 0;
  while (p_cur != 0)
    {
      node_pointer p_next = p_cur->m_p_next_sibling;
      p_cur->m_p_l_child = p_cur->m_p_prev_or_parent = 0;
      p_cur->m_metadata = 0;
      p_cur->m_p_next_sibling = base_type::m_p_root;

      if (base_type::m_p_root != 0)
	base_type::m_p_root->m_p_prev_or_parent = p_cur;

      base_type::m_p_root = p_cur;
      base_type::m_p_root = fix(base_type::m_p_root);
      p_cur = p_next;
    }

  m_p_max = 0;
  PB_DS_ASSERT_VALID_COND((*this),true)
  return ersd;
}
#endif
