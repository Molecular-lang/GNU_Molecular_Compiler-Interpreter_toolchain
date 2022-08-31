/* Header file for any pass which requires SSA routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_H
#define GCC_TREE_SSA_H

/* Mapping for redirected edges.  */
struct edge_var_map {
  tree result;			/* PHI result.  */
  tree def;			/* PHI arg definition.  */
  location_t locus;        /* PHI arg location.  */
};

/* A vector of var maps.  */
typedef vec<edge_var_map, va_heap, vl_embed> edge_var_map_vector;


extern void redirect_edge_var_map_add (edge, tree, tree, location_t);
extern void redirect_edge_var_map_clear (edge);
extern void redirect_edge_var_map_dup (edge, edge);
extern vec<edge_var_map> *redirect_edge_var_map_vector (edge);
extern void redirect_edge_var_map_empty (void);
extern edge ssa_redirect_edge (edge, basic_block);
extern void flush_pending_stmts (edge);
extern void gimple_replace_ssa_lhs (gimple *, tree);
extern tree target_for_debug_bind (tree);
extern void insert_debug_temp_for_var_def (gimple_stmt_iterator *, tree);
extern void insert_debug_temps_for_defs (gimple_stmt_iterator *);
extern void reset_debug_uses (gimple *);
extern void release_defs_bitset (bitmap toremove);
extern void verify_ssa (bool, bool);
extern void init_tree_ssa (function *, int size = 0);
extern void delete_tree_ssa (function *);
extern bool tree_ssa_useless_type_conversion (tree);
extern tree tree_ssa_strip_useless_type_conversions (tree);
extern tree find_released_ssa_name (tree *, int *, void *);


extern bool ssa_defined_default_def_p (tree t);
extern bool ssa_undefined_value_p (tree, bool = true);
extern bool gimple_uses_undefined_value_p (gimple *);
extern void execute_update_addresses_taken (void);

/* Given an edge_var_map V, return the PHI arg definition.  */

static inline tree
redirect_edge_var_map_def (edge_var_map *v)
{
  return v->def;
}

/* Given an edge_var_map V, return the PHI result.  */

static inline tree
redirect_edge_var_map_result (edge_var_map *v)
{
  return v->result;
}

/* Given an edge_var_map V, return the PHI arg location.  */

static inline location_t
redirect_edge_var_map_location (edge_var_map *v)
{
  return v->locus;
}

/* Verify SSA invariants, if internal consistency checks are enabled.  */

static inline void
checking_verify_ssa (bool check_modified_stmt, bool check_ssa_operands)
{
  if (flag_checking)
    verify_ssa (check_modified_stmt, check_ssa_operands);
}

#endif /* GCC_TREE_SSA_H */
