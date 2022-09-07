/* Default macros to initialize the lang_hooks data structure.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_HOST_HOOKS_DEF_H
#define GCC_HOST_HOOKS_DEF_H

#include "hooks.h"

#define HOST_HOOKS_EXTRA_SIGNALS hook_void_void
#if HAVE_MMAP_FILE
#define HOST_HOOKS_GT_PCH_GET_ADDRESS mmap_gt_pch_get_address
#define HOST_HOOKS_GT_PCH_USE_ADDRESS mmap_gt_pch_use_address
#else
#define HOST_HOOKS_GT_PCH_GET_ADDRESS default_gt_pch_get_address
#define HOST_HOOKS_GT_PCH_USE_ADDRESS default_gt_pch_use_address
#endif

#define HOST_HOOKS_GT_PCH_ALLOC_GRANULARITY \
  default_gt_pch_alloc_granularity

extern void* default_gt_pch_get_address (size_t, int);
extern int default_gt_pch_use_address (void *&, size_t, int, size_t);
extern size_t default_gt_pch_alloc_granularity (void);
extern void* mmap_gt_pch_get_address (size_t, int);
extern int mmap_gt_pch_use_address (void *&, size_t, int, size_t);

/* The structure is defined in hosthooks.h.  */
#define HOST_HOOKS_INITIALIZER {		\
  HOST_HOOKS_EXTRA_SIGNALS,			\
  HOST_HOOKS_GT_PCH_GET_ADDRESS,		\
  HOST_HOOKS_GT_PCH_USE_ADDRESS,		\
  HOST_HOOKS_GT_PCH_ALLOC_GRANULARITY		\
}

#endif /* GCC_HOST_HOOKS_DEF_H */
