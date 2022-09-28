// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/erase_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s erase related functions.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
erase_entry(entry_pointer p_e)
{
  _GLIBCXX_DEBUG_ASSERT(p_e->m_stat = valid_entry_status);
  _GLIBCXX_DEBUG_ONLY(debug_base::erase_existing(PB_DS_V2F(p_e->m_value));)
  p_e->m_value.~value_type();
  p_e->m_stat = erased_entry_status;
  _GLIBCXX_DEBUG_ASSERT(m_num_used_e > 0);
  resize_base::notify_erased(--m_num_used_e);
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
clear()
{
  for (size_type pos = 0; pos < m_num_e; ++pos)
    {
      entry_pointer p_e = &m_entries[pos];
      if (p_e->m_stat == valid_entry_status)
	erase_entry(p_e);
    }
  do_resize_if_needed_no_throw();
  resize_base::notify_cleared();
}

PB_DS_CLASS_T_DEC
template<typename Pred>
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
erase_if(Pred pred)
{
  PB_DS_ASSERT_VALID((*this))
  size_type num_ersd = 0;
  for (size_type pos = 0; pos < m_num_e; ++pos)
    {
      entry_pointer p_e = &m_entries[pos];
      if (p_e->m_stat == valid_entry_status)
	if (pred(p_e->m_value))
	  {
	    ++num_ersd;
	    erase_entry(p_e);
	  }
    }

  do_resize_if_needed_no_throw();
  PB_DS_ASSERT_VALID((*this))
  return num_ersd;
}

PB_DS_CLASS_T_DEC
inline bool
PB_DS_CLASS_C_DEC::
erase(key_const_reference r_key)
{ return erase_imp(r_key, traits_base::m_store_extra_indicator); }

#include <ext/pb_ds/detail/gp_hash_table_map_/erase_no_store_hash_fn_imps.hpp>
#include <ext/pb_ds/detail/gp_hash_table_map_/erase_store_hash_fn_imps.hpp>
#endif
