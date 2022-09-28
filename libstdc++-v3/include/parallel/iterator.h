// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file parallel/iterator.h
 * @brief Helper iterator classes for the std::transform() functions.
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

// Written by Johannes Singler.

#ifndef _GLIBCXX_PARALLEL_ITERATOR_H
#define _GLIBCXX_PARALLEL_ITERATOR_H 1

#include <parallel/basic_iterator.h>
#include <bits/stl_pair.h>

namespace __gnu_parallel
{
  /** @brief A pair of iterators. The usual iterator operations are
   *  applied to both child iterators.
   */
  template<typename _Iterator1, typename _Iterator2,
           typename _IteratorCategory>
    class _IteratorPair : public std::pair<_Iterator1, _Iterator2>
    {
    private:
      typedef std::pair<_Iterator1, _Iterator2> _Base;

    public:
      typedef _IteratorCategory iterator_category;
      typedef void value_type;

      typedef std::iterator_traits<_Iterator1> _TraitsType;
      typedef typename _TraitsType::difference_type difference_type;
      typedef _IteratorPair* pointer;
      typedef _IteratorPair& reference;

      _IteratorPair() { }

      _IteratorPair(const _Iterator1& __first, const _Iterator2& __second)
      : _Base(__first, __second) { }

      // Pre-increment operator.
      _IteratorPair&
      operator++()
      {
        ++_Base::first;
        ++_Base::second;
        return *this;
      }

      // Post-increment operator.
      const _IteratorPair
      operator++(int)
      { return _IteratorPair(_Base::first++, _Base::second++); }

      // Pre-decrement operator.
      _IteratorPair&
      operator--()
      {
        --_Base::first;
        --_Base::second;
        return *this;
      }

      // Post-decrement operator.
      const _IteratorPair
      operator--(int)
      { return _IteratorPair(_Base::first--, _Base::second--); }

      // Type conversion.
      operator _Iterator2() const
      { return _Base::second; }

      _IteratorPair&
      operator=(const _IteratorPair& __other)
      {
        _Base::first = __other.first;
        _Base::second = __other.second;
        return *this;
      }

      _IteratorPair
      operator+(difference_type __delta) const
      { return _IteratorPair(_Base::first + __delta, _Base::second + __delta);
        }

      difference_type
      operator-(const _IteratorPair& __other) const
      { return _Base::first - __other.first; }
  };


  /** @brief A triple of iterators. The usual iterator operations are
      applied to all three child iterators.
   */
  template<typename _Iterator1, typename _Iterator2, typename _Iterator3,
           typename _IteratorCategory>
    class _IteratorTriple
    {
    public:
      typedef _IteratorCategory iterator_category;
      typedef void value_type;
      typedef typename std::iterator_traits<_Iterator1>::difference_type
                                                            difference_type;
      typedef _IteratorTriple* pointer;
      typedef _IteratorTriple& reference;

      _Iterator1 _M_first;
      _Iterator2 _M_second;
      _Iterator3 _M_third;

      _IteratorTriple() { }

      _IteratorTriple(const _Iterator1& __first, const _Iterator2& __second,
                      const _Iterator3& __third)
      {
        _M_first = __first;
        _M_second = __second;
        _M_third = __third;
      }

      // Pre-increment operator.
      _IteratorTriple&
      operator++()
      {
        ++_M_first;
        ++_M_second;
        ++_M_third;
        return *this;
      }

      // Post-increment operator.
      const _IteratorTriple
      operator++(int)
      { return _IteratorTriple(_M_first++, _M_second++, _M_third++); }

      // Pre-decrement operator.
      _IteratorTriple&
      operator--()
      {
        --_M_first;
        --_M_second;
        --_M_third;
        return *this;
      }

      // Post-decrement operator.
      const _IteratorTriple
      operator--(int)
      { return _IteratorTriple(_M_first--, _M_second--, _M_third--); }

      // Type conversion.
      operator _Iterator3() const
      { return _M_third; }

      _IteratorTriple&
      operator=(const _IteratorTriple& __other)
      {
        _M_first = __other._M_first;
        _M_second = __other._M_second;
        _M_third = __other._M_third;
        return *this;
      }

      _IteratorTriple
      operator+(difference_type __delta) const
      { return _IteratorTriple(_M_first + __delta, _M_second + __delta,
                               _M_third + __delta); }

      difference_type
      operator-(const _IteratorTriple& __other) const
      { return _M_first - __other._M_first; }
  };
}

#endif /* _GLIBCXX_PARALLEL_ITERATOR_H */
