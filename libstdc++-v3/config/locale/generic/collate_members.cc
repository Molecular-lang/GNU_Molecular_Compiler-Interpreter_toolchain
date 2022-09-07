// std::collate implementation details, generic version -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.2.4.1.2  collate virtual functions
//

#include <locale>
#include <cstring>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // These are basically extensions to char_traits, and perhaps should
  // be put there instead of here.
  template<>
    int
    collate<char>::_M_compare(const char* __one, const char* __two) const throw()
    {
      int __cmp = strcoll(__one, __two);
      return (__cmp >> (8 * sizeof (int) - 2)) | (__cmp != 0);
    }

  template<>
    size_t
    collate<char>::_M_transform(char* __to, const char* __from,
				size_t __n) const throw()
    { return strxfrm(__to, __from, __n); }

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    int
    collate<wchar_t>::_M_compare(const wchar_t* __one,
				 const wchar_t* __two) const throw()
    {
      int __cmp = wcscoll(__one, __two);
      return (__cmp >> (8 * sizeof (int) - 2)) | (__cmp != 0);
    }

  template<>
    size_t
    collate<wchar_t>::_M_transform(wchar_t* __to, const wchar_t* __from,
				   size_t __n) const throw()
    { return wcsxfrm(__to, __from, __n); }
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
