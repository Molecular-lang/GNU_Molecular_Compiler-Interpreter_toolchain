// Boilerplate support routines for -*- C++ -*- dynamic memory management.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include "new"

_GLIBCXX_WEAK_DEFINITION void
operator delete(void* ptr, std::size_t, std::align_val_t al) noexcept
{
  ::operator delete (ptr, al);
}
