/* Sorting algorithms.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef SORT_H
#define SORT_H

#include <sys/types.h> /* For size_t */
#ifdef __STDC__
#include <stddef.h>
#endif	/* __STDC__ */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "ansidecl.h"

/* Sort an array of pointers.  */

extern void sort_pointers (size_t, void **, void **);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SORT_H */


   
   
