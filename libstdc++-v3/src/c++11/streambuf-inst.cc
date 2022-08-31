// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#include <ios>
#include <streambuf>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // streambuf
  template class basic_streambuf<char>;

  template
    streamsize
    __copy_streambufs(basic_streambuf<char>*, basic_streambuf<char>*);

#ifdef _GLIBCXX_USE_WCHAR_T
  // wstreambuf
  template class basic_streambuf<wchar_t>;

  template
    streamsize
    __copy_streambufs(basic_streambuf<wchar_t>*, basic_streambuf<wchar_t>*);
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
