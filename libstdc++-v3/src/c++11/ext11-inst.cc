// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <ext/stdio_filebuf.h>
#include <ext/stdio_sync_filebuf.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template class stdio_filebuf<char>;
  template class stdio_sync_filebuf<char>;
#ifdef _GLIBCXX_USE_WCHAR_T
  template class stdio_filebuf<wchar_t>;
  template class stdio_sync_filebuf<wchar_t>;
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
