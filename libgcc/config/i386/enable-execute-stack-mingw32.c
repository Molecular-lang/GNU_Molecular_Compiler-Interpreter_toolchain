/* Implement __enable_execute_stack for Windows32.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <windows.h>

extern void __enable_execute_stack (void *);

void
__enable_execute_stack (void *addr)
{
  MEMORY_BASIC_INFORMATION b;

  if (!VirtualQuery (addr, &b, sizeof(b)))
    abort ();
  VirtualProtect (b.BaseAddress, b.RegionSize, PAGE_EXECUTE_READWRITE,
		  &b.Protect);
}
