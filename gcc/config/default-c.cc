/* Default C-family target hooks initializer.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "c-family/c-target.h"
#include "c-family/c-target-def.h"

/* Do not include tm.h or tm_p.h here; if it is useful for a target to
   define some macros for the initializer in a header without defining
   targetcm itself (for example, because of interactions with some
   hooks depending on the target OS and others on the target
   architecture), create a separate tm_c.h for only the relevant
   definitions.  */

struct gcc_targetcm targetcm = TARGETCM_INITIALIZER;
