/* Reassociation for trees.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_SSA_REASSOC_H
#define GCC_SSA_REASSOC_H

/* Operator, rank pair.  */
struct operand_entry
{
  unsigned int rank;
  unsigned int id;
  tree op;
  unsigned int count;
  gimple *stmt_to_insert;
};

struct range_entry
{
  tree exp;
  tree low;
  tree high;
  bool in_p;
  bool strict_overflow_p;
  unsigned int idx, next;
};

void dump_range_entry (FILE *file, struct range_entry *r);
void debug_range_entry (struct range_entry *r);
void init_range_entry (struct range_entry *r, tree exp, gimple *stmt);
bool no_side_effect_bb (basic_block bb);

#endif  /* GCC_SSA_REASSOC_H  */
