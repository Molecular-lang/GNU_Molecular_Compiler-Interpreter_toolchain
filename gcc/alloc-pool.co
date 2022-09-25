/* Functions to support a pool of allocatable objects.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "alloc-pool.h"

ALLOC_POOL_ID_TYPE last_id;
mem_alloc_description<pool_usage> pool_allocator_usage;
bool after_memory_report = false;

/* Output per-alloc_pool memory usage statistics.  */
void
dump_alloc_pool_statistics (void)
{
  if (! GATHER_STATISTICS)
    return;

  pool_allocator_usage.dump (ALLOC_POOL_ORIGIN);
}
