// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <bits/c++config.h>

#if __cplusplus >= 201103L
# include <ccomplex>
#endif

#if __cplusplus >= 201103L && defined(__STRICT_ANSI__)
// For strict modes do not include the C library's <complex.h>, see PR 82417.
#elif _GLIBCXX_HAVE_COMPLEX_H
# include_next <complex.h>
# ifdef _GLIBCXX_COMPLEX
// See PR56111, keep the macro in C++03 if possible.
#  undef complex
# endif
#endif

#ifndef _GLIBCXX_COMPLEX_H
#define _GLIBCXX_COMPLEX_H 1

#endif
