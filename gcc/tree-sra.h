/* Scalar Replacement of Aggregates (SRA) converts some structure
   references into scalar references, exposing them to the scalar
   optimizers.
   Please review: $(src-dir)/SPL-README for Licencing info. */

bool type_internals_preclude_sra_p (tree type, const char **msg);

/* Return true iff TYPE is stdarg va_list type (which early SRA and IPA-SRA
   should leave alone).  */

static inline bool
is_va_list_type (tree type)
{
  return TYPE_MAIN_VARIANT (type) == TYPE_MAIN_VARIANT (va_list_type_node);
}
