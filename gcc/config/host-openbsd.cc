/* OpenBSD host-specific hook definitions. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "hosthooks.h"
#include "hosthooks-def.h"


#undef HOST_HOOKS_GT_PCH_GET_ADDRESS
#define HOST_HOOKS_GT_PCH_GET_ADDRESS openbsd_gt_pch_get_address
#undef HOST_HOOKS_GT_PCH_USE_ADDRESS
#define HOST_HOOKS_GT_PCH_USE_ADDRESS openbsd_gt_pch_use_address

/* For various ports, try to guess a fixed spot in the vm space
   that's probably free.  */
#if defined(__amd64__)
# define TRY_EMPTY_VM_SPACE	0x400000000000
#elif defined(__hppa__)
# define TRY_EMPTY_VM_SPACE	0xb0000000
#elif defined(__i386__)
# define TRY_EMPTY_VM_SPACE	0xb0000000
#else
# define TRY_EMPTY_VM_SPACE	0
#endif

/* Determine a location where we might be able to reliably allocate
   SIZE bytes.  FD is the PCH file, though we should return with the
   file unmapped.  */

static void *
openbsd_gt_pch_get_address (size_t size, int fd)
{
  void *addr;

  addr = mmap ((void *) TRY_EMPTY_VM_SPACE, size, PROT_READ | PROT_WRITE,
	       MAP_PRIVATE, fd, 0);

  /* If we failed the map, that means there's *no* free space.  */
  if (addr == (void *) MAP_FAILED)
    return NULL;
  /* Unmap the area before returning.  */
  munmap (addr, size);

  return addr;
}

/* Map SIZE bytes of FD+OFFSET at BASE.  Return 1 if we succeeded at 
   mapping the data at BASE, -1 if we couldn't.  */

static int
openbsd_gt_pch_use_address (void *&base, size_t size, int fd, size_t offset)
{
  void *addr;

  /* We're called with size == 0 if we're not planning to load a PCH
     file at all.  This allows the hook to free any static space that
     we might have allocated at link time.  */
  if (size == 0)
    return -1;

  addr = mmap (base, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, offset);

  return addr == base ? 1 : -1;
}


const struct host_hooks host_hooks = HOST_HOOKS_INITIALIZER;
