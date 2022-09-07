// Boilerplate support routines for -*- C++ -*- dynamic memory management.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#pragma GCC diagnostic ignored "-Wsized-deallocation"
#include <bits/c++config.h>
#include "new"

_GLIBCXX_WEAK_DEFINITION void
operator delete(void* ptr, std::size_t) noexcept
{
  ::operator delete (ptr);
}
