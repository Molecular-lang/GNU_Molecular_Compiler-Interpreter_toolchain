// The template and inlines for the -*- C++ -*- complex number classes.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <complex>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template
    basic_istream<char, char_traits<char> >&
    operator>>(basic_istream<char, char_traits<char> >&, complex<float>&);

  template
    basic_ostream<char, char_traits<char> >&
    operator<<(basic_ostream<char, char_traits<char> >&,
	       const complex<float>&);

  template
    basic_istream<char, char_traits<char> >&
    operator>>(basic_istream<char, char_traits<char> >&, complex<double>&);

  template
    basic_ostream<char, char_traits<char> >&
    operator<<(basic_ostream<char, char_traits<char> >&,
	       const complex<double>&);

  template
    basic_istream<char, char_traits<char> >&
    operator>>(basic_istream<char, char_traits<char> >&,
	       complex<long double>&);

  template
    basic_ostream<char, char_traits<char> >&
    operator<<(basic_ostream<char, char_traits<char> >&,
               const complex<long double>&);

#ifdef _GLIBCXX_USE_WCHAR_T
  template
    basic_istream<wchar_t, char_traits<wchar_t> >&
    operator>>(basic_istream<wchar_t, char_traits<wchar_t> >&,
               complex<float>&);

  template
    basic_ostream<wchar_t, char_traits<wchar_t> >&
    operator<<(basic_ostream<wchar_t, char_traits<wchar_t> >&,
               const complex<float>&);

  template
    basic_istream<wchar_t, char_traits<wchar_t> >&
    operator>>(basic_istream<wchar_t, char_traits<wchar_t> >&,
               complex<double>&);

  template
    basic_ostream<wchar_t, char_traits<wchar_t> >&
    operator<<(basic_ostream<wchar_t, char_traits<wchar_t> >&,
               const complex<double>&);

  template
    basic_istream<wchar_t, char_traits<wchar_t> >&
    operator>>(basic_istream<wchar_t, char_traits<wchar_t> >&,
               complex<long double>&);

  template
    basic_ostream<wchar_t, char_traits<wchar_t> >&
    operator<<(basic_ostream<wchar_t, char_traits<wchar_t> >&,
               const complex<long double>&);
#endif //_GLIBCXX_USE_WCHAR_T

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

// XXX GLIBCXX_ABI Deprecated
#ifdef _GLIBCXX_LONG_DOUBLE_COMPAT

#define _GLIBCXX_LDBL_COMPAT(dbl, ldbl) \
  extern "C" void ldbl (...) __attribute__ ((alias (#dbl), weak))

_GLIBCXX_LDBL_COMPAT (_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E,
		      _ZStlsIecSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E);
#ifdef _GLIBCXX_USE_WCHAR_T
_GLIBCXX_LDBL_COMPAT (_ZStlsIdwSt11char_traitsIwEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E,
		      _ZStlsIewSt11char_traitsIwEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E);
#endif
_GLIBCXX_LDBL_COMPAT (_ZStrsIdcSt11char_traitsIcEERSt13basic_istreamIT0_T1_ES6_RSt7complexIT_E,
		      _ZStrsIecSt11char_traitsIcEERSt13basic_istreamIT0_T1_ES6_RSt7complexIT_E);
#ifdef _GLIBCXX_USE_WCHAR_T
_GLIBCXX_LDBL_COMPAT (_ZStrsIdwSt11char_traitsIwEERSt13basic_istreamIT0_T1_ES6_RSt7complexIT_E,
		      _ZStrsIewSt11char_traitsIwEERSt13basic_istreamIT0_T1_ES6_RSt7complexIT_E);
#endif

#endif // _GLIBCXX_LONG_DOUBLE_COMPAT
