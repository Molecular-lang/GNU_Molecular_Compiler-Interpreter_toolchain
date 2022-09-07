/* Default D language target hooks initializer.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "memmodel.h"
#include "tm_d.h"
#include "d/d-target.h"
#include "d/d-target-def.h"

struct gcc_targetdm targetdm = TARGETDM_INITIALIZER;
