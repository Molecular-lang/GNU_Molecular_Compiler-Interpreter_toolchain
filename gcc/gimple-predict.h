/* Gimple prediction routines.

  Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLE_PREDICT_H
#define GCC_GIMPLE_PREDICT_H

#include "predict.h"

/* Return the predictor of GIMPLE_PREDICT statement GS.  */

static inline enum br_predictor
gimple_predict_predictor (const gimple *gs)
{
  GIMPLE_CHECK (gs, GIMPLE_PREDICT);
  return (enum br_predictor) (gs->subcode & ~GF_PREDICT_TAKEN);
}


/* Set the predictor of GIMPLE_PREDICT statement GS to PREDICT.  */

static inline void
gimple_predict_set_predictor (gimple *gs, enum br_predictor predictor)
{
  GIMPLE_CHECK (gs, GIMPLE_PREDICT);
  gs->subcode = (gs->subcode & GF_PREDICT_TAKEN)
		       | (unsigned) predictor;
}


/* Return the outcome of GIMPLE_PREDICT statement GS.  */

static inline enum prediction
gimple_predict_outcome (const gimple *gs)
{
  GIMPLE_CHECK (gs, GIMPLE_PREDICT);
  return (gs->subcode & GF_PREDICT_TAKEN) ? TAKEN : NOT_TAKEN;
}


/* Set the outcome of GIMPLE_PREDICT statement GS to OUTCOME.  */

static inline void
gimple_predict_set_outcome (gimple *gs, enum prediction outcome)
{
  GIMPLE_CHECK (gs, GIMPLE_PREDICT);
  if (outcome == TAKEN)
    gs->subcode |= GF_PREDICT_TAKEN;
  else
    gs->subcode &= ~GF_PREDICT_TAKEN;
}

/* Build a GIMPLE_PREDICT statement.  PREDICT is one of the predictors from
   predict.def, OUTCOME is NOT_TAKEN or TAKEN.  */

inline gimple *
gimple_build_predict (enum br_predictor predictor, enum prediction outcome)
{
  gimple *p = gimple_alloc (GIMPLE_PREDICT, 0);
  /* Ensure all the predictors fit into the lower bits of the subcode.  */
  gcc_assert ((int) END_PREDICTORS <= GF_PREDICT_TAKEN);
  gimple_predict_set_predictor (p, predictor);
  gimple_predict_set_outcome (p, outcome);
  return p;
}

/* Return true if GS is a GIMPLE_PREDICT statement.  */

static inline bool
is_gimple_predict (const gimple *gs)
{
  return gimple_code (gs) == GIMPLE_PREDICT;
}

#endif  /* GCC_GIMPLE_PREDICT_H */
