/* Default common target hooks initializer. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "common/common-target.h"
#include "common/common-target-def.h"

/* Do not include tm.h or tm_p.h here; if it is useful for a target to
   define some macros for the initializer in a header without defining
   targetm_common itself (for example, because of interactions with
   some hooks depending on the target OS and others on the target
   architecture), create a separate tm_common.h for only the relevant
   definitions.  */

struct gcc_targetm_common targetm_common = TARGETM_COMMON_INITIALIZER;
