/* i386-darwin host-specific hook definitions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "hosthooks.h"
#include "hosthooks-def.h"
#include "config/host-darwin.h"

/* Darwin doesn't do anything special for x86 hosts; this file exists just
   to include config/host-darwin.h.  */

const struct host_hooks host_hooks = HOST_HOOKS_INITIALIZER;
