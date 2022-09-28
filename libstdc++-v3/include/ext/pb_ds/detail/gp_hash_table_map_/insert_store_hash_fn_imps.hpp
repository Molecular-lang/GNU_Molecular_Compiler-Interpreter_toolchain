// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/insert_store_hash_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s find related functions,
 * when the hash value is stored.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::comp_hash
PB_DS_CLASS_C_DEC::
find_ins_pos(key_const_reference r_key, true_type)
{
  PB_DS_ASSERT_VALID((*this))
  comp_hash pos_hash_pair = ranged_probe_fn_base::operator()(r_key);

  size_type i;

  /* The insertion position is initted to a non-legal value to indicate
   *     that it has not been initted yet.
   */
  size_type ins_pos = m_num_e;
  resize_base::notify_insert_search_start();
  for (i = 0; i < m_num_e; ++i)
    {
      const size_type pos = ranged_probe_fn_base::operator()(r_key, pos_hash_pair.second, i);

      entry* const p_e = m_entries + pos;
      switch(p_e->m_stat)
        {
        case empty_entry_status:
	  {
            resize_base::notify_insert_search_end();
	    PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)

	    return ((ins_pos == m_num_e) ?
		     std::make_pair(pos, pos_hash_pair.second) :
		     std::make_pair(ins_pos, pos_hash_pair.second));
	  }
	  break;
        case erased_entry_status:
	  if (ins_pos == m_num_e)
	    ins_pos = pos;
	  break;
        case valid_entry_status:
	  if (hash_eq_fn_base::operator()(PB_DS_V2F(p_e->m_value), p_e->m_hash,
					  r_key, pos_hash_pair.second))
            {
	      resize_base::notify_insert_search_end();
	      PB_DS_CHECK_KEY_EXISTS(r_key)
              return std::make_pair(pos, pos_hash_pair.second);
            }
	  break;
        default:
	  _GLIBCXX_DEBUG_ASSERT(0);
        };
      resize_base::notify_insert_search_collision();
    }
  resize_base::notify_insert_search_end();
  if (ins_pos == m_num_e)
    __throw_insert_error();
  return std::make_pair(ins_pos, pos_hash_pair.second);
}

PB_DS_CLASS_T_DEC
inline std::pair<typename PB_DS_CLASS_C_DEC::point_iterator, bool>
PB_DS_CLASS_C_DEC::
insert_imp(const_reference r_val, true_type)
{
  key_const_reference r_key = PB_DS_V2F(r_val);
  comp_hash pos_hash_pair = find_ins_pos(r_key, 
					 traits_base::m_store_extra_indicator);

  _GLIBCXX_DEBUG_ASSERT(pos_hash_pair.first < m_num_e);
  entry_pointer p_e =& m_entries[pos_hash_pair.first];
  if (p_e->m_stat == valid_entry_status)
    {
      PB_DS_CHECK_KEY_EXISTS(r_key)
      return std::make_pair(&p_e->m_value, false);
    }

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
  return std::make_pair(insert_new_imp(r_val, pos_hash_pair), true);
}

#endif
