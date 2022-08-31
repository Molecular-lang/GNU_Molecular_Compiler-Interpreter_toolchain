// Low-level functions for atomic operations: version for CPUs providing
// atomic builtins -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <bits/c++config.h>
#include <bits/atomic_word.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  _Atomic_word
  __attribute__ ((__unused__))
  __exchange_and_add(volatile _Atomic_word* __mem, int __val) throw ()
  { return __atomic_fetch_add(__mem, __val, __ATOMIC_ACQ_REL); }

  void
  __attribute__ ((__unused__))
  __atomic_add(volatile _Atomic_word* __mem, int __val) throw ()
  { __atomic_fetch_add(__mem, __val, __ATOMIC_ACQ_REL); }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
