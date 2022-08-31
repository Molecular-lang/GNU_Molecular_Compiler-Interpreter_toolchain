/* hash.c -- gas hash table code
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "as.h"

/* Insert ELEMENT into HTAB.  If REPLACE is non-zero existing elements
   are overwritten.  If ELEMENT already exists, a pointer to the slot
   is returned.  Otherwise NULL is returned.  */

void **
htab_insert (htab_t htab, void *element, int replace)
{
  void **slot = htab_find_slot (htab, element, INSERT);
  if (*slot != NULL)
    {
      if (replace)
	{
	  if (htab->del_f)
	    (*htab->del_f) (*slot);
	  *slot = element;
	}
      return slot;
    }
  *slot = element;
  return NULL;
}

/* Print statistics about a hash table.  */

void
htab_print_statistics (FILE *f, const char *name, htab_t table)
{
  fprintf (f, "%s hash statistics:\n", name);
  fprintf (f, "\t%u searches\n", table->searches);
  fprintf (f, "\t%u collisions\n", table->collisions);
  fprintf (f, "\t%lu elements\n", (unsigned long) htab_elements (table));
  fprintf (f, "\t%lu table size\n", (unsigned long) htab_size (table));
}
