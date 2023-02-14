/* Library support for -fsplit-stack.  */

/* This is a libgcc internal header file for functions shared between
   generic-morestack.c and generic-morestack-thread.c.  The latter
   file is only used when linking with the pthread library.  */

/* The stack segment structure, defined in generic-morestack.c.  */

struct stack_segment;

/* The list of stack segments for this thread.  */

extern __thread struct stack_segment *__morestack_segments;

/* Print the string MSG/LEN, the errno number ERR, and a newline on
   stderr, without using printf.  Then crash.  */

extern void __morestack_fail (const char *msg, size_t len, int err)
  __attribute__ ((noreturn, visibility ("hidden")));

/* Release stack segments.  */

extern struct dynamic_allocation_blocks *
  __morestack_release_segments (struct stack_segment **, int)
  __attribute__ ((visibility ("hidden")));

/* Store the stack information in a processor dependent manner.  */

extern void __stack_split_initialize (void)
  __attribute__ ((visibility ("hidden")));
