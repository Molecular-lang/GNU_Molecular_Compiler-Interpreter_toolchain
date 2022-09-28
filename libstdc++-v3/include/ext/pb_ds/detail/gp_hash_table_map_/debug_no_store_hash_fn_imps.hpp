// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/debug_no_store_hash_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s debug-mode functions.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_entry_array_valid(const entry_array a_entries, false_type,
			 const char* __file, int __line) const
{
  size_type iterated_num_used_e = 0;
  for (size_type pos = 0; pos < m_num_e; ++pos)
    {
      const_entry_pointer p_e = &a_entries[pos];
      switch(p_e->m_stat)
        {
        case empty_entry_status:
        case erased_entry_status:
	  break;
        case valid_entry_status:
	  {
	    key_const_reference r_key = PB_DS_V2F(p_e->m_value);
	    debug_base::check_key_exists(r_key, __file, __line);
	    ++iterated_num_used_e;
	    break;
	  }
        default:
	  PB_DS_DEBUG_VERIFY(0);
        };
    }
  PB_DS_DEBUG_VERIFY(iterated_num_used_e == m_num_used_e);
}

#endif 
#endif
