/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifdef __VMS__
/* On VMS, long is a 32 bit type.  */
typedef unsigned long long unw_word;
typedef long long unw_sword;
#else
typedef unsigned long unw_word;
typedef long unw_sword;
#endif

struct unw_table_entry
{
  unw_word start_offset;
  unw_word end_offset;
  unw_word info_offset;
};

/* Accessors to fields of an unwind info block header.  In this common file to
   be visible from all the units involved in a target implementation.  */
   
#ifndef __USING_SJLJ_EXCEPTIONS__
#define UNW_VER(x)		((x) >> 48)
#define UNW_FLAG_MASK		0x0000ffff00000000
#define UNW_FLAG_OSMASK		0x0000f00000000000
#define UNW_FLAG_EHANDLER(x)	((x) & 0x0000000100000000L)
#define UNW_FLAG_UHANDLER(x)	((x) & 0x0000000200000000L)
#define UNW_LENGTH(x)		((x) & 0x00000000ffffffffL)
#endif

extern struct unw_table_entry *
_Unwind_FindTableEntry (void *pc, unw_word *segment_base,
			unw_word *gp, struct unw_table_entry *ent)
			__attribute__ ((__visibility__ ("hidden")));
