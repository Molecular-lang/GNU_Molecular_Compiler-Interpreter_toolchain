// string instantiations for C++17 -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:2017 24  Strings library
//

#ifndef _GLIBCXX_USE_CXX11_ABI
// Instantiations in this file use the new SSO std::string ABI unless included
// by another file which defines _GLIBCXX_USE_CXX11_ABI=0.
# define _GLIBCXX_USE_CXX11_ABI 1
#endif

#include <string>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

template basic_string<char>::basic_string(__sv_wrapper, const allocator_type&);
template basic_string<char>::__sv_wrapper::__sv_wrapper(string_view);
template string_view basic_string<char>::_S_to_string_view(string_view);
template basic_string<char>::operator string_view() const noexcept;
template char* basic_string<char>::data() noexcept;

#ifdef _GLIBCXX_USE_WCHAR_T
template basic_string<wchar_t>::basic_string(__sv_wrapper, const allocator_type&);
template basic_string<wchar_t>::__sv_wrapper::__sv_wrapper(wstring_view);
template wstring_view basic_string<wchar_t>::_S_to_string_view(wstring_view);
template basic_string<wchar_t>::operator wstring_view() const noexcept;
template wchar_t* basic_string<wchar_t>::data() noexcept;
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
