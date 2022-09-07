// Reference-counted COW string instantiations -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 21  Strings library
//

#define _GLIBCXX_USE_CXX11_ABI 0
#include "string-inst.cc"

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

#ifdef  _GLIBCXX_USE_C99_STDINT_TR1
#include <random>

namespace std _GLIBCXX_VISIBILITY(default)
{
  void
  random_device::_M_init(const std::string& token)
  { _M_init(token.c_str(), token.length()); }

  void
  random_device::_M_init_pretr1(const std::string& token)
  { _M_init(token.c_str(), token.length()); }
} // namespace
#endif
