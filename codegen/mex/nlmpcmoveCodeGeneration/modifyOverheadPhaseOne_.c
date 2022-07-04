/*
 * modifyOverheadPhaseOne_.c
 *
 * Code generation for function 'modifyOverheadPhaseOne_'
 *
 */

/* Include files */
#include "modifyOverheadPhaseOne_.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo dd_emlrtRSI = { 1,  /* lineNo */
  "modifyOverheadPhaseOne_",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadPhaseOne_.p"/* pathName */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "modifyOverheadPhaseOne_",           /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadPhaseOne_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void modifyOverheadPhaseOne_(const emlrtStack *sp, j_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T idx;
  int32_T idxStartIneq;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b = obj->sizes[0];
  st.site = &dd_emlrtRSI;
  if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < b; idx++) {
    i = obj->ATwset.size[0];
    if ((obj->nVar < 1) || (obj->nVar > i)) {
      emlrtDynamicBoundsCheckR2012b(obj->nVar, 1, i, &ub_emlrtBCI, sp);
    }

    i = obj->ATwset.size[1];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ub_emlrtBCI, sp);
    }

    obj->ATwset.data[(obj->nVar + obj->ATwset.size[0] * idx) - 1] = 0.0;
  }

  st.site = &dd_emlrtRSI;
  for (idx = 0; idx < 240; idx++) {
    i = obj->Aeq.size[0];
    if ((obj->nVar < 1) || (obj->nVar > i)) {
      emlrtDynamicBoundsCheckR2012b(obj->nVar, 1, i, &ub_emlrtBCI, sp);
    }

    obj->Aeq.data[(obj->nVar + obj->Aeq.size[0] * idx) - 1] = 0.0;
    i = obj->ATwset.size[0];
    if ((obj->nVar < 1) || (obj->nVar > i)) {
      emlrtDynamicBoundsCheckR2012b(obj->nVar, 1, i, &ub_emlrtBCI, sp);
    }

    i = obj->ATwset.size[1];
    b = obj->isActiveIdx[1] + idx;
    if ((b < 1) || (b > i)) {
      emlrtDynamicBoundsCheckR2012b(b, 1, i, &ub_emlrtBCI, sp);
    }

    obj->ATwset.data[(obj->nVar + obj->ATwset.size[0] * (b - 1)) - 1] = 0.0;
  }

  b = obj->sizes[2];
  st.site = &dd_emlrtRSI;
  if ((1 <= obj->sizes[2]) && (obj->sizes[2] > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < b; idx++) {
    i = obj->Aineq.size[0];
    if ((obj->nVar < 1) || (obj->nVar > i)) {
      emlrtDynamicBoundsCheckR2012b(obj->nVar, 1, i, &ub_emlrtBCI, sp);
    }

    i = obj->Aineq.size[1];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ub_emlrtBCI, sp);
    }

    obj->Aineq.data[(obj->nVar + obj->Aineq.size[0] * idx) - 1] = -1.0;
  }

  i = obj->indexLB.size[0];
  if ((obj->sizes[3] < 1) || (obj->sizes[3] > i)) {
    emlrtDynamicBoundsCheckR2012b(obj->sizes[3], 1, i, &ub_emlrtBCI, sp);
  }

  obj->indexLB.data[obj->sizes[3] - 1] = obj->nVar;
  i = obj->lb.size[0];
  if ((obj->nVar < 1) || (obj->nVar > i)) {
    emlrtDynamicBoundsCheckR2012b(obj->nVar, 1, i, &ub_emlrtBCI, sp);
  }

  obj->lb.data[obj->nVar - 1] = 1.0E-5;
  idxStartIneq = obj->isActiveIdx[2];
  b = obj->nActiveConstr;
  st.site = &dd_emlrtRSI;
  if ((obj->isActiveIdx[2] <= obj->nActiveConstr) && (obj->nActiveConstr >
       2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = idxStartIneq; idx <= b; idx++) {
    i = obj->ATwset.size[0];
    if ((obj->nVar < 1) || (obj->nVar > i)) {
      emlrtDynamicBoundsCheckR2012b(obj->nVar, 1, i, &ub_emlrtBCI, sp);
    }

    i = obj->ATwset.size[1];
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ub_emlrtBCI, sp);
    }

    obj->ATwset.data[(obj->nVar + obj->ATwset.size[0] * (idx - 1)) - 1] = -1.0;
  }
}

/* End of code generation (modifyOverheadPhaseOne_.c) */
