/* Pass to detect and issue warnings for invalid accesses, including
   invalid or mismatched allocation/deallocation calls.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLE_SSA_WARN_ACCESS_H
#define GCC_GIMPLE_SSA_WARN_ACCESS_H

extern bool check_nul_terminated_array (tree, tree, tree = NULL_TREE);
extern void warn_string_no_nul (location_t, gimple *, const char *, tree,
				tree, tree = NULL_TREE, bool = false,
				const wide_int[2] = NULL);
extern void warn_string_no_nul (location_t, tree, const char *, tree,
				tree, tree = NULL_TREE, bool = false,
				const wide_int[2] = NULL);
extern tree unterminated_array (tree, tree * = NULL, bool * = NULL);

extern bool maybe_warn_nonstring_arg (tree, gimple *);
extern bool maybe_warn_nonstring_arg (tree, tree);

class access_data;
extern bool maybe_warn_for_bound (opt_code, location_t, gimple *, tree,
				  tree[2], tree, const access_data * = NULL);
extern bool maybe_warn_for_bound (opt_code, location_t, tree, tree,
				  tree[2], tree, const access_data * = NULL);

class access_data;
extern bool check_access (tree, tree, tree, tree, tree, access_mode,
			  const access_data * = NULL);

#endif   // GCC_GIMPLE_SSA_WARN_ACCESS_H
