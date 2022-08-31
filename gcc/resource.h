/* Definitions for computing resource usage of specific insns.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_RESOURCE_H
#define GCC_RESOURCE_H

/* Macro to clear all resources.  */
#define CLEAR_RESOURCE(RES)	\
 do { (RES)->memory = (RES)->volatil = (RES)->cc = 0; \
      CLEAR_HARD_REG_SET ((RES)->regs); } while (0)

/* The resources used by a given insn.  */
struct resources
{
  char memory;		/* Insn sets or needs a memory location.  */
  char volatil;		/* Insn sets or needs a volatile memory loc.  */
  char cc;		/* Insn sets or needs the condition codes.  */
  HARD_REG_SET regs;	/* Which registers are set or needed.  */
};

/* The kinds of rtl mark_*_resources will consider */
enum mark_resource_type
{
  MARK_SRC_DEST = 0,
  MARK_SRC_DEST_CALL = 1
};

extern void mark_target_live_regs (rtx_insn *, rtx, struct resources *);
extern void mark_set_resources (rtx, struct resources *, int,
				enum mark_resource_type);
extern void mark_referenced_resources (rtx, struct resources *, bool);
extern void clear_hashed_info_for_insn (rtx_insn *);
extern void clear_hashed_info_until_next_barrier (rtx_insn *);
extern void incr_ticks_for_insn (rtx_insn *);
extern void mark_end_of_function_resources (rtx, bool);
extern void init_resource_info (rtx_insn *);
extern void free_resource_info (void);

#endif /* GCC_RESOURCE_H */
