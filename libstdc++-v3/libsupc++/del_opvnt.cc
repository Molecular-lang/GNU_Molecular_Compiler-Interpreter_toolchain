// Boilerplate support routines for -*- C++ -*- dynamic memory management.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include "new"

_GLIBCXX_WEAK_DEFINITION void
operator delete[] (void *ptr, const std::nothrow_t&) noexcept
{
  ::operator delete[] (ptr);
}
