// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_STDINT_H
#define _GLIBCXX_STDINT_H 1

#pragma GCC system_header

#include <bits/c++config.h>

#if __cplusplus >= 201103L

// For 8.22.1/1 (see C99, Notes 219, 220, 222)
# if _GLIBCXX_HAVE_STDINT_H
#  ifndef __STDC_LIMIT_MACROS
#   define _UNDEF__STDC_LIMIT_MACROS
#   define __STDC_LIMIT_MACROS
#  endif
#  ifndef __STDC_CONSTANT_MACROS
#   define _UNDEF__STDC_CONSTANT_MACROS
#   define __STDC_CONSTANT_MACROS
#  endif
#  include_next <stdint.h>
#  ifdef _UNDEF__STDC_LIMIT_MACROS
#   undef __STDC_LIMIT_MACROS
#   undef _UNDEF__STDC_LIMIT_MACROS
#  endif
#  ifdef _UNDEF__STDC_CONSTANT_MACROS
#   undef __STDC_CONSTANT_MACROS
#   undef _UNDEF__STDC_CONSTANT_MACROS
#  endif
# endif

#ifdef _GLIBCXX_USE_C99_STDINT_TR1

namespace std
{
  using ::int8_t;
  using ::int16_t;
  using ::int32_t;
  using ::int64_t;

  using ::int_fast8_t;
  using ::int_fast16_t;
  using ::int_fast32_t;
  using ::int_fast64_t;

  using ::int_least8_t;
  using ::int_least16_t;
  using ::int_least32_t;
  using ::int_least64_t;

  using ::intmax_t;
  using ::intptr_t;
  
  using ::uint8_t;
  using ::uint16_t;
  using ::uint32_t;
  using ::uint64_t;

  using ::uint_fast8_t;
  using ::uint_fast16_t;
  using ::uint_fast32_t;
  using ::uint_fast64_t;

  using ::uint_least8_t;
  using ::uint_least16_t;
  using ::uint_least32_t;
  using ::uint_least64_t;

  using ::uintmax_t;
  using ::uintptr_t;
} // namespace

#endif // _GLIBCXX_USE_C99_STDINT_TR1

#else

# if _GLIBCXX_HAVE_STDINT_H
#  include_next <stdint.h>
# endif

#endif // C++11

#endif // _GLIBCXX_STDINT_H
