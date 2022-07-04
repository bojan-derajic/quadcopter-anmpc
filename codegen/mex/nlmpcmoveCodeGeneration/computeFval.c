/*
 * computeFval.c
 *
 * Code generation for function 'computeFval'
 *
 */

/* Include files */
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "linearForm_.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo xf_emlrtRSI = { 1,  /* lineNo */
  "computeFval",                       /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval.p"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 1,  /* lineNo */
  "linearFormReg_",                    /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\linearFormReg_.p"/* pathName */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeFval",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "linearFormReg_",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\linearFormReg_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T computeFval(const emlrtStack *sp, const i_struct_T *obj, real_T
                   workspace_data[], const real_T H[58081], const real_T f_data[],
                   const int32_T f_size[1], const real_T x_data[], const int32_T
                   x_size[1])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T val;
  int32_T a;
  int32_T b;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    if ((obj->nvar < 1) || (obj->nvar > x_size[0])) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, x_size[0], &hd_emlrtBCI, sp);
    }

    val = obj->gammaScalar * x_data[obj->nvar - 1];
    break;

   case 3:
    st.site = &xf_emlrtRSI;
    linearForm_(&st, obj->hasLinear, obj->nvar, workspace_data, H, f_data,
                f_size, x_data);
    if (obj->nvar >= 1) {
      n_t = (ptrdiff_t)obj->nvar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      val = ddot(&n_t, &x_data[0], &incx_t, &workspace_data[0], &incy_t);
    }
    break;

   case 4:
    st.site = &xf_emlrtRSI;
    linearForm_(&st, obj->hasLinear, obj->nvar, workspace_data, H, f_data,
                f_size, x_data);
    st.site = &xf_emlrtRSI;
    a = obj->nvar + 1;
    b = obj->maxVar - 1;
    b_st.site = &ag_emlrtRSI;
    if ((obj->nvar + 1 <= obj->maxVar - 1) && (obj->maxVar - 1 > 2147483646)) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = a; idx <= b; idx++) {
      if ((idx < 1) || (idx > x_size[0])) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, x_size[0], &id_emlrtBCI, &st);
      }

      workspace_data[idx - 1] = 0.5 * obj->beta * x_data[idx - 1] + obj->rho;
    }

    if (obj->maxVar - 1 >= 1) {
      n_t = (ptrdiff_t)(obj->maxVar - 1);
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      val = ddot(&n_t, &x_data[0], &incx_t, &workspace_data[0], &incy_t);
    }
    break;
  }

  return val;
}

/* End of code generation (computeFval.c) */
