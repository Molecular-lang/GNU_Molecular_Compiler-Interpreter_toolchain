/* Interface for high-level plugins in GCC - Parts common between GCC,
   ICI and high-level plugins.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef HIGHLEV_PLUGIN_COMMON_H
#define HIGHLEV_PLUGIN_COMMON_H

/* Return codes for invoke_plugin_callbacks / call_plugin_event .  */
#define PLUGEVT_SUCCESS         0
#define PLUGEVT_NO_EVENTS       1
#define PLUGEVT_NO_SUCH_EVENT   2
#define PLUGEVT_NO_CALLBACK     3

#endif /* HIGHLEV_PLUGIN_COMMON_H */
