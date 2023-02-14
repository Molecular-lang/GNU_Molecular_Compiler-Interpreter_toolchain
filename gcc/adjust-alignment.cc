/* Adjust alignment for local variable.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "tree.h"
#include "tree-pass.h"
#include "memmodel.h"
#include "tm_p.h"

namespace {

const pass_data pass_data_adjust_alignment =
{
  GIMPLE_PASS, /* type */
  "adjust_alignment", /* name */
  OPTGROUP_NONE, /* optinfo_flags */
  TV_NONE, /* tv_id */
  0, /* properties_required */
  0, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  0, /* todo_flags_finish */
};

class pass_adjust_alignment : public gimple_opt_pass
{
public:
  pass_adjust_alignment (gcc::context *ctxt)
    : gimple_opt_pass (pass_data_adjust_alignment, ctxt)
  {}

  unsigned int execute (function *) final override;
}; // class pass_adjust_alignment

} // anon namespace

/* Entry point to adjust_alignment pass.  */
unsigned int
pass_adjust_alignment::execute (function *fun)
{
  size_t i;
  tree var;

  FOR_EACH_LOCAL_DECL (fun, i, var)
    {
      /* Don't adjust aligment for static local var and hard register var.  */
      if (is_global_var (var) || DECL_HARD_REGISTER (var))
	continue;

      unsigned align = LOCAL_DECL_ALIGNMENT (var);

      /* Make sure alignment only increase.  */
      gcc_assert (align >= DECL_ALIGN (var));

      SET_DECL_ALIGN (var, align);
    }
  return 0;
}

gimple_opt_pass *
make_pass_adjust_alignment (gcc::context *ctxt)
{
  return new pass_adjust_alignment (ctxt);
}
