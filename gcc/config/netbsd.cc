/* Functions for generic NetBSD as target machine for GNU C compiler. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "varasm.h"
#include "netbsd-protos.h"

static void
netbsd_patch_builtin (enum built_in_function fncode)
{
  tree fn = builtin_decl_explicit (fncode);
  tree sym;
  char *newname;

  if (!fn)
    return;

  sym = DECL_ASSEMBLER_NAME (fn);
  newname = ACONCAT (("__c99_", IDENTIFIER_POINTER (sym), NULL));

  set_user_assembler_name (fn, newname);

  fn = builtin_decl_implicit (fncode);
  if (fn)
    set_user_assembler_name (fn, newname);
}

void
netbsd_patch_builtins (void)
{
  netbsd_patch_builtin (BUILT_IN_CABSF);
  netbsd_patch_builtin (BUILT_IN_CABS);
  netbsd_patch_builtin (BUILT_IN_CABSL);
}
