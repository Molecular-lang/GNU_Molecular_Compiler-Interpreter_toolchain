// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/erase_store_hash_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s erase related functions,
 * when the hash value is stored.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline bool
PB_DS_CLASS_C_DEC::
erase_imp(key_const_reference r_key, true_type)
{
  const comp_hash pos_hash_pair = ranged_probe_fn_base::operator()(r_key);
  size_type i;
  resize_base::notify_erase_search_start();
  for (i = 0; i < m_num_e; ++i)
    {
      const size_type pos = ranged_probe_fn_base::operator()(r_key, pos_hash_pair.second, i);

      entry* const p_e = m_entries + pos;
      switch(p_e->m_stat)
        {
        case empty_entry_status:
	  {
	    resize_base::notify_erase_search_end();
	    PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
	    return false;
	  }
	  break;
        case valid_entry_status:
	  if (hash_eq_fn_base::operator()(PB_DS_V2F(p_e->m_value), p_e->m_hash,
					  r_key, pos_hash_pair.second))
            {
	      resize_base::notify_erase_search_end();
	      erase_entry(p_e);
	      do_resize_if_needed_no_throw();
	      return true;
            }
	  break;
        case erased_entry_status:
	  break;
        default:
	  _GLIBCXX_DEBUG_ASSERT(0);
        };

      resize_base::notify_erase_search_collision();
    }
  resize_base::notify_erase_search_end();
  return false;
}

#endif
