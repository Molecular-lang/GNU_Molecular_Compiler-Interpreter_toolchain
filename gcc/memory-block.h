/* Shared pool of memory blocks for pool allocators.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef MEMORY_BLOCK_H
#define MEMORY_BLOCK_H

/* Shared pool which allows other memory pools to reuse each others' allocated
   memory blocks instead of calling free/malloc again.  */
class memory_block_pool
{
public:
  /* Blocks have fixed size.  This is necessary for sharing.  */
  static const size_t block_size = 64 * 1024;
  /* Number of blocks we keep in the freelists.  */
  static const size_t freelist_size = 1024 * 1024 / block_size;

  memory_block_pool ();

  static inline void *allocate () ATTRIBUTE_MALLOC;
  static inline void release (void *);
  static void trim (int nblocks = freelist_size);
  void reduce_free_list (int);

private:
  /* memory_block_pool singleton instance, defined in memory-block.cc.  */
  static memory_block_pool instance;

  struct block_list
  {
    block_list *m_next;
  };

  /* Free list.  */
  block_list *m_blocks;
};

/* Allocate a single block.  Reuse a previously returned block, if possible.  */
inline void *
memory_block_pool::allocate ()
{
  if (instance.m_blocks == NULL)
    return XNEWVEC (char, block_size);

  void *result = instance.m_blocks;
  instance.m_blocks = instance.m_blocks->m_next;
  VALGRIND_DISCARD (VALGRIND_MAKE_MEM_UNDEFINED (result, block_size));
  return result;
}

/* Return UNCAST_BLOCK to the pool.  */
inline void
memory_block_pool::release (void *uncast_block)
{
  block_list *block = new (uncast_block) block_list;
  block->m_next = instance.m_blocks;
  instance.m_blocks = block;

  VALGRIND_DISCARD (VALGRIND_MAKE_MEM_NOACCESS ((char *)uncast_block
						+ sizeof (block_list),
						block_size
						- sizeof (block_list)));
}

extern void *mempool_obstack_chunk_alloc (size_t) ATTRIBUTE_MALLOC;
extern void mempool_obstack_chunk_free (void *);

#endif /* MEMORY_BLOCK_H */
