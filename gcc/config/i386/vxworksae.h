/* IA32 VxWorks AE target definitions for GNU compiler.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This platform supports the probing method of stack checking and
   requires 4K of space for executing a possible last chance handler.  */
#undef STACK_CHECK_PROTECT
#define STACK_CHECK_PROTECT 4096
