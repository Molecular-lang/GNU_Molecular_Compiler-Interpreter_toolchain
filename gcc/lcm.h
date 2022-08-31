/* Generic partial redundancy elimination with lazy code motion header file.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_LCM_H
#define GCC_LCM_H

extern struct edge_list *pre_edge_lcm_avs (int, sbitmap *, sbitmap *,
					   sbitmap *, sbitmap *, sbitmap *,
					   sbitmap *, sbitmap **, sbitmap **);
extern struct edge_list *pre_edge_lcm (int, sbitmap *, sbitmap *,
				       sbitmap *, sbitmap *, sbitmap **,
				       sbitmap **);
extern void compute_available (sbitmap *, sbitmap *, sbitmap *, sbitmap *);
extern struct edge_list *pre_edge_rev_lcm (int, sbitmap *,
					   sbitmap *, sbitmap *,
					   sbitmap *, sbitmap **,
					   sbitmap **);
#endif /* GCC_LCM_H */
