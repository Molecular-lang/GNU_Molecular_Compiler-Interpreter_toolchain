// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/info_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s entire container info related
 * functions.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
size() const
{ return m_num_used_e; }

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
{ return (size() == 0); }
#endif
