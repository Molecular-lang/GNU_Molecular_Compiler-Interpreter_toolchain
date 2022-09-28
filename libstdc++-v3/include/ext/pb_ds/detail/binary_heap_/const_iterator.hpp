// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/const_iterator.hpp
 * Contains an iterator class returned by the table's const find and insert
 *     methods.
 */

#ifndef PB_DS_BINARY_HEAP_CONST_ITERATOR_HPP
#define PB_DS_BINARY_HEAP_CONST_ITERATOR_HPP

#include <ext/pb_ds/detail/binary_heap_/point_const_iterator.hpp>
#include <debug/debug.h>

namespace __gnu_pbds
{
  namespace detail
  {
#define PB_DS_BIN_HEAP_CIT_BASE \
    binary_heap_point_const_iterator_<Value_Type, Entry, Simple, _Alloc>

    /// Const point-type iterator.
    template<typename Value_Type,
	     typename Entry,
	     bool Simple,
	     typename _Alloc>
    class binary_heap_const_iterator_ : public PB_DS_BIN_HEAP_CIT_BASE
    {
    private:
      typedef PB_DS_BIN_HEAP_CIT_BASE 		       	base_type;
      typedef typename base_type::entry_pointer 	entry_pointer;

    public:
      /// Category.
      typedef std::forward_iterator_tag 		iterator_category;

      /// Difference type.
      typedef typename _Alloc::difference_type 		difference_type;

      /// Iterator's value type.
      typedef typename base_type::value_type 		value_type;

      /// Iterator's pointer type.
      typedef typename base_type::pointer 		pointer;

      /// Iterator's const pointer type.
      typedef typename base_type::const_pointer 	const_pointer;

      /// Iterator's reference type.
      typedef typename base_type::reference 		reference;

      /// Iterator's const reference type.
      typedef typename base_type::const_reference 	const_reference;

      inline
      binary_heap_const_iterator_(entry_pointer p_e) : base_type(p_e)
      { }

      /// Default constructor.
      inline
      binary_heap_const_iterator_()
      { }

      /// Copy constructor.
      inline
      binary_heap_const_iterator_(const binary_heap_const_iterator_& other) 
      : base_type(other)
      { }

      /// Compares content to a different iterator object.
      inline bool
      operator==(const binary_heap_const_iterator_& other) const
      { return base_type::m_p_e == other.m_p_e; }

      /// Compares content (negatively) to a different iterator object.
      inline bool
      operator!=(const binary_heap_const_iterator_& other) const
      { return base_type::m_p_e != other.m_p_e; }

      inline binary_heap_const_iterator_& 
      operator++()
      {
	_GLIBCXX_DEBUG_ASSERT(base_type::m_p_e != 0);
	inc();
	return *this;
      }

      inline binary_heap_const_iterator_
      operator++(int)
      {
	binary_heap_const_iterator_ ret_it(base_type::m_p_e);
	operator++();
	return ret_it;
      }

    private:
      void
      inc()
      { ++base_type::m_p_e; }
    };

#undef PB_DS_BIN_HEAP_CIT_BASE
  } // namespace detail
} // namespace __gnu_pbds

#endif 
