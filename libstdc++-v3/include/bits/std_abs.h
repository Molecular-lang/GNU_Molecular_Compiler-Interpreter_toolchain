// -*- C++ -*- C library enhancements header.

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file include/bits/std_abs.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{cmath, cstdlib}
 */

#ifndef _GLIBCXX_BITS_STD_ABS_H
#define _GLIBCXX_BITS_STD_ABS_H

#pragma GCC system_header

#include <bits/c++config.h>

#define _GLIBCXX_INCLUDE_NEXT_C_HEADERS
#include_next <stdlib.h>
#ifdef __CORRECT_ISO_CPP_MATH_H_PROTO
# include_next <math.h>
#endif
#undef _GLIBCXX_INCLUDE_NEXT_C_HEADERS

#undef abs

extern "C++"
{
namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  using ::abs;

#ifndef __CORRECT_ISO_CPP_STDLIB_H_PROTO
  inline long
  abs(long __i) { return __builtin_labs(__i); }
#endif

#ifdef _GLIBCXX_USE_LONG_LONG
  inline long long
  abs(long long __x) { return __builtin_llabs (__x); }
#endif

// _GLIBCXX_RESOLVE_LIB_DEFECTS
// 2192. Validity and return type of std::abs(0u) is unclear
// 2294. <cstdlib> should declare abs(double)
// 2735. std::abs(short), std::abs(signed char) and others should return int

#ifndef __CORRECT_ISO_CPP_MATH_H_PROTO
  inline _GLIBCXX_CONSTEXPR double
  abs(double __x)
  { return __builtin_fabs(__x); }

  inline _GLIBCXX_CONSTEXPR float
  abs(float __x)
  { return __builtin_fabsf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  abs(long double __x)
  { return __builtin_fabsl(__x); }
#endif

#if defined(__GLIBCXX_TYPE_INT_N_0)
  __extension__ inline _GLIBCXX_CONSTEXPR __GLIBCXX_TYPE_INT_N_0
  abs(__GLIBCXX_TYPE_INT_N_0 __x) { return __x >= 0 ? __x : -__x; }
#endif
#if defined(__GLIBCXX_TYPE_INT_N_1)
  __extension__ inline _GLIBCXX_CONSTEXPR __GLIBCXX_TYPE_INT_N_1
  abs(__GLIBCXX_TYPE_INT_N_1 __x) { return __x >= 0 ? __x : -__x; }
#endif
#if defined(__GLIBCXX_TYPE_INT_N_2)
  __extension__ inline _GLIBCXX_CONSTEXPR __GLIBCXX_TYPE_INT_N_2
  abs(__GLIBCXX_TYPE_INT_N_2 __x) { return __x >= 0 ? __x : -__x; }
#endif
#if defined(__GLIBCXX_TYPE_INT_N_3)
  __extension__ inline _GLIBCXX_CONSTEXPR __GLIBCXX_TYPE_INT_N_3
  abs(__GLIBCXX_TYPE_INT_N_3 __x) { return __x >= 0 ? __x : -__x; }
#endif

#if !defined(__STRICT_ANSI__) && defined(_GLIBCXX_USE_FLOAT128)
  __extension__ inline _GLIBCXX_CONSTEXPR
  __float128
  abs(__float128 __x)
  { return __x < 0 ? -__x : __x; }
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
} // extern "C"++"

#endif // _GLIBCXX_BITS_STD_ABS_H
