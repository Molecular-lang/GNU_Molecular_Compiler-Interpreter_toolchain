# This file just make a stack frame for the contents of the .fini and
# .init sections.  Users may put any desired instructions in those
# sections.

	.section	".init"
	.align 16
	.global	_init
_init:
	.prologue 14, 33
	.save ar.pfs, r34
	alloc	r34 = ar.pfs, 0, 4, 0, 0
	.vframe r35
	mov	r35 = r12
	.save rp, r33
	mov	r33 = b0
	.body

	.section	".fini"
	.align	16
	.global	_fini
_fini:
	.prologue 14, 33
	.save ar.pfs, r34
	alloc	r34 = ar.pfs, 0, 4, 0, 0
	.vframe r35
	mov	r35 = r12
	.save rp, r33
	mov	r33 = b0
	.body

# end of crti.S
