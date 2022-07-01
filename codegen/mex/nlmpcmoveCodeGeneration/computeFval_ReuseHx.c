/*
 * computeFval_ReuseHx.c
 *
 * Code generation for function 'computeFval_ReuseHx'
 *
 */

/* Include files */
#include "computeFval_ReuseHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo dg_emlrtRSI = { 1,  /* lineNo */
  "computeFval_ReuseHx",               /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval_ReuseHx.p"/* pathName */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeFval_ReuseHx",               /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval_ReuseHx.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T computeFval_ReuseHx(const emlrtStack *sp, const i_struct_T *obj, real_T
  workspace_data[], const real_T f_data[], const int32_T f_size[1], const real_T
  x_data[], const int32_T x_size[1])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T val;
  int32_T b;
  int32_T i;
  int32_T idx;
  int32_T maxRegVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    if ((obj->nvar < 1) || (obj->nvar > x_size[0])) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, x_size[0], &pd_emlrtBCI, sp);
    }

    val = obj->gammaScalar * x_data[obj->nvar - 1];
    break;

   case 3:
    if (obj->hasLinear) {
      b = obj->nvar;
      st.site = &dg_emlrtRSI;
      if ((1 <= obj->nvar) && (obj->nvar > 2147483646)) {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i = 0; i < b; i++) {
        idx = obj->Hx.size[0];
        if ((i + 1 < 1) || (i + 1 > idx)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, idx, &pd_emlrtBCI, sp);
        }

        if ((i + 1 < 1) || (i + 1 > f_size[0])) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, f_size[0], &pd_emlrtBCI, sp);
        }

        workspace_data[i] = 0.5 * obj->Hx.data[i] + f_data[i];
      }

      if (obj->nvar >= 1) {
        n_t = (ptrdiff_t)obj->nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, &x_data[0], &incx_t, &workspace_data[0], &incy_t);
      }
    } else {
      if (obj->nvar >= 1) {
        n_t = (ptrdiff_t)obj->nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, &x_data[0], &incx_t, &obj->Hx.data[0], &incy_t);
      }

      val *= 0.5;
    }
    break;

   case 4:
    maxRegVar = obj->maxVar - 1;
    if (obj->hasLinear) {
      b = obj->nvar;
      st.site = &dg_emlrtRSI;
      if ((1 <= obj->nvar) && (obj->nvar > 2147483646)) {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i = 0; i < b; i++) {
        if ((i + 1 < 1) || (i + 1 > f_size[0])) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, f_size[0], &pd_emlrtBCI, sp);
        }

        workspace_data[i] = f_data[i];
      }

      b = (obj->maxVar - obj->nvar) - 1;
      st.site = &dg_emlrtRSI;
      if ((1 <= b) && (b > 2147483646)) {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i = 0; i < b; i++) {
        workspace_data[obj->nvar + i] = obj->rho;
      }

      st.site = &dg_emlrtRSI;
      if ((1 <= obj->maxVar - 1) && (obj->maxVar - 1 > 2147483646)) {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i = 0; i < maxRegVar; i++) {
        idx = obj->Hx.size[0];
        if ((i + 1 < 1) || (i + 1 > idx)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, idx, &pd_emlrtBCI, sp);
        }

        workspace_data[i] += 0.5 * obj->Hx.data[i];
      }

      if (obj->maxVar - 1 >= 1) {
        n_t = (ptrdiff_t)(obj->maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, &x_data[0], &incx_t, &workspace_data[0], &incy_t);
      }
    } else {
      if (obj->maxVar - 1 >= 1) {
        n_t = (ptrdiff_t)(obj->maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, &x_data[0], &incx_t, &obj->Hx.data[0], &incy_t);
      }

      val *= 0.5;
      b = obj->nvar + 1;
      st.site = &dg_emlrtRSI;
      if ((obj->nvar + 1 <= obj->maxVar - 1) && (obj->maxVar - 1 > 2147483646))
      {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (idx = b; idx <= maxRegVar; idx++) {
        if ((idx < 1) || (idx > x_size[0])) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, x_size[0], &pd_emlrtBCI, sp);
        }

        val += x_data[idx - 1] * obj->rho;
      }
    }
    break;
  }

  return val;
}

/* End of code generation (computeFval_ReuseHx.c) */
