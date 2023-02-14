/* Dummy subroutines for language-specific support on Windows. */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"

bool
i386_pe_type_dllimport_p (tree)
{
  return false;
}


bool
i386_pe_type_dllexport_p (tree)
{
  return false;
}


void
i386_pe_adjust_class_at_definition (tree)
{ }
