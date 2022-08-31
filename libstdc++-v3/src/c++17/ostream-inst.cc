// std::ostream instantiations for C++17 -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:2017 28  Input/output library
//

#include <ostream>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

template basic_ostream<char>& basic_ostream<char>::operator<<(nullptr_t);

#ifdef _GLIBCXX_USE_WCHAR_T
template basic_ostream<wchar_t>& basic_ostream<wchar_t>::operator<<(nullptr_t);
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
