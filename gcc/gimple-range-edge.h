/* Gimple range edge header file.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GIMPLE_RANGE_EDGE_H
#define GIMPLE_RANGE_EDGE_H

// This class is used to query ranges on constant edges in GIMPLE.
//
// For a COND_EXPR, the TRUE edge will return [1,1] and the false edge a [0,0].
//
// For SWITCH_EXPR, it is awkward to calculate ranges.  When a request
// is made, the entire switch is evalauted and the results cached. 
// Any future requests to that switch will use the cached value, providing
// dramatic decrease in computation time.
//
// The API is simple, just ask for the range on the edge.
// The return value is NULL for no range, or the branch statement which the
// edge gets the range from, along with the range.

class gimple_outgoing_range
{
public:
  gimple_outgoing_range (int max_sw_edges = INT_MAX);
  ~gimple_outgoing_range ();
  gimple *edge_range_p (irange &r, edge e);
private:
  void calc_switch_ranges (gswitch *sw);
  bool switch_edge_range (irange &r, gswitch *sw, edge e);

  int m_max_edges;
  hash_map<edge, irange *> *m_edge_table;
  vrange_allocator m_range_allocator;
};

// If there is a range control statement at the end of block BB, return it.
gimple *gimple_outgoing_range_stmt_p (basic_block bb);
// Return the range on edge E if it is from a GCOND.  Either TRUE or FALSE.
void gcond_edge_range (irange &r, edge e);

#endif  // GIMPLE_RANGE_EDGE_H
