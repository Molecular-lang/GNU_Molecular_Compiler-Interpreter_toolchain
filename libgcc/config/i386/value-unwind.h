/* Store register values as _Unwind_Word type in DWARF2 EH unwind context.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Define this macro if the target stores register values as _Unwind_Word
   type in unwind context.  Only enable it for x32.  */
#if defined __x86_64 && !defined __LP64__
# define REG_VALUE_IN_UNWIND_CONTEXT
#endif
