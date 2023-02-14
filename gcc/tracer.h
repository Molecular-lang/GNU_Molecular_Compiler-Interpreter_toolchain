/* Header file for Tracer. */

#ifndef GCC_TRACER_H
#define GCC_TRACER_H

extern basic_block transform_duplicate(basic_block bb, basic_block bb2);
extern bool ignore_bb_p(const_basic_block bb);

#endif /* GCC_TRACER_H */
