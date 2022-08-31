// std::tr1::hash definitions -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#define _GLIBCXX_USE_CXX11_ABI 0
#include <string>
#include <tr1/functional>

#include "hash-long-double-tr1-aux.cc"

namespace std _GLIBCXX_VISIBILITY(default)
{
  namespace tr1
  {
#ifndef _GLIBCXX_LONG_DOUBLE_COMPAT_IMPL
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
#endif
  }
}
