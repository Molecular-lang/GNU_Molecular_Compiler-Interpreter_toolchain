/* Utilities for querying and manipulating type trees.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_CP_TYPE_UTILS_H
#define GCC_CP_TYPE_UTILS_H

/* Returns the first tree within T that is directly matched by PRED.  T may be a
   type or PARM_DECL and is incrementally decomposed toward its type-specifier
   until a match is found.  NULL is returned if PRED does not match any
   part of T.

   This is primarily intended for detecting whether T uses `auto' or a concept
   identifier.  Since either of these can only appear as a type-specifier for
   the declaration in question, only top-level qualifications are traversed;
   find_type_usage does not look through the whole type.  */

inline tree
find_type_usage (tree t, bool (*pred) (const_tree))
{
  if (pred (t))
    return t;

  enum tree_code code = TREE_CODE (t);

  if (code == POINTER_TYPE || code == REFERENCE_TYPE
      || code == PARM_DECL || code == OFFSET_TYPE
      || code == FUNCTION_TYPE || code == METHOD_TYPE
      || code == ARRAY_TYPE)
    return find_type_usage (TREE_TYPE (t), pred);

  if (TYPE_PTRMEMFUNC_P (t))
    return find_type_usage
      (TREE_TYPE (TYPE_PTRMEMFUNC_FN_TYPE (t)), pred);

  return NULL_TREE;
}

#endif // GCC_CP_TYPE_UTILS_H
