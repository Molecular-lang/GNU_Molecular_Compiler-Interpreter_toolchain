/* Definitions for Intel 386 ELF systems.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifdef __i386__
/* Used by crtstuff.c to initialize the base of data-relative relocations.
   These are GOT relative on x86, so return the pic register.  */
#define CRT_GET_RFIB_DATA(BASE)						\
  __asm__ ("call\t.LPR%=\n"						\
	   ".LPR%=:\n\t"						\
	   "pop{l}\t%0\n\t"						\
	   /* Due to a GAS bug, this cannot use EAX.  That encodes	\
	      smaller than the traditional EBX, which results in the	\
	      offset being off by one.  */				\
	   "add{l}\t{$_GLOBAL_OFFSET_TABLE_+[.-.LPR%=],%0"		\
		   "|%0,_GLOBAL_OFFSET_TABLE_+(.-.LPR%=)}"		\
	   : "=d"(BASE))
#endif
