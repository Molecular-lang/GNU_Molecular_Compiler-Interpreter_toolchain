// Compatibility symbols for alternate 128-bit long-double format -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#define _GLIBCXX_USE_CXX11_ABI 1
#include <locale>

#ifdef _GLIBCXX_LONG_DOUBLE_ALT128_COMPAT

#if !defined(_GLIBCXX_USE_DUAL_ABI)
#error "compatibility-ldbl-alt128-cxx11.cc must only be compiled when dual ABI is enabled"
#endif

#if ! defined __LONG_DOUBLE_IBM128__ && ! defined __LONG_DOUBLE_IEEE128__
#error "compatibility-ldbl-alt128.cc must only be compiled for 128-bit long double"
#endif

#define C char
#define C_is_char
#include "locale-inst-monetary.h"

#ifdef _GLIBCXX_USE_WCHAR_T
# undef C
# undef C_is_char
# define C wchar_t
# include "locale-inst-monetary.h"
#endif

#include <functional>
namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  namespace
  {
    alignas(money_get<char>) char money_get_c[sizeof(money_get<char>)];
    alignas(money_put<char>) char money_put_c[sizeof(money_put<char>)];
#ifdef _GLIBCXX_USE_WCHAR_T
    alignas(money_get<wchar_t>) char money_get_w[sizeof(money_get<wchar_t>)];
    alignas(money_put<wchar_t>) char money_put_w[sizeof(money_put<wchar_t>)];
#endif

  template<typename Facet>
    void
    init_facet(function<void(const locale::id*, const locale::facet*)>& func,
	       Facet* facet)
    {
      func(&Facet::id, facet);
    }

  } // namespace

  template class function<void(const locale::id*, const locale::facet*)>;

  void
  __locale_Impl_init_extra_ldbl128(
      function<void(const locale::id*, const locale::facet*)> f,
      bool classic)
  {
    if (classic)
      {
	init_facet(f, new (&money_get_c) money_get<char>(1));
	init_facet(f, new (&money_put_c) money_put<char>(1));
#ifdef _GLIBCXX_USE_WCHAR_T
	init_facet(f, new (&money_get_w) money_get<wchar_t>(1));
	init_facet(f, new (&money_put_w) money_put<wchar_t>(1));
#endif
      }
    else
      {
	init_facet(f, new money_get<char>);
	init_facet(f, new money_put<char>);
#ifdef _GLIBCXX_USE_WCHAR_T
	init_facet(f, new money_get<wchar_t>);
	init_facet(f, new money_put<wchar_t>);
#endif
      }
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
#endif
