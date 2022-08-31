// Explicit instantantiations for monetary facets -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#ifndef C
#define "This file should not be compiled directly, only included"
#endif

// This header is included multiple times, to instantiate these symbols
// for char/wchar_t and for both std::string ABIs,
// and (depending on the target) for two long double formats.

namespace std _GLIBCXX_VISIBILITY(default)
{
  template const money_put<C>& use_facet<money_put<C> >(const locale&);
  template const money_get<C>& use_facet<money_get<C> >(const locale&);

  template bool has_facet<money_put<C> >(const locale&);
  template bool has_facet<money_get<C> >(const locale&);

_GLIBCXX_BEGIN_NAMESPACE_LDBL_OR_CXX11
  template class money_get<C, istreambuf_iterator<C> >;
  template class money_put<C, ostreambuf_iterator<C> >;

  template
    istreambuf_iterator<C>
    money_get<C, istreambuf_iterator<C> >::
    _M_extract<true>(istreambuf_iterator<C>, istreambuf_iterator<C>,
		     ios_base&, ios_base::iostate&, string&) const;

  template
    istreambuf_iterator<C>
    money_get<C, istreambuf_iterator<C> >::
    _M_extract<false>(istreambuf_iterator<C>, istreambuf_iterator<C>,
		      ios_base&, ios_base::iostate&, string&) const;

  template
    ostreambuf_iterator<C>
    money_put<C, ostreambuf_iterator<C> >::
    _M_insert<true>(ostreambuf_iterator<C>, ios_base&, C,
		    const string_type&) const;

  template
    ostreambuf_iterator<C>
    money_put<C, ostreambuf_iterator<C> >::
    _M_insert<false>(ostreambuf_iterator<C>, ios_base&, C,
		     const string_type&) const;
_GLIBCXX_END_NAMESPACE_LDBL_OR_CXX11
} // namespace std
