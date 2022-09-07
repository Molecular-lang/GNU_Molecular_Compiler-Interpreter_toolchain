/* Export function prototypes from dojump.cc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_DOJUMP_H
#define GCC_DOJUMP_H

/* At the start of a function, record that we have no previously-pushed
   arguments waiting to be popped.  */
extern void init_pending_stack_adjust (void);

/* Discard any pending stack adjustment.  */
extern void discard_pending_stack_adjust (void);

/* When exiting from function, if safe, clear out any pending stack adjust
   so the adjustment won't get done.  */
extern void clear_pending_stack_adjust (void);

/* Pop any previously-pushed arguments that have not been popped yet.  */
extern void do_pending_stack_adjust (void);

/* Struct for saving/restoring of pending_stack_adjust/stack_pointer_delta
   values.  */

class saved_pending_stack_adjust
{
public:
  /* Saved value of pending_stack_adjust.  */
  poly_int64 x_pending_stack_adjust;

  /* Saved value of stack_pointer_delta.  */
  poly_int64 x_stack_pointer_delta;
};

/* Remember pending_stack_adjust/stack_pointer_delta.
   To be used around code that may call do_pending_stack_adjust (),
   but the generated code could be discarded e.g. using delete_insns_since.  */

extern void save_pending_stack_adjust (saved_pending_stack_adjust *);

/* Restore the saved pending_stack_adjust/stack_pointer_delta.  */

extern void restore_pending_stack_adjust (saved_pending_stack_adjust *);

extern bool split_comparison (enum rtx_code, machine_mode,
			      enum rtx_code *, enum rtx_code *);

/* Generate code to evaluate EXP and jump to LABEL if the value is nonzero.  */
extern void jumpif (tree exp, rtx_code_label *label, profile_probability prob);
extern void jumpif_1 (enum tree_code, tree, tree, rtx_code_label *,
		      profile_probability);

/* Generate code to evaluate EXP and jump to LABEL if the value is zero.  */
extern void jumpifnot (tree exp, rtx_code_label *label,
		       profile_probability prob);
extern void jumpifnot_1 (enum tree_code, tree, tree, rtx_code_label *,
			 profile_probability);

extern void do_compare_rtx_and_jump (rtx, rtx, enum rtx_code, int,
				     machine_mode, rtx, rtx_code_label *,
				     rtx_code_label *, profile_probability);

#endif /* GCC_DOJUMP_H */
