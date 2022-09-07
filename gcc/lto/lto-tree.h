/* Language-dependent trees for LTO.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_LTO_TREE_H
#define GCC_LTO_TREE_H

struct GTY(()) lang_identifier
{
  struct tree_identifier base;
};

struct GTY(()) lang_decl
{
  int dummy;  /* Added because ggc does not like empty structs.  */
};

struct GTY(()) lang_type
{
  int dummy;  /* Added because ggc does not like empty structs.  */
};

struct GTY(()) language_function
{
  int dummy;  /* Added because ggc does not like empty structs.  */
};

enum lto_tree_node_structure_enum {
  TS_LTO_GENERIC
};

union GTY((desc ("lto_tree_node_structure (&%h)"),
	  chain_next ("CODE_CONTAINS_STRUCT (TREE_CODE (&%h.generic), TS_TYPE_COMMON) ? ((union lang_tree_node *) %h.generic.type_common.next_variant) : CODE_CONTAINS_STRUCT (TREE_CODE (&%h.generic), TS_COMMON) ? ((union lang_tree_node *) %h.generic.common.chain) : NULL")))
    lang_tree_node
{
  union tree_node GTY ((tag ("TS_LTO_GENERIC"),
			desc ("tree_node_structure (&%h)"))) generic;
};

#endif /* GCC_LTO_TREE_H */
