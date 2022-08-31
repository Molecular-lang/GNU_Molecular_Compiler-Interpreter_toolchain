/* Declarations and data structures for stmt.cc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_STMT_H
#define GCC_STMT_H

extern void expand_label (tree);
extern bool parse_output_constraint (const char **, int, int, int, bool *, bool *, bool *);
extern bool parse_input_constraint (const char **, int, int, int, int, const char * const *, bool *, bool *);
extern tree resolve_asm_operand_names (tree, tree, tree, tree);
#ifdef HARD_CONST
/* Silly ifdef to avoid having all includers depend on hard-reg-set.h.  */
extern tree tree_overlaps_hard_reg_set (tree, HARD_REG_SET *);
#endif

/* Return the CODE_LABEL rtx for a LABEL_DECL, creating it if necessary.
   If label was deleted, the corresponding note
   (NOTE_INSN_DELETED{_DEBUG,}_LABEL) insn will be returned.  */
extern rtx_insn *label_rtx (tree);

/* As label_rtx, but additionally the label is placed on the forced label
   list of its containing function (i.e. it is treated as reachable even
   if how is not obvious).  */
extern rtx_insn *force_label_rtx (tree);

/* As label_rtx, but checks that label was not deleted.  */
extern rtx_code_label *jump_target_rtx (tree);

/* Expand a GIMPLE_SWITCH statement.  */
extern void expand_case (gswitch *);

/* Like expand_case but special-case for SJLJ exception dispatching.  */
extern void expand_sjlj_dispatch_table (rtx, vec<tree> );

#endif  // GCC_STMT_H
