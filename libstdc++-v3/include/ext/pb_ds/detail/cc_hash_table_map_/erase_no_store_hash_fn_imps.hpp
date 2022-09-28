// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/erase_no_store_hash_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s erase related functions,
 * when the hash value is not stored.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline bool
PB_DS_CLASS_C_DEC::
erase(key_const_reference r_key)
{
  PB_DS_ASSERT_VALID((*this))
  return erase_in_pos_imp(r_key, ranged_hash_fn_base::operator()(r_key));
}

PB_DS_CLASS_T_DEC
inline bool
PB_DS_CLASS_C_DEC::
erase_in_pos_imp(key_const_reference r_key, size_type pos)
{
  PB_DS_ASSERT_VALID((*this))
  entry_pointer p_e = m_entries[pos];
  resize_base::notify_erase_search_start();
  if (p_e == 0)
    {
      resize_base::notify_erase_search_end();
      PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
      PB_DS_ASSERT_VALID((*this))
      return false;
    }

  if (hash_eq_fn_base::operator()(PB_DS_V2F(p_e->m_value), r_key))
    {
      resize_base::notify_erase_search_end();
      PB_DS_CHECK_KEY_EXISTS(r_key)
      erase_entry_pointer(m_entries[pos]);
      do_resize_if_needed_no_throw();
      PB_DS_ASSERT_VALID((*this))
      return true;
    }

  while (true)
    {
      entry_pointer p_next_e = p_e->m_p_next;
      if (p_next_e == 0)
	{
	  resize_base::notify_erase_search_end();
	  PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
	  PB_DS_ASSERT_VALID((*this))
	  return false;
	}

      if (hash_eq_fn_base::operator()(PB_DS_V2F(p_next_e->m_value), r_key))
	{
	  resize_base::notify_erase_search_end();
	  PB_DS_CHECK_KEY_EXISTS(r_key)
	  erase_entry_pointer(p_e->m_p_next);
	  do_resize_if_needed_no_throw();
	  PB_DS_ASSERT_VALID((*this))
	  return true;
	}
      resize_base::notify_erase_search_collision();
      p_e = p_next_e;
    }
}
#endif
