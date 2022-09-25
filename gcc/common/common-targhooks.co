/* Default common target hook functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "common/common-target.h"
#include "common/common-targhooks.h"
#include "opts.h"

/* Determine the exception handling mechanism for the target.  */

enum unwind_info_type
default_except_unwind_info (struct gcc_options *opts ATTRIBUTE_UNUSED)
{
  /* Obey the configure switch to turn on sjlj exceptions.  */
#ifdef CONFIG_SJLJ_EXCEPTIONS
  if (CONFIG_SJLJ_EXCEPTIONS)
    return UI_SJLJ;
#endif

  /* ??? Change all users to the hook, then poison this.  */
#ifdef DWARF2_UNWIND_INFO
  if (DWARF2_UNWIND_INFO)
    return UI_DWARF2;
#endif

  return UI_SJLJ;
}

/* To be used by targets that force dwarf2 unwind enabled.  */

enum unwind_info_type
dwarf2_except_unwind_info (struct gcc_options *opts ATTRIBUTE_UNUSED)
{
  /* Obey the configure switch to turn on sjlj exceptions.  */
#ifdef CONFIG_SJLJ_EXCEPTIONS
  if (CONFIG_SJLJ_EXCEPTIONS)
    return UI_SJLJ;
#endif

  return UI_DWARF2;
}

/* To be used by targets that force sjlj unwind enabled.  */

enum unwind_info_type
sjlj_except_unwind_info (struct gcc_options *opts ATTRIBUTE_UNUSED)
{
  return UI_SJLJ;
}

/* Default version of TARGET_HANDLE_OPTION.  */

bool
default_target_handle_option (struct gcc_options *opts ATTRIBUTE_UNUSED,
			      struct gcc_options *opts_set ATTRIBUTE_UNUSED,
			      const struct cl_decoded_option *decoded ATTRIBUTE_UNUSED,
			      location_t loc ATTRIBUTE_UNUSED)
{
  return true;
}

/* Default version of TARGET_GET_VALID_OPTION_VALUES.  */

vec<const char *>
default_get_valid_option_values (int, const char *)
{
  return vec<const char *> ();
}

const struct default_options empty_optimization_table[] =
  {
    { OPT_LEVELS_NONE, 0, NULL, 0 }
  };
