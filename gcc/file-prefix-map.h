/* Declarations for file prefix remapping support (-f*-prefix-map options).
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_FILE_PREFIX_MAP_H
#define GCC_FILE_PREFIX_MAP_H

void add_macro_prefix_map (const char *);
void add_debug_prefix_map (const char *);
void add_file_prefix_map (const char *);
void add_profile_prefix_map (const char *);

const char *remap_macro_filename (const char *);
const char *remap_debug_filename (const char *);
const char *remap_profile_filename (const char *);

#endif /* !GCC_FILE_PREFIX_MAP_H  */
