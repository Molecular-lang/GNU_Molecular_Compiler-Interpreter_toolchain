// <bits/erase_if.h> -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/erase_if.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly.
 */

#ifndef _GLIBCXX_ERASE_IF_H
#define _GLIBCXX_ERASE_IF_H 1

#pragma GCC system_header

#if __cplusplus >= 201402L

#include <bits/c++config.h>

namespace std
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

#if __cplusplus > 201703L
# define __cpp_lib_erase_if 202002L
#endif

  namespace __detail
  {
    template<typename _Container, typename _UnsafeContainer,
	     typename _Predicate>
      typename _Container::size_type
      __erase_nodes_if(_Container& __cont, const _UnsafeContainer& __ucont,
		       _Predicate __pred)
      {
	typename _Container::size_type __num = 0;
	for (auto __iter = __ucont.begin(), __last = __ucont.end();
	     __iter != __last;)
	  {
	    if (__pred(*__iter))
	      {
		__iter = __cont.erase(__iter);
		++__num;
	      }
	    else
	      ++__iter;
	  }
	return __num;
      }
  } // namespace __detail

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif // C++14

#endif // _GLIBCXX_ERASE_IF_H
