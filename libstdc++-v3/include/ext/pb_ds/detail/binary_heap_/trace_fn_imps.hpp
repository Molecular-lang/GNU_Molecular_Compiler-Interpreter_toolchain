// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/trace_fn_imps.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef PB_DS_BINARY_HEAP_TRACE_

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace() const
{
  std::cerr << this << std::endl;

  std::cerr << m_a_entries << std::endl;

  for (size_type i = 0; i < m_size; ++i)
    trace_entry(m_a_entries[i], s_no_throw_copies_ind);

  std::cerr << std::endl;

  std::cerr << "size = " << m_size << " " << "actual_size = " << m_actual_size << std::endl;

  resize_policy::trace();
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace_entry(const entry& r_e, false_type) const
{
  std::cout << r_e << " " <<* r_e << std::endl;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace_entry(const entry& r_e, true_type) const
{
  std::cout << r_e << std::endl;
}

#endif // #ifdef PB_DS_BINARY_HEAP_TRACE_
#endif
