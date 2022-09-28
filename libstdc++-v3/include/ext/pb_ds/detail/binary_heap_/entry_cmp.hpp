// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/entry_cmp.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifndef PB_DS_BINARY_HEAP_ENTRY_CMP_HPP
#define PB_DS_BINARY_HEAP_ENTRY_CMP_HPP

namespace __gnu_pbds
{
  namespace detail
  {
    /// Entry compare, primary template.
    template<typename _VTp, typename Cmp_Fn, typename _Alloc, bool No_Throw>
      struct entry_cmp;

    /// Specialization, true.
    template<typename _VTp, typename Cmp_Fn, typename _Alloc>
      struct entry_cmp<_VTp, Cmp_Fn, _Alloc, true>
      {
	/// Compare.
	typedef Cmp_Fn 						type;
      };

    /// Specialization, false.
    template<typename _VTp, typename Cmp_Fn, typename _Alloc>
      struct entry_cmp<_VTp, Cmp_Fn, _Alloc, false>
      {
      private:
	typedef rebind_traits<_Alloc, _VTp>		__rebind_v;

      public:
	typedef typename __rebind_v::const_pointer	entry;

	/// Compare plus entry.
	struct type : public Cmp_Fn
	{
	  type() { }

	  type(const Cmp_Fn& other) : Cmp_Fn(other) { }

	  bool
	  operator()(entry lhs, entry rhs) const
	  { return Cmp_Fn::operator()(*lhs, *rhs); }
	};
      };
  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_BINARY_HEAP_ENTRY_CMP_HPP
