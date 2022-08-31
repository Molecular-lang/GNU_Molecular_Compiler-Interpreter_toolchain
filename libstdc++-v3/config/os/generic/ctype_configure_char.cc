// Locale support -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file ctype_configure_char.cc */

//
// ISO C++ 14882: 22.1  Locales
//

#include <locale>
#include <cstdlib>
#include <cstring>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

// Information as gleaned from /usr/include/ctype.h

  const ctype_base::mask*
  ctype<char>::classic_table() throw()
  { return 0; }

  ctype<char>::ctype(__c_locale, const mask* __table, bool __del,
		     size_t __refs)
  : facet(__refs), _M_del(__table != 0 && __del),
  _M_toupper(NULL), _M_tolower(NULL),
  _M_table(__table ? __table : classic_table())
  {
    memset(_M_widen, 0, sizeof(_M_widen));
    _M_widen_ok = 0;
    memset(_M_narrow, 0, sizeof(_M_narrow));
    _M_narrow_ok = 0;
  }

  ctype<char>::ctype(const mask* __table, bool __del, size_t __refs)
  : facet(__refs), _M_del(__table != 0 && __del),
  _M_toupper(NULL), _M_tolower(NULL),
  _M_table(__table ? __table : classic_table())
  {
    memset(_M_widen, 0, sizeof(_M_widen));
    _M_widen_ok = 0;
    memset(_M_narrow, 0, sizeof(_M_narrow));
    _M_narrow_ok = 0;
  }

  char
  ctype<char>::do_toupper(char __c) const
  { return ::toupper((int) __c); }

  const char*
  ctype<char>::do_toupper(char* __low, const char* __high) const
  {
    while (__low < __high)
      {
	*__low = ::toupper((int) *__low);
	++__low;
      }
    return __high;
  }

  char
  ctype<char>::do_tolower(char __c) const
  { return ::tolower((int) __c); }

  const char*
  ctype<char>::do_tolower(char* __low, const char* __high) const
  {
    while (__low < __high)
      {
	*__low = ::tolower((int) *__low);
	++__low;
      }
    return __high;
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
