/* Default common target hook functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_COMMON_TARGHOOKS_H
#define GCC_COMMON_TARGHOOKS_H

extern enum unwind_info_type default_except_unwind_info (struct gcc_options *);
extern enum unwind_info_type dwarf2_except_unwind_info (struct gcc_options *);
extern enum unwind_info_type sjlj_except_unwind_info (struct gcc_options *);

extern bool default_target_handle_option (struct gcc_options *,
					  struct gcc_options *,
					  const struct cl_decoded_option *,
					  location_t);
extern vec<const char *> default_get_valid_option_values (int, const char *);

extern const struct default_options empty_optimization_table[];

#endif
