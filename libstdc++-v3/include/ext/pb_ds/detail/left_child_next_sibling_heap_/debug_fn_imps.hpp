// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file left_child_next_sibling_heap_/debug_fn_imps.hpp
 * Contains an implementation class for left_child_next_sibling_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  PB_DS_DEBUG_VERIFY(m_p_root == 0 || m_p_root->m_p_prev_or_parent == 0);

  if (m_p_root != 0)
    assert_node_consistent(m_p_root, Single_Link_Roots, __file, __line);
  assert_size(__file, __line);
  assert_iterators(__file, __line);
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_node_consistent(node_const_pointer p_nd, bool single_link,
		       const char* __file, int __line) const
{
  if (p_nd == 0)
    return;

  assert_node_consistent(p_nd->m_p_l_child, false, __file, __line);
  assert_node_consistent(p_nd->m_p_next_sibling, single_link, __file, __line);

  if (single_link)
    PB_DS_DEBUG_VERIFY(p_nd->m_p_prev_or_parent == 0);
  else if (p_nd->m_p_next_sibling != 0)
    PB_DS_DEBUG_VERIFY(p_nd->m_p_next_sibling->m_p_prev_or_parent == p_nd);

  if (p_nd->m_p_l_child == 0)
    return;

  node_const_pointer p_child = p_nd->m_p_l_child;
  while (p_child != 0)
    {
      node_const_pointer p_next_child = p_child->m_p_next_sibling;
      PB_DS_DEBUG_VERIFY(!Cmp_Fn::operator()(p_nd->m_value, p_child->m_value));
      p_child = p_next_child;
    }
  PB_DS_DEBUG_VERIFY(p_nd->m_p_l_child->m_p_prev_or_parent == p_nd);
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_iterators(const char* __file, int __line) const
{
  PB_DS_DEBUG_VERIFY(std::distance(begin(), end()) == size());
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_size(const char* __file, int __line) const
{
  PB_DS_DEBUG_VERIFY(size_from_node(m_p_root) == m_size);
}

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
size_under_node(node_const_pointer p_nd)
{ return 1 + size_from_node(p_nd->m_p_l_child); }

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
size_from_node(node_const_pointer p_nd)
{
  size_type ret = 0;
  while (p_nd != 0)
    {
      ret += 1 + size_from_node(p_nd->m_p_l_child);
      p_nd = p_nd->m_p_next_sibling;
    }
  return ret;
}

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
degree(node_const_pointer p_nd)
{
  size_type ret = 0;
  node_const_pointer p_child = p_nd->m_p_l_child;
  while (p_child != 0)
    {
      ++ret;
      p_child = p_child->m_p_next_sibling;
    }
  return ret;
}

#endif 
#endif
