/* Header file for the context-aware pointer equivalence tracker.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_VALUE_POINTER_EQUIV_H
#define GCC_VALUE_POINTER_EQUIV_H

// Simple context-aware pointer equivalency analyzer that returns what
// a pointer SSA name is equivalent to at a given point during a walk
// of the IL.
//
// Note that global equivalency take priority over conditional
// equivalency.  That is, p = &q takes priority over a later p == &t.
//
// This class is meant to be called during a DOM walk.

class pointer_equiv_analyzer
{
public:
  pointer_equiv_analyzer (gimple_ranger *r);
  ~pointer_equiv_analyzer ();
  void enter (basic_block);
  void leave (basic_block);
  void visit_stmt (gimple *stmt);
  tree get_equiv (tree ssa);

private:
  void visit_edge (edge e);
  tree get_equiv_expr (tree_code code, tree expr);
  void set_global_equiv (tree ssa, tree pointee);
  void set_cond_equiv (tree ssa, tree pointee);

  gimple_ranger *m_ranger;
  // Global pointer equivalency indexed by SSA_NAME_VERSION.
  auto_vec<tree> m_global_points;
  // Conditional pointer equivalency.
  class ssa_equiv_stack *m_cond_points;
};

inline bool
supported_pointer_equiv_p (tree expr)
{
  return TREE_CODE (expr) == SSA_NAME && POINTER_TYPE_P (TREE_TYPE (expr));
}

#endif // GCC_VALUE_POINTER_EQUIV_H
