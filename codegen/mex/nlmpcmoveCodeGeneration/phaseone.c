/*
 * phaseone.c
 *
 * Code generation for function 'phaseone'
 *
 */

/* Include files */
#include "phaseone.h"
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "iterate.h"
#include "moveConstraint_.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"

/* Variable Definitions */
static emlrtRSInfo wf_emlrtRSI = { 1,  /* lineNo */
  "phaseone",                          /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\phaseone.p"/* pathName */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "phaseone",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\phaseone.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void phaseone(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
              real_T H[58081], const real_T f_data[], const int32_T f_size[1],
              g_struct_T *solution, d_struct_T *memspace, j_struct_T *workingset,
              l_struct_T *qrmanager, m_struct_T *cholmanager, i_struct_T
              *objective, c_struct_T *options, const c_struct_T *runTimeOptions)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T PHASEONE;
  int32_T PROBTYPE_ORIG;
  int32_T TYPE_tmp;
  int32_T i;
  int32_T i1;
  int32_T mEqFixed;
  int32_T nVar;
  int32_T nVarP1;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  PROBTYPE_ORIG = workingset->probType;
  nVar = workingset->nVar;
  nVarP1 = workingset->nVar + 1;
  i = solution->xstar.size[0];
  i1 = workingset->nVar + 1;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &gd_emlrtBCI, sp);
  }

  solution->xstar.data[i1 - 1] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    PHASEONE = 1;
  } else {
    PHASEONE = 4;
  }

  st.site = &wf_emlrtRSI;
  removeAllIneqConstr(&st, workingset);
  st.site = &wf_emlrtRSI;
  setProblemType(&st, workingset, PHASEONE);
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = nVarP1;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-6;
  options->StepTolerance = 1.4901161193847657E-10;
  st.site = &wf_emlrtRSI;
  solution->fstar = computeFval(&st, objective, memspace->workspace_double.data,
    H, f_data, f_size, solution->xstar.data, solution->xstar.size);
  solution->state = 5;
  st.site = &wf_emlrtRSI;
  iterate(SD, &st, H, f_data, f_size, solution, memspace, workingset, qrmanager,
          cholmanager, objective, options->StepTolerance,
          options->ObjectiveLimit, runTimeOptions->MaxIterations);
  st.site = &wf_emlrtRSI;
  i = workingset->isActiveConstr.size[0];
  i1 = workingset->isActiveIdx[3] + workingset->sizes[3];
  if ((i1 - 1 < 1) || (i1 - 1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1 - 1, 1, i, &hc_emlrtBCI, &st);
  }

  if (workingset->isActiveConstr.data[i1 - 2]) {
    st.site = &wf_emlrtRSI;
    if ((workingset->sizes[0] + 181 <= workingset->nActiveConstr) &&
        (workingset->nActiveConstr > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    PHASEONE = workingset->sizes[0] + 181;
    exitg1 = false;
    while ((!exitg1) && (PHASEONE <= workingset->nActiveConstr)) {
      i = workingset->Wid.size[0];
      if ((PHASEONE < 1) || (PHASEONE > i)) {
        emlrtDynamicBoundsCheckR2012b(PHASEONE, 1, i, &gd_emlrtBCI, sp);
      }

      if (workingset->Wid.data[PHASEONE - 1] == 4) {
        i = workingset->Wlocalidx.size[0];
        if (PHASEONE > i) {
          emlrtDynamicBoundsCheckR2012b(PHASEONE, 1, i, &gd_emlrtBCI, sp);
        }

        i = workingset->Wlocalidx.data[PHASEONE - 1];
        if (i == workingset->sizes[3]) {
          st.site = &wf_emlrtRSI;
          i1 = workingset->Wid.size[0];
          if (PHASEONE > i1) {
            emlrtDynamicBoundsCheckR2012b(PHASEONE, 1, i1, &oc_emlrtBCI, &st);
          }

          i1 = workingset->Wlocalidx.size[0];
          if (PHASEONE > i1) {
            emlrtDynamicBoundsCheckR2012b(PHASEONE, 1, i1, &oc_emlrtBCI, &st);
          }

          i1 = workingset->isActiveConstr.size[0];
          i = (workingset->isActiveIdx[3] + i) - 1;
          if ((i < 1) || (i > i1)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i1, &oc_emlrtBCI, &st);
          }

          workingset->isActiveConstr.data[i - 1] = false;
          b_st.site = &af_emlrtRSI;
          moveConstraint_(&b_st, workingset, workingset->nActiveConstr, PHASEONE);
          workingset->nActiveConstr--;
          workingset->nWConstr[3]--;
          exitg1 = true;
        } else {
          PHASEONE++;
        }
      } else {
        PHASEONE++;
      }
    }
  }

  PHASEONE = workingset->nActiveConstr;
  mEqFixed = workingset->sizes[0] + 180;
  while ((PHASEONE > mEqFixed) && (PHASEONE > nVar)) {
    st.site = &wf_emlrtRSI;
    i = workingset->Wid.size[0];
    if ((PHASEONE < 1) || (PHASEONE > i)) {
      emlrtDynamicBoundsCheckR2012b(PHASEONE, 1, i, &oc_emlrtBCI, &st);
    }

    TYPE_tmp = workingset->Wid.data[PHASEONE - 1];
    i = workingset->Wlocalidx.size[0];
    if (PHASEONE > i) {
      emlrtDynamicBoundsCheckR2012b(PHASEONE, 1, i, &oc_emlrtBCI, &st);
    }

    if ((TYPE_tmp < 1) || (TYPE_tmp > 6)) {
      emlrtDynamicBoundsCheckR2012b(workingset->Wid.data[PHASEONE - 1], 1, 6,
        &pc_emlrtBCI, &st);
    }

    i = workingset->isActiveConstr.size[0];
    i1 = (workingset->isActiveIdx[TYPE_tmp - 1] + workingset->
          Wlocalidx.data[PHASEONE - 1]) - 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &oc_emlrtBCI, &st);
    }

    workingset->isActiveConstr.data[i1 - 1] = false;
    b_st.site = &af_emlrtRSI;
    moveConstraint_(&b_st, workingset, workingset->nActiveConstr, PHASEONE);
    workingset->nActiveConstr--;
    if (TYPE_tmp > 5) {
      emlrtDynamicBoundsCheckR2012b(6, 1, 5, &qc_emlrtBCI, &st);
    }

    workingset->nWConstr[TYPE_tmp - 1]--;
    PHASEONE--;
  }

  i = solution->xstar.size[0];
  if ((nVarP1 < 1) || (nVarP1 > i)) {
    emlrtDynamicBoundsCheckR2012b(nVarP1, 1, i, &gd_emlrtBCI, sp);
  }

  solution->maxConstr = solution->xstar.data[nVarP1 - 1];
  st.site = &wf_emlrtRSI;
  setProblemType(&st, workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = rtMinusInf;
  options->StepTolerance = 1.0E-6;
}

/* End of code generation (phaseone.c) */
