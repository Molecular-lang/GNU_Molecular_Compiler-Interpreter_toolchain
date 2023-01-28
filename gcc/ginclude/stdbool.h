/* Please review: $(src-dir)/SPL-README for Licencing info. */

/*
 * ISO C Standard:  7.16  Boolean type and values  <stdbool.h>
 */

#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifndef __cplusplus

#if defined __STDC_VERSION__ && __STDC_VERSION__ > 201710L
/* bool, true and false are keywords.  */
#else
#define bool	_Bool
#define true	1
#define false	0
#endif

#else /* __cplusplus */

/* Supporting _Bool in C++ is a GCC extension.  */
#define _Bool	bool

#endif /* __cplusplus */

/* Signal that all the definitions are present.  */
#define __bool_true_false_are_defined	1

#endif	/* stdbool.h */
