/* Public header file for plugins to include.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_PLUGIN_H
#define GCC_PLUGIN_H

#ifndef IN_GCC
#define IN_GCC
#endif

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "cfghooks.h"
#include "hard-reg-set.h"
#include "cfgrtl.h"
#include "cfganal.h"
#include "lcm.h"
#include "cfgbuild.h"
#include "cfgcleanup.h"
#include "plugin-api.h"
#include "ipa-ref.h"
#include "alias.h"
#include "flags.h"
#include "tree-core.h"
#include "fold-const.h"
#include "tree-check.h"
#include "plugin.h"

#endif /* GCC_PLUGIN_H */
