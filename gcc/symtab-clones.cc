/* Support for virtual clones in symbol table.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "tree.h"
#include "gimple.h"
#include "predict.h"
#include "target.h"
#include "rtl.h"
#include "alloc-pool.h"
#include "cgraph.h"
#include "symbol-summary.h"
#include "symtab-clones.h"
#include "lto-streamer.h"
#include "data-streamer.h"

namespace {

/* Function summary for clone_infos.  */
class GTY((user)) clone_infos_t: public function_summary <clone_info *>
{
public:
  clone_infos_t (symbol_table *table, bool ggc):
    function_summary<clone_info *> (table, ggc) { }
};

}  /* anon namespace  */

/* Return thunk_info possibly creating new one.  */
clone_info *
clone_info::get_create (cgraph_node *node)
{
  if (!symtab->m_clones)
    {
      symtab->m_clones
	 = new (ggc_alloc_no_dtor <function_summary <clone_info *>> ())
	     function_summary <clone_info *> (symtab, true);
      symtab->m_clones->disable_insertion_hook ();
      symtab->m_clones->disable_duplication_hook ();
    }
  return symtab->m_clones->get_create (node);
}
