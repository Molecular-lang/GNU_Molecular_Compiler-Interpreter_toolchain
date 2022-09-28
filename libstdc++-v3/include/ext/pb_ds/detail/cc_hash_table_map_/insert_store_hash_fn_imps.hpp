// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/insert_store_hash_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s insert related functions,
 * when the hash value is stored.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline std::pair<typename PB_DS_CLASS_C_DEC::point_iterator, bool>
PB_DS_CLASS_C_DEC::
insert_imp(const_reference r_val, true_type)
{
  PB_DS_ASSERT_VALID((*this))
  key_const_reference key = PB_DS_V2F(r_val);
  comp_hash pos_hash_pair = ranged_hash_fn_base::operator()(key);
  entry_pointer p_e = m_entries[pos_hash_pair.first];
  resize_base::notify_insert_search_start();

  while (p_e != 0 && !hash_eq_fn_base::operator()(PB_DS_V2F(p_e->m_value),
						     p_e->m_hash,
						    key, pos_hash_pair.second))
    {
      resize_base::notify_insert_search_collision();
      p_e = p_e->m_p_next;
    }

  resize_base::notify_insert_search_end();
  if (p_e != 0)
    {
      PB_DS_CHECK_KEY_EXISTS(key)
      return std::make_pair(&p_e->m_value, false);
    }

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(key)
  return std::make_pair(insert_new_imp(r_val, pos_hash_pair), true);
}

#endif
