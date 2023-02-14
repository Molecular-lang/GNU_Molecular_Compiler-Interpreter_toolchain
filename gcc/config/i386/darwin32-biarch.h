/* Target definitions for i386 running Darwin with a 32b host and supporting
   a 64b multilib.
 */

#undef DARWIN_ARCH_SPEC
#define DARWIN_ARCH_SPEC "%{m64:x86_64;:i386}"

#define TARGET_64BIT_DEFAULT 0
#define TARGET_BI_ARCH 1

#undef  DARWIN_SUBARCH_SPEC
#define DARWIN_SUBARCH_SPEC DARWIN_ARCH_SPEC

#undef SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS                                   \
  DARWIN_EXTRA_SPECS                                            \
  { "darwin_arch", DARWIN_ARCH_SPEC },                          \
  { "darwin_crt2", "" },                                        \
  { "darwin_subarch", DARWIN_SUBARCH_SPEC },
