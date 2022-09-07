// Prototypes for GLIBC thread locale __-prefixed functions -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <bits/c++config.h>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <cstddef>
#include <langinfo.h>

#include <vector>
#include <string.h>	// ::strdup

#include <ext/concurrence.h>

#if __GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ > 2)

extern "C" __typeof(nl_langinfo_l) __nl_langinfo_l;
extern "C" __typeof(strcoll_l) __strcoll_l;
extern "C" __typeof(strftime_l) __strftime_l;
extern "C" __typeof(strtod_l) __strtod_l;
extern "C" __typeof(strtof_l) __strtof_l;
extern "C" __typeof(strtold_l) __strtold_l;
extern "C" __typeof(strxfrm_l) __strxfrm_l;
extern "C" __typeof(newlocale) __newlocale;
extern "C" __typeof(freelocale) __freelocale;
extern "C" __typeof(duplocale) __duplocale;
extern "C" __typeof(uselocale) __uselocale;

#ifdef _GLIBCXX_USE_WCHAR_T
extern "C" __typeof(iswctype_l) __iswctype_l;
extern "C" __typeof(towlower_l) __towlower_l;
extern "C" __typeof(towupper_l) __towupper_l;
extern "C" __typeof(wcscoll_l) __wcscoll_l;
extern "C" __typeof(wcsftime_l) __wcsftime_l;
extern "C" __typeof(wcsxfrm_l) __wcsxfrm_l;
extern "C" __typeof(wctype_l) __wctype_l;
#endif

#endif // GLIBC 2.3 and later

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  struct Catalog_info
  {
    Catalog_info(messages_base::catalog __id, const char* __domain,
		 locale __loc)
      : _M_id(__id), _M_domain(strdup(__domain)), _M_locale(__loc)
    { }

    ~Catalog_info()
    { free(_M_domain); }

    messages_base::catalog _M_id;
    char* _M_domain;
    locale _M_locale;

  private:
    Catalog_info(const Catalog_info&);

    Catalog_info&
    operator=(const Catalog_info&);
  };

  class Catalogs
  {
  public:
    Catalogs() : _M_catalog_counter(0) { }
    ~Catalogs();

    messages_base::catalog
    _M_add(const char* __domain, locale __l);

    void
    _M_erase(messages_base::catalog __c);

    const Catalog_info*
    _M_get(messages_base::catalog __c) const;

  private:
    mutable __gnu_cxx::__mutex _M_mutex;
    messages_base::catalog _M_catalog_counter;
    vector<Catalog_info*> _M_infos;
  };

  Catalogs&
  get_catalogs();

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
