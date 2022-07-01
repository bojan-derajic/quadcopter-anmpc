/*
 * checkStoppingAndUpdateFval.c
 *
 * Code generation for function 'checkStoppingAndUpdateFval'
 *
 */

/* Include files */
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wg_emlrtRSI = { 1,  /* lineNo */
  "checkStoppingAndUpdateFval",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+stopping\\checkStoppingAndUpdateFval.p"/* pathName */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "checkStoppingAndUpdateFval",        /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+stopping\\checkStoppingAndUpdateFval.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void checkStoppingAndUpdateFval(c_nlmpcmoveCodeGenerationStackD *SD, const
  emlrtStack *sp, int32_T *activeSetChangeID, const real_T f_data[], const
  int32_T f_size[1], g_struct_T *solution, d_struct_T *memspace, const
  i_struct_T *objective, j_struct_T *workingset, l_struct_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
  updateFval)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T tmp_data[2323];
  real_T constrViolation_new;
  int32_T loop_ub;
  int32_T nVar;
  int32_T tmp_size_idx_0;
  boolean_T nonDegenerateWset;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  solution->iterations++;
  nVar = objective->nvar;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    st.site = &wg_emlrtRSI;
    solution->maxConstr = b_maxConstraintViolation(&st, workingset,
      solution->xstar.data, solution->xstar.size);
    if (solution->maxConstr > 1.0E-6) {
      tmp_size_idx_0 = solution->searchDir.size[0];
      loop_ub = solution->searchDir.size[0];
      if (0 <= loop_ub - 1) {
        memcpy(&tmp_data[0], &solution->searchDir.data[0], loop_ub * sizeof
               (real_T));
      }

      st.site = &wg_emlrtRSI;
      c_xcopy(objective->nvar, solution->xstar.data, tmp_data);
      solution->searchDir.size[0] = tmp_size_idx_0;
      if (0 <= tmp_size_idx_0 - 1) {
        memcpy(&solution->searchDir.data[0], &tmp_data[0], tmp_size_idx_0 *
               sizeof(real_T));
      }

      st.site = &wg_emlrtRSI;
      nonDegenerateWset = feasibleX0ForWorkingSet(SD, &st,
        memspace->workspace_double.data, memspace->workspace_double.size,
        solution->searchDir.data, solution->searchDir.size, workingset,
        qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      st.site = &wg_emlrtRSI;
      constrViolation_new = b_maxConstraintViolation(&st, workingset,
        solution->searchDir.data, solution->searchDir.size);
      if (constrViolation_new < solution->maxConstr) {
        st.site = &wg_emlrtRSI;
        if ((1 <= objective->nvar) && (objective->nvar > 2147483646)) {
          b_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (loop_ub = 0; loop_ub < nVar; loop_ub++) {
          tmp_size_idx_0 = solution->searchDir.size[0];
          if ((loop_ub + 1 < 1) || (loop_ub + 1 > tmp_size_idx_0)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, tmp_size_idx_0,
              &wd_emlrtBCI, sp);
          }

          tmp_size_idx_0 = solution->xstar.size[0];
          if ((loop_ub + 1 < 1) || (loop_ub + 1 > tmp_size_idx_0)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, tmp_size_idx_0,
              &wd_emlrtBCI, sp);
          }

          solution->xstar.data[loop_ub] = solution->searchDir.data[loop_ub];
        }

        solution->maxConstr = constrViolation_new;
      }
    }
  }

  if ((options_ObjectiveLimit > rtMinusInf) && updateFval) {
    st.site = &wg_emlrtRSI;
    solution->fstar = computeFval_ReuseHx(&st, objective,
      memspace->workspace_double.data, f_data, f_size, solution->xstar.data,
      solution->xstar.size);
    if ((solution->fstar < options_ObjectiveLimit) && ((solution->state != 0) ||
         (objective->objtype != 5))) {
      solution->state = 2;
    }
  }
}

/* End of code generation (checkStoppingAndUpdateFval.c) */
