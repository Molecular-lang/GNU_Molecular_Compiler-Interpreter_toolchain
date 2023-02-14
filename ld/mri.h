/* mri.h -- header file for MRI scripting functions */

#ifndef MRI_H
#define MRI_H

extern void mri_output_section (const char *, etree_type *);
extern void mri_only_load (const char *);
extern void mri_base (etree_type *);
extern void mri_load (const char *);
extern void mri_order (const char *);
extern void mri_alias (const char *, const char *, int);
extern void mri_name (const char *);
extern void mri_format (const char *);
extern void mri_public (const char *, etree_type *);
extern void mri_align (const char *, etree_type *);
extern void mri_alignmod (const char *, etree_type *);
extern void mri_truncate (unsigned int);
extern void mri_draw_tree (void);

#endif
