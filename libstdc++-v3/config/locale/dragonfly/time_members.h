// std::time_get, std::time_put implementation, DragonFly version -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.2.5.1.2 - time_get functions
// ISO C++ 14882: 22.2.5.3.2 - time_put functions
//

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template<typename _CharT>
    __timepunct<_CharT>::__timepunct(size_t __refs)
    : facet(__refs), _M_data(0), _M_c_locale_timepunct(0),
      _M_name_timepunct(_S_get_c_name())
    { _M_initialize_timepunct(); }

  template<typename _CharT>
    __timepunct<_CharT>::__timepunct(__cache_type* __cache, size_t __refs)
    : facet(__refs), _M_data(__cache), _M_c_locale_timepunct(0),
      _M_name_timepunct(_S_get_c_name())
    { _M_initialize_timepunct(); }

  template<typename _CharT>
    __timepunct<_CharT>::__timepunct(__c_locale __cloc, const char* __s,
				     size_t __refs)
    : facet(__refs), _M_data(0), _M_c_locale_timepunct(0),
      _M_name_timepunct(0)
    {
      if (__builtin_strcmp(__s, _S_get_c_name()) != 0)
	{
	  const size_t __len = __builtin_strlen(__s) + 1;
	  char* __tmp = new char[__len];
	  __builtin_memcpy(__tmp, __s, __len);
	  _M_name_timepunct = __tmp;
	}
      else
	_M_name_timepunct = _S_get_c_name();

      __try
	{ _M_initialize_timepunct(__cloc); }
      __catch(...)
	{
	  if (_M_name_timepunct != _S_get_c_name())
	    delete [] _M_name_timepunct;
	  __throw_exception_again;
	}
    }

  template<typename _CharT>
    __timepunct<_CharT>::~__timepunct()
    {
      if (_M_name_timepunct != _S_get_c_name())
	delete [] _M_name_timepunct;
      delete _M_data;
      _S_destroy_c_locale(_M_c_locale_timepunct);
    }

  // specialization
  template<>
    __timepunct<wchar_t>::~__timepunct();


_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
