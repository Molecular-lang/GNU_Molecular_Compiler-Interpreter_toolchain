// <memory> Forward declarations -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/memoryfwd.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{memory}
 */

#ifndef _MEMORYFWD_H
#define _MEMORYFWD_H 1

#pragma GCC system_header

#include <bits/c++config.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /**
   * @defgroup allocators Allocators
   * @ingroup memory
   *
   * Classes encapsulating memory operations.
   *
   * @{
   */

  template<typename>
    class allocator;

  template<>
    class allocator<void>;

#if __cplusplus >= 201103L
  /// Declare uses_allocator so it can be specialized in `<queue>` etc.
  template<typename, typename>
    struct uses_allocator;

  template<typename>
    struct allocator_traits;
#endif

  /// @} group memory

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif
