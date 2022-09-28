// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/find_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s find related functions.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
find(key_const_reference r_key)
{
  PB_DS_ASSERT_VALID((*this))
  return find_key_pointer(r_key, traits_base::m_store_extra_indicator);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
find(key_const_reference r_key) const
{
  PB_DS_ASSERT_VALID((*this))
  return const_cast<PB_DS_CLASS_C_DEC& >(*this).find_key_pointer(r_key, 
					traits_base::m_store_extra_indicator);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
find_end()
{ return 0; }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
find_end() const
{ return 0; }

#endif
