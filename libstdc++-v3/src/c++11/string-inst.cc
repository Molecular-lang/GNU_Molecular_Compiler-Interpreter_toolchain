// Components for manipulating sequences of characters -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 21  Strings library
//

// Written by Jason Merrill based upon the specification by Takanori Adachi
// in ANSI X3J16/94-0013R2.  Rewritten by Nathan Myers.

#ifndef _GLIBCXX_USE_CXX11_ABI
// Instantiations in this file use the new SSO std::string ABI unless included
// by another file which defines _GLIBCXX_USE_CXX11_ABI=0.
# define _GLIBCXX_USE_CXX11_ABI 1
#endif

// Prevent the basic_string(const _CharT*, const _Alloc&) and
// basic_string(size_type, _CharT, const _Alloc&) constructors from being
// replaced by constrained function templates, so that we instantiate the
// pre-C++17 definitions.
// This also causes the instantiation of the non-standard C++0x-era
// insert(iterator, initializer_list<C>) overload, see PR libstdc++/83328
#define _GLIBCXX_DEFINING_STRING_INSTANTIATIONS 1

#include <string>

// Instantiation configuration.
#ifndef C
# define C char
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  typedef basic_string<C> S;

  template class basic_string<C>;
  template S operator+(const C*, const S&);
  template S operator+(C, const S&);
  template S operator+(const S&, const S&);

  // Only one template keyword allowed here.
  // See core issue #46 (NAD)
  // http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_closed.html#46
  template
    S::basic_string(C*, C*, const allocator<C>&);

  template
    S::basic_string(const C*, const C*, const allocator<C>&);

  template
    S::basic_string(S::iterator, S::iterator, const allocator<C>&);

#if _GLIBCXX_USE_CXX11_ABI
  template
    void
    S::_M_construct(S::iterator, S::iterator, forward_iterator_tag);

  template
    void
    S::_M_construct(S::const_iterator, S::const_iterator,
		    forward_iterator_tag);

  template
    void
    S::_M_construct(C*, C*, forward_iterator_tag);

  template
    void
    S::_M_construct(const C*, const C*, forward_iterator_tag);

#else // !_GLIBCXX_USE_CXX11_ABI

  template
    C*
    S::_S_construct(S::iterator, S::iterator,
		    const allocator<C>&, forward_iterator_tag);

  template
    C*
    S::_S_construct(C*, C*, const allocator<C>&, forward_iterator_tag);

  template
    C*
    S::_S_construct(const C*, const C*, const allocator<C>&,
		    forward_iterator_tag);
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  using std::S;
  template bool operator==(const S::iterator&, const S::iterator&);
  template bool operator==(const S::const_iterator&, const S::const_iterator&);

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
