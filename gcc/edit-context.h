/* Determining the results of applying fix-it hints.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_EDIT_CONTEXT_H
#define GCC_EDIT_CONTEXT_H

#include "typed-splay-tree.h"

class edit_context;
class edited_file;

/* A set of changes to the source code.

   The changes are "atomic" - if any changes can't be applied,
   none of them can be (tracked by the m_valid flag).
   Similarly, attempts to add the changes from a rich_location flagged
   as containing invalid changes mean that the whole of the edit_context
   is flagged as invalid.

   A complication here is that fix-its are expressed relative to coordinates
   in the files when they were parsed, before any changes have been made, and
   so if there's more that one fix-it to be applied, we have to adjust
   later fix-its to allow for the changes made by earlier ones.  This
   is done by the various "get_effective_column" methods.  */

class edit_context
{
 public:
  edit_context ();

  bool valid_p () const { return m_valid; }

  void add_fixits (rich_location *richloc);

  char *get_content (const char *filename);

  int get_effective_column (const char *filename, int line, int column);

  char *generate_diff (bool show_filenames);
  void print_diff (pretty_printer *pp, bool show_filenames);

 private:
  bool apply_fixit (const fixit_hint *hint);
  edited_file *get_file (const char *filename);
  edited_file &get_or_insert_file (const char *filename);

  bool m_valid;
  typed_splay_tree<const char *, edited_file *> m_files;
};

#endif /* GCC_EDIT_CONTEXT_H.  */
