// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#include <memory>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template class allocator<char>;
  template class allocator<wchar_t>;

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
