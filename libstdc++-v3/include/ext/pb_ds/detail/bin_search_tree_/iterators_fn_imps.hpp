// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file bin_search_tree_/iterators_fn_imps.hpp
 * Contains an implementation class for bin_search_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
begin()
{
  return (iterator(m_p_head->m_p_left));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin() const
{
  return (const_iterator(m_p_head->m_p_left));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
end()
{
  return (iterator(m_p_head));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end() const
{
  return (const_iterator(m_p_head));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reverse_iterator
PB_DS_CLASS_C_DEC::
rbegin() const
{
  return (const_reverse_iterator(m_p_head->m_p_right));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::reverse_iterator
PB_DS_CLASS_C_DEC::
rbegin()
{
  return (reverse_iterator(m_p_head->m_p_right));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::reverse_iterator
PB_DS_CLASS_C_DEC::
rend()
{
  return (reverse_iterator(m_p_head));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reverse_iterator
PB_DS_CLASS_C_DEC::
rend() const
{
  return (const_reverse_iterator(m_p_head));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_const_iterator
PB_DS_CLASS_C_DEC::
node_begin() const
{
  return (node_const_iterator(m_p_head->m_p_parent));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
node_begin()
{
  return (node_iterator(m_p_head->m_p_parent));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_const_iterator
PB_DS_CLASS_C_DEC::
node_end() const
{
  return (node_const_iterator(0));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
node_end()
{
  return (node_iterator(0));
}

#endif
