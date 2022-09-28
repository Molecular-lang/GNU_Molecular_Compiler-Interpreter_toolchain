// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file left_child_next_sibling_heap_/iterators_fn_imps.hpp
 * Contains an implementation class for left_child_next_sibling_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
begin()
{
  node_pointer p_nd = m_p_root;

  if (p_nd == 0)
    return (iterator(0));

  while (p_nd->m_p_l_child != 0)
    p_nd = p_nd->m_p_l_child;

  return (iterator(p_nd));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin() const
{
  node_pointer p_nd = m_p_root;

  if (p_nd == 0)
    return (const_iterator(0));

  while (p_nd->m_p_l_child != 0)
    p_nd = p_nd->m_p_l_child;

  return (const_iterator(p_nd));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
end()
{
  return (iterator(0));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end() const
{
  return (const_iterator(0));
}

#endif
