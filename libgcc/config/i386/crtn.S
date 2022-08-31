/* crtn.S for x86.

   Please review: $(src-dir)/SPL-README for Licencing info. */


/* This file just supplies returns for the .init and .fini sections.  It is
   linked in after all other files.  */

	.ident	"GNU C crtn.o"

	.section .init
	ret    $0x0

	.section .fini
	ret    $0x0
