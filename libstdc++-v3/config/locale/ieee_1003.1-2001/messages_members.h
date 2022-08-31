// std::messages implementation details, IEEE 1003.1-200x version -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.2.7.1.2  messages virtual functions
//

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // Non-virtual member functions.
  template<typename _CharT>
    typename messages<_CharT>::catalog
    messages<_CharT>::open(const basic_string<char>& __s, const locale& __loc,
			   const char*) const
    { return this->do_open(__s, __loc); }

  // Virtual member functions.
  template<typename _CharT>
    messages<_CharT>::~messages()
    { }

  template<typename _CharT>
    typename messages<_CharT>::catalog
    messages<_CharT>::do_open(const basic_string<char>& __s,
			      const locale&) const
    { return reinterpret_cast<catalog>(catopen(__s.c_str(), NL_CAT_LOCALE)); }

  template<typename _CharT>
    typename messages<_CharT>::string_type
    messages<_CharT>::do_get(catalog __c, int __setid, int __msgid,
			     const string_type& __dfault) const
    {
      nl_catd __nlc = reinterpret_cast<nl_catd>(__c);
      char* __msg = catgets(__nlc, __setid, __msgid,
			    _M_convert_to_char(__dfault));
      return _M_convert_from_char(__msg);
    }

  template<typename _CharT>
    void
    messages<_CharT>::do_close(catalog __c) const
    { catclose(reinterpret_cast<nl_catd>(__c)); }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
