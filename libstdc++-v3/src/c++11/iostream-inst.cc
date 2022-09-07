// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#include <iomanip>
#include <istream>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template class _Setfill<char>;
  template _Setfill<char> setfill(char);
  template class basic_iostream<char>;

#ifdef _GLIBCXX_USE_WCHAR_T
  template class _Setfill<wchar_t>;
  template _Setfill<wchar_t> setfill(wchar_t);
  template class basic_iostream<wchar_t>;
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
