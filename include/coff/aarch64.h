/* AArch64 COFF support for BFD. */

#define COFFAARCH64 1

#define L_LNNO_SIZE 2
#define INCLUDE_COMDAT_FIELDS_IN_AUXENT
#include "coff/external.h"

#define F_AARCH64_ARCHITECTURE_MASK	(0x4000)

#define	AARCH64MAGIC	0xaa64  /* From Microsoft specification. */

#undef  BADMAG
#define BADMAG(x) ((x).f_magic != AARCH64MAGIC)
#define AARCH64         1                 /* Customize coffcode.h.  */

#define IMAGE_NT_OPTIONAL_HDR64_MAGIC      0x20b

#define OMAGIC          0404    /* Object files, eg as output.  */
#define ZMAGIC          IMAGE_NT_OPTIONAL_HDR64_MAGIC    /* Demand load format, eg normal ld output 0x10b.  */
#define STMAGIC		0401	/* Target shlib.  */
#define SHMAGIC		0443	/* Host   shlib.  */

/* define some NT default values */
/*  #define NT_IMAGE_BASE        0x400000 moved to internal.h */
#define NT_SECTION_ALIGNMENT 0x1000
#define NT_FILE_ALIGNMENT    0x200
#define NT_DEF_RESERVE       0x100000
#define NT_DEF_COMMIT        0x1000

/* We use the .rdata section to hold read only data.  */
#define _LIT	".rdata"

/********************** RELOCATION DIRECTIVES **********************/
struct external_reloc
{
  char r_vaddr[4];
  char r_symndx[4];
  char r_type[2];
  char r_offset[4];
};

#define RELOC struct external_reloc
#define RELSZ 14

#define ARM_NOTE_SECTION ".note"
