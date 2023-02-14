/* Default definitions for progress macros. */

/* The default definitions below are intended to be replaced by real
   definitions, if building the tools for an interactive programming
   environment.  */

#ifndef _PROGRESS_H
#define _PROGRESS_H

#ifndef START_PROGRESS
#define START_PROGRESS(STR,N)
#endif

#ifndef PROGRESS
#define PROGRESS(X)
#endif

#ifndef END_PROGRESS
#define END_PROGRESS(STR)
#endif

#endif /* _PROGRESS_H */
