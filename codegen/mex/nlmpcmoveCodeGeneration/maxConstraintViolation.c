/*
 * maxConstraintViolation.c
 *
 * Code generation for function 'maxConstraintViolation'
 *
 */

/* Include files */
#include "maxConstraintViolation.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "maxConstraintViolation_AMats_regularized_",/* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\maxConstraintViolation_AMats_regularized_"
  ".p",                                /* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T b_maxConstraintViolation(const emlrtStack *sp, j_struct_T *obj, const
  real_T x_data[], const int32_T x_size[1])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T idx;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  switch (obj->probType) {
   case 2:
    st.site = &sf_emlrtRSI;
    v = 0.0;
    mIneq = obj->sizes[2];
    if ((obj->Aineq.size[0] != 0) && (obj->Aineq.size[1] != 0)) {
      b_st.site = &tf_emlrtRSI;
      c_xcopy(obj->sizes[2], obj->bineq.data, obj->maxConstrWorkspace.data);
      b_st.site = &tf_emlrtRSI;
      c_xgemv(obj->sizes[2], obj->Aineq.data, obj->ldA, x_data,
              obj->maxConstrWorkspace.data);
      b_st.site = &tf_emlrtRSI;
      if ((1 <= obj->sizes[2]) && (obj->sizes[2] > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < mIneq; idx++) {
        obj->maxConstrWorkspace.data[idx] -= x_data[idx + 241];
        v = muDoubleScalarMax(v, obj->maxConstrWorkspace.data[idx]);
      }
    }

    b_st.site = &tf_emlrtRSI;
    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 180U * sizeof(real_T));
    b_st.site = &tf_emlrtRSI;
    d_xgemv(241, obj->Aeq.data, obj->ldA, x_data, obj->maxConstrWorkspace.data);
    b_st.site = &tf_emlrtRSI;
    i = x_size[0];
    for (idx = 0; idx < 180; idx++) {
      i1 = (mIneq + idx) + 242;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &dd_emlrtBCI, &st);
      }

      i2 = (obj->sizes[2] + idx) + 422;
      if ((i2 < 1) || (i2 > i)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i, &dd_emlrtBCI, &st);
      }

      obj->maxConstrWorkspace.data[idx] = (obj->maxConstrWorkspace.data[idx] -
        x_data[i1 - 1]) + x_data[i2 - 1];
      v = muDoubleScalarMax(v, muDoubleScalarAbs(obj->
        maxConstrWorkspace.data[idx]));
    }
    break;

   default:
    st.site = &sf_emlrtRSI;
    v = 0.0;
    mIneq = obj->sizes[2];
    if ((obj->Aineq.size[0] != 0) && (obj->Aineq.size[1] != 0)) {
      b_st.site = &uf_emlrtRSI;
      c_xcopy(obj->sizes[2], obj->bineq.data, obj->maxConstrWorkspace.data);
      b_st.site = &uf_emlrtRSI;
      e_xgemv(obj->nVar, obj->sizes[2], obj->Aineq.data, obj->ldA, x_data,
              obj->maxConstrWorkspace.data);
      b_st.site = &uf_emlrtRSI;
      if ((1 <= obj->sizes[2]) && (obj->sizes[2] > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < mIneq; idx++) {
        v = muDoubleScalarMax(v, obj->maxConstrWorkspace.data[idx]);
      }
    }

    b_st.site = &uf_emlrtRSI;
    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 180U * sizeof(real_T));
    b_st.site = &uf_emlrtRSI;
    d_xgemv(obj->nVar, obj->Aeq.data, obj->ldA, x_data,
            obj->maxConstrWorkspace.data);
    b_st.site = &uf_emlrtRSI;
    for (idx = 0; idx < 180; idx++) {
      v = muDoubleScalarMax(v, muDoubleScalarAbs(obj->
        maxConstrWorkspace.data[idx]));
    }
    break;
  }

  if (obj->sizes[3] > 0) {
    st.site = &sf_emlrtRSI;
    if ((1 <= obj->sizes[3]) && (obj->sizes[3] > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mLB; idx++) {
      i = obj->indexLB.size[0];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ad_emlrtBCI, sp);
      }

      mIneq = obj->indexLB.data[idx] - 1;
      if ((obj->indexLB.data[idx] < 1) || (obj->indexLB.data[idx] > x_size[0]))
      {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB.data[idx], 1, x_size[0],
          &ad_emlrtBCI, sp);
      }

      i = obj->lb.size[0];
      if ((obj->indexLB.data[idx] < 1) || (obj->indexLB.data[idx] > i)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB.data[idx], 1, i, &ad_emlrtBCI,
          sp);
      }

      v = muDoubleScalarMax(v, -x_data[mIneq] - obj->lb.data[mIneq]);
    }
  }

  if (obj->sizes[4] > 0) {
    st.site = &sf_emlrtRSI;
    if ((1 <= obj->sizes[4]) && (obj->sizes[4] > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mUB; idx++) {
      mIneq = obj->indexUB.data[idx] - 1;
      v = muDoubleScalarMax(v, x_data[mIneq] - obj->ub.data[mIneq]);
    }
  }

  if (obj->sizes[0] > 0) {
    st.site = &sf_emlrtRSI;
    if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mFixed; idx++) {
      v = muDoubleScalarMax(v, muDoubleScalarAbs(x_data[obj->indexFixed.data[idx]
        - 1] - obj->ub.data[obj->indexFixed.data[idx] - 1]));
    }
  }

  return v;
}

real_T maxConstraintViolation(const emlrtStack *sp, j_struct_T *obj, const
  real_T x_data[], const int32_T x_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v;
  int32_T idx;
  int32_T idxLB;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  switch (obj->probType) {
   case 2:
    st.site = &sf_emlrtRSI;
    v = 0.0;
    mIneq = obj->sizes[2];
    if ((obj->Aineq.size[0] != 0) && (obj->Aineq.size[1] != 0)) {
      b_st.site = &tf_emlrtRSI;
      c_xcopy(obj->sizes[2], obj->bineq.data, obj->maxConstrWorkspace.data);
      b_st.site = &tf_emlrtRSI;
      c_xgemv(obj->sizes[2], obj->Aineq.data, obj->ldA, x_data,
              obj->maxConstrWorkspace.data);
      b_st.site = &tf_emlrtRSI;
      if ((1 <= obj->sizes[2]) && (obj->sizes[2] > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < mIneq; idx++) {
        obj->maxConstrWorkspace.data[idx] -= x_data[idx + 241];
        v = muDoubleScalarMax(v, obj->maxConstrWorkspace.data[idx]);
      }
    }

    b_st.site = &tf_emlrtRSI;
    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 180U * sizeof(real_T));
    b_st.site = &tf_emlrtRSI;
    d_xgemv(241, obj->Aeq.data, obj->ldA, x_data, obj->maxConstrWorkspace.data);
    b_st.site = &tf_emlrtRSI;
    for (idx = 0; idx < 180; idx++) {
      obj->maxConstrWorkspace.data[idx] = (obj->maxConstrWorkspace.data[idx] -
        x_data[(mIneq + idx) + 241]) + x_data[(obj->sizes[2] + idx) + 421];
      v = muDoubleScalarMax(v, muDoubleScalarAbs(obj->
        maxConstrWorkspace.data[idx]));
    }
    break;

   default:
    st.site = &sf_emlrtRSI;
    v = 0.0;
    mIneq = obj->sizes[2];
    if ((obj->Aineq.size[0] != 0) && (obj->Aineq.size[1] != 0)) {
      b_st.site = &uf_emlrtRSI;
      c_xcopy(obj->sizes[2], obj->bineq.data, obj->maxConstrWorkspace.data);
      b_st.site = &uf_emlrtRSI;
      e_xgemv(obj->nVar, obj->sizes[2], obj->Aineq.data, obj->ldA, x_data,
              obj->maxConstrWorkspace.data);
      b_st.site = &uf_emlrtRSI;
      if ((1 <= obj->sizes[2]) && (obj->sizes[2] > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < mIneq; idx++) {
        v = muDoubleScalarMax(v, obj->maxConstrWorkspace.data[idx]);
      }
    }

    b_st.site = &uf_emlrtRSI;
    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 180U * sizeof(real_T));
    b_st.site = &uf_emlrtRSI;
    d_xgemv(obj->nVar, obj->Aeq.data, obj->ldA, x_data,
            obj->maxConstrWorkspace.data);
    b_st.site = &uf_emlrtRSI;
    for (idx = 0; idx < 180; idx++) {
      v = muDoubleScalarMax(v, muDoubleScalarAbs(obj->
        maxConstrWorkspace.data[idx]));
    }
    break;
  }

  if (obj->sizes[3] > 0) {
    st.site = &sf_emlrtRSI;
    if ((1 <= obj->sizes[3]) && (obj->sizes[3] > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mLB; idx++) {
      mIneq = obj->indexLB.size[0];
      if ((idx + 1 < 1) || (idx + 1 > mIneq)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, mIneq, &ad_emlrtBCI, sp);
      }

      idxLB = obj->indexLB.data[idx] - 1;
      mIneq = x_size[0] * x_size[1];
      if ((obj->indexLB.data[idx] < 1) || (obj->indexLB.data[idx] > mIneq)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB.data[idx], 1, mIneq,
          &ad_emlrtBCI, sp);
      }

      mIneq = obj->lb.size[0];
      if ((obj->indexLB.data[idx] < 1) || (obj->indexLB.data[idx] > mIneq)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB.data[idx], 1, mIneq,
          &ad_emlrtBCI, sp);
      }

      v = muDoubleScalarMax(v, -x_data[idxLB] - obj->lb.data[idxLB]);
    }
  }

  if (obj->sizes[4] > 0) {
    st.site = &sf_emlrtRSI;
    if ((1 <= obj->sizes[4]) && (obj->sizes[4] > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mUB; idx++) {
      mIneq = obj->indexUB.data[idx] - 1;
      v = muDoubleScalarMax(v, x_data[mIneq] - obj->ub.data[mIneq]);
    }
  }

  if (obj->sizes[0] > 0) {
    st.site = &sf_emlrtRSI;
    if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mFixed; idx++) {
      v = muDoubleScalarMax(v, muDoubleScalarAbs(x_data[obj->indexFixed.data[idx]
        - 1] - obj->ub.data[obj->indexFixed.data[idx] - 1]));
    }
  }

  return v;
}

/* End of code generation (maxConstraintViolation.c) */
