// Reference-counted COW wide string instantiations -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 21  Strings library
//

#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/c++config.h>

#ifdef _GLIBCXX_USE_WCHAR_T
#define C wchar_t
#include "string-inst.cc"

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

#endif
