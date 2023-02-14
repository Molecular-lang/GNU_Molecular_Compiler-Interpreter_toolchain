/* Prologue stub for 64-bit ms/sysv clobbers: save */

#include <cet.h>

#ifdef __x86_64__
#include "i386-asm.h"

/* Prologue routine for saving 64-bit ms/sysv registers.  */

	.text
MS2SYSV_STUB_BEGIN(savms64_18)
	mov	%r15,-0x70(%rax)
MS2SYSV_STUB_BEGIN(savms64_17)
	mov	%r14,-0x68(%rax)
MS2SYSV_STUB_BEGIN(savms64_16)
	mov	%r13,-0x60(%rax)
MS2SYSV_STUB_BEGIN(savms64_15)
	mov	%r12,-0x58(%rax)
MS2SYSV_STUB_BEGIN(savms64_14)
	mov	%rbp,-0x50(%rax)
MS2SYSV_STUB_BEGIN(savms64_13)
	mov	%rbx,-0x48(%rax)
MS2SYSV_STUB_BEGIN(savms64_12)
	mov	%rdi,-0x40(%rax)
	mov	%rsi,-0x38(%rax)
	SSE_SAVE
	ret
MS2SYSV_STUB_END(savms64_12)
MS2SYSV_STUB_END(savms64_13)
MS2SYSV_STUB_END(savms64_14)
MS2SYSV_STUB_END(savms64_15)
MS2SYSV_STUB_END(savms64_16)
MS2SYSV_STUB_END(savms64_17)
MS2SYSV_STUB_END(savms64_18)

#endif /* __x86_64__ */

#if defined(__ELF__) && defined(__linux__)
	.section .note.GNU-stack,"",@progbits
	.previous
#endif
