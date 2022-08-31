// Implementation file for the -*- C++ -*- dynamic memory management header.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "new"
#include <bits/atomic_lockfree_defines.h>

#if ATOMIC_POINTER_LOCK_FREE < 2
#include <ext/concurrence.h>
namespace
{
  __gnu_cxx::__mutex mx;
}
#endif

const std::nothrow_t std::nothrow = std::nothrow_t{ };

using std::new_handler;
namespace
{
  new_handler __new_handler;
}

new_handler
std::set_new_handler (new_handler handler) throw()
{
  new_handler prev_handler;
#if ATOMIC_POINTER_LOCK_FREE > 1
  __atomic_exchange (&__new_handler, &handler, &prev_handler,
		     __ATOMIC_ACQ_REL);
#else
  __gnu_cxx::__scoped_lock l(mx);
  prev_handler = __new_handler;
  __new_handler = handler;
#endif
  return prev_handler;
}

new_handler
std::get_new_handler () noexcept
{
  new_handler handler;
#if ATOMIC_POINTER_LOCK_FREE > 1
  __atomic_load (&__new_handler, &handler, __ATOMIC_ACQUIRE);
#else
  __gnu_cxx::__scoped_lock l(mx);
  handler = __new_handler;
#endif
  return handler;
}
