/* Definitions for decoding the picoJava opcode table. */

/* Names used to describe the type of instruction arguments, used by
   the assembler and disassembler.  Attributes are encoded in various fields. */

/*            reloc  size pcrel    uns */
#define O_N    0
#define O_16  (1<<4 | 2 | (0<<6) | (0<<3))
#define O_U16 (1<<4 | 2 | (0<<6) | (1<<3))
#define O_R16 (2<<4 | 2 | (1<<6) | (0<<3))
#define O_8   (3<<4 | 1 | (0<<6) | (0<<3))
#define O_U8  (3<<4 | 1 | (0<<6) | (1<<3))
#define O_R8  (4<<4 | 1 | (0<<6) | (0<<3))
#define O_R32 (5<<4 | 4 | (1<<6) | (0<<3))
#define O_32  (6<<4 | 4 | (0<<6) | (0<<3))

#define ASIZE(x)  ((x) & 0x7)
#define PCREL(x)  (!!((x) & (1<<6)))
#define UNS(x)    (!!((x) & (1<<3)))

                  
typedef struct pj_opc_info_t
{
  short opcode;
  short opcode_next;
  char len;
  unsigned char arg[2];
  union {
    const char *name;
    void (*func) (struct pj_opc_info_t *, char *);
  } u;
} pj_opc_info_t;
