// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/find_fn_imps.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reference
PB_DS_CLASS_C_DEC::
top() const
{
  PB_DS_ASSERT_VALID((*this))
  _GLIBCXX_DEBUG_ASSERT(!empty());
  return top_imp(s_no_throw_copies_ind);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reference
PB_DS_CLASS_C_DEC::
top_imp(true_type) const
{ return *m_a_entries; }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reference
PB_DS_CLASS_C_DEC::
top_imp(false_type) const
{ return **m_a_entries; }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
left_child(size_type i)
{ return i * 2 + 1; }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
right_child(size_type i)
{ return i * 2 + 2; }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
parent(size_type i)
{ return (i - 1) / 2; }
#endif
