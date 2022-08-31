/* Data structures and functions for streaming GIMPLE.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLE_STREAMER_H
#define GCC_GIMPLE_STREAMER_H

#include "tree-streamer.h"

/* In gimple-streamer-in.cc  */
void input_bb (class lto_input_block *, enum LTO_tags, class data_in *, struct function *, int);

/* In gimple-streamer-out.cc  */
void output_bb (struct output_block *, basic_block, struct function *);

#endif  /* GCC_GIMPLE_STREAMER_H  */
