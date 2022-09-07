/* Operations with SIGNED and UNSIGNED.  -*- C++ -*-
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef SIGNOP_H
#define SIGNOP_H

/* This type is used for the large number of functions that produce
   different results depending on if the operands are signed types or
   unsigned types.  The signedness of a tree type can be found by
   using the TYPE_SIGN macro.  */

enum signop {
  SIGNED,
  UNSIGNED
};

#endif
