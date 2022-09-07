/* Default initializers for a generic GCC target.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* See target.def for a description of what this file contains and how to
   use it.

   We want to have non-NULL default definitions of all hook functions,
   even if they do nothing.  */

/* Note that if one of these macros must be defined in an OS .h file
   rather than the .c file, then we need to wrap the default
   definition in a #ifndef, since files include tm.h before this one.  */

#define TARGET_ASM_ALIGNED_HI_OP "\t.short\t"
#define TARGET_ASM_ALIGNED_SI_OP "\t.long\t"
#define TARGET_ASM_ALIGNED_DI_OP NULL
#define TARGET_ASM_ALIGNED_TI_OP NULL

/* GAS and SYSV4 assemblers accept these.  */
#if defined (OBJECT_FORMAT_ELF)
#define TARGET_ASM_UNALIGNED_HI_OP "\t.2byte\t"
#define TARGET_ASM_UNALIGNED_SI_OP "\t.4byte\t"
#define TARGET_ASM_UNALIGNED_DI_OP "\t.8byte\t"
#define TARGET_ASM_UNALIGNED_TI_OP NULL
#else
#define TARGET_ASM_UNALIGNED_HI_OP NULL
#define TARGET_ASM_UNALIGNED_SI_OP NULL
#define TARGET_ASM_UNALIGNED_DI_OP NULL
#define TARGET_ASM_UNALIGNED_TI_OP NULL
#endif /* OBJECT_FORMAT_ELF */

/* There is no standard way to handle P{S,D,T}Imode, targets must implement them
   if required.  */
#define TARGET_ASM_ALIGNED_PSI_OP NULL
#define TARGET_ASM_UNALIGNED_PSI_OP NULL
#define TARGET_ASM_ALIGNED_PDI_OP NULL
#define TARGET_ASM_UNALIGNED_PDI_OP NULL
#define TARGET_ASM_ALIGNED_PTI_OP NULL
#define TARGET_ASM_UNALIGNED_PTI_OP NULL

#if !defined(TARGET_ASM_CONSTRUCTOR) && !defined(USE_COLLECT2)
# ifdef CTORS_SECTION_ASM_OP
#  define TARGET_ASM_CONSTRUCTOR default_ctor_section_asm_out_constructor
# else
#  ifdef TARGET_ASM_NAMED_SECTION
#   define TARGET_ASM_CONSTRUCTOR default_named_section_asm_out_constructor
#  else
#   define TARGET_ASM_CONSTRUCTOR default_stabs_asm_out_constructor
#  endif
# endif
#endif

#if !defined(TARGET_ASM_DESTRUCTOR) && !defined(USE_COLLECT2)
# ifdef DTORS_SECTION_ASM_OP
#  define TARGET_ASM_DESTRUCTOR default_dtor_section_asm_out_destructor
# else
#  ifdef TARGET_ASM_NAMED_SECTION
#   define TARGET_ASM_DESTRUCTOR default_named_section_asm_out_destructor
#  else
#   define TARGET_ASM_DESTRUCTOR default_stabs_asm_out_destructor
#  endif
# endif
#endif

#if !defined(TARGET_HAVE_CTORS_DTORS)
# if defined(TARGET_ASM_CONSTRUCTOR) && defined(TARGET_ASM_DESTRUCTOR)
# define TARGET_HAVE_CTORS_DTORS true
# endif
#endif

#ifndef TARGET_TERMINATE_DW2_EH_FRAME_INFO
#ifdef EH_FRAME_SECTION_NAME
#define TARGET_TERMINATE_DW2_EH_FRAME_INFO false
#endif
#endif

#if !defined(TARGET_ASM_OUTPUT_ANCHOR) && !defined(ASM_OUTPUT_DEF)
#define TARGET_ASM_OUTPUT_ANCHOR NULL
#endif

#define TARGET_ASM_ALIGNED_INT_OP				\
		       {TARGET_ASM_ALIGNED_HI_OP,		\
			TARGET_ASM_ALIGNED_PSI_OP,		\
			TARGET_ASM_ALIGNED_SI_OP,		\
			TARGET_ASM_ALIGNED_PDI_OP,		\
			TARGET_ASM_ALIGNED_DI_OP,		\
			TARGET_ASM_ALIGNED_PTI_OP,		\
			TARGET_ASM_ALIGNED_TI_OP}

#define TARGET_ASM_UNALIGNED_INT_OP				\
		       {TARGET_ASM_UNALIGNED_HI_OP,		\
			TARGET_ASM_UNALIGNED_PSI_OP,		\
			TARGET_ASM_UNALIGNED_SI_OP,		\
			TARGET_ASM_UNALIGNED_PDI_OP,		\
			TARGET_ASM_UNALIGNED_DI_OP,		\
			TARGET_ASM_UNALIGNED_PTI_OP,		\
			TARGET_ASM_UNALIGNED_TI_OP}

#if !defined (TARGET_FUNCTION_INCOMING_ARG)
#define TARGET_FUNCTION_INCOMING_ARG TARGET_FUNCTION_ARG
#endif

#include "target-hooks-def.h"

#include "hooks.h"
#include "targhooks.h"
#include "insn-target-def.h"
