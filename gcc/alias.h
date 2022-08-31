/* Exported functions from alias.cc
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ALIAS_H
#define GCC_ALIAS_H

extern alias_set_type new_alias_set (void);
extern alias_set_type get_alias_set (tree);
extern alias_set_type get_deref_alias_set (tree);
extern alias_set_type get_varargs_alias_set (void);
extern alias_set_type get_frame_alias_set (void);
extern tree component_uses_parent_alias_set_from (const_tree);
extern bool ends_tbaa_access_path_p (const_tree);
extern bool alias_set_subset_of (alias_set_type, alias_set_type);
extern void record_alias_subset (alias_set_type, alias_set_type);
extern void record_component_aliases (tree);
extern int alias_sets_conflict_p (alias_set_type, alias_set_type);
extern int alias_sets_must_conflict_p (alias_set_type, alias_set_type);
extern int objects_must_conflict_p (tree, tree);
extern int nonoverlapping_memrefs_p (const_rtx, const_rtx, bool);
extern void dump_alias_stats_in_alias_c (FILE *s);
tree reference_alias_ptr_type (tree);
tree reference_alias_ptr_type_1 (tree *);
bool alias_ptr_types_compatible_p (tree, tree);
int compare_base_decls (tree, tree);
bool refs_same_for_tbaa_p (tree, tree);

/* This alias set can be used to force a memory to conflict with all
   other memories, creating a barrier across which no memory reference
   can move.  Note that there are other legacy ways to create such
   memory barriers, including an address of SCRATCH.  */
#define ALIAS_SET_MEMORY_BARRIER	((alias_set_type) -1)

#endif /* GCC_ALIAS_H */
