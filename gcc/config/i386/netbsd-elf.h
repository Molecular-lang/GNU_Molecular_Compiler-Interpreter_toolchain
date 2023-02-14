/* Definitions of target machine for GCC,
   for i386/ELF NetBSD systems.
 */

#define TARGET_OS_CPP_BUILTINS()		\
  do						\
    {						\
      NETBSD_OS_CPP_BUILTINS_ELF();		\
    }						\
  while (0)


/* Extra specs needed for NetBSD/i386 ELF.  */

#undef SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS			\
  { "netbsd_cpp_spec", NETBSD_CPP_SPEC },	\
  { "netbsd_entry_point", NETBSD_ENTRY_POINT },


/* Provide a LINK_SPEC appropriate for a NetBSD/i386 ELF target.  */

#undef LINK_SPEC
#define LINK_SPEC NETBSD_LINK_SPEC_ELF

#define NETBSD_ENTRY_POINT "__start"


/* Provide a CPP_SPEC appropriate for NetBSD.  */

#undef CPP_SPEC
#define CPP_SPEC "%(netbsd_cpp_spec)"


/* Make gcc agree with <machine/ansi.h> */

#undef SIZE_TYPE
#define SIZE_TYPE "unsigned int"

#undef PTRDIFF_TYPE
#define PTRDIFF_TYPE "int"

#undef ASM_APP_ON
#define ASM_APP_ON "#APP\n"

#undef ASM_APP_OFF
#define ASM_APP_OFF "#NO_APP\n"

#undef ASM_COMMENT_START
#define ASM_COMMENT_START "#"

#undef DEBUGGER_REGNO
#define DEBUGGER_REGNO(n)  svr4_debugger_register_map[n]


/* Output assembler code to FILE to call the profiler.  */

#undef NO_PROFILE_COUNTERS
#define NO_PROFILE_COUNTERS	1

#undef FUNCTION_PROFILER
#define FUNCTION_PROFILER(FILE, LABELNO)				\
{									\
  if (flag_pic)								\
    fprintf (FILE, "\tcall __mcount@PLT\n");				\
  else									\
    fprintf (FILE, "\tcall __mcount\n");				\
}


#undef HAS_INIT_SECTION

/* This is how we tell the assembler that two symbols have the same value.  */

#define ASM_OUTPUT_DEF(FILE,NAME1,NAME2) \
  do { assemble_name(FILE, NAME1); 	 \
       fputs(" = ", FILE);		 \
       assemble_name(FILE, NAME2);	 \
       fputc('\n', FILE); } while (0)

/* We always use gas here, so we don't worry about ECOFF assembler
   problems.  */
#undef TARGET_GAS
#define TARGET_GAS	1

/* Default to pcc-struct-return, because this is the ELF abi and
   we don't care about compatibility with older gcc versions.  */
#define DEFAULT_PCC_STRUCT_RETURN 1

#define HAVE_ENABLE_EXECUTE_STACK
