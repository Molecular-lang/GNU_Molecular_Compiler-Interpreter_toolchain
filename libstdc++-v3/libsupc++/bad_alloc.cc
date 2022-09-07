// Implementation file for the -*- C++ -*- dynamic memory management header.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "new"

std::bad_alloc::~bad_alloc() _GLIBCXX_USE_NOEXCEPT { }

const char* 
std::bad_alloc::what() const _GLIBCXX_USE_NOEXCEPT
{
  return "std::bad_alloc";
}
