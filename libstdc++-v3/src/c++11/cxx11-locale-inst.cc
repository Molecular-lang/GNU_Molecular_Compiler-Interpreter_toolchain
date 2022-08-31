// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 22.1  Locales
//

// Facet instantiations using new ABI strings.

#define _GLIBCXX_USE_CXX11_ABI 1
#include <bits/c++config.h>
#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

#define C char
#define C_is_char
# include "locale-inst.cc"
