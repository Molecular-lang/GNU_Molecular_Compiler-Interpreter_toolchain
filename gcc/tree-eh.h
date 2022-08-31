/* Header file for exception handling.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_EH_H
#define GCC_TREE_EH_H


typedef struct eh_region_d *eh_region;

extern void using_eh_for_cleanups (void);
extern void add_stmt_to_eh_lp (gimple *, int);
extern bool remove_stmt_from_eh_lp_fn (struct function *, gimple *);
extern bool remove_stmt_from_eh_lp (gimple *);
extern int lookup_stmt_eh_lp_fn (struct function *, const gimple *);
extern int lookup_stmt_eh_lp (const gimple *);
extern bool make_eh_dispatch_edges (geh_dispatch *);
extern void make_eh_edges (gimple *);
extern edge redirect_eh_edge (edge, basic_block);
extern void redirect_eh_dispatch_edge (geh_dispatch *, edge, basic_block);
extern bool operation_could_trap_helper_p (enum tree_code, bool, bool, bool, bool, tree, bool *);
extern bool operation_could_trap_p (enum tree_code, bool, bool, tree);
extern bool tree_could_trap_p (tree);
extern tree rewrite_to_non_trapping_overflow (tree);
extern bool stmt_could_throw_p (function *, gimple *);
extern bool stmt_unremovable_because_of_non_call_eh_p (function *, gimple *);
extern bool tree_could_throw_p (tree);
extern bool stmt_can_throw_external (function *, gimple *);
extern bool stmt_can_throw_internal (function *, gimple *);
extern bool maybe_clean_eh_stmt_fn (struct function *, gimple *);
extern bool maybe_clean_eh_stmt (gimple *);
extern bool maybe_clean_or_replace_eh_stmt (gimple *, gimple *);
extern bool maybe_duplicate_eh_stmt_fn (struct function *, gimple *,
					struct function *, gimple *,
					hash_map<void *, void *> *, int);
extern bool maybe_duplicate_eh_stmt (gimple *, gimple *);
extern void maybe_remove_unreachable_handlers (void);
extern void unsplit_eh_edges (void);
extern bool verify_eh_edges (gimple *);
extern bool verify_eh_dispatch_edge (geh_dispatch *);

#endif /* GCC_TREE_EH_H */
