// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binomial_heap_.hpp
 * Contains an implementation class for a binomial heap.
 */

/*
 * Binomial heap.
 * Vuillemin J is the mastah.
 * Modified from CLRS.
 */

#include <debug/debug.h>
#include <ext/pb_ds/detail/cond_dealtor.hpp>
#include <ext/pb_ds/detail/type_utils.hpp>
#include <ext/pb_ds/detail/binomial_heap_base_/binomial_heap_base_.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
#define PB_DS_CLASS_T_DEC \
    template<typename Value_Type, typename Cmp_Fn, typename _Alloc>

#define PB_DS_CLASS_C_DEC \
    binomial_heap<Value_Type, Cmp_Fn, _Alloc>

    /**
     *  Binomial heap.
     *
     *  @ingroup heap-detail
     */
    template<typename Value_Type, typename Cmp_Fn, typename _Alloc>
    class binomial_heap
    : public binomial_heap_base<Value_Type, Cmp_Fn, _Alloc>
    {
    private:
      typedef binomial_heap_base<Value_Type, Cmp_Fn, _Alloc> 	base_type;
      typedef typename base_type::node_pointer 		node_pointer;
      typedef typename base_type::node_const_pointer 	node_const_pointer;

    public:
      typedef Value_Type 				value_type;
      typedef typename _Alloc::size_type 		size_type;
      typedef typename _Alloc::difference_type 		difference_type;
      typedef typename base_type::pointer 		pointer;
      typedef typename base_type::const_pointer 	const_pointer;
      typedef typename base_type::reference 		reference;
      typedef typename base_type::const_reference 	const_reference;
      typedef typename base_type::point_const_iterator 	point_const_iterator;
      typedef typename base_type::point_iterator 	point_iterator;
      typedef typename base_type::const_iterator 	const_iterator;
      typedef typename base_type::iterator 		iterator;
      typedef typename base_type::cmp_fn 		cmp_fn;
      typedef typename base_type::allocator_type 	allocator_type;

      binomial_heap();

      binomial_heap(const Cmp_Fn&);

      binomial_heap(const binomial_heap&);

      ~binomial_heap();

    protected:
#ifdef _GLIBCXX_DEBUG
      void
      assert_valid(const char*, int) const;
#endif
    };

#include <ext/pb_ds/detail/binomial_heap_/constructors_destructor_fn_imps.hpp>
#include <ext/pb_ds/detail/binomial_heap_/debug_fn_imps.hpp>

#undef PB_DS_CLASS_C_DEC
#undef PB_DS_CLASS_T_DEC
  } // namespace detail
} // namespace __gnu_pbds
