/* Deleter objects
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef CC1_PLUGIN_DELETER_HH
#define CC1_PLUGIN_DELETER_HH

#include <memory>

namespace cc1_plugin
{
  // Any pointer type requires a deleter object that knows how to
  // clean up.  These are used in multiple places.
  template<typename T> struct deleter;

  template<>
  struct deleter<char>
  {
    void operator() (char *s)
    {
      delete[] s;
    }
  };

  template<>
  struct deleter<gcc_type_array>
  {
    void operator() (gcc_type_array *p)
    {
      delete[] p->elements;
      delete p;
    }
  };

  template<typename T> using unique_ptr = std::unique_ptr<T, deleter<T>>;
}

#endif // CC1_PLUGIN_DELETER_HH
