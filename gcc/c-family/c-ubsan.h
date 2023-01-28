/* UndefinedBehaviorSanitizer, undefined behavior detector.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_C_UBSAN_H
#define GCC_C_UBSAN_H

extern tree ubsan_instrument_division (location_t, tree, tree);
extern tree ubsan_instrument_shift (location_t, enum tree_code, tree, tree);
extern tree ubsan_instrument_vla (location_t, tree);
extern tree ubsan_instrument_return (location_t);
extern tree ubsan_instrument_bounds (location_t, tree, tree *, bool);
extern bool ubsan_array_ref_instrumented_p (const_tree);
extern void ubsan_maybe_instrument_array_ref (tree *, bool);
extern void ubsan_maybe_instrument_reference (tree *);
extern void ubsan_maybe_instrument_member_call (tree, bool);

#endif  /* GCC_C_UBSAN_H  */
