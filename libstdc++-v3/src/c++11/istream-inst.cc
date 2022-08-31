// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#include <istream>
#include <iomanip>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template class basic_istream<char>;
  template istream& ws(istream&);
  template istream& operator>>(istream&, char&);
  template istream& operator>>(istream&, unsigned char&);
  template istream& operator>>(istream&, signed char&);

#if ! _GLIBCXX_INLINE_VERSION
  // XXX GLIBCXX_ABI Deprecated
  template istream& operator>>(istream&, char*);
  template istream& operator>>(istream&, unsigned char*);
  template istream& operator>>(istream&, signed char*);
#endif

  template istream& operator>>(istream&, _Setfill<char>);
  template istream& operator>>(istream&, _Setiosflags);
  template istream& operator>>(istream&, _Resetiosflags);
  template istream& operator>>(istream&, _Setbase);
  template istream& operator>>(istream&, _Setprecision);
  template istream& operator>>(istream&, _Setw);

  template istream& istream::_M_extract(unsigned short&);
  template istream& istream::_M_extract(unsigned int&);
  template istream& istream::_M_extract(long&);
  template istream& istream::_M_extract(unsigned long&);
  template istream& istream::_M_extract(bool&);
#ifdef _GLIBCXX_USE_LONG_LONG
  template istream& istream::_M_extract(long long&);
  template istream& istream::_M_extract(unsigned long long&);
#endif
  template istream& istream::_M_extract(float&);
  template istream& istream::_M_extract(double&);
  template istream& istream::_M_extract(long double&);
  template istream& istream::_M_extract(void*&);

#ifdef _GLIBCXX_USE_WCHAR_T
  template class basic_istream<wchar_t>;
  template wistream& ws(wistream&);
  template wistream& operator>>(wistream&, wchar_t&);
  template void __istream_extract(wistream&, wchar_t*, streamsize);

#if ! _GLIBCXX_INLINE_VERSION
  // XXX GLIBCXX_ABI Deprecated
  template wistream& operator>>(wistream&, wchar_t*);
#endif

  template wistream& operator>>(wistream&, _Setfill<wchar_t>);
  template wistream& operator>>(wistream&, _Setiosflags);
  template wistream& operator>>(wistream&, _Resetiosflags);
  template wistream& operator>>(wistream&, _Setbase);
  template wistream& operator>>(wistream&, _Setprecision);
  template wistream& operator>>(wistream&, _Setw);

  template wistream& wistream::_M_extract(unsigned short&);
  template wistream& wistream::_M_extract(unsigned int&);
  template wistream& wistream::_M_extract(long&);
  template wistream& wistream::_M_extract(unsigned long&);
  template wistream& wistream::_M_extract(bool&);
#ifdef _GLIBCXX_USE_LONG_LONG
  template wistream& wistream::_M_extract(long long&);
  template wistream& wistream::_M_extract(unsigned long long&);
#endif
  template wistream& wistream::_M_extract(float&);
  template wistream& wistream::_M_extract(double&);
  template wistream& wistream::_M_extract(long double&);
  template wistream& wistream::_M_extract(void*&);
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

// XXX GLIBCXX_ABI Deprecated
#ifdef _GLIBCXX_LONG_DOUBLE_COMPAT

#pragma GCC diagnostic ignored "-Wattribute-alias"

#define _GLIBCXX_LDBL_COMPAT(dbl, ldbl) \
  extern "C" void ldbl (void) __attribute__ ((alias (#dbl), weak))
_GLIBCXX_LDBL_COMPAT (_ZNSirsERd, _ZNSirsERe);
#ifdef _GLIBCXX_USE_WCHAR_T
_GLIBCXX_LDBL_COMPAT (_ZNSt13basic_istreamIwSt11char_traitsIwEErsERd,
		      _ZNSt13basic_istreamIwSt11char_traitsIwEErsERe);
#endif
_GLIBCXX_LDBL_COMPAT (_ZNSi10_M_extractIdEERSiRT_,
		      _ZNSi10_M_extractIeEERSiRT_);
#ifdef _GLIBCXX_USE_WCHAR_T
_GLIBCXX_LDBL_COMPAT (_ZNSt13basic_istreamIwSt11char_traitsIwEE10_M_extractIdEERS2_RT_,
		      _ZNSt13basic_istreamIwSt11char_traitsIwEE10_M_extractIeEERS2_RT_);
#endif

#endif // _GLIBCXX_LONG_DOUBLE_COMPAT
