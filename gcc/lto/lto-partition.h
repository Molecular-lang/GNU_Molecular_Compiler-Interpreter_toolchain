/* LTO partitioning logic routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Structure describing ltrans partitions.  */

struct ltrans_partition_def
{
  lto_symtab_encoder_t encoder;
  const char * name;
  int insns;
  int symbols;
  hash_set<symtab_node *> *initializers_visited;
};

typedef struct ltrans_partition_def *ltrans_partition;

extern vec<ltrans_partition> ltrans_partitions;

void lto_1_to_1_map (void);
void lto_max_map (void);
void lto_balanced_map (int, int);
void lto_promote_cross_file_statics (void);
void free_ltrans_partitions (void);
void lto_promote_statics_nonwpa (void);
