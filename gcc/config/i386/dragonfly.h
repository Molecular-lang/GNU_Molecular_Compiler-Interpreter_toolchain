/* Definitions for Intel 386 running DragonFly with ELF format */

/* Override the default comment-starter of "/".  */
#undef  ASM_COMMENT_START
#define ASM_COMMENT_START "#"

#undef  ASM_APP_ON
#define ASM_APP_ON "#APP\n"

#undef  ASM_APP_OFF
#define ASM_APP_OFF "#NO_APP\n"

#undef  DEBUGGER_REGNO
#define DEBUGGER_REGNO(n) \
  (TARGET_64BIT ? debugger64_register_map[n] : svr4_debugger_register_map[n])

#undef  NO_PROFILE_COUNTERS
#define NO_PROFILE_COUNTERS	1

/* Tell final.cc that we don't need a label passed to mcount.  */

#undef  MCOUNT_NAME
#define MCOUNT_NAME ".mcount"

/* Make gcc agree with <machine/ansi.h>.  */

#undef  SIZE_TYPE
#define SIZE_TYPE	(TARGET_64BIT ? "long unsigned int" : "unsigned int")

#undef  PTRDIFF_TYPE
#define PTRDIFF_TYPE	(TARGET_64BIT ? "long int" : "int")

#undef  WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE	(TARGET_64BIT ? 32 : BITS_PER_WORD)

#undef  SUBTARGET_EXTRA_SPECS	/* i386.h bogusly defines it.  */
#define SUBTARGET_EXTRA_SPECS \
  { "dfbsd_dynamic_linker", DFBSD_DYNAMIC_LINKER }

/* Don't default to pcc-struct-return, we want to retain compatibility with
   older gcc versions AND pcc-struct-return is nonreentrant.
   (even though the SVR4 ABI for the i386 says that records and unions are
   returned in memory).  */

#undef  DEFAULT_PCC_STRUCT_RETURN
#define DEFAULT_PCC_STRUCT_RETURN 0

/* DragonFly sets the rounding precision of the FPU to 53 bits.  Let the
   compiler get the contents of <float.h> and std::numeric_limits correct.  */
#undef TARGET_96_ROUND_53_LONG_DOUBLE
#define TARGET_96_ROUND_53_LONG_DOUBLE (!TARGET_64BIT)

/* Static stack checking is supported by means of probes.  */
#define STACK_CHECK_STATIC_BUILTIN 1

/* Support for i386 was removed from DragonFly in 2007  */
#define SUBTARGET32_DEFAULT_CPU "i486"

#define TARGET_ASM_FILE_END file_end_indicate_exec_stack
