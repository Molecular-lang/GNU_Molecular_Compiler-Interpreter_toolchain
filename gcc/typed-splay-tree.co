/* Selftests for typed-splay-tree.h.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "typed-splay-tree.h"
#include "selftest.h"

#if CHECKING_P

namespace selftest {

/* Callback for use by test_str_to_int.  */

static int
append_cb (const char *, int value, void *user_data)
{
  auto_vec <int> *vec = (auto_vec <int> *)user_data;
  vec->safe_push (value);
  return 0;
}

/* Test of typed_splay_tree <const char *, int>.  */

static void
test_str_to_int ()
{
  typed_splay_tree <const char *, int> t (strcmp, NULL, NULL);

  t.insert ("a", 1);
  t.insert ("b", 2);
  t.insert ("c", 3);
  t.insert ("d", 4);

  t.remove ("d");

  ASSERT_EQ (1, t.lookup ("a"));
  ASSERT_EQ (2, t.lookup ("b"));
  ASSERT_EQ (3, t.lookup ("c"));

  ASSERT_EQ (2, t.predecessor ("c"));
  ASSERT_EQ (3, t.successor ("b"));
  ASSERT_EQ (1, t.min ());
  ASSERT_EQ (3, t.max ());

  /* Test foreach by appending to a vec, and verifying the vec.  */
  auto_vec <int> v;
  t.foreach (append_cb, &v);
  ASSERT_EQ (3, v.length ());
  ASSERT_EQ (1, v[0]);
  ASSERT_EQ (2, v[1]);
  ASSERT_EQ (3, v[2]);
}

/* Run all of the selftests within this file.  */

void
typed_splay_tree_cc_tests ()
{
  test_str_to_int ();
}

} // namespace selftest

#endif /* #if CHECKING_P */
