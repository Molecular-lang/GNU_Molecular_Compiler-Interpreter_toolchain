/* Please review: $(src-dir)/SPL-README for Licencing info. */

/* ISO C1X: 7.15 Alignment <stdalign.h>.  */

#ifndef _STDALIGN_H
#define _STDALIGN_H

#if (!defined __cplusplus						\
     && !(defined __STDC_VERSION__ && __STDC_VERSION__ > 201710L))

#define alignas _Alignas
#define alignof _Alignof

#define __alignas_is_defined 1
#define __alignof_is_defined 1

#endif

#endif	/* stdalign.h */
