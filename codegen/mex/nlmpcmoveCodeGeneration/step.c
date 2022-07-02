/*
 * step.c
 *
 * Code generation for function 'step'
 *
 */

/* Include files */
#include "step.h"
#include "addBoundToActiveSetMatrix_.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "normal.h"
#include "relaxed.h"
#include "rt_nonfinite.h"
#include "soc.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo le_emlrtRSI = { 1,  /* lineNo */
  "makeBoundFeasible",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\makeBoundFeasible.p"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 1,  /* lineNo */
  "step",                              /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\step.p"/* pathName */
};

static emlrtRSInfo kh_emlrtRSI = { 1,  /* lineNo */
  "saturateDirection",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\saturateDirection.p"/* pathName */
};

static emlrtRSInfo lh_emlrtRSI = { 1,  /* lineNo */
  "BFGSReset",                         /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\BFGSReset.p"/* pathName */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "makeBoundFeasible",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\makeBoundFeasible.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "saturateDirection",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\saturateDirection.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "step",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\step.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { 1,  /* iFirst */
  241,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "saturateDirection",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\saturateDirection.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
boolean_T step(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
               int32_T *STEP_TYPE, real_T Hessian[58081], const real_T lb[241],
               const real_T ub[241], g_struct_T *TrialState, k_struct_T
               *MeritFunction, d_struct_T *memspace, j_struct_T *WorkingSet,
               l_struct_T *QRManager, m_struct_T *CholManager, i_struct_T
               *QPObjective, c_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T tmp_data[1743];
  real_T b_tmp_data[962];
  real_T nrmDirInf;
  real_T nrmGradInf;
  int32_T tmp_size[1];
  int32_T exitg1;
  int32_T iH0;
  int32_T idx;
  int32_T loop_ub;
  int32_T mLB;
  int32_T mUB;
  int32_T nVar;
  boolean_T checkBoundViolation;
  boolean_T guard1 = false;
  boolean_T stepSuccess;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  stepSuccess = true;
  checkBoundViolation = true;
  nVar = WorkingSet->nVar;
  if (*STEP_TYPE != 3) {
    st.site = &qe_emlrtRSI;
    xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar.data);
  } else {
    iH0 = TrialState->searchDir.size[0];
    loop_ub = TrialState->searchDir.size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&tmp_data[0], &TrialState->searchDir.data[0], loop_ub * sizeof
             (real_T));
    }

    st.site = &qe_emlrtRSI;
    c_xcopy(WorkingSet->nVar, TrialState->xstar.data, tmp_data);
    TrialState->searchDir.size[0] = iH0;
    if (0 <= iH0 - 1) {
      memcpy(&TrialState->searchDir.data[0], &tmp_data[0], iH0 * sizeof(real_T));
    }
  }

  st.site = &qe_emlrtRSI;
  tmp_size[0] = TrialState->xstar.size[0];
  loop_ub = TrialState->xstar.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&b_tmp_data[0], &TrialState->xstar.data[0], loop_ub * sizeof(real_T));
  }

  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  b_st.site = &le_emlrtRSI;
  if ((1 <= WorkingSet->sizes[3]) && (WorkingSet->sizes[3] > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    iH0 = WorkingSet->indexLB.size[0];
    if ((idx + 1 < 1) || (idx + 1 > iH0)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, iH0, &gc_emlrtBCI, &st);
    }

    if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
         tmp_size[0])) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1, tmp_size[0],
        &gc_emlrtBCI, &st);
    }

    iH0 = WorkingSet->lb.size[0];
    if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
         iH0)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1, iH0,
        &gc_emlrtBCI, &st);
    }

    nrmGradInf = WorkingSet->lb.data[WorkingSet->indexLB.data[idx] - 1];
    if (-b_tmp_data[WorkingSet->indexLB.data[idx] - 1] >= nrmGradInf) {
      iH0 = WorkingSet->lb.size[0];
      if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
           iH0)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1, iH0,
          &gc_emlrtBCI, &st);
      }

      if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
           tmp_size[0])) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1,
          tmp_size[0], &gc_emlrtBCI, &st);
      }

      b_tmp_data[WorkingSet->indexLB.data[idx] - 1] = -nrmGradInf;
      b_st.site = &le_emlrtRSI;
      iH0 = WorkingSet->isActiveConstr.size[0];
      loop_ub = WorkingSet->isActiveIdx[3] + idx;
      if ((loop_ub < 1) || (loop_ub > iH0)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, iH0, &hc_emlrtBCI, &b_st);
      }

      if (!WorkingSet->isActiveConstr.data[loop_ub - 1]) {
        b_st.site = &le_emlrtRSI;
        c_st.site = &me_emlrtRSI;
        addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4, idx + 1);
      }
    }
  }

  b_st.site = &le_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    nrmGradInf = WorkingSet->ub.data[WorkingSet->indexUB.data[idx] - 1];
    if (b_tmp_data[WorkingSet->indexUB.data[idx] - 1] >= nrmGradInf) {
      b_tmp_data[WorkingSet->indexUB.data[idx] - 1] = nrmGradInf;
      b_st.site = &le_emlrtRSI;
      iH0 = WorkingSet->isActiveConstr.size[0];
      loop_ub = WorkingSet->isActiveIdx[4] + idx;
      if ((loop_ub < 1) || (loop_ub > iH0)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, iH0, &hc_emlrtBCI, &b_st);
      }

      if (!WorkingSet->isActiveConstr.data[loop_ub - 1]) {
        b_st.site = &le_emlrtRSI;
        c_st.site = &oe_emlrtRSI;
        addBoundToActiveSetMatrix_(&c_st, WorkingSet, 5, idx + 1);
      }
    }
  }

  TrialState->xstar.size[0] = tmp_size[0];
  loop_ub = tmp_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&TrialState->xstar.data[0], &b_tmp_data[0], loop_ub * sizeof(real_T));
  }

  do {
    exitg1 = 0;
    guard1 = false;
    switch (*STEP_TYPE) {
     case 1:
      st.site = &qe_emlrtRSI;
      normal(SD, &st, Hessian, TrialState->grad.data, TrialState->grad.size,
             TrialState, MeritFunction, memspace, WorkingSet, QRManager,
             CholManager, QPObjective, qpoptions);
      if ((TrialState->state <= 0) && (TrialState->state != -6)) {
        *STEP_TYPE = 2;
      } else {
        iH0 = TrialState->delta_x.size[0];
        loop_ub = TrialState->delta_x.size[0];
        if (0 <= loop_ub - 1) {
          memcpy(&tmp_data[0], &TrialState->delta_x.data[0], loop_ub * sizeof
                 (real_T));
        }

        st.site = &qe_emlrtRSI;
        c_xcopy(nVar, TrialState->xstar.data, tmp_data);
        TrialState->delta_x.size[0] = iH0;
        if (0 <= iH0 - 1) {
          memcpy(&TrialState->delta_x.data[0], &tmp_data[0], iH0 * sizeof(real_T));
        }

        guard1 = true;
      }
      break;

     case 2:
      st.site = &qe_emlrtRSI;
      relaxed(SD, &st, Hessian, TrialState->grad.data, TrialState->grad.size,
              TrialState, MeritFunction, memspace, WorkingSet, QRManager,
              CholManager, QPObjective, qpoptions);
      iH0 = TrialState->delta_x.size[0];
      loop_ub = TrialState->delta_x.size[0];
      if (0 <= loop_ub - 1) {
        memcpy(&tmp_data[0], &TrialState->delta_x.data[0], loop_ub * sizeof
               (real_T));
      }

      st.site = &qe_emlrtRSI;
      c_xcopy(nVar, TrialState->xstar.data, tmp_data);
      TrialState->delta_x.size[0] = iH0;
      if (0 <= iH0 - 1) {
        memcpy(&TrialState->delta_x.data[0], &tmp_data[0], iH0 * sizeof(real_T));
      }

      guard1 = true;
      break;

     default:
      tmp_size[0] = TrialState->grad.size[0];
      loop_ub = TrialState->grad.size[0];
      if (0 <= loop_ub - 1) {
        memcpy(&b_tmp_data[0], &TrialState->grad.data[0], loop_ub * sizeof
               (real_T));
      }

      st.site = &qe_emlrtRSI;
      stepSuccess = soc(SD, &st, Hessian, b_tmp_data, tmp_size, TrialState,
                        memspace, WorkingSet, QRManager, CholManager,
                        QPObjective, qpoptions);
      checkBoundViolation = stepSuccess;
      if (stepSuccess && (TrialState->state != -6)) {
        st.site = &qe_emlrtRSI;
        if ((1 <= nVar) && (nVar > 2147483646)) {
          b_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (idx = 0; idx < nVar; idx++) {
          iH0 = TrialState->xstar.size[0];
          if ((idx + 1 < 1) || (idx + 1 > iH0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, iH0, &jc_emlrtBCI, sp);
          }

          iH0 = TrialState->socDirection.size[0];
          if ((idx + 1 < 1) || (idx + 1 > iH0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, iH0, &jc_emlrtBCI, sp);
          }

          iH0 = TrialState->delta_x.size[0];
          if ((idx + 1 < 1) || (idx + 1 > iH0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, iH0, &jc_emlrtBCI, sp);
          }

          TrialState->delta_x.data[idx] = TrialState->xstar.data[idx] +
            TrialState->socDirection.data[idx];
        }
      }

      guard1 = true;
      break;
    }

    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        st.site = &qe_emlrtRSI;
        nrmGradInf = 0.0;
        nrmDirInf = 1.0;
        for (idx = 0; idx < 241; idx++) {
          nrmGradInf = muDoubleScalarMax(nrmGradInf, muDoubleScalarAbs
            (TrialState->grad.data[idx]));
          nrmDirInf = muDoubleScalarMax(nrmDirInf, muDoubleScalarAbs
            (TrialState->xstar.data[idx]));
        }

        nrmGradInf = muDoubleScalarMax(2.2204460492503131E-16, nrmGradInf /
          nrmDirInf);
        for (loop_ub = 0; loop_ub < 241; loop_ub++) {
          iH0 = 241 * loop_ub;
          b_st.site = &lh_emlrtRSI;
          h_xcopy(&b_st, loop_ub, Hessian, iH0 + 1);
          Hessian[loop_ub + 241 * loop_ub] = nrmGradInf;
          iH0 += loop_ub;
          b_st.site = &lh_emlrtRSI;
          h_xcopy(&b_st, 240 - loop_ub, Hessian, iH0 + 2);
        }
      }
    }
  } while (exitg1 == 0);

  if (checkBoundViolation) {
    mLB = WorkingSet->sizes[3];
    mUB = WorkingSet->sizes[4];
    st.site = &qe_emlrtRSI;
    tmp_size[0] = TrialState->delta_x.size[0];
    loop_ub = TrialState->delta_x.size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&b_tmp_data[0], &TrialState->delta_x.data[0], loop_ub * sizeof
             (real_T));
    }

    b_st.site = &kh_emlrtRSI;
    if ((1 <= WorkingSet->sizes[3]) && (WorkingSet->sizes[3] > 2147483646)) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx < mLB; idx++) {
      iH0 = WorkingSet->indexLB.size[0];
      if ((idx + 1 < 1) || (idx + 1 > iH0)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, iH0, &ic_emlrtBCI, &st);
      }

      if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
           241)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1, 241,
          &kc_emlrtBCI, &st);
      }

      if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
           tmp_size[0])) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1,
          tmp_size[0], &ic_emlrtBCI, &st);
      }

      if ((WorkingSet->indexLB.data[idx] < 1) || (WorkingSet->indexLB.data[idx] >
           241)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB.data[idx], 1, 241,
          &kc_emlrtBCI, &st);
      }

      nrmGradInf = b_tmp_data[WorkingSet->indexLB.data[idx] - 1];
      nrmDirInf = (TrialState->xstarsqp[WorkingSet->indexLB.data[idx] - 1] +
                   nrmGradInf) - lb[WorkingSet->indexLB.data[idx] - 1];
      if (nrmDirInf < 0.0) {
        b_tmp_data[WorkingSet->indexLB.data[idx] - 1] = nrmGradInf - nrmDirInf;
        TrialState->xstar.data[WorkingSet->indexLB.data[idx] - 1] -= nrmDirInf;
      }
    }

    b_st.site = &kh_emlrtRSI;
    if ((1 <= WorkingSet->sizes[4]) && (WorkingSet->sizes[4] > 2147483646)) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx < mUB; idx++) {
      nrmGradInf = b_tmp_data[WorkingSet->indexUB.data[idx] - 1];
      nrmDirInf = (ub[WorkingSet->indexUB.data[idx] - 1] - TrialState->
                   xstarsqp[WorkingSet->indexUB.data[idx] - 1]) - nrmGradInf;
      if (nrmDirInf < 0.0) {
        b_tmp_data[WorkingSet->indexUB.data[idx] - 1] = nrmGradInf + nrmDirInf;
        TrialState->xstar.data[WorkingSet->indexUB.data[idx] - 1] += nrmDirInf;
      }
    }

    TrialState->delta_x.size[0] = tmp_size[0];
    loop_ub = tmp_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&TrialState->delta_x.data[0], &b_tmp_data[0], loop_ub * sizeof
             (real_T));
    }
  }

  return stepSuccess;
}

/* End of code generation (step.c) */
