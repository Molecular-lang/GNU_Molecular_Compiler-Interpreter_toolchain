/* Generate from machine description:
   a series of #define statements, one for each constant named in
   a (define_constants ...) pattern.
 */

/* This program does not use gensupport.cc because it does not need to
   look at insn patterns, only (define_constants), and we want to
   minimize dependencies.  */

#include "bconfig.h"
#include "system.h"
#include "coretypes.h"
#include "errors.h"
#include "statistics.h"
#include "vec.h"
#include "read-md.h"

/* Called via traverse_md_constants; emit a #define for
   the current constant definition.  */

static int
print_md_constant (void **slot, void *info ATTRIBUTE_UNUSED)
{
  struct md_constant *def = (struct md_constant *) *slot;

  if (!def->parent_enum)
    printf ("#define %s %s\n", def->name, def->value);
  return 1;
}

/* Called via traverse_enums.  Emit an enum definition for
   enum_type *SLOT.  */

static int
print_enum_type (void **slot, void *info ATTRIBUTE_UNUSED)
{
  struct enum_type *def;
  struct enum_value *value;
  char *value_name;

  def = (struct enum_type *) *slot;
  printf ("\nenum %s {", def->name);
  for (value = def->values; value; value = value->next)
    {
      printf ("\n  %s = %s", value->def->name, value->def->value);
      if (value->next)
	putc (',', stdout);
    }
  printf ("\n};\n");

  /* Define NUM_<enum>_VALUES to be the largest enum value + 1.  */
  value_name = ACONCAT (("num_", def->name, "_values", NULL));
  upcase_string (value_name);
  printf ("#define %s %d\n", value_name, def->num_values);

  /* Declare the array that is generated by genenum.  */
  printf ("extern const char *const %s_strings[];\n", def->name);

  return 1;
}

int
main (int argc, const char **argv)
{
  progname = "genconstants";

  noop_reader reader;
  if (!reader.read_md_files (argc, argv, NULL))
    return (FATAL_EXIT_CODE);

  /* Initializing the MD reader has the side effect of loading up
     the constants table that we wish to scan.  */

  puts ("/* Generated automatically by the program `genconstants'");
  puts ("   from the machine description file `md'.  */\n");
  puts ("#ifndef GCC_INSN_CONSTANTS_H");
  puts ("#define GCC_INSN_CONSTANTS_H\n");

  reader.traverse_md_constants (print_md_constant, 0);
  reader.traverse_enum_types (print_enum_type, 0);

  puts ("\n#endif /* GCC_INSN_CONSTANTS_H */");

  if (ferror (stdout) || fflush (stdout) || fclose (stdout))
    return FATAL_EXIT_CODE;

  return SUCCESS_EXIT_CODE;
}