// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/info_fn_imps.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
_GLIBCXX_NODISCARD
inline bool
PB_DS_CLASS_C_DEC::
empty() const
{ return m_size == 0; }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
size() const
{ return m_size; }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
max_size() const
{ return s_entry_allocator.max_size(); }

#endif
