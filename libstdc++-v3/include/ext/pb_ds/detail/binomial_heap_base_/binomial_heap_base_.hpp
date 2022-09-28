// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binomial_heap_base_/binomial_heap_base_.hpp
 * Contains an implementation class for a base of binomial heaps.
 */

#ifndef PB_DS_BINOMIAL_HEAP_BASE_HPP
#define PB_DS_BINOMIAL_HEAP_BASE_HPP

/*
 * Binomial heap base.
 * Vuillemin J is the mastah.
 * Modified from CLRS.
 */

#include <debug/debug.h>
#include <ext/pb_ds/detail/cond_dealtor.hpp>
#include <ext/pb_ds/detail/type_utils.hpp>
#include <ext/pb_ds/detail/left_child_next_sibling_heap_/left_child_next_sibling_heap_.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
#define PB_DS_CLASS_T_DEC \
    template<typename Value_Type, typename Cmp_Fn, typename _Alloc>

#define PB_DS_CLASS_C_DEC \
    binomial_heap_base<Value_Type, Cmp_Fn, _Alloc>

#ifdef _GLIBCXX_DEBUG
#define PB_DS_B_HEAP_BASE \
  left_child_next_sibling_heap<Value_Type, Cmp_Fn, \
				typename _Alloc::size_type,  _Alloc, false>
#else
#define PB_DS_B_HEAP_BASE \
  left_child_next_sibling_heap<Value_Type, Cmp_Fn, \
				typename _Alloc::size_type, _Alloc>
#endif

    /// Base class for binomial heap.
    template<typename Value_Type, typename Cmp_Fn, typename _Alloc>
    class binomial_heap_base
    : public PB_DS_B_HEAP_BASE
    {
    private:
      typedef rebind_traits<_Alloc, Value_Type>		__rebind_v;
      typedef PB_DS_B_HEAP_BASE	  			base_type;

    protected:
      typedef typename base_type::node 			node;
      typedef typename base_type::node_pointer 		node_pointer;
      typedef typename base_type::node_const_pointer 	node_const_pointer;

    public:
      typedef Value_Type 				value_type;
      typedef Cmp_Fn 					cmp_fn;
      typedef _Alloc 					allocator_type;
      typedef typename _Alloc::size_type 		size_type;
      typedef typename _Alloc::difference_type 		difference_type;

      typedef typename __rebind_v::pointer 		pointer;
      typedef typename __rebind_v::const_pointer 	const_pointer;
      typedef typename __rebind_v::reference 		reference;
      typedef typename __rebind_v::const_reference   	const_reference;

      typedef typename base_type::point_const_iterator 	point_const_iterator;
      typedef typename base_type::point_iterator 	point_iterator;
      typedef typename base_type::const_iterator 	const_iterator;
      typedef typename base_type::iterator 		iterator;

    public:

      inline point_iterator
      push(const_reference);

      void
      modify(point_iterator, const_reference);

      inline const_reference
      top() const;

      void
      pop();

      void
      erase(point_iterator);

      inline void
      clear();

      template<typename Pred>
      size_type
      erase_if(Pred);

      template<typename Pred>
      void
      split(Pred, PB_DS_CLASS_C_DEC&);

      void
      join(PB_DS_CLASS_C_DEC&);

    protected:

      binomial_heap_base();

      binomial_heap_base(const Cmp_Fn&);

      binomial_heap_base(const PB_DS_CLASS_C_DEC&);

      void
      swap(PB_DS_CLASS_C_DEC&);

      ~binomial_heap_base();

      template<typename It>
      void
      copy_from_range(It, It);

      inline void
      find_max();

#ifdef _GLIBCXX_DEBUG
      void
      assert_valid(bool, const char*, int) const;

      void
      assert_max(const char*, int) const;
#endif

    private:

      inline node_pointer
      fix(node_pointer) const;

      inline void
      insert_node(node_pointer);

      inline void
      remove_parentless_node(node_pointer);

      inline node_pointer
      join(node_pointer, node_pointer) const;

#ifdef _GLIBCXX_DEBUG
      void
      assert_node_consistent(node_const_pointer, bool, bool,
			     const char*, int) const;
#endif

    protected:
      node_pointer 	m_p_max;
    };

#define PB_DS_ASSERT_VALID_COND(X, _StrictlyBinomial)			\
  _GLIBCXX_DEBUG_ONLY(X.assert_valid(_StrictlyBinomial,__FILE__, __LINE__);)

#define PB_DS_ASSERT_BASE_NODE_CONSISTENT(_Node, _Bool)			\
  _GLIBCXX_DEBUG_ONLY(base_type::assert_node_consistent(_Node, _Bool,	\
							__FILE__, __LINE__);)

#include <ext/pb_ds/detail/binomial_heap_base_/constructors_destructor_fn_imps.hpp>
#include <ext/pb_ds/detail/binomial_heap_base_/debug_fn_imps.hpp>
#include <ext/pb_ds/detail/binomial_heap_base_/find_fn_imps.hpp>
#include <ext/pb_ds/detail/binomial_heap_base_/insert_fn_imps.hpp>
#include <ext/pb_ds/detail/binomial_heap_base_/erase_fn_imps.hpp>
#include <ext/pb_ds/detail/binomial_heap_base_/split_join_fn_imps.hpp>

#undef PB_DS_ASSERT_BASE_NODE_CONSISTENT
#undef PB_DS_ASSERT_VALID_COND
#undef PB_DS_CLASS_C_DEC
#undef PB_DS_CLASS_T_DEC
#undef PB_DS_B_HEAP_BASE
  } // namespace detail
} // namespace __gnu_pbds

#endif
