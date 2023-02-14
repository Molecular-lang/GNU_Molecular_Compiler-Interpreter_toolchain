/* Definitions for Intel 386 running Linux-based GNU systems with ELF format. */

#define GNU_USER_LINK_EMULATION "elf_i386"
#define GLIBC_DYNAMIC_LINKER "/lib/ld-linux.so.2"

#undef MUSL_DYNAMIC_LINKER
#define MUSL_DYNAMIC_LINKER "/lib/ld-musl-i386.so.1"
