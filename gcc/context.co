/* context.cc - Holder for global state
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "context.h"
#include "pass_manager.h"
#include "dumpfile.h"
#include "realmpfr.h"

/* The singleton holder of global state: */
gcc::context *g;

gcc::context::context ()
  : m_passes (NULL), m_dumps (new gcc::dump_manager ())
{
  have_offload = false;
}

gcc::context::~context ()
{
  delete m_passes;
  delete m_dumps;

  /* Release MPFR caches to avoid Valgrind leak reports.  */
  mpfr_free_cache ();
}
