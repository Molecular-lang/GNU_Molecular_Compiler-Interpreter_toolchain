// <vstring.h> Forward declarations -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _VSTRING_FWD_H
#define _VSTRING_FWD_H 1

#pragma GCC system_header

#include <bits/c++config.h>
#include <bits/char_traits.h>
#include <bits/allocator.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template<typename _CharT, typename _Traits, typename _Alloc>
    class __sso_string_base;

  template<typename _CharT, typename _Traits, typename _Alloc>
    class __rc_string_base;

  template<typename _CharT, typename _Traits = std::char_traits<_CharT>,
           typename _Alloc = std::allocator<_CharT>,
	   template
	   <typename, typename, typename> class _Base = __sso_string_base>
    class __versa_string;

  typedef __versa_string<char>                              __vstring;
  typedef __vstring                                         __sso_string;
  typedef 
  __versa_string<char, std::char_traits<char>,
		 std::allocator<char>, __rc_string_base>    __rc_string;

  typedef __versa_string<wchar_t>                           __wvstring;
  typedef __wvstring                                        __wsso_string;
  typedef
  __versa_string<wchar_t, std::char_traits<wchar_t>,
		 std::allocator<wchar_t>, __rc_string_base> __wrc_string;

#if __cplusplus >= 201103L
  typedef __versa_string<char16_t>                          __u16vstring;
  typedef __u16vstring                                      __u16sso_string;
  typedef 
  __versa_string<char16_t, std::char_traits<char16_t>,
		 std::allocator<char16_t>, __rc_string_base> __u16rc_string;

  typedef __versa_string<char32_t>                          __u32vstring;
  typedef __u32vstring                                      __u32sso_string;
  typedef 
  __versa_string<char32_t, std::char_traits<char32_t>,
		 std::allocator<char32_t>, __rc_string_base> __u32rc_string;
#endif // C++11

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif /* _VSTRING_FWD_H */
