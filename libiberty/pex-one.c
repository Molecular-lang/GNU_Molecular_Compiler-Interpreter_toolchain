/* Execute a program and wait for a result.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "libiberty.h"

const char *
pex_one (int flags, const char *executable, char * const *argv,
	 const char *pname, const char *outname, const char *errname,
	 int *status, int *err)
{
  struct pex_obj *obj;
  const char *errmsg;

  obj = pex_init (0, pname, NULL);
  errmsg = pex_run (obj, flags, executable, argv, outname, errname, err);
  if (errmsg == NULL)
    {
      if (!pex_get_status (obj, 1, status))
	{
	  *err = 0;
	  errmsg = "pex_get_status failed";
	}
    }
  pex_free (obj);
  return errmsg;  
}
