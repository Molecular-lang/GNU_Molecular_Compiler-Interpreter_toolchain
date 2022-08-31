/* Digraph reachability.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_REACHABILITY_H
#define GCC_ANALYZER_REACHABILITY_H

namespace ana {

/* The set of nodes from which a target node in a digraph can be reached.  */
// TODO(stage1): move to gcc

template <typename GraphTraits>
class reachability
{
public:
  typedef typename GraphTraits::graph_t graph_t;
  typedef typename GraphTraits::node_t node_t;
  typedef typename GraphTraits::edge_t edge_t;

  reachability (const graph_t &graph,
		const node_t *target_node)
  : m_indices (graph.m_nodes.length ())
  {
    bitmap_clear (m_indices);
    auto_vec<const node_t *> worklist;
    worklist.safe_push (target_node);
    bitmap_set_bit (m_indices, target_node->m_index);

    while (worklist.length () > 0)
      {
	const node_t *next = worklist.pop ();
	unsigned i;
	edge_t *pred;
	FOR_EACH_VEC_ELT (next->m_preds, i, pred)
	  {
	    if (!reachable_from_p (pred->m_src))
	      {
		worklist.safe_push (pred->m_src);
		bitmap_set_bit (m_indices, pred->m_src->m_index);
	      }
	  }
      }
  }

  bool reachable_from_p (const node_t *src_node) const
  {
    return bitmap_bit_p (m_indices, src_node->m_index);
  }

private:
  /* The nodes that can reach the target.  */
  auto_sbitmap m_indices;
};

//TODO: selftests for reachability

} // namespace ana

#endif /* GCC_ANALYZER_REACHABILITY_H */
