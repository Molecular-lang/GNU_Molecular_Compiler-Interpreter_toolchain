// Helpers for ostream inserters -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/ostream_insert.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{ostream}
 */

#ifndef _OSTREAM_INSERT_H
#define _OSTREAM_INSERT_H 1

#pragma GCC system_header

#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/exception_defines.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /// @cond undocumented

  template<typename _CharT, typename _Traits>
    inline void
    __ostream_write(basic_ostream<_CharT, _Traits>& __out,
		    const _CharT* __s, streamsize __n)
    {
      typedef basic_ostream<_CharT, _Traits>       __ostream_type;      
      typedef typename __ostream_type::ios_base    __ios_base;

      const streamsize __put = __out.rdbuf()->sputn(__s, __n);
      if (__put != __n)
	__out.setstate(__ios_base::badbit);
    }

  template<typename _CharT, typename _Traits>
    inline void
    __ostream_fill(basic_ostream<_CharT, _Traits>& __out, streamsize __n)
    {
      typedef basic_ostream<_CharT, _Traits>       __ostream_type;      
      typedef typename __ostream_type::ios_base    __ios_base;

      const _CharT __c = __out.fill();
      for (; __n > 0; --__n)
	{
	  const typename _Traits::int_type __put = __out.rdbuf()->sputc(__c);
	  if (_Traits::eq_int_type(__put, _Traits::eof()))
	    {
	      __out.setstate(__ios_base::badbit);
	      break;
	    }
	}
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    __ostream_insert(basic_ostream<_CharT, _Traits>& __out,
		     const _CharT* __s, streamsize __n)
    {
      typedef basic_ostream<_CharT, _Traits>       __ostream_type;
      typedef typename __ostream_type::ios_base    __ios_base;

      typename __ostream_type::sentry __cerb(__out);
      if (__cerb)
	{
	  __try
	    {
	      const streamsize __w = __out.width();
	      if (__w > __n)
		{
		  const bool __left = ((__out.flags()
					& __ios_base::adjustfield)
				       == __ios_base::left);
		  if (!__left)
		    __ostream_fill(__out, __w - __n);
		  if (__out.good())
		    __ostream_write(__out, __s, __n);
		  if (__left && __out.good())
		    __ostream_fill(__out, __w - __n);
		}
	      else
		__ostream_write(__out, __s, __n);
	      __out.width(0);
	    }
	  __catch(__cxxabiv1::__forced_unwind&)
	    {
	      __out._M_setstate(__ios_base::badbit);
	      __throw_exception_again;
	    }
	  __catch(...)
	    { __out._M_setstate(__ios_base::badbit); }
	}
      return __out;
    }

  // Inhibit implicit instantiations for required instantiations,
  // which are defined via explicit instantiations elsewhere.
#if _GLIBCXX_EXTERN_TEMPLATE
  extern template ostream& __ostream_insert(ostream&, const char*, streamsize);

#ifdef _GLIBCXX_USE_WCHAR_T
  extern template wostream& __ostream_insert(wostream&, const wchar_t*,
					     streamsize);
#endif
#endif

  /// @endcond

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif /* _OSTREAM_INSERT_H */
