/*
 * fmincon.c
 *
 * Code generation for function 'fmincon'
 *
 */

/* Include files */
#include "fmincon.h"
#include "checkLinearInputs.h"
#include "checkNonlinearInputs.h"
#include "computeConstrViolationIneq_.h"
#include "computeLinearResiduals.h"
#include "driver.h"
#include "evalObjAndConstrAndDerivatives.h"
#include "factoryConstruct.h"
#include "initActiveSet.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gb_emlrtRSI = { 1,  /* lineNo */
  "fmincon",                           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\eml\\fmincon.p"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 1,  /* lineNo */
  "factoryConstruct",                  /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+MeritFunction\\factoryConstruct.p"/* pathName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  241,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compressBounds",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\compressBounds.p",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "fmincon",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\eml\\fmincon.p"/* pName */
};

/* Function Definitions */
void fmincon(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
             f_struct_T *fun_tunableEnvironment_f1, const e_struct_T
             *fun_tunableEnvironment_f2, const real_T x0[241], const real_T
             Aineq_data[], const int32_T Aineq_size[2], const real_T bineq_data[],
             const int32_T bineq_size[1], const real_T lb[241], const real_T ub
             [241], const f_struct_T *nonlcon_tunableEnvironment_f1, const
             e_struct_T *nonlcon_tunableEnvironment_f2, real_T x[241], real_T
             *fval, real_T *exitflag, b_struct_T *output)
{
  emlrtStack b_st;
  emlrtStack st;
  h_struct_T FcnEvaluator;
  i_struct_T QPObjective;
  k_struct_T MeritFunction;
  real_T TrialState[241];
  real_T absxk;
  real_T normResid;
  real_T scale;
  real_T t;
  int32_T indexFixed[241];
  int32_T indexLB[241];
  int32_T indexUB[241];
  int32_T fscales_cineq_constraint_size[1];
  int32_T fscales_lineq_constraint_size[1];
  int32_T idx;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mNonlinIneq;
  int32_T mUB;
  int32_T maxDims;
  boolean_T guard1 = false;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  checkLinearInputs(SD, &st, x0, Aineq_data, Aineq_size, bineq_data, bineq_size,
                    lb, ub);
  st.site = &gb_emlrtRSI;
  mNonlinIneq = checkNonlinearInputs(SD, &st, x0,
    nonlcon_tunableEnvironment_f1->x, nonlcon_tunableEnvironment_f1->OutputMin,
    nonlcon_tunableEnvironment_f1->OutputMax);
  mIneq = (bineq_size[0] + mNonlinIneq) + 602;
  mConstrMax = (mIneq + mIneq) - 181;
  maxDims = muIntScalarMax_sint32(mIneq, mConstrMax);
  SD->f9.TrialState.nVarMax = mIneq;
  SD->f9.TrialState.mNonlinIneq = mNonlinIneq;
  SD->f9.TrialState.mNonlinEq = 180;
  SD->f9.TrialState.mIneq = mIneq - 602;
  SD->f9.TrialState.mEq = 180;
  SD->f9.TrialState.iNonIneq0 = (mIneq - mNonlinIneq) - 601;
  SD->f9.TrialState.iNonEq0 = 1;
  SD->f9.TrialState.sqpFval = 0.0;
  SD->f9.TrialState.sqpFval_old = 0.0;
  SD->f9.TrialState.cIneq.size[0] = mIneq - 602;
  SD->f9.TrialState.cIneq_old.size[0] = mIneq - 602;
  SD->f9.TrialState.grad.size[0] = mIneq;
  SD->f9.TrialState.grad_old.size[0] = mIneq;
  SD->f9.TrialState.FunctionEvaluations = 0;
  SD->f9.TrialState.sqpIterations = 0;
  SD->f9.TrialState.sqpExitFlag = 0;
  SD->f9.TrialState.lambdasqp.size[0] = mConstrMax;
  if (0 <= mConstrMax - 1) {
    memset(&SD->f9.TrialState.lambdasqp.data[0], 0, mConstrMax * sizeof(real_T));
  }

  SD->f9.TrialState.lambdasqp_old.size[0] = mConstrMax;
  SD->f9.TrialState.steplength = 1.0;
  SD->f9.TrialState.delta_x.size[0] = mIneq;
  if (0 <= mIneq - 1) {
    memset(&SD->f9.TrialState.delta_x.data[0], 0, mIneq * sizeof(real_T));
  }

  SD->f9.TrialState.socDirection.size[0] = mIneq;
  SD->f9.TrialState.lambda_old.size[0] = mConstrMax;
  SD->f9.TrialState.workingset_old.size[0] = mConstrMax;
  if (mNonlinIneq > 0) {
    SD->f9.TrialState.JacCineqTrans_old.size[0] = mIneq;
    SD->f9.TrialState.JacCineqTrans_old.size[1] = mNonlinIneq;
  } else {
    SD->f9.TrialState.JacCineqTrans_old.size[0] = 0;
    SD->f9.TrialState.JacCineqTrans_old.size[1] = 0;
  }

  SD->f9.TrialState.JacCeqTrans_old.size[0] = mIneq;
  SD->f9.TrialState.JacCeqTrans_old.size[1] = 180;
  SD->f9.TrialState.gradLag.size[0] = mIneq;
  SD->f9.TrialState.delta_gradLag.size[0] = mIneq;
  SD->f9.TrialState.xstar.size[0] = mIneq;
  SD->f9.TrialState.fstar = 0.0;
  SD->f9.TrialState.firstorderopt = 0.0;
  SD->f9.TrialState.lambda.size[0] = mConstrMax;
  if (0 <= mConstrMax - 1) {
    memset(&SD->f9.TrialState.lambda.data[0], 0, mConstrMax * sizeof(real_T));
  }

  SD->f9.TrialState.state = 0;
  SD->f9.TrialState.maxConstr = 0.0;
  SD->f9.TrialState.iterations = 0;
  SD->f9.TrialState.searchDir.size[0] = mIneq;
  memcpy(&SD->f9.TrialState.xstarsqp[0], &x0[0], 241U * sizeof(real_T));
  FcnEvaluator.mCineq = mNonlinIneq;
  FcnEvaluator.objfun.tunableEnvironment.f1 = *fun_tunableEnvironment_f1;
  FcnEvaluator.objfun.tunableEnvironment.f2 = *fun_tunableEnvironment_f2;
  FcnEvaluator.nonlcon.tunableEnvironment.f1 = *nonlcon_tunableEnvironment_f1;
  FcnEvaluator.nonlcon.tunableEnvironment.f2 = *nonlcon_tunableEnvironment_f2;
  FcnEvaluator.nVar = 241;
  FcnEvaluator.mCeq = 180;
  FcnEvaluator.NonFiniteSupport = true;
  FcnEvaluator.SpecifyObjectiveGradient = true;
  FcnEvaluator.SpecifyConstraintGradient = true;
  FcnEvaluator.ScaleProblem = false;
  QPObjective.grad.size[0] = mIneq;
  QPObjective.Hx.size[0] = mIneq - 1;
  QPObjective.maxVar = mIneq;
  QPObjective.beta = 0.0;
  QPObjective.rho = 0.0;
  QPObjective.prev_objtype = 3;
  QPObjective.prev_nvar = 0;
  QPObjective.prev_hasLinear = false;
  QPObjective.gammaScalar = 0.0;
  QPObjective.hasLinear = true;
  QPObjective.nvar = 241;
  QPObjective.objtype = 3;
  SD->f9.memspace.workspace_double.size[0] = maxDims;
  SD->f9.memspace.workspace_double.size[1] = mIneq;
  SD->f9.memspace.workspace_int.size[0] = maxDims;
  SD->f9.memspace.workspace_sort.size[0] = maxDims;
  fscales_lineq_constraint_size[0] = bineq_size[0];
  fscales_cineq_constraint_size[0] = mNonlinIneq;
  st.site = &gb_emlrtRSI;
  mLB = 0;
  mUB = 0;
  mFixed = 0;
  for (idx = 0; idx < 241; idx++) {
    normResid = lb[idx];
    guard1 = false;
    if ((!muDoubleScalarIsInf(normResid)) && (!muDoubleScalarIsNaN(normResid)))
    {
      if (muDoubleScalarAbs(normResid - ub[idx]) < 1.0E-6) {
        mFixed++;
        if (mFixed > 241) {
          emlrtDynamicBoundsCheckR2012b(242, 1, 241, &emlrtBCI, &st);
        }

        indexFixed[mFixed - 1] = idx + 1;
      } else {
        mLB++;
        if (mLB > 241) {
          emlrtDynamicBoundsCheckR2012b(242, 1, 241, &emlrtBCI, &st);
        }

        indexLB[mLB - 1] = idx + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      normResid = ub[idx];
      if ((!muDoubleScalarIsInf(normResid)) && (!muDoubleScalarIsNaN(normResid)))
      {
        mUB++;
        if (mUB > 241) {
          emlrtDynamicBoundsCheckR2012b(242, 1, 241, &emlrtBCI, &st);
        }

        indexUB[mUB - 1] = idx + 1;
      }
    }
  }

  st.site = &gb_emlrtRSI;
  factoryConstruct(&st, mIneq - 602, bineq_size[0], Aineq_data, Aineq_size, mLB,
                   indexLB, mUB, indexUB, mFixed, indexFixed, mIneq, mConstrMax,
                   &SD->f9.WorkingSet);
  st.site = &gb_emlrtRSI;
  for (idx = 0; idx < mLB; idx++) {
    mConstrMax = SD->f9.WorkingSet.indexLB.data[idx];
    SD->f9.TrialState.xstarsqp[mConstrMax - 1] = muDoubleScalarMax
      (SD->f9.TrialState.xstarsqp[mConstrMax - 1], lb[mConstrMax - 1]);
  }

  st.site = &gb_emlrtRSI;
  for (idx = 0; idx < mUB; idx++) {
    mConstrMax = SD->f9.WorkingSet.indexUB.data[idx];
    SD->f9.TrialState.xstarsqp[mConstrMax - 1] = muDoubleScalarMin
      (SD->f9.TrialState.xstarsqp[mConstrMax - 1], ub[mConstrMax - 1]);
  }

  st.site = &gb_emlrtRSI;
  for (idx = 0; idx < mFixed; idx++) {
    mConstrMax = SD->f9.WorkingSet.indexFixed.data[idx];
    SD->f9.TrialState.xstarsqp[mConstrMax - 1] = ub[mConstrMax - 1];
  }

  memcpy(&TrialState[0], &SD->f9.TrialState.xstarsqp[0], 241U * sizeof(real_T));
  st.site = &gb_emlrtRSI;
  evalObjAndConstrAndDerivatives(SD, &st, fun_tunableEnvironment_f1->x,
    fun_tunableEnvironment_f1->lastMV, fun_tunableEnvironment_f1->ref,
    fun_tunableEnvironment_f1->OutputWeights,
    fun_tunableEnvironment_f1->MVWeights,
    fun_tunableEnvironment_f1->MVRateWeights,
    fun_tunableEnvironment_f1->MVScaledTarget, nonlcon_tunableEnvironment_f1->x,
    nonlcon_tunableEnvironment_f1->OutputMin,
    nonlcon_tunableEnvironment_f1->OutputMax, mNonlinIneq, TrialState,
    SD->f9.TrialState.grad.data, SD->f9.TrialState.grad.size,
    SD->f9.TrialState.cIneq.data, SD->f9.TrialState.cIneq.size,
    SD->f9.TrialState.iNonIneq0, SD->f9.TrialState.cEq,
    SD->f9.WorkingSet.Aineq.data, SD->f9.WorkingSet.Aineq.size,
    SD->f9.TrialState.iNonIneq0, SD->f9.WorkingSet.Aeq.data,
    SD->f9.WorkingSet.Aeq.size, &SD->f9.TrialState.sqpFval, &mConstrMax);
  if (mConstrMax != 1) {
    emlrtErrorWithMessageIdR2018a(sp, &f_emlrtRTEI,
      "optim_codegen:fmincon:UndefAtX0", "optim_codegen:fmincon:UndefAtX0", 0);
  }

  SD->f9.TrialState.FunctionEvaluations = 1;
  st.site = &gb_emlrtRSI;
  computeLinearResiduals(SD->f9.TrialState.xstarsqp,
    SD->f9.TrialState.cIneq.data, SD->f9.TrialState.cIneq.size, bineq_size[0],
    SD->f9.WorkingSet.Aineq.data, bineq_data, SD->f9.WorkingSet.ldA);
  st.site = &gb_emlrtRSI;
  updateWorkingSetForNewQP(&st, x0, &SD->f9.WorkingSet, mIneq - 602,
    SD->f9.TrialState.cIneq.data, SD->f9.TrialState.cIneq.size,
    SD->f9.TrialState.cEq, mLB, lb, mUB, ub, mFixed);
  st.site = &gb_emlrtRSI;
  initActiveSet(&st, &SD->f9.WorkingSet);
  st.site = &gb_emlrtRSI;
  MeritFunction.initFval = SD->f9.TrialState.sqpFval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  normResid = 0.0;
  for (mConstrMax = 0; mConstrMax < 180; mConstrMax++) {
    normResid += muDoubleScalarAbs(SD->f9.TrialState.cEq[mConstrMax]);
  }

  MeritFunction.initConstrViolationEq = normResid;
  b_st.site = &fd_emlrtRSI;
  MeritFunction.initConstrViolationIneq = computeConstrViolationIneq_(&b_st,
    mIneq - 602, SD->f9.TrialState.cIneq.data, SD->f9.TrialState.cIneq.size);
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  MeritFunction.firstOrderOpt = 0.0;
  MeritFunction.hasObjective = true;
  SD->f9.obj.ldq = maxDims;
  SD->f9.obj.QR.size[0] = maxDims;
  SD->f9.obj.QR.size[1] = maxDims;
  SD->f9.obj.Q.size[0] = maxDims;
  SD->f9.obj.Q.size[1] = maxDims;
  mConstrMax = maxDims * maxDims;
  if (0 <= mConstrMax - 1) {
    memset(&SD->f9.obj.Q.data[0], 0, mConstrMax * sizeof(real_T));
  }

  SD->f9.obj.jpvt.size[0] = maxDims;
  if (0 <= maxDims - 1) {
    memset(&SD->f9.obj.jpvt.data[0], 0, maxDims * sizeof(int32_T));
  }

  SD->f9.obj.mrows = 0;
  SD->f9.obj.ncols = 0;
  SD->f9.obj.tau.size[0] = muIntScalarMin_sint32(maxDims, maxDims);
  SD->f9.obj.minRowCol = 0;
  SD->f9.obj.usedPivoting = false;
  SD->f9.b_obj.FMat.size[0] = maxDims;
  SD->f9.b_obj.FMat.size[1] = maxDims;
  SD->f9.b_obj.ldm = maxDims;
  SD->f9.b_obj.ndims = 0;
  SD->f9.b_obj.info = 0;
  st.site = &gb_emlrtRSI;
  driver(SD, &st, bineq_data, lb, ub, &SD->f9.TrialState, &MeritFunction,
         &FcnEvaluator, &SD->f9.memspace, &SD->f9.WorkingSet, &SD->f9.obj,
         &SD->f9.b_obj, &QPObjective, fscales_lineq_constraint_size,
         fscales_cineq_constraint_size, SD->f9.unusedExpr);
  memcpy(&x[0], &SD->f9.TrialState.xstarsqp[0], 241U * sizeof(real_T));
  *fval = SD->f9.TrialState.sqpFval;
  *exitflag = SD->f9.TrialState.sqpExitFlag;
  output->iterations = SD->f9.TrialState.sqpIterations;
  output->funcCount = SD->f9.TrialState.FunctionEvaluations;
  output->algorithm[0] = 's';
  output->algorithm[1] = 'q';
  output->algorithm[2] = 'p';
  output->constrviolation = MeritFunction.nlpPrimalFeasError;
  normResid = 0.0;
  scale = 3.3121686421112381E-170;
  for (mConstrMax = 0; mConstrMax < 241; mConstrMax++) {
    absxk = muDoubleScalarAbs(SD->f9.TrialState.delta_x.data[mConstrMax]);
    if (absxk > scale) {
      t = scale / absxk;
      normResid = normResid * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      normResid += t * t;
    }
  }

  output->stepsize = scale * muDoubleScalarSqrt(normResid);
  output->lssteplength = SD->f9.TrialState.steplength;
  output->firstorderopt = MeritFunction.firstOrderOpt;
}

/* End of code generation (fmincon.c) */
