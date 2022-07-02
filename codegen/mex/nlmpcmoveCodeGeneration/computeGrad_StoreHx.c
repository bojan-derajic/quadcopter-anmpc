/*
 * computeGrad_StoreHx.c
 *
 * Code generation for function 'computeGrad_StoreHx'
 *
 */

/* Include files */
#include "computeGrad_StoreHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xgemv.h"

/* Variable Definitions */
static emlrtRSInfo cg_emlrtRSI = { 1,  /* lineNo */
  "computeGrad_StoreHx",               /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeGrad_StoreHx.p"/* pathName */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeGrad_StoreHx",               /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeGrad_StoreHx.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void computeGrad_StoreHx(const emlrtStack *sp, i_struct_T *obj, const real_T H
  [58081], const real_T f_data[], const real_T x_data[], const int32_T x_size[1])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T b_i;
  int32_T i;
  int32_T maxRegVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (obj->objtype) {
   case 5:
    b = obj->nvar;
    st.site = &cg_emlrtRSI;
    if ((1 <= obj->nvar - 1) && (obj->nvar - 1 > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 0; i <= b - 2; i++) {
      b_i = obj->grad.size[0];
      if ((i + 1 < 1) || (i + 1 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &od_emlrtBCI, sp);
      }

      obj->grad.data[i] = 0.0;
    }

    b_i = obj->grad.size[0];
    if ((obj->nvar < 1) || (obj->nvar > b_i)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, b_i, &od_emlrtBCI, sp);
    }

    obj->grad.data[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    st.site = &cg_emlrtRSI;
    h_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x_data, obj->Hx.data);
    b = obj->nvar;
    st.site = &cg_emlrtRSI;
    if ((1 <= obj->nvar) && (obj->nvar > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 0; i < b; i++) {
      b_i = obj->Hx.size[0];
      if ((i + 1 < 1) || (i + 1 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &od_emlrtBCI, sp);
      }

      b_i = obj->grad.size[0];
      if ((i + 1 < 1) || (i + 1 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &od_emlrtBCI, sp);
      }

      obj->grad.data[i] = obj->Hx.data[i];
    }

    if (obj->hasLinear) {
      st.site = &cg_emlrtRSI;
      b_xaxpy(obj->nvar, 1.0, f_data, obj->grad.data);
    }
    break;

   case 4:
    maxRegVar = obj->maxVar - 1;
    st.site = &cg_emlrtRSI;
    h_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x_data, obj->Hx.data);
    b = obj->nvar + 1;
    st.site = &cg_emlrtRSI;
    if ((obj->nvar + 1 <= obj->maxVar - 1) && (obj->maxVar - 1 > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = b; i <= maxRegVar; i++) {
      if ((i < 1) || (i > x_size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, x_size[0], &od_emlrtBCI, sp);
      }

      b_i = obj->Hx.size[0];
      if (i > b_i) {
        emlrtDynamicBoundsCheckR2012b(i, 1, b_i, &od_emlrtBCI, sp);
      }

      obj->Hx.data[i - 1] = obj->beta * x_data[i - 1];
    }

    st.site = &cg_emlrtRSI;
    if ((1 <= obj->maxVar - 1) && (obj->maxVar - 1 > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 0; i < maxRegVar; i++) {
      b_i = obj->Hx.size[0];
      if ((i + 1 < 1) || (i + 1 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &od_emlrtBCI, sp);
      }

      b_i = obj->grad.size[0];
      if ((i + 1 < 1) || (i + 1 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &od_emlrtBCI, sp);
      }

      obj->grad.data[i] = obj->Hx.data[i];
    }

    if (obj->hasLinear) {
      st.site = &cg_emlrtRSI;
      b_xaxpy(obj->nvar, 1.0, f_data, obj->grad.data);
    }

    b = (obj->maxVar - obj->nvar) - 1;
    if (b >= 1) {
      maxRegVar = obj->nvar;
      b_i = b - 1;
      for (b = 0; b <= b_i; b++) {
        obj->grad.data[maxRegVar] += obj->rho;
        maxRegVar++;
      }
    }
    break;
  }
}

/* End of code generation (computeGrad_StoreHx.c) */
