// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file list_update_map_/iterators_fn_imps.hpp
 * Contains implementations of lu_map_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
begin()
{
  if (m_p_l == 0)
    {
      _GLIBCXX_DEBUG_ASSERT(empty());
      return end();
    }
  return iterator(&m_p_l->m_value, m_p_l, this);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin() const
{
  if (m_p_l == 0)
    {
      _GLIBCXX_DEBUG_ASSERT(empty());
      return end();
    }
  return iterator(&m_p_l->m_value, m_p_l, const_cast<PB_DS_CLASS_C_DEC* >(this));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
end()
{ return iterator(0, 0, this); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end() const
{
  return const_iterator(0, 0, const_cast<PB_DS_CLASS_C_DEC*>(this));
}

#endif
