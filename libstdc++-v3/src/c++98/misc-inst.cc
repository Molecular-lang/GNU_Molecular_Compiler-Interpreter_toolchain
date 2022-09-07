// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#if __cplusplus != 199711L
# error This file must be compiled as C++98
#endif

#define _GLIBCXX_USE_CXX11_ABI 1
#define _GLIBCXX_DISAMBIGUATE_REPLACE_INST 1
#include <string>
#include <istream>
#include <ostream>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

#if _GLIBCXX_USE_CXX11_ABI
  // C++98 members that are not instantiated by src/c++11/string-inst.cc
  // because they changed in C++11 to take const_iterator parameters.
  template string::iterator string::erase(iterator);
  template string::iterator string::erase(iterator, iterator);
  template void string::insert(iterator, size_type, char);
  template void string::insert(iterator, iterator, iterator);
  template string::iterator string::insert(iterator, char);
  template string& string::replace(iterator, iterator, const string&);
  template string&
  string::replace(iterator, iterator, const char*, size_type);
  template string& string::replace(iterator, iterator, const char*);
  template string& string::replace(iterator, iterator, size_type, char);
  template string& string::replace(iterator, iterator, char*, char*);
  template string&
  string::replace(iterator, iterator, const char*, const char*);
  template string& string::replace(iterator, iterator, iterator, iterator);
  template string&
  string::replace(iterator, iterator, const_iterator, const_iterator);

#ifdef _GLIBCXX_USE_WCHAR_T
  template wstring::iterator wstring::erase(iterator);
  template wstring::iterator wstring::erase(iterator, iterator);
  template void wstring::insert(iterator, size_type, wchar_t);
  template void wstring::insert(iterator, iterator, iterator);
  template wstring::iterator wstring::insert(iterator, wchar_t);
  template wstring& wstring::replace(iterator, iterator, const wstring&);
  template wstring&
  wstring::replace(iterator, iterator, const wchar_t*, size_type);
  template wstring& wstring::replace(iterator, iterator, const wchar_t*);
  template wstring& wstring::replace(iterator, iterator, size_type, wchar_t);
  template wstring& wstring::replace(iterator, iterator, wchar_t*, wchar_t*);
  template wstring&
  wstring::replace(iterator, iterator, const wchar_t*, const wchar_t*);
  template wstring& wstring::replace(iterator, iterator, iterator, iterator);
  template wstring&
  wstring::replace(iterator, iterator, const_iterator, const_iterator);
#endif

  // XXX this doesn't belong in an -inst.cc file
  // Defined in src/c++98/locale_facets.cc
  _GLIBCXX_PURE bool
  __verify_grouping_impl(const char* __grouping, size_t __grouping_size,
                         const char* __grouping_tmp, size_t __n);

  bool
  __verify_grouping(const char* __grouping, size_t __grouping_size,
		    const string& __grouping_tmp) throw()
  {
    return __verify_grouping_impl(__grouping, __grouping_size,
                                  __grouping_tmp.c_str(),
                                  __grouping_tmp.size());
  }
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
