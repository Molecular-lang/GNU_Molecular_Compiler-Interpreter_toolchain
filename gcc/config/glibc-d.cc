/* Glibc support needed only by D front-end.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "memmodel.h"
#include "tm_p.h"
#include "d/d-target.h"
#include "d/d-target-def.h"

/* Implement TARGET_D_OS_VERSIONS for Glibc targets.  */

static void
glibc_d_os_builtins (void)
{
  d_add_builtin_version ("Posix");

#define builtin_version(TXT) d_add_builtin_version (TXT)

#ifdef GNU_USER_TARGET_D_OS_VERSIONS
  GNU_USER_TARGET_D_OS_VERSIONS ();
#endif

#ifdef EXTRA_TARGET_D_OS_VERSIONS
  EXTRA_TARGET_D_OS_VERSIONS ();
#endif
}

/* Handle a call to `__traits(getTargetInfo, "objectFormat")'.  */

static tree
glibc_d_handle_target_object_format (void)
{
  const char *objfmt = "elf";

  return build_string_literal (strlen (objfmt) + 1, objfmt);
}

/* Implement TARGET_D_REGISTER_OS_TARGET_INFO for Glibc targets.  */

static void
glibc_d_register_target_info (void)
{
  const struct d_target_info_spec handlers[] = {
    { "objectFormat", glibc_d_handle_target_object_format },
    { NULL, NULL },
  };

  d_add_target_info_handlers (handlers);
}

#undef TARGET_D_OS_VERSIONS
#define TARGET_D_OS_VERSIONS glibc_d_os_builtins

#undef TARGET_D_REGISTER_OS_TARGET_INFO
#define TARGET_D_REGISTER_OS_TARGET_INFO glibc_d_register_target_info

struct gcc_targetdm targetdm = TARGETDM_INITIALIZER;
