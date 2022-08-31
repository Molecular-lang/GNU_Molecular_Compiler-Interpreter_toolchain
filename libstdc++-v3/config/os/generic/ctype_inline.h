// Locale support -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.1  Locales
//

// ctype bits to be inlined go here. Non-inlinable (ie virtual do_*)
// functions go in ctype.cc

// The following definitions are portable, but insanely slow. If one
// cares at all about performance, then specialized ctype
// functionality should be added for the native os in question: see
// the config/os/bits/ctype_*.h files.

// Constructing a synthetic "C" table should be seriously considered...

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  bool
  ctype<char>::
  is(mask __m, char __c) const
  {
    if (_M_table)
      return _M_table[static_cast<unsigned char>(__c)] & __m;
    else
      {
	bool __ret = false;
	const size_t __bitmasksize = 15;
	size_t __bitcur = 0; // Lowest bitmask in ctype_base == 0
	for (; __bitcur <= __bitmasksize; ++__bitcur)
	  {
	    const mask __bit = static_cast<mask>(1 << __bitcur);
	    if (__m & __bit)
	      {
		bool __testis;
		switch (__bit)
		  {
		  case space:
		    __testis = isspace(__c);
		    break;
		  case print:
		    __testis = isprint(__c);
		    break;
		  case cntrl:
		    __testis = iscntrl(__c);
		    break;
		  case upper:
		    __testis = isupper(__c);
		    break;
		  case lower:
		    __testis = islower(__c);
		    break;
		  case alpha:
		    __testis = isalpha(__c);
		    break;
		  case digit:
		    __testis = isdigit(__c);
		    break;
		  case punct:
		    __testis = ispunct(__c);
		    break;
		  case xdigit:
		    __testis = isxdigit(__c);
		    break;
		  case alnum:
		    __testis = isalnum(__c);
		    break;
		  case graph:
		    __testis = isgraph(__c);
		    break;
#ifdef _GLIBCXX_USE_C99_CTYPE_TR1
		  case blank:
		    __testis = isblank(__c);
		    break;
#endif
		  default:
		    __testis = false;
		    break;
		  }
		__ret |= __testis;
	      }
	  }
	return __ret;
      }
  }

  const char*
  ctype<char>::
  is(const char* __low, const char* __high, mask* __vec) const
  {
    if (_M_table)
      while (__low < __high)
	*__vec++ = _M_table[static_cast<unsigned char>(*__low++)];
    else
      {
	// Highest bitmask in ctype_base == 11.
	const size_t __bitmasksize = 15;
	for (;__low < __high; ++__vec, ++__low)
	  {
	    mask __m = 0;
	    // Lowest bitmask in ctype_base == 0
	    size_t __i = 0;
	    for (;__i <= __bitmasksize; ++__i)
	      {
		const mask __bit = static_cast<mask>(1 << __i);
		if (this->is(__bit, *__low))
		  __m |= __bit;
	      }
	    *__vec = __m;
	  }
      }
    return __high;
  }

  const char*
  ctype<char>::
  scan_is(mask __m, const char* __low, const char* __high) const
  {
    if (_M_table)
      while (__low < __high
	     && !(_M_table[static_cast<unsigned char>(*__low)] & __m))
	++__low;
    else
      while (__low < __high && !this->is(__m, *__low))
	++__low;
    return __low;
  }

  const char*
  ctype<char>::
  scan_not(mask __m, const char* __low, const char* __high) const
  {
    if (_M_table)
      while (__low < __high
	     && (_M_table[static_cast<unsigned char>(*__low)] & __m) != 0)
	++__low;
    else
      while (__low < __high && this->is(__m, *__low) != 0)
	++__low;
    return __low;
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
