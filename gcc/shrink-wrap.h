/* Shrink-wrapping related functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_SHRINK_WRAP_H
#define GCC_SHRINK_WRAP_H

#include "function.h"

/* In shrink-wrap.cc.  */
extern bool requires_stack_frame_p (rtx_insn *, HARD_REG_SET, HARD_REG_SET);
extern void try_shrink_wrapping (edge *entry_edge, rtx_insn *prologue_seq);
extern void try_shrink_wrapping_separate (basic_block first_bb);
#define SHRINK_WRAPPING_ENABLED (flag_shrink_wrap && targetm.have_simple_return ())

#endif  /* GCC_SHRINK_WRAP_H  */


