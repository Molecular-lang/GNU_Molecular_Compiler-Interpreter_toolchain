// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binomial_heap_base_/debug_fn_imps.hpp
 * Contains an implementation class for a base of binomial heaps.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(bool strictly_binomial, const char* __file, int __line) const
{
  base_type::assert_valid(__file, __line);
  assert_node_consistent(base_type::m_p_root, strictly_binomial, true,
			 __file, __line);
  assert_max(__file, __line);
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_max(const char* __file, int __line) const
{
  if (m_p_max == 0)
    return;
  PB_DS_DEBUG_VERIFY(base_type::parent(m_p_max) == 0);
  for (const_iterator it = base_type::begin(); it != base_type::end(); ++it)
    PB_DS_DEBUG_VERIFY(!Cmp_Fn::operator()(m_p_max->m_value,
					   it.m_p_nd->m_value));
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_node_consistent(node_const_pointer p_nd, bool strictly_binomial,
		       bool increasing, const char* __file, int __line) const
{
  PB_DS_DEBUG_VERIFY(increasing || strictly_binomial);
  base_type::assert_node_consistent(p_nd, false, __file, __line);
  if (p_nd == 0)
    return;
  PB_DS_DEBUG_VERIFY(p_nd->m_metadata == base_type::degree(p_nd));
  PB_DS_DEBUG_VERIFY(base_type::size_under_node(p_nd) ==
		   static_cast<size_type>(1 << p_nd->m_metadata));
  assert_node_consistent(p_nd->m_p_next_sibling, strictly_binomial, increasing,
			 __file, __line);
  assert_node_consistent(p_nd->m_p_l_child, true, false, __file, __line);
  if (p_nd->m_p_next_sibling != 0)
    {
      if (increasing)
	{
	  if (strictly_binomial)
	    PB_DS_DEBUG_VERIFY(p_nd->m_metadata
				  < p_nd->m_p_next_sibling->m_metadata);
	  else
	    PB_DS_DEBUG_VERIFY(p_nd->m_metadata
				  <= p_nd->m_p_next_sibling->m_metadata);
	}
      else
	PB_DS_DEBUG_VERIFY(p_nd->m_metadata
			      > p_nd->m_p_next_sibling->m_metadata);
    }
}

#endif
#endif
