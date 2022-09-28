// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/erase_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s erase related functions.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
erase_entry_pointer(entry_pointer& r_p_e)
{
  _GLIBCXX_DEBUG_ONLY(debug_base::erase_existing(PB_DS_V2F(r_p_e->m_value)));

  entry_pointer p_e = r_p_e;
  r_p_e = r_p_e->m_p_next;
  rels_entry(p_e);
  _GLIBCXX_DEBUG_ASSERT(m_num_used_e > 0);
  resize_base::notify_erased(--m_num_used_e);
}

PB_DS_CLASS_T_DEC
template<typename Pred>
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
erase_if(Pred pred)
{
  size_type num_ersd = 0;
  for (size_type pos = 0; pos < m_num_e; ++pos)
    {
      while (m_entries[pos] != 0 && pred(m_entries[pos]->m_value))
        {
	  ++num_ersd;
	  entry_pointer p_next_e = m_entries[pos]->m_p_next;
	  erase_entry_pointer(m_entries[pos]);
	  m_entries[pos] = p_next_e;
        }

      entry_pointer p_e = m_entries[pos];
      while (p_e != 0 && p_e->m_p_next != 0)
        {
	  if (pred(p_e->m_p_next->m_value))
            {
	      ++num_ersd;
	      erase_entry_pointer(p_e->m_p_next);
            }
	  else
	    p_e = p_e->m_p_next;
        }
    }

  do_resize_if_needed_no_throw();
  return num_ersd;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
clear()
{
  for (size_type pos = 0; pos < m_num_e; ++pos)
    while (m_entries[pos] != 0)
      erase_entry_pointer(m_entries[pos]);
  do_resize_if_needed_no_throw();
  resize_base::notify_cleared();
}

#include <ext/pb_ds/detail/cc_hash_table_map_/erase_no_store_hash_fn_imps.hpp>
#include <ext/pb_ds/detail/cc_hash_table_map_/erase_store_hash_fn_imps.hpp>

#endif
