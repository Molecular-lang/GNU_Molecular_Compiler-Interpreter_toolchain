/* Epilogue stub for 64-bit ms/sysv clobbers: restore, leave and return */

#include <cet.h>

#ifdef __x86_64__
#include "i386-asm.h"

/* Epilogue routine for 64-bit ms/sysv registers when hard frame pointer
 * used -- restores registers, restores frame pointer and then returns
 * from the function.  */

	.text
	cfi_startproc()
	cfi_offset(%rbp, -16)
	cfi_def_cfa(%rbp, 16)
MS2SYSV_STUB_BEGIN(resms64fx_17)
	mov	-0x68(%rsi),%r15
MS2SYSV_STUB_BEGIN(resms64fx_16)
	mov	-0x60(%rsi),%r14
MS2SYSV_STUB_BEGIN(resms64fx_15)
	mov	-0x58(%rsi),%r13
MS2SYSV_STUB_BEGIN(resms64fx_14)
	mov	-0x50(%rsi),%r12
MS2SYSV_STUB_BEGIN(resms64fx_13)
	mov	-0x48(%rsi),%rbx
MS2SYSV_STUB_BEGIN(resms64fx_12)
	mov	-0x40(%rsi),%rdi
	SSE_RESTORE
	mov	-0x38(%rsi),%rsi
	leaveq
	cfi_def_cfa(%rsp, 8)
	ret
	cfi_endproc()
MS2SYSV_STUB_END(resms64fx_12)
MS2SYSV_STUB_END(resms64fx_13)
MS2SYSV_STUB_END(resms64fx_14)
MS2SYSV_STUB_END(resms64fx_15)
MS2SYSV_STUB_END(resms64fx_16)
MS2SYSV_STUB_END(resms64fx_17)

#endif /* __x86_64__ */

#if defined(__ELF__) && defined(__linux__)
	.section .note.GNU-stack,"",@progbits
	.previous
#endif
