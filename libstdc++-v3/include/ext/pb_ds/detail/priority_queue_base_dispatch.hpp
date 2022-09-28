// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef PB_DS_PRIORITY_QUEUE_BASE_DS_DISPATCHER_HPP
#define PB_DS_PRIORITY_QUEUE_BASE_DS_DISPATCHER_HPP

#define PB_DS_ASSERT_VALID(X)						\
  _GLIBCXX_DEBUG_ONLY(X.assert_valid(__FILE__, __LINE__);)

#define PB_DS_DEBUG_VERIFY(_Cond)					\
  _GLIBCXX_DEBUG_VERIFY_AT(_Cond,					\
			   _M_message(#_Cond" assertion from %1;:%2;")	\
			   ._M_string(__FILE__)._M_integer(__LINE__)	\
			   ,__file,__line)

#include <ext/pb_ds/detail/pairing_heap_/pairing_heap_.hpp>
#include <ext/pb_ds/detail/binomial_heap_/binomial_heap_.hpp>
#include <ext/pb_ds/detail/rc_binomial_heap_/rc_binomial_heap_.hpp>
#include <ext/pb_ds/detail/binary_heap_/binary_heap_.hpp>
#include <ext/pb_ds/detail/thin_heap_/thin_heap_.hpp>

#undef PB_DS_DEBUG_VERIFY
#undef PB_DS_ASSERT_VALID

namespace __gnu_pbds
{
  namespace detail
  {
    /**
     *  @ingroup pbds
     *
     *  @{
     */

    /// Specialization for pairing_heap.
    template<typename _VTp, typename Cmp_Fn, typename _Alloc>
      struct container_base_dispatch<_VTp, Cmp_Fn, _Alloc, pairing_heap_tag,
				     null_type>
      {
	/// Dispatched type.
	typedef pairing_heap<_VTp, Cmp_Fn, _Alloc> 		type;
      };

    /// Specialization for binomial_heap.
    template<typename _VTp, typename Cmp_Fn, typename _Alloc>
      struct container_base_dispatch<_VTp, Cmp_Fn, _Alloc, binomial_heap_tag,
				     null_type>
      {
	/// Dispatched type.
	typedef binomial_heap<_VTp, Cmp_Fn, _Alloc> 		type;
      };

    /// Specialization for rc_binary_heap.
    template<typename _VTp, typename Cmp_Fn, typename _Alloc>
      struct container_base_dispatch<_VTp, Cmp_Fn, _Alloc, rc_binomial_heap_tag,
  				     null_type>
      {
	/// Dispatched type.
	typedef rc_binomial_heap<_VTp, Cmp_Fn, _Alloc>	       	type;
      };

    /// Specialization for binary_heap.
    template<typename _VTp, typename Cmp_Fn, typename _Alloc>
      struct container_base_dispatch<_VTp, Cmp_Fn, _Alloc, binary_heap_tag,
  				     null_type>
      {
	/// Dispatched type.
	typedef binary_heap<_VTp, Cmp_Fn, _Alloc> 		type;
      };

    /// Specialization for thin_heap.
    template<typename _VTp, typename Cmp_Fn, typename _Alloc>
      struct container_base_dispatch<_VTp, Cmp_Fn, _Alloc, thin_heap_tag,
  				     null_type>    
      {
	/// Dispatched type.
	typedef thin_heap<_VTp, Cmp_Fn, _Alloc> 		type;
      };
    ///@} group pbds
  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_PRIORITY_QUEUE_BASE_DS_DISPATCHER_HPP
