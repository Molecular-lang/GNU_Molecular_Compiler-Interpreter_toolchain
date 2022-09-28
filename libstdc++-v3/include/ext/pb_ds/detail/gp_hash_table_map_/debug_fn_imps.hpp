// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/debug_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s debug-mode functions.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  debug_base::check_size(m_num_used_e, __file, __line);
  assert_entry_array_valid(m_entries, traits_base::m_store_extra_indicator,
			   __file, __line);
}

#include <ext/pb_ds/detail/gp_hash_table_map_/debug_no_store_hash_fn_imps.hpp>
#include <ext/pb_ds/detail/gp_hash_table_map_/debug_store_hash_fn_imps.hpp>

#endif 
#endif
