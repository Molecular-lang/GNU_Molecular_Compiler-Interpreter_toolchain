// Versatile string utility -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _VSTRING_UTIL_H
#define _VSTRING_UTIL_H 1

#pragma GCC system_header

#include <ext/vstring_fwd.h>
#include <debug/debug.h>
#include <bits/stl_function.h>  // For less
#include <bits/functexcept.h>
#include <bits/localefwd.h>
#include <bits/ostream_insert.h>
#include <bits/stl_iterator.h>
#include <ext/numeric_traits.h>
#include <ext/alloc_traits.h>
#include <bits/move.h>
#include <bits/range_access.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template<typename _CharT, typename _Traits, typename _Alloc>
    struct __vstring_utility
    {
      typedef typename __alloc_traits<_Alloc>::template rebind<_CharT>::other
	_CharT_alloc_type;
      typedef __alloc_traits<_CharT_alloc_type> _CharT_alloc_traits;

      typedef _Traits					    traits_type;
      typedef typename _Traits::char_type		    value_type;
      typedef typename _CharT_alloc_type::size_type	    size_type;
      typedef typename _CharT_alloc_type::difference_type   difference_type;
      typedef typename _CharT_alloc_traits::pointer	    pointer;
      typedef typename _CharT_alloc_traits::const_pointer   const_pointer;

      // For __sso_string.
      typedef __gnu_cxx::
      __normal_iterator<pointer, __gnu_cxx::
			__versa_string<_CharT, _Traits, _Alloc,
				       __sso_string_base> >
	__sso_iterator;
      typedef __gnu_cxx::
      __normal_iterator<const_pointer, __gnu_cxx::
			__versa_string<_CharT, _Traits, _Alloc,
				       __sso_string_base> >
	__const_sso_iterator;

      // For __rc_string.
      typedef __gnu_cxx::
      __normal_iterator<pointer, __gnu_cxx::
			__versa_string<_CharT, _Traits, _Alloc,
				       __rc_string_base> >
	__rc_iterator;
      typedef __gnu_cxx::
      __normal_iterator<const_pointer, __gnu_cxx::
			__versa_string<_CharT, _Traits, _Alloc,
				       __rc_string_base> >
	__const_rc_iterator;

      // NB:  When the allocator is empty, deriving from it saves space
      // (http://www.cantrip.org/emptyopt.html).
      template<typename _Alloc1>
	struct _Alloc_hider
	: public _Alloc1
	{
	  _Alloc_hider(_CharT* __ptr)
	  : _Alloc1(), _M_p(__ptr) { }

	  _Alloc_hider(const _Alloc1& __a, _CharT* __ptr)
	  : _Alloc1(__a), _M_p(__ptr) { }

	  _CharT*  _M_p; // The actual data.
	};

      // When __n = 1 way faster than the general multichar
      // traits_type::copy/move/assign.
      static void
      _S_copy(_CharT* __d, const _CharT* __s, size_type __n)
      {
	if (__n == 1)
	  traits_type::assign(*__d, *__s);
	else
	  traits_type::copy(__d, __s, __n);
      }

      static void
      _S_move(_CharT* __d, const _CharT* __s, size_type __n)
      {
	if (__n == 1)
	  traits_type::assign(*__d, *__s);
	else
	  traits_type::move(__d, __s, __n);
      }

      static void
      _S_assign(_CharT* __d, size_type __n, _CharT __c)
      {
	if (__n == 1)
	  traits_type::assign(*__d, __c);
	else
	  traits_type::assign(__d, __n, __c);
      }

      // _S_copy_chars is a separate template to permit specialization
      // to optimize for the common case of pointers as iterators.
      template<typename _Iterator>
	static void
	_S_copy_chars(_CharT* __p, _Iterator __k1, _Iterator __k2)
	{
	  for (; __k1 != __k2; ++__k1, ++__p)
	    traits_type::assign(*__p, *__k1); // These types are off.
	}

      static void
      _S_copy_chars(_CharT* __p, __sso_iterator __k1, __sso_iterator __k2)
      { _S_copy_chars(__p, __k1.base(), __k2.base()); }

      static void
      _S_copy_chars(_CharT* __p, __const_sso_iterator __k1,
		    __const_sso_iterator __k2)
      { _S_copy_chars(__p, __k1.base(), __k2.base()); }

      static void
      _S_copy_chars(_CharT* __p, __rc_iterator __k1, __rc_iterator __k2)
      { _S_copy_chars(__p, __k1.base(), __k2.base()); }

      static void
      _S_copy_chars(_CharT* __p, __const_rc_iterator __k1,
		    __const_rc_iterator __k2)
      { _S_copy_chars(__p, __k1.base(), __k2.base()); }

      static void
      _S_copy_chars(_CharT* __p, _CharT* __k1, _CharT* __k2)
      { _S_copy(__p, __k1, __k2 - __k1); }

      static void
      _S_copy_chars(_CharT* __p, const _CharT* __k1, const _CharT* __k2)
      { _S_copy(__p, __k1, __k2 - __k1); }

      static int
      _S_compare(size_type __n1, size_type __n2)
      {
	const difference_type __d = difference_type(__n1 - __n2);

	if (__d > __numeric_traits_integer<int>::__max)
	  return __numeric_traits_integer<int>::__max;
	else if (__d < __numeric_traits_integer<int>::__min)
	  return __numeric_traits_integer<int>::__min;
	else
	  return int(__d);
      }
    };

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif /* _VSTRING_UTIL_H */
