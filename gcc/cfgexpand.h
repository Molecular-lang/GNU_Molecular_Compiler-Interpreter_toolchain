/* Header file for lowering trees to RTL.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_CFGEXPAND_H
#define GCC_CFGEXPAND_H

extern tree gimple_assign_rhs_to_tree (gimple *);
extern HOST_WIDE_INT estimated_stack_frame_size (struct cgraph_node *);
extern void set_parm_rtl (tree, rtx);


#endif /* GCC_CFGEXPAND_H */
