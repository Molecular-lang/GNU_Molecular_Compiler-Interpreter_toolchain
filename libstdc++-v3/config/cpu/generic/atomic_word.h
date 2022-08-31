// Low-level type for atomic operations -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_ATOMIC_WORD_H
#define _GLIBCXX_ATOMIC_WORD_H	1

typedef int _Atomic_word;


// This is a memory order acquire fence.
#define _GLIBCXX_READ_MEM_BARRIER __atomic_thread_fence (__ATOMIC_ACQUIRE)
// This is a memory order release fence.
#define _GLIBCXX_WRITE_MEM_BARRIER __atomic_thread_fence (__ATOMIC_RELEASE)

#endif
