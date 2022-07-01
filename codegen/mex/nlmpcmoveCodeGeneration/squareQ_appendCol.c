/*
 * squareQ_appendCol.c
 *
 * Code generation for function 'squareQ_appendCol'
 *
 */

/* Include files */
#include "squareQ_appendCol.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xrot.h"
#include "blas.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo eg_emlrtRSI = { 1,  /* lineNo */
  "squareQ_appendCol",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+QRManager\\squareQ_appendCol.p"/* pathName */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "squareQ_appendCol",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+QRManager\\squareQ_appendCol.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void squareQ_appendCol(const emlrtStack *sp, l_struct_T *obj, const real_T
  vec_data[], int32_T iv0)
{
  emlrtStack st;
  real_T c;
  real_T d;
  real_T d1;
  real_T s;
  int32_T Qk0;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  Qk0 = obj->ncols + 1;
  obj->minRowCol = muIntScalarMin_sint32(obj->mrows, Qk0);
  i_xgemv(obj->mrows, obj->mrows, obj->Q.data, obj->ldq, vec_data, iv0,
          obj->QR.data, obj->ldq * obj->ncols + 1);
  obj->ncols++;
  Qk0 = obj->jpvt.size[0];
  if ((obj->ncols < 1) || (obj->ncols > Qk0)) {
    emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, Qk0, &qd_emlrtBCI, sp);
  }

  obj->jpvt.data[obj->ncols - 1] = obj->ncols;
  for (idx = obj->mrows; idx > obj->ncols; idx--) {
    st.site = &eg_emlrtRSI;
    Qk0 = obj->QR.size[0];
    if ((idx - 1 < 1) || (idx - 1 > Qk0)) {
      emlrtDynamicBoundsCheckR2012b(idx - 1, 1, Qk0, &qd_emlrtBCI, &st);
    }

    Qk0 = obj->QR.size[1];
    if ((obj->ncols < 1) || (obj->ncols > Qk0)) {
      emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, Qk0, &qd_emlrtBCI, &st);
    }

    Qk0 = idx + obj->QR.size[0] * (obj->ncols - 1);
    d = obj->QR.data[Qk0 - 2];
    i = obj->QR.size[0];
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &qd_emlrtBCI, &st);
    }

    i = obj->QR.size[1];
    if ((obj->ncols < 1) || (obj->ncols > i)) {
      emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, i, &qd_emlrtBCI, &st);
    }

    d1 = obj->QR.data[Qk0 - 1];
    c = 0.0;
    s = 0.0;
    drotg(&d, &d1, &c, &s);
    i = obj->QR.size[0];
    if ((idx - 1 < 1) || (idx - 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx - 1, 1, i, &qd_emlrtBCI, sp);
    }

    i = obj->QR.size[1];
    if ((obj->ncols < 1) || (obj->ncols > i)) {
      emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, i, &qd_emlrtBCI, sp);
    }

    obj->QR.data[Qk0 - 2] = d;
    Qk0 = obj->QR.size[0];
    if (idx > Qk0) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, Qk0, &qd_emlrtBCI, sp);
    }

    Qk0 = obj->QR.size[1];
    if ((obj->ncols < 1) || (obj->ncols > Qk0)) {
      emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, Qk0, &qd_emlrtBCI, sp);
    }

    obj->QR.data[(idx + obj->QR.size[0] * (obj->ncols - 1)) - 1] = d1;
    Qk0 = obj->ldq * (idx - 2) + 1;
    xrot(obj->mrows, obj->Q.data, Qk0, obj->ldq + Qk0, c, s);
  }
}

/* End of code generation (squareQ_appendCol.c) */
