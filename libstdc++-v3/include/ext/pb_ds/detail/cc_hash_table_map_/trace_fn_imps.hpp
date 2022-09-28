// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/trace_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s trace-mode functions.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef PB_DS_HT_MAP_TRACE_

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace() const
{
  std::cerr << static_cast<unsigned long>(m_num_e) << " " 
	    << static_cast<unsigned long>(m_num_used_e) << std::endl;

  for (size_type i = 0; i < m_num_e; ++i)
    {
      std::cerr << static_cast<unsigned long>(i) << " ";
      trace_list(m_entries[i]);
      std::cerr << std::endl;
    }
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace_list(const_entry_pointer p_l) const
{
  size_type iterated_num_used_e = 0;
  while (p_l != 0)
    {
      std::cerr << PB_DS_V2F(p_l->m_value) << " ";
      p_l = p_l->m_p_next;
    }
}

#endif 
#endif
