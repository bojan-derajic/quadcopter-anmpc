/*
 * feasibleratiotest.c
 *
 * Code generation for function 'feasibleratiotest'
 *
 */

/* Include files */
#include "feasibleratiotest.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xnrm2.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo tg_emlrtRSI = { 1,  /* lineNo */
  "feasibleratiotest",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\feasibleratiotest.p"/* pathName */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "feasibleratiotest",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\feasibleratiotest.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void feasibleratiotest(const emlrtStack *sp, const real_T solution_xstar_data[],
  const int32_T solution_xstar_size[1], const real_T solution_searchDir_data[],
  const int32_T solution_searchDir_size[1], real_T workspace_data[], const
  int32_T workspace_size[2], int32_T workingset_nVar, int32_T workingset_ldA,
  const real_T workingset_Aineq_data[], const real_T workingset_bineq_data[],
  const real_T workingset_lb_data[], const int32_T workingset_lb_size[1], const
  real_T workingset_ub_data[], const int32_T workingset_indexLB_data[], const
  int32_T workingset_indexLB_size[1], const int32_T workingset_indexUB_data[],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr_data[], const int32_T
  workingset_isActiveConstr_size[1], const int32_T workingset_nWConstr[5],
  boolean_T isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T
  *constrType, int32_T *constrIdx)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T alphaTemp;
  real_T denomTol;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T ratio;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T ldw;
  int32_T totalIneq;
  int32_T totalUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  totalIneq = workingset_sizes[2];
  totalUB = workingset_sizes[4];
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  denomTol = 2.2204460492503131E-13 * xnrm2(workingset_nVar,
    solution_searchDir_data);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    st.site = &tg_emlrtRSI;
    c_xcopy(workingset_sizes[2], workingset_bineq_data, workspace_data);
    st.site = &tg_emlrtRSI;
    e_xgemv(workingset_nVar, workingset_sizes[2], workingset_Aineq_data,
            workingset_ldA, solution_xstar_data, workspace_data);
    ldw = workspace_size[0];
    st.site = &tg_emlrtRSI;
    l_xgemv(workingset_nVar, workingset_sizes[2], workingset_Aineq_data,
            workingset_ldA, solution_searchDir_data, workspace_data,
            workspace_size[0] + 1);
    st.site = &tg_emlrtRSI;
    if ((1 <= workingset_sizes[2]) && (workingset_sizes[2] > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < totalIneq; idx++) {
      i = ldw + idx;
      if (workspace_data[i] > denomTol) {
        st.site = &tg_emlrtRSI;
        i1 = workingset_isActiveIdx[2] + idx;
        if ((i1 < 1) || (i1 > workingset_isActiveConstr_size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, workingset_isActiveConstr_size[0],
            &hc_emlrtBCI, &st);
        }

        if (!workingset_isActiveConstr_data[i1 - 1]) {
          alphaTemp = muDoubleScalarMin(muDoubleScalarAbs(workspace_data[idx]),
            1.0E-6 - workspace_data[idx]) / workspace_data[i];
          if (alphaTemp < *alpha) {
            *alpha = alphaTemp;
            *constrType = 3;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    if ((workingset_nVar < 1) || (workingset_nVar > solution_xstar_size[0])) {
      emlrtDynamicBoundsCheckR2012b(workingset_nVar, 1, solution_xstar_size[0],
        &vd_emlrtBCI, sp);
    }

    phaseOneCorrectionX = (real_T)isPhaseOne *
      solution_xstar_data[workingset_nVar - 1];
    if (workingset_nVar > solution_searchDir_size[0]) {
      emlrtDynamicBoundsCheckR2012b(workingset_nVar, 1, solution_searchDir_size
        [0], &vd_emlrtBCI, sp);
    }

    phaseOneCorrectionP = (real_T)isPhaseOne *
      solution_searchDir_data[workingset_nVar - 1];
    totalIneq = workingset_sizes[3];
    st.site = &tg_emlrtRSI;
    for (idx = 0; idx <= totalIneq - 2; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > workingset_indexLB_size[0])) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, workingset_indexLB_size[0],
          &vd_emlrtBCI, sp);
      }

      if ((workingset_indexLB_data[idx] < 1) || (workingset_indexLB_data[idx] >
           solution_searchDir_size[0])) {
        emlrtDynamicBoundsCheckR2012b(workingset_indexLB_data[idx], 1,
          solution_searchDir_size[0], &vd_emlrtBCI, sp);
      }

      alphaTemp = -solution_searchDir_data[workingset_indexLB_data[idx] - 1] -
        phaseOneCorrectionP;
      if (alphaTemp > denomTol) {
        st.site = &tg_emlrtRSI;
        i = workingset_isActiveIdx[3] + idx;
        if ((i < 1) || (i > workingset_isActiveConstr_size[0])) {
          emlrtDynamicBoundsCheckR2012b(i, 1, workingset_isActiveConstr_size[0],
            &hc_emlrtBCI, &st);
        }

        if (!workingset_isActiveConstr_data[i - 1]) {
          if ((workingset_indexLB_data[idx] < 1) || (workingset_indexLB_data[idx]
               > solution_xstar_size[0])) {
            emlrtDynamicBoundsCheckR2012b(workingset_indexLB_data[idx], 1,
              solution_xstar_size[0], &vd_emlrtBCI, sp);
          }

          if ((workingset_indexLB_data[idx] < 1) || (workingset_indexLB_data[idx]
               > workingset_lb_size[0])) {
            emlrtDynamicBoundsCheckR2012b(workingset_indexLB_data[idx], 1,
              workingset_lb_size[0], &vd_emlrtBCI, sp);
          }

          ratio = (-solution_xstar_data[workingset_indexLB_data[idx] - 1] -
                   workingset_lb_data[workingset_indexLB_data[idx] - 1]) -
            phaseOneCorrectionX;
          alphaTemp = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio)
            / alphaTemp;
          if (alphaTemp < *alpha) {
            *alpha = alphaTemp;
            *constrType = 4;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }

    if ((workingset_sizes[3] < 1) || (workingset_sizes[3] >
         workingset_indexLB_size[0])) {
      emlrtDynamicBoundsCheckR2012b(workingset_sizes[3], 1,
        workingset_indexLB_size[0], &vd_emlrtBCI, sp);
    }

    i = workingset_indexLB_data[workingset_sizes[3] - 1];
    if ((i < 1) || (i > solution_searchDir_size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, solution_searchDir_size[0],
        &vd_emlrtBCI, sp);
    }

    alphaTemp = -solution_searchDir_data[i - 1];
    if (alphaTemp > denomTol) {
      st.site = &tg_emlrtRSI;
      i1 = workingset_isActiveIdx[3] + workingset_sizes[3];
      if ((i1 - 1 < 1) || (i1 - 1 > workingset_isActiveConstr_size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1 - 1, 1, workingset_isActiveConstr_size
          [0], &hc_emlrtBCI, &st);
      }

      if (!workingset_isActiveConstr_data[i1 - 2]) {
        if (i > solution_xstar_size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, solution_xstar_size[0],
            &vd_emlrtBCI, sp);
        }

        if (i > workingset_lb_size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, workingset_lb_size[0],
            &vd_emlrtBCI, sp);
        }

        ratio = -solution_xstar_data[i - 1] - workingset_lb_data[i - 1];
        if (i > solution_searchDir_size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, solution_searchDir_size[0],
            &vd_emlrtBCI, sp);
        }

        alphaTemp = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) /
          alphaTemp;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = workingset_sizes[3];
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    if ((workingset_nVar < 1) || (workingset_nVar > solution_xstar_size[0])) {
      emlrtDynamicBoundsCheckR2012b(workingset_nVar, 1, solution_xstar_size[0],
        &vd_emlrtBCI, sp);
    }

    phaseOneCorrectionX = (real_T)isPhaseOne *
      solution_xstar_data[workingset_nVar - 1];
    if (workingset_nVar > solution_searchDir_size[0]) {
      emlrtDynamicBoundsCheckR2012b(workingset_nVar, 1, solution_searchDir_size
        [0], &vd_emlrtBCI, sp);
    }

    phaseOneCorrectionP = (real_T)isPhaseOne *
      solution_searchDir_data[workingset_nVar - 1];
    st.site = &tg_emlrtRSI;
    if ((1 <= workingset_sizes[4]) && (workingset_sizes[4] > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < totalUB; idx++) {
      alphaTemp = solution_searchDir_data[workingset_indexUB_data[idx] - 1] -
        phaseOneCorrectionP;
      if (alphaTemp > denomTol) {
        st.site = &tg_emlrtRSI;
        i = workingset_isActiveIdx[4] + idx;
        if ((i < 1) || (i > workingset_isActiveConstr_size[0])) {
          emlrtDynamicBoundsCheckR2012b(i, 1, workingset_isActiveConstr_size[0],
            &hc_emlrtBCI, &st);
        }

        if (!workingset_isActiveConstr_data[i - 1]) {
          ratio = (solution_xstar_data[workingset_indexUB_data[idx] - 1] -
                   workingset_ub_data[workingset_indexUB_data[idx] - 1]) -
            phaseOneCorrectionX;
          alphaTemp = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio)
            / alphaTemp;
          if (alphaTemp < *alpha) {
            *alpha = alphaTemp;
            *constrType = 5;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }
  }

  if (!isPhaseOne) {
    if ((*newBlocking) && (*alpha > 1.0)) {
      *newBlocking = false;
    }

    *alpha = muDoubleScalarMin(*alpha, 1.0);
  }
}

/* End of code generation (feasibleratiotest.c) */
