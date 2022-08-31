// std::tr1::hash definitions with new string -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#define _GLIBCXX_USE_CXX11_ABI 1
#include <string>

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

#include <tr1/functional>
namespace std _GLIBCXX_VISIBILITY(default)
{
  namespace tr1
  {
  template<>
    size_t
    hash<string>::operator()(string __s) const
    { return _Fnv_hash::hash(__s.data(), __s.length()); }

  template<>
    size_t
    hash<const string&>::operator()(const string& __s) const
    { return _Fnv_hash::hash(__s.data(), __s.length()); }

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    size_t
    hash<wstring>::operator()(wstring __s) const
    { return _Fnv_hash::hash(__s.data(), __s.length() * sizeof(wchar_t)); }

  template<>
    size_t
    hash<const wstring&>::operator()(const wstring& __s) const
    { return _Fnv_hash::hash(__s.data(), __s.length() * sizeof(wchar_t)); }
#endif
  }
}
