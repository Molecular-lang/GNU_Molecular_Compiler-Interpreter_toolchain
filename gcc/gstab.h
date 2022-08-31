/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GSTAB_H
#define GCC_GSTAB_H

#define __define_stab(NAME, CODE, STRING) NAME=CODE,

enum
{
#include "stab.def"
LAST_UNUSED_STAB_CODE
};

/* stabs debug codes really are integers with expressive names.  */
typedef int stab_code_type;

#undef __define_stab

#endif /* ! GCC_GSTAB_H */
