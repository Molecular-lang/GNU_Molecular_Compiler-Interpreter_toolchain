/* Hash Table Helper for Trees
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_HASHER_H
#define GCC_TREE_HASHER_H 1

struct int_tree_map {
  unsigned int uid;
  tree to;
};

/* Hashtable helpers.  */

struct int_tree_hasher
{
  typedef int_tree_map value_type;
  typedef int_tree_map compare_type;
  static inline hashval_t hash (const value_type &);
  static inline bool equal (const value_type &, const compare_type &);
  static bool is_deleted (const value_type &v)
    {
      return v.to == reinterpret_cast<tree> (1);
    }
  static void mark_deleted (value_type &v) { v.to = reinterpret_cast<tree> (0x1); }
  static bool is_empty (const value_type &v) { return v.to == NULL; }
  static const bool empty_zero_p = true;
  static void mark_empty (value_type &v) { v.to = NULL; }
  static void remove (value_type &) {}
};

/* Hash a UID in a int_tree_map.  */

inline hashval_t
int_tree_hasher::hash (const value_type &item)
{
  return item.uid;
}

/* Return true if the uid in both int tree maps are equal.  */

inline bool
int_tree_hasher::equal (const value_type &a, const compare_type &b)
{
  return (a.uid == b.uid);
}

typedef hash_table <int_tree_hasher> int_tree_htab_type;

#endif /* GCC_TREE_HASHER_H  */
