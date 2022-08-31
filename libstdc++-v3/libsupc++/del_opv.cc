// Boilerplate support routines for -*- C++ -*- dynamic memory management.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include "new"

// The sized deletes are defined in other files.
#pragma GCC diagnostic ignored "-Wsized-deallocation"

_GLIBCXX_WEAK_DEFINITION void
operator delete[] (void *ptr) _GLIBCXX_USE_NOEXCEPT
{
  ::operator delete (ptr);
}
