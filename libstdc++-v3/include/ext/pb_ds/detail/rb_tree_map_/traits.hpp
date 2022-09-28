// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file rb_tree_map_/traits.hpp
 * Contains an implementation for rb_tree_.
 */

#ifndef PB_DS_RB_TREE_NODE_AND_IT_TRAITS_HPP
#define PB_DS_RB_TREE_NODE_AND_IT_TRAITS_HPP

#include <ext/pb_ds/detail/rb_tree_map_/node.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Specialization.
    /// @ingroup traits
    template<typename Key,
	     typename Mapped,
	     typename Cmp_Fn,
	     template<typename Node_CItr,
		      typename Node_Itr,
		      typename Cmp_Fn_,
		      typename _Alloc_>
	     class Node_Update,
	     typename _Alloc>
    struct tree_traits<Key, Mapped, Cmp_Fn, Node_Update, rb_tree_tag,_Alloc> 
    : public bin_search_tree_traits<
      Key,
      Mapped,
      Cmp_Fn,
      Node_Update,
      rb_tree_node_<
	typename types_traits<Key, Mapped, _Alloc, false>::value_type,
	typename tree_node_metadata_dispatch<Key, Mapped, Cmp_Fn, Node_Update,
					     _Alloc>::type,
	_Alloc>,
      _Alloc>
    { };

    /// Specialization.
    /// @ingroup traits
    template<typename Key,
	     typename Cmp_Fn,
	     template<typename Node_CItr,
		      typename Node_Itr,
		      typename Cmp_Fn_,
		      typename _Alloc_>
	     class Node_Update,
	     typename _Alloc>
    struct tree_traits<Key, null_type, Cmp_Fn, Node_Update, rb_tree_tag,_Alloc> 
    : public bin_search_tree_traits<
      Key,
      null_type,
      Cmp_Fn,
      Node_Update,
      rb_tree_node_<
      typename types_traits<Key, null_type, _Alloc, false>::value_type,
      typename tree_node_metadata_dispatch<Key, null_type, Cmp_Fn, Node_Update,
					   _Alloc>::type,
	_Alloc>,
	  _Alloc>
    { };

  } // namespace detail
} // namespace __gnu_pbds

#endif 
