// Support routines for the -*- C++ -*- dynamic memory management.
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include <bits/exception_defines.h>
#include "new"

extern "C" void *malloc (std::size_t);

_GLIBCXX_WEAK_DEFINITION void *
operator new (std::size_t sz, const std::nothrow_t&) noexcept
{
  // _GLIBCXX_RESOLVE_LIB_DEFECTS
  // 206. operator new(size_t, nothrow) may become unlinked to ordinary
  // operator new if ordinary version replaced
  __try
    {
      return ::operator new(sz);
    }
  __catch (...)
    {
      // N.B. catch (...) means the process will terminate if operator new(sz)
      // exits with a __forced_unwind exception. The process will print
      // "FATAL: exception not rethrown" to stderr before exiting.
      //
      // If we propagated that exception the process would still terminate
      // (because this function is noexcept) but with a less informative error:
      // "terminate called without active exception".
      return nullptr;
    }
}
