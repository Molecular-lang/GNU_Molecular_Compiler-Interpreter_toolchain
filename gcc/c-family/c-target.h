/* Data structure definitions for target-specific C-family behavior.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_C_TARGET_H
#define GCC_C_TARGET_H

#define DEFHOOKPOD(NAME, DOC, TYPE, INIT) TYPE NAME;
#define DEFHOOK(NAME, DOC, TYPE, PARAMS, INIT) TYPE (* NAME) PARAMS;
#define DEFHOOK_UNDOC DEFHOOK
#define HOOKSTRUCT(FRAGMENT) FRAGMENT

#include "c-target.def"

/* Each target can provide their own.  */
extern struct gcc_targetcm targetcm;

#endif /* GCC_C_TARGET_H */
