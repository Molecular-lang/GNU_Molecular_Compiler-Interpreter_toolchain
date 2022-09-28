// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/entry_pred.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifndef PB_DS_BINARY_HEAP_ENTRY_PRED_HPP
#define PB_DS_BINARY_HEAP_ENTRY_PRED_HPP

namespace __gnu_pbds
{
  namespace detail
  {
    /// Entry predicate primary class template.
    template<typename _VTp, typename Pred, typename _Alloc, bool No_Throw>
      struct entry_pred;

    /// Specialization, true.
    template<typename _VTp, typename Pred, typename _Alloc>
      struct entry_pred<_VTp, Pred, _Alloc, true>
      {
	typedef Pred 						type;
      };

    /// Specialization, false.
    template<typename _VTp, typename Pred, typename _Alloc>
      struct entry_pred<_VTp, Pred, _Alloc, false>
      {
      private:
	typedef rebind_traits<_Alloc, _VTp>		__rebind_v;

      public:
	typedef typename __rebind_v::const_pointer	entry;

	struct type : public Pred
	{
	  inline
	  type() { }

	  inline
	  type(const Pred& other) : Pred(other) { }

	  inline bool
	  operator()(entry p_v) const
	  { return Pred::operator()(*p_v); }
	};
      };
  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_BINARY_HEAP_ENTRY_PRED_HPP
