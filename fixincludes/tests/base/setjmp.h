/*  DO NOT EDIT THIS FILE.

    It has been auto-edited by fixincludes from:

	"fixinc/tests/inc/setjmp.h"

    This had to be done to correct non-standard usages in the
    original, manufacturer supplied header file.  */



#if defined( HPUX_LONGJMP_CHECK )
extern void	longjmp __((jmp_buf, int)) __attribute__ ((__noreturn__));
#endif  /* HPUX_LONGJMP_CHECK */