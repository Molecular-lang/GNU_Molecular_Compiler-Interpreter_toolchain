/* Solaris support needed only by D front-end.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "memmodel.h"
#include "tm_p.h"
#include "d/d-target.h"
#include "d/d-target-def.h"

/* Implement TARGET_D_OS_VERSIONS for Solaris targets.  */

static void
solaris_d_os_builtins (void)
{
  d_add_builtin_version ("Posix");
  d_add_builtin_version ("Solaris");			\
}

/* Handle a call to `__traits(getTargetInfo, "objectFormat")'.  */

static tree
solaris_d_handle_target_object_format (void)
{
  const char *objfmt = "elf";

  return build_string_literal (strlen (objfmt) + 1, objfmt);
}

/* Implement TARGET_D_REGISTER_OS_TARGET_INFO for Solaris targets.  */

static void
solaris_d_register_target_info (void)
{
  const struct d_target_info_spec handlers[] = {
    { "objectFormat", solaris_d_handle_target_object_format },
    { NULL, NULL },
  };

  d_add_target_info_handlers (handlers);
}

#undef TARGET_D_OS_VERSIONS
#define TARGET_D_OS_VERSIONS solaris_d_os_builtins

#undef TARGET_D_REGISTER_OS_TARGET_INFO
#define TARGET_D_REGISTER_OS_TARGET_INFO solaris_d_register_target_info

struct gcc_targetdm targetdm = TARGETDM_INITIALIZER;
