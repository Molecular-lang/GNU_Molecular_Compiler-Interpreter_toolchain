// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef PB_DS_TREE_POLICY_HPP
#define PB_DS_TREE_POLICY_HPP

#include <bits/c++config.h>
#include <iterator>
#include <ext/pb_ds/detail/type_utils.hpp>
#include <ext/pb_ds/detail/branch_policy/branch_policy.hpp>

namespace __gnu_pbds
{
#define PB_DS_CLASS_T_DEC \
  template<typename Node_CItr, typename Node_Itr, typename Cmp_Fn, \
	   typename _Alloc>

#define PB_DS_CLASS_C_DEC \
  tree_order_statistics_node_update<Node_CItr, Node_Itr, Cmp_Fn, _Alloc>

#define PB_DS_BRANCH_POLICY_BASE \
  detail::branch_policy<Node_CItr, Node_Itr, _Alloc>

  /// Functor updating ranks of entrees.
  template<typename Node_CItr, typename Node_Itr, 
	   typename Cmp_Fn, typename _Alloc>
  class tree_order_statistics_node_update : private PB_DS_BRANCH_POLICY_BASE
  {
  private:
    typedef PB_DS_BRANCH_POLICY_BASE 		       	base_type;

  public:
    typedef Cmp_Fn 					cmp_fn;
    typedef _Alloc 					allocator_type;
    typedef typename allocator_type::size_type 		size_type;
    typedef typename base_type::key_type 		key_type;
    typedef typename base_type::key_const_reference 	key_const_reference;

    typedef size_type 					metadata_type;
    typedef Node_CItr 	       			node_const_iterator;
    typedef Node_Itr 					node_iterator;
    typedef typename node_const_iterator::value_type 	const_iterator;
    typedef typename node_iterator::value_type 		iterator;

    /// Finds an entry by __order. Returns a const_iterator to the
    /// entry with the __order order, or a const_iterator to the
    /// container object's end if order is at least the size of the
    /// container object.
    inline const_iterator
    find_by_order(size_type) const;

    /// Finds an entry by __order. Returns an iterator to the entry
    /// with the __order order, or an iterator to the container
    /// object's end if order is at least the size of the container
    /// object.
    inline iterator
    find_by_order(size_type);

    /// Returns the order of a key within a sequence. For exapmle, if
    /// r_key is the smallest key, this method will return 0; if r_key
    /// is a key between the smallest and next key, this method will
    /// return 1; if r_key is a key larger than the largest key, this
    /// method will return the size of r_c.
    inline size_type
    order_of_key(key_const_reference) const;

  private:
    /// Const reference to the container's value-type.
    typedef typename base_type::const_reference 	const_reference;

    /// Const pointer to the container's value-type.
    typedef typename base_type::const_pointer 		const_pointer;

    /// Const metadata reference.
    typedef typename detail::rebind_traits<_Alloc, metadata_type>::const_reference
      metadata_const_reference;

    /// Metadata reference.
    typedef typename detail::rebind_traits<_Alloc, metadata_type>::reference
      metadata_reference;

    /// Returns the node_const_iterator associated with the tree's root node.
    virtual node_const_iterator
    node_begin() const = 0;

    /// Returns the node_iterator associated with the tree's root node.
    virtual node_iterator
    node_begin() = 0;

    /// Returns the node_const_iterator associated with a just-after leaf node.
    virtual node_const_iterator
    node_end() const = 0;

    /// Returns the node_iterator associated with a just-after leaf node.
    virtual node_iterator
    node_end() = 0;

    /// Access to the cmp_fn object.
    virtual cmp_fn& 
    get_cmp_fn() = 0;

  protected:
    /// Updates the rank of a node through a node_iterator node_it;
    /// end_nd_it is the end node iterator.
    inline void
    operator()(node_iterator, node_const_iterator) const;

    virtual
    ~tree_order_statistics_node_update();
  };

#include <ext/pb_ds/detail/tree_policy/order_statistics_imp.hpp>

#undef PB_DS_CLASS_T_DEC
#undef PB_DS_CLASS_C_DEC
#undef PB_DS_BRANCH_POLICY_BASE

} // namespace __gnu_pbds

#endif 
