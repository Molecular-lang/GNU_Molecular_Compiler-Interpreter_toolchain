/* A class to encapsulate decisions about how the analysis should happen.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_ANALYSIS_PLAN_H
#define GCC_ANALYZER_ANALYSIS_PLAN_H

namespace ana {

/* A class to encapsulate decisions about how the analysis should happen.
   Examples:
   - the order in which functions should be analyzed, so that function
     summaries are created before analysis of call sites that might use
     them
   - which callgraph edges should use call summaries
   TODO: the above is a work-in-progress.  */

class analysis_plan : public log_user
{
public:
  analysis_plan (const supergraph &sg, logger *logger);
  ~analysis_plan ();

  int cmp_function (function *fun_a, function *fun_b) const;

  bool use_summary_p (const cgraph_edge *edge) const;

private:
  DISABLE_COPY_AND_ASSIGN (analysis_plan);

  const supergraph &m_sg;

  /* Result of ipa_reverse_postorder.  */
  cgraph_node **m_cgraph_node_postorder;
  int m_num_cgraph_nodes;

  /* Index of each node within the postorder ordering,
     accessed via the "m_uid" field.  */
  auto_vec<int> m_index_by_uid;
};

} // namespace ana

#endif /* GCC_ANALYZER_ANALYSIS_PLAN_H */
