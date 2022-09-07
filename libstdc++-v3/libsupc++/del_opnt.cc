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

_GLIBCXX_WEAK_DEFINITION void
operator delete (void *ptr, const std::nothrow_t&) noexcept
{
  // _GLIBCXX_RESOLVE_LIB_DEFECTS
  // 206. operator new(size_t, nothrow) may become unlinked to ordinary
  // operator new if ordinary version replaced
  ::operator delete (ptr);
}
