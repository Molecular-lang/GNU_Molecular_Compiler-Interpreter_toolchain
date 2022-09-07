/* Epilogue stub for 64-bit ms/sysv clobbers: restore
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <cet.h>

#ifdef __x86_64__
#include "i386-asm.h"

/* Epilogue routine for restoring 64-bit ms/sysv registers.  */

	.text
MS2SYSV_STUB_BEGIN(resms64_18)
	mov	-0x70(%rsi),%r15
MS2SYSV_STUB_BEGIN(resms64_17)
	mov	-0x68(%rsi),%r14
MS2SYSV_STUB_BEGIN(resms64_16)
	mov	-0x60(%rsi),%r13
MS2SYSV_STUB_BEGIN(resms64_15)
	mov	-0x58(%rsi),%r12
MS2SYSV_STUB_BEGIN(resms64_14)
	mov	-0x50(%rsi),%rbp
MS2SYSV_STUB_BEGIN(resms64_13)
	mov	-0x48(%rsi),%rbx
MS2SYSV_STUB_BEGIN(resms64_12)
	mov	-0x40(%rsi),%rdi
	SSE_RESTORE
	mov	-0x38(%rsi),%rsi
	ret
MS2SYSV_STUB_END(resms64_12)
MS2SYSV_STUB_END(resms64_13)
MS2SYSV_STUB_END(resms64_14)
MS2SYSV_STUB_END(resms64_15)
MS2SYSV_STUB_END(resms64_16)
MS2SYSV_STUB_END(resms64_17)
MS2SYSV_STUB_END(resms64_18)

#endif /* __x86_64__ */

#if defined(__ELF__) && defined(__linux__)
	.section .note.GNU-stack,"",@progbits
	.previous
#endif
