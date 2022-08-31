/* Calculate (post)dominators header file.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_DOMINANCE_H
#define GCC_DOMINANCE_H

enum cdi_direction
{
  CDI_DOMINATORS = 1,
  CDI_POST_DOMINATORS = 2
};

/* State of dominance information.  */

enum dom_state
{
  DOM_NONE,		/* Not computed at all.  */
  DOM_NO_FAST_QUERY,	/* The data is OK, but the fast query data are not usable.  */
  DOM_OK		/* Everything is ok.  */
};

extern void calculate_dominance_info (enum cdi_direction);
extern void calculate_dominance_info_for_region (enum cdi_direction,
						 vec<basic_block>);
extern void free_dominance_info (function *, enum cdi_direction);
extern void free_dominance_info (enum cdi_direction);
extern void free_dominance_info_for_region (function *,
					    enum cdi_direction,
					    vec<basic_block>);
extern basic_block get_immediate_dominator (enum cdi_direction, basic_block);
extern void set_immediate_dominator (enum cdi_direction, basic_block,
				     basic_block);
extern auto_vec<basic_block> get_dominated_by (enum cdi_direction, basic_block);
extern auto_vec<basic_block> get_dominated_by_region (enum cdi_direction,
							 basic_block *,
							 unsigned);
extern auto_vec<basic_block> get_dominated_to_depth (enum cdi_direction,
						     basic_block, int);
extern auto_vec<basic_block> get_all_dominated_blocks (enum cdi_direction,
						       basic_block);
extern void redirect_immediate_dominators (enum cdi_direction, basic_block,
					   basic_block);
extern basic_block nearest_common_dominator (enum cdi_direction,
					     basic_block, basic_block);
extern basic_block nearest_common_dominator_for_set (enum cdi_direction,
						     bitmap);
extern bool dominated_by_p (enum cdi_direction, const_basic_block,
			    const_basic_block);
unsigned bb_dom_dfs_in (enum cdi_direction, basic_block);
unsigned bb_dom_dfs_out (enum cdi_direction, basic_block);
extern void verify_dominators (enum cdi_direction);

/* Verify invariants of computed dominance information, if internal consistency
   checks are enabled.  */

static inline void
checking_verify_dominators (cdi_direction dir)
{
  if (flag_checking)
    verify_dominators (dir);
}

basic_block recompute_dominator (enum cdi_direction, basic_block);
extern void iterate_fix_dominators (enum cdi_direction,
				    vec<basic_block> &, bool);
extern void add_to_dominance_info (enum cdi_direction, basic_block);
extern void delete_from_dominance_info (enum cdi_direction, basic_block);
extern basic_block first_dom_son (enum cdi_direction, basic_block);
extern basic_block next_dom_son (enum cdi_direction, basic_block);
extern enum dom_state dom_info_state (function *, enum cdi_direction);
extern enum dom_state dom_info_state (enum cdi_direction);
extern void set_dom_info_availability (enum cdi_direction, enum dom_state);
extern bool dom_info_available_p (function *, enum cdi_direction);
extern bool dom_info_available_p (enum cdi_direction);



#endif /* GCC_DOMINANCE_H */
