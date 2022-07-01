/*
 * driver.c
 *
 * Code generation for function 'driver'
 *
 */

/* Include files */
#include "driver.h"
#include "BFGSUpdate.h"
#include "computeConstrViolationIneq_.h"
#include "computeDeltaLag.h"
#include "computeLinearResiduals.h"
#include "eml_int_forloop_overflow_check.h"
#include "evalObjAndConstr.h"
#include "evalObjAndConstrAndDerivatives.h"
#include "linesearch.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "revertSolution.h"
#include "rt_nonfinite.h"
#include "saveJacobian.h"
#include "saveState.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hd_emlrtRSI = { 1,  /* lineNo */
  "driver",                            /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\driver.p"/* pathName */
};

static emlrtBCInfo vb_emlrtBCI = { 1,  /* iFirst */
  321,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "driver",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\driver.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "driver",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\driver.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { 1,  /* iFirst */
  321,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "driver",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\driver.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void driver(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, real_T
            Hessian[103041], const real_T bineq_data[], const real_T lb[321],
            const real_T ub[321], g_struct_T *TrialState, k_struct_T
            *MeritFunction, const h_struct_T *FcnEvaluator, d_struct_T *memspace,
            j_struct_T *WorkingSet, l_struct_T *QRManager, m_struct_T
            *CholManager, i_struct_T *QPObjective, const int32_T
            fscales_lineq_constraint_size[1], const int32_T
            fscales_cineq_constraint_size[1])
{
  static const char_T qpoptions_SolverName[7] = { 'f', 'm', 'i', 'n', 'c', 'o',
    'n' };

  c_struct_T b_expl_temp;
  c_struct_T expl_temp;
  emlrtStack b_st;
  emlrtStack st;
  struct_T Flags;
  real_T b_TrialState[321];
  real_T constrViolationEq;
  real_T constrViolationIneq;
  int32_T i;
  int32_T mConstr;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T nVar;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  boolean_T socTaken;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr = (((WorkingSet->sizes[0] + WorkingSet->sizes[2]) + WorkingSet->sizes
              [3]) + WorkingSet->sizes[4]) + 240;
  mLinIneq = WorkingSet->sizes[2] - TrialState->mNonlinIneq;
  y = ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
    (WorkingSet->sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet->nVar, y);
  TrialState->steplength = 1.0;
  st.site = &hd_emlrtRSI;
  test_exit(&st, MeritFunction, fscales_lineq_constraint_size,
            fscales_cineq_constraint_size, WorkingSet, TrialState, lb, ub,
            &Flags.gradOK, &Flags.fevalOK, &Flags.done, &Flags.stepAccepted,
            &Flags.failedLineSearch, &Flags.stepType);
  st.site = &hd_emlrtRSI;
  saveJacobian(&st, TrialState, nVar, mIneq, WorkingSet->Aineq.data,
               TrialState->iNonIneq0, WorkingSet->Aeq.data, WorkingSet->ldA);
  st.site = &hd_emlrtRSI;
  saveState(TrialState);
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }

  while (!Flags.done) {
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      st.site = &hd_emlrtRSI;
      b_updateWorkingSetForNewQP(&st, TrialState->xstarsqp, WorkingSet, mIneq,
        TrialState->mNonlinIneq, TrialState->cIneq.data, TrialState->cIneq.size,
        TrialState->cEq, mLB, lb, mUB, ub, mFixed);
      expl_temp.IterDisplayQP = false;
      expl_temp.RemainFeasible = false;
      expl_temp.ProbRelTolFactor = 1.0;
      expl_temp.ConstrRelTolFactor = 1.0;
      expl_temp.PricingTolerance = 0.0;
      expl_temp.ObjectiveLimit = rtMinusInf;
      expl_temp.ConstraintTolerance = 1.0E-6;
      expl_temp.OptimalityTolerance = 2.2204460492503131E-14;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }

      b_expl_temp = expl_temp;
      st.site = &hd_emlrtRSI;
      Flags.stepAccepted = step(SD, &st, &Flags.stepType, Hessian, lb, ub,
        TrialState, MeritFunction, memspace, WorkingSet, QRManager, CholManager,
        QPObjective, &b_expl_temp);
      if (Flags.stepAccepted) {
        st.site = &hd_emlrtRSI;
        if ((1 <= nVar) && (nVar > 2147483646)) {
          b_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (y = 0; y < nVar; y++) {
          if ((y + 1 < 1) || (y + 1 > 321)) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, 321, &vb_emlrtBCI, sp);
          }

          i = TrialState->delta_x.size[0];
          if ((y + 1 < 1) || (y + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &wb_emlrtBCI, sp);
          }

          if ((y + 1 < 1) || (y + 1 > 321)) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, 321, &xb_emlrtBCI, sp);
          }

          TrialState->xstarsqp[y] += TrialState->delta_x.data[y];
        }

        memcpy(&b_TrialState[0], &TrialState->xstarsqp[0], 321U * sizeof(real_T));
        st.site = &hd_emlrtRSI;
        evalObjAndConstr(SD, &st, FcnEvaluator->objfun.tunableEnvironment.f1.x,
                         FcnEvaluator->objfun.tunableEnvironment.f1.lastMV,
                         FcnEvaluator->objfun.tunableEnvironment.f1.ref,
                         FcnEvaluator->objfun.tunableEnvironment.f1.OutputWeights,
                         FcnEvaluator->objfun.tunableEnvironment.f1.MVWeights,
                         FcnEvaluator->objfun.tunableEnvironment.f1.MVRateWeights,
                         FcnEvaluator->objfun.tunableEnvironment.f1.MVScaledTarget,
                         FcnEvaluator->nonlcon.tunableEnvironment.f1.x,
                         FcnEvaluator->nonlcon.tunableEnvironment.f1.OutputMin,
                         FcnEvaluator->nonlcon.tunableEnvironment.f1.OutputMax,
                         FcnEvaluator->mCineq, b_TrialState,
                         TrialState->cIneq.data, TrialState->cIneq.size,
                         TrialState->iNonIneq0, TrialState->cEq,
                         &TrialState->sqpFval, &y);
        Flags.fevalOK = (y == 1);
        TrialState->FunctionEvaluations++;
        st.site = &hd_emlrtRSI;
        b_computeLinearResiduals(TrialState->xstarsqp, nVar,
          TrialState->cIneq.data, TrialState->cIneq.size, mLinIneq,
          WorkingSet->Aineq.data, bineq_data, WorkingSet->ldA);
        st.site = &hd_emlrtRSI;
        if (Flags.fevalOK) {
          constrViolationEq = 0.0;
          for (y = 0; y < 240; y++) {
            constrViolationEq += muDoubleScalarAbs(TrialState->cEq[y]);
          }

          b_st.site = &ph_emlrtRSI;
          constrViolationIneq = computeConstrViolationIneq_(&b_st, mIneq,
            TrialState->cIneq.data, TrialState->cIneq.size);
          MeritFunction->phiFullStep = TrialState->sqpFval +
            MeritFunction->penaltyParam * (constrViolationEq +
            constrViolationIneq);
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }

      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }

        st.site = &hd_emlrtRSI;
        linesearch(SD, &st, &Flags.fevalOK, bineq_data, WorkingSet->nVar,
                   WorkingSet->ldA, WorkingSet->Aineq.data, TrialState,
                   MeritFunction->penaltyParam, MeritFunction->phi,
                   MeritFunction->phiPrimePlus, MeritFunction->phiFullStep,
                   &FcnEvaluator->objfun.tunableEnvironment.f1,
                   &FcnEvaluator->nonlcon.tunableEnvironment.f1,
                   FcnEvaluator->mCineq, socTaken, &constrViolationEq, &y);
        TrialState->steplength = constrViolationEq;
        if (y > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }

    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      st.site = &hd_emlrtRSI;
      if ((1 <= nVar) && (nVar > 2147483646)) {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (y = 0; y < nVar; y++) {
        if ((y + 1 < 1) || (y + 1 > 321)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, 321, &vb_emlrtBCI, sp);
        }

        i = TrialState->delta_x.size[0];
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &wb_emlrtBCI, sp);
        }

        if ((y + 1 < 1) || (y + 1 > 321)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, 321, &xb_emlrtBCI, sp);
        }

        TrialState->xstarsqp[y] = TrialState->xstarsqp_old[y] +
          TrialState->delta_x.data[y];
      }

      st.site = &hd_emlrtRSI;
      if ((1 <= mConstr) && (mConstr > 2147483646)) {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (y = 0; y < mConstr; y++) {
        i = TrialState->lambdasqp.size[0];
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &wb_emlrtBCI, sp);
        }

        i = TrialState->lambda.size[0];
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &wb_emlrtBCI, sp);
        }

        i = TrialState->lambdasqp.size[0];
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &wb_emlrtBCI, sp);
        }

        i = TrialState->lambdasqp.size[0];
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &wb_emlrtBCI, sp);
        }

        constrViolationEq = TrialState->lambdasqp.data[y];
        TrialState->lambdasqp.data[y] = constrViolationEq +
          TrialState->steplength * (TrialState->lambda.data[y] -
          constrViolationEq);
      }

      st.site = &hd_emlrtRSI;
      saveState(TrialState);
      Flags.gradOK = true;
      memcpy(&b_TrialState[0], &TrialState->xstarsqp[0], 321U * sizeof(real_T));
      st.site = &hd_emlrtRSI;
      evalObjAndConstrAndDerivatives(SD, &st,
        FcnEvaluator->objfun.tunableEnvironment.f1.x,
        FcnEvaluator->objfun.tunableEnvironment.f1.lastMV,
        FcnEvaluator->objfun.tunableEnvironment.f1.ref,
        FcnEvaluator->objfun.tunableEnvironment.f1.OutputWeights,
        FcnEvaluator->objfun.tunableEnvironment.f1.MVWeights,
        FcnEvaluator->objfun.tunableEnvironment.f1.MVRateWeights,
        FcnEvaluator->objfun.tunableEnvironment.f1.MVScaledTarget,
        FcnEvaluator->nonlcon.tunableEnvironment.f1.x,
        FcnEvaluator->nonlcon.tunableEnvironment.f1.OutputMin,
        FcnEvaluator->nonlcon.tunableEnvironment.f1.OutputMax,
        FcnEvaluator->mCineq, b_TrialState, TrialState->grad.data,
        TrialState->grad.size, TrialState->cIneq.data, TrialState->cIneq.size,
        TrialState->iNonIneq0, TrialState->cEq, WorkingSet->Aineq.data,
        WorkingSet->Aineq.size, TrialState->iNonIneq0, WorkingSet->Aeq.data,
        WorkingSet->Aeq.size, &TrialState->sqpFval, &y);
      TrialState->FunctionEvaluations++;
      Flags.fevalOK = (y == 1);
    } else {
      st.site = &hd_emlrtRSI;
      revertSolution(TrialState);
    }

    st.site = &hd_emlrtRSI;
    b_test_exit(&st, &Flags, memspace, MeritFunction,
                fscales_lineq_constraint_size, fscales_cineq_constraint_size,
                WorkingSet, TrialState, QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      st.site = &hd_emlrtRSI;
      computeDeltaLag(&st, nVar, WorkingSet->ldA, TrialState->mNonlinIneq,
                      TrialState->delta_gradLag.data,
                      TrialState->delta_gradLag.size, TrialState->grad.data,
                      TrialState->grad.size, WorkingSet->Aineq.data,
                      TrialState->iNonIneq0, WorkingSet->Aeq.data,
                      TrialState->grad_old.data,
                      TrialState->JacCineqTrans_old.data,
                      TrialState->JacCeqTrans_old.data,
                      TrialState->lambdasqp.data, (mFixed +
        TrialState->iNonIneq0) + 240, mFixed + 1);
      st.site = &hd_emlrtRSI;
      saveJacobian(&st, TrialState, nVar, mIneq, WorkingSet->Aineq.data,
                   TrialState->iNonIneq0, WorkingSet->Aeq.data, WorkingSet->ldA);
      st.site = &hd_emlrtRSI;
      BFGSUpdate(nVar, Hessian, TrialState->delta_x.data,
                 TrialState->delta_gradLag.data, memspace->workspace_double.data);
      TrialState->sqpIterations++;
    }
  }
}

/* End of code generation (driver.c) */
