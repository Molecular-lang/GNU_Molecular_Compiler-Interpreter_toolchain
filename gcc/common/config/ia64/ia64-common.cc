/* Common hooks for IA64. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "diagnostic-core.h"
#include "tm.h"
#include "memmodel.h"
#include "tm_p.h"
#include "common/common-target.h"
#include "common/common-target-def.h"
#include "opts.h"
#include "flags.h"

/* Implement overriding of the optimization options.  */
static const struct default_options ia64_option_optimization_table[] =
  {
#ifdef SUBTARGET_OPTIMIZATION_OPTIONS
    SUBTARGET_OPTIMIZATION_OPTIONS,
#endif

    /* Let the scheduler form additional regions.  */
    { OPT_LEVELS_ALL, OPT__param_max_sched_extend_regions_iters_, NULL, 2 },
      /* Set the default values for cache-related parameters.  */
    { OPT_LEVELS_ALL, OPT__param_simultaneous_prefetches_, NULL, 6 },
    { OPT_LEVELS_ALL, OPT__param_l1_cache_line_size_ , NULL, 32},
    { OPT_LEVELS_ALL, OPT__param_sched_mem_true_dep_cost_, NULL, 4 },

    { OPT_LEVELS_NONE, 0, NULL, 0 }
  };

/* Implement TARGET_HANDLE_OPTION.  */

static bool
ia64_handle_option (struct gcc_options *opts ATTRIBUTE_UNUSED,
		    struct gcc_options *opts_set ATTRIBUTE_UNUSED,
		    const struct cl_decoded_option *decoded,
		    location_t loc)
{
  size_t code = decoded->opt_index;
  const char *arg = decoded->arg;
  int value = decoded->value;

  switch (code)
    {
    case OPT_mtls_size_:
      if (value != 14 && value != 22 && value != 64)
	error_at (loc, "bad value %<%s%> for %<-mtls-size=%> switch", arg);
      return true;

    default:
      return true;
    }
}

/* Implement TARGET_EXCEPT_UNWIND_INFO.  */

enum unwind_info_type
ia64_except_unwind_info (struct gcc_options *opts)
{
  /* Honor the --enable-sjlj-exceptions configure switch.  */
#ifdef CONFIG_SJLJ_EXCEPTIONS
  if (CONFIG_SJLJ_EXCEPTIONS)
    return UI_SJLJ;
#endif

  /* For simplicity elsewhere in this file, indicate that all unwind
     info is disabled if we're not emitting unwind tables.  */
  if (!opts->x_flag_exceptions && !opts->x_flag_unwind_tables)
    return UI_NONE;

  return UI_TARGET;
}

#undef TARGET_OPTION_OPTIMIZATION_TABLE
#define TARGET_OPTION_OPTIMIZATION_TABLE ia64_option_optimization_table

#undef TARGET_EXCEPT_UNWIND_INFO
#define TARGET_EXCEPT_UNWIND_INFO  ia64_except_unwind_info

#undef TARGET_DEFAULT_TARGET_FLAGS
#define TARGET_DEFAULT_TARGET_FLAGS (TARGET_DEFAULT | TARGET_CPU_DEFAULT)
#undef TARGET_HANDLE_OPTION
#define TARGET_HANDLE_OPTION ia64_handle_option

struct gcc_targetm_common targetm_common = TARGETM_COMMON_INITIALIZER;
