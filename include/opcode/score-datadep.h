/* score-datadep.h -- Score Instructions data dependency table */

#ifndef SCORE_DATA_DEPENDENCY_H
#define SCORE_DATA_DEPENDENCY_H

#define INSN_NAME_LEN 16

enum insn_type_for_dependency
{
  D_mtcr,
  D_all_insn
};

struct insn_to_dependency
{
  char *insn_name;
  enum insn_type_for_dependency type;
};

struct data_dependency
{
  enum insn_type_for_dependency pre_insn_type;
  char pre_reg[6];
  enum insn_type_for_dependency cur_insn_type;
  char cur_reg[6];
  int bubblenum_7;
  int bubblenum_3;
  int warn_or_error;           /* warning - 0; error - 1  */
};

static const struct insn_to_dependency insn_to_dependency_table[] =
{
  /* move spectial instruction.  */
  {"mtcr",      D_mtcr},
};

static const struct data_dependency data_dependency_table[] =
{
  /* Status regiser.  */
  {D_mtcr, "cr0", D_all_insn, "", 5, 1, 0},
};

#endif
