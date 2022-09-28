// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file thin_heap_/find_fn_imps.hpp
 * Contains an implementation for thin_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reference
PB_DS_CLASS_C_DEC::
top() const
{
  PB_DS_ASSERT_VALID((*this))
  _GLIBCXX_DEBUG_ASSERT(!base_type::empty());

  _GLIBCXX_DEBUG_ASSERT(m_p_max != 0);
  return m_p_max->m_value;
}
#endif
