/*
 * computePrimalFeasError.c
 *
 * Code generation for function 'computePrimalFeasError'
 *
 */

/* Include files */
#include "computePrimalFeasError.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo kd_emlrtRSI = { 1,  /* lineNo */
  "computePrimalFeasError",            /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computePrimalFeasError.p"/* pathName */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computePrimalFeasError",            /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computePrimalFeasError.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  241,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computePrimalFeasError",            /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computePrimalFeasError.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T computePrimalFeasError(const emlrtStack *sp, const real_T x[241], int32_T
  mLinIneq, int32_T mNonlinIneq, const real_T cIneq_data[], const int32_T
  cIneq_size[1], const real_T cEq[180], const int32_T finiteLB_data[], const
  int32_T finiteLB_size[1], int32_T mLB, const real_T lb[241], const int32_T
  finiteUB_data[], int32_T mUB, const real_T ub[241])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T feasError;
  int32_T idx;
  int32_T mIneq;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  feasError = 0.0;
  mIneq = mNonlinIneq + mLinIneq;
  st.site = &kd_emlrtRSI;
  for (idx = 0; idx < 180; idx++) {
    feasError = muDoubleScalarMax(feasError, muDoubleScalarAbs(cEq[idx]));
  }

  st.site = &kd_emlrtRSI;
  if ((1 <= mIneq) && (mIneq > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mIneq; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > cIneq_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cIneq_size[0], &p_emlrtBCI, sp);
    }

    feasError = muDoubleScalarMax(feasError, cIneq_data[idx]);
  }

  st.site = &kd_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteLB_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB_size[0], &p_emlrtBCI,
        sp);
    }

    mIneq = finiteLB_data[idx] - 1;
    if ((finiteLB_data[idx] < 1) || (finiteLB_data[idx] > 241)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB_data[idx], 1, 241, &q_emlrtBCI, sp);
    }

    feasError = muDoubleScalarMax(feasError, lb[mIneq] - x[mIneq]);
  }

  st.site = &kd_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    feasError = muDoubleScalarMax(feasError, x[finiteUB_data[idx] - 1] -
      ub[finiteUB_data[idx] - 1]);
  }

  return feasError;
}

/* End of code generation (computePrimalFeasError.c) */
