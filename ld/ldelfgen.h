/* Emulation code used by all ELF targets. */

struct elf_internal_sym;
struct elf_strtab_hash;
struct ctf_dict;

extern void ldelf_map_segments (bool);
extern int ldelf_emit_ctf_early (void);
extern void ldelf_acquire_strings_for_ctf
  (struct ctf_dict *ctf_output, struct elf_strtab_hash *strtab);
extern void ldelf_new_dynsym_for_ctf
  (struct ctf_dict *ctf_output, int symidx, struct elf_internal_sym *sym);
