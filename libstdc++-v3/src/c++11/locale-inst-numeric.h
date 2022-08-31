// Explicit instantantiations for numeric facets -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#ifndef C
#define "This file should not be compiled directly, only included"
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
#if ! _GLIBCXX_USE_CXX11_ABI
  template const num_get<C>& use_facet<num_get<C> >(const locale&);
  template const num_put<C>& use_facet<num_put<C> >(const locale&);

  template bool has_facet<num_get<C> >(const locale&);
  template bool has_facet<num_put<C> >(const locale&);
#endif

_GLIBCXX_BEGIN_NAMESPACE_LDBL

#if ! _GLIBCXX_USE_CXX11_ABI
  template class num_get<C, istreambuf_iterator<C> >;
  template class num_put<C, ostreambuf_iterator<C> >;
#endif

  // num_get member function templates
  template
    istreambuf_iterator<C>
    num_get<C, istreambuf_iterator<C> >::
    _M_extract_int(istreambuf_iterator<C>, istreambuf_iterator<C>,
		   ios_base&, ios_base::iostate&,
		   long&) const;

  template
    istreambuf_iterator<C>
    num_get<C, istreambuf_iterator<C> >::
    _M_extract_int(istreambuf_iterator<C>, istreambuf_iterator<C>,
		   ios_base&, ios_base::iostate&,
		   unsigned short&) const;

  template
    istreambuf_iterator<C>
    num_get<C, istreambuf_iterator<C> >::
    _M_extract_int(istreambuf_iterator<C>, istreambuf_iterator<C>,
		   ios_base&, ios_base::iostate&,
		   unsigned int&) const;

  template
    istreambuf_iterator<C>
    num_get<C, istreambuf_iterator<C> >::
    _M_extract_int(istreambuf_iterator<C>, istreambuf_iterator<C>,
		   ios_base&, ios_base::iostate&,
		   unsigned long&) const;

#ifdef _GLIBCXX_USE_LONG_LONG
  template
    istreambuf_iterator<C>
    num_get<C, istreambuf_iterator<C> >::
    _M_extract_int(istreambuf_iterator<C>, istreambuf_iterator<C>,
		   ios_base&, ios_base::iostate&,
		   long long&) const;

  template
    istreambuf_iterator<C>
    num_get<C, istreambuf_iterator<C> >::
    _M_extract_int(istreambuf_iterator<C>, istreambuf_iterator<C>,
		   ios_base&, ios_base::iostate&,
		   unsigned long long&) const;
#endif

#if ! _GLIBCXX_USE_CXX11_ABI
  // num_put member function templates
  template
    ostreambuf_iterator<C>
    num_put<C, ostreambuf_iterator<C> >::
    _M_insert_int(ostreambuf_iterator<C>, ios_base&, C,
		  long) const;

  template
    ostreambuf_iterator<C>
    num_put<C, ostreambuf_iterator<C> >::
    _M_insert_int(ostreambuf_iterator<C>, ios_base&, C,
		  unsigned long) const;

#ifdef _GLIBCXX_USE_LONG_LONG
  template
    ostreambuf_iterator<C>
    num_put<C, ostreambuf_iterator<C> >::
    _M_insert_int(ostreambuf_iterator<C>, ios_base&, C,
		  long long) const;

  template
    ostreambuf_iterator<C>
    num_put<C, ostreambuf_iterator<C> >::
    _M_insert_int(ostreambuf_iterator<C>, ios_base&, C,
		  unsigned long long) const;
#endif

  template
    ostreambuf_iterator<C>
    num_put<C, ostreambuf_iterator<C> >::
    _M_insert_float(ostreambuf_iterator<C>, ios_base&, C, char,
		    double) const;

  template
    ostreambuf_iterator<C>
    num_put<C, ostreambuf_iterator<C> >::
    _M_insert_float(ostreambuf_iterator<C>, ios_base&, C, char,
		    long double) const;
#endif

_GLIBCXX_END_NAMESPACE_LDBL
} // namespace std
