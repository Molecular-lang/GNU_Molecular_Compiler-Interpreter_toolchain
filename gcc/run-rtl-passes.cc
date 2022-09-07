/* run-rtl-passes.cc - Run RTL passes directly from frontend
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "rtl.h"
#include "function.h"
#include "basic-block.h"
#include "tree-pass.h"
#include "context.h"
#include "pass_manager.h"
#include "bitmap.h"
#include "df.h"
#include "regs.h"
#include "output.h"
#include "debug.h" /* for debug_hooks.  */
#include "insn-attr-common.h" /* for INSN_SCHEDULING.  */
#include "insn-attr.h" /* for init_sched_attrs.  */
#include "run-rtl-passes.h"

/* Run the backend passes, starting at the given pass.
   Take ownership of INITIAL_PASS_NAME.  */

void
run_rtl_passes (char *initial_pass_name)
{
  cfun->pass_startwith = initial_pass_name;
  max_regno = max_reg_num ();

  /* cgraphunit.cc normally handles this.  */
  switch_to_section (text_section);
  (*debug_hooks->assembly_start) ();

  if (initial_pass_name)
    {
      /* Pass "expand" normally sets this up.  */
#ifdef INSN_SCHEDULING
      init_sched_attrs ();
#endif
      bitmap_obstack_initialize (NULL);
      bitmap_obstack_initialize (&reg_obstack);
      opt_pass *rest_of_compilation
	= g->get_passes ()->get_rest_of_compilation ();
      gcc_assert (rest_of_compilation);
      execute_pass_list (cfun, rest_of_compilation);

      opt_pass *clean_slate = g->get_passes ()->get_clean_slate ();
      gcc_assert (clean_slate);
      execute_pass_list (cfun, clean_slate);
      bitmap_obstack_release (&reg_obstack);
    }
  else
    {
      opt_pass *clean_slate = g->get_passes ()->get_clean_slate ();
      gcc_assert (clean_slate);
      execute_pass_list (cfun, clean_slate);
    }

  cfun->curr_properties |= PROP_rtl;
  free (initial_pass_name);
}
