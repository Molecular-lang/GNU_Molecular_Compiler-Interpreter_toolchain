/* Shared pool of memory blocks for pool allocators.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "memory-block.h"
#include "obstack.h"

/* Global singleton-like instance.  */
memory_block_pool memory_block_pool::instance;

memory_block_pool::memory_block_pool () : m_blocks (NULL) {}

/* Reduce free list to NUM blocks and return remaining to malloc.  */
void
memory_block_pool::reduce_free_list (int num)
{
  block_list **blocks = &m_blocks;

  /* First skip NUM blocks.  */

  for (;num > 0 && *blocks; num--)
    blocks = &(*blocks)->m_next;

  if (!*blocks)
    return;

  /* And free the remainder of them.  */

  block_list *to_free = *blocks;
  *blocks = NULL;

  while (to_free)
    {
      block_list *next = to_free->m_next;
      XDELETEVEC (to_free);
      to_free = next;
    }
}

/* Allocate a chunk for obstack.  Use the pool if requested chunk size matches
   the size of blocks in the pool.  */
void *
mempool_obstack_chunk_alloc (size_t size)
{
  if (size == memory_block_pool::block_size)
    return memory_block_pool::allocate ();
  else
    return XNEWVEC (char, size);
}

/* Free previously allocated obstack chunk.  */
void
mempool_obstack_chunk_free (void *chunk)
{
  size_t size = (reinterpret_cast<_obstack_chunk *> (chunk)->limit
		 - reinterpret_cast<char *> (chunk));
  if (size == memory_block_pool::block_size)
    memory_block_pool::release (chunk);
  else
    XDELETEVEC (chunk);
}

/* Return allocated memory back to malloc (and to system).  */
void
memory_block_pool::trim (int num)
{
  instance.reduce_free_list (num);
}
