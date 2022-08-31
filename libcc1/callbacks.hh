/* Callback management
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef CC1_PLUGIN_CALLBACKS_HH
#define CC1_PLUGIN_CALLBACKS_HH

#include "status.hh"
#include "hashtab.h"

namespace cc1_plugin
{
  class connection;

  // The type of a callback method.
  typedef status callback_ftype (connection *);

  // This class manages callback functions.  A callback has a name and
  // an underlying function.  When a query packet arrives, the name is
  // inspected and the corresponding function is called.  A callback
  // function has to know how to decode its own arguments, but
  // wrappers are provided elsewhere to automate this.
  class callbacks
  {
  public:

    callbacks ();
    ~callbacks ();

    callbacks (const callbacks &) = delete;
    callbacks &operator= (const callbacks &) = delete;

    // Add a callback named NAME.  FUNC is the function to call when
    // this method is invoked.
    void add_callback (const char *name, callback_ftype *func);

    // Look up a callback by name.  Returns NULL if the method is not
    // found.
    callback_ftype *find_callback (const char *name);

  private:

    // The mapping.
    htab_t m_registry;
  };
};

#endif // CC1_PLUGIN_CALLBACKS_HH
