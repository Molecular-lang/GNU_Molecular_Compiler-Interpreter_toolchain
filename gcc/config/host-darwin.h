/* Darwin host-specific hook definitions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

extern void * darwin_gt_pch_get_address (size_t sz, int fd);
extern int darwin_gt_pch_use_address (void *&addr, size_t sz, int fd, size_t off);

#undef HOST_HOOKS_GT_PCH_GET_ADDRESS
#define HOST_HOOKS_GT_PCH_GET_ADDRESS darwin_gt_pch_get_address
#undef HOST_HOOKS_GT_PCH_USE_ADDRESS
#define HOST_HOOKS_GT_PCH_USE_ADDRESS darwin_gt_pch_use_address
