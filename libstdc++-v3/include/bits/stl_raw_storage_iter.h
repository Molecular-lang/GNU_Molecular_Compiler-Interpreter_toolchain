// -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/stl_raw_storage_iter.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{memory}
 */

#ifndef _STL_RAW_STORAGE_ITERATOR_H
#define _STL_RAW_STORAGE_ITERATOR_H 1

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

// Ignore warnings about std::iterator.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

  /**
   *  This iterator class lets algorithms store their results into
   *  uninitialized memory.
  */
  template <class _OutputIterator, class _Tp>
    class _GLIBCXX17_DEPRECATED raw_storage_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _OutputIterator _M_iter;

    public:
      explicit
      raw_storage_iterator(_OutputIterator __x)
      : _M_iter(__x) {}

      raw_storage_iterator&
      operator*() { return *this; }

      raw_storage_iterator&
      operator=(const _Tp& __element)
      {
	std::_Construct(std::__addressof(*_M_iter), __element);
	return *this;
      }

#if __cplusplus >= 201103L
      // _GLIBCXX_RESOLVE_LIB_DEFECTS
      // 2127. Move-construction with raw_storage_iterator
      raw_storage_iterator&
      operator=(_Tp&& __element)
      {
	std::_Construct(std::__addressof(*_M_iter), std::move(__element));
	return *this;
      }
#endif

      raw_storage_iterator&
      operator++()
      {
	++_M_iter;
	return *this;
      }

      raw_storage_iterator
      operator++(int)
      {
	raw_storage_iterator __tmp = *this;
	++_M_iter;
	return __tmp;
      }

      // _GLIBCXX_RESOLVE_LIB_DEFECTS
      // 2454. Add raw_storage_iterator::base() member
      _OutputIterator base() const { return _M_iter; }
    };
#pragma GCC diagnostic pop

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
