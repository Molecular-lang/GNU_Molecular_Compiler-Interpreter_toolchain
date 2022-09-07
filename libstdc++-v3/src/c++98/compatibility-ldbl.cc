// Compatibility symbols for -mlong-double-64 compatibility -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#define _GLIBCXX_USE_CXX11_ABI 0
#include <locale>
#include <cmath>
#include <tr1/functional>

#ifdef _GLIBCXX_LONG_DOUBLE_COMPAT

#ifdef __LONG_DOUBLE_128__
#error "compatibility-ldbl.cc must be compiled with -mlong-double-64"
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
#define C char
  template class num_get<C, istreambuf_iterator<C> >;
  template class num_put<C, ostreambuf_iterator<C> >;
  template class money_get<C, istreambuf_iterator<C> >;
  template class money_put<C, ostreambuf_iterator<C> >;
  template const num_put<C>& use_facet<num_put<C> >(const locale&);
  template const num_get<C>& use_facet<num_get<C> >(const locale&);
  template const money_put<C>& use_facet<money_put<C> >(const locale&);
  template const money_get<C>& use_facet<money_get<C> >(const locale&);
  template bool has_facet<num_put<C> >(const locale&);
  template bool has_facet<num_get<C> >(const locale&);
  template bool has_facet<money_put<C> >(const locale&);
  template bool has_facet<money_get<C> >(const locale&);
#undef C
#ifdef _GLIBCXX_USE_WCHAR_T
#define C wchar_t
  template class num_get<C, istreambuf_iterator<C> >;
  template class num_put<C, ostreambuf_iterator<C> >;
  template class money_get<C, istreambuf_iterator<C> >;
  template class money_put<C, ostreambuf_iterator<C> >;
  template const num_put<C>& use_facet<num_put<C> >(const locale&);
  template const num_get<C>& use_facet<num_get<C> >(const locale&);
  template const money_put<C>& use_facet<money_put<C> >(const locale&);
  template const money_get<C>& use_facet<money_get<C> >(const locale&);
  template bool has_facet<num_put<C> >(const locale&);
  template bool has_facet<num_get<C> >(const locale&);
  template bool has_facet<money_put<C> >(const locale&);
  template bool has_facet<money_get<C> >(const locale&);
#undef C
#endif
}

// For std::tr1::hash<long double>::operator()
#define _GLIBCXX_LONG_DOUBLE_COMPAT_IMPL
#include "hash-long-double-tr1-aux.cc"

// std::tr1::hash<long double>::operator()
// and std::hash<long double>::operator()
// are the same, no need to duplicate them.
extern "C" std::size_t _ZNKSt4hashIeEclEe (long double)
  _GLIBCXX_PURE __attribute__((alias ("_ZNKSt3tr14hashIeEclEe")));

#endif
