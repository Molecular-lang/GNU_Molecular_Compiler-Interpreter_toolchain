// std::rel_ops implementation -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/stl_relops.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{utility}
 *
 *  This file is only included by `<utility>`, which is required by the
 *  standard to define namespace `rel_ops` and its contents.
 */

#ifndef _STL_RELOPS_H
#define _STL_RELOPS_H 1

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  namespace rel_ops
  {
    /** @namespace std::rel_ops
     *  @brief  The generated relational operators are sequestered here.
     *
     *  Libstdc++ headers must not use the contents of `rel_ops`.
     *  User code should also avoid them, because unconstrained function
     *  templates are too greedy and can easily cause ambiguities.
     *
     *  C++20 default comparisons are a better solution.
     */

    /**
     *  @brief Defines @c != for arbitrary types, in terms of @c ==.
     *  @param  __x  A thing.
     *  @param  __y  Another thing.
     *  @return   __x != __y
     *
     *  This function uses @c == to determine its result.
     */
    template <class _Tp>
      inline bool
      operator!=(const _Tp& __x, const _Tp& __y)
      { return !(__x == __y); }

    /**
     *  @brief Defines @c > for arbitrary types, in terms of @c <.
     *  @param  __x  A thing.
     *  @param  __y  Another thing.
     *  @return   __x > __y
     *
     *  This function uses @c < to determine its result.
     */
    template <class _Tp>
      inline bool
      operator>(const _Tp& __x, const _Tp& __y)
      { return __y < __x; }

    /**
     *  @brief Defines @c <= for arbitrary types, in terms of @c <.
     *  @param  __x  A thing.
     *  @param  __y  Another thing.
     *  @return   __x <= __y
     *
     *  This function uses @c < to determine its result.
     */
    template <class _Tp>
      inline bool
      operator<=(const _Tp& __x, const _Tp& __y)
      { return !(__y < __x); }

    /**
     *  @brief Defines @c >= for arbitrary types, in terms of @c <.
     *  @param  __x  A thing.
     *  @param  __y  Another thing.
     *  @return   __x >= __y
     *
     *  This function uses @c < to determine its result.
     */
    template <class _Tp>
      inline bool operator>=(const _Tp& __x, const _Tp& __y)
      { return !(__x < __y); }
  } // namespace rel_ops

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif /* _STL_RELOPS_H */
