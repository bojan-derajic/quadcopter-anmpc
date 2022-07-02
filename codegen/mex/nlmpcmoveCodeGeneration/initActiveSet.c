/*
 * initActiveSet.c
 *
 * Code generation for function 'initActiveSet'
 *
 */

/* Include files */
#include "initActiveSet.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = { 1,  /* lineNo */
  "initActiveSet",                     /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\initActiveSet.p"/* pathName */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "initActiveSet",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\initActiveSet.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void initActiveSet(const emlrtStack *sp, j_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T iATw0;
  int32_T iAeq0;
  int32_T idxFillStart;
  int32_T idx_local;
  int32_T nWFixed;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  setProblemType(&st, obj, 3);
  idxFillStart = obj->isActiveIdx[2];
  iATw0 = obj->mConstrMax;
  st.site = &bd_emlrtRSI;
  if ((obj->isActiveIdx[2] <= obj->mConstrMax) && (obj->mConstrMax > 2147483646))
  {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (iAeq0 = idxFillStart; iAeq0 <= iATw0; iAeq0++) {
    i = obj->isActiveConstr.size[0];
    if ((iAeq0 < 1) || (iAeq0 > i)) {
      emlrtDynamicBoundsCheckR2012b(iAeq0, 1, i, &sb_emlrtBCI, sp);
    }

    obj->isActiveConstr.data[iAeq0 - 1] = false;
  }

  obj->nWConstr[0] = obj->sizes[0];
  obj->nWConstr[1] = 180;
  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0] + 180;
  nWFixed = obj->sizes[0];
  st.site = &bd_emlrtRSI;
  if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx_local = 0; idx_local < nWFixed; idx_local++) {
    obj->Wid.data[idx_local] = 1;
    obj->Wlocalidx.data[idx_local] = idx_local + 1;
    obj->isActiveConstr.data[idx_local] = true;
    iATw0 = obj->indexFixed.data[idx_local];
    st.site = &bd_emlrtRSI;
    if (1 > obj->indexFixed.data[idx_local] - 1) {
      overflow = false;
    } else {
      overflow = (obj->indexFixed.data[idx_local] - 1 > 2147483646);
    }

    if (overflow) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (b_i = 0; b_i <= iATw0 - 2; b_i++) {
      obj->ATwset.data[b_i + obj->ATwset.size[0] * idx_local] = 0.0;
    }

    obj->ATwset.data[(obj->indexFixed.data[idx_local] + obj->ATwset.size[0] *
                      idx_local) - 1] = 1.0;
    idxFillStart = obj->indexFixed.data[idx_local] + 1;
    iATw0 = obj->nVar;
    st.site = &bd_emlrtRSI;
    if (obj->indexFixed.data[idx_local] + 1 > obj->nVar) {
      overflow = false;
    } else {
      overflow = (obj->nVar > 2147483646);
    }

    if (overflow) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (b_i = idxFillStart; b_i <= iATw0; b_i++) {
      i = obj->ATwset.size[0];
      if ((b_i < 1) || (b_i > i)) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, i, &sb_emlrtBCI, sp);
      }

      obj->ATwset.data[(b_i + obj->ATwset.size[0] * idx_local) - 1] = 0.0;
    }

    obj->bwset.data[idx_local] = obj->ub.data[obj->indexFixed.data[idx_local] -
      1];
  }

  st.site = &bd_emlrtRSI;
  for (idx_local = 0; idx_local < 180; idx_local++) {
    idxFillStart = nWFixed + idx_local;
    obj->Wid.data[idxFillStart] = 2;
    obj->Wlocalidx.data[idxFillStart] = idx_local + 1;
    obj->isActiveConstr.data[idxFillStart] = true;
    iAeq0 = obj->ldA * idx_local + 1;
    iATw0 = obj->ldA * idxFillStart;
    i = obj->nVar - 1;
    for (b_i = 0; b_i <= i; b_i++) {
      i1 = obj->Aeq.size[0] * 180;
      i2 = iAeq0 + b_i;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &sb_emlrtBCI, sp);
      }

      obj->ATwset.data[iATw0 + b_i] = obj->Aeq.data[i2 - 1];
    }

    obj->bwset.data[idxFillStart] = obj->beq[idx_local];
  }
}

/* End of code generation (initActiveSet.c) */
