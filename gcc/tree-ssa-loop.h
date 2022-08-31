/* Header file for SSA loop optimizations.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_LOOP_H
#define GCC_TREE_SSA_LOOP_H


/* Affine iv.  */

struct affine_iv
{
  /* Iv = BASE + STEP * i.  */
  tree base, step;

  /* True if this iv does not overflow.  */
  bool no_overflow;
};

/* Description of number of iterations of a loop.  All the expressions inside
   the structure can be evaluated at the end of the loop's preheader
   (and due to ssa form, also anywhere inside the body of the loop).  */

class tree_niter_desc
{
public:
  tree assumptions;	/* The boolean expression.  If this expression evaluates
			   to false, then the other fields in this structure
			   should not be used; there is no guarantee that they
			   will be correct.  */
  tree may_be_zero;	/* The boolean expression.  If it evaluates to true,
			   the loop will exit in the first iteration (i.e.
			   its latch will not be executed), even if the niter
			   field says otherwise.  */
  tree niter;		/* The expression giving the number of iterations of
			   a loop (provided that assumptions == true and
			   may_be_zero == false), more precisely the number
			   of executions of the latch of the loop.  */
  widest_int max;	/* The upper bound on the number of iterations of
			   the loop.  */

  /* The simplified shape of the exit condition.  The loop exits if
     CONTROL CMP BOUND is false, where CMP is one of NE_EXPR,
     LT_EXPR, or GT_EXPR, and step of CONTROL is positive if CMP is
     LE_EXPR and negative if CMP is GE_EXPR.  This information is used
     by loop unrolling.  */
  affine_iv control;
  tree bound;
  enum tree_code cmp;
};

extern bool for_each_index (tree *, bool (*) (tree, tree *, void *), void *);
extern char *get_lsm_tmp_name (tree ref, unsigned n, const char *suffix = NULL);
extern unsigned tree_num_loop_insns (class loop *, struct eni_weights *);

/* Returns the loop of the statement STMT.  */

static inline class loop *
loop_containing_stmt (gimple *stmt)
{
  basic_block bb = gimple_bb (stmt);
  if (!bb)
    return NULL;

  return bb->loop_father;
}

#endif /* GCC_TREE_SSA_LOOP_H */
