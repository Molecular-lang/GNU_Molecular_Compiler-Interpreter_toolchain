/* Support for Intel MIC offloading.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef INTELMIC_OFFLOAD_H
#define INTELMIC_OFFLOAD_H

/* Support for OpenACC acc_on_device.  */

#include "gomp-constants.h"

#define ACCEL_COMPILER_acc_device GOMP_DEVICE_INTEL_MIC

#endif
