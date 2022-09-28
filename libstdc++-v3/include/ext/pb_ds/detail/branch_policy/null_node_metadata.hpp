// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file branch_policy/null_node_metadata.hpp
 * Contains an implementation class for tree-like classes.
 */

#ifndef PB_DS_0_NODE_METADATA_HPP
#define PB_DS_0_NODE_METADATA_HPP

#include <ext/pb_ds/detail/types_traits.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Constant node iterator.
    template<typename Key, typename Data, typename _Alloc>
      struct dumnode_const_iterator
      {
      private:
	typedef types_traits<Key, Data, _Alloc, false>	__traits_type;
	typedef typename __traits_type::pointer        	const_iterator;
	
      public:
	typedef const_iterator 				value_type;
	typedef const_iterator 				const_reference;
	typedef const_reference 	       		reference;
      };
  } // namespace detail
} // namespace __gnu_pbds

#endif
