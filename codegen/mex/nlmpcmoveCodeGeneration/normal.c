/*
 * normal.c
 *
 * Code generation for function 'normal'
 *
 */

/* Include files */
#include "normal.h"
#include "addAeqConstr.h"
#include "computeConstrViolationIneq_.h"
#include "driver1.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo re_emlrtRSI = { 1,  /* lineNo */
  "normal",                            /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\normal.p"/* pathName */
};

static emlrtBCInfo lc_emlrtBCI = { 1,  /* iFirst */
  180,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "normal",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\normal.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void normal(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
            real_T Hessian[58081], const real_T grad_data[], const int32_T
            grad_size[1], g_struct_T *TrialState, k_struct_T *MeritFunction,
            d_struct_T *memspace, j_struct_T *WorkingSet, l_struct_T *QRManager,
            m_struct_T *CholManager, i_struct_T *QPObjective, const c_struct_T
            *qpoptions)
{
  c_struct_T b_qpoptions;
  c_struct_T c_qpoptions;
  emlrtStack b_st;
  emlrtStack st;
  real_T constrViolationEq;
  real_T constrViolationIneq;
  real_T penaltyParamTrial;
  int32_T k;
  boolean_T exitg1;
  boolean_T nonlinEqRemoved;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_qpoptions = *qpoptions;
  c_qpoptions = *qpoptions;
  st.site = &re_emlrtRSI;
  b_driver(SD, &st, Hessian, grad_data, grad_size, TrialState, memspace,
           WorkingSet, QRManager, CholManager, QPObjective, &b_qpoptions,
           &c_qpoptions);
  if (TrialState->state > 0) {
    st.site = &re_emlrtRSI;
    penaltyParamTrial = MeritFunction->penaltyParam;
    constrViolationEq = 0.0;
    for (k = 0; k < 180; k++) {
      constrViolationEq += muDoubleScalarAbs(TrialState->cEq[k]);
    }

    b_st.site = &xg_emlrtRSI;
    constrViolationIneq = computeConstrViolationIneq_(&b_st, WorkingSet->sizes[2],
      TrialState->cIneq.data, TrialState->cIneq.size);
    constrViolationIneq += constrViolationEq;
    constrViolationEq = MeritFunction->linearizedConstrViol;
    MeritFunction->linearizedConstrViol = 0.0;
    constrViolationEq += constrViolationIneq;
    if ((constrViolationEq > 2.2204460492503131E-16) && (TrialState->fstar > 0.0))
    {
      if (TrialState->sqpFval == 0.0) {
        penaltyParamTrial = 1.0;
      } else {
        penaltyParamTrial = 1.5;
      }

      penaltyParamTrial = penaltyParamTrial * TrialState->fstar /
        constrViolationEq;
    }

    if (penaltyParamTrial < MeritFunction->penaltyParam) {
      MeritFunction->phi = TrialState->sqpFval + penaltyParamTrial *
        constrViolationIneq;
      if ((MeritFunction->initFval + penaltyParamTrial *
           (MeritFunction->initConstrViolationEq +
            MeritFunction->initConstrViolationIneq)) - MeritFunction->phi >
          (real_T)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) > TrialState->sqpIterations)
        {
          MeritFunction->threshold *= 10.0;
        }

        MeritFunction->penaltyParam = muDoubleScalarMax(penaltyParamTrial,
          1.0E-10);
      } else {
        MeritFunction->phi = TrialState->sqpFval + MeritFunction->penaltyParam *
          constrViolationIneq;
      }
    } else {
      MeritFunction->penaltyParam = muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
      MeritFunction->phi = TrialState->sqpFval + MeritFunction->penaltyParam *
        constrViolationIneq;
    }

    MeritFunction->phiPrimePlus = muDoubleScalarMin(TrialState->fstar -
      MeritFunction->penaltyParam * constrViolationIneq, 0.0);
  }

  st.site = &re_emlrtRSI;
  sortLambdaQP(&st, TrialState->lambda.data, TrialState->lambda.size,
               WorkingSet->nActiveConstr, WorkingSet->sizes,
               WorkingSet->isActiveIdx, WorkingSet->Wid.data,
               WorkingSet->Wid.size, WorkingSet->Wlocalidx.data,
               WorkingSet->Wlocalidx.size, memspace->workspace_double.data,
               memspace->workspace_double.size);
  nonlinEqRemoved = (WorkingSet->mEqRemoved > 0);
  exitg1 = false;
  while ((!exitg1) && (WorkingSet->mEqRemoved > 0)) {
    if ((WorkingSet->mEqRemoved < 1) || (WorkingSet->mEqRemoved > 180)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 180, &lc_emlrtBCI,
        sp);
    }

    k = WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1];
    if (k >= 1) {
      if ((WorkingSet->mEqRemoved < 1) || (WorkingSet->mEqRemoved > 180)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 180,
          &lc_emlrtBCI, sp);
      }

      st.site = &re_emlrtRSI;
      addAeqConstr(&st, WorkingSet, k);
      WorkingSet->mEqRemoved--;
    } else {
      exitg1 = true;
    }
  }

  if (nonlinEqRemoved) {
    st.site = &re_emlrtRSI;
    for (k = 0; k < 180; k++) {
      WorkingSet->Wlocalidx.data[WorkingSet->sizes[0] + k] = k + 1;
    }
  }
}

/* End of code generation (normal.c) */
