/* Header file for normal form into SSA.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_INTO_SSA_H
#define GCC_TREE_INTO_SSA_H

extern tree get_current_def (tree);
extern void set_current_def (tree, tree);
void delete_update_ssa (void);
tree create_new_def_for (tree, gimple *, def_operand_p);
void mark_virtual_operands_for_renaming (struct function *);
void mark_virtual_operand_for_renaming (tree);
void mark_virtual_phi_result_for_renaming (gphi *);
bool need_ssa_update_p (struct function *);
bool name_registered_for_update_p (tree);
void release_ssa_name_after_update_ssa (tree);
void update_ssa (unsigned);

/* Prototypes for debugging functions.  */
extern void debug_decl_set (bitmap set);
extern void dump_defs_stack (FILE *, int);
extern void debug_defs_stack (int);
extern void dump_currdefs (FILE *);
extern void debug_currdefs (void);
extern void dump_tree_ssa (FILE *);
extern void debug_tree_ssa (void);
extern void dump_tree_ssa_stats (FILE *);
extern void debug_tree_ssa_stats (void);
extern void dump_var_infos (FILE *);
extern void debug_var_infos (void);
extern void dump_names_replaced_by (FILE *, tree);
extern void debug_names_replaced_by (tree);
extern void dump_update_ssa (FILE *);
extern void debug_update_ssa (void);
extern bitmap names_to_release;

#endif /* GCC_TREE_INTO_SSA_H */
