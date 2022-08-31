/* Prototypes of memory model helper functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_MEMMODEL_H
#define GCC_MEMMODEL_H

/* Suppose that higher bits are target dependent. */
#define MEMMODEL_MASK ((1<<16)-1)

/* Legacy sync operations set this upper flag in the memory model.  This allows
   targets that need to do something stronger for sync operations to
   differentiate with their target patterns and issue a more appropriate insn
   sequence.  See bugzilla 65697 for background.  */
#define MEMMODEL_SYNC (1<<15)

/* Memory model without SYNC bit for targets/operations that do not care.  */
#define MEMMODEL_BASE_MASK (MEMMODEL_SYNC-1)

/* Memory model types for the __atomic* builtins.
   This must match the order in libstdc++-v3/include/bits/atomic_base.h.  */
enum memmodel
{
  MEMMODEL_RELAXED = 0,
  MEMMODEL_CONSUME = 1,
  MEMMODEL_ACQUIRE = 2,
  MEMMODEL_RELEASE = 3,
  MEMMODEL_ACQ_REL = 4,
  MEMMODEL_SEQ_CST = 5,
  MEMMODEL_LAST = 6,
  MEMMODEL_SYNC_ACQUIRE = MEMMODEL_ACQUIRE | MEMMODEL_SYNC,
  MEMMODEL_SYNC_RELEASE = MEMMODEL_RELEASE | MEMMODEL_SYNC,
  MEMMODEL_SYNC_SEQ_CST = MEMMODEL_SEQ_CST | MEMMODEL_SYNC,
  /* Say that all the higher bits are valid target extensions.  */
  MEMMODEL_MAX = INTTYPE_MAXIMUM (int)
};

/* Return the memory model from a host integer.  */
static inline enum memmodel
memmodel_from_int (unsigned HOST_WIDE_INT val)
{
  return (enum memmodel) (val & MEMMODEL_MASK);
}

/* Return the base memory model from a host integer.  */
static inline enum memmodel
memmodel_base (unsigned HOST_WIDE_INT val)
{
  return (enum memmodel) (val & MEMMODEL_BASE_MASK);
}

/* Return TRUE if the memory model is RELAXED.  */
static inline bool
is_mm_relaxed (enum memmodel model)
{
  return (model & MEMMODEL_BASE_MASK) == MEMMODEL_RELAXED;
}

/* Return TRUE if the memory model is CONSUME.  */
static inline bool
is_mm_consume (enum memmodel model)
{
  return (model & MEMMODEL_BASE_MASK) == MEMMODEL_CONSUME;
}

/* Return TRUE if the memory model is ACQUIRE.  */
static inline bool
is_mm_acquire (enum memmodel model)
{
  return (model & MEMMODEL_BASE_MASK) == MEMMODEL_ACQUIRE;
}

/* Return TRUE if the memory model is RELEASE.  */
static inline bool
is_mm_release (enum memmodel model)
{
  return (model & MEMMODEL_BASE_MASK) == MEMMODEL_RELEASE;
}

/* Return TRUE if the memory model is ACQ_REL.  */
static inline bool
is_mm_acq_rel (enum memmodel model)
{
  return (model & MEMMODEL_BASE_MASK) == MEMMODEL_ACQ_REL;
}

/* Return TRUE if the memory model is SEQ_CST.  */
static inline bool
is_mm_seq_cst (enum memmodel model)
{
  return (model & MEMMODEL_BASE_MASK) == MEMMODEL_SEQ_CST;
}

/* Return TRUE if the memory model is a SYNC variant.  */
static inline bool
is_mm_sync (enum memmodel model)
{
  return (model & MEMMODEL_SYNC);
}

#endif  /* GCC_MEMMODEL_H  */
