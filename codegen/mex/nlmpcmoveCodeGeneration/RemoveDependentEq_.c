/*
 * RemoveDependentEq_.c
 *
 * Code generation for function 'RemoveDependentEq_'
 *
 */

/* Include files */
#include "RemoveDependentEq_.h"
#include "ComputeNumDependentEq_.h"
#include "IndexOfDependentEq_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "moveConstraint_.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo ue_emlrtRSI = { 1,  /* lineNo */
  "RemoveDependentEq_",                /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\RemoveDependentEq_.p"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 1,  /* lineNo */
  "removeEqConstr",                    /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeEqConstr.p"/* pathName */
};

static emlrtBCInfo rc_emlrtBCI = { 1,  /* iFirst */
  6,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeEqConstr",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeEqConstr.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "RemoveDependentEq_",                /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\RemoveDependentEq_.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeEqConstr",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeEqConstr.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeEqConstr",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeEqConstr.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { 1,  /* iFirst */
  5,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeEqConstr",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeEqConstr.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
int32_T RemoveDependentEq_(const emlrtStack *sp, d_struct_T *memspace,
  j_struct_T *workingset, l_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T TYPE;
  int32_T i;
  int32_T idx;
  int32_T idx_col;
  int32_T mTotalWorkingEq_tmp_tmp;
  int32_T nDepInd;
  int32_T nVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nVar = workingset->nVar;
  mTotalWorkingEq_tmp_tmp = workingset->nWConstr[1] + workingset->nWConstr[0];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp_tmp > 0) {
    st.site = &ue_emlrtRSI;
    if (mTotalWorkingEq_tmp_tmp > 2147483646) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (TYPE = 0; TYPE < mTotalWorkingEq_tmp_tmp; TYPE++) {
      st.site = &ue_emlrtRSI;
      if ((1 <= nVar) && (nVar > 2147483646)) {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (idx_col = 0; idx_col < nVar; idx_col++) {
        i = workingset->ATwset.size[0];
        if ((idx_col + 1 < 1) || (idx_col + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &sc_emlrtBCI, sp);
        }

        i = workingset->ATwset.size[1];
        if (TYPE + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(TYPE + 1, 1, i, &sc_emlrtBCI, sp);
        }

        i = qrmanager->QR.size[0];
        if (TYPE + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(TYPE + 1, 1, i, &sc_emlrtBCI, sp);
        }

        qrmanager->QR.data[TYPE + qrmanager->QR.size[0] * idx_col] =
          workingset->ATwset.data[idx_col + workingset->ATwset.size[0] * TYPE];
      }
    }

    st.site = &ue_emlrtRSI;
    nDepInd = ComputeNumDependentEq_(&st, qrmanager, workingset->bwset.data,
      mTotalWorkingEq_tmp_tmp, workingset->nVar);
    if (nDepInd > 0) {
      st.site = &ue_emlrtRSI;
      IndexOfDependentEq_(&st, memspace->workspace_int.data,
                          memspace->workspace_int.size, workingset->nWConstr[0],
                          nDepInd, qrmanager, workingset->ATwset.data,
                          workingset->ATwset.size, workingset->nVar,
                          mTotalWorkingEq_tmp_tmp);
      st.site = &ue_emlrtRSI;
      countsort(&st, memspace->workspace_int.data, memspace->workspace_int.size,
                nDepInd, memspace->workspace_sort.data,
                memspace->workspace_sort.size, 1, mTotalWorkingEq_tmp_tmp);
      for (idx = nDepInd; idx >= 1; idx--) {
        st.site = &ue_emlrtRSI;
        i = memspace->workspace_int.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &sc_emlrtBCI, &st);
        }

        i = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (i != 0) {
          idx_col = memspace->workspace_int.data[idx - 1];
          if (idx_col <= i) {
            if ((workingset->nActiveConstr == i) || (idx_col == i)) {
              workingset->mEqRemoved++;
              i = workingset->Wlocalidx.size[0];
              if ((idx_col < 1) || (idx_col > i)) {
                emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx -
                  1], 1, i, &tc_emlrtBCI, &st);
              }

              if ((workingset->mEqRemoved < 1) || (workingset->mEqRemoved > 240))
              {
                emlrtDynamicBoundsCheckR2012b(workingset->mEqRemoved, 1, 240,
                  &uc_emlrtBCI, &st);
              }

              i = memspace->workspace_int.data[idx - 1] - 1;
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
                workingset->Wlocalidx.data[i];
              b_st.site = &ye_emlrtRSI;
              mTotalWorkingEq_tmp_tmp = workingset->Wid.size[0];
              if (idx_col > mTotalWorkingEq_tmp_tmp) {
                emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx -
                  1], 1, mTotalWorkingEq_tmp_tmp, &oc_emlrtBCI, &b_st);
              }

              nVar = workingset->Wid.data[i];
              mTotalWorkingEq_tmp_tmp = workingset->Wlocalidx.size[0];
              if (idx_col > mTotalWorkingEq_tmp_tmp) {
                emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx -
                  1], 1, mTotalWorkingEq_tmp_tmp, &oc_emlrtBCI, &b_st);
              }

              if ((nVar < 1) || (nVar > 6)) {
                emlrtDynamicBoundsCheckR2012b(nVar, 1, 6, &pc_emlrtBCI, &b_st);
              }

              idx_col = workingset->isActiveConstr.size[0];
              i = (workingset->isActiveIdx[workingset->Wid.data[i] - 1] +
                   workingset->Wlocalidx.data[i]) - 1;
              if ((i < 1) || (i > idx_col)) {
                emlrtDynamicBoundsCheckR2012b(i, 1, idx_col, &oc_emlrtBCI, &b_st);
              }

              workingset->isActiveConstr.data[i - 1] = false;
              c_st.site = &af_emlrtRSI;
              moveConstraint_(&c_st, workingset, workingset->nActiveConstr,
                              memspace->workspace_int.data[idx - 1]);
              workingset->nActiveConstr--;
              if (nVar > 5) {
                emlrtDynamicBoundsCheckR2012b(6, 1, 5, &qc_emlrtBCI, &b_st);
              }

              workingset->nWConstr[nVar - 1]--;
            } else {
              workingset->mEqRemoved++;
              mTotalWorkingEq_tmp_tmp = workingset->Wid.size[0];
              if ((idx_col < 1) || (idx_col > mTotalWorkingEq_tmp_tmp)) {
                emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx -
                  1], 1, mTotalWorkingEq_tmp_tmp, &tc_emlrtBCI, &st);
              }

              TYPE = workingset->Wid.data[idx_col - 1];
              mTotalWorkingEq_tmp_tmp = workingset->Wlocalidx.size[0];
              if (idx_col > mTotalWorkingEq_tmp_tmp) {
                emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx -
                  1], 1, mTotalWorkingEq_tmp_tmp, &tc_emlrtBCI, &st);
              }

              nVar = workingset->Wlocalidx.data[idx_col - 1];
              if ((workingset->mEqRemoved < 1) || (workingset->mEqRemoved > 240))
              {
                emlrtDynamicBoundsCheckR2012b(workingset->mEqRemoved, 1, 240,
                  &uc_emlrtBCI, &st);
              }

              workingset->indexEqRemoved[workingset->mEqRemoved - 1] = nVar;
              if ((TYPE < 1) || (TYPE > 6)) {
                emlrtDynamicBoundsCheckR2012b(TYPE, 1, 6, &rc_emlrtBCI, &st);
              }

              idx_col = workingset->isActiveConstr.size[0];
              mTotalWorkingEq_tmp_tmp = (workingset->isActiveIdx[TYPE - 1] +
                nVar) - 1;
              if ((mTotalWorkingEq_tmp_tmp < 1) || (mTotalWorkingEq_tmp_tmp >
                   idx_col)) {
                emlrtDynamicBoundsCheckR2012b(mTotalWorkingEq_tmp_tmp, 1,
                  idx_col, &tc_emlrtBCI, &st);
              }

              workingset->isActiveConstr.data[mTotalWorkingEq_tmp_tmp - 1] =
                false;
              b_st.site = &ye_emlrtRSI;
              moveConstraint_(&b_st, workingset, i, memspace->
                              workspace_int.data[idx - 1]);
              b_st.site = &ye_emlrtRSI;
              moveConstraint_(&b_st, workingset, workingset->nActiveConstr, i);
              workingset->nActiveConstr--;
              if (TYPE > 5) {
                emlrtDynamicBoundsCheckR2012b(6, 1, 5, &vc_emlrtBCI, &st);
              }

              workingset->nWConstr[TYPE - 1]--;
            }
          }
        }
      }
    }
  }

  return nDepInd;
}

/* End of code generation (RemoveDependentEq_.c) */
