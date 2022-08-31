// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#include <ios>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template class basic_ios<char>;

#ifdef _GLIBCXX_USE_WCHAR_T
  template class basic_ios<wchar_t>;
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
