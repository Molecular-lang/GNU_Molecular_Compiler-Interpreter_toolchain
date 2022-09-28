// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file splay_tree_/debug_fn_imps.hpp
 * Contains an implementation class for splay_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  base_type::assert_valid(__file, __line);
  const node_pointer p_head = base_type::m_p_head;
  assert_special_imp(p_head, __file, __line);
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_special_imp(const node_pointer p_nd,
		   const char* __file, int __line) const
{
  if (p_nd == 0)
    return;

  if (p_nd == base_type::m_p_head)
    {
      PB_DS_DEBUG_VERIFY(p_nd->m_special);
      assert_special_imp(p_nd->m_p_parent, __file, __line);
      return;
    }

  PB_DS_DEBUG_VERIFY(!p_nd->m_special);
  assert_special_imp(p_nd->m_p_left, __file, __line);
  assert_special_imp(p_nd->m_p_right, __file, __line);
}

#endif 

#endif
