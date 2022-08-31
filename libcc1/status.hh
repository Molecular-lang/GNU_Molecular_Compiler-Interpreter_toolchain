/* status type definition
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef CC1_PLUGIN_STATUS_HH
#define CC1_PLUGIN_STATUS_HH

namespace cc1_plugin
{
  // The status returned by various connection functions.
  enum status
  {
    FAIL = 0,
    OK = 1
  };
}

#endif // CC1_PLUGIN_STATUS_HH
