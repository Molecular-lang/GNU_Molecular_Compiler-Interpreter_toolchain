/* Definition of functions in convert.cc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_CONVERT_H
#define GCC_CONVERT_H

extern tree convert_to_integer (tree, tree);
extern tree convert_to_integer_maybe_fold (tree, tree, bool);
extern tree convert_to_pointer (tree, tree);
extern tree convert_to_pointer_maybe_fold (tree, tree, bool);
extern tree convert_to_real (tree, tree);
extern tree convert_to_real_maybe_fold (tree, tree, bool);
extern tree convert_to_fixed (tree, tree);
extern tree convert_to_complex (tree, tree);
extern tree convert_to_complex_maybe_fold (tree, tree, bool);
extern tree convert_to_vector (tree, tree);

extern inline tree convert_to_integer_nofold (tree t, tree x)
{ return convert_to_integer_maybe_fold (t, x, false); }
extern inline tree convert_to_pointer_nofold (tree t, tree x)
{ return convert_to_pointer_maybe_fold (t, x, false); }
extern inline tree convert_to_real_nofold (tree t, tree x)
{ return convert_to_real_maybe_fold (t, x, false); }
extern inline tree convert_to_complex_nofold (tree t, tree x)
{ return convert_to_complex_maybe_fold (t, x, false); }

extern tree preserve_any_location_wrapper (tree result, tree orig_expr);

#endif /* GCC_CONVERT_H */
