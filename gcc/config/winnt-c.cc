/* Default C-family target hooks initializer. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "c-family/c-target.h"
#include "c-family/c-target-def.h"

static bool
winnt_implicit_extern_c (const char *ident)
{
  return !strcmp(ident, "wmain")
      || !strcmp(ident, "DllMain")
      || !strcmp(ident, "WinMain")
      || !strcmp(ident, "wWinMain");
}

#undef TARGET_CXX_IMPLICIT_EXTERN_C
#define TARGET_CXX_IMPLICIT_EXTERN_C winnt_implicit_extern_c

struct gcc_targetcm targetcm = TARGETCM_INITIALIZER;
