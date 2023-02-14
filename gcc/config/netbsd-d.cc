/* Functions for generic NetBSD as target machine for GNU D compiler. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tm_d.h"
#include "d/d-target.h"
#include "d/d-target-def.h"

/* Define TARGET_D_OS_VERSIONS for NetBSD targets.  */

static void
netbsd_d_os_builtins (void)
{
  d_add_builtin_version ("Posix");
  d_add_builtin_version ("NetBSD");
}

/* Handle a call to `__traits(getTargetInfo, "objectFormat")'.  */

static tree
netbsd_d_handle_target_object_format (void)
{
  const char *objfmt = "elf";

  return build_string_literal (strlen (objfmt) + 1, objfmt);
}

/* Implement TARGET_D_REGISTER_OS_TARGET_INFO for NetBSD targets.  */

static void
netbsd_d_register_target_info (void)
{
  const struct d_target_info_spec handlers[] = {
    { "objectFormat", netbsd_d_handle_target_object_format },
    { NULL, NULL },
  };

  d_add_target_info_handlers (handlers);
}

#undef TARGET_D_OS_VERSIONS
#define TARGET_D_OS_VERSIONS netbsd_d_os_builtins

#undef TARGET_D_REGISTER_OS_TARGET_INFO
#define TARGET_D_REGISTER_OS_TARGET_INFO netbsd_d_register_target_info

struct gcc_targetdm targetdm = TARGETDM_INITIALIZER;
