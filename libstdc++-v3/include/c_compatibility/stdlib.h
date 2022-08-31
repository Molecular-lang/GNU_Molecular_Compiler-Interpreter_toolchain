// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#if !defined __cplusplus || defined _GLIBCXX_INCLUDE_NEXT_C_HEADERS
# include_next <stdlib.h>
#else

#ifndef _GLIBCXX_STDLIB_H
#define _GLIBCXX_STDLIB_H 1

# include <cstdlib>

using std::abort;
using std::atexit;
using std::exit;
#if __cplusplus >= 201103L
# ifdef _GLIBCXX_HAVE_AT_QUICK_EXIT
  using std::at_quick_exit;
# endif
# ifdef _GLIBCXX_HAVE_QUICK_EXIT
  using std::quick_exit;
# endif
#endif

#if _GLIBCXX_HOSTED
using std::div_t;
using std::ldiv_t;

using std::abs;
using std::atof;
using std::atoi;
using std::atol;
using std::bsearch;
using std::calloc;
using std::div;
using std::free;
using std::getenv;
using std::labs;
using std::ldiv;
using std::malloc;
#ifdef _GLIBCXX_HAVE_MBSTATE_T
using std::mblen;
using std::mbstowcs;
using std::mbtowc;
#endif // _GLIBCXX_HAVE_MBSTATE_T
using std::qsort;
using std::rand;
using std::realloc;
using std::srand;
using std::strtod;
using std::strtol;
using std::strtoul;
using std::system;
#ifdef _GLIBCXX_USE_WCHAR_T
using std::wcstombs;
using std::wctomb;
#endif // _GLIBCXX_USE_WCHAR_T
#endif

#endif // _GLIBCXX_STDLIB_H
#endif // __cplusplus
