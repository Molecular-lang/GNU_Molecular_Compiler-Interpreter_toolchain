// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file list_update_map_/erase_fn_imps.hpp
 * Contains implementations of lu_map_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline bool
PB_DS_CLASS_C_DEC::
erase(key_const_reference r_key)
{
  PB_DS_ASSERT_VALID((*this))
  if (m_p_l == 0)
    return false;

  if (s_eq_fn(r_key, PB_DS_V2F(m_p_l->m_value)))
    {
      entry_pointer p_next = m_p_l->m_p_next;
      actual_erase_entry(m_p_l);
      m_p_l = p_next;
      return true;
    }

  entry_pointer p_l = m_p_l;
  while (p_l->m_p_next != 0)
    if (s_eq_fn(r_key, PB_DS_V2F(p_l->m_p_next->m_value)))
      {
	erase_next(p_l);
	return true;
      }
    else
      p_l = p_l->m_p_next;
  return false;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
clear()
{
  deallocate_all();
}

PB_DS_CLASS_T_DEC
template<typename Pred>
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
erase_if(Pred pred)
{
  PB_DS_ASSERT_VALID((*this))
  size_type num_ersd = 0;
  while (m_p_l != 0 && pred(m_p_l->m_value))
    {
      entry_pointer p_next = m_p_l->m_p_next;
      ++num_ersd;
      actual_erase_entry(m_p_l);
      m_p_l = p_next;
    }

  if (m_p_l == 0)
    return num_ersd;

  entry_pointer p_l = m_p_l;
  while (p_l->m_p_next != 0)
    {
      if (pred(p_l->m_p_next->m_value))
        {
	  ++num_ersd;
	  erase_next(p_l);
        }
      else
	p_l = p_l->m_p_next;
    }

  PB_DS_ASSERT_VALID((*this))
  return num_ersd;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
erase_next(entry_pointer p_l)
{
  _GLIBCXX_DEBUG_ASSERT(p_l != 0);
  _GLIBCXX_DEBUG_ASSERT(p_l->m_p_next != 0);
  entry_pointer p_next_l = p_l->m_p_next->m_p_next;
  actual_erase_entry(p_l->m_p_next);
  p_l->m_p_next = p_next_l;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
actual_erase_entry(entry_pointer p_l)
{
  _GLIBCXX_DEBUG_ONLY(debug_base::erase_existing(PB_DS_V2F(p_l->m_value));)
  p_l->~entry();
  s_entry_allocator.deallocate(p_l, 1);
}

#endif
