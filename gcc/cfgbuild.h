/* Control flow graph building header file.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_CFGBUILD_H
#define GCC_CFGBUILD_H

extern bool inside_basic_block_p (const rtx_insn *);
extern bool control_flow_insn_p (const rtx_insn *);
extern void rtl_make_eh_edge (sbitmap, basic_block, rtx);
extern void find_many_sub_basic_blocks (sbitmap);

#endif /* GCC_CFGBUILD_H */
