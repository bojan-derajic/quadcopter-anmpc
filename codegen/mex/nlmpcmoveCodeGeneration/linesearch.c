/*
 * linesearch.c
 *
 * Code generation for function 'linesearch'
 *
 */

/* Include files */
#include "linesearch.h"
#include "computeConstrViolationIneq_.h"
#include "computeLinearResiduals.h"
#include "eml_int_forloop_overflow_check.h"
#include "evalObjAndConstr.h"
#include "isDeltaXTooSmall.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qh_emlrtRSI = { 1,  /* lineNo */
  "linesearch",                        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\linesearch.p"/* pathName */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "linesearch",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\linesearch.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { 1,  /* iFirst */
  241,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "linesearch",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\linesearch.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { 1,  /* iFirst */
  241,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "linesearch",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\linesearch.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void linesearch(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
                boolean_T *evalWellDefined, const real_T bineq_data[], int32_T
                WorkingSet_nVar, int32_T WorkingSet_ldA, const real_T
                WorkingSet_Aineq_data[], g_struct_T *TrialState, real_T
                MeritFunction_penaltyParam, real_T MeritFunction_phi, real_T
                MeritFunction_phiPrimePlus, real_T MeritFunction_phiFullStep,
                const f_struct_T *c_FcnEvaluator_objfun_tunableEn, const
                f_struct_T *c_FcnEvaluator_nonlcon_tunableE, int32_T
                FcnEvaluator_mCineq, boolean_T socTaken, real_T *alpha, int32_T *
                exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T y_data[1743];
  real_T b_TrialState[241];
  real_T constrViolationIneq;
  real_T phi_alpha;
  int32_T exitg1;
  int32_T loop_ub;
  int32_T mLinIneq;
  int32_T y_size_idx_0;
  boolean_T tooSmallX;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  mLinIneq = TrialState->mIneq - TrialState->mNonlinIneq;
  *alpha = 1.0;
  *exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  st.site = &qh_emlrtRSI;
  y_size_idx_0 = TrialState->searchDir.size[0];
  loop_ub = TrialState->searchDir.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&y_data[0], &TrialState->searchDir.data[0], loop_ub * sizeof(real_T));
  }

  if (WorkingSet_nVar >= 1) {
    n_t = (ptrdiff_t)WorkingSet_nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &TrialState->delta_x.data[0], &incx_t, &y_data[0], &incy_t);
  }

  TrialState->searchDir.size[0] = y_size_idx_0;
  if (0 <= y_size_idx_0 - 1) {
    memcpy(&TrialState->searchDir.data[0], &y_data[0], y_size_idx_0 * sizeof
           (real_T));
  }

  do {
    exitg1 = 0;
    if (TrialState->FunctionEvaluations < 24100) {
      if ((*evalWellDefined) && (phi_alpha <= MeritFunction_phi + *alpha *
           0.0001 * MeritFunction_phiPrimePlus)) {
        exitg1 = 1;
      } else {
        *alpha *= 0.7;
        st.site = &qh_emlrtRSI;
        if ((1 <= WorkingSet_nVar) && (WorkingSet_nVar > 2147483646)) {
          b_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (loop_ub = 0; loop_ub < WorkingSet_nVar; loop_ub++) {
          y_size_idx_0 = TrialState->xstar.size[0];
          if ((loop_ub + 1 < 1) || (loop_ub + 1 > y_size_idx_0)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, y_size_idx_0,
              &je_emlrtBCI, sp);
          }

          y_size_idx_0 = TrialState->delta_x.size[0];
          if ((loop_ub + 1 < 1) || (loop_ub + 1 > y_size_idx_0)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, y_size_idx_0,
              &je_emlrtBCI, sp);
          }

          TrialState->delta_x.data[loop_ub] = *alpha * TrialState->
            xstar.data[loop_ub];
        }

        if (socTaken) {
          st.site = &qh_emlrtRSI;
          b_xaxpy(WorkingSet_nVar, *alpha * *alpha,
                  TrialState->socDirection.data, TrialState->delta_x.data);
        }

        st.site = &qh_emlrtRSI;
        tooSmallX = isDeltaXTooSmall(&st, TrialState->xstarsqp,
          TrialState->delta_x.data, TrialState->delta_x.size, WorkingSet_nVar);
        if (tooSmallX) {
          *exitflag = -2;
          exitg1 = 1;
        } else {
          st.site = &qh_emlrtRSI;
          for (loop_ub = 0; loop_ub < WorkingSet_nVar; loop_ub++) {
            if ((loop_ub + 1 < 1) || (loop_ub + 1 > 241)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, 241, &ke_emlrtBCI,
                sp);
            }

            y_size_idx_0 = TrialState->delta_x.size[0];
            if ((loop_ub + 1 < 1) || (loop_ub + 1 > y_size_idx_0)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, y_size_idx_0,
                &je_emlrtBCI, sp);
            }

            if ((loop_ub + 1 < 1) || (loop_ub + 1 > 241)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, 241, &le_emlrtBCI,
                sp);
            }

            TrialState->xstarsqp[loop_ub] = TrialState->xstarsqp_old[loop_ub] +
              TrialState->delta_x.data[loop_ub];
          }

          memcpy(&b_TrialState[0], &TrialState->xstarsqp[0], 241U * sizeof
                 (real_T));
          st.site = &qh_emlrtRSI;
          evalObjAndConstr(SD, &st, c_FcnEvaluator_objfun_tunableEn->x,
                           c_FcnEvaluator_objfun_tunableEn->lastMV,
                           c_FcnEvaluator_objfun_tunableEn->ref,
                           c_FcnEvaluator_objfun_tunableEn->OutputWeights,
                           c_FcnEvaluator_objfun_tunableEn->MVWeights,
                           c_FcnEvaluator_objfun_tunableEn->MVRateWeights,
                           c_FcnEvaluator_objfun_tunableEn->MVScaledTarget,
                           c_FcnEvaluator_nonlcon_tunableE->x,
                           c_FcnEvaluator_nonlcon_tunableE->OutputMin,
                           c_FcnEvaluator_nonlcon_tunableE->OutputMax,
                           FcnEvaluator_mCineq, b_TrialState,
                           TrialState->cIneq.data, TrialState->cIneq.size,
                           TrialState->iNonIneq0, TrialState->cEq,
                           &TrialState->sqpFval, &y_size_idx_0);
          st.site = &qh_emlrtRSI;
          b_computeLinearResiduals(TrialState->xstarsqp, WorkingSet_nVar,
            TrialState->cIneq.data, TrialState->cIneq.size, mLinIneq,
            WorkingSet_Aineq_data, bineq_data, WorkingSet_ldA);
          TrialState->FunctionEvaluations++;
          *evalWellDefined = (y_size_idx_0 == 1);
          st.site = &qh_emlrtRSI;
          if (*evalWellDefined) {
            phi_alpha = 0.0;
            for (y_size_idx_0 = 0; y_size_idx_0 < 180; y_size_idx_0++) {
              phi_alpha += muDoubleScalarAbs(TrialState->cEq[y_size_idx_0]);
            }

            b_st.site = &ph_emlrtRSI;
            constrViolationIneq = computeConstrViolationIneq_(&b_st,
              TrialState->mIneq, TrialState->cIneq.data, TrialState->cIneq.size);
            phi_alpha = TrialState->sqpFval + MeritFunction_penaltyParam *
              (phi_alpha + constrViolationIneq);
          } else {
            phi_alpha = rtInf;
          }
        }
      }
    } else {
      *exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (linesearch.c) */
