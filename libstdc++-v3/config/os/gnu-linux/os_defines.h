// Specific definitions for GNU/Linux  -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_OS_DEFINES
#define _GLIBCXX_OS_DEFINES 1

// System-specific #define, typedefs, corrections, etc, go here.  This
// file will come before all others.

// This keeps isalnum, et al from being propagated as macros.
#define __NO_CTYPE 1

#include <features.h>

// Provide a declaration for the possibly deprecated gets function, as
// glibc 2.15 and later does not declare gets for ISO C11 when
// __GNU_SOURCE is defined.
#if __GLIBC_PREREQ(2,15) && defined(_GNU_SOURCE)
# undef _GLIBCXX_HAVE_GETS
#endif

// Glibc 2.23 removed the obsolete isinf and isnan declarations. Check the
// version dynamically in case it has changed since libstdc++ was configured.
#define _GLIBCXX_NO_OBSOLETE_ISINF_ISNAN_DYNAMIC __GLIBC_PREREQ(2,23)

#if __GLIBC_PREREQ(2, 27)
// Since glibc 2.27 pthread_self() is usable without linking to libpthread.
# define _GLIBCXX_NATIVE_THREAD_ID pthread_self()
#else
// Before then it was in libc.so.6 but not libc.a, and always returns 0,
// which breaks the invariant this_thread::get_id() != thread::id{}.
// So only use it if we know the libpthread version is available.
// Otherwise use (__gthread_t)1 as the ID of the main (and only) thread.
# define _GLIBCXX_NATIVE_THREAD_ID \
  (__gthread_active_p() ? __gthread_self() : (__gthread_t)1)
#endif

#if __GLIBC_PREREQ(2, 34)
// Since glibc 2.34 all pthreads functions are usable without linking to
// libpthread.
# define _GLIBCXX_GTHREAD_USE_WEAK 0
#endif

#endif
