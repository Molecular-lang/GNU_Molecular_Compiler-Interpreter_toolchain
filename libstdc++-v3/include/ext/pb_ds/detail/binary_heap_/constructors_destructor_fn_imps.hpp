// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/constructors_destructor_fn_imps.hpp
 * Contains an implementation class for binary_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::entry_allocator
PB_DS_CLASS_C_DEC::s_entry_allocator;

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::value_allocator
PB_DS_CLASS_C_DEC::s_value_allocator;

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::no_throw_copies_t
PB_DS_CLASS_C_DEC::s_no_throw_copies_ind;

PB_DS_CLASS_T_DEC
template<typename It>
void
PB_DS_CLASS_C_DEC::
copy_from_range(It first_it, It last_it)
{
  while (first_it != last_it)
    {
      insert_value(*first_it, s_no_throw_copies_ind);
      ++first_it;
    }
  make_heap();
 PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binary_heap()
: m_size(0), m_actual_size(resize_policy::min_size),
  m_a_entries(s_entry_allocator.allocate(m_actual_size))
{ PB_DS_ASSERT_VALID((*this)) }

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binary_heap(const Cmp_Fn& r_cmp_fn)
: entry_cmp(r_cmp_fn), m_size(0), m_actual_size(resize_policy::min_size),
  m_a_entries(s_entry_allocator.allocate(m_actual_size))
{ PB_DS_ASSERT_VALID((*this)) }

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binary_heap(const PB_DS_CLASS_C_DEC& other)
: entry_cmp(other), resize_policy(other), m_size(0),
  m_actual_size(other.m_actual_size),
  m_a_entries(s_entry_allocator.allocate(m_actual_size))
{
  PB_DS_ASSERT_VALID(other)
  _GLIBCXX_DEBUG_ASSERT(m_a_entries != other.m_a_entries);

  __try
    {
      copy_from_range(other.begin(), other.end());
    }
  __catch(...)
    {
      for (size_type i = 0; i < m_size; ++i)
	erase_at(m_a_entries, i, s_no_throw_copies_ind);

      s_entry_allocator.deallocate(m_a_entries, m_actual_size);
      __throw_exception_again;
    }
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
  _GLIBCXX_DEBUG_ASSERT(m_a_entries != other.m_a_entries);
  value_swap(other);
  std::swap((entry_cmp&)(*this), (entry_cmp&)other);
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
value_swap(PB_DS_CLASS_C_DEC& other)
{
  std::swap(m_a_entries, other.m_a_entries);
  std::swap(m_size, other.m_size);
  std::swap(m_actual_size, other.m_actual_size);
  static_cast<resize_policy*>(this)->swap(other);
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
~binary_heap()
{
  for (size_type i = 0; i < m_size; ++i)
    erase_at(m_a_entries, i, s_no_throw_copies_ind);
  s_entry_allocator.deallocate(m_a_entries, m_actual_size);
}
#endif
