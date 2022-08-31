/* Header file for memory address lowering and mode selection.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_ADDRESS_H
#define GCC_TREE_SSA_ADDRESS_H

/* Description of a memory address.  */

struct mem_address
{
  tree symbol, base, index, step, offset;
};

extern rtx addr_for_mem_ref (struct mem_address *, addr_space_t, bool);
extern rtx addr_for_mem_ref (tree exp, addr_space_t as, bool really_expand);
extern void get_address_description (tree, struct mem_address *);
extern tree tree_mem_ref_addr (tree, tree);
extern bool valid_mem_ref_p (machine_mode, addr_space_t, struct mem_address *);
extern void move_fixed_address_to_symbol (struct mem_address *, class aff_tree *);
tree create_mem_ref (gimple_stmt_iterator *, tree, class aff_tree *, tree, tree, tree, bool);
extern void copy_ref_info (tree, tree);
tree maybe_fold_tmr (tree);

extern unsigned int preferred_mem_scale_factor (tree base, machine_mode mem_mode, bool speed);
#endif /* GCC_TREE_SSA_ADDRESS_H */
