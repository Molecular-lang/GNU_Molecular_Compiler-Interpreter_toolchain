// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file tree_policy/sample_tree_node_update.hpp
 * Contains a samle node update functor.
 */

#ifndef PB_DS_SAMPLE_TREE_NODE_UPDATOR_HPP
#define PB_DS_SAMPLE_TREE_NODE_UPDATOR_HPP

namespace __gnu_pbds
{
  /// A sample node updator.
  template<typename Const_Node_Iter, typename Node_Iter, typename Cmp_Fn,
	   typename _Alloc>
  class sample_tree_node_update
  {
    typedef std::size_t metadata_type;

    /// Default constructor.
    sample_tree_node_update();

    /// Updates the rank of a node through a node_iterator node_it;
    /// end_nd_it is the end node iterator.
    inline void
    operator()(node_iterator node_it, node_const_iterator end_nd_it) const;
  };
}
#endif // #ifndef PB_DS_SAMPLE_TREE_NODE_UPDATOR_HPP
