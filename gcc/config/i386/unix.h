/* Definitions for Unix assembler syntax for the Intel 80386.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This file defines the aspects of assembler syntax
   that are the same for all the i386 Unix systems
   (though they may differ in non-Unix systems).  */

/* Define macro used to output shift-double opcodes when the shift
   count is in %cl.  Some assemblers require %cl as an argument;
   some don't.  This macro controls what to do: by default, don't
   print %cl.  */
#define SHIFT_DOUBLE_OMITS_COUNT 1

/* Define the syntax of pseudo-ops, labels and comments.  */

/* String containing the assembler's comment-starter.
   Note the trailing space is necessary in case the character
   that immediately follows the comment is '*'.  If this happens
   and the space is not there the assembler will interpret this
   as the start of a C-like slash-star comment and complain when
   there is no terminator.  */

#define ASM_COMMENT_START "/ "

/* Output to assembler file text saying following lines
   may contain character constants, extra white space, comments, etc.  */

#define ASM_APP_ON "/APP\n"

/* Output to assembler file text saying following lines
   no longer contain unusual constructs.  */

#define ASM_APP_OFF "/NO_APP\n"

/* Output before read-only data.  */

#define TEXT_SECTION_ASM_OP "\t.text"

/* Output before writable (initialized) data.  */

#define DATA_SECTION_ASM_OP "\t.data"

/* Output before writable (uninitialized) data.  */

#define BSS_SECTION_ASM_OP "\t.bss"

/* Globalizing directive for a label.  */
#define GLOBAL_ASM_OP "\t.globl\t"

/* By default, target has a 80387, uses IEEE compatible arithmetic,
   and returns float values in the 387.  */
#undef TARGET_SUBTARGET_DEFAULT
#define TARGET_SUBTARGET_DEFAULT \
	(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS)

/* By default, 64-bit mode uses 128-bit long double.  */
#undef TARGET_SUBTARGET64_DEFAULT
#define TARGET_SUBTARGET64_DEFAULT \
	MASK_128BIT_LONG_DOUBLE
