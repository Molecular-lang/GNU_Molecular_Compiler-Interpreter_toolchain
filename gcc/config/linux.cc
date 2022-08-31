/* Functions for Linux Android as target machine for GNU C compiler.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "linux-protos.h"

bool
linux_libc_has_function (enum function_class fn_class, tree type ATTRIBUTE_UNUSED)
{
	if (OPTION_GLIBC || OPTION_MUSL)
		return true;
	if (OPTION_BIONIC)
		if (fn_class == function_c94 || fn_class == function_c99_misc || fn_class == function_sincos)
			return true;

	return false;
}
