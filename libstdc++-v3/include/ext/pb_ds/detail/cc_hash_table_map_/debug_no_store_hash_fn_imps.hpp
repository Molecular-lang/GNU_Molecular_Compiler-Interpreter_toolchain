// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/debug_no_store_hash_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s debug-mode functions.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_entry_pointer_valid(const entry_pointer p, false_type,
			   const char* __file, int __line) const
{ debug_base::check_key_exists(PB_DS_V2F(p->m_value), __file, __line); }

#endif
#endif
