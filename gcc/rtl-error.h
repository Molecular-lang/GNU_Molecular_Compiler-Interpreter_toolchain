/* RTL specific diagnostic subroutines for GCC
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_RTL_ERROR_H
#define GCC_RTL_ERROR_H

#include "rtl.h"
#include "diagnostic-core.h"

extern void error_for_asm (const rtx_insn *, const char *, ...) ATTRIBUTE_GCC_DIAG(2,3);
extern void warning_for_asm (const rtx_insn *, const char *, ...) ATTRIBUTE_GCC_DIAG(2,3);

#endif /* GCC_RTL_ERROR_H */
