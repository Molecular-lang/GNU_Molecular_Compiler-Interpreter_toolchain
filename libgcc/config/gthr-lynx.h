/* Threads compatibility routines for libgcc2 and libobjc for
   LynxOS.  */
/* Compile this one with gcc.  */

#ifndef GCC_GTHR_LYNX_H
#define GCC_GTHR_LYNX_H

#ifdef _MULTITHREADED

/* Using the macro version of pthread_setspecific leads to a
   compilation error.  Instead we have two choices either kill all
   macros in pthread.h with defining _POSIX_THREADS_CALLS or undefine
   individual macros where we should fall back on the function
   implementation.  We choose the second approach.  */

#include <pthread.h>
#undef pthread_setspecific

/* When using static libc on LynxOS, we cannot define pthread_create
   weak.  If the multi-threaded application includes iostream.h,
   gthr-posix.h is included and pthread_create will be defined weak.
   If pthread_create is weak its defining module in libc is not
   necessarily included in the link and the symbol is resolved to zero.
   Therefore the first call to it will crash.

   Since -mthreads is a multilib switch on LynxOS we know that at this
   point we are compiling for multi-threaded.  Omitting the weak
   definitions at this point should have no effect.  */

#undef  GTHREAD_USE_WEAK
#define GTHREAD_USE_WEAK 0

#include "gthr-posix.h"

#else
#include "gthr-single.h"
#endif

#endif /* GCC_GTHR_LYNX_H */
