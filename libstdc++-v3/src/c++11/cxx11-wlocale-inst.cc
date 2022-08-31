// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 22.1  Locales
//

// Facet wchar_t instantiations using new ABI strings.

#define _GLIBCXX_USE_CXX11_ABI 1
#include <bits/c++config.h>
#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

#ifdef _GLIBCXX_USE_WCHAR_T
#define C wchar_t
#include "locale-inst.cc"
#endif
