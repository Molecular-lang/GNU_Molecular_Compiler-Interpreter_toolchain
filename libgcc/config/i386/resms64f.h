/* Epilogue stub for 64-bit ms/sysv clobbers: restore (with hard frame pointer) */

#include <cet.h>

#ifdef __x86_64__
#include "i386-asm.h"

/* Epilogue routine for restoring 64-bit ms/sysv registers when hard frame
   pointer is used.  */

	.text
MS2SYSV_STUB_BEGIN(resms64f_17)
	mov	-0x68(%rsi),%r15
MS2SYSV_STUB_BEGIN(resms64f_16)
	mov	-0x60(%rsi),%r14
MS2SYSV_STUB_BEGIN(resms64f_15)
	mov	-0x58(%rsi),%r13
MS2SYSV_STUB_BEGIN(resms64f_14)
	mov	-0x50(%rsi),%r12
MS2SYSV_STUB_BEGIN(resms64f_13)
	mov	-0x48(%rsi),%rbx
MS2SYSV_STUB_BEGIN(resms64f_12)
	mov	-0x40(%rsi),%rdi
	SSE_RESTORE
	mov	-0x38(%rsi),%rsi
	ret
MS2SYSV_STUB_END(resms64f_12)
MS2SYSV_STUB_END(resms64f_13)
MS2SYSV_STUB_END(resms64f_14)
MS2SYSV_STUB_END(resms64f_15)
MS2SYSV_STUB_END(resms64f_16)
MS2SYSV_STUB_END(resms64f_17)

#endif /* __x86_64__ */

#if defined(__ELF__) && defined(__linux__)
	.section .note.GNU-stack,"",@progbits
	.previous
#endif
