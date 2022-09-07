// std::collate implementation details, GNU version -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.2.4.1.2  collate virtual functions
//

#include <locale>
#include <bits/c++locale_internal.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // These are basically extensions to char_traits, and perhaps should
  // be put there instead of here.
  template<>
    int
    collate<char>::_M_compare(const char* __one,
			      const char* __two) const throw()
    {
      int __cmp = __strcoll_l(__one, __two, _M_c_locale_collate);
      return (__cmp >> (8 * sizeof (int) - 2)) | (__cmp != 0);
    }

  template<>
    size_t
    collate<char>::_M_transform(char* __to, const char* __from,
				size_t __n) const throw()
    { return __strxfrm_l(__to, __from, __n, _M_c_locale_collate); }

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    int
    collate<wchar_t>::_M_compare(const wchar_t* __one,
				 const wchar_t* __two) const throw()
    {
      int __cmp = __wcscoll_l(__one, __two, _M_c_locale_collate);
      return (__cmp >> (8 * sizeof (int) - 2)) | (__cmp != 0);
    }

  template<>
    size_t
    collate<wchar_t>::_M_transform(wchar_t* __to, const wchar_t* __from,
				   size_t __n) const throw()
    { return __wcsxfrm_l(__to, __from, __n, _M_c_locale_collate); }
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
