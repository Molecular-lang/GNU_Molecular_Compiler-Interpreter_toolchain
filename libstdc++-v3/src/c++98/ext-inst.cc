// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#include <ext/rope>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  namespace
  {
    const int min_len = __detail::_S_max_rope_depth + 1;
  }

  template
    const unsigned long
    rope<char, std::allocator<char> >::_S_min_len[min_len];

  template
    char
    rope<char, std::allocator<char> >::
    _S_fetch(_Rope_RopeRep<char, std::allocator<char> >*, size_type);

#ifdef _GLIBCXX_USE_WCHAR_T
  template
    const unsigned long
    rope<wchar_t, std::allocator<wchar_t> >::_S_min_len[min_len];

  template
    wchar_t
    rope<wchar_t, std::allocator<wchar_t> >::
    _S_fetch(_Rope_RopeRep<wchar_t, std::allocator<wchar_t> >*, size_type);
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
