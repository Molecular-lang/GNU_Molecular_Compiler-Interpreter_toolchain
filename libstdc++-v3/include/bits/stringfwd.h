// <string> Forward declarations -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/stringfwd.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{string}
 */

//
// ISO C++ 14882: 21 Strings library
//

#ifndef _STRINGFWD_H
#define _STRINGFWD_H 1

#pragma GCC system_header

#include <bits/c++config.h>
#include <bits/memoryfwd.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /**
   *  @defgroup strings Strings
   *
   *  @{
  */

  template<class _CharT>
    struct char_traits;

  template<> struct char_traits<char>;

  template<> struct char_traits<wchar_t>;

#ifdef _GLIBCXX_USE_CHAR8_T
  template<> struct char_traits<char8_t>;
#endif

#if __cplusplus >= 201103L
  template<> struct char_traits<char16_t>;
  template<> struct char_traits<char32_t>;
#endif

_GLIBCXX_BEGIN_NAMESPACE_CXX11

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_string;

_GLIBCXX_END_NAMESPACE_CXX11

  /// A string of @c char
  typedef basic_string<char>    string;   

  /// A string of @c wchar_t
  typedef basic_string<wchar_t> wstring;   

#ifdef _GLIBCXX_USE_CHAR8_T
  /// A string of @c char8_t
  typedef basic_string<char8_t> u8string;
#endif

#if __cplusplus >= 201103L
  /// A string of @c char16_t
  typedef basic_string<char16_t> u16string; 

  /// A string of @c char32_t
  typedef basic_string<char32_t> u32string; 
#endif

  /** @}  */

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif	// _STRINGFWD_H
