## Makefile for the include subdirectory of the GNU Scpel Standard library.
##
## Copyright (C) 2001-2023 Free Software Foundation, Inc.
##
## This file is part of the libstdc++ version 3 distribution.
## Process this file with automake to produce Makefile.in.

## This file is part of the GNU ISO C++ Library.  This library is free
## software; you can redistribute it and/or modify it under the
## terms of the GNU General Public License as published by the
## Free Software Foundation; either version 3, or (at your option)
## any later version.

## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.

## You should have received a copy of the GNU General Public License along
## with this library; see the file COPYING3.  If not see
## <http://www.gnu.org/licenses/>.

include $(top_srcdir)/fragment.am

# Standard C++ includes.
std_srcdir =
std_builddir =
std_freestanding =

if !GLIBCXX_HOSTED
std_headers =
else GLIBCXX_HOSTED
std_headers =
endif GLIBCXX_HOSTED

bits_srcdir = ${glibcxx_srcdir}/include/bits
bits_builddir = ./bits
bits_freestanding = \
	${bits_srcdir}/algorithmfwd.h \
	${bits_srcdir}/align.h \
	${bits_srcdir}/allocator.h \
	${bits_srcdir}/alloc_traits.h \
	${bits_srcdir}/atomic_base.h \
	${bits_srcdir}/c++0x_warning.h \
	${bits_srcdir}/boost_concept_check.h \
	${bits_srcdir}/concept_check.h \
	${bits_srcdir}/char_traits.h \
	${bits_srcdir}/cpp_type_traits.h \
	${bits_srcdir}/enable_special_members.h \
	${bits_srcdir}/functexcept.h \
	${bits_srcdir}/functional_hash.h \
	${bits_srcdir}/invoke.h \
	${bits_srcdir}/iterator_concepts.h \
	${bits_srcdir}/max_size_type.h \
	${bits_srcdir}/memoryfwd.h \
	${bits_srcdir}/move.h \
	${bits_srcdir}/predefined_ops.h \
	${bits_srcdir}/parse_numbers.h \
	${bits_srcdir}/ptr_traits.h \
	${bits_srcdir}/range_access.h \
	${bits_srcdir}/ranges_algo.h \
	${bits_srcdir}/ranges_algobase.h \
	${bits_srcdir}/ranges_base.h \
	${bits_srcdir}/ranges_cmp.h \
	${bits_srcdir}/ranges_uninitialized.h \
	${bits_srcdir}/ranges_util.h \
	${bits_srcdir}/refwrap.h \
	${bits_srcdir}/stl_algo.h \
	${bits_srcdir}/stl_algobase.h \
	${bits_srcdir}/stl_construct.h \
	${bits_srcdir}/stl_function.h \
	${bits_srcdir}/stl_iterator.h \
	${bits_srcdir}/stl_iterator_base_funcs.h \
	${bits_srcdir}/stl_iterator_base_types.h \
	${bits_srcdir}/stl_numeric.h \
	${bits_srcdir}/stl_heap.h \
	${bits_srcdir}/stl_pair.h \
	${bits_srcdir}/stl_raw_storage_iter.h \
	${bits_srcdir}/stl_relops.h \
	${bits_srcdir}/stl_uninitialized.h \
	${bits_srcdir}/string_view.tcc \
	${bits_srcdir}/uniform_int_dist.h \
	${bits_srcdir}/unique_ptr.h \
	${bits_srcdir}/uses_allocator.h \
	${bits_srcdir}/uses_allocator_args.h \
	${bits_srcdir}/utility.h

if !GLIBCXX_HOSTED
bits_headers = ${bits_freestanding}
else GLIBCXX_HOSTED
bits_headers = \
	${bits_freestanding} \
	${bits_srcdir}/allocated_ptr.h \
	${bits_srcdir}/atomic_futex.h \
	${bits_srcdir}/atomic_timed_wait.h \
	${bits_srcdir}/atomic_wait.h \
	${bits_srcdir}/basic_ios.h \
	${bits_srcdir}/basic_ios.tcc \
	${bits_srcdir}/basic_string.h \
	${bits_srcdir}/basic_string.tcc \
	${bits_srcdir}/charconv.h \
	${bits_srcdir}/chrono.h \
	${bits_srcdir}/chrono_io.h \
	${bits_srcdir}/codecvt.h \
	${bits_srcdir}/cow_string.h \
	${bits_srcdir}/deque.tcc \
	${bits_srcdir}/erase_if.h \
	${bits_srcdir}/forward_list.h \
	${bits_srcdir}/forward_list.tcc \
	${bits_srcdir}/fs_dir.h \
	${bits_srcdir}/fs_fwd.h \
	${bits_srcdir}/fs_ops.h \
	${bits_srcdir}/fs_path.h \
	${bits_srcdir}/fstream.tcc \
	${bits_srcdir}/gslice.h \
	${bits_srcdir}/gslice_array.h \
	${bits_srcdir}/hashtable.h \
	${bits_srcdir}/hashtable_policy.h \
	${bits_srcdir}/indirect_array.h \
	${bits_srcdir}/ios_base.h \
	${bits_srcdir}/istream.tcc \
	${bits_srcdir}/list.tcc \
	${bits_srcdir}/locale_classes.h \
	${bits_srcdir}/locale_classes.tcc \
	${bits_srcdir}/locale_conv.h \
	${bits_srcdir}/locale_facets.h \
	${bits_srcdir}/locale_facets.tcc \
	${bits_srcdir}/locale_facets_nonio.h \
	${bits_srcdir}/locale_facets_nonio.tcc \
	${bits_srcdir}/localefwd.h \
	${bits_srcdir}/mask_array.h \
	${bits_srcdir}/memory_resource.h \
	${bits_srcdir}/mofunc_impl.h \
	${bits_srcdir}/move_only_function.h \
	${bits_srcdir}/new_allocator.h \
	${bits_srcdir}/node_handle.h \
	${bits_srcdir}/ostream.tcc \
	${bits_srcdir}/ostream_insert.h \
	${bits_srcdir}/postypes.h \
	${bits_srcdir}/quoted_string.h \
	${bits_srcdir}/random.h \
	${bits_srcdir}/random.tcc \
	${bits_srcdir}/regex.h \
	${bits_srcdir}/regex.tcc \
	${bits_srcdir}/regex_constants.h \
	${bits_srcdir}/regex_error.h \
	${bits_srcdir}/regex_scanner.h \
	${bits_srcdir}/regex_scanner.tcc \
	${bits_srcdir}/regex_automaton.h \
	${bits_srcdir}/regex_automaton.tcc \
	${bits_srcdir}/regex_compiler.h \
	${bits_srcdir}/regex_compiler.tcc \
	${bits_srcdir}/regex_executor.h \
	${bits_srcdir}/regex_executor.tcc \
	${bits_srcdir}/requires_hosted.h \
	${bits_srcdir}/semaphore_base.h \
	${bits_srcdir}/shared_ptr.h \
	${bits_srcdir}/shared_ptr_atomic.h \
	${bits_srcdir}/shared_ptr_base.h \
	${bits_srcdir}/slice_array.h \
	${bits_srcdir}/specfun.h \
	${bits_srcdir}/sstream.tcc \
	${bits_srcdir}/std_abs.h \
	${bits_srcdir}/std_function.h \
	${bits_srcdir}/std_mutex.h \
	${bits_srcdir}/std_thread.h \
	${bits_srcdir}/stl_bvector.h \
	${bits_srcdir}/stl_deque.h \
	${bits_srcdir}/stl_list.h \
	${bits_srcdir}/stl_map.h \
	${bits_srcdir}/stl_multimap.h \
	${bits_srcdir}/stl_multiset.h \
	${bits_srcdir}/stl_queue.h \
	${bits_srcdir}/stl_relops.h \
	${bits_srcdir}/stl_set.h \
	${bits_srcdir}/stl_stack.h \
	${bits_srcdir}/stl_tempbuf.h \
	${bits_srcdir}/stl_tree.h \
	${bits_srcdir}/stl_vector.h \
	${bits_srcdir}/stream_iterator.h \
	${bits_srcdir}/streambuf_iterator.h \
	${bits_srcdir}/streambuf.tcc \
	${bits_srcdir}/stringfwd.h \
	${bits_srcdir}/this_thread_sleep.h \
	${bits_srcdir}/unique_lock.h \
	${bits_srcdir}/unordered_map.h \
	${bits_srcdir}/unordered_set.h \
	${bits_srcdir}/valarray_array.h \
	${bits_srcdir}/valarray_array.tcc \
	${bits_srcdir}/valarray_before.h \
	${bits_srcdir}/valarray_after.h \
	${bits_srcdir}/vector.tcc
endif GLIBCXX_HOSTED

bits_host_headers = \
	${glibcxx_srcdir}/${CPU_OPT_BITS_RANDOM}

bits_sup_srcdir =
bits_sup_headers =

# C++17 Parallel Algorithm Includes.
pstl_srcdir =
pstl_builddir =
pstl_headers =

backward_srcdir = ${glibcxx_srcdir}/include/backward
backward_builddir = ./backward
backward_freestanding = \
	${backward_srcdir}/auto_ptr.h \
	${backward_srcdir}/binders.h

if !GLIBCXX_HOSTED
backward_headers = ${backward_freestanding}
else GLIBCXX_HOSTED
backward_headers = \
	${backward_freestanding} \
	${backward_srcdir}/backward_warning.h \
	${backward_srcdir}/hash_map \
	${backward_srcdir}/hash_set \
	${backward_srcdir}/hash_fun.h \
	${backward_srcdir}/hashtable.h \
	${backward_srcdir}/strstream
endif GLIBCXX_HOSTED

pb_srcdir = ${glibcxx_srcdir}/include/ext/pb_ds
pb_builddir = ./ext/pb_ds

pb_subdirs = \
	${pb_builddir}/detail \
	${pb_builddir}/detail/pairing_heap_ \
	${pb_builddir}/detail/splay_tree_ \
	${pb_builddir}/detail/list_update_map_ \
	${pb_builddir}/detail/branch_policy \
	${pb_builddir}/detail/trie_policy \
	${pb_builddir}/detail/gp_hash_table_map_ \
	${pb_builddir}/detail/tree_policy \
	${pb_builddir}/detail/binomial_heap_base_ \
	${pb_builddir}/detail/resize_policy \
	${pb_builddir}/detail/bin_search_tree_ \
	${pb_builddir}/detail/binomial_heap_ \
	${pb_builddir}/detail/thin_heap_ \
	${pb_builddir}/detail/pat_trie_ \
	${pb_builddir}/detail/cc_hash_table_map_ \
	${pb_builddir}/detail/rc_binomial_heap_ \
	${pb_builddir}/detail/left_child_next_sibling_heap_ \
	${pb_builddir}/detail/unordered_iterator \
	${pb_builddir}/detail/binary_heap_ \
	${pb_builddir}/detail/ov_tree_map_ \
	${pb_builddir}/detail/hash_fn \
	${pb_builddir}/detail/eq_fn \
	${pb_builddir}/detail/rb_tree_map_ \
	${pb_builddir}/detail/list_update_policy

# The ability for make and the underlying host to deal with this
# unwieldy list as one entire entity is not a sure thing, and may
# cause build errors. Thus, split one list into many smaller
# mini-lists, with the maximum size per mini-list of no more than 42.

pb_headers1 = \
	${pb_srcdir}/assoc_container.hpp \
	${pb_srcdir}/exception.hpp \
	${pb_srcdir}/hash_policy.hpp \
	${pb_srcdir}/list_update_policy.hpp \
	${pb_srcdir}/priority_queue.hpp \
	${pb_srcdir}/tag_and_trait.hpp \
	${pb_srcdir}/tree_policy.hpp \
	${pb_srcdir}/trie_policy.hpp \
	${pb_srcdir}/detail/branch_policy/branch_policy.hpp \
	${pb_srcdir}/detail/branch_policy/null_node_metadata.hpp \
	${pb_srcdir}/detail/branch_policy/traits.hpp \
	${pb_srcdir}/detail/binary_heap_/binary_heap_.hpp \
	${pb_srcdir}/detail/binary_heap_/const_iterator.hpp \
	${pb_srcdir}/detail/binary_heap_/point_const_iterator.hpp \
	${pb_srcdir}/detail/binary_heap_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/entry_cmp.hpp \
	${pb_srcdir}/detail/binary_heap_/entry_pred.hpp \
	${pb_srcdir}/detail/binary_heap_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/find_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/info_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/iterators_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/policy_access_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/resize_policy.hpp \
	${pb_srcdir}/detail/binary_heap_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/binary_heap_/trace_fn_imps.hpp \
	${pb_srcdir}/detail/binomial_heap_base_/binomial_heap_base_.hpp \
	${pb_srcdir}/detail/binomial_heap_base_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/binomial_heap_base_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/binomial_heap_base_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/binomial_heap_base_/find_fn_imps.hpp \
	${pb_srcdir}/detail/binomial_heap_base_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/binomial_heap_base_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/binomial_heap_/binomial_heap_.hpp \
	${pb_srcdir}/detail/binomial_heap_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/binomial_heap_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/bin_search_tree_.hpp

pb_headers2 = \
	${pb_srcdir}/detail/bin_search_tree_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/find_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/info_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/iterators_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/node_iterators.hpp \
	${pb_srcdir}/detail/bin_search_tree_/point_iterators.hpp \
	${pb_srcdir}/detail/bin_search_tree_/policy_access_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/r_erase_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/rotate_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/bin_search_tree_/traits.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/cc_ht_map_.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/cmp_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/cond_key_dtor_entry_dealtor.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/constructor_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/constructor_destructor_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/constructor_destructor_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/debug_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/debug_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/entry_list_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/erase_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/erase_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/find_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/find_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/info_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/insert_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/insert_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/iterators_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/policy_access_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/resize_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/resize_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/resize_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/cc_hash_table_map_/size_fn_imps.hpp

pb_headers3 = \
	${pb_srcdir}/detail/cc_hash_table_map_/trace_fn_imps.hpp \
	${pb_srcdir}/detail/cond_dealtor.hpp \
	${pb_srcdir}/detail/container_base_dispatch.hpp \
	${pb_srcdir}/detail/eq_fn/eq_by_less.hpp \
	${pb_srcdir}/detail/eq_fn/hash_eq_fn.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/constructor_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/constructor_destructor_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/constructor_destructor_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/debug_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/debug_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/erase_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/erase_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/find_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/find_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/find_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/gp_ht_map_.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/info_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/insert_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/insert_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/iterator_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/policy_access_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/resize_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/resize_no_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/resize_store_hash_fn_imps.hpp \
	${pb_srcdir}/detail/gp_hash_table_map_/trace_fn_imps.hpp \
	${pb_srcdir}/detail/hash_fn/direct_mask_range_hashing_imp.hpp \
	${pb_srcdir}/detail/hash_fn/direct_mod_range_hashing_imp.hpp \
	${pb_srcdir}/detail/hash_fn/linear_probe_fn_imp.hpp \
	${pb_srcdir}/detail/hash_fn/mask_based_range_hashing.hpp \
	${pb_srcdir}/detail/hash_fn/mod_based_range_hashing.hpp \
	${pb_srcdir}/detail/hash_fn/probe_fn_base.hpp \
	${pb_srcdir}/detail/hash_fn/quadratic_probe_fn_imp.hpp \
	${pb_srcdir}/detail/hash_fn/ranged_hash_fn.hpp \
	${pb_srcdir}/detail/hash_fn/ranged_probe_fn.hpp

pb_headers4 = \
	${pb_srcdir}/detail/hash_fn/sample_probe_fn.hpp \
	${pb_srcdir}/detail/hash_fn/sample_ranged_hash_fn.hpp \
	${pb_srcdir}/detail/hash_fn/sample_ranged_probe_fn.hpp \
	${pb_srcdir}/detail/hash_fn/sample_range_hashing.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/const_iterator.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/point_const_iterator.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/info_fn_imps.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/iterators_fn_imps.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/left_child_next_sibling_heap_.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/node.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/policy_access_fn_imps.hpp \
	${pb_srcdir}/detail/left_child_next_sibling_heap_/trace_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_map_/constructor_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_map_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_map_/entry_metadata_base.hpp \
	${pb_srcdir}/detail/list_update_map_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_map_/find_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_map_/info_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_map_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_map_/iterators_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_map_/lu_map_.hpp \
	${pb_srcdir}/detail/list_update_map_/trace_fn_imps.hpp \
	${pb_srcdir}/detail/list_update_policy/lu_counter_metadata.hpp \
	${pb_srcdir}/detail/list_update_policy/sample_update_policy.hpp \
	${pb_srcdir}/detail/debug_map_base.hpp \
	${pb_srcdir}/detail/ov_tree_map_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/ov_tree_map_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/ov_tree_map_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/ov_tree_map_/info_fn_imps.hpp \
	${pb_srcdir}/detail/ov_tree_map_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/ov_tree_map_/iterators_fn_imps.hpp \
	${pb_srcdir}/detail/ov_tree_map_/node_iterators.hpp \
	${pb_srcdir}/detail/ov_tree_map_/ov_tree_map_.hpp

pb_headers5 = \
	${pb_srcdir}/detail/ov_tree_map_/policy_access_fn_imps.hpp \
	${pb_srcdir}/detail/ov_tree_map_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/ov_tree_map_/traits.hpp \
	${pb_srcdir}/detail/pairing_heap_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/pairing_heap_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/pairing_heap_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/pairing_heap_/find_fn_imps.hpp \
	${pb_srcdir}/detail/pairing_heap_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/pairing_heap_/pairing_heap_.hpp \
	${pb_srcdir}/detail/pairing_heap_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/find_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/info_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/insert_join_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/iterators_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/pat_trie_.hpp \
	${pb_srcdir}/detail/pat_trie_/pat_trie_base.hpp \
	${pb_srcdir}/detail/pat_trie_/policy_access_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/r_erase_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/rotate_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/split_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/synth_access_traits.hpp \
	${pb_srcdir}/detail/pat_trie_/trace_fn_imps.hpp \
	${pb_srcdir}/detail/pat_trie_/traits.hpp \
	${pb_srcdir}/detail/pat_trie_/update_fn_imps.hpp \
	${pb_srcdir}/detail/priority_queue_base_dispatch.hpp \
	${pb_srcdir}/detail/rb_tree_map_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/rb_tree_map_/debug_fn_imps.hpp

pb_headers6 = \
	${pb_srcdir}/detail/rb_tree_map_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/rb_tree_map_/find_fn_imps.hpp \
	${pb_srcdir}/detail/rb_tree_map_/info_fn_imps.hpp \
	${pb_srcdir}/detail/rb_tree_map_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/rb_tree_map_/node.hpp \
	${pb_srcdir}/detail/rb_tree_map_/rb_tree_.hpp \
	${pb_srcdir}/detail/rb_tree_map_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/rb_tree_map_/traits.hpp \
	${pb_srcdir}/detail/rc_binomial_heap_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/rc_binomial_heap_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/rc_binomial_heap_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/rc_binomial_heap_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/rc_binomial_heap_/rc_binomial_heap_.hpp \
	${pb_srcdir}/detail/rc_binomial_heap_/rc.hpp \
	${pb_srcdir}/detail/rc_binomial_heap_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/rc_binomial_heap_/trace_fn_imps.hpp \
	${pb_srcdir}/detail/resize_policy/cc_hash_max_collision_check_resize_trigger_imp.hpp \
	${pb_srcdir}/detail/resize_policy/hash_exponential_size_policy_imp.hpp \
	${pb_srcdir}/detail/resize_policy/hash_load_check_resize_trigger_imp.hpp \
	${pb_srcdir}/detail/resize_policy/hash_load_check_resize_trigger_size_base.hpp \
	${pb_srcdir}/detail/resize_policy/hash_prime_size_policy_imp.hpp \
	${pb_srcdir}/detail/resize_policy/hash_standard_resize_policy_imp.hpp \
	${pb_srcdir}/detail/resize_policy/sample_resize_policy.hpp \
	${pb_srcdir}/detail/resize_policy/sample_resize_trigger.hpp \
	${pb_srcdir}/detail/resize_policy/sample_size_policy.hpp \
	${pb_srcdir}/detail/splay_tree_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/splay_tree_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/splay_tree_/erase_fn_imps.hpp \
	${pb_srcdir}/detail/splay_tree_/find_fn_imps.hpp \
	${pb_srcdir}/detail/splay_tree_/info_fn_imps.hpp \
	${pb_srcdir}/detail/splay_tree_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/splay_tree_/node.hpp \
	${pb_srcdir}/detail/splay_tree_/splay_fn_imps.hpp \
	${pb_srcdir}/detail/splay_tree_/splay_tree_.hpp \
	${pb_srcdir}/detail/splay_tree_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/splay_tree_/traits.hpp \
	${pb_srcdir}/detail/standard_policies.hpp \
	${pb_srcdir}/detail/thin_heap_/constructors_destructor_fn_imps.hpp \
	${pb_srcdir}/detail/thin_heap_/debug_fn_imps.hpp \
	${pb_srcdir}/detail/thin_heap_/erase_fn_imps.hpp

pb_headers7 = \
	${pb_srcdir}/detail/thin_heap_/find_fn_imps.hpp \
	${pb_srcdir}/detail/thin_heap_/insert_fn_imps.hpp \
	${pb_srcdir}/detail/thin_heap_/split_join_fn_imps.hpp \
	${pb_srcdir}/detail/thin_heap_/thin_heap_.hpp \
	${pb_srcdir}/detail/thin_heap_/trace_fn_imps.hpp \
	${pb_srcdir}/detail/tree_policy/node_metadata_selector.hpp \
	${pb_srcdir}/detail/tree_policy/order_statistics_imp.hpp \
	${pb_srcdir}/detail/tree_policy/sample_tree_node_update.hpp \
	${pb_srcdir}/detail/tree_trace_base.hpp \
	${pb_srcdir}/detail/trie_policy/node_metadata_selector.hpp \
	${pb_srcdir}/detail/trie_policy/order_statistics_imp.hpp \
	${pb_srcdir}/detail/trie_policy/prefix_search_node_update_imp.hpp \
	${pb_srcdir}/detail/trie_policy/sample_trie_access_traits.hpp \
	${pb_srcdir}/detail/trie_policy/sample_trie_node_update.hpp \
	${pb_srcdir}/detail/trie_policy/trie_string_access_traits_imp.hpp \
	${pb_srcdir}/detail/trie_policy/trie_policy_base.hpp \
	${pb_srcdir}/detail/types_traits.hpp \
	${pb_srcdir}/detail/type_utils.hpp \
	${pb_srcdir}/detail/unordered_iterator/const_iterator.hpp \
	${pb_srcdir}/detail/unordered_iterator/point_const_iterator.hpp \
	${pb_srcdir}/detail/unordered_iterator/iterator.hpp \
	${pb_srcdir}/detail/unordered_iterator/point_iterator.hpp


ext_srcdir = ${glibcxx_srcdir}/include/ext
ext_builddir = ./ext
ext_freestanding = \
	${ext_srcdir}/aligned_buffer.h \
	${ext_srcdir}/alloc_traits.h \
	${ext_srcdir}/atomicity.h \
	${ext_srcdir}/cast.h \
	${ext_srcdir}/concurrence.h \
	${ext_srcdir}/numeric_traits.h \
	${ext_srcdir}/iterator \
	${ext_srcdir}/pointer.h \
	${ext_srcdir}/type_traits.h \
	${ext_srcdir}/typelist.h

if !GLIBCXX_HOSTED
ext_headers = ${ext_freestanding}
else GLIBCXX_HOSTED
ext_headers = \
	${ext_freestanding} \
	${ext_srcdir}/algorithm \
	${ext_srcdir}/bitmap_allocator.h \
	${ext_srcdir}/cmath \
	${ext_srcdir}/codecvt_specializations.h \
	${ext_srcdir}/debug_allocator.h \
	${ext_srcdir}/enc_filebuf.h \
	${ext_srcdir}/extptr_allocator.h \
	${ext_srcdir}/functional \
	${ext_srcdir}/malloc_allocator.h \
	${ext_srcdir}/memory \
	${ext_srcdir}/mt_allocator.h \
	${ext_srcdir}/new_allocator.h \
	${ext_srcdir}/numeric \
	${ext_srcdir}/pod_char_traits.h \
	${ext_srcdir}/pool_allocator.h \
	${ext_srcdir}/random \
	${ext_srcdir}/random.tcc \
	${ext_srcdir}/rb_tree \
	${ext_srcdir}/rc_string_base.h \
	${ext_srcdir}/rope \
	${ext_srcdir}/ropeimpl.h \
	${ext_srcdir}/slist \
	${ext_srcdir}/sso_string_base.h \
	${ext_srcdir}/stdio_filebuf.h \
	${ext_srcdir}/stdio_sync_filebuf.h \
	${ext_srcdir}/string_conversions.h \
	${ext_srcdir}/throw_allocator.h \
	${ext_srcdir}/vstring_fwd.h \
	${ext_srcdir}/vstring.h \
	${ext_srcdir}/vstring.tcc \
	${ext_srcdir}/vstring_util.h \
	${ext_compat_headers}
endif GLIBCXX_HOSTED

ext_compat_headers = \
	${backward_srcdir}/hash_set \
	${backward_srcdir}/hash_map

ext_host_headers = \
	${glibcxx_srcdir}/${CPU_OPT_EXT_RANDOM}

tr1_srcdir =
tr1_builddir =
tr1_headers =

tr2_srcdir =
tr2_builddir =
tr2_headers =

decimal_srcdir = ${glibcxx_srcdir}/include/decimal
decimal_builddir = ./decimal
decimal_headers = \
	${decimal_srcdir}/decimal \
	${decimal_srcdir}/decimal.h

# Post-C++11 TS's
experimental_srcdir =
experimental_builddir =
experimental_headers =

experimental_bits_srcdir =
experimental_bits_builddir =
experimental_bits_headers =

if ENABLE_FILESYSTEM_TS
experimental_filesystem_headers = \
	${experimental_srcdir}/filesystem
experimental_bits_filesystem_headers = \
	${experimental_bits_srcdir}/fs_dir.h \
	${experimental_bits_srcdir}/fs_fwd.h \
	${experimental_bits_srcdir}/fs_ops.h \
	${experimental_bits_srcdir}/fs_path.h
else
experimental_filesystem_headers =
experimental_bits_filesystem_headers =
endif

# This is the common subset of C++ files that all three "C" header models use.
c_base_srcdir = $(C_INCLUDE_DIR)
c_base_builddir = .
c_base_freestanding = \
	${c_base_srcdir}/cfloat \
	${c_base_srcdir}/climits \
	${c_base_srcdir}/cstddef \
	${c_base_srcdir}/cstdint \
	${c_base_srcdir}/cstdlib

if !GLIBCXX_HOSTED
c_base_headers = ${c_base_freestanding}
else GLIBCXX_HOSTED
c_base_headers = \
	${c_base_freestanding} \
	${c_base_srcdir}/cassert \
	${c_base_srcdir}/ccomplex \
	${c_base_srcdir}/cctype \
	${c_base_srcdir}/cerrno \
	${c_base_srcdir}/cfenv \
	${c_base_srcdir}/cinttypes \
	${c_base_srcdir}/ciso646 \
	${c_base_srcdir}/clocale \
	${c_base_srcdir}/cmath \
	${c_base_srcdir}/csetjmp \
	${c_base_srcdir}/csignal \
	${c_base_srcdir}/cstdalign \
	${c_base_srcdir}/cstdarg \
	${c_base_srcdir}/cstdbool \
	${c_base_srcdir}/cstdio \
	${c_base_srcdir}/cstring \
	${c_base_srcdir}/ctgmath \
	${c_base_srcdir}/ctime \
	${c_base_srcdir}/cuchar \
	${c_base_srcdir}/cwchar \
	${c_base_srcdir}/cwctype
endif GLIBCXX_HOSTED

# "C" compatibility headers.
c_compatibility_srcdir =
c_compatibility_builddir =

if GLIBCXX_C_HEADERS_C_STD
c_compatibility_headers =
endif

if GLIBCXX_C_HEADERS_C_GLOBAL
c_compatibility_headers = \
	${c_compatibility_srcdir}/complex.h \
	${c_compatibility_srcdir}/fenv.h \
	${c_compatibility_srcdir}/tgmath.h \
	${c_compatibility_srcdir}/math.h \
	${c_compatibility_srcdir}/stdatomic.h \
	${c_compatibility_srcdir}/stdlib.h
endif

if GLIBCXX_C_HEADERS_C
c_compatibility_headers = \
	${c_compatibility_srcdir}/assert.h \
	${c_compatibility_srcdir}/complex.h \
	${c_compatibility_srcdir}/ctype.h \
	${c_compatibility_srcdir}/errno.h \
	${c_compatibility_srcdir}/fenv.h \
	${c_compatibility_srcdir}/float.h \
	${c_compatibility_srcdir}/inttypes.h \
	${c_compatibility_srcdir}/iso646.h \
	${c_compatibility_srcdir}/limits.h \
	${c_compatibility_srcdir}/locale.h \
	${c_compatibility_srcdir}/math.h \
	${c_compatibility_srcdir}/setjmp.h \
	${c_compatibility_srcdir}/signal.h \
	${c_compatibility_srcdir}/stdarg.h \
	${c_compatibility_srcdir}/stdbool.h \
	${c_compatibility_srcdir}/stddef.h \
	${c_compatibility_srcdir}/stdint.h \
	${c_compatibility_srcdir}/stdio.h \
	${c_compatibility_srcdir}/stdlib.h \
	${c_compatibility_srcdir}/string.h \
	${c_compatibility_srcdir}/tgmath.h \
	${c_compatibility_srcdir}/time.h \
	${c_compatibility_srcdir}/uchar.h \
	${c_compatibility_srcdir}/wchar.h \
	${c_compatibility_srcdir}/wctype.h
endif

# Debug mode headers
debug_srcdir = ${glibcxx_srcdir}/include/debug
debug_builddir = ./debug
debug_freestanding = \
	${debug_srcdir}/assertions.h \
	${debug_srcdir}/debug.h

if !GLIBCXX_HOSTED
debug_headers = ${debug_freestanding}
else GLIBCXX_HOSTED
debug_headers = \
	${debug_freestanding} \
	${debug_srcdir}/bitset \
	${debug_srcdir}/deque \
	${debug_srcdir}/formatter.h \
	${debug_srcdir}/forward_list \
	${debug_srcdir}/functions.h \
	${debug_srcdir}/helper_functions.h \
	${debug_srcdir}/list \
	${debug_srcdir}/map \
	${debug_srcdir}/macros.h \
	${debug_srcdir}/map.h \
	${debug_srcdir}/multimap.h \
	${debug_srcdir}/multiset.h \
	${debug_srcdir}/safe_base.h \
	${debug_srcdir}/safe_container.h \
	${debug_srcdir}/safe_iterator.h \
	${debug_srcdir}/safe_iterator.tcc \
	${debug_srcdir}/safe_local_iterator.h \
	${debug_srcdir}/safe_local_iterator.tcc \
	${debug_srcdir}/safe_sequence.h \
	${debug_srcdir}/safe_sequence.tcc \
	${debug_srcdir}/safe_unordered_base.h \
	${debug_srcdir}/safe_unordered_container.h \
	${debug_srcdir}/safe_unordered_container.tcc \
	${debug_srcdir}/set \
	${debug_srcdir}/set.h \
	${debug_srcdir}/stl_iterator.h \
	${debug_srcdir}/string \
	${debug_srcdir}/unordered_map \
	${debug_srcdir}/unordered_set \
	${debug_srcdir}/vector
endif GLIBCXX_HOSTED

# Parallel mode headers
parallel_srcdir =
parallel_builddir =
parallel_headers =

# Some "C" header schemes require the "C" compatibility headers.
# For --enable-cheaders=c_std
if GLIBCXX_C_HEADERS_COMPATIBILITY
c_compatibility_headers_extra = ${c_compatibility_headers}
else
c_compatibility_headers_extra =
endif

host_srcdir = ${glibcxx_srcdir}/$(OS_INC_SRCDIR)
host_builddir = ./${host_alias}/bits
host_installdir = ${gxx_include_dir}/${host_alias}$(MULTISUBDIR)/bits
host_headers = \
	${host_srcdir}/ctype_base.h \
	${host_srcdir}/ctype_inline.h \
	${host_srcdir}/os_defines.h \
	${glibcxx_srcdir}/$(ATOMIC_WORD_SRCDIR)/atomic_word.h \
	${glibcxx_srcdir}/$(ABI_TWEAKS_SRCDIR)/cxxabi_tweaks.h \
	${glibcxx_srcdir}/$(CPU_DEFINES_SRCDIR)/cpu_defines.h \
	${glibcxx_srcdir}/$(ERROR_CONSTANTS_SRCDIR)/error_constants.h

# Non-installed host_header files.
COMPATIBILITY_H = config/abi/compatibility.h
host_headers_noinst = \
	${glibcxx_srcdir}/$(CLOCALE_INTERNAL_H) \
	${glibcxx_srcdir}/$(COMPATIBILITY_H)

# These host_headers_extra files are all built with ad hoc naming rules.
host_headers_extra = \
	${host_builddir}/basic_file.h \
	${host_builddir}/c++config.h \
	${host_builddir}/c++allocator.h \
	${host_builddir}/c++io.h \
	${host_builddir}/c++locale.h \
	${host_builddir}/messages_members.h \
	${host_builddir}/time_members.h

thread_host_headers = \
	${host_builddir}/gthr.h \
	${host_builddir}/gthr-single.h \
	${host_builddir}/gthr-posix.h \
	${host_builddir}/gthr-default.h


pch1_source =
pch1_output_builddir = ${host_builddir}/stdc++.h.gch
pch1_output_anchor = ${host_builddir}/stdc++.h
pch1_output_installdir = ${host_installdir}/stdc++.h.gch
pch1a_output = ${pch1_output_builddir}/O2ggnu++0x.gch
pch1b_output = ${pch1_output_builddir}/O2g.gch
pch1_output = ${pch1a_output} ${pch1b_output}

pch2_source =
pch2_output_builddir = ${host_builddir}/stdtr1c++.h.gch
pch2_output_anchor = ${host_builddir}/stdtr1c++.h
pch2_output_installdir = ${host_installdir}/stdtr1c++.h.gch
pch2_output = ${pch2_output_builddir}/O2g.gch

pch3_source =
pch3_output_builddir = ${host_builddir}/extc++.h.gch
pch3_output_anchor = ${host_builddir}/extc++.h
pch3_output_installdir = ${host_installdir}/extc++.h.gch
pch3_output = ${pch3_output_builddir}/O2g.gch


pch_output = ${pch1_output} ${pch2_output} ${pch3_output}
pch_output_dirs = \
	${pch1_output_builddir} ${pch2_output_builddir} ${pch3_output_builddir}
pch_output_anchors = \
	${pch1_output_anchor} ${pch2_output_anchor} ${pch3_output_anchor}
PCHFLAGS=-x c++-header -nostdinc++ $(CXXFLAGS) $(VTV_PCH_CXXFLAGS)
if GLIBCXX_BUILD_PCH
pch_build = ${pch_output}
else
pch_build =
endif

# List of all timestamp files.  By keeping only one copy of this list, both
# CLEANFILES and all-local are kept up-to-date.
allstamped = \
	stamp-bits stamp-c_base \
	stamp-backward stamp-ext stamp-pb stamp-decimal stamp-debug stamp-host

# List of all files that are created by explicit building, editing, or
# catenation.
allcreated = \
	${host_builddir}/c++config.h \
	${host_builddir}/largefile-config.h \
	${thread_host_headers} \
	${pch_build}

# Here are the rules for building the headers
all-local: ${allstamped} ${allcreated}

# Ignore errors from 'mkdir -p' to avoid parallel make failure on
# systems with broken mkdir.  Call mkdir unconditionally because
# it is just as cheap to avoid going through the shell.
# Ignore errors from $(LN_S) because the links may already exist.
stamp-std:

stamp-bits: ${bits_headers}
	@-mkdir -p ${bits_builddir}
	@-cd ${bits_builddir} && $(LN_S) $? . 2>/dev/null
	@$(STAMP) stamp-bits

stamp-bits-sup:

stamp-pstl:

stamp-c_base: ${c_base_headers}
	@-mkdir -p ${c_base_builddir}
	@-cd ${c_base_builddir} && $(LN_S) $? . 2>/dev/null
	@$(STAMP) stamp-c_base

stamp-c_base_extra: ${c_base_headers_extra}
	@-mkdir -p ${bits_builddir}
	@-cd ${bits_builddir} && $(LN_S) $? . 2>/dev/null
	@$(STAMP) stamp-c_base_extra

stamp-c_compatibility:

stamp-backward: ${backward_headers}
	@-mkdir -p ${backward_builddir}
	@-cd ${backward_builddir} && $(LN_S) $? . 2>/dev/null
	@$(STAMP) stamp-backward

stamp-ext: ${ext_headers}
	@-mkdir -p ${ext_builddir}
	@-cd ${ext_builddir} && $(LN_S) $? . 2>/dev/null
	@$(STAMP) stamp-ext

# Have to deal with nested include directories, gah! Strip off source
# directory before making the link.
# XXX check  ${pb_headers}
stamp-pb:
	@if [ ! -d "${pb_builddir}" ]; then \
	    mkdir -p ${pb_subdirs} ;\
	fi
	@if [ ! -f stamp-pb ]; then \
	    cd ${pb_builddir} && for h in ${pb_headers1}; do \
		build_name=`echo $$h | sed -e "s|${pb_srcdir}|.|g"` ;\
		$(LN_S) $$h $${build_name} || true ;\
	      done ;\
	fi
	@if [ ! -f stamp-pb ]; then \
	    cd ${pb_builddir} && for h in ${pb_headers2}; do \
		build_name=`echo $$h | sed -e "s|${pb_srcdir}|.|g"` ;\
		$(LN_S) $$h $${build_name} || true ;\
	      done ;\
	fi
	@if [ ! -f stamp-pb ]; then \
	    cd ${pb_builddir} && for h in ${pb_headers3}; do \
		build_name=`echo $$h | sed -e "s|${pb_srcdir}|.|g"` ;\
		$(LN_S) $$h $${build_name} || true ;\
	      done ;\
	fi
	@if [ ! -f stamp-pb ]; then \
	    cd ${pb_builddir} && for h in ${pb_headers4}; do \
		build_name=`echo $$h | sed -e "s|${pb_srcdir}|.|g"` ;\
		$(LN_S) $$h $${build_name} || true ;\
	      done ;\
	fi
	@if [ ! -f stamp-pb ]; then \
	    cd ${pb_builddir} && for h in ${pb_headers5}; do \
		build_name=`echo $$h | sed -e "s|${pb_srcdir}|.|g"` ;\
		$(LN_S) $$h $${build_name} || true ;\
	      done ;\
	fi
	@if [ ! -f stamp-pb ]; then \
	    cd ${pb_builddir} && for h in ${pb_headers6}; do \
		build_name=`echo $$h | sed -e "s|${pb_srcdir}|.|g"` ;\
		$(LN_S) $$h $${build_name} || true ;\
	      done ;\
	fi
	@if [ ! -f stamp-pb ]; then \
	    cd ${pb_builddir} && for h in ${pb_headers7}; do \
		build_name=`echo $$h | sed -e "s|${pb_srcdir}|.|g"` ;\
		$(LN_S) $$h $${build_name} || true ;\
	      done ;\
	fi
	$(STAMP) stamp-pb

stamp-tr1:

stamp-tr2:

stamp-decimal: ${decimal_headers}
	@-mkdir -p ${decimal_builddir}
	@-cd ${decimal_builddir} && $(LN_S) $? . 2>/dev/null
	@$(STAMP) stamp-decimal

stamp-experimental:

stamp-experimental-bits:

stamp-debug: ${debug_headers}
	@-mkdir -p ${debug_builddir}
	@-cd ${debug_builddir} && $(LN_S) $? . 2>/dev/null
	@$(STAMP) stamp-debug

stamp-parallel:

stamp-${host_alias}:
	@-mkdir -p ${host_builddir}
	@-mkdir -p ${host_builddir}/../ext
	@$(STAMP) stamp-${host_alias}

# Host includes static.
# XXX Missing dependency info for {host_headers_extra}
stamp-host: ${host_headers} ${bits_host_headers} ${ext_host_headers} ${host_headers_noinst} stamp-${host_alias}
	@cd ${host_builddir} && {\
	  $(LN_S) ${host_headers} ${bits_host_headers} . || true ;\
	  $(LN_S) ${glibcxx_srcdir}/$(BASIC_FILE_H) basic_file.h || true ;\
	  $(LN_S) ${glibcxx_srcdir}/$(ALLOCATOR_H) c++allocator.h || true ;\
	  $(LN_S) ${glibcxx_srcdir}/$(CSTDIO_H) c++io.h || true ;\
	  $(LN_S) ${glibcxx_srcdir}/$(CLOCALE_H) c++locale.h || true ;\
	  $(LN_S) ${glibcxx_srcdir}/$(CLOCALE_INTERNAL_H) . || true ;\
	  $(LN_S) ${glibcxx_srcdir}/$(COMPATIBILITY_H) . || true ;\
	  $(LN_S) ${glibcxx_srcdir}/$(CMESSAGES_H) messages_members.h || true ;\
	  $(LN_S) ${glibcxx_srcdir}/$(CTIME_H) time_members.h || true;\
	} 2>/dev/null
	@cd ${host_builddir}/../ext && {\
	  $(LN_S) ${ext_host_headers} . || true ;\
	} 2>/dev/null
	$(STAMP) stamp-host

# Host includes dynamic.
if ENABLE_SYMVERS_GNU_NAMESPACE
stamp-namespace-version:
	echo 1 > stamp-namespace-version
else
stamp-namespace-version:
	echo 0 > stamp-namespace-version
endif

if ENABLE_EXTERN_TEMPLATE
stamp-extern-template:
	echo 1 > stamp-extern-template
else
stamp-extern-template:
	echo 0 > stamp-extern-template
endif

if ENABLE_VISIBILITY
stamp-visibility:
	echo 1 > stamp-visibility
else
stamp-visibility:
	echo 0 > stamp-visibility
endif

if ENABLE_DUAL_ABI
stamp-dual-abi:
	echo 1 > stamp-dual-abi
else
stamp-dual-abi:
	echo 0 > stamp-dual-abi
endif

if ENABLE_CXX11_ABI
stamp-cxx11-abi:
	echo 1 > stamp-cxx11-abi
else
stamp-cxx11-abi:
	echo 0 > stamp-cxx11-abi
endif

if ENABLE_ALLOCATOR_NEW
stamp-allocator-new:
	echo 1 > stamp-allocator-new
else
stamp-allocator-new:
	echo 0 > stamp-allocator-new
endif

if ENABLE_FLOAT128
stamp-float128:
	echo 'define _GLIBCXX_USE_FLOAT128 1' > stamp-float128
else
stamp-float128:
	echo 'undef _GLIBCXX_USE_FLOAT128' > stamp-float128
endif

# This header is not installed, it's only used to build libstdc++ itself.
${host_builddir}/largefile-config.h: ${CONFIG_HEADER} stamp-${host_alias}
	@rm -f $@.tmp
	@-grep 'define _DARWIN_USE_64_BIT_INODE' ${CONFIG_HEADER} >> $@.tmp
	@-grep 'define _FILE_OFFSET_BITS' ${CONFIG_HEADER} >> $@.tmp
	@-grep 'define _LARGE_FILES' ${CONFIG_HEADER} >> $@.tmp
	@mv $@.tmp $@

# NB: The non-empty default ldbl_compat works around an AIX sed
# oddity, see libstdc++/31957 for details.
${host_builddir}/c++config.h: ${CONFIG_HEADER} \
			      ${glibcxx_srcdir}/include/bits/c++config \
			      ${host_builddir}/largefile-config.h \
			      stamp-${host_alias} \
			      ${toplevel_srcdir}/spl/DATESTAMP \
			      stamp-namespace-version \
			      stamp-visibility \
			      stamp-extern-template \
			      stamp-dual-abi \
			      stamp-cxx11-abi \
			      stamp-allocator-new \
			      stamp-float128
	@date=`cat ${toplevel_srcdir}/spl/DATESTAMP` ;\
	release=`sed 's/^\([0-9]*\).*$$/\1/' ${toplevel_srcdir}/spl/BASE-VER` ;\
	ns_version=`cat stamp-namespace-version` ;\
	visibility=`cat stamp-visibility` ;\
	externtemplate=`cat stamp-extern-template` ;\
	dualabi=`cat stamp-dual-abi` ;\
	cxx11abi=`cat stamp-cxx11-abi` ;\
	allocatornew=`cat stamp-allocator-new` ;\
	float128=`cat stamp-float128` ;\
	ldbl_compat='s,g,g,' ;\
	grep "^[	 ]*#[	 ]*define[	 ][	 ]*_GLIBCXX_LONG_DOUBLE_COMPAT[	 ][	 ]*1[	 ]*$$" \
	${CONFIG_HEADER} > /dev/null 2>&1 \
	&& ldbl_compat='s,^#undef _GLIBCXX_LONG_DOUBLE_COMPAT$$,#define _GLIBCXX_LONG_DOUBLE_COMPAT 1,' ;\
	ldbl_alt128_compat='s,g,g,' ;\
	grep "^[	 ]*#[	 ]*define[	 ][	 ]*_GLIBCXX_LONG_DOUBLE_ALT128_COMPAT[	 ][	 ]*1[	 ]*$$" \
	${CONFIG_HEADER} > /dev/null 2>&1 \
	&& ldbl_alt128_compat='s,^#undef _GLIBCXX_LONG_DOUBLE_ALT128_COMPAT$$,#define _GLIBCXX_LONG_DOUBLE_ALT128_COMPAT 1,' ;\
	verbose_assert='s,g,g,' ; \
	grep "^[	 ]*#[	 ]*define[	 ][	 ]*_GLIBCXX_HOSTED[	 ][	 ]*__STDC_HOSTED__[	 ]*$$" \
	${CONFIG_HEADER} > /dev/null 2>&1 \
	&& grep "^[	 ]*#[	 ]*define[	 ][	 ]*_GLIBCXX_VERBOSE[	 ][	 ]*1[	 ]*$$" \
	${CONFIG_HEADER} > /dev/null 2>&1 \
	&& verbose_assert='s,^#undef _GLIBCXX_VERBOSE_ASSERT$$,#define _GLIBCXX_VERBOSE_ASSERT 1,' ;\
	sed -e "s,define __GLIBCXX__,define __GLIBCXX__ $$date," \
	-e "s,define _GLIBCXX_RELEASE,define _GLIBCXX_RELEASE $$release," \
	-e "s,define _GLIBCXX_INLINE_VERSION, define _GLIBCXX_INLINE_VERSION $$ns_version," \
	-e "s,define _GLIBCXX_HAVE_ATTRIBUTE_VISIBILITY, define _GLIBCXX_HAVE_ATTRIBUTE_VISIBILITY $$visibility," \
	-e "s,define _GLIBCXX_EXTERN_TEMPLATE$$, define _GLIBCXX_EXTERN_TEMPLATE $$externtemplate," \
	-e "s,define _GLIBCXX_USE_DUAL_ABI, define _GLIBCXX_USE_DUAL_ABI $$dualabi," \
	-e "s,define _GLIBCXX_USE_CXX11_ABI, define _GLIBCXX_USE_CXX11_ABI $$cxx11abi," \
	-e "s,define _GLIBCXX_USE_ALLOCATOR_NEW, define _GLIBCXX_USE_ALLOCATOR_NEW $$allocatornew," \
	-e "s,define _GLIBCXX_USE_FLOAT128,$$float128," \
	-e "$$ldbl_compat" \
	-e "$$ldbl_alt128_compat" \
	-e "$$verbose_assert" \
	    < ${glibcxx_srcdir}/include/bits/c++config > $@ ;\
	sed -e 's/HAVE_/_GLIBCXX_HAVE_/g' \
	    -e 's/PACKAGE/_GLIBCXX_PACKAGE/g' \
	    -e 's/VERSION/_GLIBCXX_VERSION/g' \
	    -e 's/WORDS_/_GLIBCXX_WORDS_/g' \
	    -e 's/LT_OBJDIR/_GLIBCXX_LT_OBJDIR/g' \
	    -e 's/STDC_HEADERS/_GLIBCXX_STDC_HEADERS/g' \
	    -e 's/_DARWIN_USE_64_BIT_INODE/_GLIBCXX_DARWIN_USE_64_BIT_INODE/g' \
	    -e 's/_FILE_OFFSET_BITS/_GLIBCXX_FILE_OFFSET_BITS/g' \
	    -e 's/_LARGE_FILES/_GLIBCXX_LARGE_FILES/g' \
	    -e 's/ICONV_CONST/_GLIBCXX_ICONV_CONST/g' \
	    -e '/[	 ]_GLIBCXX_LONG_DOUBLE_COMPAT[	 ]/d' \
	    -e '/[	 ]_GLIBCXX_LONG_DOUBLE_ALT128_COMPAT[	 ]/d' \
	    < ${CONFIG_HEADER} >> $@ ;\
	echo "" >> $@ ;\
	echo "#endif // _GLIBCXX_CXX_CONFIG_H" >> $@

# Host includes for threads
uppercase = [ABCDEFGHIJKLMNOPQRSTUVWXYZ_]

${host_builddir}/gthr.h: ${toplevel_srcdir}/libgcc/gthr.h stamp-${host_alias}
	sed -e '/^#pragma/b' \
	    -e '/^#/s/\(${uppercase}${uppercase}*\)/_GLIBCXX_\1/g' \
	    -e 's/_GLIBCXX_SUPPORTS_WEAK/__GXX_WEAK__/g' \
	    -e 's/_GLIBCXX___MINGW32_GLIBCXX___/__MINGW32__/g' \
	    -e 's,^#include "\(.*\)",#include <bits/\1>,g' \
	    < $< > $@

${host_builddir}/gthr-single.h: ${toplevel_srcdir}/libgcc/gthr-single.h \
				  stamp-${host_alias}
	sed -e 's/\(UNUSED\)/_GLIBCXX_\1/g' \
	    -e 's/\(GCC${uppercase}*_H\)/_GLIBCXX_\1/g' \
	    < $< > $@

${host_builddir}/gthr-posix.h: ${toplevel_srcdir}/libgcc/gthr-posix.h \
				   stamp-${host_alias}
	sed -e 's/\(UNUSED\)/_GLIBCXX_\1/g' \
	    -e 's/\(GCC${uppercase}*_H\)/_GLIBCXX_\1/g' \
	    -e 's/SUPPORTS_WEAK/__GXX_WEAK__/g' \
	    -e 's/\(${uppercase}*USE_WEAK\)/_GLIBCXX_\1/g' \
	    < $< > $@

${host_builddir}/gthr-default.h: ${toplevel_srcdir}/libgcc/${thread_header} \
				   stamp-${host_alias}
	sed -e 's/\(UNUSED\)/_GLIBCXX_\1/g' \
	    -e 's/\(GCC${uppercase}*_H\)/_GLIBCXX_\1/g' \
	    -e 's/SUPPORTS_WEAK/__GXX_WEAK__/g' \
	    -e 's/\(${uppercase}*USE_WEAK\)/_GLIBCXX_\1/g' \
	    -e 's,^#include "\(.*\)",#include <bits/\1>,g' \
	    < $< > $@

# Build two precompiled C++ includes, stdc++.h.gch/*.gch
${pch1a_output}: ${allstamped} ${host_builddir}/c++config.h ${pch1_source}
	-mkdir -p ${pch1_output_builddir}
	$(CXX) $(PCHFLAGS) $(AM_CPPFLAGS) -O2 -g -std=gnu++0x ${pch1_source} \
	-o $@

${pch1b_output}: ${allstamped} ${host_builddir}/c++config.h ${pch1_source}
	-mkdir -p ${pch1_output_builddir}
	$(CXX) $(PCHFLAGS) $(AM_CPPFLAGS) -O2 -g ${pch1_source} -o $@

# Build a precompiled TR1 include, stdtr1c++.h.gch/O2.gch
${pch2_output}: ${pch2_source} ${pch1_output}
	-mkdir -p ${pch2_output_builddir}
	$(CXX) $(PCHFLAGS) $(AM_CPPFLAGS) -O2 -g ${pch2_source} -o $@

# Build a precompiled extension include, extc++.h.gch/O2.gch
${pch3_output}: ${pch3_source} ${pch2_output}
	-mkdir -p ${pch3_output_builddir}
	$(CXX) $(PCHFLAGS) $(AM_CPPFLAGS) -O2 -g ${pch3_source} -o $@

# The real deal.
install-data-local: install-headers
install-headers:
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${bits_builddir}
	for file in ${bits_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${bits_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${backward_builddir}
	for file in ${backward_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${backward_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${std_builddir}
	for file in ${std_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${std_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${debug_builddir}
	for file in ${debug_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${debug_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${pb_builddir}
	$(mkinstalldirs) $(DESTDIR)${host_installdir}
	for file in ${host_headers} ${bits_host_headers} ${host_headers_extra} \
	 ${thread_host_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${host_installdir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${c_base_builddir}
	for file in ${c_base_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${c_base_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${ext_builddir}
	for file in ${ext_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${ext_builddir}; done
if GLIBCXX_HOSTED
	for dir in ${pb_subdirs}; do \
	  $(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/$${dir} ; done
	for file in ${pb_headers1}; do \
	  install_base=$(DESTDIR)${gxx_include_dir}/${pb_builddir} ; \
	  relative_name=`echo $$file | sed -e "s|${pb_srcdir}|.|g"` ;\
	  $(INSTALL_DATA) $${file} $${install_base}/$${relative_name} ; done
	for file in ${pb_headers2}; do \
	  install_base=$(DESTDIR)${gxx_include_dir}/${pb_builddir} ; \
	  relative_name=`echo $$file | sed -e "s|${pb_srcdir}|.|g"` ;\
	  $(INSTALL_DATA) $${file} $${install_base}/$${relative_name} ; done
	for file in ${pb_headers3}; do \
	  install_base=$(DESTDIR)${gxx_include_dir}/${pb_builddir} ; \
	  relative_name=`echo $$file | sed -e "s|${pb_srcdir}|.|g"` ;\
	  $(INSTALL_DATA) $${file} $${install_base}/$${relative_name} ; done
	for file in ${pb_headers4}; do \
	  install_base=$(DESTDIR)${gxx_include_dir}/${pb_builddir} ; \
	  relative_name=`echo $$file | sed -e "s|${pb_srcdir}|.|g"` ;\
	  $(INSTALL_DATA) $${file} $${install_base}/$${relative_name} ; done
	for file in ${pb_headers5}; do \
	  install_base=$(DESTDIR)${gxx_include_dir}/${pb_builddir} ; \
	  relative_name=`echo $$file | sed -e "s|${pb_srcdir}|.|g"` ;\
	  $(INSTALL_DATA) $${file} $${install_base}/$${relative_name} ; done
	for file in ${pb_headers6}; do \
	  install_base=$(DESTDIR)${gxx_include_dir}/${pb_builddir} ; \
	  relative_name=`echo $$file | sed -e "s|${pb_srcdir}|.|g"` ;\
	  $(INSTALL_DATA) $${file} $${install_base}/$${relative_name} ; done
	for file in ${pb_headers7}; do \
	  install_base=$(DESTDIR)${gxx_include_dir}/${pb_builddir} ; \
	  relative_name=`echo $$file | sed -e "s|${pb_srcdir}|.|g"` ;\
	  $(INSTALL_DATA) $${file} $${install_base}/$${relative_name} ; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${tr1_builddir}
	for file in ${tr1_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${tr1_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${tr2_builddir}
	for file in ${tr2_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${tr2_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${decimal_builddir}
	for file in ${decimal_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${decimal_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${experimental_builddir}
	for file in ${experimental_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${experimental_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${experimental_bits_builddir}
	for file in ${experimental_bits_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${experimental_bits_builddir}; done
	c_base_headers_extra_install='$(c_base_headers_extra)';\
	for file in $$c_base_headers_extra_install; do \
	  $(INSTALL_DATA) $$file $(DESTDIR)${gxx_include_dir}/${bits_builddir}; done
	c_compatibility_headers_install='$(c_compatibility_headers_extra)';\
	for file in $$c_compatibility_headers_install; do \
	  $(INSTALL_DATA) $$file $(DESTDIR)${gxx_include_dir}; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${parallel_builddir}
	for file in ${parallel_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${parallel_builddir}; done
	$(mkinstalldirs) $(DESTDIR)${host_installdir}/../ext
	for file in ${ext_host_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${host_installdir}/../ext; done
	$(mkinstalldirs) $(DESTDIR)${gxx_include_dir}/${pstl_builddir}
	for file in ${pstl_headers}; do \
	  $(INSTALL_DATA) $${file} $(DESTDIR)${gxx_include_dir}/${pstl_builddir}; done
endif GLIBCXX_HOSTED

# By adding these files here, automake will remove them for 'make clean'
CLEANFILES = ${pch_output} ${pch_output_anchors} stamp-host

# To remove directories.
clean-local:
	rm -rf ${pch_output_dirs}

# Stop implicit '.o' make rules from ever stomping on extensionless
# headers, in the improbable case where some foolish, crack-addled
# developer tries to create them via make in the include build
# directory. (This is more of an example of how this kind of rule can
# be made.)
.PRECIOUS: $(std_headers) $(c_base_headers) $(tr1_headers) $(tr2_headers)
	   $(decimal_headers) $(ext_headers) $(experimental_headers)
	   $(experimental_bits_headers)
$(std_headers): ; @:
$(c_base_headers): ; @:
$(tr1_headers): ; @:
$(decimal_headers): ; @:
$(ext_headers): ; @:
$(experimental_headers): ; @:
$(experimental_bits_headers): ; @:

if INCLUDE_DIR_NOTPARALLEL
# See https://spl.gnu.org/bugzilla/show_bug.cgi?id=81797
.NOTPARALLEL:
endif
