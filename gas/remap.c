/* Remap file names for debug info for GNU assembler.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "as.h"
#include "filenames.h"

/* Structure recording the mapping from source file and directory
   names at compile time to those to be embedded in debug
   information.  */
typedef struct debug_prefix_map
{
  const char *old_prefix;
  const char *new_prefix;
  size_t old_len;
  size_t new_len;
  struct debug_prefix_map *next;
} debug_prefix_map;

/* Linked list of such structures.  */
debug_prefix_map *debug_prefix_maps;


/* Record a debug file prefix mapping.  ARG is the argument to
   -fdebug-prefix-map and must be of the form OLD=NEW.  */

void
add_debug_prefix_map (const char *arg)
{
  debug_prefix_map *map;
  const char *p;
  char *o;

  p = strchr (arg, '=');
  if (!p)
    {
      as_fatal (_("invalid argument '%s' to -fdebug-prefix-map"), arg);
      return;
    }
  map = XNEW (debug_prefix_map);
  o = xstrdup (arg);
  map->old_prefix = o;
  map->old_len = p - arg;
  o[map->old_len] = 0;
  p++;
  map->new_prefix = xstrdup (p);
  map->new_len = strlen (p);
  map->next = debug_prefix_maps;
  debug_prefix_maps = map;
}

/* Perform user-specified mapping of debug filename prefixes.  Returns
   a newly allocated buffer containing the name corresponding to FILENAME.
   It is the caller's responsibility to free the buffer.  */

const char *
remap_debug_filename (const char *filename)
{
  debug_prefix_map *map;

  for (map = debug_prefix_maps; map; map = map->next)
    if (filename_ncmp (filename, map->old_prefix, map->old_len) == 0)
      {
	const char *name = filename + map->old_len;
	return concat (map->new_prefix, name, NULL);
      }
	
  return xstrdup (filename);
}
