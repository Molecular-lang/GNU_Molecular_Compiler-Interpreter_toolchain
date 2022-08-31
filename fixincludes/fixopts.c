/* Handle options that are passed from environment variables.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "fixlib.h"

te_verbose  verbose_level = VERB_PROGRESS;

fixinc_mode_t fixinc_mode = TESTING_OFF;

#define _ENV_(v,m,n,t) char const * v = NULL;
ENV_TABLE
#undef _ENV_

static void
show_not_def (char const * vname)
{
  static const char var_not_found[] =
    "fixincl ERROR:  %s environment variable not defined\n"
    "each of these must be defined:\n";
  static char const not_found_var[] = "\t%s\n";

  fprintf (stderr, var_not_found, vname);
# define _ENV_(vv,mm,nn,tt) \
  if (mm) fprintf (stderr, not_found_var, nn);
  ENV_TABLE
# undef _ENV_

  exit (EXIT_FAILURE);
}

void
initialize_opts (void)
{
#define _ENV_(v,m,n,t) { \
    static char const var[] = n; \
    v = getenv (var); \
    if (m && (v == NULL)) show_not_def (var); \
  }

  ENV_TABLE;
#undef _ENV_

  if ((pz_test_mode != NULL) && (strcmp (pz_test_mode, "true") == 0))
    fixinc_mode = TESTING_ON;
}
