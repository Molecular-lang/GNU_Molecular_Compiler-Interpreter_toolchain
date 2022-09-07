/* Finding reachable regions and values.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_REGION_MODEL_REACHABILITY_H
#define GCC_ANALYZER_REGION_MODEL_REACHABILITY_H

namespace ana {

/* A class for determining which regions and svalues are reachable.

   Used by region_model::handle_unrecognized_call for keeping
   track of all regions that are reachable, and, of those, which are
   mutable.

   Used by program_state::detect_leaks
   (via region_model::get_reachable_svalues) for detecting leaks.  */

class reachable_regions
{
public:
  reachable_regions (region_model *model);

  /* Callback called for each cluster when initializing this object.  */
  static void init_cluster_cb (const region *base_reg,
			       reachable_regions *this_ptr);

  /* Called for each cluster when initializing this object.  */
  void init_cluster (const region *base_reg);

  /* Lazily mark the cluster containing REG as being reachable, recursively
     adding clusters reachable from REG's cluster.  */
  void add (const region *reg, bool is_mutable);

  static void handle_sval_cb (const svalue *sval,
			      reachable_regions *this_ptr);

  /* Add SVAL.  If it is a pointer, add the pointed-to region.  */
  void handle_sval (const svalue *sval);

  /* Add SVAL.  If it is a pointer, add the pointed-to region.
     Use PARAM_TYPE for determining mutability.  */
  void handle_parm (const svalue *sval, tree param_type);

  /* Update the store to mark the clusters that were found to be mutable
     as having escaped.
     Notify CTXT about escaping function_decls.  */
  void mark_escaped_clusters (region_model_context *ctxt);

  /* Iteration over reachable base regions.  */
  hash_set<const region *>::iterator begin ()
  {
    return m_reachable_base_regs.begin ();
  }
  hash_set<const region *>::iterator end ()
  {
    return m_reachable_base_regs.end ();
  }

  svalue_set::iterator begin_reachable_svals ()
  {
    return m_reachable_svals.begin ();
  }
  svalue_set::iterator end_reachable_svals ()
  {
    return m_reachable_svals.end ();
  }
  svalue_set::iterator begin_mutable_svals ()
  {
    return m_mutable_svals.begin ();
  }
  svalue_set::iterator end_mutable_svals ()
  {
    return m_mutable_svals.end ();
  }
  hash_set<const region *>::iterator begin_mutable_base_regs ()
  {
    return m_mutable_base_regs.begin ();
  }
  hash_set<const region *>::iterator end_mutable_base_regs ()
  {
    return m_mutable_base_regs.end ();
  }

  void dump_to_pp (pretty_printer *pp) const;

  DEBUG_FUNCTION void dump () const;

private:
  region_model *m_model;
  store *m_store;

  /* The base regions already seen.  */
  hash_set<const region *> m_reachable_base_regs;

  /* The base regions that can be changed (accessed via non-const pointers).  */
  hash_set<const region *> m_mutable_base_regs;

  /* svalues that were passed as const pointers, so e.g. couldn't have
     been freed (but could have e.g. had "close" called on them if an
     int file-descriptor).  */
  svalue_set m_reachable_svals;
  /* svalues that were passed as non-const pointers, so e.g. could have
     been freed.  */
  svalue_set m_mutable_svals;
};

} // namespace ana

#endif /* GCC_ANALYZER_REGION_MODEL_REACHABILITY_H */
