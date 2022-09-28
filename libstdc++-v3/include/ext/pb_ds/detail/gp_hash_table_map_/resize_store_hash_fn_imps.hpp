// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/resize_store_hash_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s resize related functions, when the
 * hash value is stored.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
resize_imp_reassign(entry_pointer p_e, entry_array a_entries_resized, 
		    true_type)
{
  key_const_reference r_key = PB_DS_V2F(p_e->m_value);
  size_type hash = ranged_probe_fn_base::operator()(r_key, p_e->m_hash);

  size_type i;
  for (i = 0; i < m_num_e; ++i)
    {
      const size_type pos = ranged_probe_fn_base::operator()(r_key, hash, i);
      entry_pointer p_new_e = a_entries_resized + pos;
      switch(p_new_e->m_stat)
        {
        case empty_entry_status:
	  new (&p_new_e->m_value) value_type(p_e->m_value);
	  p_new_e->m_hash = hash;
	  p_new_e->m_stat = valid_entry_status;
	  return;
        case erased_entry_status:
	  _GLIBCXX_DEBUG_ASSERT(0);
	  break;
        case valid_entry_status:
	  break;
        default:
	  _GLIBCXX_DEBUG_ASSERT(0);
        };
    }
  __throw_insert_error();
}

#endif
