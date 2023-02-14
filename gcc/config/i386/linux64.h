/* Definitions for AMD x86-64 running Linux-based GNU systems with ELF format. */

#define GNU_USER_LINK_EMULATION32 "elf_i386"
#define GNU_USER_LINK_EMULATION64 "elf_x86_64"
#define GNU_USER_LINK_EMULATIONX32 "elf32_x86_64"

#define GLIBC_DYNAMIC_LINKER32 "/lib/ld-linux.so.2"
#define GLIBC_DYNAMIC_LINKER64 "/lib64/ld-linux-x86-64.so.2"
#define GLIBC_DYNAMIC_LINKERX32 "/libx32/ld-linux-x32.so.2"

#undef MUSL_DYNAMIC_LINKER32
#define MUSL_DYNAMIC_LINKER32 "/lib/ld-musl-i386.so.1"
#undef MUSL_DYNAMIC_LINKER64
#define MUSL_DYNAMIC_LINKER64 "/lib/ld-musl-x86_64.so.1"
#undef MUSL_DYNAMIC_LINKERX32
#define MUSL_DYNAMIC_LINKERX32 "/lib/ld-musl-x32.so.1"
