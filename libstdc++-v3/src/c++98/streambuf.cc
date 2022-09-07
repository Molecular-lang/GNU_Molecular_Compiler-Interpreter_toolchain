// Stream buffer classes -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 27.5  Stream buffers
//

#include <streambuf>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template<>
    streamsize
    __copy_streambufs_eof(basic_streambuf<char>* __sbin,
			  basic_streambuf<char>* __sbout, bool& __ineof)
    {
      typedef basic_streambuf<char>::traits_type traits_type;
      streamsize __ret = 0;
      __ineof = true;
      traits_type::int_type __c = __sbin->sgetc();
      while (!traits_type::eq_int_type(__c, traits_type::eof()))
	{
	  const streamsize __n = __sbin->egptr() - __sbin->gptr();
	  if (__n > 1)
	    {
	      const streamsize __wrote = __sbout->sputn(__sbin->gptr(), __n);
	      __sbin->__safe_gbump(__wrote);
	      __ret += __wrote;
	      if (__wrote < __n)
		{
		  __ineof = false;
		  break;
		}
	      __c = __sbin->underflow();
	    }
	  else
	    {
	      __c = __sbout->sputc(traits_type::to_char_type(__c));
	      if (traits_type::eq_int_type(__c, traits_type::eof()))
		{
		  __ineof = false;
		  break;
		}
	      ++__ret;
	      __c = __sbin->snextc();
	    }
	}
      return __ret;
    }

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    streamsize
    __copy_streambufs_eof(basic_streambuf<wchar_t>* __sbin,
			  basic_streambuf<wchar_t>* __sbout, bool& __ineof)
    {
      typedef basic_streambuf<wchar_t>::traits_type traits_type;
      streamsize __ret = 0;
      __ineof = true;
      traits_type::int_type __c = __sbin->sgetc();
      while (!traits_type::eq_int_type(__c, traits_type::eof()))
	{
	  const streamsize __n = __sbin->egptr() - __sbin->gptr();
	  if (__n > 1)
	    {
	      const streamsize __wrote = __sbout->sputn(__sbin->gptr(), __n);
	      __sbin->__safe_gbump(__wrote);
	      __ret += __wrote;
	      if (__wrote < __n)
		{
		  __ineof = false;
		  break;
		}
	      __c = __sbin->underflow();
	    }
	  else
	    {
	      __c = __sbout->sputc(traits_type::to_char_type(__c));
	      if (traits_type::eq_int_type(__c, traits_type::eof()))
		{
		  __ineof = false;
		  break;
		}
	      ++__ret;
	      __c = __sbin->snextc();
	    }
	}
      return __ret;
    }
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
