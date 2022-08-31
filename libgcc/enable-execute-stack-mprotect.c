/* Implement __enable_execute_stack using mprotect(2).
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

#define STACK_PROT_RWX (PROT_READ | PROT_WRITE | PROT_EXEC)

static int need_enable_exec_stack;

static void check_enabling (void) __attribute__ ((unused));
extern void __enable_execute_stack (void *);

#if defined __sun__ && defined __svr4__
static void __attribute__ ((constructor))
check_enabling (void)
{
  int prot = (int) sysconf (_SC_STACK_PROT);

  if (prot != STACK_PROT_RWX)
    need_enable_exec_stack = 1;
}
#else
/* There is no way to query the execute permission of the stack, so
   we always issue the mprotect() call.  */

static int need_enable_exec_stack = 1;
#endif

/* Attempt to turn on access permissions for the stack.  Unfortunately it
   is not possible to make this namespace-clean.*/

void
__enable_execute_stack (void *addr)
{
  if (!need_enable_exec_stack)
    return;
  else
    {
      static long size, mask;

      if (size == 0) {
	size = getpagesize ();
	mask = ~(size - 1);
      }

      char *page = (char *) (((long) addr) & mask);
      char *end  = (char *)
	((((long) (addr + __LIBGCC_TRAMPOLINE_SIZE__)) & mask) + size);

      if (mprotect (page, end - page, STACK_PROT_RWX) < 0)
	/* Note that no errors should be emitted by this code; it is
	   considered dangerous for library calls to send messages to
	   stdout/stderr.  */
	abort ();
    }
}
