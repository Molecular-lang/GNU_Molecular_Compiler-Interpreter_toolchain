// Specific definitions for generic platforms  -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_OS_DEFINES
#define _GLIBCXX_OS_DEFINES 1

// System-specific #define, typedefs, corrections, etc, go here.  This
// file will come before all others.

// Disable the weak reference logic in gthr.h for os/generic because it
// is broken on every platform unless there is implementation specific
// workaround in gthr-posix.h and at link-time for static linking.
#define _GLIBCXX_GTHREAD_USE_WEAK 0

#endif
