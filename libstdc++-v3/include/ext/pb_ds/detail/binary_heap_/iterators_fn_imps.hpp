// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/iterators_fn_imps.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
begin()
{ return iterator(m_a_entries); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin() const
{ return const_iterator(m_a_entries); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
end()
{ return iterator(m_a_entries + m_size); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end() const
{ return const_iterator(m_a_entries + m_size); }

#endif
