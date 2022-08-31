/* Header file for minimum-cost maximal flow routines used to smooth basic
   block and edge frequency counts.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef PROFILE_H
#define PROFILE_H

/* Additional information about edges. */
struct edge_profile_info
{
  unsigned int count_valid:1;

  /* Is on the spanning tree.  */
  unsigned int on_tree:1;

  /* Pretend this edge does not exist (it is abnormal and we've
     inserted a fake to compensate).  */
  unsigned int ignore:1;
};

#define EDGE_INFO(e)  ((struct edge_profile_info *) (e)->aux)

/* Helpers annotating edges/basic blocks to GCOV counts.  */

extern vec<gcov_type> bb_gcov_counts;
extern hash_map<edge,gcov_type> *edge_gcov_counts;

inline gcov_type &
edge_gcov_count (edge e)
{
  bool existed;
  gcov_type &c = edge_gcov_counts->get_or_insert (e, &existed);
  if (!existed)
    c = 0;
  return c;
}

inline gcov_type &
bb_gcov_count (basic_block bb)
{
  return bb_gcov_counts[bb->index];
}

typedef struct gcov_working_set_info gcov_working_set_t;
extern gcov_working_set_t *find_working_set (unsigned pct_times_10);
extern void add_working_set (gcov_working_set_t *);

/* Smoothes the initial assigned basic block and edge counts using
   a minimum cost flow algorithm. */
extern void mcf_smooth_cfg (void);

extern gcov_type sum_edge_counts (vec<edge, va_gc> *edges);

extern void init_node_map (bool);
extern void del_node_map (void);

extern void get_working_sets (void);

/* Counter summary from the last set of coverage counts read by
   profile.cc.  */
extern struct gcov_summary *profile_info;

#endif /* PROFILE_H */
