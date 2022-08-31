// Reference-counted COW wide string instantiations for I/O -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 21  Strings library
//

#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/c++config.h>

#ifdef _GLIBCXX_USE_WCHAR_T
#include <ostream>
#include <istream>

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // The equivalent SSO wstring instantiations are in c++98/misc-inst.cc,
  // repeat them for COW wstring

  // string related to iostreams
  template
    basic_istream<wchar_t>&
    operator>>(basic_istream<wchar_t>&, wstring&);
  template
    basic_ostream<wchar_t>&
    operator<<(basic_ostream<wchar_t>&, const wstring&);
  template
    basic_istream<wchar_t>&
    getline(basic_istream<wchar_t>&, wstring&, wchar_t);
  template
    basic_istream<wchar_t>&
    getline(basic_istream<wchar_t>&, wstring&);

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
#endif
