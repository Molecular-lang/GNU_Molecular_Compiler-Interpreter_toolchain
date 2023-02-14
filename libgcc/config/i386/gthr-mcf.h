/* Threads compatibility routines for libgcc and libobjc.  */

#ifdef _LIBOBJC

/* libobjc references some internal structures and requires a
 * dedicated set of functions.  */
#include <mcfgthread/gthr_libobjc.h>

#else  /* _LIBOBJC  */

/* This is for libgcc and libstdc++.  */
#include <mcfgthread/gthr.h>

#endif  /* _LIBOBJC  */
