/* Infrastructure for tracking user variable locations and values
   throughout compilation.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_VALTRACK_H
#define GCC_VALTRACK_H

/* Debug uses of dead regs.  */

/* Entry that maps a dead pseudo (REG) used in a debug insns that dies
   at different blocks to the debug temp (DTEMP) it was replaced
   with.  */

struct dead_debug_global_entry
{
  rtx reg;
  rtx dtemp;
};

/* Descriptor for hash_table to hash by dead_debug_global_entry's REG
   and map to DTEMP.  */

struct dead_debug_hash_descr : free_ptr_hash <dead_debug_global_entry>
{
  /* Hash on the pseudo number.  */
  static inline hashval_t hash (const dead_debug_global_entry *my);
  /* Entries are identical if they refer to the same pseudo.  */
  static inline bool equal (const dead_debug_global_entry *my,
			    const dead_debug_global_entry *other);
};

/* Hash on the pseudo number.  */
inline hashval_t
dead_debug_hash_descr::hash (const dead_debug_global_entry *my)
{
  return REGNO (my->reg);
}

/* Entries are identical if they refer to the same pseudo.  */
inline bool
dead_debug_hash_descr::equal (const dead_debug_global_entry *my,
			      const dead_debug_global_entry *other)
{
  return my->reg == other->reg;
}

/* Maintain a global table of pseudos used in debug insns after their
   deaths in other blocks, and debug temps their deathpoint values are
   to be bound to.  */

struct dead_debug_global
{
  /* This hash table that maps pseudos to debug temps.  */
  hash_table<dead_debug_hash_descr> *htab;
  /* For each entry in htab, the bit corresponding to its REGNO will
     be set.  */
  bitmap used;
};

/* Node of a linked list of uses of dead REGs in debug insns.  */

struct dead_debug_use
{
  df_ref use;
  struct dead_debug_use *next;
};

/* Linked list of the above, with a bitmap of the REGs in the
   list.  */

struct dead_debug_local
{
  /* The first dead_debug_use entry in the list.  */
  struct dead_debug_use *head;
  /* A pointer to the global tracking data structure.  */
  struct dead_debug_global *global;
  /* A bitmap that has bits set for each REG used in the
     dead_debug_use list, and for each entry in the global hash
     table.  */
  bitmap used;
  /* A bitmap that has bits set for each INSN that is to be
     rescanned.  */
  bitmap to_rescan;
};

/* This type controls the behavior of dead_debug_insert_temp WRT
   UREGNO and INSN.  */

enum debug_temp_where
  {
    /* Bind a newly-created debug temporary to a REG for UREGNO, and
       insert the debug insn before INSN.  REG is expected to die at
       INSN.  */
    DEBUG_TEMP_BEFORE_WITH_REG = -1,
    /* Bind a newly-created debug temporary to the value INSN stores
       in REG, and insert the debug insn before INSN.  */
    DEBUG_TEMP_BEFORE_WITH_VALUE = 0,
    /* Bind a newly-created debug temporary to a REG for UREGNO, and
       insert the debug insn after INSN.  REG is expected to be set at
       INSN.  */
    DEBUG_TEMP_AFTER_WITH_REG = 1,
    /* Like DEBUG_TEMP_AFTER_WITH_REG, but force addition of a debug
       temporary even if there is just a single debug use.  This is used
       on regs that are becoming REG_DEAD on INSN and so uses of the
       reg later on are invalid.  */
    DEBUG_TEMP_AFTER_WITH_REG_FORCE = 2
  };

extern void dead_debug_global_init (struct dead_debug_global *, bitmap);
extern void dead_debug_global_finish (struct dead_debug_global *, bitmap);
extern void dead_debug_local_init (struct dead_debug_local *, bitmap,
				   struct dead_debug_global *);
extern void dead_debug_local_finish (struct dead_debug_local *, bitmap);
extern void dead_debug_add (struct dead_debug_local *, df_ref, unsigned int);
extern int dead_debug_insert_temp (struct dead_debug_local *,
				   unsigned int uregno, rtx_insn *insn,
				   enum debug_temp_where);

extern void propagate_for_debug (rtx_insn *, rtx_insn *, rtx, rtx, basic_block);


#endif /* GCC_VALTRACK_H */
