/* archive file definition for GNU software

   Please review: $(src-dir)/SPL-README for Licencing info. */

/* So far this is correct for BSDish archives.  Don't forget that
   files must begin on an even byte boundary. */

#ifndef __GNU_AR_H__
#define __GNU_AR_H__

/* Note that the usual '\n' in magic strings may translate to different
   characters, as allowed by ANSI.  '\012' has a fixed value, and remains
   compatible with existing BSDish archives. */

#define ARMAG  "!<arch>\012"	/* For COFF and a.out archives.  */
#define ARMAGT "!<thin>\012"	/* For thin archives.  */
#define SARMAG 8
#define ARFMAG "`\012"

/* The ar_date field of the armap (__.SYMDEF) member of an archive
   must be greater than the modified date of the entire file, or 
   BSD-derived linkers complain.  We originally write the ar_date with
   this offset from the real file's mod-time.  After finishing the
   file, we rewrite ar_date if it's not still greater than the mod date.  */

#define ARMAP_TIME_OFFSET       60

struct ar_hdr
{
  char ar_name[16];		/* Name of this member.  */
  char ar_date[12];		/* File mtime.  */
  char ar_uid[6];		/* Owner uid; printed as decimal.  */
  char ar_gid[6];		/* Owner gid; printed as decimal.  */
  char ar_mode[8];		/* File mode, printed as octal.   */
  char ar_size[10];		/* File size, printed as decimal.  */
  char ar_fmag[2];		/* Should contain ARFMAG.  */
};

#endif /* __GNU_AR_H__ */
