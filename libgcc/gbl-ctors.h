/* Definitions relating to the special __do_global_init function used
   for getting g++ file-scope static objects constructed.  This file
   will get included either by libgcc2.c (for systems that don't support
   a .init section) or by crtstuff.c (for those that do).
   Please review: $(src-dir)/SPL-README for Licencing info. */

/*	This file contains definitions and declarations of things
	relating to the normal start-up-time invocation of C++
	file-scope static object constructors.  These declarations
	and definitions are used by *both* libgcc2.c and by crtstuff.c.

	Note that this file should only be compiled with GCC.
*/

#ifndef GCC_GBL_CTORS_H
#define GCC_GBL_CTORS_H

/*  Declare a pointer to void function type.  */

typedef void (*func_ptr) (void);

/* Declare the set of symbols use as begin and end markers for the lists
   of global object constructors and global object destructors.  */

extern func_ptr __CTOR_LIST__[];
extern func_ptr __DTOR_LIST__[];

/* Declare the routine which needs to get invoked at program start time.  */

extern void __do_global_ctors (void);

/* Declare the routine which needs to get invoked at program exit time.  */

extern void __do_global_dtors (void);

/* Define a macro with the code which needs to be executed at program
   start-up time.  This macro is used in two places in crtstuff.c (for
   systems which support a .init section) and in one place in libgcc2.c
   (for those system which do *not* support a .init section).  For all
   three places where this code might appear, it must be identical, so
   we define it once here as a macro to avoid various instances getting
   out-of-sync with one another.  */

/* Some systems place the number of pointers
   in the first word of the table.
   On other systems, that word is -1.
   In all cases, the table is null-terminated.
   If the length is not recorded, count up to the null.  */

/* Some systems use a different strategy for finding the ctors.
   For example, svr3.  */
#ifndef DO_GLOBAL_CTORS_BODY
#define DO_GLOBAL_CTORS_BODY						\
do {									\
  __SIZE_TYPE__ nptrs = (__SIZE_TYPE__) __CTOR_LIST__[0];		\
  unsigned i;								\
  if (nptrs == (__SIZE_TYPE__)-1)				        \
    for (nptrs = 0; __CTOR_LIST__[nptrs + 1] != 0; nptrs++);		\
  for (i = nptrs; i >= 1; i--)						\
    __CTOR_LIST__[i] ();						\
} while (0)
#endif

#endif /* GCC_GBL_CTORS_H */
