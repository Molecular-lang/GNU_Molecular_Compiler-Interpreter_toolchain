/* crti.S for x86. */

/* This file just supplies labeled starting points for the .init and .fini
   sections.  It is linked in before the values-Xx.o files and also before
   crtbegin.o.  */
 
	.ident	"GNU C crti.s"

	.section .init
	.globl	_init
	.type	_init,@function
_init:

	.section .fini
	.globl	_fini
	.type	_fini,@function
_fini:
