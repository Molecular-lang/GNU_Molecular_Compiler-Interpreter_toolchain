/* Control flow optimization header file.
   Please review: $(src-dir)/SPL-README for Licencing info. */


#ifndef GCC_CFGCLEANUP_H
#define GCC_CFGCLEANUP_H

enum replace_direction { dir_none, dir_forward, dir_backward, dir_both };

extern int flow_find_cross_jump (basic_block, basic_block, rtx_insn **, rtx_insn **, enum replace_direction*);
extern int flow_find_head_matching_sequence (basic_block, basic_block, rtx_insn **, rtx_insn **, int);
extern bool delete_unreachable_blocks (void);
extern void delete_dead_jumptables (void);
extern bool cleanup_cfg (int);

#endif /* GCC_CFGCLEANUP_H */
