/* Default D language target hooks initializer. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm_d.h"
#include "d/d-target.h"
#include "d/d-target-def.h"

/* Do not include tm.h or tm_p.h here; definitions needed by the target
   architecture to initialize targetdm should instead be added to tm_d.h.  */

struct gcc_targetdm targetdm = TARGETDM_INITIALIZER;
