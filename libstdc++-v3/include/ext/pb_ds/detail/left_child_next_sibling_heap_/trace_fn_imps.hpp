// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file left_child_next_sibling_heap_/trace_fn_imps.hpp
 * Contains an implementation class for left_child_next_sibling_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef PB_DS_LC_NS_HEAP_TRACE_

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace() const
{
  std::cerr << std::endl;
  trace_node(m_p_root, 0);
  std::cerr << std::endl;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace_node(node_const_pointer p_nd, size_type level)
{
  while (p_nd != 0)
    {
      for (size_type i = 0; i < level; ++i)
	std::cerr << ' ';

      std::cerr << p_nd <<
	" prev = " << p_nd->m_p_prev_or_parent <<
	" next " << p_nd->m_p_next_sibling <<
	" left = " << p_nd->m_p_l_child << " ";

      trace_node_metadata(p_nd, type_to_type<node_metadata>());
      std::cerr << p_nd->m_value << std::endl;
      trace_node(p_nd->m_p_l_child, level + 1);
      p_nd = p_nd->m_p_next_sibling;
    }
}

PB_DS_CLASS_T_DEC
template<typename Metadata_>
void
PB_DS_CLASS_C_DEC::
trace_node_metadata(node_const_pointer p_nd, type_to_type<Metadata_>)
{
  std::cerr << "(" << p_nd->m_metadata << ") ";
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace_node_metadata(node_const_pointer, type_to_type<null_type>)
{ }

#endif // #ifdef PB_DS_LC_NS_HEAP_TRACE_
#endif
