// Exception Handling support header for -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

/** @file eh_atomics.h
 *  This is an internal header file, included by library source files.
 *  Do not attempt to use it directly.
 */

#ifndef _EH_ATOMICS_H
#define _EH_ATOMICS_H 1

#include <bits/c++config.h>
#include <bits/atomic_word.h>
#include <bits/atomic_lockfree_defines.h>
#if ATOMIC_INT_LOCK_FREE <= 1
# include <ext/atomicity.h>
#endif

#pragma GCC visibility push(default)
extern "C++" {
namespace __gnu_cxx
{
  void
  __eh_atomic_inc (_Atomic_word* __count) __attribute__((always_inline));

  bool
  __eh_atomic_dec (_Atomic_word* __count) __attribute__((always_inline));

  // Increments the count.
  inline void
  __eh_atomic_inc (_Atomic_word* __count)
  {
#if ATOMIC_INT_LOCK_FREE > 1
    __atomic_add_fetch (__count, 1, __ATOMIC_ACQ_REL);
#else
    _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE (__count);
    __gnu_cxx::__atomic_add_dispatch (__count, 1);
    _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER (__count);
#endif
  }

  // Decrements the count and returns true if it reached zero.
  inline bool
  __eh_atomic_dec (_Atomic_word* __count)
  {
#if ATOMIC_INT_LOCK_FREE > 1
    return __atomic_sub_fetch (__count, 1, __ATOMIC_ACQ_REL) == 0;
#else
    _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE (__count);
    if (__gnu_cxx::__exchange_and_add_dispatch (__count, -1) == 1)
      {
	_GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER (__count);
	return true;
      }
    return false;
#endif
  }
} // namespace __gnu_cxx
}
#pragma GCC visibility pop

#endif // _EH_ATOMICS_H
