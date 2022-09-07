// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_INTTYPES_H
#define _GLIBCXX_INTTYPES_H 1

#pragma GCC system_header

#include <bits/c++config.h>

#if __cplusplus >= 201103L

// For 8.11.1/1 (see C99, Note 184)
# if _GLIBCXX_HAVE_INTTYPES_H
#  ifndef __STDC_FORMAT_MACROS
#   define _UNDEF__STDC_FORMAT_MACROS
#   define __STDC_FORMAT_MACROS
#  endif
#  include_next <inttypes.h>
#  ifdef _UNDEF__STDC_FORMAT_MACROS
#   undef __STDC_FORMAT_MACROS
#   undef _UNDEF__STDC_FORMAT_MACROS
#  endif
# endif

#ifdef _GLIBCXX_USE_C99_INTTYPES_TR1

namespace std
{
  // types
  using ::imaxdiv_t;

  // functions
  using ::imaxabs;

  // May collide with _Longlong abs(_Longlong), and is not described
  // anywhere outside the synopsis.  Likely, a defect.
  //
  // intmax_t abs(intmax_t)

  using ::imaxdiv;

  // Likewise, with lldiv_t div(_Longlong, _Longlong).
  //
  // imaxdiv_t div(intmax_t, intmax_t)

  using ::strtoimax;
  using ::strtoumax;

#if defined(_GLIBCXX_USE_WCHAR_T) && _GLIBCXX_USE_C99_INTTYPES_WCHAR_T_TR1
  using ::wcstoimax;
  using ::wcstoumax;
#endif
} // namespace

#endif _GLIBCXX_USE_C99_INTTYPES_TR1

#else

# if _GLIBCXX_HAVE_INTTYPES_H
#  include_next <inttypes.h>
# endif

#endif // C++11

#endif // _GLIBCXX_INTTYPES_H
