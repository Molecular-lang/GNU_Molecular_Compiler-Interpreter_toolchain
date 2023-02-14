/* Set the title of a process. */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_SYS_PRCTL_H
#include <sys/types.h>
#include <sys/prctl.h>
#endif
#include "ansidecl.h"

/*

@deftypefn Supplemental void setproctitle (const char *@var{fmt}, ...)

Set the title of a process to @var{fmt}. va args not supported for now,
but defined for compatibility with BSD. 

@end deftypefn

*/

void
setproctitle (const char *name ATTRIBUTE_UNUSED, ...)
{
#ifdef PR_SET_NAME
  /* On GNU/Linux this sets the top visible "comm", but not
     necessarily the name visible in ps. */
  prctl (PR_SET_NAME, name);
#endif
}
