// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file left_child_next_sibling_heap_/node.hpp
 * Contains an implementation struct for this type of heap's node.
 */

#ifndef PB_DS_LEFT_CHILD_NEXT_SIBLING_HEAP_NODE_HPP
#define PB_DS_LEFT_CHILD_NEXT_SIBLING_HEAP_NODE_HPP

#include <ext/pb_ds/detail/types_traits.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Node.
    template<typename _Value, typename _Metadata, typename _Alloc>
    struct left_child_next_sibling_heap_node_
    {
    private:
      typedef left_child_next_sibling_heap_node_<_Value, _Metadata, _Alloc> this_type;

    public:
      typedef _Value 				value_type;
      typedef typename _Alloc::size_type 	size_type;
      typedef _Metadata 			metadata_type;

      typedef typename rebind_traits<_Alloc, this_type>::pointer node_pointer;

      value_type 	m_value;
      metadata_type 	m_metadata;
      node_pointer 	m_p_l_child;
      node_pointer 	m_p_next_sibling;
      node_pointer 	m_p_prev_or_parent;
    };

    template<typename _Value, typename _Alloc>
    struct left_child_next_sibling_heap_node_<_Value, null_type, _Alloc>
    {
    private:
      typedef left_child_next_sibling_heap_node_<_Value, null_type, _Alloc> this_type;

    public:
      typedef _Value 				value_type;
      typedef typename _Alloc::size_type 	size_type;

      typedef typename rebind_traits<_Alloc, this_type>::pointer node_pointer;

      value_type 	m_value;
      node_pointer 	m_p_l_child;
      node_pointer 	m_p_next_sibling;
      node_pointer 	m_p_prev_or_parent;
    };

  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_LEFT_CHILD_NEXT_SIBLING_HEAP_NODE_HPP
