/*
 * ComputeNumDependentEq_.c
 *
 * Code generation for function 'ComputeNumDependentEq_'
 *
 */

/* Include files */
#include "ComputeNumDependentEq_.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xdot.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ve_emlrtRSI = { 1,  /* lineNo */
  "ComputeNumDependentEq_",            /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\ComputeNumDependentEq_.p"/* pathName */
};

/* Function Definitions */
int32_T ComputeNumDependentEq_(const emlrtStack *sp, l_struct_T *qrmanager,
  const real_T beqf_data[], int32_T mConstr, int32_T nVar)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T tol;
  int32_T numDependent;
  int32_T y;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y = mConstr - nVar;
  numDependent = muIntScalarMax_sint32(0, y);
  st.site = &ve_emlrtRSI;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= nVar - 1) {
    memset(&qrmanager->jpvt.data[0], 0, nVar * sizeof(int32_T));
  }

  st.site = &ve_emlrtRSI;
  qrmanager->usedPivoting = true;
  qrmanager->mrows = mConstr;
  qrmanager->ncols = nVar;
  qrmanager->minRowCol = muIntScalarMin_sint32(mConstr, nVar);
  b_st.site = &pd_emlrtRSI;
  xgeqp3(&b_st, qrmanager->QR.data, qrmanager->QR.size, mConstr, nVar,
         qrmanager->jpvt.data, qrmanager->jpvt.size, qrmanager->tau.data,
         qrmanager->tau.size);
  tol = 100.0 * (real_T)nVar * 2.2204460492503131E-16;
  y = muIntScalarMin_sint32(nVar, mConstr);
  while ((y > 0) && (muDoubleScalarAbs(qrmanager->QR.data[(y +
            qrmanager->QR.size[0] * (y - 1)) - 1]) < tol)) {
    y--;
    numDependent++;
  }

  if (numDependent > 0) {
    st.site = &ve_emlrtRSI;
    b_st.site = &ce_emlrtRSI;
    computeQ_(&b_st, qrmanager, mConstr);
    st.site = &ve_emlrtRSI;
    if (numDependent > 2147483646) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    y = 0;
    exitg1 = false;
    while ((!exitg1) && (y <= numDependent - 1)) {
      if (muDoubleScalarAbs(xdot(mConstr, qrmanager->Q.data, qrmanager->ldq *
            ((mConstr - y) - 1) + 1, beqf_data)) >= tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        y++;
      }
    }
  }

  return numDependent;
}

/* End of code generation (ComputeNumDependentEq_.c) */
