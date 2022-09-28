// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/debug_fn_imps.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
#ifdef PB_DS_REGRESSION
  s_entry_allocator.check_allocated(m_a_entries, m_actual_size);
#endif

  resize_policy::assert_valid(__file, __line);
  PB_DS_DEBUG_VERIFY(m_size <= m_actual_size);
  for (size_type i = 0; i < m_size; ++i)
    {
#ifdef PB_DS_REGRESSION
      s_value_allocator.check_allocated(m_a_entries[i], 1);
#endif

      if (left_child(i) < m_size)
	PB_DS_DEBUG_VERIFY(!entry_cmp::operator()(m_a_entries[i], m_a_entries[left_child(i)]));

      PB_DS_DEBUG_VERIFY(parent(left_child(i)) == i);

      if (right_child(i) < m_size)
	PB_DS_DEBUG_VERIFY(!entry_cmp::operator()(m_a_entries[i], m_a_entries[right_child(i)]));

      PB_DS_DEBUG_VERIFY(parent(right_child(i)) == i);
    }
}

#endif
#endif
