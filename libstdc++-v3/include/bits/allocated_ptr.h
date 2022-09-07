// Guarded Allocation -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/allocated_ptr.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{memory}
 */

#ifndef _ALLOCATED_PTR_H
#define _ALLOCATED_PTR_H 1

#if __cplusplus < 201103L
# include <bits/c++0xwarning.h>
#else
# include <type_traits>
# include <bits/ptr_traits.h>
# include <bits/alloc_traits.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION
/// @cond undocumented

  /// Non-standard RAII type for managing pointers obtained from allocators.
  template<typename _Alloc>
    struct __allocated_ptr
    {
      using pointer = typename allocator_traits<_Alloc>::pointer;
      using value_type = typename allocator_traits<_Alloc>::value_type;

      /// Take ownership of __ptr
      __allocated_ptr(_Alloc& __a, pointer __ptr) noexcept
      : _M_alloc(std::__addressof(__a)), _M_ptr(__ptr)
      { }

      /// Convert __ptr to allocator's pointer type and take ownership of it
      template<typename _Ptr,
	       typename _Req = _Require<is_same<_Ptr, value_type*>>>
      __allocated_ptr(_Alloc& __a, _Ptr __ptr)
      : _M_alloc(std::__addressof(__a)),
	_M_ptr(pointer_traits<pointer>::pointer_to(*__ptr))
      { }

      /// Transfer ownership of the owned pointer
      __allocated_ptr(__allocated_ptr&& __gd) noexcept
      : _M_alloc(__gd._M_alloc), _M_ptr(__gd._M_ptr)
      { __gd._M_ptr = nullptr; }

      /// Deallocate the owned pointer
      ~__allocated_ptr()
      {
	if (_M_ptr != nullptr)
	  std::allocator_traits<_Alloc>::deallocate(*_M_alloc, _M_ptr, 1);
      }

      /// Release ownership of the owned pointer
      __allocated_ptr&
      operator=(std::nullptr_t) noexcept
      {
	_M_ptr = nullptr;
	return *this;
      }

      /// Get the address that the owned pointer refers to.
      value_type* get() { return std::__to_address(_M_ptr); }

    private:
      _Alloc* _M_alloc;
      pointer _M_ptr;
    };

  /// Allocate space for a single object using __a
  template<typename _Alloc>
    __allocated_ptr<_Alloc>
    __allocate_guarded(_Alloc& __a)
    {
      return { __a, std::allocator_traits<_Alloc>::allocate(__a, 1) };
    }

/// @endcond
_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif
#endif
