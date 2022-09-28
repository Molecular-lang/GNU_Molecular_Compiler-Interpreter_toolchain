// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pairing_heap_/find_fn_imps.hpp
 * Contains an implementation class for a pairing heap.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reference
PB_DS_CLASS_C_DEC::
top() const
{
  PB_DS_ASSERT_VALID((*this))
  _GLIBCXX_DEBUG_ASSERT(!base_type::empty());
  return base_type::m_p_root->m_value;
}
#endif
