/* Type class enum
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TYPECLASS_H
#define GCC_TYPECLASS_H

/* Values returned by __builtin_classify_type.  */

enum type_class
{
  no_type_class = -1,
  void_type_class, integer_type_class, char_type_class,
  enumeral_type_class, boolean_type_class,
  pointer_type_class, reference_type_class, offset_type_class,
  real_type_class, complex_type_class,
  function_type_class, method_type_class,
  record_type_class, union_type_class,
  array_type_class, string_type_class,
  lang_type_class, opaque_type_class
};

#endif /* GCC_TYPECLASS_H */
