// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#define _GLIBCXX_USE_CXX11_ABI 1
#include <fstream>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template class basic_filebuf<char, char_traits<char> >;
  template class basic_ifstream<char>;
  template class basic_ofstream<char>;
  template class basic_fstream<char>;

#ifdef _GLIBCXX_USE_WCHAR_T
  template class basic_filebuf<wchar_t, char_traits<wchar_t> >;
  template class basic_ifstream<wchar_t>;
  template class basic_ofstream<wchar_t>;
  template class basic_fstream<wchar_t>;
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
