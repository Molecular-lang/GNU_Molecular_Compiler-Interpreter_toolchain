// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file branch_policy/traits.hpp
 * Contains an implementation class for tree-like classes.
 */

#ifndef PB_DS_NODE_AND_IT_TRAITS_HPP
#define PB_DS_NODE_AND_IT_TRAITS_HPP

#include <ext/pb_ds/detail/types_traits.hpp>
#include <ext/pb_ds/detail/bin_search_tree_/traits.hpp>
#include <ext/pb_ds/detail/tree_policy/node_metadata_selector.hpp>
#include <ext/pb_ds/detail/trie_policy/node_metadata_selector.hpp>

#define PB_DS_DEBUG_VERIFY(_Cond)					\
  _GLIBCXX_DEBUG_VERIFY_AT(_Cond,					\
			   _M_message(#_Cond" assertion from %1;:%2;")	\
			   ._M_string(__FILE__)._M_integer(__LINE__)	\
			   ,__file,__line)

namespace __gnu_pbds
{
  namespace detail
  {
    /// Tree traits class, primary template.
    template<typename Key,
	     typename Data,
	     typename Cmp_Fn,
	     template<typename Node_CItr,
		      typename Node_Itr,
		      typename Cmp_Fn_,
		      typename _Alloc>
	     class Node_Update,
	     typename Tag,
	     typename _Alloc>
    struct tree_traits;

    /// Trie traits class, primary template.
    template<typename Key,
	     typename Data,
	     typename _ATraits,
	     template<typename Node_CItr,
		      typename Node_Itr,
		      typename _ATraits_,
		      typename _Alloc>
	     class Node_Update,
	     typename Tag,
	     typename _Alloc>
    struct trie_traits;

  } // namespace detail
} // namespace __gnu_pbds

#include <ext/pb_ds/detail/rb_tree_map_/traits.hpp>
#include <ext/pb_ds/detail/splay_tree_/traits.hpp>
#include <ext/pb_ds/detail/ov_tree_map_/traits.hpp>
#include <ext/pb_ds/detail/pat_trie_/traits.hpp>

#undef PB_DS_DEBUG_VERIFY

#endif // #ifndef PB_DS_NODE_AND_IT_TRAITS_HPP
