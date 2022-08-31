/* Measuring the complexity of svalues/regions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_COMPLEXITY_H
#define GCC_ANALYZER_COMPLEXITY_H

namespace ana {

/* A measurement of the complexity of an svalue or region, so that
   we can impose bounds on the growth of these tree-like structures
   and thus avoid infinite chains of analysis.  */

struct complexity
{
  complexity (unsigned num_nodes, unsigned max_depth)
  : m_num_nodes (num_nodes), m_max_depth (max_depth)
  {}

  complexity (const region *reg);
  complexity (const svalue *sval);
  static complexity from_pair (const complexity &c1, const complexity &c);
  static complexity from_vec_svalue (const vec<const svalue *> &vec);

  /* The total number of svalues and regions in the tree of this
     entity, including the entity itself.  */
  unsigned m_num_nodes;

  /* The maximum depth of the tree of this entity, including the
     entity itself.  */
  unsigned m_max_depth;
};

} // namespace ana

#endif /* GCC_ANALYZER_COMPLEXITY_H */
