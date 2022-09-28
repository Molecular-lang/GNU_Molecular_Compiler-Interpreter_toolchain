// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file ov_tree_map_/traits.hpp
 * Contains an implementation class for ov_tree_.
 */

#ifndef PB_DS_OV_TREE_NODE_AND_IT_TRAITS_HPP
#define PB_DS_OV_TREE_NODE_AND_IT_TRAITS_HPP

#include <ext/pb_ds/detail/ov_tree_map_/node_iterators.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Tree traits.
    /// @ingroup traits
    template<typename Key,
	     typename Mapped,
	     class Cmp_Fn,
	     template<typename Node_CItr,
		      class Node_Itr,
		      class Cmp_Fn_,
		      typename _Alloc_>
    class Node_Update,
	     typename _Alloc>
    struct tree_traits<
      Key,
      Mapped,
      Cmp_Fn,
      Node_Update,
      ov_tree_tag,
      _Alloc>
    {
    private:
      typedef
      typename types_traits<
      Key,
      Mapped,
      _Alloc,
      false>::value_type
      value_type;

    public:
      typedef
      typename tree_node_metadata_dispatch<
      Key,
      Mapped,
      Cmp_Fn,
      Node_Update,
      _Alloc>::type
      metadata_type;

      /// This is an iterator to an iterator: it iterates over nodes,
      /// and de-referencing it returns one of the tree's iterators.
      typedef
      ov_tree_node_const_it_<
	value_type,
	metadata_type,
	_Alloc>
      node_const_iterator;

      typedef
      ov_tree_node_it_<
	value_type,
	metadata_type,
	_Alloc>
      node_iterator;

      typedef
      Node_Update<
	node_const_iterator,
	node_iterator,
	Cmp_Fn,
	_Alloc>
      node_update;

      typedef
      __gnu_pbds::null_node_update<
	node_const_iterator,
	node_iterator,
	Cmp_Fn,
	_Alloc>* 
      null_node_update_pointer;
    };


    /// Specialization.
    /// @ingroup traits
    template<typename Key,
	     class Cmp_Fn,
	     template<typename Node_CItr,
		      class Node_Itr,
		      class Cmp_Fn_,
		      typename _Alloc_>
    class Node_Update,
	     typename _Alloc>
    struct tree_traits<
      Key,
      null_type,
      Cmp_Fn,
      Node_Update,
      ov_tree_tag,
      _Alloc>
    {
    private:
      typedef
      typename types_traits<
      Key,
      null_type,
      _Alloc,
      false>::value_type
      value_type;

    public:
      typedef
      typename tree_node_metadata_dispatch<
      Key,
      null_type,
      Cmp_Fn,
      Node_Update,
      _Alloc>::type
      metadata_type;

      /// This is an iterator to an iterator: it iterates over nodes,
      /// and de-referencing it returns one of the tree's iterators.
      typedef
      ov_tree_node_const_it_<
	value_type,
	metadata_type,
	_Alloc>
      node_const_iterator;

      typedef node_const_iterator node_iterator;

      typedef
      Node_Update<
	node_const_iterator,
	node_const_iterator,
	Cmp_Fn,
	_Alloc>
      node_update;

      typedef
      __gnu_pbds::null_node_update<
	node_const_iterator,
	node_iterator,
	Cmp_Fn,
	_Alloc>* 
      null_node_update_pointer;
    };
  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_OV_TREE_NODE_AND_IT_TRAITS_HPP

