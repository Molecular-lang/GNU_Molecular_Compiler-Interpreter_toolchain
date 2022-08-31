// std::messages implementation details, IEEE 1003.1-200x version -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.2.7.1.2  messages virtual functions
//

#include <locale>

namespace std _GLIBCXX_VISIBILITY(default)
{
  // Specializations
  template<>
    string
    messages<char>::do_get(catalog __c, int __setid, int __msgid,
			   const string& __dfault) const
    {
      nl_catd __nlc = reinterpret_cast<nl_catd>(__c);
      return string(catgets(__nlc, __setid, __msgid, __dfault.c_str()));
    }

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    wstring
    messages<wchar_t>::do_get(catalog, int, int, const wstring& __dfault) const
    {
      nl_catd __nlc = reinterpret_cast<nl_catd>(__c);
      char* __msg = catgets(__nlc, __setid, __msgid,
			    _M_convert_to_char(__dfault));
      return _M_convert_from_char(__msg);
    }
#endif
}
