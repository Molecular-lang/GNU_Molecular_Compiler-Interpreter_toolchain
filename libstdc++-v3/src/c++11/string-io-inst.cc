// SSO string instantiations for I/O -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#define _GLIBCXX_USE_CXX11_ABI 1
#include <string>
#include <istream>
#include <ostream>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // string related to iostreams
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
