/* Header file the type CGEN_BITSET.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef CGEN_BITSET_H
#define CGEN_BITSET_H

#ifdef __cplusplus
extern "C" {
#endif

/* A bitmask represented as a string.
   Each member of the set is represented as a bit
   in the string. Bytes are indexed from left to right in the string and
   bits from most significant to least within each byte.

   For example, the bit representing member number 6 is (set->bits[0] & 0x02).
*/
typedef struct cgen_bitset
{
  unsigned length;
  char *bits;
} CGEN_BITSET;

extern CGEN_BITSET *cgen_bitset_create (unsigned);
extern void cgen_bitset_init (CGEN_BITSET *, unsigned);
extern void cgen_bitset_clear (CGEN_BITSET *);
extern void cgen_bitset_add (CGEN_BITSET *, unsigned);
extern void cgen_bitset_set (CGEN_BITSET *, unsigned);
extern int cgen_bitset_compare (CGEN_BITSET *, CGEN_BITSET *);
extern void cgen_bitset_union (CGEN_BITSET *, CGEN_BITSET *, CGEN_BITSET *);
extern int cgen_bitset_intersect_p (CGEN_BITSET *, CGEN_BITSET *);
extern int cgen_bitset_contains (CGEN_BITSET *, unsigned);
extern CGEN_BITSET *cgen_bitset_copy (CGEN_BITSET *);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
