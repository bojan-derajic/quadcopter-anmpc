/*
 * relaxed.c
 *
 * Code generation for function 'relaxed'
 *
 */

/* Include files */
#include "relaxed.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "ixamax.h"
#include "moveConstraint_.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "updatePenaltyParam.h"
#include "xasum.h"
#include "xcopy.h"
#include "xdot.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo dh_emlrtRSI = { 1,  /* lineNo */
  "relaxed",                           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\relaxed.p"/* pathName */
};

static emlrtRSInfo eh_emlrtRSI = { 1,  /* lineNo */
  "assignResidualsToXSlack",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\assignResidualsToXSlack.p"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 1,  /* lineNo */
  "findActiveSlackLowerBounds",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\findActiveSlackLowerBounds.p"/* pathName */
};

static emlrtRSInfo gh_emlrtRSI = { 1,  /* lineNo */
  "removeActiveSlackLowerBounds",      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\removeActiveSlackLowerBounds.p"/* pathName */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "relaxed",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\relaxed.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { 1,  /* iFirst */
  321,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "relaxed",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\relaxed.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "assignResidualsToXSlack",           /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\assignResidualsToXSlack.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeActiveSlackLowerBounds",      /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\removeActiveSlackLowerBounds.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void relaxed(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
             real_T Hessian[103041], const real_T grad_data[], const int32_T
             grad_size[1], g_struct_T *TrialState, k_struct_T *MeritFunction,
             d_struct_T *memspace, j_struct_T *WorkingSet, l_struct_T *QRManager,
             m_struct_T *CholManager, i_struct_T *QPObjective, c_struct_T
             *qpoptions)
{
  c_struct_T b_qpoptions;
  c_struct_T c_qpoptions;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T beta;
  real_T rho;
  int32_T b_mIneq;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T iIneqEnd;
  int32_T idx;
  int32_T mIneq;
  int32_T nActiveLBArtificial;
  int32_T nVarMax;
  int32_T nVarOrig;
  int32_T temp;
  boolean_T b_tf;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nVarOrig = WorkingSet->nVar;
  nVarMax = WorkingSet->nVarMax;
  mIneq = WorkingSet->sizes[2];
  beta = 0.0;
  st.site = &dh_emlrtRSI;
  if ((1 <= WorkingSet->nVar) && (WorkingSet->nVar > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < nVarOrig; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > 321)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 321, &be_emlrtBCI, sp);
    }

    beta += Hessian[idx + 321 * idx];
  }

  beta /= (real_T)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    i = ixamax(QPObjective->nvar, grad_data);
    if ((i < 1) || (i > grad_size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, grad_size[0], &ae_emlrtBCI, sp);
    }

    rho = 100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad_data[i - 1]));
  } else {
    i = TrialState->lambdasqp.size[0];
    i1 = ixamax(WorkingSet->mConstr, TrialState->lambdasqp.data);
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ae_emlrtBCI, sp);
    }

    rho = muDoubleScalarAbs(TrialState->lambdasqp.data[i1 - 1]);
  }

  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = rho;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  st.site = &dh_emlrtRSI;
  setProblemType(&st, WorkingSet, 2);
  st.site = &dh_emlrtRSI;
  b_mIneq = WorkingSet->sizes[2] - 1;
  temp = (WorkingSet->sizes[3] - WorkingSet->sizes[2]) - 480;
  b_st.site = &eh_emlrtRSI;
  c_xcopy(WorkingSet->sizes[2], WorkingSet->bineq.data,
          memspace->workspace_double.data);
  b_st.site = &eh_emlrtRSI;
  e_xgemv(nVarOrig, WorkingSet->sizes[2], WorkingSet->Aineq.data,
          WorkingSet->ldA, TrialState->xstar.data,
          memspace->workspace_double.data);
  b_st.site = &eh_emlrtRSI;
  if ((1 <= WorkingSet->sizes[2]) && (WorkingSet->sizes[2] > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx <= b_mIneq; idx++) {
    i = TrialState->xstar.size[0];
    i1 = (nVarOrig + idx) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ce_emlrtBCI, &st);
    }

    TrialState->xstar.data[i1 - 1] = (real_T)(memspace->
      workspace_double.data[idx] > 0.0) * memspace->workspace_double.data[idx];
    if (memspace->workspace_double.data[idx] <= 1.0E-6) {
      b_st.site = &eh_emlrtRSI;
      c_st.site = &me_emlrtRSI;
      addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4, (temp + idx) + 1);
    }
  }

  b_st.site = &eh_emlrtRSI;
  memcpy(&memspace->workspace_double.data[0], &WorkingSet->beq[0], 240U * sizeof
         (real_T));
  b_st.site = &eh_emlrtRSI;
  d_xgemv(nVarOrig, WorkingSet->Aeq.data, WorkingSet->ldA,
          TrialState->xstar.data, memspace->workspace_double.data);
  b_st.site = &eh_emlrtRSI;
  for (idx = 0; idx < 240; idx++) {
    iIneqEnd = b_mIneq + idx;
    if (memspace->workspace_double.data[idx] <= 0.0) {
      i = TrialState->xstar.size[0];
      i1 = (nVarOrig + iIneqEnd) + 2;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ce_emlrtBCI, &st);
      }

      TrialState->xstar.data[i1 - 1] = 0.0;
      i = TrialState->xstar.size[0];
      i1 = (nVarOrig + iIneqEnd) + 242;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ce_emlrtBCI, &st);
      }

      TrialState->xstar.data[i1 - 1] = -memspace->workspace_double.data[idx];
      b_st.site = &eh_emlrtRSI;
      c_st.site = &me_emlrtRSI;
      addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4, (temp + iIneqEnd) + 2);
      if (memspace->workspace_double.data[idx] >= -1.0E-6) {
        b_st.site = &eh_emlrtRSI;
        c_st.site = &me_emlrtRSI;
        addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4, (temp + iIneqEnd) + 242);
      }
    } else {
      i = TrialState->xstar.size[0];
      i1 = nVarOrig + iIneqEnd;
      if ((i1 + 2 < 1) || (i1 + 2 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1 + 2, 1, i, &ce_emlrtBCI, &st);
      }

      TrialState->xstar.data[i1 + 1] = memspace->workspace_double.data[idx];
      i = TrialState->xstar.size[0];
      if ((i1 + 242 < 1) || (i1 + 242 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1 + 242, 1, i, &ce_emlrtBCI, &st);
      }

      TrialState->xstar.data[i1 + 241] = 0.0;
      b_st.site = &eh_emlrtRSI;
      c_st.site = &me_emlrtRSI;
      addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4, (temp + iIneqEnd) + 242);
      if (memspace->workspace_double.data[idx] <= 1.0E-6) {
        b_st.site = &eh_emlrtRSI;
        c_st.site = &me_emlrtRSI;
        addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4, (temp + iIneqEnd) + 2);
      }
    }
  }

  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations = (qpoptions->MaxIterations + WorkingSet->nVar) -
    nVarOrig;
  b_qpoptions = *qpoptions;
  c_qpoptions = *qpoptions;
  st.site = &dh_emlrtRSI;
  b_driver(SD, &st, Hessian, grad_data, grad_size, TrialState, memspace,
           WorkingSet, QRManager, CholManager, QPObjective, &b_qpoptions,
           &c_qpoptions);
  qpoptions->MaxIterations = temp;
  st.site = &dh_emlrtRSI;
  b_mIneq = WorkingSet->sizes[2] - 2;
  temp = WorkingSet->sizes[3] - 480;
  nActiveLBArtificial = 0;
  b_st.site = &fh_emlrtRSI;
  i = WorkingSet->isActiveConstr.size[0];
  i1 = WorkingSet->isActiveConstr.size[0];
  for (idx = 0; idx < 240; idx++) {
    b_st.site = &fh_emlrtRSI;
    i2 = (WorkingSet->isActiveIdx[3] + temp) + idx;
    if ((i2 < 1) || (i2 > i)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i, &hc_emlrtBCI, &b_st);
    }

    tf = WorkingSet->isActiveConstr.data[i2 - 1];
    b_st.site = &fh_emlrtRSI;
    if ((i2 + 240 < 1) || (i2 + 240 > i1)) {
      emlrtDynamicBoundsCheckR2012b(i2 + 240, 1, i1, &hc_emlrtBCI, &b_st);
    }

    b_tf = WorkingSet->isActiveConstr.data[i2 + 239];
    memspace->workspace_int.data[idx] = tf;
    memspace->workspace_int.data[idx + 240] = b_tf;
    nActiveLBArtificial = (nActiveLBArtificial + tf) + b_tf;
  }

  b_st.site = &fh_emlrtRSI;
  if ((1 <= WorkingSet->sizes[2]) && (WorkingSet->sizes[2] > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx <= b_mIneq + 1; idx++) {
    b_st.site = &fh_emlrtRSI;
    i = WorkingSet->isActiveConstr.size[0];
    i1 = (((WorkingSet->isActiveIdx[3] + temp) - b_mIneq) + idx) - 2;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &hc_emlrtBCI, &b_st);
    }

    tf = WorkingSet->isActiveConstr.data[i1 - 1];
    memspace->workspace_int.data[idx + 480] = tf;
    nActiveLBArtificial += tf;
  }

  if (TrialState->state != -6) {
    temp = (WorkingSet->nVarMax - nVarOrig) - 1;
    st.site = &dh_emlrtRSI;
    updatePenaltyParam(&st, MeritFunction, TrialState->sqpFval,
                       TrialState->cIneq.data, TrialState->cIneq.size, mIneq,
                       TrialState->cEq, TrialState->sqpIterations,
                       (TrialState->fstar - rho * xasum(temp,
      TrialState->xstar.data, nVarOrig + 1)) - beta / 2.0 * b_xdot(temp,
      TrialState->xstar.data, nVarOrig + 1, TrialState->xstar.data, nVarOrig + 1),
                       TrialState->xstar.data, nVarOrig + 1, (nVarMax - nVarOrig)
                       - 1);
    temp = WorkingSet->isActiveIdx[1];
    st.site = &dh_emlrtRSI;
    for (idx = 0; idx < 240; idx++) {
      if ((memspace->workspace_int.data[idx] != 0) &&
          (memspace->workspace_int.data[idx + 240] != 0)) {
        tf = true;
      } else {
        tf = false;
      }

      i = TrialState->lambda.size[0];
      i1 = temp + idx;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ae_emlrtBCI, sp);
      }

      i = TrialState->lambda.size[0];
      if (i1 > i) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ae_emlrtBCI, sp);
      }

      TrialState->lambda.data[i1 - 1] *= (real_T)tf;
    }

    temp = WorkingSet->isActiveIdx[2];
    iIneqEnd = WorkingSet->nActiveConstr;
    st.site = &dh_emlrtRSI;
    if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = temp; idx <= iIneqEnd; idx++) {
      i = WorkingSet->Wlocalidx.size[0];
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ae_emlrtBCI, sp);
      }

      i = WorkingSet->Wid.size[0];
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ae_emlrtBCI, sp);
      }

      if (WorkingSet->Wid.data[idx - 1] == 3) {
        i = memspace->workspace_int.size[0];
        i1 = WorkingSet->Wlocalidx.data[idx - 1];
        if ((i1 + 480 < 1) || (i1 + 480 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1 + 480, 1, i, &ae_emlrtBCI, sp);
        }

        i = TrialState->lambda.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ae_emlrtBCI, sp);
        }

        i = TrialState->lambda.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ae_emlrtBCI, sp);
        }

        TrialState->lambda.data[idx - 1] *= (real_T)memspace->
          workspace_int.data[i1 + 479];
      }
    }
  }

  st.site = &dh_emlrtRSI;
  temp = WorkingSet->sizes[0];
  i = (WorkingSet->sizes[3] - WorkingSet->sizes[2]) - 480;
  idx = WorkingSet->nActiveConstr;
  while ((idx > temp + 240) && (nActiveLBArtificial > 0)) {
    i1 = WorkingSet->Wid.size[0];
    if ((idx < 1) || (idx > i1)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &de_emlrtBCI, &st);
    }

    if (WorkingSet->Wid.data[idx - 1] == 4) {
      i1 = WorkingSet->Wlocalidx.size[0];
      if (idx > i1) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &de_emlrtBCI, &st);
      }

      i1 = WorkingSet->Wlocalidx.data[idx - 1];
      if (i1 > i) {
        i2 = TrialState->lambda.size[0];
        if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > i2))
        {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, i2,
            &de_emlrtBCI, &st);
        }

        iIneqEnd = WorkingSet->nActiveConstr - 1;
        beta = TrialState->lambda.data[iIneqEnd];
        i2 = TrialState->lambda.size[0];
        if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > i2))
        {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, i2,
            &de_emlrtBCI, &st);
        }

        TrialState->lambda.data[iIneqEnd] = 0.0;
        i2 = TrialState->lambda.size[0];
        if (idx > i2) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i2, &de_emlrtBCI, &st);
        }

        TrialState->lambda.data[idx - 1] = beta;
        b_st.site = &gh_emlrtRSI;
        i2 = WorkingSet->Wid.size[0];
        if (idx > i2) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i2, &oc_emlrtBCI, &b_st);
        }

        i2 = WorkingSet->Wlocalidx.size[0];
        if (idx > i2) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i2, &oc_emlrtBCI, &b_st);
        }

        i2 = WorkingSet->isActiveConstr.size[0];
        i1 = (WorkingSet->isActiveIdx[3] + i1) - 1;
        if ((i1 < 1) || (i1 > i2)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &oc_emlrtBCI, &b_st);
        }

        WorkingSet->isActiveConstr.data[i1 - 1] = false;
        c_st.site = &af_emlrtRSI;
        moveConstraint_(&c_st, WorkingSet, WorkingSet->nActiveConstr, idx);
        WorkingSet->nActiveConstr--;
        WorkingSet->nWConstr[3]--;
        nActiveLBArtificial--;
      }
    }

    idx--;
  }

  QPObjective->nvar = nVarOrig;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  st.site = &dh_emlrtRSI;
  setProblemType(&st, WorkingSet, 3);
  st.site = &dh_emlrtRSI;
  sortLambdaQP(&st, TrialState->lambda.data, TrialState->lambda.size,
               WorkingSet->nActiveConstr, WorkingSet->sizes,
               WorkingSet->isActiveIdx, WorkingSet->Wid.data,
               WorkingSet->Wid.size, WorkingSet->Wlocalidx.data,
               WorkingSet->Wlocalidx.size, memspace->workspace_double.data,
               memspace->workspace_double.size);
}

/* End of code generation (relaxed.c) */
