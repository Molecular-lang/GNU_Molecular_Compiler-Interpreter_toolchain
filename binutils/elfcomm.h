/* elfcomm.h -- include file of common code for ELF format file. */

#ifndef _ELFCOMM_H
#define _ELFCOMM_H

#include "aout/ar.h"

extern void error (const char *, ...) ATTRIBUTE_PRINTF_1;
extern void warn (const char *, ...) ATTRIBUTE_PRINTF_1;

typedef unsigned HOST_WIDEST_INT elf_vma;

extern void (*byte_put) (unsigned char *, elf_vma, unsigned int);
extern void byte_put_little_endian (unsigned char *, elf_vma, unsigned int);
extern void byte_put_big_endian (unsigned char *, elf_vma, unsigned int);

extern elf_vma (*byte_get) (const unsigned char *, unsigned int);
extern elf_vma byte_get_signed (const unsigned char *, unsigned int);
extern elf_vma byte_get_little_endian (const unsigned char *, unsigned int);
extern elf_vma byte_get_big_endian (const unsigned char *, unsigned int);

#define BYTE_PUT(field, val)	byte_put (field, val, sizeof (field))
#define BYTE_GET(field)		byte_get (field, sizeof (field))
#define BYTE_GET_SIGNED(field)	byte_get_signed (field, sizeof (field))

/* This is just a bit of syntatic sugar.  */
#define streq(a,b)	  (strcmp ((a), (b)) == 0)

/* Structure to hold information about an archive file.  */

struct archive_info
{
  char * file_name;                     /* Archive file name.  */
  FILE * file;                          /* Open file descriptor.  */
  elf_vma index_num;                    /* Number of symbols in table.  */
  elf_vma * index_array;                /* The array of member offsets.  */
  char * sym_table;                     /* The symbol table.  */
  unsigned long sym_size;               /* Size of the symbol table.  */
  char * longnames;                     /* The long file names table.  */
  unsigned long longnames_size;         /* Size of the long file names table.  */
  unsigned long nested_member_origin;   /* Origin in the nested archive of the current member.  */
  unsigned long next_arhdr_offset;      /* Offset of the next archive header.  */
  int is_thin_archive;                  /* 1 if this is a thin archive.  */
  int uses_64bit_indices;               /* 1 if the index table uses 64bit entries.  */
  struct ar_hdr arhdr;                  /* Current archive header.  */
};

/* Return the path name for a proxy entry in a thin archive.  */
extern char *adjust_relative_path (const char *, const char *, unsigned long);

/* Read the symbol table and long-name table from an archive.  */
extern int setup_archive (struct archive_info *, const char *, FILE *,
			  off_t, int, int);

/* Open and setup a nested archive, if not already open.  */
extern int setup_nested_archive (struct archive_info *, const char *);

/* Release the memory used for the archive information.  */
extern void release_archive (struct archive_info *);

/* Get the name of an archive member from the current archive header.  */

extern char *get_archive_member_name (struct archive_info *,
				      struct archive_info *);

/* Get the name of an archive member at a given offset within an
   archive.  */

extern char *get_archive_member_name_at (struct archive_info *,
					 unsigned long,
					 struct archive_info *);

/* Construct a string showing the name of the archive member, qualified
   with the name of the containing archive file.  */

extern char *make_qualified_name (struct archive_info *,
				  struct archive_info *,
				  const char *);

#endif /* _ELFCOMM_H */
