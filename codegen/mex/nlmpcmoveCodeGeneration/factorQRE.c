/*
 * factorQRE.c
 *
 * Code generation for function 'factorQRE'
 *
 */

/* Include files */
#include "factorQRE.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"

/* Function Definitions */
void factorQRE(const emlrtStack *sp, l_struct_T *obj, const real_T A_data[],
               const int32_T A_size[2], int32_T mrows, int32_T ncols)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T guard1 = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  guard1 = false;
  if ((A_size[0] != 0) && (A_size[1] != 0) && (mrows * ncols > 0)) {
    st.site = &pd_emlrtRSI;
    if ((1 <= ncols) && (ncols > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < ncols; idx++) {
      st.site = &pd_emlrtRSI;
      d_xcopy(mrows, A_data, A_size[0] * idx + 1, obj->QR.data, obj->ldq * idx +
              1);
    }

    guard1 = true;
  } else if (mrows * ncols == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = muIntScalarMin_sint32(mrows, ncols);
    st.site = &pd_emlrtRSI;
    xgeqp3(&st, obj->QR.data, obj->QR.size, mrows, ncols, obj->jpvt.data,
           obj->jpvt.size, obj->tau.data, obj->tau.size);
  }
}

/* End of code generation (factorQRE.c) */
