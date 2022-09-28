// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pat_trie_/trace_fn_imps.hpp
 * Contains an implementation class for pat_trie_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef PB_DS_PAT_TRIE_TRACE_

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace() const
{
  std::cerr << std::endl;
  if (m_p_head->m_p_parent == 0)
    return;
  trace_node(m_p_head->m_p_parent, 0);
  std::cerr << std::endl;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace_node(node_const_pointer p_nd, size_type level)
{
  for (size_type i = 0; i < level; ++i)
    std::cerr << ' ';
  std::cerr << p_nd << " ";
  std::cerr << ((p_nd->m_type == pat_trie_leaf_node_type) ? "l " : "i ");

  trace_node_metadata(p_nd, type_to_type<typename node::metadata_type>());
  typename access_traits::const_iterator el_it = pref_begin(p_nd);
  while (el_it != pref_end(p_nd))
    {
      std::cerr <<* el_it;
      ++el_it;
    }

  if (p_nd->m_type == pat_trie_leaf_node_type)
    {
      std::cerr << std::endl;
      return;
    }

  inode_const_pointer p_internal = static_cast<inode_const_pointer>(p_nd);

  std::cerr << " " <<
    static_cast<unsigned long>(p_internal->get_e_ind()) << std::endl;

  const size_type num_children = std::distance(p_internal->begin(),
					       p_internal->end());

  for (size_type child_i = 0; child_i < num_children; ++child_i)
    {
      typename inode::const_iterator child_it = p_internal->begin();
      std::advance(child_it, num_children - child_i - 1);
      trace_node(*child_it, level + 1);
    }
}

PB_DS_CLASS_T_DEC
template<typename Metadata_>
void
PB_DS_CLASS_C_DEC::
trace_node_metadata(node_const_pointer p_nd, type_to_type<Metadata_>)
{
  std::cerr << "(" << static_cast<unsigned long>(p_nd->get_metadata()) << ") ";
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace_node_metadata(node_const_pointer, type_to_type<null_type>)
{ }

#endif 

#endif
