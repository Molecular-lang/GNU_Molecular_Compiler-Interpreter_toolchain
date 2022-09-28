// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/point_const_iterator.hpp
 * Contains an iterator class returned by the table's const find and insert
 * methods.
 */

#ifndef PB_DS_BINARY_HEAP_CONST_FIND_ITERATOR_HPP
#define PB_DS_BINARY_HEAP_CONST_FIND_ITERATOR_HPP

#include <ext/pb_ds/tag_and_trait.hpp>
#include <debug/debug.h>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Const point-type iterator.
    template<typename Value_Type, typename Entry, bool Simple, 
	     typename _Alloc>
    class binary_heap_point_const_iterator_
    {
    protected:
      typedef typename rebind_traits<_Alloc, Entry>::pointer entry_pointer;

    public:
      /// Category.
      typedef trivial_iterator_tag iterator_category;

      /// Difference type.
      typedef trivial_iterator_difference_type difference_type;

      /// Iterator's value type.
      typedef Value_Type value_type;

      /// Iterator's pointer type.
      typedef typename rebind_traits<_Alloc, value_type>::pointer pointer;

      /// Iterator's const pointer type.
      typedef typename rebind_traits<_Alloc, value_type>::const_pointer
	const_pointer;

      /// Iterator's reference type.
      typedef typename rebind_traits<_Alloc, value_type>::reference
	reference;

      /// Iterator's const reference type.
      typedef typename rebind_traits<_Alloc, value_type>::const_reference
	const_reference;

      inline
      binary_heap_point_const_iterator_(entry_pointer p_e) : m_p_e(p_e)
      { }

      /// Default constructor.
      inline
      binary_heap_point_const_iterator_() : m_p_e(0) { }

      /// Copy constructor.
      inline
      binary_heap_point_const_iterator_(const binary_heap_point_const_iterator_& other)
      : m_p_e(other.m_p_e)
      { }

      /// Access.
      inline const_pointer
      operator->() const
      {
	_GLIBCXX_DEBUG_ASSERT(m_p_e != 0);
	return to_ptr(integral_constant<int, Simple>());
      }

      /// Access.
      inline const_reference
      operator*() const
      {
	_GLIBCXX_DEBUG_ASSERT(m_p_e != 0);
	return *to_ptr(integral_constant<int, Simple>());
      }

      /// Compares content to a different iterator object.
      inline bool
      operator==(const binary_heap_point_const_iterator_& other) const
      { return m_p_e == other.m_p_e; }

      /// Compares content (negatively) to a different iterator object.
      inline bool
      operator!=(const binary_heap_point_const_iterator_& other) const
      { return m_p_e != other.m_p_e; }

    private:
      inline const_pointer
      to_ptr(true_type) const
      { return m_p_e; }

      inline const_pointer
      to_ptr(false_type) const
      { return *m_p_e; }

    public:
      entry_pointer m_p_e;
    };
  } // namespace detail
} // namespace __gnu_pbds

#endif 
