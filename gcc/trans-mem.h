/* Miscellaneous transactional memory support definitions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TRANS_MEM_H
#define GCC_TRANS_MEM_H

/* These defines must match the enumerations in libitm.h.  */
#define PR_INSTRUMENTEDCODE		0x0001
#define PR_UNINSTRUMENTEDCODE	0x0002
#define PR_MULTIWAYCODE			(PR_INSTRUMENTEDCODE | PR_UNINSTRUMENTEDCODE)
#define PR_HASNOXMMUPDATE		0x0004
#define PR_HASNOABORT			0x0008
#define PR_HASNOIRREVOCABLE		0x0020
#define PR_DOESGOIRREVOCABLE	0x0040
#define PR_HASNOSIMPLEREADS		0x0080
#define PR_AWBARRIERSOMITTED	0x0100
#define PR_RARBARRIERSOMITTED	0x0200
#define PR_UNDOLOGCODE			0x0400
#define PR_PREFERUNINSTRUMENTED	0x0800
#define PR_EXCEPTIONBLOCK		0x1000
#define PR_HASELSE				0x2000
#define PR_READONLY				0x4000

extern void compute_transaction_bits (void);
extern bool is_tm_ending (gimple *);
extern tree build_tm_abort_call (location_t, bool);
extern bool is_tm_safe (const_tree);
extern bool is_tm_pure (const_tree);
extern bool is_tm_may_cancel_outer (tree);
extern bool is_tm_ending_fndecl (tree);
extern void record_tm_replacement (tree, tree);
extern void tm_malloc_replacement (tree);

#endif  // GCC_TRANS_MEM_H
