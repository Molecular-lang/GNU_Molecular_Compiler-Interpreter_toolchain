// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file trie_policy/node_metadata_selector.hpp
 * Contains an implementation class for tries.
 */

#ifndef PB_DS_TRIE_NODE_METADATA_DISPATCH_HPP
#define PB_DS_TRIE_NODE_METADATA_DISPATCH_HPP

#include <ext/pb_ds/detail/branch_policy/null_node_metadata.hpp>
#include <ext/pb_ds/detail/types_traits.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /**
     *  @addtogroup traits Traits
     *  @{
     */

    /// Trie metadata helper.
    template<typename Node_Update, bool _BTp>
      struct trie_metadata_helper;

    /// Specialization, false.
    template<typename Node_Update>
      struct trie_metadata_helper<Node_Update, false>
      {
	typedef typename Node_Update::metadata_type 	type;
      };

    /// Specialization, true.
    template<typename Node_Update>
      struct trie_metadata_helper<Node_Update, true>
      {
	typedef null_type 				type;
      };

    /// Trie node metadata dispatch.
    template<typename Key,
	     typename Data,
	     typename Cmp_Fn,
	     template<typename Node_CItr,
		      typename Const_Iterator,
		      typename Cmp_Fn_,
		      typename _Alloc_>
	     class Node_Update,
	     typename _Alloc>
    struct trie_node_metadata_dispatch
    {
    private:
      typedef dumnode_const_iterator<Key, Data, _Alloc>		__it_type;
      typedef Node_Update<__it_type, __it_type, Cmp_Fn, _Alloc>	__node_u;
      typedef null_node_update<__it_type, __it_type, Cmp_Fn, _Alloc> __nnode_u;

      enum
	{
	  null_update = is_same<__node_u, __nnode_u>::value
	};

    public:
      typedef typename trie_metadata_helper<__node_u, null_update>::type type;
    };
    ///@}
  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_TRIE_NODE_METADATA_DISPATCH_HPP
