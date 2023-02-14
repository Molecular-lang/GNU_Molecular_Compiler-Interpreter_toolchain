/* coff information for Texas Instruments TMS320C3X */

#define L_LNNO_SIZE 4
#include "coff/external.h"

#define	TIC30MAGIC	0xC000

#define TIC30BADMAG(x) (((x).f_magic != TIC30MAGIC))

/********************** RELOCATION DIRECTIVES **********************/

/* The external reloc has an offset field, because some of the reloc
   types on the z8k don't have room in the instruction for the entire
   offset - eg with segments */

struct external_reloc
{
  char r_vaddr[4];
  char r_symndx[4];
  char r_offset[4];
  char r_type[2];
  char r_stuff[2];
};

#define RELOC struct external_reloc
#define RELSZ 16

/* TMS320C30 relocation types.  */

#define R_TIC30_ABS16 0x100  /* 16 bit absolute. */
#define R_TIC30_ABS24 0x101  /* 24 bit absolute. */
#define R_TIC30_ABS32 0x102  /* 32 bit absolute. */
#define R_TIC30_LDP   0x103  /* LDP bits 23-16 to 7-0. */
#define R_TIC30_PC16  0x104  /* 16 bit pc relative. */
