// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pat_trie_/debug_fn_imps.hpp
 * Contains an implementation class for pat_trie_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  if (m_p_head->m_p_parent != 0)
    m_p_head->m_p_parent->assert_valid(this, __file, __line);
  assert_iterators(__file, __line);
  assert_reverse_iterators(__file, __line);
  if (m_p_head->m_p_parent == 0)
    {
      PB_DS_DEBUG_VERIFY(m_p_head->m_p_min == m_p_head);
      PB_DS_DEBUG_VERIFY(m_p_head->m_p_max == m_p_head);
      PB_DS_DEBUG_VERIFY(empty());
      return;
    }

  PB_DS_DEBUG_VERIFY(m_p_head->m_p_min->m_type == leaf_node);
  PB_DS_DEBUG_VERIFY(m_p_head->m_p_max->m_type == leaf_node);
  PB_DS_DEBUG_VERIFY(!empty());
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_iterators(const char* __file, int __line) const
{
  size_type calc_size = 0;
  for (const_iterator it = begin(); it != end(); ++it)
    {
      ++calc_size;
      debug_base::check_key_exists(PB_DS_V2F(*it), __file, __line);
      PB_DS_DEBUG_VERIFY(lower_bound(PB_DS_V2F(*it)) == it);
      PB_DS_DEBUG_VERIFY(--upper_bound(PB_DS_V2F(*it)) == it);
    }
  PB_DS_DEBUG_VERIFY(calc_size == m_size);
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_reverse_iterators(const char* __file, int __line) const
{
  size_type calc_size = 0;
  for (const_reverse_iterator it = rbegin(); it != rend(); ++it)
    {
      ++calc_size;
      node_const_pointer p_nd =
	const_cast<PB_DS_CLASS_C_DEC*>(this)->find_imp(PB_DS_V2F(*it));
      PB_DS_DEBUG_VERIFY(p_nd == it.m_p_nd);
    }
  PB_DS_DEBUG_VERIFY(calc_size == m_size);
}

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
recursive_count_leafs(node_const_pointer p_nd, const char* __file, int __line)
{
  if (p_nd == 0)
    return (0);
  if (p_nd->m_type == leaf_node)
    return (1);
  PB_DS_DEBUG_VERIFY(p_nd->m_type == i_node);
  size_type ret = 0;
  for (typename inode::const_iterator it = static_cast<inode_const_pointer>(p_nd)->begin();
       it != static_cast<inode_const_pointer>(p_nd)->end();
       ++it)
    ret += recursive_count_leafs(*it, __file, __line);
  return ret;
}

#endif
#endif
