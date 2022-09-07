// Exception Handling support header for -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

/** @file bits/exception.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly.
 */

#ifndef __EXCEPTION_H
#define __EXCEPTION_H 1

#pragma GCC system_header

#include <bits/c++config.h>

extern "C++" {

namespace std _GLIBCXX_VISIBILITY(default)
{
  /**
   * @defgroup exceptions Exceptions
   * @ingroup diagnostics
   * @since C++98
   *
   * Classes and functions for reporting errors via exceptions.
   * @{
   */

  /**
   *  @brief Base class for all library exceptions.
   *
   *  This is the base class for all exceptions thrown by the standard
   *  library, and by certain language expressions.  You are free to derive
   *  your own %exception classes, or use a different hierarchy, or to
   *  throw non-class data (e.g., fundamental types).
   */
  class exception
  {
  public:
    exception() _GLIBCXX_NOTHROW { }
    virtual ~exception() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
#if __cplusplus >= 201103L
    exception(const exception&) = default;
    exception& operator=(const exception&) = default;
    exception(exception&&) = default;
    exception& operator=(exception&&) = default;
#endif

    /** Returns a C-style character string describing the general cause
     *  of the current error.  */
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
  };

  /// @}

} // namespace std

}

#endif
