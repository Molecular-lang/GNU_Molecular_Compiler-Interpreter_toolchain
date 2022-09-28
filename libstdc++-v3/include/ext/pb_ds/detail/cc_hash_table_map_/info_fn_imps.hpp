// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/info_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s entire container info related
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
{ return m_entry_allocator.max_size(); }

PB_DS_CLASS_T_DEC
_GLIBCXX_NODISCARD
inline bool
PB_DS_CLASS_C_DEC::
empty() const
{ return (size() == 0); }

PB_DS_CLASS_T_DEC
template<typename Other_HT_Map_Type>
bool
PB_DS_CLASS_C_DEC::
operator==(const Other_HT_Map_Type& other) const
{ return cmp_with_other(other); }

PB_DS_CLASS_T_DEC
template<typename Other_Map_Type>
bool
PB_DS_CLASS_C_DEC::
cmp_with_other(const Other_Map_Type& other) const
{
  if (size() != other.size())
    return false;

  for (typename Other_Map_Type::const_iterator it = other.begin();
       it != other.end(); ++it)
    {
      key_const_reference r_key =(key_const_reference)PB_DS_V2F(*it);
      mapped_const_pointer p_mapped_value =
	const_cast<PB_DS_CLASS_C_DEC& >(*this).
	find_key_pointer(r_key, traits_base::m_store_extra_indicator);

      if (p_mapped_value == 0)
	return false;

#ifdef PB_DS_DATA_TRUE_INDICATOR
      if (p_mapped_value->second != it->second)
	return false;
#endif 
    }
  return true;
}

PB_DS_CLASS_T_DEC
template<typename Other_HT_Map_Type>
bool
PB_DS_CLASS_C_DEC::
operator!=(const Other_HT_Map_Type& other) const
{ return !operator==(other); }
#endif
