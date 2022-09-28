// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file list_update_map_/trace_fn_imps.hpp
 * Contains implementations of lu_map_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef PB_DS_LU_MAP_TRACE_

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace() const
{
  std::cerr << m_p_l << std::endl << std::endl;
  const_entry_pointer p_l = m_p_l;
  while (p_l != 0)
    {
      std::cerr << PB_DS_V2F(p_l->m_value) << std::endl;
      p_l = p_l->m_p_next;
    }
  std::cerr << std::endl;
}

#endif 

#endif
