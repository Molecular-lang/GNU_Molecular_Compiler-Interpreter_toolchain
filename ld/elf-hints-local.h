#ifndef	_ELF_HINTS_H_
#define	_ELF_HINTS_H_

#include <stdint.h>

/* Hints file produced by ldconfig.  */
struct elfhints_hdr
{
  uint32_t magic;		/* Magic number.  */
  uint32_t version;		/* File version (1).  */
  uint32_t strtab;		/* Offset of string table in file.  */
  uint32_t strsize;		/* Size of string table.  */
  uint32_t dirlist;		/* Offset of directory list in string table.  */
  uint32_t dirlistlen;		/* strlen(dirlist).  */
  uint32_t spare[26];		/* Room for expansion.  */
};

#define ELFHINTS_MAGIC	0x746e6845

#define _PATH_ELF_HINTS	"/var/run/ld-elf.so.hints"

#endif /* !_ELF_HINTS_H_ */
