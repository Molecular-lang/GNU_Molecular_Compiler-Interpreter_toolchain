/* Header file for graph routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GRAPH_H
#define GCC_GRAPH_H

extern void print_graph_cfg (const char *, struct function *);
extern void clean_graph_dump_file (const char *);
extern void finish_graph_dump_file (const char *);

#endif /* ! GCC_GRAPH_H */
