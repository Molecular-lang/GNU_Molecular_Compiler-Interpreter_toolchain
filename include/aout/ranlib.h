/* ranlib.h -- archive library index member definition for GNU. */

/* The Symdef member of an archive contains two things:
   a table that maps symbol-string offsets to file offsets,
   and a symbol-string table.  All the symbol names are
   run together (each with trailing null) in the symbol-string
   table.  There is a single longword bytecount on the front
   of each of these tables.  Thus if we have two symbols,
   "foo" and "_bar", that are in archive members at offsets
   200 and 900, it would look like this:
        16		; byte count of index table
  	0		; offset of "foo" in string table
  	200		; offset of foo-module in file
  	4		; offset of "bar" in string table
  	900		; offset of bar-module in file
  	9		; byte count of string table
  	"foo\0_bar\0"	; string table  */

#define	RANLIBMAG	"__.SYMDEF"	/* Archive file name containing index */
#define	RANLIBSKEW	3		/* Creation time offset */

/* Format of __.SYMDEF:
   First, a longword containing the size of the 'symdef' data that follows.
   Second, zero or more 'symdef' structures.
   Third, a longword containing the length of symbol name strings.
   Fourth, zero or more symbol name strings (each followed by a null).  */

struct symdef
  {
    union
      {
	unsigned long string_offset;	/* In the file */
	char *name;			/* In memory, sometimes */
      } s;
    /* this points to the front of the file header (AKA member header --
       a struct ar_hdr), not to the front of the file or into the file).
       in other words it only tells you which file to read */       
    unsigned long file_offset;
  };

/* Compatability with BSD code */

#define	ranlib	symdef
#define	ran_un	s
#define	ran_strx string_offset
#define	ran_name name
#define	ran_off	file_offset
