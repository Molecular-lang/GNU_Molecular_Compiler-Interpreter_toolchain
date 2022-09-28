// Allocator that wraps operator new -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _NEW_ALLOCATOR_H
#define _NEW_ALLOCATOR_H 1

#include <bits/new_allocator.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /**
   *  @brief  An allocator that uses global `new`, as per C++03 [20.4.1].
   *  @ingroup allocators
   *
   *  This is precisely the allocator defined in the C++ Standard.
   *    - all allocation calls `operator new`
   *    - all deallocation calls `operator delete`
   *
   *  This is a non-standard extension that can be used to guarantee
   *  allocation from `new` even if the library has been configured to
   *  use a different implementation for `std::allocator`.
   *
   *  @tparam  _Tp  Type of allocated object.
   *
   *  @headerfile ext/new_allocator.h
   */
  template<typename _Tp>
    class new_allocator : public std::__new_allocator<_Tp>
    {
    public:
#if __cplusplus <= 201703L
      template<typename _Tp1>
	struct rebind
	{ typedef new_allocator<_Tp1> other; };
#endif

      new_allocator() _GLIBCXX_USE_NOEXCEPT { }

      new_allocator(const new_allocator&) _GLIBCXX_USE_NOEXCEPT { }

      template<typename _Tp1>
	new_allocator(const new_allocator<_Tp1>&) _GLIBCXX_USE_NOEXCEPT { }
    };

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
