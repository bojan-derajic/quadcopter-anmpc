/*
 * saveJacobian.c
 *
 * Code generation for function 'saveJacobian'
 *
 */

/* Include files */
#include "saveJacobian.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"

/* Variable Definitions */
static emlrtRSInfo je_emlrtRSI = { 1,  /* lineNo */
  "saveJacobian",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+TrialState\\saveJacobian.p"/* pathName */
};

/* Function Definitions */
void saveJacobian(const emlrtStack *sp, g_struct_T *obj, int32_T nVar, int32_T
                  mIneq, const real_T JacCineqTrans_data[], int32_T ineqCol0,
                  const real_T JacCeqTrans_data[], int32_T ldJ)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T iCol;
  int32_T iCol_old;
  int32_T idx_col;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  iCol = ldJ * (ineqCol0 - 1) + 1;
  iCol_old = 1;
  b = (mIneq - ineqCol0) + 1;
  st.site = &je_emlrtRSI;
  if ((1 <= b) && (b > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx_col = 0; idx_col < b; idx_col++) {
    st.site = &je_emlrtRSI;
    d_xcopy(nVar, JacCineqTrans_data, iCol, obj->JacCineqTrans_old.data,
            iCol_old);
    iCol += ldJ;
    iCol_old += ldJ;
  }

  iCol = 1;
  iCol_old = 1;
  st.site = &je_emlrtRSI;
  for (idx_col = 0; idx_col < 180; idx_col++) {
    st.site = &je_emlrtRSI;
    f_xcopy(nVar, JacCeqTrans_data, iCol, obj->JacCeqTrans_old.data, iCol_old);
    iCol += ldJ;
    iCol_old += ldJ;
  }
}

/* End of code generation (saveJacobian.c) */
