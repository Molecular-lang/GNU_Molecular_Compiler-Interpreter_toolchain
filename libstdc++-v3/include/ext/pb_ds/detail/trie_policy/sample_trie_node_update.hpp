// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file trie_policy/sample_trie_node_update.hpp
 * Contains a samle node update functor.
 */

#ifndef PB_DS_SAMPLE_TRIE_NODE_UPDATOR_HPP
#define PB_DS_SAMPLE_TRIE_NODE_UPDATOR_HPP

namespace __gnu_pbds
{
  /// A sample node updator.
  template<typename Node_CItr, typename Node_Itr,
	   typename _ATraits, typename _Alloc>
  class sample_trie_node_update
  {
  public:
    typedef std::size_t 		metadata_type;

  protected:
    /// Default constructor.
    sample_trie_node_update();

    /// Updates the rank of a node through a node_iterator node_it;
    /// end_nd_it is the end node iterator.
    inline void
    operator()(node_iterator, node_const_iterator) const;
  };
}
#endif // #ifndef PB_DS_SAMPLE_TRIE_NODE_UPDATOR_HPP
