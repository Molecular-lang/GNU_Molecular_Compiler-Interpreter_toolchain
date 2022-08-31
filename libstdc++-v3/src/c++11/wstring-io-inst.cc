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
#ifdef _GLIBCXX_USE_WCHAR_T
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
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
