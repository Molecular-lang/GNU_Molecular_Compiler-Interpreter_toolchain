// Reference-counted COW string instantiations for C++17 -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:2017 24  Strings library
//

#define _GLIBCXX_USE_CXX11_ABI 0
#include "string-inst.cc"

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif
