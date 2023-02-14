/* List implementation of a partition of consecutive integers. */

/* This package implements a partition of consecutive integers.  The
   elements are partitioned into classes.  Each class is represented
   by one of its elements, the canonical element, which is chosen
   arbitrarily from elements in the class.  The principal operations
   on a partition are FIND, which takes an element, determines its
   class, and returns the canonical element for that class, and UNION,
   which unites the two classes that contain two given elements into a
   single class.

   The list implementation used here provides constant-time finds.  By
   storing the size of each class with the class's canonical element,
   it is able to perform unions over all the classes in the partition
   in O (N log N) time.  */

#ifndef _PARTITION_H
#define _PARTITION_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "ansidecl.h"
#include <stdio.h>

struct partition_elem
{
  /* The next element in this class.  Elements in each class form a
     circular list.  */
  struct partition_elem* next;
  /* The canonical element that represents the class containing this
     element.  */
  int class_element;
  /* The number of elements in this class.  Valid only if this is the
     canonical element for its class.  */
  unsigned class_count;
};

typedef struct partition_def 
{
  /* The number of elements in this partition.  */
  int num_elements;
  /* The elements in the partition.  */
  struct partition_elem elements[1];
} *partition;

extern partition partition_new (int);
extern void partition_delete (partition);
extern int partition_union (partition, int, int);
extern void partition_print (partition,	FILE*);

/* Returns the canonical element corresponding to the class containing
   ELEMENT__ in PARTITION__.  */

#define partition_find(partition__, element__) \
    ((partition__)->elements[(element__)].class_element)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PARTITION_H */
