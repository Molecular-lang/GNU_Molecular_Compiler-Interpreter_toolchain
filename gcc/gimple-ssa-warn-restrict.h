/* Warn on violations of the restrict qualifier.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GIMPLE_SSA_WARN_RESTRICT_H

extern opt_code check_bounds_or_overlap (gimple *, tree, tree, tree, tree, bool = false, bool = true);
extern opt_code check_bounds_or_overlap (class pointer_query &, gimple *, tree, tree, tree, tree,
					 bool = false, bool = true);

#endif /* GIMPLE_SSA_WARN_RESTRICT_H */
