// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file rb_tree_map_/debug_fn_imps.hpp
 * Contains an implementation for rb_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
assert_node_consistent(const node_pointer p_nd, const char* __file,
						int __line) const
{
  if (p_nd == 0)
    return 1;

  const size_type l_height =
    assert_node_consistent(p_nd->m_p_left, __file, __line);
  const size_type r_height =
    assert_node_consistent(p_nd->m_p_right, __file, __line);
  if (p_nd->m_red)
    {
      PB_DS_DEBUG_VERIFY(is_effectively_black(p_nd->m_p_left));
      PB_DS_DEBUG_VERIFY(is_effectively_black(p_nd->m_p_right));
    }
  PB_DS_DEBUG_VERIFY(l_height == r_height);
  return (p_nd->m_red ? 0 : 1) + l_height;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  base_type::assert_valid(__file, __line);
  const node_pointer p_head = base_type::m_p_head;
  PB_DS_DEBUG_VERIFY(p_head->m_red);
  if (p_head->m_p_parent != 0)
    {
      PB_DS_DEBUG_VERIFY(!p_head->m_p_parent->m_red);
      assert_node_consistent(p_head->m_p_parent, __file, __line);
    }
}

#endif 

#endif
