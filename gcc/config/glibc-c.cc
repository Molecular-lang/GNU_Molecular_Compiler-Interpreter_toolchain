/* C-family target hooks initializer for targets possibly using glibc. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "c-family/c-target.h"
#include "c-family/c-target-def.h"

/* Implement TARGET_C_PREINCLUDE for glibc targets.  */

static const char *
glibc_c_preinclude (void)
{
  return "stdc-predef.h";
}

#undef TARGET_C_PREINCLUDE
#define TARGET_C_PREINCLUDE glibc_c_preinclude

struct gcc_targetcm targetcm = TARGETCM_INITIALIZER;
