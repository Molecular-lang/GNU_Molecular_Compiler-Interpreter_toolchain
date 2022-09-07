/* Plugin support for BFD.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#ifndef _PLUGIN_H_
#define _PLUGIN_H_

void bfd_plugin_set_program_name (const char *);
int bfd_plugin_open_input (bfd *, struct ld_plugin_input_file *);
void bfd_plugin_set_plugin (const char *);
bool bfd_plugin_target_p (const bfd_target *);
bool bfd_plugin_specified_p (void);
bool bfd_link_plugin_object_p (bfd *);
void register_ld_plugin_object_p (bfd_cleanup (*object_p) (bfd *));
void bfd_plugin_close_file_descriptor (bfd *, int);

typedef struct plugin_data_struct
{
  int nsyms;
  const struct ld_plugin_symbol *syms;
}
plugin_data_struct;

#endif
