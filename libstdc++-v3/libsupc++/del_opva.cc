// Boilerplate support routines for -*- C++ -*- dynamic memory management.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include "new"

// The sized deletes are defined in other files.
#pragma GCC diagnostic ignored "-Wsized-deallocation"

_GLIBCXX_WEAK_DEFINITION void
operator delete[] (void *ptr, std::align_val_t al) noexcept
{
  ::operator delete (ptr, al);
}
