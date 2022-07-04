/*
 * computeGradLag.c
 *
 * Code generation for function 'computeGradLag'
 *
 */

/* Include files */
#include "computeGradLag.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo jd_emlrtRSI = { 1,  /* lineNo */
  "computeGradLag",                    /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeGradLag.p"/* pathName */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeGradLag",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeGradLag.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void b_computeGradLag(const emlrtStack *sp, real_T workspace_data[], const
                      int32_T workspace_size[2], int32_T ldA, int32_T nVar,
                      const real_T grad_data[], const int32_T grad_size[1],
                      int32_T mIneq, const real_T AineqTrans_data[], const
                      real_T AeqTrans_data[], const int32_T finiteFixed_data[],
                      int32_T mFixed, const int32_T finiteLB_data[], const
                      int32_T finiteLB_size[1], int32_T mLB, const int32_T
                      finiteUB_data[], int32_T mUB, const real_T lambda_data[],
                      const int32_T lambda_size[1])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  int32_T i;
  int32_T iL0;
  int32_T idx;
  char_T TRANSA;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (iL0 = 0; iL0 < nVar; iL0++) {
    if ((iL0 + 1 < 1) || (iL0 + 1 > grad_size[0])) {
      emlrtDynamicBoundsCheckR2012b(iL0 + 1, 1, grad_size[0], &ac_emlrtBCI, sp);
    }

    workspace_data[iL0] = grad_data[iL0];
  }

  st.site = &jd_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mFixed; idx++) {
    workspace_data[finiteFixed_data[idx] - 1] += lambda_data[idx];
  }

  st.site = &jd_emlrtRSI;
  alpha1 = 1.0;
  beta1 = 1.0;
  TRANSA = 'N';
  m_t = (ptrdiff_t)nVar;
  n_t = (ptrdiff_t)180;
  lda_t = (ptrdiff_t)ldA;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &AeqTrans_data[0], &lda_t,
        &lambda_data[mFixed], &incx_t, &beta1, &workspace_data[0], &incy_t);
  st.site = &jd_emlrtRSI;
  if (mIneq >= 1) {
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mIneq;
    lda_t = (ptrdiff_t)ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &AineqTrans_data[0], &lda_t,
          &lambda_data[mFixed + 180], &incx_t, &beta1, &workspace_data[0],
          &incy_t);
  }

  iL0 = (mFixed + mIneq) + 181;
  st.site = &jd_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteLB_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB_size[0], &ac_emlrtBCI,
        sp);
    }

    i = workspace_size[0] * workspace_size[1];
    if ((finiteLB_data[idx] < 1) || (finiteLB_data[idx] > i)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB_data[idx], 1, i, &ac_emlrtBCI, sp);
    }

    if ((iL0 < 1) || (iL0 > lambda_size[0])) {
      emlrtDynamicBoundsCheckR2012b(iL0, 1, lambda_size[0], &ac_emlrtBCI, sp);
    }

    if ((finiteLB_data[idx] < 1) || (finiteLB_data[idx] > i)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB_data[idx], 1, i, &ac_emlrtBCI, sp);
    }

    workspace_data[finiteLB_data[idx] - 1] -= lambda_data[iL0 - 1];
    iL0++;
  }

  st.site = &jd_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    if ((iL0 < 1) || (iL0 > lambda_size[0])) {
      emlrtDynamicBoundsCheckR2012b(iL0, 1, lambda_size[0], &ac_emlrtBCI, sp);
    }

    workspace_data[finiteUB_data[idx] - 1] += lambda_data[iL0 - 1];
    iL0++;
  }
}

void computeGradLag(const emlrtStack *sp, real_T workspace_data[], const int32_T
                    workspace_size[1], int32_T ldA, int32_T nVar, const real_T
                    grad_data[], const int32_T grad_size[1], int32_T mIneq,
                    const real_T AineqTrans_data[], const real_T AeqTrans_data[],
                    const int32_T finiteFixed_data[], int32_T mFixed, const
                    int32_T finiteLB_data[], const int32_T finiteLB_size[1],
                    int32_T mLB, const int32_T finiteUB_data[], int32_T mUB,
                    const real_T lambda_data[], const int32_T lambda_size[1])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  int32_T i;
  int32_T iL0;
  int32_T idx;
  char_T TRANSA;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (iL0 = 0; iL0 < nVar; iL0++) {
    if ((iL0 + 1 < 1) || (iL0 + 1 > grad_size[0])) {
      emlrtDynamicBoundsCheckR2012b(iL0 + 1, 1, grad_size[0], &ac_emlrtBCI, sp);
    }

    i = workspace_size[0];
    if ((iL0 + 1 < 1) || (iL0 + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(iL0 + 1, 1, i, &ac_emlrtBCI, sp);
    }

    workspace_data[iL0] = grad_data[iL0];
  }

  st.site = &jd_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mFixed; idx++) {
    workspace_data[finiteFixed_data[idx] - 1] += lambda_data[idx];
  }

  st.site = &jd_emlrtRSI;
  alpha1 = 1.0;
  beta1 = 1.0;
  TRANSA = 'N';
  m_t = (ptrdiff_t)nVar;
  n_t = (ptrdiff_t)180;
  lda_t = (ptrdiff_t)ldA;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &AeqTrans_data[0], &lda_t,
        &lambda_data[mFixed], &incx_t, &beta1, &workspace_data[0], &incy_t);
  st.site = &jd_emlrtRSI;
  if (mIneq >= 1) {
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mIneq;
    lda_t = (ptrdiff_t)ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &AineqTrans_data[0], &lda_t,
          &lambda_data[mFixed + 180], &incx_t, &beta1, &workspace_data[0],
          &incy_t);
  }

  iL0 = (mFixed + mIneq) + 181;
  st.site = &jd_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteLB_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB_size[0], &ac_emlrtBCI,
        sp);
    }

    i = workspace_size[0];
    if ((finiteLB_data[idx] < 1) || (finiteLB_data[idx] > i)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB_data[idx], 1, i, &ac_emlrtBCI, sp);
    }

    if ((iL0 < 1) || (iL0 > lambda_size[0])) {
      emlrtDynamicBoundsCheckR2012b(iL0, 1, lambda_size[0], &ac_emlrtBCI, sp);
    }

    i = workspace_size[0];
    if ((finiteLB_data[idx] < 1) || (finiteLB_data[idx] > i)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB_data[idx], 1, i, &ac_emlrtBCI, sp);
    }

    workspace_data[finiteLB_data[idx] - 1] -= lambda_data[iL0 - 1];
    iL0++;
  }

  st.site = &jd_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    if ((iL0 < 1) || (iL0 > lambda_size[0])) {
      emlrtDynamicBoundsCheckR2012b(iL0, 1, lambda_size[0], &ac_emlrtBCI, sp);
    }

    workspace_data[finiteUB_data[idx] - 1] += lambda_data[iL0 - 1];
    iL0++;
  }
}

/* End of code generation (computeGradLag.c) */
