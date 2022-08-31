// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#ifndef _GLIBCXX_USE_CXX11_ABI
// Instantiations in this file use the new SSO std::string ABI unless included
// by another file which defines _GLIBCXX_USE_CXX11_ABI=0.
# define _GLIBCXX_USE_CXX11_ABI 1
#endif
#include <sstream>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template class basic_stringbuf<char>;
  template class basic_istringstream<char>;
  template class basic_ostringstream<char>;
  template class basic_stringstream<char>;

#ifdef _GLIBCXX_USE_WCHAR_T
  template class basic_stringbuf<wchar_t>;
  template class basic_istringstream<wchar_t>;
  template class basic_ostringstream<wchar_t>;
  template class basic_stringstream<wchar_t>;
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
