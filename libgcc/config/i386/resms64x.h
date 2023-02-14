/* Epilogue stub for 64-bit ms/sysv clobbers: restore and return */

#include <cet.h>

#ifdef __x86_64__
#include "i386-asm.h"

/* Epilogue routine for restoring 64-bit ms/sysv registers and returning from
 * function.  */

	.text
	cfi_startproc()
	cfi_def_cfa(%r10, 8)
MS2SYSV_STUB_BEGIN(resms64x_18)
	mov	-0x70(%rsi),%r15
MS2SYSV_STUB_BEGIN(resms64x_17)
	mov	-0x68(%rsi),%r14
MS2SYSV_STUB_BEGIN(resms64x_16)
	mov	-0x60(%rsi),%r13
MS2SYSV_STUB_BEGIN(resms64x_15)
	mov	-0x58(%rsi),%r12
MS2SYSV_STUB_BEGIN(resms64x_14)
	mov	-0x50(%rsi),%rbp
MS2SYSV_STUB_BEGIN(resms64x_13)
	mov	-0x48(%rsi),%rbx
MS2SYSV_STUB_BEGIN(resms64x_12)
	mov	-0x40(%rsi),%rdi
	SSE_RESTORE
	mov	-0x38(%rsi),%rsi
	mov	%r10,%rsp
	cfi_def_cfa_register(%rsp)
	ret
	cfi_endproc()
MS2SYSV_STUB_END(resms64x_12)
MS2SYSV_STUB_END(resms64x_13)
MS2SYSV_STUB_END(resms64x_14)
MS2SYSV_STUB_END(resms64x_15)
MS2SYSV_STUB_END(resms64x_16)
MS2SYSV_STUB_END(resms64x_17)
MS2SYSV_STUB_END(resms64x_18)

#endif /* __x86_64__ */

#if defined(__ELF__) && defined(__linux__)
	.section .note.GNU-stack,"",@progbits
	.previous
#endif
