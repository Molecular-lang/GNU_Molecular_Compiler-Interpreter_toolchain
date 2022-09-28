// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file ov_tree_map_/iterators_fn_imps.hpp
 * Contains an implementation class for ov_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_const_iterator
PB_DS_CLASS_C_DEC::
node_begin() const
{ return PB_DS_node_begin_imp(); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_const_iterator
PB_DS_CLASS_C_DEC::
node_end() const
{ return PB_DS_node_end_imp(); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
node_begin()
{ return PB_DS_node_begin_imp(); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
node_end()
{ return PB_DS_node_end_imp(); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_const_iterator
PB_DS_CLASS_C_DEC::
PB_DS_node_begin_imp() const
{
  return node_const_iterator(const_cast<pointer>(mid_pointer(begin(), end())),
			      const_cast<pointer>(begin()),
			      const_cast<pointer>(end()),(m_a_metadata == 0)?
			      0 :
			      mid_pointer(m_a_metadata, m_a_metadata + m_size));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_const_iterator
PB_DS_CLASS_C_DEC::
PB_DS_node_end_imp() const
{
  return node_const_iterator(end(), end(), end(),
		     (m_a_metadata == 0) ? 0 : m_a_metadata + m_size);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
PB_DS_node_begin_imp()
{
  return node_iterator(mid_pointer(begin(), end()), begin(), end(),
		       (m_a_metadata == 0) ? 0 : mid_pointer(m_a_metadata, m_a_metadata + m_size));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
PB_DS_node_end_imp()
{
  return node_iterator(end(), end(),
		  end(),(m_a_metadata == 0) ? 0 : m_a_metadata + m_size);
}

#endif
