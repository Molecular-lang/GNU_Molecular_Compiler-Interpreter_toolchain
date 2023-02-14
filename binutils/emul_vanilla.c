/* Binutils emulation layer. */

#include "binemul.h"

struct bin_emulation_xfer_struct bin_vanilla_emulation =
{
  ar_emul_default_usage,
  ar_emul_default_append,
  ar_emul_default_replace,
  ar_emul_default_parse_arg,
};
