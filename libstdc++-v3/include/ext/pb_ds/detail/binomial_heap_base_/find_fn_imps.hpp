// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binomial_heap_base_/find_fn_imps.hpp
 * Contains an implementation class for a base of binomial heaps.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reference
PB_DS_CLASS_C_DEC::
top() const
{
  PB_DS_ASSERT_VALID_COND((*this),false)
  _GLIBCXX_DEBUG_ASSERT(!base_type::empty());

  if (m_p_max == 0)
    const_cast<PB_DS_CLASS_C_DEC* >(this)->find_max();

  _GLIBCXX_DEBUG_ASSERT(m_p_max != 0);
  return m_p_max->m_value;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
find_max()
{
  node_pointer p_cur = base_type::m_p_root;
  m_p_max = p_cur;
  while (p_cur != 0)
    {
      if (Cmp_Fn::operator()(m_p_max->m_value, p_cur->m_value))
	m_p_max = p_cur;
      p_cur = p_cur->m_p_next_sibling;
    }
}

#endif
