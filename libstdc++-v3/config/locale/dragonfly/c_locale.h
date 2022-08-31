// localization implementation details, DragonFly version -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.8  Standard locale categories.
//

#ifndef _GLIBCXX_CXX_LOCALE_H
#define _GLIBCXX_CXX_LOCALE_H 1

#pragma GCC system_header

#include <clocale>
#include <xlocale.h>

#define _GLIBCXX_NUM_CATEGORIES 0

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  typedef int*			__c_locale;

  // Convert numeric value of type double and long double to string and
  // return length of string.  If vsnprintf is available use it, otherwise
  // fall back to the unsafe vsprintf which, in general, can be dangerous
  // and should be avoided.
  inline int
  __convert_from_v(const __c_locale& __cloc, char* __out,
		   const int __size __attribute__ ((__unused__)),
		   const char* __fmt, ...)
  {
    __c_locale __old = (__c_locale)uselocale((locale_t)__cloc);

    __builtin_va_list __args;
    __builtin_va_start(__args, __fmt);

#if _GLIBCXX_USE_C99_STDIO
    const int __ret = __builtin_vsnprintf(__out, __size, __fmt, __args);
#else
    const int __ret = __builtin_vsprintf(__out, __fmt, __args);
#endif

    __builtin_va_end(__args);

    uselocale((locale_t)__old);
    return __ret;
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
