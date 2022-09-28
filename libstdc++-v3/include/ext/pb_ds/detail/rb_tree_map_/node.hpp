// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file rb_tree_map_/node.hpp
 * Contains an implementation for rb_tree_.
 */

#ifndef PB_DS_RB_TREE_NODE_HPP
#define PB_DS_RB_TREE_NODE_HPP

#include <ext/pb_ds/detail/branch_policy/null_node_metadata.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Node for Red-Black trees.
    template<typename Value_Type, class Metadata, typename _Alloc>
    struct rb_tree_node_
    {
    public:
      typedef Value_Type 		value_type;
      typedef Metadata 			metadata_type;

      typedef typename rebind_traits<_Alloc, rb_tree_node_>::pointer
	node_pointer;

      typedef typename rebind_traits<_Alloc, metadata_type>::reference
	metadata_reference;

      typedef typename rebind_traits<_Alloc, metadata_type>::const_reference
	metadata_const_reference;

      bool
      special() const
      { return m_red; }

      metadata_const_reference
      get_metadata() const
      { return m_metadata; }

      metadata_reference
      get_metadata()
      { return m_metadata; }

#ifdef PB_DS_BIN_SEARCH_TREE_TRACE_
      void
      trace() const
      {
	std::cout << PB_DS_V2F(m_value) <<(m_red? " <r> " : " <b> ") 
		  << "(" << m_metadata << ")";
      }
#endif

      node_pointer 	m_p_left;
      node_pointer 	m_p_right;
      node_pointer 	m_p_parent;
      value_type 	m_value;
      bool 		m_red;
      metadata_type 	m_metadata;
    };

    template<typename Value_Type, typename _Alloc>
    struct rb_tree_node_<Value_Type, null_type, _Alloc>
    {
    public:
      typedef Value_Type 		value_type;
      typedef null_type 	metadata_type;

      typedef typename rebind_traits<_Alloc, rb_tree_node_>::pointer
	node_pointer;

      bool
      special() const
      { return m_red; }

#ifdef PB_DS_BIN_SEARCH_TREE_TRACE_
      void
      trace() const
      { std::cout << PB_DS_V2F(m_value) <<(m_red? " <r> " : " <b> "); }
#endif 

      node_pointer 	m_p_left;
      node_pointer 	m_p_right;
      node_pointer 	m_p_parent;
      value_type 	m_value;
      bool 		m_red;
    };
  } // namespace detail
} // namespace __gnu_pbds

#endif 
