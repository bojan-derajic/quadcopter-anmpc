/*
 * soc.c
 *
 * Code generation for function 'soc'
 *
 */

/* Include files */
#include "soc.h"
#include "addAeqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xnrm2.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hh_emlrtRSI = { 1,  /* lineNo */
  "soc",                               /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\soc.p"/* pathName */
};

static emlrtRSInfo ih_emlrtRSI = { 1,  /* lineNo */
  "updateWorkingSet",                  /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\updateWorkingSet.p"/* pathName */
};

static emlrtRSInfo jh_emlrtRSI = { 1,  /* lineNo */
  "restoreWorkingSet",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\restoreWorkingSet.p"/* pathName */
};

static emlrtBCInfo ee_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "soc",                               /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\soc.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSet",                  /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\updateWorkingSet.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "soc",                               /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\soc.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "restoreWorkingSet",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\restoreWorkingSet.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
boolean_T soc(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
              real_T Hessian[103041], const real_T grad_data[], const int32_T
              grad_size[1], g_struct_T *TrialState, d_struct_T *memspace,
              j_struct_T *WorkingSet, l_struct_T *QRManager, m_struct_T
              *CholManager, i_struct_T *QPObjective, const c_struct_T *qpoptions)
{
  c_struct_T b_qpoptions;
  c_struct_T c_qpoptions;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T oldDirIdx_tmp;
  int32_T i;
  int32_T idx;
  int32_T idxIneqOffset;
  int32_T idx_Aineq;
  int32_T idx_IneqLocal_tmp;
  int32_T idx_Partition;
  int32_T idx_lower;
  int32_T idx_upper;
  int32_T mConstrMax;
  int32_T mIneq;
  int32_T nVar;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  boolean_T exitg1;
  boolean_T success;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  nWIneq_old = WorkingSet->nWConstr[2];
  nWLower_old = WorkingSet->nWConstr[3];
  nWUpper_old = WorkingSet->nWConstr[4];
  nVar = WorkingSet->nVar;
  mConstrMax = WorkingSet->mConstrMax;
  st.site = &hh_emlrtRSI;
  b_st.site = &oc_emlrtRSI;
  c_st.site = &pc_emlrtRSI;
  if ((1 <= WorkingSet->nVar) && (WorkingSet->nVar > 2147483646)) {
    d_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  if (0 <= nVar - 1) {
    memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0], nVar * sizeof
           (real_T));
  }

  st.site = &hh_emlrtRSI;
  if ((1 <= WorkingSet->nVar) && (WorkingSet->nVar > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (mIneq = 0; mIneq < nVar; mIneq++) {
    i = TrialState->xstar.size[0];
    if ((mIneq + 1 < 1) || (mIneq + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(mIneq + 1, 1, i, &ge_emlrtBCI, sp);
    }

    i = TrialState->socDirection.size[0];
    if ((mIneq + 1 < 1) || (mIneq + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(mIneq + 1, 1, i, &ge_emlrtBCI, sp);
    }

    TrialState->socDirection.data[mIneq] = TrialState->xstar.data[mIneq];
  }

  st.site = &hh_emlrtRSI;
  c_xcopy(WorkingSet->mConstrMax, TrialState->lambda.data,
          TrialState->lambda_old.data);
  st.site = &hh_emlrtRSI;
  mIneq = WorkingSet->sizes[2];
  idxIneqOffset = WorkingSet->isActiveIdx[2];
  b_st.site = &ih_emlrtRSI;
  for (idx = 0; idx < 240; idx++) {
    WorkingSet->beq[idx] = -TrialState->cEq[idx];
  }

  b_st.site = &ih_emlrtRSI;
  m_xgemv(WorkingSet->nVar, WorkingSet->Aeq.data, WorkingSet->ldA,
          TrialState->searchDir.data, WorkingSet->beq);
  b_st.site = &ih_emlrtRSI;
  c_st.site = &oc_emlrtRSI;
  for (idx_Aineq = 0; idx_Aineq < 240; idx_Aineq++) {
    WorkingSet->bwset.data[WorkingSet->sizes[0] + idx_Aineq] = WorkingSet->
      beq[idx_Aineq];
  }

  if (WorkingSet->sizes[2] > 0) {
    b_st.site = &ih_emlrtRSI;
    if ((1 <= WorkingSet->sizes[2]) && (WorkingSet->sizes[2] > 2147483646)) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx < mIneq; idx++) {
      i = TrialState->cIneq.size[0];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &fe_emlrtBCI, &st);
      }

      i = WorkingSet->bineq.size[0] * WorkingSet->bineq.size[1];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &fe_emlrtBCI, &st);
      }

      WorkingSet->bineq.data[idx] = -TrialState->cIneq.data[idx];
    }

    b_st.site = &ih_emlrtRSI;
    n_xgemv(SD, WorkingSet->nVar, WorkingSet->sizes[2], WorkingSet->Aineq.data,
            WorkingSet->ldA, TrialState->searchDir.data, WorkingSet->bineq.data,
            WorkingSet->bineq.size);
    idx_Aineq = 1;
    idx_lower = WorkingSet->sizes[2] + 1;
    idx_upper = (WorkingSet->sizes[2] + WorkingSet->sizes[3]) + 1;
    mIneq = WorkingSet->nActiveConstr;
    b_st.site = &ih_emlrtRSI;
    if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = idxIneqOffset; idx <= mIneq; idx++) {
      i = WorkingSet->Wid.size[0];
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &fe_emlrtBCI, &st);
      }

      i = WorkingSet->Wlocalidx.size[0];
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &fe_emlrtBCI, &st);
      }

      idx_IneqLocal_tmp = WorkingSet->Wlocalidx.data[idx - 1];
      switch (WorkingSet->Wid.data[idx - 1]) {
       case 3:
        idx_Partition = idx_Aineq;
        idx_Aineq++;
        i = WorkingSet->bineq.size[0] * WorkingSet->bineq.size[1];
        if ((idx_IneqLocal_tmp < 1) || (idx_IneqLocal_tmp > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx.data[idx - 1], 1,
            i, &fe_emlrtBCI, &st);
        }

        i = WorkingSet->bwset.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &fe_emlrtBCI, &st);
        }

        WorkingSet->bwset.data[idx - 1] = WorkingSet->
          bineq.data[idx_IneqLocal_tmp - 1];
        break;

       case 4:
        idx_Partition = idx_lower;
        idx_lower++;
        break;

       default:
        idx_Partition = idx_upper;
        idx_upper++;
        break;
      }

      i = TrialState->workingset_old.size[0];
      if ((idx_Partition < 1) || (idx_Partition > i)) {
        emlrtDynamicBoundsCheckR2012b(idx_Partition, 1, i, &fe_emlrtBCI, &st);
      }

      TrialState->workingset_old.data[idx_Partition - 1] = idx_IneqLocal_tmp;
    }
  }

  st.site = &hh_emlrtRSI;
  xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar.data);
  b_qpoptions = *qpoptions;
  c_qpoptions = *qpoptions;
  st.site = &hh_emlrtRSI;
  b_driver(SD, &st, Hessian, grad_data, grad_size, TrialState, memspace,
           WorkingSet, QRManager, CholManager, QPObjective, &b_qpoptions,
           &c_qpoptions);
  exitg1 = false;
  while ((!exitg1) && (WorkingSet->mEqRemoved > 0)) {
    if ((WorkingSet->mEqRemoved < 1) || (WorkingSet->mEqRemoved > 240)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 240, &ee_emlrtBCI,
        sp);
    }

    if (WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1] >= 1) {
      if ((WorkingSet->mEqRemoved < 1) || (WorkingSet->mEqRemoved > 240)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 240,
          &ee_emlrtBCI, sp);
      }

      st.site = &hh_emlrtRSI;
      addAeqConstr(&st, WorkingSet, WorkingSet->indexEqRemoved
                   [WorkingSet->mEqRemoved - 1]);
      WorkingSet->mEqRemoved--;
    } else {
      exitg1 = true;
    }
  }

  st.site = &hh_emlrtRSI;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < nVar; idx++) {
    i = TrialState->socDirection.size[0];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ge_emlrtBCI, sp);
    }

    oldDirIdx_tmp = TrialState->socDirection.data[idx];
    i = TrialState->xstar.size[0];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ge_emlrtBCI, sp);
    }

    i = TrialState->socDirection.size[0];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ge_emlrtBCI, sp);
    }

    TrialState->socDirection.data[idx] = TrialState->xstar.data[idx] -
      oldDirIdx_tmp;
    i = TrialState->xstar.size[0];
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ge_emlrtBCI, sp);
    }

    TrialState->xstar.data[idx] = oldDirIdx_tmp;
  }

  success = (xnrm2(nVar, TrialState->socDirection.data) <= 2.0 * xnrm2(nVar,
              TrialState->xstar.data));
  st.site = &hh_emlrtRSI;
  mIneq = WorkingSet->sizes[2] + 1;
  idx_upper = WorkingSet->sizes[3];
  b_st.site = &jh_emlrtRSI;
  for (idx = 0; idx < 240; idx++) {
    WorkingSet->beq[idx] = -TrialState->cEq[idx];
  }

  b_st.site = &jh_emlrtRSI;
  c_st.site = &oc_emlrtRSI;
  for (idx_Aineq = 0; idx_Aineq < 240; idx_Aineq++) {
    WorkingSet->bwset.data[WorkingSet->sizes[0] + idx_Aineq] = WorkingSet->
      beq[idx_Aineq];
  }

  if (WorkingSet->sizes[2] > 0) {
    b_st.site = &jh_emlrtRSI;
    if ((1 <= WorkingSet->sizes[2]) && (WorkingSet->sizes[2] > 2147483646)) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx <= mIneq - 2; idx++) {
      i = TrialState->cIneq.size[0];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &he_emlrtBCI, &st);
      }

      i = WorkingSet->bineq.size[0] * WorkingSet->bineq.size[1];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &he_emlrtBCI, &st);
      }

      WorkingSet->bineq.data[idx] = -TrialState->cIneq.data[idx];
    }

    if (!success) {
      b_st.site = &jh_emlrtRSI;
      removeAllIneqConstr(&b_st, WorkingSet);
      b_st.site = &jh_emlrtRSI;
      if ((1 <= nWIneq_old) && (nWIneq_old > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < nWIneq_old; idx++) {
        b_st.site = &jh_emlrtRSI;
        i = TrialState->workingset_old.size[0];
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &he_emlrtBCI, &b_st);
        }

        idx_Aineq = TrialState->workingset_old.data[idx];
        c_st.site = &ug_emlrtRSI;
        WorkingSet->nWConstr[2]++;
        i = WorkingSet->isActiveConstr.size[0];
        idx_lower = (WorkingSet->isActiveIdx[2] + idx_Aineq) - 1;
        if ((idx_lower < 1) || (idx_lower > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_lower, 1, i, &ec_emlrtBCI, &c_st);
        }

        WorkingSet->isActiveConstr.data[idx_lower - 1] = true;
        WorkingSet->nActiveConstr++;
        i = WorkingSet->Wid.size[0];
        if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > i))
        {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, i,
            &ec_emlrtBCI, &c_st);
        }

        WorkingSet->Wid.data[WorkingSet->nActiveConstr - 1] = 3;
        i = WorkingSet->Wlocalidx.size[0];
        if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > i))
        {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, i,
            &ec_emlrtBCI, &c_st);
        }

        WorkingSet->Wlocalidx.data[WorkingSet->nActiveConstr - 1] = idx_Aineq;
        c_st.site = &ug_emlrtRSI;
        d_xcopy(WorkingSet->nVar, WorkingSet->Aineq.data, WorkingSet->ldA *
                (idx_Aineq - 1) + 1, WorkingSet->ATwset.data, WorkingSet->ldA *
                (WorkingSet->nActiveConstr - 1) + 1);
        i = WorkingSet->bineq.size[0] * WorkingSet->bineq.size[1];
        if ((idx_Aineq < 1) || (idx_Aineq > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_Aineq, 1, i, &md_emlrtBCI, &b_st);
        }

        i = WorkingSet->bwset.size[0];
        if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > i))
        {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, i,
            &md_emlrtBCI, &b_st);
        }

        WorkingSet->bwset.data[WorkingSet->nActiveConstr - 1] =
          WorkingSet->bineq.data[idx_Aineq - 1];
      }

      b_st.site = &jh_emlrtRSI;
      if ((1 <= nWLower_old) && (nWLower_old > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < nWLower_old; idx++) {
        b_st.site = &jh_emlrtRSI;
        i = TrialState->workingset_old.size[0];
        idx_lower = idx + mIneq;
        if ((idx_lower < 1) || (idx_lower > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_lower, 1, i, &he_emlrtBCI, &b_st);
        }

        c_st.site = &me_emlrtRSI;
        addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4,
          TrialState->workingset_old.data[idx_lower - 1]);
      }

      b_st.site = &jh_emlrtRSI;
      if ((1 <= nWUpper_old) && (nWUpper_old > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < nWUpper_old; idx++) {
        b_st.site = &jh_emlrtRSI;
        i = TrialState->workingset_old.size[0];
        idx_lower = (idx + mIneq) + idx_upper;
        if ((idx_lower < 1) || (idx_lower > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_lower, 1, i, &he_emlrtBCI, &b_st);
        }

        c_st.site = &oe_emlrtRSI;
        addBoundToActiveSetMatrix_(&c_st, WorkingSet, 5,
          TrialState->workingset_old.data[idx_lower - 1]);
      }
    }
  }

  if (!success) {
    st.site = &hh_emlrtRSI;
    c_xcopy(mConstrMax, TrialState->lambda_old.data, TrialState->lambda.data);
  } else {
    st.site = &hh_emlrtRSI;
    sortLambdaQP(&st, TrialState->lambda.data, TrialState->lambda.size,
                 WorkingSet->nActiveConstr, WorkingSet->sizes,
                 WorkingSet->isActiveIdx, WorkingSet->Wid.data,
                 WorkingSet->Wid.size, WorkingSet->Wlocalidx.data,
                 WorkingSet->Wlocalidx.size, memspace->workspace_double.data,
                 memspace->workspace_double.size);
  }

  return success;
}

/* End of code generation (soc.c) */
