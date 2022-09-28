// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file splay_tree_/node.hpp
 * Contains an implementation struct for splay_tree_'s node.
 */

#ifndef PB_DS_SPLAY_TREE_NODE_HPP
#define PB_DS_SPLAY_TREE_NODE_HPP

namespace __gnu_pbds
{
  namespace detail
  {
    /// Node for splay tree.
    template<typename Value_Type, class Metadata, typename _Alloc>
    struct splay_tree_node_
    {
    public:
      typedef Value_Type value_type;
      typedef Metadata metadata_type;

      typedef typename rebind_traits<_Alloc, splay_tree_node_>::pointer
	node_pointer;

      typedef typename rebind_traits<_Alloc, metadata_type>::reference
	metadata_reference;

      typedef typename rebind_traits<_Alloc, metadata_type>::const_reference
	metadata_const_reference;

#ifdef PB_DS_BIN_SEARCH_TREE_TRACE_
      void
      trace() const
      { std::cout << PB_DS_V2F(m_value) << "(" << m_metadata << ")"; }
#endif

      inline bool
      special() const
      { return m_special; }

      inline metadata_const_reference
      get_metadata() const
      { return m_metadata; }

      inline metadata_reference
      get_metadata()
      { return m_metadata; }

      value_type m_value;
      bool m_special;
      node_pointer m_p_left;
      node_pointer m_p_right;
      node_pointer m_p_parent;
      metadata_type m_metadata;
    };

    template<typename Value_Type, typename _Alloc>
    struct splay_tree_node_<Value_Type, null_type, _Alloc>
    {
    public:
      typedef Value_Type value_type;
      typedef null_type metadata_type;

      typedef typename rebind_traits<_Alloc, splay_tree_node_>::pointer
	node_pointer;

      inline bool
      special() const
      { return m_special; }

#ifdef PB_DS_BIN_SEARCH_TREE_TRACE_
      void
      trace() const
      { std::cout << PB_DS_V2F(m_value); }
#endif 

      node_pointer m_p_left;
      node_pointer m_p_right;
      node_pointer m_p_parent;
      value_type m_value;
      bool m_special;
    };
  } // namespace detail
} // namespace __gnu_pbds

#endif 
