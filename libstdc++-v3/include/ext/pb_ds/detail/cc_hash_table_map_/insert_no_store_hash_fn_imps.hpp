// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/insert_no_store_hash_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s insert related functions,
 * when the hash value is not stored.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline std::pair<typename PB_DS_CLASS_C_DEC::point_iterator, bool>
PB_DS_CLASS_C_DEC::
insert_imp(const_reference r_val, false_type)
{
  PB_DS_ASSERT_VALID((*this))
  key_const_reference r_key = PB_DS_V2F(r_val);
  const size_type pos = ranged_hash_fn_base::operator()(r_key);
  entry_pointer p_e = m_entries[pos];
  resize_base::notify_insert_search_start();

  while (p_e != 0 && !hash_eq_fn_base::operator()(PB_DS_V2F(p_e->m_value), 
						     r_key))
    {
      resize_base::notify_insert_search_collision();
      p_e = p_e->m_p_next;
    }

  resize_base::notify_insert_search_end();
  if (p_e != 0)
    {
      PB_DS_CHECK_KEY_EXISTS(r_key)
      return std::make_pair(&p_e->m_value, false);
    }

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
  return std::make_pair(insert_new_imp(r_val, pos), true);
}

#endif
