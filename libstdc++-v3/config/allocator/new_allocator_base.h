// Base to std::allocator -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_CXX_ALLOCATOR_H
#define _GLIBCXX_CXX_ALLOCATOR_H 1

#include <bits/new_allocator.h>

#if __cplusplus >= 201103L
namespace std
{
  /**
   *  @brief  An alias to the base class for std::allocator.
   *
   *  Used to set the std::allocator base class to std::__new_allocator.
   *
   *  @ingroup allocators
   *  @tparam  _Tp  Type of allocated object.
    */
  template<typename _Tp>
    using __allocator_base = __new_allocator<_Tp>;
}
#else
// Define __new_allocator as the base class to std::allocator.
# define __allocator_base  __new_allocator
#endif

#ifndef _GLIBCXX_SANITIZE_STD_ALLOCATOR
# if defined(__SANITIZE_ADDRESS__)
#  define _GLIBCXX_SANITIZE_STD_ALLOCATOR 1
# elif defined __has_feature
#  if __has_feature(address_sanitizer)
#   define _GLIBCXX_SANITIZE_STD_ALLOCATOR 1
#  endif
# endif
#endif

#endif
