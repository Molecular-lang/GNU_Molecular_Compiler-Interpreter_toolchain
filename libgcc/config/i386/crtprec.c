#ifndef _SOFT_FLOAT
#if __PREC == 32
 #define X87CW		(0 << 8)	/* Single precision (24 bits) */
#elif __PREC == 64
 #define X87CW		(2 << 8)	/* Double precision (53 bits) */
#elif __PREC == 80
 #define X87CW		(3 << 8)	/* Extended precision (64 bits) */
#else
 #error "Wrong precision requested."
#endif

#define X87CW_PCMASK	(3 << 8)

static void __attribute__((constructor))
set_precision (void)
{
  unsigned short int cwd;

  asm volatile ("fnstcw\t%0" : "=m" (cwd));

  cwd &= ~X87CW_PCMASK;
  cwd |= X87CW;

  asm volatile ("fldcw\t%0" : : "m" (cwd));
}
#endif
