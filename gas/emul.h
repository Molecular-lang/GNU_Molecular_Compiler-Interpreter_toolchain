/* emul.h.  File format emulation routines
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef EMUL_DEFS
#define EMUL_DEFS

struct emulation
  {
    void (*match) (const char *);
    const char *name;
    void (*init) (void);
    const char *(*bfd_name) (void);
    unsigned local_labels_fb : 1;
    unsigned local_labels_dollar : 1;
    unsigned leading_underscore : 2;
    unsigned default_endian : 2;
    const char *fake_label_name;
    const struct format_ops *format;
  };

COMMON struct emulation * this_emulation;

extern const char * default_emul_bfd_name (void);
extern void common_emul_init (void);

#endif
