/*
 * computeComplError.c
 *
 * Code generation for function 'computeComplError'
 *
 */

/* Include files */
#include "computeComplError.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo md_emlrtRSI = { 1,  /* lineNo */
  "computeComplError",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeComplError.p"/* pathName */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeComplError",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeComplError.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { 1,  /* iFirst */
  321,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeComplError",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeComplError.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T computeComplError(const emlrtStack *sp, const int32_T
  fscales_lineq_constraint_size[1], const int32_T fscales_cineq_constraint_size
  [1], const real_T xCurrent[321], int32_T mIneq, const real_T cIneq_data[],
  const int32_T cIneq_size[1], const int32_T finiteLB_data[], const int32_T
  finiteLB_size[1], int32_T mLB, const real_T lb[321], const int32_T
  finiteUB_data[], int32_T mUB, const real_T ub[321], const real_T lambda_data[],
  const int32_T lambda_size[1], int32_T iL0)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T lbDelta;
  real_T lbLambda;
  real_T nlpComplError;
  int32_T i;
  int32_T iLineq0;
  int32_T idx;
  int32_T mLinIneq;
  int32_T mNonlinIneq;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nlpComplError = 0.0;
  mLinIneq = fscales_lineq_constraint_size[0];
  mNonlinIneq = fscales_cineq_constraint_size[0];
  if ((mIneq + mLB) + mUB > 0) {
    st.site = &md_emlrtRSI;
    for (idx = 0; idx < mLinIneq; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > fscales_lineq_constraint_size[0])) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, fscales_lineq_constraint_size
          [0], &kb_emlrtBCI, sp);
      }

      if ((idx + 1 < 1) || (idx + 1 > cIneq_size[0])) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cIneq_size[0], &kb_emlrtBCI,
          sp);
      }

      lbDelta = lambda_data[(iL0 + idx) - 1];
      nlpComplError = muDoubleScalarMax(nlpComplError, muDoubleScalarMin
        (muDoubleScalarAbs(cIneq_data[idx] * lbDelta), muDoubleScalarMin
         (muDoubleScalarAbs(cIneq_data[idx]), lbDelta)));
    }

    iLineq0 = (iL0 + fscales_lineq_constraint_size[0]) - 2;
    st.site = &md_emlrtRSI;
    for (idx = 0; idx < mNonlinIneq; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > fscales_cineq_constraint_size[0])) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, fscales_cineq_constraint_size
          [0], &kb_emlrtBCI, sp);
      }

      i = (mLinIneq + idx) + 1;
      if ((i < 1) || (i > cIneq_size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, cIneq_size[0], &kb_emlrtBCI, sp);
      }

      lbDelta = lambda_data[(iLineq0 + idx) + 1];
      if ((i < 1) || (i > cIneq_size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, cIneq_size[0], &kb_emlrtBCI, sp);
      }

      nlpComplError = muDoubleScalarMax(nlpComplError, muDoubleScalarMin
        (muDoubleScalarAbs(cIneq_data[i - 1] * lbDelta), muDoubleScalarMin
         (muDoubleScalarAbs(cIneq_data[i - 1]), lbDelta)));
    }

    mLinIneq = iL0 + mIneq;
    mNonlinIneq = mLinIneq + mLB;
    st.site = &md_emlrtRSI;
    if ((1 <= mLB) && (mLB > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mLB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > finiteLB_size[0])) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB_size[0], &kb_emlrtBCI,
          sp);
      }

      if ((finiteLB_data[idx] < 1) || (finiteLB_data[idx] > 321)) {
        emlrtDynamicBoundsCheckR2012b(finiteLB_data[idx], 1, 321, &lb_emlrtBCI,
          sp);
      }

      lbDelta = xCurrent[finiteLB_data[idx] - 1] - lb[finiteLB_data[idx] - 1];
      i = mLinIneq + idx;
      if ((i < 1) || (i > lambda_size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, lambda_size[0], &kb_emlrtBCI, sp);
      }

      lbLambda = lambda_data[i - 1];
      nlpComplError = muDoubleScalarMax(nlpComplError, muDoubleScalarMin
        (muDoubleScalarAbs(lbDelta * lbLambda), muDoubleScalarMin
         (muDoubleScalarAbs(lbDelta), lbLambda)));
    }

    st.site = &md_emlrtRSI;
    if ((1 <= mUB) && (mUB > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mUB; idx++) {
      lbDelta = ub[finiteUB_data[idx] - 1] - xCurrent[finiteUB_data[idx] - 1];
      i = mNonlinIneq + idx;
      if ((i < 1) || (i > lambda_size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, lambda_size[0], &kb_emlrtBCI, sp);
      }

      lbLambda = lambda_data[i - 1];
      nlpComplError = muDoubleScalarMax(nlpComplError, muDoubleScalarMin
        (muDoubleScalarAbs(lbDelta * lbLambda), muDoubleScalarMin
         (muDoubleScalarAbs(lbDelta), lbLambda)));
    }
  }

  return nlpComplError;
}

/* End of code generation (computeComplError.c) */
