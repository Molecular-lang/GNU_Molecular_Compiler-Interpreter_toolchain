/* output-file.c -  Deal with the output file
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "as.h"
#include "output-file.h"

#ifndef TARGET_MACH
#define TARGET_MACH 0
#endif

bfd *stdoutput;

void
output_file_create (const char *name)
{
  if (name[0] == '-' && name[1] == '\0')
    as_fatal (_("can't open a bfd on stdout %s"), name);

  else if (!(stdoutput = bfd_openw (name, TARGET_FORMAT)))
    {
      bfd_error_type err = bfd_get_error ();

      if (err == bfd_error_invalid_target)
	as_fatal (_("selected target format '%s' unknown"), TARGET_FORMAT);
      else
	as_fatal (_("can't create %s: %s"), name, bfd_errmsg (err));
    }

  bfd_set_format (stdoutput, bfd_object);
  bfd_set_arch_mach (stdoutput, TARGET_ARCH, TARGET_MACH);
  if (flag_traditional_format)
    stdoutput->flags |= BFD_TRADITIONAL_FORMAT;
}

void
output_file_close (const char *filename)
{
  bool res;

  if (stdoutput == NULL)
    return;

  /* Close the bfd.  */
  if (!flag_always_generate_output && had_errors ())
    res = bfd_cache_close_all ();
  else
    res = bfd_close (stdoutput);

  /* Prevent an infinite loop - if the close failed we will call as_fatal
     which will call xexit() which may call this function again...  */
  stdoutput = NULL;

  if (! res)
    as_fatal ("%s: %s", filename, bfd_errmsg (bfd_get_error ()));
}
