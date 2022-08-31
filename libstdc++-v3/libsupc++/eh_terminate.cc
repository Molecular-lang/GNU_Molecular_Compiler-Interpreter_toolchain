// -*- C++ -*- std::terminate, std::unexpected and friends.
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "typeinfo"
#include "exception"
#include <cstdlib>
#include "unwind-cxx.h"
#include "eh_term_handler.h"
#include <bits/exception_defines.h>
#include <bits/atomic_lockfree_defines.h>

#if ATOMIC_POINTER_LOCK_FREE < 2
#include <ext/concurrence.h>
namespace
{
  __gnu_cxx::__mutex mx;
}
#endif

using namespace __cxxabiv1;

void
__cxxabiv1::__terminate (std::terminate_handler handler) throw ()
{
  __try 
    {
      handler ();
      std::abort ();
    } 
  __catch(...) 
    { std::abort (); }
}

void
std::terminate () throw()
{
  __cxxabiv1::__terminate (get_terminate ());
}

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
void
__cxxabiv1::__unexpected (std::unexpected_handler handler)
{
  handler();
  std::terminate ();
}

void
std::unexpected ()
{
  __unexpected (get_unexpected ());
}

std::terminate_handler
std::set_terminate (std::terminate_handler func) throw()
{
  if (!func)
    func = _GLIBCXX_DEFAULT_TERM_HANDLER;

  std::terminate_handler old;
#if ATOMIC_POINTER_LOCK_FREE > 1
  __atomic_exchange (&__terminate_handler, &func, &old, __ATOMIC_ACQ_REL);
#else
  __gnu_cxx::__scoped_lock l(mx);
  old = __terminate_handler;
  __terminate_handler = func;
#endif
  return old;
}

std::terminate_handler
std::get_terminate () noexcept
{
  std::terminate_handler func;
#if ATOMIC_POINTER_LOCK_FREE > 1
  __atomic_load (&__terminate_handler, &func, __ATOMIC_ACQUIRE);
#else
  __gnu_cxx::__scoped_lock l(mx);
  func = __terminate_handler;
#endif
  return func;
}

std::unexpected_handler
std::set_unexpected (std::unexpected_handler func) throw()
{
  if (!func)
    func = std::terminate;

  std::unexpected_handler old;
#if ATOMIC_POINTER_LOCK_FREE > 1
  __atomic_exchange (&__unexpected_handler, &func, &old, __ATOMIC_ACQ_REL);
#else
  __gnu_cxx::__scoped_lock l(mx);
  old = __unexpected_handler;
  __unexpected_handler = func;
#endif
  return old;
}

std::unexpected_handler
std::get_unexpected () noexcept
{
  std::unexpected_handler func;
#if ATOMIC_POINTER_LOCK_FREE > 1
  __atomic_load (&__unexpected_handler, &func, __ATOMIC_ACQUIRE);
#else
  __gnu_cxx::__scoped_lock l(mx);
  func = __unexpected_handler;
#endif
  return func;
}
