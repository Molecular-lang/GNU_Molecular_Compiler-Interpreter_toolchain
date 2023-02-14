/* Implement __enable_execute_stack for Windows32. */

#define WIN32_LEAN_AND_MEAN
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
