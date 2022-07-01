/*
 * computeQ_.c
 *
 * Code generation for function 'computeQ_'
 *
 */

/* Include files */
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xorgqr.h"

/* Variable Definitions */
static emlrtRSInfo de_emlrtRSI = { 1,  /* lineNo */
  "computeQ_",                         /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+QRManager\\computeQ_.p"/* pathName */
};

/* Function Definitions */
void computeQ_(const emlrtStack *sp, l_struct_T *obj, int32_T nrows)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T iQR0;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b = obj->minRowCol;
  st.site = &de_emlrtRSI;
  if ((1 <= obj->minRowCol) && (obj->minRowCol > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < b; idx++) {
    iQR0 = (obj->ldq * idx + idx) + 2;
    st.site = &de_emlrtRSI;
    d_xcopy((obj->mrows - idx) - 1, obj->QR.data, iQR0, obj->Q.data, iQR0);
  }

  st.site = &de_emlrtRSI;
  xorgqr(&st, obj->mrows, nrows, obj->minRowCol, obj->Q.data, obj->Q.size,
         obj->ldq, obj->tau.data);
}

/* End of code generation (computeQ_.c) */
