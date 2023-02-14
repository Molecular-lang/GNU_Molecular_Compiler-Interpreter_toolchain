/* ELF program property for Intel CET. */

/* Add x86 feature with IBT and/or SHSTK bits to ELF program property
   if they are enabled.  Otherwise, contents in this header file are
   unused.  Define _CET_ENDBR for assembly codes.  _CET_ENDBR should be
   placed unconditionally at the entrance of a function whose address
   may be taken.  */

#ifndef _CET_H_INCLUDED
#define _CET_H_INCLUDED

#ifdef __ASSEMBLER__

# if defined __CET__ && (__CET__ & 1) != 0
#  ifdef __x86_64__
#   define _CET_ENDBR endbr64
#  else
#   define _CET_ENDBR endbr32
#  endif
# else
#  define _CET_ENDBR
# endif

# ifdef __ELF__
#  ifdef __CET__
#   if (__CET__ & 1) != 0
/* GNU_PROPERTY_X86_FEATURE_1_IBT.  */
#    define __PROPERTY_IBT 0x1
#   else
#    define __PROPERTY_IBT 0x0
#   endif

#   if (__CET__ & 2) != 0
/* GNU_PROPERTY_X86_FEATURE_1_SHSTK.  */
#    define __PROPERTY_SHSTK 0x2
#   else
#    define __PROPERTY_SHSTK 0x0
#   endif

#   define __PROPERTY_BITS (__PROPERTY_IBT | __PROPERTY_SHSTK)

#   ifdef __LP64__
#    define __PROPERTY_ALIGN 3
#   else
#    define __PROPERTY_ALIGN 2
#   endif

	.pushsection ".note.gnu.property", "a"
	.p2align __PROPERTY_ALIGN
	.long 1f - 0f		/* name length.  */
	.long 4f - 1f		/* data length.  */
	/* NT_GNU_PROPERTY_TYPE_0.   */
	.long 5			/* note type.  */
0:
	.asciz "GNU"		/* vendor name.  */
1:
	.p2align __PROPERTY_ALIGN
	/* GNU_PROPERTY_X86_FEATURE_1_AND.  */
	.long 0xc0000002	/* pr_type.  */
	.long 3f - 2f		/* pr_datasz.  */
2:
	/* GNU_PROPERTY_X86_FEATURE_1_XXX.  */
	.long __PROPERTY_BITS
3:
	.p2align __PROPERTY_ALIGN
4:
	.popsection
#  endif /* __CET__ */
# endif /* __ELF__ */
#endif /* __ASSEMBLER__ */

#endif /* _CET_H_INCLUDED */
