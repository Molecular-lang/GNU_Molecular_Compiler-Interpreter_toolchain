/* VxWorks support for ELF
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "elf/common.h"
#include "elf/internal.h"

bool elf_vxworks_add_symbol_hook
  (bfd *, struct bfd_link_info *, Elf_Internal_Sym *, const char **,
   flagword *, asection **, bfd_vma *);
int elf_vxworks_link_output_symbol_hook
  (struct bfd_link_info *, const char *name, Elf_Internal_Sym *,
   asection *, struct elf_link_hash_entry *);
bool elf_vxworks_emit_relocs
  (bfd *, asection *, Elf_Internal_Shdr *, Elf_Internal_Rela *,
   struct elf_link_hash_entry **);
bool elf_vxworks_final_write_processing (bfd *);
bool elf_vxworks_create_dynamic_sections
  (bfd *, struct bfd_link_info *, asection **);
bool elf_vxworks_add_dynamic_entries (bfd *, struct bfd_link_info *);
bool elf_vxworks_finish_dynamic_entry (bfd *, Elf_Internal_Dyn *);
bool _bfd_elf_maybe_vxworks_add_dynamic_tags
  (bfd *, struct bfd_link_info *, bool);
