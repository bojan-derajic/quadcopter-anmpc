/*
 * checkVectorNonFinite.c
 *
 * Code generation for function 'checkVectorNonFinite'
 *
 */

/* Include files */
#include "checkVectorNonFinite.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  180,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "checkVectorNonFinite",              /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\+internal\\checkVectorNonFinite.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
int32_T b_checkVectorNonFinite(const emlrtStack *sp, const real_T vec[180])
{
  real_T d;
  int32_T idx_current;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  idx_current = 0;
  while (allFinite && (idx_current + 1 <= 180)) {
    allFinite = ((!muDoubleScalarIsInf(vec[idx_current])) &&
                 (!muDoubleScalarIsNaN(vec[idx_current])));
    idx_current++;
  }

  if (!allFinite) {
    if ((idx_current < 1) || (idx_current > 180)) {
      emlrtDynamicBoundsCheckR2012b(idx_current, 1, 180, &n_emlrtBCI, sp);
    }

    d = vec[idx_current - 1];
    if (muDoubleScalarIsNaN(d)) {
      status = -3;
    } else if (d < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }

  return status;
}

int32_T checkVectorNonFinite(const emlrtStack *sp, int32_T N, const real_T
  vec_data[], const int32_T vec_size[1], int32_T iv0)
{
  real_T d;
  int32_T idx_current;
  int32_T idx_end;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  idx_current = iv0 - 1;
  idx_end = (iv0 + N) - 1;
  while (allFinite && (idx_current + 1 <= idx_end)) {
    if ((idx_current + 1 < 1) || (idx_current + 1 > vec_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx_current + 1, 1, vec_size[0], &m_emlrtBCI,
        sp);
    }

    allFinite = ((!muDoubleScalarIsInf(vec_data[idx_current])) &&
                 (!muDoubleScalarIsNaN(vec_data[idx_current])));
    idx_current++;
  }

  if (!allFinite) {
    if ((idx_current < 1) || (idx_current > vec_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx_current, 1, vec_size[0], &m_emlrtBCI, sp);
    }

    d = vec_data[idx_current - 1];
    if (muDoubleScalarIsNaN(d)) {
      status = -3;
    } else {
      if (idx_current > vec_size[0]) {
        emlrtDynamicBoundsCheckR2012b(idx_current, 1, vec_size[0], &m_emlrtBCI,
          sp);
      }

      if (d < 0.0) {
        status = -1;
      } else {
        status = -2;
      }
    }
  }

  return status;
}

/* End of code generation (checkVectorNonFinite.c) */
