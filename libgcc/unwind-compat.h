/* Backward compatibility unwind routines. */

#define symver(name, version) \
  __asm__ (".symver " #name"," #name "@" #version)

#define alias(name) \
  __typeof(name) __libunwind##name __attribute__ ((alias (#name)))
