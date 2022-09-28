// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/split_join_fn_imps.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
template<typename Pred>
void
PB_DS_CLASS_C_DEC::
split(Pred pred, PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))

  typedef
    typename entry_pred<value_type, Pred, _Alloc, simple_value>::type
    pred_t;

  const size_type left = partition(pred_t(pred));
  _GLIBCXX_DEBUG_ASSERT(m_size >= left);

  const size_type ersd = m_size - left;
  _GLIBCXX_DEBUG_ASSERT(m_size >= ersd);

  const size_type new_size = resize_policy::get_new_size_for_arbitrary(left);
  const size_type other_actual_size = other.get_new_size_for_arbitrary(ersd);

  entry_pointer a_entries = 0;
  entry_pointer a_other_entries = 0;

  __try
    {
      a_entries = s_entry_allocator.allocate(new_size);
      a_other_entries = s_entry_allocator.allocate(other_actual_size);
    }
  __catch(...)
    {
      if (a_entries != 0)
	s_entry_allocator.deallocate(a_entries, new_size);

      if (a_other_entries != 0)
	s_entry_allocator.deallocate(a_other_entries, other_actual_size);

      __throw_exception_again;
    };

  for (size_type i = 0; i < other.m_size; ++i)
    erase_at(other.m_a_entries, i, s_no_throw_copies_ind);

  _GLIBCXX_DEBUG_ASSERT(new_size >= left);
  std::copy(m_a_entries, m_a_entries + left, a_entries);
  std::copy(m_a_entries + left, m_a_entries + m_size, a_other_entries);

  s_entry_allocator.deallocate(m_a_entries, m_actual_size);
  s_entry_allocator.deallocate(other.m_a_entries, other.m_actual_size);

  m_actual_size = new_size;
  other.m_actual_size = other_actual_size;

  m_size = left;
  other.m_size = ersd;

  m_a_entries = a_entries;
  other.m_a_entries = a_other_entries;

  make_heap();
  other.make_heap();

  resize_policy::notify_arbitrary(m_actual_size);
  other.notify_arbitrary(other.m_actual_size);

  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
join(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)

  const size_type len = m_size + other.m_size;
  const size_type new_size = resize_policy::get_new_size_for_arbitrary(len);

  entry_pointer a_entries = 0;
  entry_pointer a_other_entries = 0;

  __try
    {
      a_entries = s_entry_allocator.allocate(new_size);
      a_other_entries = s_entry_allocator.allocate(resize_policy::min_size);
    }
  __catch(...)
    {
      if (a_entries != 0)
	s_entry_allocator.deallocate(a_entries, new_size);

      if (a_other_entries != 0)
	s_entry_allocator.deallocate(a_other_entries, resize_policy::min_size);

      __throw_exception_again;
    }

  std::copy(m_a_entries, m_a_entries + m_size, a_entries);
  std::copy(other.m_a_entries, other.m_a_entries + other.m_size,
	    a_entries + m_size);

  s_entry_allocator.deallocate(m_a_entries, m_actual_size);
  m_a_entries = a_entries;
  m_size = len;
  m_actual_size = new_size;
  resize_policy::notify_arbitrary(new_size);
  make_heap();

  s_entry_allocator.deallocate(other.m_a_entries, other.m_actual_size);
  other.m_a_entries = a_other_entries;
  other.m_size = 0;
  other.m_actual_size = resize_policy::min_size;
  other.notify_arbitrary(resize_policy::min_size);
  other.make_heap();
  
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}
#endif
