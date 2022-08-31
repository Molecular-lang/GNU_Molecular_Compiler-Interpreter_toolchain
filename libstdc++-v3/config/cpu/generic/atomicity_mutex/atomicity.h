// Low-level functions for atomic operations: Generic version  -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <ext/atomicity.h>
#include <ext/concurrence.h>

namespace
{
  __gnu_cxx::__mutex&
  get_atomic_mutex()
  {
    static __gnu_cxx::__mutex atomic_mutex;
    return atomic_mutex;
  }
} // anonymous namespace

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  _Atomic_word
  __attribute__ ((__unused__))
  __exchange_and_add(volatile _Atomic_word* __mem, int __val) throw ()
  {
    __gnu_cxx::__scoped_lock sentry(get_atomic_mutex());
    _Atomic_word __result;
    __result = *__mem;
    *__mem += __val;
    return __result;
  }

  void
  __attribute__ ((__unused__))
  __atomic_add(volatile _Atomic_word* __mem, int __val) throw ()
  { __exchange_and_add(__mem, __val); }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
