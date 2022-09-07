/* Please review: $(src-dir)/SPL-README for Licencing info. */

struct objdump_private_option
{
  /* Option name.  */
  const char *name;

  /* TRUE if the option is selected.  Automatically set and cleared by
     objdump.  */
  unsigned int selected;
};

struct objdump_private_desc
{
  /* Help displayed for --help.  */
  void (*help)(FILE *stream);

  /* Return TRUE if these options can be applied to ABFD.  */
  int (*filter)(bfd *abfd);

  /* Do the actual work: display whatever is requested according to the
     options whose SELECTED field is set.  */
  void (*dump)(bfd *abfd);

  /* List of options.  Terminated by a NULL name.  */
  struct objdump_private_option *options;
};
/* ELF32_AVR specific target.  */
extern const struct objdump_private_desc objdump_private_desc_elf32_avr;

/* XCOFF specific target.  */
extern const struct objdump_private_desc objdump_private_desc_xcoff;

/* Mach-O specific target.  */
extern const struct objdump_private_desc objdump_private_desc_mach_o;
