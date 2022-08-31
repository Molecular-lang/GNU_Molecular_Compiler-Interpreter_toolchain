// Concept checking instantiations -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

// The implementation of some of the more complex checks uses the simple
// checks (good reuse of code), thereby requiring that the simple checks
// be instantiated somewhere.  The simple checks use other simple checks,
// and so on, until a couple hundred symbols all need instantiations.  We
// explicitly instantiate the initial set of symbols; compiling this file
// with -fimplicit-templates will take care of the rest for us.

#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/concept_check.h>

#ifdef _GLIBCXX_CONCEPT_CHECKS

#include <memory>
#include <iterator>
#include <ostream>

#define _Instantiate(...) template void __function_requires< __VA_ARGS__ > ()

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template void __aux_require_boolean_expr<bool>(bool const&);

  _Instantiate(_ConvertibleConcept<unsigned, unsigned> );

  _Instantiate(_InputIteratorConcept<char*> );

  _Instantiate(_InputIteratorConcept<char const*> );

#ifdef _GLIBCXX_USE_WCHAR_T
  _Instantiate(_InputIteratorConcept<wchar_t*> );

  _Instantiate(_InputIteratorConcept<wchar_t const*> );

  _Instantiate(_LessThanComparableConcept<wchar_t*> );
#endif

  _Instantiate(_LessThanComparableConcept<char*> );

  _Instantiate(_LessThanComparableConcept<int> );

  _Instantiate(_LessThanComparableConcept<long> );

  _Instantiate(_LessThanComparableConcept<long long> );

  _Instantiate(_LessThanComparableConcept<unsigned> );

  _Instantiate(_OutputIteratorConcept<std::ostreambuf_iterator<
    char, std::char_traits<char> >, char> );

#ifdef _GLIBCXX_USE_WCHAR_T
  _Instantiate(_OutputIteratorConcept<std::ostreambuf_iterator<
    wchar_t, std::char_traits<wchar_t> >, wchar_t> );
#endif

  _Instantiate(_RandomAccessIteratorConcept<char*> );

  _Instantiate(_RandomAccessIteratorConcept<char const*> );

  _Instantiate(_RandomAccessIteratorConcept<
    __normal_iterator<char const*, std::string> > );

  _Instantiate(_RandomAccessIteratorConcept<
    __normal_iterator<char*, std::string> > );

#ifdef _GLIBCXX_USE_WCHAR_T
  _Instantiate(_RandomAccessIteratorConcept<
    __normal_iterator<wchar_t const*,
    std::basic_string<wchar_t, std::char_traits<wchar_t>,
                               std::allocator<wchar_t> > > > );

  _Instantiate(_RandomAccessIteratorConcept<
    __normal_iterator<wchar_t*,
    std::basic_string<wchar_t, std::char_traits<wchar_t>,
                               std::allocator<wchar_t> > > > );

  _Instantiate(_RandomAccessIteratorConcept<wchar_t*> );

  _Instantiate(_RandomAccessIteratorConcept<wchar_t const*> );
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#undef _Instantiate

#endif
