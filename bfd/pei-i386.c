/* BFD back-end for Intel 386 PE IMAGE COFF files.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "bfd.h"

#define TARGET_SYM		i386_pei_vec
#define TARGET_NAME		"pei-i386"
#define COFF_IMAGE_WITH_PE
#define COFF_WITH_PE
#define PCRELOFFSET		true
#define TARGET_UNDERSCORE	'_'
/* Long section names not allowed in executable images, only object files.  */
#define COFF_LONG_SECTION_NAMES 0
#define COFF_SUPPORT_GNU_LINKONCE
#define COFF_LONG_FILENAMES

#define COFF_SECTION_ALIGNMENT_ENTRIES \
{ COFF_SECTION_NAME_PARTIAL_MATCH (".idata"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \
{ COFF_SECTION_NAME_EXACT_MATCH (".pdata"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \
{ COFF_SECTION_NAME_PARTIAL_MATCH (".debug"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 0 }, \
{ COFF_SECTION_NAME_PARTIAL_MATCH (".gnu.linkonce.wi."), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 0 }

#include "coff-i386.c"
