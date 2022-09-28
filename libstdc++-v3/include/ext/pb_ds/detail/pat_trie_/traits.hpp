// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pat_trie_/traits.hpp
 * Contains an implementation class for pat_trie_.
 */

#ifndef PB_DS_PAT_TRIE_NODE_AND_IT_TRAITS_HPP
#define PB_DS_PAT_TRIE_NODE_AND_IT_TRAITS_HPP

#include <ext/pb_ds/detail/pat_trie_/pat_trie_base.hpp>
#include <ext/pb_ds/detail/pat_trie_/synth_access_traits.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Specialization.
    /// @ingroup traits
    template<typename Key,
	     typename Mapped,
	     typename _ATraits,
	     template<typename Node_CItr,
		      typename Node_Itr,
		      typename Cmp_Fn_,
		      typename _Alloc_>
	     class Node_Update,
	     typename _Alloc>
    struct trie_traits<Key, Mapped, _ATraits, Node_Update, pat_trie_tag, _Alloc>
    {
    private:
      typedef pat_trie_base				    	base_type;
      typedef types_traits<Key, Mapped, _Alloc, false> 		type_traits;

    public:
      typedef typename trie_node_metadata_dispatch<Key, Mapped, _ATraits, Node_Update, _Alloc>::type metadata_type;
      typedef base_type::_Metadata<metadata_type, _Alloc>      	metadata;
      typedef _ATraits 		       			       	access_traits;

      /// Type for synthesized traits.
      typedef __gnu_pbds::detail::synth_access_traits<type_traits, false, access_traits>   synth_access_traits;

      typedef base_type::_Node_base<synth_access_traits, metadata>     	node;
      typedef base_type::_Head<synth_access_traits, metadata>	       	head;
      typedef base_type::_Leaf<synth_access_traits, metadata>	       	leaf;
      typedef base_type::_Inode<synth_access_traits, metadata> 		inode;

      typedef base_type::_Iter<node, leaf, head, inode, true>	       	iterator;
      typedef base_type::_CIter<node, leaf, head, inode, true> 	 	const_iterator;
      typedef base_type::_Iter<node, leaf, head, inode, false> 		reverse_iterator;
      typedef base_type::_CIter<node, leaf, head, inode, false>	 	const_reverse_iterator;

      /// This is an iterator to an iterator: it iterates over nodes,
      /// and de-referencing it returns one of the tree's iterators.
      typedef base_type::_Node_citer<node, leaf, head, inode, const_iterator, iterator, _Alloc> node_const_iterator;

      typedef base_type::_Node_iter<node, leaf, head, inode, const_iterator, iterator, _Alloc> node_iterator;

      /// Type for node update.
      typedef Node_Update<node_const_iterator, node_iterator, _ATraits, _Alloc> 		node_update;

      typedef null_node_update<node_const_iterator, node_iterator, _ATraits, _Alloc>* 		null_node_update_pointer;
    };


    /// Specialization.
    /// @ingroup traits
    template<typename Key,
	     typename _ATraits,
	     template<typename Node_CItr,
		      typename Node_Itr,
		      typename Cmp_Fn_,
		      typename _Alloc_>
	     class Node_Update,
	     typename _Alloc>
    struct trie_traits<Key, null_type, _ATraits, Node_Update, pat_trie_tag, _Alloc>
    {
    private:
      typedef pat_trie_base					base_type;
      typedef types_traits<Key, null_type, _Alloc, false> 	type_traits;

    public:
      typedef typename trie_node_metadata_dispatch<Key, null_type, _ATraits, Node_Update, _Alloc>::type metadata_type;
      typedef base_type::_Metadata<metadata_type, _Alloc>				metadata;
      typedef _ATraits 				     					access_traits;

      /// Type for synthesized traits.
      typedef __gnu_pbds::detail::synth_access_traits<type_traits, true, access_traits> synth_access_traits;

      typedef base_type::_Node_base<synth_access_traits, metadata>     	node;
      typedef base_type::_Head<synth_access_traits, metadata> 	       	head;
      typedef base_type::_Leaf<synth_access_traits, metadata> 	       	leaf;
      typedef base_type::_Inode<synth_access_traits, metadata> 	       	inode;

      typedef base_type::_CIter<node, leaf, head, inode, true> 		const_iterator;
      typedef const_iterator 					       	iterator;
      typedef base_type::_CIter<node, leaf, head, inode, false>	       	const_reverse_iterator;
      typedef const_reverse_iterator 			       		reverse_iterator;

      /// This is an iterator to an iterator: it iterates over nodes,
      /// and de-referencing it returns one of the tree's iterators.
      typedef base_type::_Node_citer<node, leaf, head, inode, const_iterator, iterator, _Alloc> node_const_iterator;

      typedef node_const_iterator 								node_iterator;

      /// Type for node update.
      typedef Node_Update<node_const_iterator, node_iterator, _ATraits, _Alloc> 		node_update;

      typedef null_node_update<node_const_iterator, node_const_iterator, _ATraits, _Alloc>* 	null_node_update_pointer;
    };

  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_PAT_TRIE_NODE_AND_IT_TRAITS_HPP
