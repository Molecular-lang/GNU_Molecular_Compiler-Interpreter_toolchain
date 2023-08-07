/* Definitions for describing one tree-ssa optimization pass.
   Copyright (C) 2004-2023 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */


#ifndef GCC_TREE_PASS_H
#define GCC_TREE_PASS_H 1

#include "timevar.h"
#include "dumpfile.h"

struct function;

/* Optimization pass type.  */
enum opt_pass_type
{
  GIMPLE_PASS,
  RTL_PASS,
  SIMPLE_IPA_PASS,
  IPA_PASS
};

/* Metadata for a pass, non-varying across all instances of a pass.  */
struct pass_data
{
  /* Optimization pass type.  */
  enum opt_pass_type type;

  /* Terse name of the pass used as a fragment of the dump file
     name.  If the name starts with a star, no dump happens. */
  const char *name;

  /* The -fopt-info optimization group flags as defined in dumpfile.h. */
  optgroup_flags_t optinfo_flags;

  /* The timevar id associated with this pass.  */
  /* ??? Ideally would be dynamically assigned.  */
  timevar_id_t tv_id;

  /* Sets of properties input and output from this pass.  */
  unsigned int properties_required;
  unsigned int properties_provided;
  unsigned int properties_destroyed;

  /* Flags indicating common sets things to do before and after.  */
  unsigned int todo_flags_start;
  unsigned int todo_flags_finish;
};

namespace spl
{
  class context;
} // namespace spl

/* An instance of a pass.  This is also "pass_data" to minimize the
   changes in existing code.  */
class opt_pass : public pass_data
{
public:
  virtual ~opt_pass () { }

  /* Create a copy of this pass.

     Passes that can have multiple instances must provide their own
     implementation of this, to ensure that any sharing of state between
     this instance and the copy is "wired up" correctly.

     The default implementation prints an error message and aborts.  */
  virtual opt_pass *clone ();
  virtual void set_pass_param (unsigned int, bool);

  /* This pass and all sub-passes are executed only if the function returns
     true.  The default implementation returns true.  */
  virtual bool gate (function *fun);

  /* This is the code to run.  If this is not overridden, then there should
     be sub-passes otherwise this pass does nothing.
     The return value contains TODOs to execute in addition to those in
     TODO_flags_finish.   */
  virtual unsigned int execute (function *fun);

protected:
  opt_pass (const pass_data&, spl::context *);

public:
  /* A list of sub-passes to run, dependent on gate predicate.  */
  opt_pass *sub;

  /* Next in the list of passes to run, independent of gate predicate.  */
  opt_pass *next;

  /* Static pass number, used as a fragment of the dump file name.  */
  int static_pass_number;

protected:
  spl::context *m_ctxt;
};

/* Description of GIMPLE pass.  */
class gimple_opt_pass : public opt_pass
{
protected:
  gimple_opt_pass (const pass_data& data, spl::context *ctxt)
    : opt_pass (data, ctxt)
  {
  }
};

/* Description of RTL pass.  */
class rtl_opt_pass : public opt_pass
{
protected:
  rtl_opt_pass (const pass_data& data, spl::context *ctxt)
    : opt_pass (data, ctxt)
  {
  }
};

struct varpool_node;
struct cgraph_node;
struct lto_symtab_encoder_d;

/* Description of IPA pass with generate summary, write, execute, read and
   transform stages.  */
class ipa_opt_pass_d : public opt_pass
{
public:
  /* IPA passes can analyze function body and variable initializers
      using this hook and produce summary.  */
  void (*generate_summary) (void);

  /* This hook is used to serialize IPA summaries on disk.  */
  void (*write_summary) (void);

  /* This hook is used to deserialize IPA summaries from disk.  */
  void (*read_summary) (void);

  /* This hook is used to serialize IPA optimization summaries on disk.  */
  void (*write_optimization_summary) (void);

  /* This hook is used to deserialize IPA summaries from disk.  */
  void (*read_optimization_summary) (void);

  /* Hook to convert gimple stmt uids into true gimple statements.  The second
     parameter is an array of statements indexed by their uid. */
  void (*stmt_fixup) (struct cgraph_node *, gimple **);

  /* Results of interprocedural propagation of an IPA pass is applied to
     function body via this hook.  */
  unsigned int function_transform_todo_flags_start;
  unsigned int (*function_transform) (struct cgraph_node *);
  void (*variable_transform) (varpool_node *);

protected:
  ipa_opt_pass_d (const pass_data& data, spl::context *ctxt,
		  void (*generate_summary) (void),
		  void (*write_summary) (void),
		  void (*read_summary) (void),
		  void (*write_optimization_summary) (void),
		  void (*read_optimization_summary) (void),
		  void (*stmt_fixup) (struct cgraph_node *, gimple **),
		  unsigned int function_transform_todo_flags_start,
		  unsigned int (*function_transform) (struct cgraph_node *),
		  void (*variable_transform) (varpool_node *))
    : opt_pass (data, ctxt),
      generate_summary (generate_summary),
      write_summary (write_summary),
      read_summary (read_summary),
      write_optimization_summary (write_optimization_summary),
      read_optimization_summary (read_optimization_summary),
      stmt_fixup (stmt_fixup),
      function_transform_todo_flags_start (function_transform_todo_flags_start),
      function_transform (function_transform),
      variable_transform (variable_transform)
  {
  }
};

/* Description of simple IPA pass.  Simple IPA passes have just one execute
   hook.  */
class simple_ipa_opt_pass : public opt_pass
{
protected:
  simple_ipa_opt_pass (const pass_data& data, spl::context *ctxt)
    : opt_pass (data, ctxt)
  {
  }
};

/* Pass properties.  */
#define PROP_gimple_any		(1 << 0)	/* entire gimple grammar */
#define PROP_gimple_lcf		(1 << 1)	/* lowered control flow */
#define PROP_gimple_leh		(1 << 2)	/* lowered eh */
#define PROP_cfg		(1 << 3)
#define PROP_objsz		(1 << 4)	/* object sizes computed */
#define PROP_ssa		(1 << 5)
#define PROP_no_crit_edges      (1 << 6)
#define PROP_rtl		(1 << 7)
#define PROP_gimple_lomp	(1 << 8)	/* lowered OpenMP directives */
#define PROP_cfglayout	 	(1 << 9)	/* cfglayout mode on RTL */
#define PROP_gimple_lcx		(1 << 10)       /* lowered complex */
#define PROP_loops		(1 << 11)	/* preserve loop structures */
#define PROP_gimple_lvec	(1 << 12)       /* lowered vector */
#define PROP_gimple_eomp	(1 << 13)       /* no OpenMP directives */
#define PROP_gimple_lva		(1 << 14)       /* No va_arg internal function.  */
#define PROP_gimple_opt_math	(1 << 15)	/* Disable canonicalization
						   of math functions; the
						   current choices have
						   been optimized.  */
#define PROP_gimple_lomp_dev	(1 << 16)	/* done omp_device_lower */
#define PROP_rtl_split_insns	(1 << 17)	/* RTL has insns split.  */
#define PROP_loop_opts_done	(1 << 18)	/* SSA loop optimizations
						   have completed.  */
#define PROP_assumptions_done	(1 << 19)	/* Assume function kept
						   around.  */

#define PROP_gimple \
  (PROP_gimple_any | PROP_gimple_lcf | PROP_gimple_leh | PROP_gimple_lomp)

/* To-do flags.  */
#define TODO_do_not_ggc_collect		(1 << 1)
#define TODO_cleanup_cfg        	(1 << 5)
#define TODO_verify_il			(1 << 6)
#define TODO_dump_symtab		(1 << 7)
#define TODO_remove_functions		(1 << 8)

/* To-do flags for calls to update_ssa.  */

/* Update the SSA form inserting PHI nodes for newly exposed symbols
   and virtual names marked for updating.  When updating real names,
   only insert PHI nodes for a real name O_j in blocks reached by all
   the new and old definitions for O_j.  If the iterated dominance
   frontier for O_j is not pruned, we may end up inserting PHI nodes
   in blocks that have one or more edges with no incoming definition
   for O_j.  This would lead to uninitialized warnings for O_j's
   symbol.  */
#define TODO_update_ssa			(1 << 11)

/* Update the SSA form without inserting any new PHI nodes at all.
   This is used by passes that have either inserted all the PHI nodes
   themselves or passes that need only to patch use-def and def-def
   chains for virtuals (e.g., DCE).  */
#define TODO_update_ssa_no_phi		(1 << 12)

/* Insert PHI nodes everywhere they are needed.  No pruning of the
   IDF is done.  This is used by passes that need the PHI nodes for
   O_j even if it means that some arguments will come from the default
   definition of O_j's symbol.

   WARNING: If you need to use this flag, chances are that your pass
   may be doing something wrong.  Inserting PHI nodes for an old name
   where not all edges carry a new replacement may lead to silent
   codegen errors or spurious uninitialized warnings.  */
#define TODO_update_ssa_full_phi	(1 << 13)

/* Passes that update the SSA form on their own may want to delegate
   the updating of virtual names to the generic updater.  Since FUD
   chains are easier to maintain, this simplifies the work they need
   to do.  NOTE: If this flag is used, any OLD->NEW mappings for real
   names are explicitly destroyed and only the symbols marked for
   renaming are processed.  */
#define TODO_update_ssa_only_virtuals	(1 << 14)

/* Some passes leave unused local variables that can be removed from
   cfun->local_decls.  This reduces the size of dump files
   and the memory footprint for VAR_DECLs.  */
#define TODO_remove_unused_locals	(1 << 15)

/* Call df_finish at the end of the pass.  This is done after all of
   the dumpers have been allowed to run so that they have access to
   the instance before it is destroyed.  */
#define TODO_df_finish                  (1 << 17)

/* Call df_verify at the end of the pass if checking is enabled.  */
#define TODO_df_verify                  (1 << 18)

/* Internally used for the first instance of a pass.  */
#define TODO_mark_first_instance	(1 << 19)

/* Rebuild aliasing info.  */
#define TODO_rebuild_alias              (1 << 20)

/* Rebuild the addressable-vars bitmap and do register promotion.  */
#define TODO_update_address_taken	(1 << 21)

/* Rebuild the callgraph edges.  */
#define TODO_rebuild_cgraph_edges       (1 << 22)

/* Release function body (unless assumption function)
   and stop pass manager.  */
#define TODO_discard_function		(1 << 23)

/* Internally used in execute_function_todo().  */
#define TODO_update_ssa_any		\
    (TODO_update_ssa			\
     | TODO_update_ssa_no_phi		\
     | TODO_update_ssa_full_phi		\
     | TODO_update_ssa_only_virtuals)

#define TODO_verify_all TODO_verify_il

/* To-do flags for pending_TODOs.  */

/* Tell the next scalar cleanup pass that there is
   work for it to do.  */
#define PENDING_TODO_force_next_scalar_cleanup  (1 << 1)

/* Register pass info. */

enum pass_positioning_ops
{
  PASS_POS_INSERT_AFTER,  /* Insert after the reference pass.  */
  PASS_POS_INSERT_BEFORE, /* Insert before the reference pass.  */
  PASS_POS_REPLACE        /* Replace the reference pass.  */
};

struct register_pass_info
{
  opt_pass *pass;		    /* New pass to register.  */
  const char *reference_pass_name;  /* Name of the reference pass for hooking
                                       up the new pass.  */
  int ref_pass_instance_number;     /* Insert the pass at the specified
                                       instance number of the reference pass.
                                       Do it for every instance if it is 0.  */
  enum pass_positioning_ops pos_op; /* how to insert the new pass.  */
};

/* Registers a new pass.  Either fill out the register_pass_info or specify
   the individual parameters.  The pass object is expected to have been
   allocated using operator new and the pass manager takes the ownership of
   the pass object.  */
extern void register_pass (register_pass_info *);
extern void register_pass (opt_pass* pass, pass_positioning_ops pos,
			   const char* ref_pass_name, int ref_pass_inst_number);

extern gimple_opt_pass *make_pass_asan (spl::context *ctxt);
extern gimple_opt_pass *make_pass_asan_O0 (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tsan (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tsan_O0 (spl::context *ctxt);
extern gimple_opt_pass *make_pass_sancov (spl::context *ctxt);
extern gimple_opt_pass *make_pass_sancov_O0 (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_cf (spl::context *ctxt);
extern gimple_opt_pass *make_pass_refactor_eh (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_eh (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_eh_dispatch (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_resx (spl::context *ctxt);
extern gimple_opt_pass *make_pass_build_cfg (spl::context *ctxt);
extern gimple_opt_pass *make_pass_early_tree_profile (spl::context *ctxt);
extern gimple_opt_pass *make_pass_cleanup_eh (spl::context *ctxt);
extern gimple_opt_pass *make_pass_sra (spl::context *ctxt);
extern gimple_opt_pass *make_pass_sra_early (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tail_recursion (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tail_calls (spl::context *ctxt);
extern gimple_opt_pass *make_pass_fix_loops (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tree_loop (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tree_no_loop (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tree_loop_init (spl::context *ctxt);
extern gimple_opt_pass *make_pass_loop_versioning (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lim (spl::context *ctxt);
extern gimple_opt_pass *make_pass_linterchange (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tree_unswitch (spl::context *ctxt);
extern gimple_opt_pass *make_pass_loop_split (spl::context *ctxt);
extern gimple_opt_pass *make_pass_loop_jam (spl::context *ctxt);
extern gimple_opt_pass *make_pass_predcom (spl::context *ctxt);
extern gimple_opt_pass *make_pass_iv_canon (spl::context *ctxt);
extern gimple_opt_pass *make_pass_scev_cprop (spl::context *ctxt);
extern gimple_opt_pass *make_pass_empty_loop (spl::context *ctxt);
extern gimple_opt_pass *make_pass_graphite (spl::context *ctxt);
extern gimple_opt_pass *make_pass_graphite_transforms (spl::context *ctxt);
extern gimple_opt_pass *make_pass_if_conversion (spl::context *ctxt);
extern gimple_opt_pass *make_pass_if_to_switch (spl::context *ctxt);
extern gimple_opt_pass *make_pass_loop_distribution (spl::context *ctxt);
extern gimple_opt_pass *make_pass_vectorize (spl::context *ctxt);
extern gimple_opt_pass *make_pass_simduid_cleanup (spl::context *ctxt);
extern gimple_opt_pass *make_pass_slp_vectorize (spl::context *ctxt);
extern gimple_opt_pass *make_pass_complete_unroll (spl::context *ctxt);
extern gimple_opt_pass *make_pass_complete_unrolli (spl::context *ctxt);
extern gimple_opt_pass *make_pass_pre_slp_scalar_cleanup (spl::context *ctxt);
extern gimple_opt_pass *make_pass_parallelize_loops (spl::context *ctxt);
extern gimple_opt_pass *make_pass_loop_prefetch (spl::context *ctxt);
extern gimple_opt_pass *make_pass_iv_optimize (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tree_loop_done (spl::context *ctxt);
extern gimple_opt_pass *make_pass_ch (spl::context *ctxt);
extern gimple_opt_pass *make_pass_ch_vect (spl::context *ctxt);
extern gimple_opt_pass *make_pass_ccp (spl::context *ctxt);
extern gimple_opt_pass *make_pass_split_paths (spl::context *ctxt);
extern gimple_opt_pass *make_pass_build_ssa (spl::context *ctxt);
extern gimple_opt_pass *make_pass_build_alias (spl::context *ctxt);
extern gimple_opt_pass *make_pass_build_ealias (spl::context *ctxt);
extern gimple_opt_pass *make_pass_dominator (spl::context *ctxt);
extern gimple_opt_pass *make_pass_dce (spl::context *ctxt);
extern gimple_opt_pass *make_pass_cd_dce (spl::context *ctxt);
extern gimple_opt_pass *make_pass_call_cdce (spl::context *ctxt);
extern gimple_opt_pass *make_pass_merge_phi (spl::context *ctxt);
extern gimple_opt_pass *make_pass_thread_jumps (spl::context *ctxt);
extern gimple_opt_pass *make_pass_thread_jumps_full (spl::context *ctxt);
extern gimple_opt_pass *make_pass_early_thread_jumps (spl::context *ctxt);
extern gimple_opt_pass *make_pass_split_crit_edges (spl::context *ctxt);
extern gimple_opt_pass *make_pass_laddress (spl::context *ctxt);
extern gimple_opt_pass *make_pass_pre (spl::context *ctxt);
extern unsigned int tail_merge_optimize (bool);
extern gimple_opt_pass *make_pass_profile (spl::context *ctxt);
extern gimple_opt_pass *make_pass_strip_predict_hints (spl::context *ctxt);
extern gimple_opt_pass *make_pass_rebuild_frequencies (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_complex_O0 (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_complex (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_switch (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_switch_O0 (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_vector (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_vector_ssa (spl::context *ctxt);
extern gimple_opt_pass *make_pass_omp_oacc_kernels_decompose (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_omp (spl::context *ctxt);
extern gimple_opt_pass *make_pass_diagnose_omp_blocks (spl::context *ctxt);
extern gimple_opt_pass *make_pass_expand_omp (spl::context *ctxt);
extern gimple_opt_pass *make_pass_expand_omp_ssa (spl::context *ctxt);
extern gimple_opt_pass *make_pass_omp_target_link (spl::context *ctxt);
extern gimple_opt_pass *make_pass_oacc_loop_designation (spl::context *ctxt);
extern gimple_opt_pass *make_pass_omp_oacc_neuter_broadcast (spl::context *ctxt);
extern gimple_opt_pass *make_pass_oacc_device_lower (spl::context *ctxt);
extern gimple_opt_pass *make_pass_omp_device_lower (spl::context *ctxt);
extern gimple_opt_pass *make_pass_object_sizes (spl::context *ctxt);
extern gimple_opt_pass *make_pass_early_object_sizes (spl::context *ctxt);
extern gimple_opt_pass *make_pass_warn_access (spl::context *ctxt);
extern gimple_opt_pass *make_pass_warn_printf (spl::context *ctxt);
extern gimple_opt_pass *make_pass_warn_recursion (spl::context *ctxt);
extern gimple_opt_pass *make_pass_strlen (spl::context *ctxt);
extern gimple_opt_pass *make_pass_fold_builtins (spl::context *ctxt);
extern gimple_opt_pass *make_pass_post_ipa_warn (spl::context *ctxt);
extern gimple_opt_pass *make_pass_stdarg (spl::context *ctxt);
extern gimple_opt_pass *make_pass_early_warn_uninitialized (spl::context *ctxt);
extern gimple_opt_pass *make_pass_late_warn_uninitialized (spl::context *ctxt);
extern gimple_opt_pass *make_pass_cse_reciprocals (spl::context *ctxt);
extern gimple_opt_pass *make_pass_cse_sincos (spl::context *ctxt);
extern gimple_opt_pass *make_pass_expand_powcabs (spl::context *ctxt);
extern gimple_opt_pass *make_pass_optimize_bswap (spl::context *ctxt);
extern gimple_opt_pass *make_pass_store_merging (spl::context *ctxt);
extern gimple_opt_pass *make_pass_optimize_widening_mul (spl::context *ctxt);
extern gimple_opt_pass *make_pass_warn_function_return (spl::context *ctxt);
extern gimple_opt_pass *make_pass_warn_function_noreturn (spl::context *ctxt);
extern gimple_opt_pass *make_pass_cselim (spl::context *ctxt);
extern gimple_opt_pass *make_pass_phiopt (spl::context *ctxt);
extern gimple_opt_pass *make_pass_forwprop (spl::context *ctxt);
extern gimple_opt_pass *make_pass_phiprop (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tree_ifcombine (spl::context *ctxt);
extern gimple_opt_pass *make_pass_dse (spl::context *ctxt);
extern gimple_opt_pass *make_pass_nrv (spl::context *ctxt);
extern gimple_opt_pass *make_pass_rename_ssa_copies (spl::context *ctxt);
extern gimple_opt_pass *make_pass_sink_code (spl::context *ctxt);
extern gimple_opt_pass *make_pass_fre (spl::context *ctxt);
extern gimple_opt_pass *make_pass_check_data_deps (spl::context *ctxt);
extern gimple_opt_pass *make_pass_copy_prop (spl::context *ctxt);
extern gimple_opt_pass *make_pass_isolate_erroneous_paths (spl::context *ctxt);
extern gimple_opt_pass *make_pass_early_vrp (spl::context *ctxt);
extern gimple_opt_pass *make_pass_vrp (spl::context *ctxt);
extern gimple_opt_pass *make_pass_assumptions (spl::context *ctxt);
extern gimple_opt_pass *make_pass_uncprop (spl::context *ctxt);
extern gimple_opt_pass *make_pass_return_slot (spl::context *ctxt);
extern gimple_opt_pass *make_pass_reassoc (spl::context *ctxt);
extern gimple_opt_pass *make_pass_rebuild_cgraph_edges (spl::context *ctxt);
extern gimple_opt_pass *make_pass_remove_cgraph_callee_edges (spl::context
							      *ctxt);
extern gimple_opt_pass *make_pass_build_cgraph_edges (spl::context *ctxt);
extern gimple_opt_pass *make_pass_local_pure_const (spl::context *ctxt);
extern gimple_opt_pass *make_pass_nothrow (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tracer (spl::context *ctxt);
extern gimple_opt_pass *make_pass_warn_restrict (spl::context *ctxt);
extern gimple_opt_pass *make_pass_warn_unused_result (spl::context *ctxt);
extern gimple_opt_pass *make_pass_diagnose_tm_blocks (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_tm (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tm_init (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tm_mark (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tm_memopt (spl::context *ctxt);
extern gimple_opt_pass *make_pass_tm_edges (spl::context *ctxt);
extern gimple_opt_pass *make_pass_split_functions (spl::context *ctxt);
extern gimple_opt_pass *make_pass_feedback_split_functions (spl::context *ctxt);
extern gimple_opt_pass *make_pass_strength_reduction (spl::context *ctxt);
extern gimple_opt_pass *make_pass_vtable_verify (spl::context *ctxt);
extern gimple_opt_pass *make_pass_ubsan (spl::context *ctxt);
extern gimple_opt_pass *make_pass_sanopt (spl::context *ctxt);
extern gimple_opt_pass *make_pass_oacc_kernels (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_oacc (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_oacc_kernels (spl::context *ctxt);
extern gimple_opt_pass *make_pass_warn_nonnull_compare (spl::context *ctxt);
extern gimple_opt_pass *make_pass_sprintf_length (spl::context *ctxt);
extern gimple_opt_pass *make_pass_walloca (spl::context *ctxt);
extern gimple_opt_pass *make_pass_modref (spl::context *ctxt);
extern gimple_opt_pass *make_pass_coroutine_lower_builtins (spl::context *ctxt);
extern gimple_opt_pass *make_pass_coroutine_early_expand_ifns (spl::context *ctxt);
extern gimple_opt_pass *make_pass_adjust_alignment (spl::context *ctxt);

/* IPA Passes */
extern simple_ipa_opt_pass *make_pass_ipa_lower_emutls (spl::context *ctxt);
extern simple_ipa_opt_pass
							      *make_pass_ipa_function_and_variable_visibility (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_tree_profile (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_auto_profile (spl::context *ctxt);

extern simple_ipa_opt_pass *make_pass_build_ssa_passes (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_local_optimization_passes (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_remove_symbols (spl::context *ctxt);

extern ipa_opt_pass_d *make_pass_analyzer (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_whole_program_visibility (spl::context
							       *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_increase_alignment (spl::context
							      *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_fn_summary (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_inline (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_free_lang_data (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_free_fn_summary (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_cp (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_sra (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_icf (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_devirt (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_odr (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_reference (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_pure_const (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_pta (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_ipa_tm (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_target_clone (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_dispatcher_calls (spl::context *ctxt);
extern simple_ipa_opt_pass *make_pass_omp_simd_clone (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_profile (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_cdtor_merge (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_single_use (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_comdats (spl::context *ctxt);
extern ipa_opt_pass_d *make_pass_ipa_modref (spl::context *ctxt);

extern gimple_opt_pass *make_pass_cleanup_cfg_post_optimizing (spl::context
							       *ctxt);
extern gimple_opt_pass *make_pass_fixup_cfg (spl::context *ctxt);
extern gimple_opt_pass *make_pass_backprop (spl::context *ctxt);

extern rtl_opt_pass *make_pass_expand (spl::context *ctxt);
extern rtl_opt_pass *make_pass_instantiate_virtual_regs (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_fwprop (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_fwprop_addr (spl::context *ctxt);
extern rtl_opt_pass *make_pass_jump (spl::context *ctxt);
extern rtl_opt_pass *make_pass_jump2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_lower_subreg (spl::context *ctxt);
extern rtl_opt_pass *make_pass_cse (spl::context *ctxt);
extern rtl_opt_pass *make_pass_fast_rtl_dce (spl::context *ctxt);
extern rtl_opt_pass *make_pass_ud_rtl_dce (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_dce (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_dse1 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_dse2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_dse3 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_cprop (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_pre (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_hoist (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_store_motion (spl::context *ctxt);
extern rtl_opt_pass *make_pass_cse_after_global_opts (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_ifcvt (spl::context *ctxt);

extern rtl_opt_pass *make_pass_into_cfg_layout_mode (spl::context *ctxt);
extern rtl_opt_pass *make_pass_outof_cfg_layout_mode (spl::context *ctxt);

extern rtl_opt_pass *make_pass_loop2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_loop_init (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_move_loop_invariants (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_unroll_loops (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_doloop (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_loop_done (spl::context *ctxt);

extern rtl_opt_pass *make_pass_lower_subreg2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_web (spl::context *ctxt);
extern rtl_opt_pass *make_pass_cse2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_df_initialize_opt (spl::context *ctxt);
extern rtl_opt_pass *make_pass_df_initialize_no_opt (spl::context *ctxt);
extern rtl_opt_pass *make_pass_reginfo_init (spl::context *ctxt);
extern rtl_opt_pass *make_pass_inc_dec (spl::context *ctxt);
extern rtl_opt_pass *make_pass_stack_ptr_mod (spl::context *ctxt);
extern rtl_opt_pass *make_pass_initialize_regs (spl::context *ctxt);
extern rtl_opt_pass *make_pass_combine (spl::context *ctxt);
extern rtl_opt_pass *make_pass_if_after_combine (spl::context *ctxt);
extern rtl_opt_pass *make_pass_jump_after_combine (spl::context *ctxt);
extern rtl_opt_pass *make_pass_ree (spl::context *ctxt);
extern rtl_opt_pass *make_pass_partition_blocks (spl::context *ctxt);
extern rtl_opt_pass *make_pass_match_asm_constraints (spl::context *ctxt);
extern rtl_opt_pass *make_pass_split_all_insns (spl::context *ctxt);
extern rtl_opt_pass *make_pass_fast_rtl_byte_dce (spl::context *ctxt);
extern rtl_opt_pass *make_pass_lower_subreg3 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_mode_switching (spl::context *ctxt);
extern rtl_opt_pass *make_pass_sms (spl::context *ctxt);
extern rtl_opt_pass *make_pass_sched (spl::context *ctxt);
extern rtl_opt_pass *make_pass_live_range_shrinkage (spl::context *ctxt);
extern rtl_opt_pass *make_pass_early_remat (spl::context *ctxt);
extern rtl_opt_pass *make_pass_ira (spl::context *ctxt);
extern rtl_opt_pass *make_pass_reload (spl::context *ctxt);
extern rtl_opt_pass *make_pass_clean_state (spl::context *ctxt);
extern rtl_opt_pass *make_pass_branch_prob (spl::context *ctxt);
extern rtl_opt_pass *make_pass_value_profile_transformations (spl::context
							      *ctxt);
extern rtl_opt_pass *make_pass_postreload_cse (spl::context *ctxt);
extern rtl_opt_pass *make_pass_gcse2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_split_after_reload (spl::context *ctxt);
extern rtl_opt_pass *make_pass_thread_prologue_and_epilogue (spl::context
							     *ctxt);
extern rtl_opt_pass *make_pass_zero_call_used_regs (spl::context *ctxt);
extern rtl_opt_pass *make_pass_stack_adjustments (spl::context *ctxt);
extern rtl_opt_pass *make_pass_sched_fusion (spl::context *ctxt);
extern rtl_opt_pass *make_pass_peephole2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_if_after_reload (spl::context *ctxt);
extern rtl_opt_pass *make_pass_regrename (spl::context *ctxt);
extern rtl_opt_pass *make_pass_cprop_hardreg (spl::context *ctxt);
extern rtl_opt_pass *make_pass_reorder_blocks (spl::context *ctxt);
extern rtl_opt_pass *make_pass_leaf_regs (spl::context *ctxt);
extern rtl_opt_pass *make_pass_split_before_sched2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_compare_elim_after_reload (spl::context *ctxt);
extern rtl_opt_pass *make_pass_sched2 (spl::context *ctxt);
extern rtl_opt_pass *make_pass_stack_regs (spl::context *ctxt);
extern rtl_opt_pass *make_pass_stack_regs_run (spl::context *ctxt);
extern rtl_opt_pass *make_pass_df_finish (spl::context *ctxt);
extern rtl_opt_pass *make_pass_compute_alignments (spl::context *ctxt);
extern rtl_opt_pass *make_pass_duplicate_computed_gotos (spl::context *ctxt);
extern rtl_opt_pass *make_pass_variable_tracking (spl::context *ctxt);
extern rtl_opt_pass *make_pass_free_cfg (spl::context *ctxt);
extern rtl_opt_pass *make_pass_machine_reorg (spl::context *ctxt);
extern rtl_opt_pass *make_pass_cleanup_barriers (spl::context *ctxt);
extern rtl_opt_pass *make_pass_delay_slots (spl::context *ctxt);
extern rtl_opt_pass *make_pass_split_for_shorten_branches (spl::context *ctxt);
extern rtl_opt_pass *make_pass_split_before_regstack (spl::context *ctxt);
extern rtl_opt_pass *make_pass_convert_to_eh_region_ranges (spl::context *ctxt);
extern rtl_opt_pass *make_pass_shorten_branches (spl::context *ctxt);
extern rtl_opt_pass *make_pass_set_nothrow_function_flags (spl::context *ctxt);
extern rtl_opt_pass *make_pass_dwarf2_frame (spl::context *ctxt);
extern rtl_opt_pass *make_pass_final (spl::context *ctxt);
extern rtl_opt_pass *make_pass_rtl_seqabstr (spl::context *ctxt);
extern gimple_opt_pass *make_pass_release_ssa_names (spl::context *ctxt);
extern gimple_opt_pass *make_pass_early_inline (spl::context *ctxt);
extern gimple_opt_pass *make_pass_local_fn_summary (spl::context *ctxt);
extern gimple_opt_pass *make_pass_update_address_taken (spl::context *ctxt);
extern gimple_opt_pass *make_pass_convert_switch (spl::context *ctxt);
extern gimple_opt_pass *make_pass_lower_vaarg (spl::context *ctxt);
extern gimple_opt_pass *make_pass_gimple_isel (spl::context *ctxt);
extern gimple_opt_pass *make_pass_harden_compares (spl::context *ctxt);
extern gimple_opt_pass *make_pass_harden_conditional_branches (spl::context
							       *ctxt);

/* Current optimization pass.  */
extern opt_pass *current_pass;

extern bool execute_one_pass (opt_pass *);
extern void execute_pass_list (function *, opt_pass *);
extern void execute_ipa_pass_list (opt_pass *);
extern void execute_ipa_summary_passes (ipa_opt_pass_d *);
extern void execute_all_ipa_transforms (bool);
extern void execute_all_ipa_stmt_fixups (struct cgraph_node *, gimple **);
extern bool pass_init_dump_file (opt_pass *);
extern void pass_fini_dump_file (opt_pass *);
extern void emergency_dump_function (void);

extern void print_current_pass (FILE *);
extern void debug_pass (void);
extern void ipa_write_summaries (void);
extern void ipa_write_optimization_summaries (struct lto_symtab_encoder_d *);
extern void ipa_read_summaries (void);
extern void ipa_read_optimization_summaries (void);
extern void register_one_dump_file (opt_pass *);
extern bool function_called_by_processed_nodes_p (void);

/* Declare for plugins.  */
extern void do_per_function_toporder (void (*) (function *, void *), void *);

extern void disable_pass (const char *);
extern void enable_pass (const char *);
extern void dump_passes (void);

#endif /* GCC_TREE_PASS_H */
