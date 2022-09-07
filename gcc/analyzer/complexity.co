/* Measuring the complexity of svalues/regions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "diagnostic-core.h"
#include "gimple-pretty-print.h"
#include "function.h"
#include "basic-block.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "diagnostic-core.h"
#include "graphviz.h"
#include "options.h"
#include "cgraph.h"
#include "tree-dfa.h"
#include "stringpool.h"
#include "convert.h"
#include "target.h"
#include "fold-const.h"
#include "tree-pretty-print.h"
#include "tristate.h"
#include "bitmap.h"
#include "selftest.h"
#include "function.h"
#include "json.h"
#include "analyzer/analyzer.h"
#include "analyzer/analyzer-logging.h"
#include "options.h"
#include "cgraph.h"
#include "cfg.h"
#include "digraph.h"
#include "analyzer/call-string.h"
#include "analyzer/program-point.h"
#include "analyzer/store.h"
#include "analyzer/complexity.h"
#include "analyzer/svalue.h"
#include "analyzer/region.h"

#if ENABLE_ANALYZER

namespace ana {

/* struct complexity.  */

/* Get complexity for a new node that references REG
   (the complexity of REG, plus one for the new node).  */

complexity::complexity (const region *reg)
: m_num_nodes (reg->get_complexity ().m_num_nodes + 1),
  m_max_depth (reg->get_complexity ().m_max_depth + 1)
{
}

/* Get complexity for a new node that references SVAL.
   (the complexity of SVAL, plus one for the new node).  */

complexity::complexity (const svalue *sval)
: m_num_nodes (sval->get_complexity ().m_num_nodes + 1),
  m_max_depth (sval->get_complexity ().m_max_depth + 1)
{
}

/* Get complexity for a new node that references nodes with complexity
   C1 and C2.  */

complexity
complexity::from_pair (const complexity &c1, const complexity &c2)
{
  return complexity (c1.m_num_nodes + c2.m_num_nodes + 1,
		     MAX (c1.m_max_depth, c2.m_max_depth) + 1);
}

/* Get complexity for a new node that references the svalues in VEC.  */

complexity
complexity::from_vec_svalue (const vec<const svalue *> &vec)
{
  unsigned num_nodes = 0;
  unsigned max_depth = 0;
  for (auto iter_sval : vec)
    {
      const complexity &iter_c = iter_sval->get_complexity ();
      num_nodes += iter_c.m_num_nodes;
      max_depth = MAX (max_depth, iter_c.m_max_depth);
    }
  return complexity (num_nodes + 1, max_depth + 1);
}

} // namespace ana

#endif /* #if ENABLE_ANALYZER */
