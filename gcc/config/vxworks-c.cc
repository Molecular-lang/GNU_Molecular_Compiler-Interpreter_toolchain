/* C-family target hooks initializer for VxWorks targets. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "c-family/c-target.h"
#include "c-family/c-target-def.h"

/* Implement TARGET_C_PREINCLUDE for vxworks targets.  */

static const char *
vxworks_c_preinclude (void)
{
  return "vxworks-predef.h";
}

#undef TARGET_C_PREINCLUDE
#define TARGET_C_PREINCLUDE vxworks_c_preinclude

struct gcc_targetcm targetcm = TARGETCM_INITIALIZER;
