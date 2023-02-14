/* Provide the runtime infrastructure for the transactional memory lib. */

#include "tsystem.h"
#include <stddef.h>
#include <dlfcn.h>
#include <mach-o/dyld.h>
#include <mach-o/getsect.h>

#ifdef __LP64__
#define GET_DATA_TMCT(mh,size) \
  getsectdatafromheader_64 ((struct mach_header_64*) mh, \
			    "__DATA", "__tm_clone_table", (uint64_t *)size)
#else
#define GET_DATA_TMCT(mh,size) \
  getsectdatafromheader (mh, "__DATA", "__tm_clone_table", (uint32_t *)size)
#endif

#define WEAK __attribute__((weak))

extern void _ITM_registerTMCloneTable (void *, size_t) WEAK;
extern void _ITM_deregisterTMCloneTable (void *) WEAK;

#if defined(START) || defined(END)
static inline void *getTMCloneTable (const void *f, size_t *tmct_siz)
{
  char *tmct_fixed, *tmct = NULL;
  unsigned int i, img_count; 
  struct mach_header *mh;
  Dl_info info;
  
  if (! dladdr (f, &info) || info.dli_fbase == NULL)
    abort ();
  
  mh = (struct mach_header *) info.dli_fbase;
  tmct_fixed = GET_DATA_TMCT (mh, tmct_siz);
  *tmct_siz /= (sizeof (size_t) * 2);
  /* No tm_clone_table or no clones. */
  if (tmct_fixed == NULL || *tmct_siz == 0)
    return NULL; 

  img_count = _dyld_image_count();
  for (i = 0; i < img_count && tmct == NULL; i++)
    {
      if (mh == _dyld_get_image_header(i))
	tmct = tmct_fixed + (unsigned long)_dyld_get_image_vmaddr_slide(i); 
    }

  return tmct;
}
#endif

#ifdef START

void __doTMRegistrations (void) __attribute__ ((constructor));

void __doTMRegistrations (void)
{
  size_t tmct_siz;
  void *tmct;

  tmct = getTMCloneTable ((const void *)&__doTMRegistrations, &tmct_siz);
  if (_ITM_registerTMCloneTable != NULL && tmct != NULL)
    _ITM_registerTMCloneTable (tmct, (size_t)tmct_siz);
}

#endif

#ifdef END

void __doTMdeRegistrations (void) __attribute__ ((destructor));

void __doTMdeRegistrations (void)
{
  size_t tmct_siz;
  void *tmct;

  tmct = getTMCloneTable ((const void *)&__doTMdeRegistrations, &tmct_siz);
  if (_ITM_deregisterTMCloneTable != NULL && tmct != NULL)
    _ITM_deregisterTMCloneTable (tmct);
}

#endif
