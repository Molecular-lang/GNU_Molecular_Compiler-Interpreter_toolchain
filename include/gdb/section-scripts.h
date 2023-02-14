/* Definition of kinds of records in section .debug_gdb_scripts. */

#ifndef GDB_SECTION_SCRIPTS_H
#define GDB_SECTION_SCRIPTS_H

/* Each entry in section .debug_gdb_scripts begins with a byte that is used to
   identify the entry.  This byte is to use as we choose.
   0 is reserved so that it is never used (to catch errors).
   It is recommended to avoid ASCII values 32-127 to help catch (most) cases
   of forgetting to include this byte.
   Other unused values needn't specify different scripting languages,
   but we have no need for anything else at the moment.

   These values are defined as macros so that they can be used in embedded
   asms and assembler source files.  */

/* Reserved.  */
#define SECTION_SCRIPT_ID_NEVER_USE 0

/* The record is a nul-terminated file name to load as a python file.  */
#define SECTION_SCRIPT_ID_PYTHON_FILE 1

/* Native GDB scripts are not currently supported in .debug_gdb_scripts,
   but we reserve a value for it.  */
/*#define SECTION_SCRIPT_ID_GDB_FILE 2*/

/* The record is a nul-terminated file name to load as a guile(scheme)
   file.  */
#define SECTION_SCRIPT_ID_SCHEME_FILE 3

/* The record is a nul-terminated string.
   The first line is the name of the script.
   Subsequent lines are interpreted as a python script.  */
#define SECTION_SCRIPT_ID_PYTHON_TEXT 4

/* Native GDB scripts are not currently supported in .debug_gdb_scripts,
   but we reserve a value for it.  */
/*#define SECTION_SCRIPT_ID_GDB_TEXT 5*/

/* The record is a nul-terminated string.
   The first line is the name of the script.
   Subsequent lines are interpreted as a guile(scheme) script.  */
#define SECTION_SCRIPT_ID_SCHEME_TEXT 6

#endif /* GDB_SECTION_SCRIPTS_H */
