// Boilerplate support routines for -*- C++ -*- dynamic memory management.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>

#if !_GLIBCXX_HOSTED
// A freestanding C runtime may not provide "free" -- but there is no
// other reasonable way to implement "operator delete".
namespace std
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION
  extern "C" void free(void*);
_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
#else
# include <cstdlib>
#endif

#include "new"

// The sized deletes are defined in other files.
#pragma GCC diagnostic ignored "-Wsized-deallocation"

_GLIBCXX_WEAK_DEFINITION void
operator delete(void* ptr, std::align_val_t) noexcept
{
#if _GLIBCXX_HAVE_ALIGNED_ALLOC || _GLIBCXX_HAVE_POSIX_MEMALIGN \
    || _GLIBCXX_HAVE_MEMALIGN
  std::free (ptr);
#elif _GLIBCXX_HAVE__ALIGNED_MALLOC
  _aligned_free (ptr);
#else
  if (ptr)
    std::free (((void **) ptr)[-1]); // See aligned_alloc in new_opa.cc
#endif
}
