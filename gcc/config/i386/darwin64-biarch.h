/* Target definitions for x86_64 running Darwin with a 64b host supporting a
   32b multilib.
 */

#undef  DARWIN_ARCH_SPEC
#define DARWIN_ARCH_SPEC "%{m32:i386;:x86_64}"

#define TARGET_64BIT_DEFAULT (OPTION_MASK_ISA_64BIT | OPTION_MASK_ABI_64)
#define TARGET_BI_ARCH 1

#undef  DARWIN_SUBARCH_SPEC
#define DARWIN_SUBARCH_SPEC DARWIN_ARCH_SPEC

#undef SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS                                   \
  DARWIN_EXTRA_SPECS                                            \
  { "darwin_arch", DARWIN_ARCH_SPEC },                          \
  { "darwin_crt2", "" },                                        \
  { "darwin_subarch", DARWIN_SUBARCH_SPEC },
