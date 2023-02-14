/* We could call fesetenv() here but that would create a confusing
   dependency on libm (since that is where fesetenv() gets defined.
   To avoid this, just do everything locally.  */
#define FE_NONIEEE_ENV 0x0009a04d0270037f

static void __attribute__((constructor))
__ia64_set_fast_math (void)
{
  __asm__ __volatile__ ("mov.m ar.fpsr=%0" : : "r"(FE_NONIEEE_ENV));
}
