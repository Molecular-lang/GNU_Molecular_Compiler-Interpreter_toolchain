/* Basic struct timeval utilities. */

#ifndef TIMEVAL_UTILS_H
#define TIMEVAL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* forward decl */
struct timeval;

extern void timeval_add (struct timeval *result,
			 const struct timeval *a, const struct timeval *b);

extern void timeval_sub (struct timeval *result,
			 const struct timeval *a, const struct timeval *b);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TIMEVAL_UTILS_H */
