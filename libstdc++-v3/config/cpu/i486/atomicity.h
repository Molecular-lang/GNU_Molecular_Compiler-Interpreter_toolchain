// Low-level functions for atomic operations: x86, x >= 4 version  -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <ext/atomicity.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  _Atomic_word
  __attribute__ ((__unused__))
  __exchange_and_add(volatile _Atomic_word* __mem, int __val) throw ()
  {
    register _Atomic_word __result;
    __asm__ __volatile__ ("lock; xadd{l} {%0,%1|%1,%0}"
			  : "=r" (__result), "=m" (*__mem)
			  : "0" (__val), "m" (*__mem));
    return __result;
  }

  void
  __attribute__ ((__unused__))
  __atomic_add(volatile _Atomic_word* __mem, int __val) throw ()
  {
    __asm__ __volatile__ ("lock; add{l} {%1,%0|%0,%1}"
			  : "=m" (*__mem) : "ir" (__val), "m" (*__mem));
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

