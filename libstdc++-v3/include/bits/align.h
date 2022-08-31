// align implementation -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/align.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{memory}
 */

#ifndef _GLIBCXX_ALIGN_H
#define _GLIBCXX_ALIGN_H 1

#include <bits/c++config.h>

#include <bit>          // std::has_single_bit
#include <stdint.h>     // uintptr_t
#include <debug/assertions.h> // _GLIBCXX_DEBUG_ASSERT

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

/**
 *  @brief Fit aligned storage in buffer.
 *
 *  This function tries to fit @a __size bytes of storage with alignment
 *  @a __align into the buffer @a __ptr of size @a __space bytes.  If such
 *  a buffer fits then @a __ptr is changed to point to the first byte of the
 *  aligned storage and @a __space is reduced by the bytes used for alignment.
 *
 *  C++11 20.6.5 [ptr.align]
 *
 *  @param __align   A fundamental or extended alignment value.
 *  @param __size    Size of the aligned storage required.
 *  @param __ptr     Pointer to a buffer of @a __space bytes.
 *  @param __space   Size of the buffer pointed to by @a __ptr.
 *  @return the updated pointer if the aligned storage fits, otherwise nullptr.
 *
 *  @ingroup memory
 */
inline void*
align(size_t __align, size_t __size, void*& __ptr, size_t& __space) noexcept
{
  if (__space < __size)
    return nullptr;
  const auto __intptr = reinterpret_cast<uintptr_t>(__ptr);
  const auto __aligned = (__intptr - 1u + __align) & -__align;
  const auto __diff = __aligned - __intptr;
  if (__diff > (__space - __size))
    return nullptr;
  else
    {
      __space -= __diff;
      return __ptr = reinterpret_cast<void*>(__aligned);
    }
}

#if __cplusplus > 201703L
#define __cpp_lib_assume_aligned 201811L
  /** @brief Inform the compiler that a pointer is aligned.
   *
   *  @tparam _Align An alignment value (i.e. a power of two)
   *  @tparam _Tp    An object type
   *  @param  __ptr  A pointer that is aligned to _Align
   *
   *  C++20 20.10.6 [ptr.align]
   *
   *  @ingroup memory
   */
  template<size_t _Align, class _Tp>
    [[nodiscard,__gnu__::__always_inline__]]
    constexpr _Tp*
    assume_aligned(_Tp* __ptr) noexcept
    {
      static_assert(std::has_single_bit(_Align));
      if (std::is_constant_evaluated())
	return __ptr;
      else
	{
	  // This function is expected to be used in hot code, where
	  // __glibcxx_assert would add unwanted overhead.
	  _GLIBCXX_DEBUG_ASSERT((uintptr_t)__ptr % _Align == 0);
	  return static_cast<_Tp*>(__builtin_assume_aligned(__ptr, _Align));
	}
    }
#endif // C++2a

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif /* _GLIBCXX_ALIGN_H */
