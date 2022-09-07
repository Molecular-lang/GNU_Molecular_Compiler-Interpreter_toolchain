// Reference-counted COW string instantiations for I/O -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 21  Strings library
//

#define _GLIBCXX_USE_CXX11_ABI 0
#include <istream>
#include <ostream>

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // The equivalent SSO string instantiations are in c++98/misc-inst.cc,
  // repeat them for COW string

  // string related to iostreams.
  template
    basic_istream<char>&
    operator>>(basic_istream<char>&, string&);
  template
    basic_ostream<char>&
    operator<<(basic_ostream<char>&, const string&);
  template
    basic_istream<char>&
    getline(basic_istream<char>&, string&, char);
  template
    basic_istream<char>&
    getline(basic_istream<char>&, string&);

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
