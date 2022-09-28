// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pairing_heap_/debug_fn_imps.hpp
 * Contains an implementation class for a pairing heap.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  PB_DS_DEBUG_VERIFY(base_type::m_p_root == 0 
		        || base_type::m_p_root->m_p_next_sibling == 0);
  base_type::assert_valid(__file, __line);
}

#endif 
#endif
