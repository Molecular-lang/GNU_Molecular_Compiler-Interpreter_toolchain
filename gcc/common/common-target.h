/* Data structure definitions for common hooks.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_COMMON_TARGET_H
#define GCC_COMMON_TARGET_H


/* Sets of optimization levels at which an option may be enabled by
   default_options_optimization.  */
enum opt_levels
{
  OPT_LEVELS_NONE, /* No levels (mark end of array).  */
  OPT_LEVELS_ALL, /* All levels (used by targets to disable options
		     enabled in target-independent code).  */
  OPT_LEVELS_0_ONLY, /* -O0 only.  */
  OPT_LEVELS_1_PLUS, /* -O1 and above, including -Os and -Og.  */
  OPT_LEVELS_1_PLUS_SPEED_ONLY, /* -O1 and above, but not -Os or -Og.  */
  OPT_LEVELS_1_PLUS_NOT_DEBUG, /* -O1 and above, but not -Og.  */
  OPT_LEVELS_2_PLUS, /* -O2 and above, including -Os.  */
  OPT_LEVELS_2_PLUS_SPEED_ONLY, /* -O2 and above, but not -Os or -Og.  */
  OPT_LEVELS_3_PLUS, /* -O3 and above.  */
  OPT_LEVELS_3_PLUS_AND_SIZE, /* -O3 and above and -Os.  */
  OPT_LEVELS_SIZE, /* -Os only.  */
  OPT_LEVELS_FAST /* -Ofast only.  */
};

/* Description of options to enable by default at given levels.  */
struct default_options
{
  /* The levels at which to enable the option.  */
  enum opt_levels levels;

  /* The option index and argument or enabled/disabled sense of the
     option, as passed to handle_generated_option.  If ARG is NULL and
     the option allows a negative form, the option is considered to be
     passed in negative form when the optimization level is not one of
     those in LEVELS (in order to handle changes to the optimization
     level with the "optimize" attribute).  */
  size_t opt_index;
  const char *arg;
  int value;
};

#define DEFHOOKPOD(NAME, DOC, TYPE, INIT) TYPE NAME;
#define DEFHOOK(NAME, DOC, TYPE, PARAMS, INIT) TYPE (* NAME) PARAMS;
#define DEFHOOK_UNDOC DEFHOOK
#define HOOKSTRUCT(FRAGMENT) FRAGMENT

#include "common-target.def"

extern struct gcc_targetm_common targetm_common;

#endif /* GCC_C_TARGET_H */
