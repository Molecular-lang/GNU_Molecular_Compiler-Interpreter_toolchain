// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file ov_tree_map_/debug_fn_imps.hpp
 * Contains an implementation class for ov_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  if (m_a_values == 0 || m_end_it == 0 || m_size == 0)
    PB_DS_DEBUG_VERIFY(m_a_values == 0 &&  m_end_it == 0 && m_size == 0);

  assert_iterators(__file, __line);
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_iterators(const char* __file, int __line) const
{
  debug_base::check_size(m_size, __file, __line);
  size_type iterated_num = 0;
  const_iterator prev_it = end();
  PB_DS_DEBUG_VERIFY(m_end_it == m_a_values + m_size);
  for (const_iterator it = begin(); it != end(); ++it)
    {
      ++iterated_num;
      debug_base::check_key_exists(PB_DS_V2F(*it), __file, __line);
      PB_DS_DEBUG_VERIFY(lower_bound(PB_DS_V2F(*it)) == it);
      const_iterator upper_bound_it = upper_bound(PB_DS_V2F(*it));
      --upper_bound_it;
      PB_DS_DEBUG_VERIFY(upper_bound_it == it);
      if (prev_it != end())
	PB_DS_DEBUG_VERIFY(Cmp_Fn::operator()(PB_DS_V2F(*prev_it),
					      PB_DS_V2F(*it)));
      prev_it = it;
    }
  PB_DS_DEBUG_VERIFY(iterated_num == m_size);
}

#endif
#endif
