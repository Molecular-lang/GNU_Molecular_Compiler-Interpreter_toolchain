/* Generate version strings. See gcov-io.h for
   description of how the version string is generated.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bconfig.h"
#include "system.h"

/* Command line arguments are the base GCC version and the development
   phase (the latter may be an empty string).  */

int
main (void)
{
  unsigned int version = 0;
  unsigned char v[4];
  unsigned int ix;
  unsigned long major;
  unsigned long minor = 0;
  char phase = 0;
  char basever[] = BASEVER;
  char *ptr = basever;

  major = strtoul (ptr, &ptr, 10);

  if (*ptr == '.')
    minor = strtoul (ptr + 1, 0, 10);

  /* For releases the development phase is an empty string, for
     prerelease versions on a release branch it is "prerelease".
     Consider both equal as patch-level releases do not change
     the GCOV version either.
     On the trunk the development phase is "experimental".  */
  phase = DEVPHASE[0];
  if (phase == '\0'
      || strcmp (DEVPHASE, "prerelease") == 0)
    phase = '*';

  v[0] = (major / 10) + 'A';
  v[1] = (major % 10) + '0';
  v[2] = minor + '0';
  v[3] = phase;

  for (ix = 0; ix != 4; ix++)
    version = (version << 8) | v[ix];

  printf ("#ifndef VERSION_H\n");
  printf ("#define VERSION_H\n\n");
  printf ("/* Generated automatically by genversion.  */\n");
  printf ("\n");
  printf ("#define GCC_major_version %lu\n\n", major);

  printf ("/* The complete version string, assembled from several pieces.\n"
	  "BASEVER, DATESTAMP, DEVPHASE, and REVISION are defined by the\n"
	  "Makefile.  */\n\n");

  printf ("#define version_string \"" BASEVER DATESTAMP DEVPHASE REVISION "\"\n");
  printf ("#define pkgversion_string \"" PKGVERSION "\"\n\n");

  printf ("/* This is the location of the online document giving instructions for\n"
     "reporting bugs.  If you distribute a modified version of GCC,\n"
     "please configure with --with-bugurl pointing to a document giving\n"
     "instructions for reporting bugs to you, not us.  (You are of course\n"
     "welcome to forward us bugs reported to you, if you determine that\n"
     "they are not bugs in your modifications.)  */\n\n");
  printf ("#define bug_report_url \"" BUGURL "\"\n\n");

  printf ("#define GCOV_VERSION ((gcov_unsigned_t)0x%08x)  /* %.4s */\n",
	  version, v);
  printf ("\n#endif /* VERSION_H */\n");

  return 0;
}
