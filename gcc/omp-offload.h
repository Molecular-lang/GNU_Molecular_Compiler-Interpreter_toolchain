/* Bits of OpenMP and OpenACC handling that is specific to device offloading
   and a lowering pass for OpenACC device directives.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_OMP_DEVICE_H
#define GCC_OMP_DEVICE_H

extern int oacc_get_default_dim (int dim);
extern int oacc_get_min_dim (int dim);
extern int oacc_fn_attrib_level (tree attr);

extern GTY(()) vec<tree, va_gc> *offload_funcs;
extern GTY(()) vec<tree, va_gc> *offload_vars;

extern void omp_finish_file (void);
extern void omp_discover_implicit_declare_target (void);

#endif /* GCC_OMP_DEVICE_H */
