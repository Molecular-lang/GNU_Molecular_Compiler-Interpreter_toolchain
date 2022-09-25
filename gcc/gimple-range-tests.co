/* Unit tests for GIMPLE range related routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#if CHECKING_P

#include "selftest.h"

namespace selftest {

// Test ranges of tree expressions.
class test_expr_eval : public gimple_ranger
{
public:
  test_expr_eval ()
  {
    type = integer_type_node;
    op0 = make_ssa_name (type);
    op1 = make_ssa_name (type);

    // [5,10] + [15,20] => [20, 30]
    tree expr = fold_build2 (PLUS_EXPR, type, op0, op1);
    int_range<2> expect (build_int_cst (type, 20), build_int_cst (type, 30));
    int_range_max r;

    ASSERT_TRUE (range_of_expr (r, expr));
    ASSERT_TRUE (r == expect);
  }

  virtual bool range_of_expr (vrange &v, tree expr, gimple * = NULL) override
  {
    irange &r = as_a <irange> (v);
    if (expr == op0)
      {
	r.set (build_int_cst (type, 5), build_int_cst (type, 10));
	return true;
      }
    if (expr == op1)
      {
	r.set (build_int_cst (type, 15), build_int_cst (type, 20));
	return true;
      }
    return gimple_ranger::range_of_expr (r, expr);
  }

private:
  tree op0, op1, type;
};

void
gimple_range_tests ()
{
  test_expr_eval e;
}

} // namespace selftest

#endif // CHECKING_P
