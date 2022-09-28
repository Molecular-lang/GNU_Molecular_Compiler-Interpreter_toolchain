// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file list_update_map_/find_fn_imps.hpp
 * Contains implementations of lu_map_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::entry_pointer
PB_DS_CLASS_C_DEC::
find_imp(key_const_reference r_key) const
{
  if (m_p_l == 0)
    return 0;
  if (s_eq_fn(r_key, PB_DS_V2F(m_p_l->m_value)))
    {
      apply_update(m_p_l, s_metadata_type_indicator);
      PB_DS_CHECK_KEY_EXISTS(r_key)
      return m_p_l;
    }

  entry_pointer p_l = m_p_l;
  while (p_l->m_p_next != 0)
    {
      entry_pointer p_next = p_l->m_p_next;
      if (s_eq_fn(r_key, PB_DS_V2F(p_next->m_value)))
        {
	  if (apply_update(p_next, s_metadata_type_indicator))
            {
	      p_l->m_p_next = p_next->m_p_next;
	      p_next->m_p_next = m_p_l;
	      m_p_l = p_next;
	      return m_p_l;
            }
	  return p_next;
        }
      else
	p_l = p_next;
    }

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
  return 0;
}

PB_DS_CLASS_T_DEC
template<typename Metadata>
inline bool
PB_DS_CLASS_C_DEC::
apply_update(entry_pointer p_l, type_to_type<Metadata>)
{ return s_update_policy(p_l->m_update_metadata); }

PB_DS_CLASS_T_DEC
inline bool
PB_DS_CLASS_C_DEC::
apply_update(entry_pointer, type_to_type<null_type>)
{ return s_update_policy(s_null_type); }

#endif
