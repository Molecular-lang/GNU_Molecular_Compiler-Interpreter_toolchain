// std::messages implementation details, generic version -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.2.7.1.2  messages virtual functions
//

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // Non-virtual member functions.
  template<typename _CharT>
     messages<_CharT>::messages(size_t __refs)
     : facet(__refs)
     { _M_c_locale_messages = _S_get_c_locale(); }

  template<typename _CharT>
     messages<_CharT>::messages(__c_locale, const char*, size_t __refs)
     : facet(__refs)
     { _M_c_locale_messages = _S_get_c_locale(); }

  template<typename _CharT>
    typename messages<_CharT>::catalog
    messages<_CharT>::open(const basic_string<char>& __s, const locale& __loc,
			   const char*) const
    { return this->do_open(__s, __loc); }

  // Virtual member functions.
  template<typename _CharT>
    messages<_CharT>::~messages()
    { _S_destroy_c_locale(_M_c_locale_messages); }

  template<typename _CharT>
    typename messages<_CharT>::catalog
    messages<_CharT>::do_open(const basic_string<char>&, const locale&) const
    { return 0; }

  template<typename _CharT>
    typename messages<_CharT>::string_type
    messages<_CharT>::do_get(catalog, int, int,
			     const string_type& __dfault) const
    { return __dfault; }

  template<typename _CharT>
    void
    messages<_CharT>::do_close(catalog) const
    { }

   // messages_byname
   template<typename _CharT>
     messages_byname<_CharT>::messages_byname(const char* __s, size_t __refs)
     : messages<_CharT>(__refs)
     {
	if (__builtin_strcmp(__s, "C") != 0
	    && __builtin_strcmp(__s, "POSIX") != 0)
	  {
	    this->_S_destroy_c_locale(this->_M_c_locale_messages);
	    this->_S_create_c_locale(this->_M_c_locale_messages, __s);
	  }
     }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
