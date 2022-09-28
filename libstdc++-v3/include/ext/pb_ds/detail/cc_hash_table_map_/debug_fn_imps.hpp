// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/debug_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s debug-mode functions.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  debug_base::check_size(m_num_used_e, __file, __line);
  assert_entry_pointer_array_valid(m_entries, __file, __line);
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_entry_pointer_array_valid(const entry_pointer_array a_p_entries,
				 const char* __file, int __line) const
{
  size_type iterated_num_used_e = 0;
  for (size_type pos = 0; pos < m_num_e; ++pos)
    {
      entry_pointer p_e = a_p_entries[pos];
      while (p_e != 0)
        {
	  ++iterated_num_used_e;
	  assert_entry_pointer_valid(p_e, traits_base::m_store_extra_indicator,
				     __file, __line);
	  p_e = p_e->m_p_next;
        }
    }
  PB_DS_DEBUG_VERIFY(iterated_num_used_e == m_num_used_e);
}

#include <ext/pb_ds/detail/cc_hash_table_map_/debug_store_hash_fn_imps.hpp>
#include <ext/pb_ds/detail/cc_hash_table_map_/debug_no_store_hash_fn_imps.hpp>

#endif 
#endif
