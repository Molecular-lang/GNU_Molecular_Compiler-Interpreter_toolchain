/* The host_hooks data structure.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_HOST_HOOKS_H
#define GCC_HOST_HOOKS_H

struct host_hooks
{
  void (*extra_signals) (void);

  /* Identify an address that's likely to be free in a subsequent invocation
     of the compiler.  The area should be able to hold SIZE bytes.  FD is an
     open file descriptor if the host would like to probe with mmap.  */
  void * (*gt_pch_get_address) (size_t size, int fd);

  /* ADDR is an address returned by gt_pch_get_address.  Attempt to allocate
     SIZE bytes at the same address (preferrably) or some other address
     and load it with the data from FD at OFFSET.  Return -1 if we couldn't
     allocate memory, otherwise update ADDR to the actual address where it got
     allocated, return 0 if the memory is allocated but the data not loaded,
     return 1 if done.  */
  int (*gt_pch_use_address) (void *&addr, size_t size, int fd, size_t offset);

  /*  Return the alignment required for allocating virtual memory. Usually
      this is the same as pagesize.  */
  size_t (*gt_pch_alloc_granularity) (void);

  /* Whenever you add entries here, make sure you adjust hosthooks-def.h.  */
};

/* Each host provides its own.  */
extern const struct host_hooks host_hooks;

#endif /* GCC_LANG_HOOKS_H */
