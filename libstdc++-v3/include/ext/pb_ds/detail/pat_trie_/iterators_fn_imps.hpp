// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pat_trie_/iterators_fn_imps.hpp
 * Contains an implementation class for pat_trie.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
begin()
{ return iterator(m_p_head->m_p_min); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin() const
{ return const_iterator(m_p_head->m_p_min); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
end()
{ return iterator(m_p_head); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end() const
{ return const_iterator(m_p_head); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reverse_iterator
PB_DS_CLASS_C_DEC::
rbegin() const
{
  if (empty())
    return rend();
  return --end();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::reverse_iterator
PB_DS_CLASS_C_DEC::
rbegin()
{
  if (empty())
    return rend();
  return --end();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::reverse_iterator
PB_DS_CLASS_C_DEC::
rend()
{ return reverse_iterator(m_p_head); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_reverse_iterator
PB_DS_CLASS_C_DEC::
rend() const
{ return const_reverse_iterator(m_p_head); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_const_iterator
PB_DS_CLASS_C_DEC::
node_begin() const
{ return node_const_iterator(m_p_head->m_p_parent, this); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
node_begin()
{ return node_iterator(m_p_head->m_p_parent, this); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_const_iterator
PB_DS_CLASS_C_DEC::
node_end() const
{ return node_const_iterator(0, this); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
node_end()
{ return node_iterator(0, this); }

#endif
