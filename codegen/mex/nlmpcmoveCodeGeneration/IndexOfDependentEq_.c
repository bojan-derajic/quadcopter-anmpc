/*
 * IndexOfDependentEq_.c
 *
 * Code generation for function 'IndexOfDependentEq_'
 *
 */

/* Include files */
#include "IndexOfDependentEq_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQRE.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo we_emlrtRSI = { 1,  /* lineNo */
  "IndexOfDependentEq_",               /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\IndexOfDependentEq_.p"/* pathName */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "IndexOfDependentEq_",               /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\IndexOfDependentEq_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void IndexOfDependentEq_(const emlrtStack *sp, int32_T depIdx_data[], const
  int32_T depIdx_size[1], int32_T mFixed, int32_T nDep, l_struct_T *qrmanager,
  const real_T AeqfPrime_data[], const int32_T AeqfPrime_size[2], int32_T mRows,
  int32_T nCols)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &we_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mFixed; idx++) {
    i = qrmanager->jpvt.size[0];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &wc_emlrtBCI, sp);
    }

    qrmanager->jpvt.data[idx] = 1;
  }

  a = mFixed + 1;
  st.site = &we_emlrtRSI;
  if ((mFixed + 1 <= nCols) && (nCols > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = a; idx <= nCols; idx++) {
    i = qrmanager->jpvt.size[0];
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &wc_emlrtBCI, sp);
    }

    qrmanager->jpvt.data[idx - 1] = 0;
  }

  st.site = &we_emlrtRSI;
  factorQRE(&st, qrmanager, AeqfPrime_data, AeqfPrime_size, mRows, nCols);
  st.site = &we_emlrtRSI;
  if ((1 <= nDep) && (nDep > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < nDep; idx++) {
    i = qrmanager->jpvt.size[0];
    a = ((nCols - nDep) + idx) + 1;
    if ((a < 1) || (a > i)) {
      emlrtDynamicBoundsCheckR2012b(a, 1, i, &wc_emlrtBCI, sp);
    }

    i = depIdx_size[0];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &wc_emlrtBCI, sp);
    }

    depIdx_data[idx] = qrmanager->jpvt.data[a - 1];
  }
}

/* End of code generation (IndexOfDependentEq_.c) */
