// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_FENV_H
#define _GLIBCXX_FENV_H 1

#pragma GCC system_header

#include <bits/c++config.h>
#if _GLIBCXX_HAVE_FENV_H
# include_next <fenv.h>
#endif

#if __cplusplus >= 201103L

#if _GLIBCXX_USE_C99_FENV_TR1

#undef feclearexcept
#undef fegetexceptflag
#undef feraiseexcept
#undef fesetexceptflag
#undef fetestexcept
#undef fegetround
#undef fesetround
#undef fegetenv
#undef feholdexcept
#undef fesetenv
#undef feupdateenv

namespace std
{
  // types
  using ::fenv_t;
  using ::fexcept_t;

  // functions
  using ::feclearexcept;
  using ::fegetexceptflag;
  using ::feraiseexcept;
  using ::fesetexceptflag;
  using ::fetestexcept;

  using ::fegetround;
  using ::fesetround;

  using ::fegetenv;
  using ::feholdexcept;
  using ::fesetenv;
  using ::feupdateenv;
} // namespace

#endif // _GLIBCXX_USE_C99_FENV_TR1

#endif // C++11

#endif // _GLIBCXX_FENV_H
