/* Declarations for tree-object-size.cc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_OBJECT_SIZE_H
#define GCC_TREE_OBJECT_SIZE_H

/* Bits in object_size_type.  */

enum
{
  OST_SUBOBJECT = 1,
  OST_MINIMUM = 2,
  OST_DYNAMIC = 4,
  OST_END = 8,
};

extern void init_object_sizes (void);
extern void fini_object_sizes (void);
extern bool compute_builtin_object_size (tree, int, tree *);
extern tree decl_init_size (tree, bool);

#endif  // GCC_TREE_OBJECT_SIZE_H
