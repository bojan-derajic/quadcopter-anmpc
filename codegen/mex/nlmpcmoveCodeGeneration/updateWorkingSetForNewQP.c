/*
 * updateWorkingSetForNewQP.c
 *
 * Code generation for function 'updateWorkingSetForNewQP'
 *
 */

/* Include files */
#include "updateWorkingSetForNewQP.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"

/* Variable Definitions */
static emlrtRSInfo ad_emlrtRSI = { 1,  /* lineNo */
  "updateWorkingSetForNewQP",          /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p"/* pathName */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSetForNewQP",          /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { 1,  /* iFirst */
  241,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSetForNewQP",          /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void b_updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[241],
  j_struct_T *WorkingSet, int32_T mIneq, int32_T mNonlinIneq, const real_T
  cIneq_data[], const int32_T cIneq_size[1], const real_T cEq[180], int32_T mLB,
  const real_T lb[241], int32_T mUB, const real_T ub[241], int32_T mFixed)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T iEq0;
  int32_T idx;
  int32_T idx_local_tmp;
  int32_T iw0;
  int32_T nVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nVar = WorkingSet->nVar;
  st.site = &ad_emlrtRSI;
  for (idx = 0; idx < 180; idx++) {
    WorkingSet->beq[idx] = -cEq[idx];
    WorkingSet->bwset.data[mFixed + idx] = WorkingSet->beq[idx];
  }

  iw0 = WorkingSet->ldA * mFixed + 1;
  iEq0 = 1;
  st.site = &ad_emlrtRSI;
  i = nVar - 1;
  for (idx = 0; idx < 180; idx++) {
    for (b_i = 0; b_i <= i; b_i++) {
      idx_local_tmp = WorkingSet->Aeq.size[0] * 180;
      i1 = iEq0 + b_i;
      if ((i1 < 1) || (i1 > idx_local_tmp)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, idx_local_tmp, &rb_emlrtBCI, sp);
      }

      idx_local_tmp = WorkingSet->ATwset.size[0] * WorkingSet->ATwset.size[1];
      i2 = iw0 + b_i;
      if ((i2 < 1) || (i2 > idx_local_tmp)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, idx_local_tmp, &rb_emlrtBCI, sp);
      }

      WorkingSet->ATwset.data[i2 - 1] = WorkingSet->Aeq.data[i1 - 1];
    }

    iw0 += WorkingSet->ldA;
    iEq0 += WorkingSet->ldA;
  }

  st.site = &ad_emlrtRSI;
  if ((1 <= mIneq) && (mIneq > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mIneq; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > cIneq_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cIneq_size[0], &rb_emlrtBCI, sp);
    }

    i = WorkingSet->bineq.size[0] * WorkingSet->bineq.size[1];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, sp);
    }

    WorkingSet->bineq.data[idx] = -cIneq_data[idx];
  }

  st.site = &ad_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    i = WorkingSet->indexLB.size[0];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, sp);
    }

    if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
         241)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1, 241,
        &bc_emlrtBCI, sp);
    }

    if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
         241)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1, 241,
        &bc_emlrtBCI, sp);
    }

    i = WorkingSet->lb.size[0];
    if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
         i)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1, i,
        &rb_emlrtBCI, sp);
    }

    WorkingSet->lb.data[WorkingSet->indexLB.data[idx] - 1] = -lb
      [WorkingSet->indexLB.data[idx] - 1] + xk[WorkingSet->indexLB.data[idx] - 1];
  }

  st.site = &ad_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    WorkingSet->ub.data[WorkingSet->indexUB.data[idx] - 1] = ub
      [WorkingSet->indexUB.data[idx] - 1] - xk[WorkingSet->indexUB.data[idx] - 1];
  }

  st.site = &ad_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mFixed; idx++) {
    WorkingSet->ub.data[WorkingSet->indexFixed.data[idx] - 1] = ub
      [WorkingSet->indexFixed.data[idx] - 1] - xk[WorkingSet->
      indexFixed.data[idx] - 1];
    WorkingSet->bwset.data[idx] = ub[WorkingSet->indexFixed.data[idx] - 1] -
      xk[WorkingSet->indexFixed.data[idx] - 1];
  }

  if (WorkingSet->nActiveConstr > mFixed + 180) {
    iw0 = mFixed + 181;
    iEq0 = WorkingSet->nActiveConstr;
    st.site = &ad_emlrtRSI;
    if ((mFixed + 181 <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = iw0; idx <= iEq0; idx++) {
      i = WorkingSet->Wlocalidx.size[0];
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &rb_emlrtBCI, sp);
      }

      idx_local_tmp = WorkingSet->Wlocalidx.data[idx - 1];
      i = WorkingSet->Wid.size[0];
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &rb_emlrtBCI, sp);
      }

      switch (WorkingSet->Wid.data[idx - 1]) {
       case 4:
        i = WorkingSet->lb.size[0];
        if ((idx_local_tmp < 1) || (idx_local_tmp > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx.data[idx - 1], 1,
            i, &rb_emlrtBCI, sp);
        }

        i = WorkingSet->bwset.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &rb_emlrtBCI, sp);
        }

        WorkingSet->bwset.data[idx - 1] = WorkingSet->lb.data
          [WorkingSet->Wlocalidx.data[idx - 1] - 1];
        break;

       case 5:
        i = WorkingSet->ub.size[0];
        if ((idx_local_tmp < 1) || (idx_local_tmp > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx.data[idx - 1], 1,
            i, &rb_emlrtBCI, sp);
        }

        i = WorkingSet->bwset.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &rb_emlrtBCI, sp);
        }

        WorkingSet->bwset.data[idx - 1] = WorkingSet->ub.data
          [WorkingSet->Wlocalidx.data[idx - 1] - 1];
        break;

       default:
        i = WorkingSet->bineq.size[0] * WorkingSet->bineq.size[1];
        if ((idx_local_tmp < 1) || (idx_local_tmp > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx.data[idx - 1], 1,
            i, &rb_emlrtBCI, sp);
        }

        i = WorkingSet->bwset.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &rb_emlrtBCI, sp);
        }

        WorkingSet->bwset.data[idx - 1] = WorkingSet->bineq.data[idx_local_tmp -
          1];
        if (idx_local_tmp >= mNonlinIneq) {
          st.site = &ad_emlrtRSI;
          d_xcopy(nVar, WorkingSet->Aineq.data, WorkingSet->ldA * (idx_local_tmp
                   - 1) + 1, WorkingSet->ATwset.data, WorkingSet->ldA * (idx - 1)
                  + 1);
        }
        break;
      }
    }
  }
}

void updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[241],
  j_struct_T *WorkingSet, int32_T mIneq, const real_T cIneq_data[], const
  int32_T cIneq_size[1], const real_T cEq[180], int32_T mLB, const real_T lb[241],
  int32_T mUB, const real_T ub[241], int32_T mFixed)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T iEq0;
  int32_T idx;
  int32_T iw0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (idx = 0; idx < 180; idx++) {
    WorkingSet->beq[idx] = -cEq[idx];
    WorkingSet->bwset.data[mFixed + idx] = WorkingSet->beq[idx];
  }

  iw0 = WorkingSet->ldA * mFixed + 1;
  iEq0 = 1;
  st.site = &ad_emlrtRSI;
  for (idx = 0; idx < 180; idx++) {
    for (i = 0; i < 241; i++) {
      b_i = WorkingSet->Aeq.size[0] * 180;
      i1 = iEq0 + i;
      if ((i1 < 1) || (i1 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &rb_emlrtBCI, sp);
      }

      b_i = WorkingSet->ATwset.size[0] * WorkingSet->ATwset.size[1];
      i2 = iw0 + i;
      if ((i2 < 1) || (i2 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, b_i, &rb_emlrtBCI, sp);
      }

      WorkingSet->ATwset.data[i2 - 1] = WorkingSet->Aeq.data[i1 - 1];
    }

    iw0 += WorkingSet->ldA;
    iEq0 += WorkingSet->ldA;
  }

  st.site = &ad_emlrtRSI;
  if ((1 <= mIneq) && (mIneq > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mIneq; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > cIneq_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cIneq_size[0], &rb_emlrtBCI, sp);
    }

    b_i = WorkingSet->bineq.size[0] * WorkingSet->bineq.size[1];
    if ((idx + 1 < 1) || (idx + 1 > b_i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, b_i, &rb_emlrtBCI, sp);
    }

    WorkingSet->bineq.data[idx] = -cIneq_data[idx];
  }

  st.site = &ad_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    WorkingSet->lb.data[WorkingSet->indexLB.data[idx] - 1] = -lb
      [WorkingSet->indexLB.data[idx] - 1] + xk[WorkingSet->indexLB.data[idx] - 1];
  }

  st.site = &ad_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    WorkingSet->ub.data[WorkingSet->indexUB.data[idx] - 1] = ub
      [WorkingSet->indexUB.data[idx] - 1] - xk[WorkingSet->indexUB.data[idx] - 1];
  }

  st.site = &ad_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mFixed; idx++) {
    WorkingSet->ub.data[WorkingSet->indexFixed.data[idx] - 1] = ub
      [WorkingSet->indexFixed.data[idx] - 1] - xk[WorkingSet->
      indexFixed.data[idx] - 1];
    WorkingSet->bwset.data[idx] = ub[WorkingSet->indexFixed.data[idx] - 1] -
      xk[WorkingSet->indexFixed.data[idx] - 1];
  }
}

/* End of code generation (updateWorkingSetForNewQP.c) */
