/* Specialized bits of code needed for the offloading tables.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Target machine header files require this define. */
#define IN_LIBGCC2

/* FIXME: Including auto-host is incorrect, but until we have
   identified the set of defines that need to go into auto-target.h,
   this will have to do.  */
#include "auto-host.h"
#undef caddr_t
#undef pid_t
#undef rlim_t
#undef ssize_t
#undef vfork
#include "tconfig.h"
#include "tsystem.h"
#include "coretypes.h"
#include "tm.h"
#include "libgcc_tm.h"

#if defined(HAVE_GAS_HIDDEN) && ENABLE_OFFLOADING == 1

#define OFFLOAD_FUNC_TABLE_SECTION_NAME ".gnu.offload_funcs"
#define OFFLOAD_VAR_TABLE_SECTION_NAME ".gnu.offload_vars"

#ifdef CRT_BEGIN

const void *const __offload_func_table[0]
  __attribute__ ((__used__, visibility ("hidden"),
		  section (OFFLOAD_FUNC_TABLE_SECTION_NAME))) = { };
const void *const __offload_var_table[0]
  __attribute__ ((__used__, visibility ("hidden"),
		  section (OFFLOAD_VAR_TABLE_SECTION_NAME))) = { };

#elif defined CRT_END

const void *const __offload_funcs_end[0]
  __attribute__ ((__used__, visibility ("hidden"),
		  section (OFFLOAD_FUNC_TABLE_SECTION_NAME))) = { };
const void *const __offload_vars_end[0]
  __attribute__ ((__used__, visibility ("hidden"),
		  section (OFFLOAD_VAR_TABLE_SECTION_NAME))) = { };

#elif defined CRT_TABLE

extern const void *const __offload_func_table[];
extern const void *const __offload_var_table[];
extern const void *const __offload_funcs_end[];
extern const void *const __offload_vars_end[];

const void *const __OFFLOAD_TABLE__[]
  __attribute__ ((__visibility__ ("hidden"))) =
{
  &__offload_func_table, &__offload_funcs_end,
  &__offload_var_table, &__offload_vars_end
};

#else /* ! CRT_BEGIN && ! CRT_END && ! CRT_TABLE  */
#error "One of CRT_BEGIN, CRT_END or CRT_TABLE must be defined."
#endif

#endif
