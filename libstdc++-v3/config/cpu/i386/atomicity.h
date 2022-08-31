// Low-level functions for atomic operations: x86, x >= 3 version  -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <ext/atomicity.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template<int __inst>
    struct _Atomicity_lock
    {
      static volatile _Atomic_word _S_atomicity_lock;
    };

  template<int __inst>
  volatile _Atomic_word _Atomicity_lock<__inst>::_S_atomicity_lock = 0;

  template volatile _Atomic_word _Atomicity_lock<0>::_S_atomicity_lock;

  _Atomic_word
  __attribute__ ((__unused__))
  __exchange_and_add(volatile _Atomic_word* __mem, int __val) throw ()
  {
    register _Atomic_word __result, __tmp = 1;

    // Obtain the atomic exchange/add spin lock.
    do
      {
	__asm__ __volatile__ ("xchg{l} {%0,%1|%1,%0}"
			      : "=m" (_Atomicity_lock<0>::_S_atomicity_lock),
			      "+r" (__tmp)
			      : "m" (_Atomicity_lock<0>::_S_atomicity_lock));
      }
    while (__tmp);

    __result = *__mem;
    *__mem += __val;

    // Release spin lock.
    _Atomicity_lock<0>::_S_atomicity_lock = 0;

    return __result;
  }

  void
  __attribute__ ((__unused__))
  __atomic_add(volatile _Atomic_word* __mem, int __val) throw ()
  { __exchange_and_add(__mem, __val); }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
