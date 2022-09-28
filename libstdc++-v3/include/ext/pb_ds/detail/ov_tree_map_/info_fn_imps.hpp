// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file ov_tree_map_/info_fn_imps.hpp
 * Contains an implementation class for ov_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
size() const
{
  PB_DS_ASSERT_VALID((*this))
  return m_size;
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
max_size() const
{ return s_value_alloc.max_size(); }

PB_DS_CLASS_T_DEC
_GLIBCXX_NODISCARD
inline bool
PB_DS_CLASS_C_DEC::
empty() const
{ return size() == 0; }
#endif
