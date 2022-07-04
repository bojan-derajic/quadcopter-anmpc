/*
 * test_exit.c
 *
 * Code generation for function 'test_exit'
 *
 */

/* Include files */
#include "test_exit.h"
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computeLambdaLSQ.h"
#include "computePrimalFeasError.h"
#include "eml_int_forloop_overflow_check.h"
#include "isDeltaXTooSmall.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include "xcopy.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo id_emlrtRSI = { 1,  /* lineNo */
  "test_exit",                         /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\test_exit.p"/* pathName */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "test_exit",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\test_exit.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void b_test_exit(const emlrtStack *sp, struct_T *Flags, d_struct_T *memspace,
                 k_struct_T *MeritFunction, const int32_T
                 fscales_lineq_constraint_size[1], const int32_T
                 fscales_cineq_constraint_size[1], j_struct_T *WorkingSet,
                 g_struct_T *TrialState, l_struct_T *QRManager, const real_T lb
                 [241], const real_T ub[241])
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  real_T nlpComplErrorTmp;
  real_T nlpDualFeasErrorTmp;
  real_T optimRelativeFactor;
  int32_T idx;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLambda;
  int32_T mUB;
  int32_T nActiveConstr;
  int32_T nVar;
  boolean_T dxTooSmall;
  boolean_T guard1 = false;
  boolean_T isFeasible;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0] + 1;
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mLambda = (((WorkingSet->sizes[0] + WorkingSet->sizes[2]) + WorkingSet->sizes
              [3]) + WorkingSet->sizes[4]) + 180;
  st.site = &id_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag.data, TrialState->gradLag.size,
                 WorkingSet->ldA, WorkingSet->nVar, TrialState->grad.data,
                 TrialState->grad.size, WorkingSet->sizes[2],
                 WorkingSet->Aineq.data, WorkingSet->Aeq.data,
                 WorkingSet->indexFixed.data, WorkingSet->sizes[0],
                 WorkingSet->indexLB.data, WorkingSet->indexLB.size,
                 WorkingSet->sizes[3], WorkingSet->indexUB.data,
                 WorkingSet->sizes[4], TrialState->lambdasqp.data,
                 TrialState->lambdasqp.size);
  if (WorkingSet->nVar < 1) {
    nActiveConstr = 0;
  } else {
    n_t = (ptrdiff_t)WorkingSet->nVar;
    incx_t = (ptrdiff_t)1;
    n_t = idamax(&n_t, &TrialState->grad.data[0], &incx_t);
    nActiveConstr = (int32_T)n_t;
  }

  idx = TrialState->grad.size[0];
  if ((nActiveConstr < 1) || (nActiveConstr > idx)) {
    emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, idx, &yb_emlrtBCI, sp);
  }

  optimRelativeFactor = muDoubleScalarMax(1.0, muDoubleScalarAbs
    (TrialState->grad.data[nActiveConstr - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }

  st.site = &id_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(&st,
    TrialState->xstarsqp, WorkingSet->sizes[2] - TrialState->mNonlinIneq,
    TrialState->mNonlinIneq, TrialState->cIneq.data, TrialState->cIneq.size,
    TrialState->cEq, WorkingSet->indexLB.data, WorkingSet->indexLB.size,
    WorkingSet->sizes[3], lb, WorkingSet->indexUB.data, WorkingSet->sizes[4], ub);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor = muDoubleScalarMax(1.0,
      MeritFunction->nlpPrimalFeasError);
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 1.0E-6 *
                MeritFunction->feasRelativeFactor);
  st.site = &id_emlrtRSI;
  computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag.data,
                       TrialState->gradLag.size, &Flags->gradOK,
                       &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    st.site = &id_emlrtRSI;
    MeritFunction->nlpComplError = computeComplError(&st,
      fscales_lineq_constraint_size, fscales_cineq_constraint_size,
      TrialState->xstarsqp, WorkingSet->sizes[2], TrialState->cIneq.data,
      TrialState->cIneq.size, WorkingSet->indexLB.data, WorkingSet->indexLB.size,
      WorkingSet->sizes[3], lb, WorkingSet->indexUB.data, WorkingSet->sizes[4],
      ub, TrialState->lambdasqp.data, TrialState->lambdasqp.size,
      WorkingSet->sizes[0] + 181);
    MeritFunction->firstOrderOpt = muDoubleScalarMax
      (MeritFunction->nlpDualFeasError, MeritFunction->nlpComplError);
    if (TrialState->sqpIterations > 1) {
      st.site = &id_emlrtRSI;
      b_computeGradLag(&st, memspace->workspace_double.data,
                       memspace->workspace_double.size, WorkingSet->ldA,
                       WorkingSet->nVar, TrialState->grad.data,
                       TrialState->grad.size, WorkingSet->sizes[2],
                       WorkingSet->Aineq.data, WorkingSet->Aeq.data,
                       WorkingSet->indexFixed.data, WorkingSet->sizes[0],
                       WorkingSet->indexLB.data, WorkingSet->indexLB.size,
                       WorkingSet->sizes[3], WorkingSet->indexUB.data,
                       WorkingSet->sizes[4], TrialState->lambdasqp_old.data,
                       TrialState->lambdasqp_old.size);
      st.site = &id_emlrtRSI;
      b_computeDualFeasError(&st, WorkingSet->nVar,
        memspace->workspace_double.data, &dxTooSmall, &nlpDualFeasErrorTmp);
      st.site = &id_emlrtRSI;
      nlpComplErrorTmp = computeComplError(&st, fscales_lineq_constraint_size,
        fscales_cineq_constraint_size, TrialState->xstarsqp, WorkingSet->sizes[2],
        TrialState->cIneq.data, TrialState->cIneq.size, WorkingSet->indexLB.data,
        WorkingSet->indexLB.size, WorkingSet->sizes[3], lb,
        WorkingSet->indexUB.data, WorkingSet->sizes[4], ub,
        TrialState->lambdasqp_old.data, TrialState->lambdasqp_old.size,
        WorkingSet->sizes[0] + 1);
      d = muDoubleScalarMax(nlpDualFeasErrorTmp, nlpComplErrorTmp);
      if (d < muDoubleScalarMax(MeritFunction->nlpDualFeasError,
           MeritFunction->nlpComplError)) {
        MeritFunction->nlpDualFeasError = nlpDualFeasErrorTmp;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        MeritFunction->firstOrderOpt = d;
        st.site = &id_emlrtRSI;
        c_xcopy(mLambda, TrialState->lambdasqp_old.data,
                TrialState->lambdasqp.data);
      } else {
        st.site = &id_emlrtRSI;
        c_xcopy(mLambda, TrialState->lambdasqp.data,
                TrialState->lambdasqp_old.data);
      }
    } else {
      st.site = &id_emlrtRSI;
      c_xcopy(mLambda, TrialState->lambdasqp.data,
              TrialState->lambdasqp_old.data);
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 *
                       optimRelativeFactor) && (MeritFunction->nlpComplError <=
         1.0E-6 * optimRelativeFactor)) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          st.site = &id_emlrtRSI;
          dxTooSmall = isDeltaXTooSmall(&st, TrialState->xstarsqp,
            TrialState->delta_x.data, TrialState->delta_x.size, WorkingSet->nVar);
          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags->stepType != 2) {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = -2;
              }
            } else {
              nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr > 0) {
                st.site = &id_emlrtRSI;
                b_updateWorkingSetForNewQP(&st, TrialState->xstarsqp, WorkingSet,
                  WorkingSet->sizes[2], TrialState->mNonlinIneq,
                  TrialState->cIneq.data, TrialState->cIneq.size,
                  TrialState->cEq, WorkingSet->sizes[3], lb, WorkingSet->sizes[4],
                  ub, WorkingSet->sizes[0]);
                st.site = &id_emlrtRSI;
                computeLambdaLSQ(&st, nVar, nActiveConstr, QRManager,
                                 WorkingSet->ATwset.data,
                                 WorkingSet->ATwset.size, TrialState->grad.data,
                                 TrialState->lambda.data,
                                 TrialState->lambda.size,
                                 memspace->workspace_double.data);
                nActiveConstr = mFixed + 179;
                st.site = &id_emlrtRSI;
                if ((mFixed <= mFixed + 179) && (mFixed + 179 > 2147483646)) {
                  b_st.site = &db_emlrtRSI;
                  check_forloop_overflow_error(&b_st);
                }

                for (idx = mFixed; idx <= nActiveConstr; idx++) {
                  TrialState->lambda.data[idx - 1] = -TrialState->
                    lambda.data[idx - 1];
                }

                st.site = &id_emlrtRSI;
                sortLambdaQP(&st, TrialState->lambda.data,
                             TrialState->lambda.size, WorkingSet->nActiveConstr,
                             WorkingSet->sizes, WorkingSet->isActiveIdx,
                             WorkingSet->Wid.data, WorkingSet->Wid.size,
                             WorkingSet->Wlocalidx.data,
                             WorkingSet->Wlocalidx.size,
                             memspace->workspace_double.data,
                             memspace->workspace_double.size);
                st.site = &id_emlrtRSI;
                b_computeGradLag(&st, memspace->workspace_double.data,
                                 memspace->workspace_double.size,
                                 WorkingSet->ldA, nVar, TrialState->grad.data,
                                 TrialState->grad.size, mIneq,
                                 WorkingSet->Aineq.data, WorkingSet->Aeq.data,
                                 WorkingSet->indexFixed.data, mFixed - 1,
                                 WorkingSet->indexLB.data,
                                 WorkingSet->indexLB.size, mLB,
                                 WorkingSet->indexUB.data, mUB,
                                 TrialState->lambda.data,
                                 TrialState->lambda.size);
                st.site = &id_emlrtRSI;
                b_computeDualFeasError(&st, nVar,
                  memspace->workspace_double.data, &dxTooSmall,
                  &nlpDualFeasErrorTmp);
                st.site = &id_emlrtRSI;
                nlpComplErrorTmp = computeComplError(&st,
                  fscales_lineq_constraint_size, fscales_cineq_constraint_size,
                  TrialState->xstarsqp, mIneq, TrialState->cIneq.data,
                  TrialState->cIneq.size, WorkingSet->indexLB.data,
                  WorkingSet->indexLB.size, mLB, lb, WorkingSet->indexUB.data,
                  mUB, ub, TrialState->lambda.data, TrialState->lambda.size,
                  mFixed);
                if ((nlpDualFeasErrorTmp <= 1.0E-6 * optimRelativeFactor) &&
                    (nlpComplErrorTmp <= 1.0E-6 * optimRelativeFactor)) {
                  MeritFunction->nlpDualFeasError = nlpDualFeasErrorTmp;
                  MeritFunction->nlpComplError = nlpComplErrorTmp;
                  MeritFunction->firstOrderOpt = muDoubleScalarMax
                    (nlpDualFeasErrorTmp, nlpComplErrorTmp);
                  st.site = &id_emlrtRSI;
                  c_xcopy(mLambda, TrialState->lambda.data,
                          TrialState->lambdasqp.data);
                  Flags->done = true;
                  TrialState->sqpExitFlag = 1;
                } else {
                  Flags->done = true;
                  TrialState->sqpExitFlag = 2;
                }
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = 2;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          if (TrialState->sqpIterations >= 200) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          } else {
            if (TrialState->FunctionEvaluations >= 24100) {
              Flags->done = true;
              TrialState->sqpExitFlag = 0;
            }
          }
        }
      }
    }
  }
}

void test_exit(const emlrtStack *sp, k_struct_T *MeritFunction, const int32_T
               fscales_lineq_constraint_size[1], const int32_T
               fscales_cineq_constraint_size[1], const j_struct_T *WorkingSet,
               g_struct_T *TrialState, const real_T lb[241], const real_T ub[241],
               boolean_T *Flags_gradOK, boolean_T *Flags_fevalOK, boolean_T
               *Flags_done, boolean_T *Flags_stepAccepted, boolean_T
               *Flags_failedLineSearch, int32_T *Flags_stepType)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack st;
  real_T optimRelativeFactor;
  int32_T i;
  int32_T idx_max;
  boolean_T isFeasible;
  st.prev = sp;
  st.tls = sp->tls;
  *Flags_fevalOK = true;
  *Flags_done = false;
  *Flags_stepAccepted = false;
  *Flags_failedLineSearch = false;
  *Flags_stepType = 1;
  st.site = &id_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag.data, TrialState->gradLag.size,
                 WorkingSet->ldA, WorkingSet->nVar, TrialState->grad.data,
                 TrialState->grad.size, WorkingSet->sizes[2],
                 WorkingSet->Aineq.data, WorkingSet->Aeq.data,
                 WorkingSet->indexFixed.data, WorkingSet->sizes[0],
                 WorkingSet->indexLB.data, WorkingSet->indexLB.size,
                 WorkingSet->sizes[3], WorkingSet->indexUB.data,
                 WorkingSet->sizes[4], TrialState->lambdasqp.data,
                 TrialState->lambdasqp.size);
  if (WorkingSet->nVar < 1) {
    idx_max = 0;
  } else {
    n_t = (ptrdiff_t)WorkingSet->nVar;
    incx_t = (ptrdiff_t)1;
    n_t = idamax(&n_t, &TrialState->grad.data[0], &incx_t);
    idx_max = (int32_T)n_t;
  }

  i = TrialState->grad.size[0];
  if ((idx_max < 1) || (idx_max > i)) {
    emlrtDynamicBoundsCheckR2012b(idx_max, 1, i, &yb_emlrtBCI, sp);
  }

  optimRelativeFactor = muDoubleScalarMax(1.0, muDoubleScalarAbs
    (TrialState->grad.data[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }

  st.site = &id_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(&st,
    TrialState->xstarsqp, WorkingSet->sizes[2] - TrialState->mNonlinIneq,
    TrialState->mNonlinIneq, TrialState->cIneq.data, TrialState->cIneq.size,
    TrialState->cEq, WorkingSet->indexLB.data, WorkingSet->indexLB.size,
    WorkingSet->sizes[3], lb, WorkingSet->indexUB.data, WorkingSet->sizes[4], ub);
  MeritFunction->feasRelativeFactor = muDoubleScalarMax(1.0,
    MeritFunction->nlpPrimalFeasError);
  isFeasible = (MeritFunction->nlpPrimalFeasError <= 1.0E-6 *
                MeritFunction->feasRelativeFactor);
  st.site = &id_emlrtRSI;
  computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag.data,
                       TrialState->gradLag.size, Flags_gradOK,
                       &MeritFunction->nlpDualFeasError);
  if (!*Flags_gradOK) {
    *Flags_done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    st.site = &id_emlrtRSI;
    computeComplError(&st, fscales_lineq_constraint_size,
                      fscales_cineq_constraint_size, TrialState->xstarsqp,
                      WorkingSet->sizes[2], TrialState->cIneq.data,
                      TrialState->cIneq.size, WorkingSet->indexLB.data,
                      WorkingSet->indexLB.size, WorkingSet->sizes[3], lb,
                      WorkingSet->indexUB.data, WorkingSet->sizes[4], ub,
                      TrialState->lambdasqp.data, TrialState->lambdasqp.size,
                      WorkingSet->sizes[0] + 181);
    MeritFunction->nlpComplError = 0.0;
    MeritFunction->firstOrderOpt = muDoubleScalarMax
      (MeritFunction->nlpDualFeasError, 0.0);
    c_xcopy((((WorkingSet->sizes[0] + WorkingSet->sizes[2]) + WorkingSet->sizes
              [3]) + WorkingSet->sizes[4]) + 180, TrialState->lambdasqp.data,
            TrialState->lambdasqp_old.data);
    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 *
                       optimRelativeFactor)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        *Flags_done = true;
        TrialState->sqpExitFlag = -3;
      }
    }
  }
}

/* End of code generation (test_exit.c) */
