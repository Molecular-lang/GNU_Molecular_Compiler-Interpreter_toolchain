/* Debug counter for debugging support
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_DBGCNT_H
#define GCC_DBGCNT_H

#define DEBUG_COUNTER(a) a,

enum debug_counter {
#include "dbgcnt.def"
   debug_counter_number_of_counters
};

#undef DEBUG_COUNTER

extern bool dbg_cnt_is_enabled (enum debug_counter index);
extern bool dbg_cnt (enum debug_counter index);
extern unsigned dbg_cnt_counter (enum debug_counter index);
extern void dbg_cnt_process_opt (const char *arg);
extern void dbg_cnt_list_all_counters (void);

#endif /* GCC_DBGCNT_H */
