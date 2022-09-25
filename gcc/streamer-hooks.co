/* Streamer hooks.  Support for adding streamer-specific callbacks to
   generic streaming routines.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "streamer-hooks.h"

/* Streamer hooks.  */
struct streamer_hooks streamer_hooks;

/* Initialize the current set of streamer hooks.  */

void
streamer_hooks_init (void)
{
  memset (&streamer_hooks, 0, sizeof (streamer_hooks));
}
