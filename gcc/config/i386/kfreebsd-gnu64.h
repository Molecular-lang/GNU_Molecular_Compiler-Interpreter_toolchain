/* Definitions for AMD x86-64 running kFreeBSD-based GNU systems with ELF format
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define GNU_USER_LINK_EMULATION32 "elf_i386_fbsd"
#define GNU_USER_LINK_EMULATION64 "elf_x86_64_fbsd"
#define GNU_USER_LINK_EMULATIONX32 "elf32_x86_64_fbsd"

#define GLIBC_DYNAMIC_LINKER32 "/lib/ld.so.1"
#define GLIBC_DYNAMIC_LINKER64 "/lib/ld-kfreebsd-x86-64.so.1"
#define GLIBC_DYNAMIC_LINKERX32 "/lib/ld-kfreebsd-x32.so.1"
