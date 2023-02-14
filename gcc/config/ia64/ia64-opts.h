/* Definitions for option handling for IA-64. */

#ifndef IA64_OPTS_H
#define IA64_OPTS_H

/* Which processor to schedule for. The cpu attribute defines a list
   that mirrors this list, so changes to ia64.md must be made at the
   same time.  */

enum processor_type
{
  PROCESSOR_ITANIUM,			/* Original Itanium.  */
  PROCESSOR_ITANIUM2,
  PROCESSOR_max
};

#endif
