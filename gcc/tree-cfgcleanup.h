/* Header file for CFG cleanup for trees. */

#ifndef GCC_TREE_CFGCLEANUP_H
#define GCC_TREE_CFGCLEANUP_H

/* In tree-cfgcleanup.cc  */
extern bitmap cfgcleanup_altered_bbs;
extern bool cleanup_tree_cfg (unsigned = 0);
extern bool fixup_noreturn_call (gimple *stmt);
extern bool delete_unreachable_blocks_update_callgraph (cgraph_node *dst_node, bool update_clones);
extern unsigned clean_up_loop_closed_phi (function *);
extern bool phi_alternatives_equal (basic_block, edge, edge);

#endif /* GCC_TREE_CFGCLEANUP_H */
