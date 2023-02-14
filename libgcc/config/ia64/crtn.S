# This file just makes sure that the .fini and .init sections do in
# fact return.  Users may put any desired instructions in those sections.
# This file is the last thing linked into any executable.

	.section	".init"
	;;
	mov	ar.pfs = r34
	mov	b0 = r33
	.restore sp
	mov	r12 = r35
	br.ret.sptk.many b0

	.section	".fini"
	;;
	mov	ar.pfs = r34
	mov	b0 = r33
	.restore sp
	mov	r12 = r35
	br.ret.sptk.many b0

# end of crtn.S
