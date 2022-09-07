// Numeric conversions (to_string, to_chars) -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/charconv.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{charconv}
 */

#ifndef _GLIBCXX_CHARCONV_H
#define _GLIBCXX_CHARCONV_H 1

#pragma GCC system_header

#if __cplusplus >= 201103L

#include <type_traits>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION
namespace __detail
{
  // Generic implementation for arbitrary bases.
  template<typename _Tp>
    _GLIBCXX14_CONSTEXPR unsigned
    __to_chars_len(_Tp __value, int __base = 10) noexcept
    {
      static_assert(is_integral<_Tp>::value, "implementation bug");
      static_assert(is_unsigned<_Tp>::value, "implementation bug");

      unsigned __n = 1;
      const unsigned __b2 = __base  * __base;
      const unsigned __b3 = __b2 * __base;
      const unsigned long __b4 = __b3 * __base;
      for (;;)
	{
	  if (__value < (unsigned)__base) return __n;
	  if (__value < __b2) return __n + 1;
	  if (__value < __b3) return __n + 2;
	  if (__value < __b4) return __n + 3;
	  __value /= __b4;
	  __n += 4;
	}
    }

  // Write an unsigned integer value to the range [first,first+len).
  // The caller is required to provide a buffer of exactly the right size
  // (which can be determined by the __to_chars_len function).
  template<typename _Tp>
    void
    __to_chars_10_impl(char* __first, unsigned __len, _Tp __val) noexcept
    {
      static_assert(is_integral<_Tp>::value, "implementation bug");
      static_assert(is_unsigned<_Tp>::value, "implementation bug");

      static constexpr char __digits[201] =
	"0001020304050607080910111213141516171819"
	"2021222324252627282930313233343536373839"
	"4041424344454647484950515253545556575859"
	"6061626364656667686970717273747576777879"
	"8081828384858687888990919293949596979899";
      unsigned __pos = __len - 1;
      while (__val >= 100)
	{
	  auto const __num = (__val % 100) * 2;
	  __val /= 100;
	  __first[__pos] = __digits[__num + 1];
	  __first[__pos - 1] = __digits[__num];
	  __pos -= 2;
	}
      if (__val >= 10)
	{
	  auto const __num = __val * 2;
	  __first[1] = __digits[__num + 1];
	  __first[0] = __digits[__num];
	}
      else
	__first[0] = '0' + __val;
    }

} // namespace __detail
_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
#endif // C++11
#endif // _GLIBCXX_CHARCONV_H
