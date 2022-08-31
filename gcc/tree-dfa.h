/* Header file for tree data flow functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_DFA_H
#define GCC_TREE_DFA_H

extern void renumber_gimple_stmt_uids (struct function *);
extern void renumber_gimple_stmt_uids_in_blocks (basic_block *, int);
extern void dump_variable (FILE *, tree);
extern void debug_variable (tree);
extern void dump_dfa_stats (FILE *);
extern void debug_dfa_stats (void);
extern tree ssa_default_def (struct function *, tree);
extern void set_ssa_default_def (struct function *, tree, tree);
extern tree get_or_create_ssa_default_def (struct function *, tree);
extern tree get_ref_base_and_extent (tree, poly_int64_pod *, poly_int64_pod *, poly_int64_pod *, bool *);
extern tree get_ref_base_and_extent_hwi (tree, HOST_WIDE_INT *, HOST_WIDE_INT *, bool *);
extern tree get_addr_base_and_unit_offset_1 (tree, poly_int64_pod *, tree (*) (tree));
extern tree get_addr_base_and_unit_offset (tree, poly_int64_pod *);
extern bool stmt_references_abnormal_ssa_name (gimple *);
extern void replace_abnormal_ssa_names (gimple *);
extern void dump_enumerated_decls (FILE *, dump_flags_t);


#endif /* GCC_TREE_DFA_H */
