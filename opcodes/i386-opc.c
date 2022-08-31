/* Intel 80386 opcode table
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "libiberty.h"
#include "i386-opc.h"
#include "i386-tbl.h"

/* To be indexed by segment register number.  */
const unsigned char i386_seg_prefixes[] = {
	ES_PREFIX_OPCODE,
	CS_PREFIX_OPCODE,
	SS_PREFIX_OPCODE,
	DS_PREFIX_OPCODE,
	FS_PREFIX_OPCODE,
	GS_PREFIX_OPCODE
};
