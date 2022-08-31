/* Loop unrolling header file.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_LOOP_UNROLL_H
#define GCC_LOOP_UNROLL_H

extern void unroll_loops (int);
extern basic_block split_edge_and_insert (edge, rtx_insn *);


#endif /* GCC_LOOP_UNROLL_H */
