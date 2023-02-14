/* Backward compatibility unwind routines. */

#if defined (USE_GAS_SYMVER) && defined (USE_LIBUNWIND_EXCEPTIONS)
#include "tconfig.h"
#include "tsystem.h"
#include "unwind.h"
#include "unwind-dw2-fde.h"
#include "unwind-compat.h"

extern const fde * __libunwind__Unwind_Find_FDE
  (void *, struct dwarf_eh_bases *);

const fde *
_Unwind_Find_FDE (void *pc, struct dwarf_eh_bases *bases)
{
  __libunwind__Unwind_Find_FDE (pc, bases);
}

symver (_Unwind_Find_FDE, GCC_3.0);
#endif
