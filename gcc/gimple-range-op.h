/* Header file for the GIMPLE range-op interface. */

#ifndef GCC_GIMPLE_RANGE_OP_H
#define GCC_GIMPLE_RANGE_OP_H

#include "range-op.h"


class gimple_range_op_handler : public range_op_handler
{
public:
  static bool supported_p (gimple *s);
  gimple_range_op_handler (gimple *s);
  inline gimple *stmt () const { return m_stmt; }
  inline tree lhs () const { return gimple_get_lhs (m_stmt); }
  tree operand1 () const { gcc_checking_assert (m_valid); return m_op1; }
  tree operand2 () const { gcc_checking_assert (m_valid); return m_op2; }
  bool calc_op1 (vrange &r, const vrange &lhs_range);
  bool calc_op1 (vrange &r, const vrange &lhs_range, const vrange &op2_range,
		 relation_trio = TRIO_VARYING);
  bool calc_op2 (vrange &r, const vrange &lhs_range, const vrange &op1_range,
		 relation_trio = TRIO_VARYING);
private:
  void maybe_builtin_call ();
  gimple *m_stmt;
  tree m_op1, m_op2;
};

// Given stmt S, fill VEC, up to VEC_SIZE elements, with relevant ssa-names
// on the statement.  For efficiency, it is an error to not pass in enough
// elements for the vector.  Return the number of ssa-names.

unsigned gimple_range_ssa_names (tree *vec, unsigned vec_size, gimple *stmt);

#endif // GCC_GIMPLE_RANGE_OP_H
