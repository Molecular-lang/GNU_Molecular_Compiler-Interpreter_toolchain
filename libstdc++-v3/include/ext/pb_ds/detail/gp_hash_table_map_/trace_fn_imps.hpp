// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/trace_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s trace-mode functions.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef PB_DS_HT_MAP_TRACE_

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace() const
{
  std::cerr << static_cast<unsigned long>(m_num_e) << " " <<
    static_cast<unsigned long>(m_num_used_e) << std::endl;

  for (size_type i = 0; i < m_num_e; ++i)
    {
      std::cerr << static_cast<unsigned long>(i) << " ";

      switch(m_entries[i].m_stat)
        {
	case empty_entry_status:
	  std::cerr << "<empty>";
	  break;
	case erased_entry_status:
	  std::cerr << "<erased>";
	  break;
	case valid_entry_status:
	  std::cerr << PB_DS_V2F(m_entries[i].m_value);
	  break;
	default:
	  _GLIBCXX_DEBUG_ASSERT(0);
	};

      std::cerr << std::endl;
    }
}

#endif // #ifdef PB_DS_HT_MAP_TRACE_
#endif
