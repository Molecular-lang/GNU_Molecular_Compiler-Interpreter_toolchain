// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file list_update_map_/info_fn_imps.hpp
 * Contains implementations of lu_map_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
size() const
{ return std::distance(begin(), end()); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
max_size() const
{ return s_entry_allocator.max_size(); }

PB_DS_CLASS_T_DEC
_GLIBCXX_NODISCARD
inline bool
PB_DS_CLASS_C_DEC::
empty() const
{ return (m_p_l == 0); }
#endif
