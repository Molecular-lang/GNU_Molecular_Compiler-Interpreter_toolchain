/* Selftests for the analyzer.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_SELFTESTS_H
#define GCC_ANALYZER_SELFTESTS_H

#if CHECKING_P

namespace ana {

namespace selftest {

extern tree build_global_decl (const char *name, tree type);

extern void run_analyzer_selftests ();

/* Declarations for specific families of tests (by source file), in
   alphabetical order.  */
extern void analyzer_checker_script_cc_tests ();
extern void analyzer_constraint_manager_cc_tests ();
extern void analyzer_function_set_cc_tests ();
extern void analyzer_program_point_cc_tests ();
extern void analyzer_program_state_cc_tests ();
extern void analyzer_region_model_cc_tests ();
extern void analyzer_sm_file_cc_tests ();
extern void analyzer_sm_signal_cc_tests ();
extern void analyzer_store_cc_tests ();

} /* end of namespace ana::selftest.  */

} // namespace ana

#endif /* #if CHECKING_P */

#endif /* GCC_ANALYZER_SELFTESTS_H */
