// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef PB_DS_PRIORITY_QUEUE_HPP
#define PB_DS_PRIORITY_QUEUE_HPP

#include <bits/c++config.h>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/detail/priority_queue_base_dispatch.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

namespace __gnu_pbds
{
  /**
   *  @defgroup heap-based Heap-Based
   *  @ingroup containers-pbds
   *
   *  @{
   */

  /**
   *  @defgroup heap-detail Base and Policy Classes
   *  @ingroup heap-based
   */

  /**
   *  A priority queue composed of one specific heap policy.
   *
   *  @tparam _Tv 	    	Value type.
   *  @tparam Cmp_Fn	    	Comparison functor.
   *  @tparam Tag 	    	Instantiating data structure type,
   *			    	see container_tag.
   *  @tparam _Alloc 	    	Allocator type.
   *
   *  Base is dispatched at compile time via Tag, from the following
   *  choices: binary_heap_tag, binomial_heap_tag, pairing_heap_tag,
   *           rc_binomial_heap_tag, thin_heap_tag
   *
   *  Base choices are: detail::binary_heap, detail::binomial_heap,
   *                    detail::pairing_heap, detail::rc_binomial_heap,
   *                    detail::thin_heap.
   */
   template<typename _Tv,
	   typename Cmp_Fn = std::less<_Tv>,
	   typename Tag = pairing_heap_tag,
	   typename _Alloc = std::allocator<char> >
  class priority_queue
  : public detail::container_base_dispatch<_Tv, Cmp_Fn, _Alloc, Tag>::type
  {
  public:
    typedef _Tv 					value_type;
    typedef Cmp_Fn 					cmp_fn;
    typedef Tag 					container_category;
    typedef _Alloc 					allocator_type;
    typedef typename allocator_type::size_type 		size_type;
    typedef typename allocator_type::difference_type 	difference_type;

  private:
    typedef typename detail::container_base_dispatch<_Tv, Cmp_Fn, _Alloc,
						     Tag>::type
 							base_type;
    typedef detail::rebind_traits<_Alloc, _Tv>		__rebind_va;

 public:
    typedef typename __rebind_va::reference 		reference;
    typedef typename __rebind_va::const_reference 	const_reference;
    typedef typename __rebind_va::pointer 	   	pointer;
    typedef typename __rebind_va::const_pointer 	const_pointer;

    typedef typename base_type::point_iterator 		point_iterator;
    typedef typename base_type::point_const_iterator 	point_const_iterator;
    typedef typename base_type::iterator 		iterator;
    typedef typename base_type::const_iterator 		const_iterator;

    priority_queue() { }

    /// Constructor taking some policy objects. r_cmp_fn will be
    /// copied by the Cmp_Fn object of the container object.
    priority_queue(const cmp_fn& r_cmp_fn) : base_type(r_cmp_fn) { }

    /// Constructor taking __iterators to a range of value_types. The
    /// value_types between first_it and last_it will be inserted into
    /// the container object.
    template<typename It>
    priority_queue(It first_it, It last_it)
    { base_type::copy_from_range(first_it, last_it); }

    /// Constructor taking __iterators to a range of value_types and
    /// some policy objects The value_types between first_it and
    /// last_it will be inserted into the container object. r_cmp_fn
    /// will be copied by the cmp_fn object of the container object.
    template<typename It>
    priority_queue(It first_it, It last_it, const cmp_fn& r_cmp_fn)
    : base_type(r_cmp_fn)
    { base_type::copy_from_range(first_it, last_it); }

    priority_queue(const priority_queue& other)
    : base_type((const base_type& )other) { }

    virtual
    ~priority_queue() { }

    priority_queue&
    operator=(const priority_queue& other)
    {
      if (this != &other)
	{
	  priority_queue tmp(other);
	  swap(tmp);
	}
      return *this;
    }

    void
    swap(priority_queue& other)
    { base_type::swap(other); }
  };
 ///@} heap-based
} // namespace __gnu_pbds
#endif
