/* toplev.h - Various declarations for functions found in toplev.cc */

#ifndef GCC_TOPLEV_H
#define GCC_TOPLEV_H

/* Decoded options, and number of such options.  */
extern struct cl_decoded_option *save_decoded_options;
extern unsigned int save_decoded_options_count;
extern vec<cl_decoded_option> *save_opt_decoded_options;

class timer;

/* Invoking the compiler.  */
class toplev
{
public:
  toplev (timer *external_timer,
	  bool init_signals);
  ~toplev ();

  int main (int argc, char **argv);

  void finalize ();

private:

  void start_timevars ();

  void run_self_tests ();

  bool m_use_TV_TOTAL;
  bool m_init_signals;
};

extern void rest_of_decl_compilation (tree, int, int);
extern void rest_of_type_compilation (tree, int);
extern void init_optimization_passes (void);
extern bool enable_rtl_dump_file (void);

/* In except.cc.  Initialize exception handling.  This is used by the Ada
   and LTO front ends to initialize EH "on demand".  See lto-streamer-in.cc
   and ada/gcc-interface/misc.cc.  */
extern void init_eh (void);

extern void announce_function (tree);

extern void wrapup_global_declaration_1 (tree);
extern bool wrapup_global_declaration_2 (tree);
extern bool wrapup_global_declarations (tree *, int);

extern void global_decl_processing (void);

extern void
dump_memory_report (const char *);
extern void dump_profile_report (void);

extern void target_reinit (void);

/* A unique local time stamp, might be zero if none is available.  */
extern unsigned local_tick;

/* See toplev.cc.  */
extern int flag_rerun_cse_after_global_opts;

extern void print_version (FILE *, const char *, bool);

/* The hashtable, so that the C front ends can pass it to cpplib.  */
extern struct ht *ident_hash;

/* Functions used to get and set GCC's notion of in what directory
   compilation was started.  */

extern const char *get_src_pwd	       (void);
extern bool set_src_pwd		       (const char *);

/* Functions used to manipulate the random seed.  */

extern HOST_WIDE_INT get_random_seed (bool);
extern void set_random_seed (const char *);

extern void parse_alignment_opts (void);

extern void initialize_rtl (void);

#endif /* ! GCC_TOPLEV_H */
