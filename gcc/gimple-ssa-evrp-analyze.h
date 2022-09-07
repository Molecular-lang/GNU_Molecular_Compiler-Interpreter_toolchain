/* Support routines for Value Range Propagation (VRP).
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLE_SSA_EVRP_ANALYZE_H
#define GCC_GIMPLE_SSA_EVRP_ANALYZE_H

class evrp_range_analyzer : public vr_values
{
 public:
  evrp_range_analyzer (bool update_global_ranges);
  ~evrp_range_analyzer (void)
  {
    stack.release ();
  }

  void enter (basic_block);
  void push_marker (void);
  void pop_to_marker (void);
  void leave (basic_block);
  void record_ranges_from_stmt (gimple *, bool);

  /* Record a new unwindable range.  */
  void push_value_range (tree var, value_range_equiv *vr);

 private:
  DISABLE_COPY_AND_ASSIGN (evrp_range_analyzer);

  void pop_value_range ();
  value_range_equiv *try_find_new_range (tree, tree op, tree_code code,
					 tree limit);
  void record_ranges_from_incoming_edge (basic_block);
  void record_ranges_from_phis (basic_block);
  void set_ssa_range_info (tree, value_range_equiv *);

  /* STACK holds the old VR.  */
  auto_vec<std::pair <tree, value_range_equiv *> > stack;

  /* True if we are updating global ranges, false otherwise.  */
  bool m_update_global_ranges;
};

#endif /* GCC_GIMPLE_SSA_EVRP_ANALYZE_H */
