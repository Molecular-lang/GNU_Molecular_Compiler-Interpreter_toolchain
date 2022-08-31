/* Definitions needed when using stabs embedded in ELF sections.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This file may be included by any ELF target which wishes to
   support -gstabs generating stabs in sections, as produced by gas
   and understood by gdb.  */

#ifndef GCC_DBX_ELF_H
#define GCC_DBX_ELF_H

/* Output DBX (stabs) debugging information if doing -gstabs.  */

#define DBX_DEBUGGING_INFO 1

/* Make LBRAC and RBRAC addresses relative to the start of the
   function.  The native Solaris stabs debugging format works this
   way, gdb expects it, and it reduces the number of relocation
   entries...  */

#define DBX_BLOCKS_FUNCTION_RELATIVE 1

/* ... but, to make this work, functions must appear prior to line info.  */

#define DBX_FUNCTION_FIRST

/* When generating stabs debugging, use N_BINCL entries.  */

#define DBX_USE_BINCL

/* There is no limit to the length of stabs strings.  */

#ifndef DBX_CONTIN_LENGTH
#define DBX_CONTIN_LENGTH 0
#endif

/* Like block addresses, stabs line numbers are relative to the
   current function.  */

#define DBX_LINES_FUNCTION_RELATIVE 1

/* Generate a blank trailing N_SO to mark the end of the .o file, since
   we can't depend upon the linker to mark .o file boundaries with
   embedded stabs.  */

#define DBX_OUTPUT_NULL_N_SO_AT_MAIN_SOURCE_FILE_END

#endif /* ! GCC_DBX_ELF_H */
