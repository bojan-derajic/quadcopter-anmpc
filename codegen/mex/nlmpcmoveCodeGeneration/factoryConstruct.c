/*
 * factoryConstruct.c
 *
 * Code generation for function 'factoryConstruct'
 *
 */

/* Include files */
#include "factoryConstruct.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ic_emlrtRSI = { 1,  /* lineNo */
  "factoryConstruct",                  /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\factoryConstruct.p"/* pathName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "factoryConstruct",                  /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\factoryConstruct.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void factoryConstruct(const emlrtStack *sp, int32_T mIneq, int32_T mLinIneq,
                      const real_T Aineq_data[], const int32_T Aineq_size[2],
                      int32_T mLB, const int32_T indexLB[241], int32_T mUB,
                      const int32_T indexUB[241], int32_T mFixed, const int32_T
                      indexFixed[241], int32_T nVarMax, int32_T mConstrMax,
                      j_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx_col;
  int32_T idx_row;
  int32_T obj_tmp;
  int32_T obj_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj_tmp_tmp = mIneq + mLB;
  obj_tmp = ((obj_tmp_tmp + mUB) + mFixed) + 180;
  obj->mConstr = obj_tmp;
  obj->mConstrOrig = obj_tmp;
  obj->mConstrMax = mConstrMax;
  obj->nVar = 241;
  obj->nVarOrig = 241;
  obj->nVarMax = nVarMax;
  obj->ldA = nVarMax;
  if (mIneq > 0) {
    obj->Aineq.size[0] = nVarMax;
    obj->Aineq.size[1] = mIneq;
    obj->bineq.size[0] = mIneq;
    obj->bineq.size[1] = 1;
  } else {
    obj->Aineq.size[0] = 0;
    obj->Aineq.size[1] = 0;
    obj->bineq.size[0] = 0;
    obj->bineq.size[1] = 0;
  }

  obj->Aeq.size[0] = nVarMax;
  obj->Aeq.size[1] = 180;
  obj->lb.size[0] = nVarMax;
  obj->ub.size[0] = nVarMax;
  obj->indexLB.size[0] = nVarMax;
  obj->indexUB.size[0] = nVarMax;
  obj->indexFixed.size[0] = nVarMax;
  obj->mEqRemoved = 0;
  obj->ATwset.size[0] = nVarMax;
  obj->ATwset.size[1] = mConstrMax;
  obj->bwset.size[0] = mConstrMax;
  obj->nActiveConstr = 0;
  obj->maxConstrWorkspace.size[0] = mConstrMax;
  obj->sizes[0] = mFixed;
  obj->sizes[1] = 180;
  obj->sizes[2] = mIneq;
  obj->sizes[3] = mLB;
  obj->sizes[4] = mUB;
  obj->sizesPhaseOne[0] = mFixed;
  obj->sizesPhaseOne[1] = 180;
  obj->sizesPhaseOne[2] = mIneq;
  obj->sizesPhaseOne[3] = mLB + 1;
  obj->sizesPhaseOne[4] = mUB;
  obj->sizesRegularized[0] = mFixed;
  obj->sizesRegularized[1] = 180;
  obj->sizesRegularized[2] = mIneq;
  obj->sizesRegularized[3] = obj_tmp_tmp + 360;
  obj->sizesRegularized[4] = mUB;
  obj->sizesRegPhaseOne[0] = mFixed;
  obj->sizesRegPhaseOne[1] = 180;
  obj->sizesRegPhaseOne[2] = mIneq;
  obj->sizesRegPhaseOne[3] = obj_tmp_tmp + 361;
  obj->sizesRegPhaseOne[4] = mUB;
  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 180;
  obj->isActiveIdxRegPhaseOne[3] = mIneq;
  obj->isActiveIdxRegPhaseOne[4] = mLB;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (obj_tmp_tmp = 0; obj_tmp_tmp < 5; obj_tmp_tmp++) {
    obj->sizesNormal[obj_tmp_tmp] = obj->sizes[obj_tmp_tmp];
    obj->isActiveIdxRegPhaseOne[obj_tmp_tmp + 1] += obj->
      isActiveIdxRegPhaseOne[obj_tmp_tmp];
  }

  for (obj_tmp = 0; obj_tmp < 6; obj_tmp++) {
    obj->isActiveIdx[obj_tmp] = obj->isActiveIdxRegPhaseOne[obj_tmp];
    obj->isActiveIdxNormal[obj_tmp] = obj->isActiveIdxRegPhaseOne[obj_tmp];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 180;
  obj->isActiveIdxRegPhaseOne[3] = mIneq;
  obj->isActiveIdxRegPhaseOne[4] = mLB + 1;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (obj_tmp_tmp = 0; obj_tmp_tmp < 5; obj_tmp_tmp++) {
    obj->isActiveIdxRegPhaseOne[obj_tmp_tmp + 1] += obj->
      isActiveIdxRegPhaseOne[obj_tmp_tmp];
  }

  for (obj_tmp = 0; obj_tmp < 6; obj_tmp++) {
    obj->isActiveIdxPhaseOne[obj_tmp] = obj->isActiveIdxRegPhaseOne[obj_tmp];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 180;
  obj->isActiveIdxRegPhaseOne[3] = mIneq;
  obj->isActiveIdxRegPhaseOne[4] = (mLB + mIneq) + 360;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (obj_tmp_tmp = 0; obj_tmp_tmp < 5; obj_tmp_tmp++) {
    obj->isActiveIdxRegPhaseOne[obj_tmp_tmp + 1] += obj->
      isActiveIdxRegPhaseOne[obj_tmp_tmp];
  }

  for (obj_tmp = 0; obj_tmp < 6; obj_tmp++) {
    obj->isActiveIdxRegularized[obj_tmp] = obj->isActiveIdxRegPhaseOne[obj_tmp];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 180;
  obj->isActiveIdxRegPhaseOne[3] = mIneq;
  obj->isActiveIdxRegPhaseOne[4] = (mLB + mIneq) + 361;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  obj->isActiveConstr.size[0] = mConstrMax;
  obj->Wid.size[0] = mConstrMax;
  obj->Wlocalidx.size[0] = mConstrMax;
  for (obj_tmp_tmp = 0; obj_tmp_tmp < 5; obj_tmp_tmp++) {
    obj->isActiveIdxRegPhaseOne[obj_tmp_tmp + 1] += obj->
      isActiveIdxRegPhaseOne[obj_tmp_tmp];
    obj->nWConstr[obj_tmp_tmp] = 0;
  }

  obj->probType = 3;
  obj->SLACK0 = 1.0E-5;
  if (mIneq > 0) {
    st.site = &ic_emlrtRSI;
    if ((1 <= mLinIneq) && (mLinIneq > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx_col = 0; idx_col < mLinIneq; idx_col++) {
      obj_tmp = Aineq_size[0];
      obj_tmp_tmp = Aineq_size[1];
      for (idx_row = 0; idx_row < 241; idx_row++) {
        if ((idx_col + 1 < 1) || (idx_col + 1 > obj_tmp)) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, obj_tmp, &i_emlrtBCI, sp);
        }

        if (idx_row + 1 > obj_tmp_tmp) {
          emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, obj_tmp_tmp, &i_emlrtBCI,
            sp);
        }

        if (idx_row + 1 > obj->Aineq.size[0]) {
          emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, obj->Aineq.size[0],
            &i_emlrtBCI, sp);
        }

        if ((idx_col + 1 < 1) || (idx_col + 1 > obj->Aineq.size[1])) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, obj->Aineq.size[1],
            &i_emlrtBCI, sp);
        }

        obj->Aineq.data[idx_row + obj->Aineq.size[0] * idx_col] =
          Aineq_data[idx_col + obj_tmp * idx_row];
      }
    }
  }

  st.site = &ic_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= mLB - 1) {
    memcpy(&obj->indexLB.data[0], &indexLB[0], mLB * sizeof(int32_T));
  }

  st.site = &ic_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= mUB - 1) {
    memcpy(&obj->indexUB.data[0], &indexUB[0], mUB * sizeof(int32_T));
  }

  st.site = &ic_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= mFixed - 1) {
    memcpy(&obj->indexFixed.data[0], &indexFixed[0], mFixed * sizeof(int32_T));
  }
}

/* End of code generation (factoryConstruct.c) */
