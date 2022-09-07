// Boilerplate support routines for -*- C++ -*- dynamic memory management.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include <bits/exception_defines.h>
#include "new"

_GLIBCXX_WEAK_DEFINITION void*
operator new(std::size_t sz, std::align_val_t al, const std::nothrow_t&)
  noexcept
{
  __try
    {
      return operator new(sz, al);
    }
  __catch(...)
    {
      return nullptr;
    }
}
