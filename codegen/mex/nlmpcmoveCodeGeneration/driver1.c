/*
 * driver1.c
 *
 * Code generation for function 'driver1'
 *
 */

/* Include files */
#include "driver1.h"
#include "PresolveWorkingSet.h"
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pe_emlrtRSI = { 1,  /* lineNo */
  "snap_bounds",                       /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_bounds.p"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 1,  /* lineNo */
  "driver",                            /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\driver.p"/* pathName */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "snap_bounds",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_bounds.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void b_driver(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
              real_T H[58081], const real_T f_data[], const int32_T f_size[1],
              g_struct_T *solution, d_struct_T *memspace, j_struct_T *workingset,
              l_struct_T *qrmanager, m_struct_T *cholmanager, i_struct_T
              *objective, c_struct_T *options, c_struct_T *runTimeOptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T tmp_data[1743];
  real_T maxConstr_new;
  int32_T b;
  int32_T i;
  int32_T idx;
  int32_T loop_ub;
  int32_T nVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  solution->iterations = 0;
  runTimeOptions->RemainFeasible = true;
  nVar = workingset->nVar;
  st.site = &se_emlrtRSI;
  b = workingset->sizes[0];
  b_st.site = &pe_emlrtRSI;
  if ((1 <= workingset->sizes[0]) && (workingset->sizes[0] > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < b; idx++) {
    solution->xstar.data[workingset->indexFixed.data[idx] - 1] =
      workingset->ub.data[workingset->indexFixed.data[idx] - 1];
  }

  b = workingset->sizes[3];
  b_st.site = &pe_emlrtRSI;
  if ((1 <= workingset->sizes[3]) && (workingset->sizes[3] > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < b; idx++) {
    loop_ub = workingset->isActiveConstr.size[0];
    i = workingset->isActiveIdx[3] + idx;
    if ((i < 1) || (i > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &mc_emlrtBCI, &st);
    }

    if (workingset->isActiveConstr.data[i - 1]) {
      loop_ub = workingset->indexLB.size[0];
      if ((idx + 1 < 1) || (idx + 1 > loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, loop_ub, &mc_emlrtBCI, &st);
      }

      loop_ub = workingset->lb.size[0];
      if ((workingset->indexLB.data[idx] < 1) || (workingset->indexLB.data[idx] >
           loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(workingset->indexLB.data[idx], 1, loop_ub,
          &mc_emlrtBCI, &st);
      }

      loop_ub = solution->xstar.size[0];
      if ((workingset->indexLB.data[idx] < 1) || (workingset->indexLB.data[idx] >
           loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(workingset->indexLB.data[idx], 1, loop_ub,
          &mc_emlrtBCI, &st);
      }

      solution->xstar.data[workingset->indexLB.data[idx] - 1] =
        -workingset->lb.data[workingset->indexLB.data[idx] - 1];
    }
  }

  b = workingset->sizes[4];
  b_st.site = &pe_emlrtRSI;
  if ((1 <= workingset->sizes[4]) && (workingset->sizes[4] > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < b; idx++) {
    loop_ub = workingset->isActiveConstr.size[0];
    i = workingset->isActiveIdx[4] + idx;
    if ((i < 1) || (i > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &mc_emlrtBCI, &st);
    }

    if (workingset->isActiveConstr.data[i - 1]) {
      solution->xstar.data[workingset->indexUB.data[idx] - 1] =
        workingset->ub.data[workingset->indexUB.data[idx] - 1];
    }
  }

  st.site = &se_emlrtRSI;
  PresolveWorkingSet(SD, &st, solution, memspace, workingset, qrmanager);
  if (solution->state >= 0) {
    solution->iterations = 0;
    st.site = &se_emlrtRSI;
    solution->maxConstr = b_maxConstraintViolation(&st, workingset,
      solution->xstar.data, solution->xstar.size);
    if (solution->maxConstr > 1.0E-6) {
      st.site = &se_emlrtRSI;
      phaseone(SD, &st, H, f_data, f_size, solution, memspace, workingset,
               qrmanager, cholmanager, objective, options, runTimeOptions);
      if (solution->state != 0) {
        st.site = &se_emlrtRSI;
        solution->maxConstr = b_maxConstraintViolation(&st, workingset,
          solution->xstar.data, solution->xstar.size);
        if (solution->maxConstr > 1.0E-6) {
          st.site = &se_emlrtRSI;
          e_xcopy(&st, workingset->mConstrMax, solution->lambda.data);
          st.site = &se_emlrtRSI;
          solution->fstar = computeFval(&st, objective,
            memspace->workspace_double.data, H, f_data, f_size,
            solution->xstar.data, solution->xstar.size);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            b = solution->searchDir.size[0];
            loop_ub = solution->searchDir.size[0];
            if (0 <= loop_ub - 1) {
              memcpy(&tmp_data[0], &solution->searchDir.data[0], loop_ub *
                     sizeof(real_T));
            }

            st.site = &se_emlrtRSI;
            c_xcopy(nVar, solution->xstar.data, tmp_data);
            solution->searchDir.size[0] = b;
            if (0 <= b - 1) {
              memcpy(&solution->searchDir.data[0], &tmp_data[0], b * sizeof
                     (real_T));
            }

            st.site = &se_emlrtRSI;
            PresolveWorkingSet(SD, &st, solution, memspace, workingset,
                               qrmanager);
            st.site = &se_emlrtRSI;
            maxConstr_new = b_maxConstraintViolation(&st, workingset,
              solution->xstar.data, solution->xstar.size);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              b = solution->xstar.size[0];
              loop_ub = solution->xstar.size[0];
              if (0 <= loop_ub - 1) {
                memcpy(&tmp_data[0], &solution->xstar.data[0], loop_ub * sizeof
                       (real_T));
              }

              st.site = &se_emlrtRSI;
              c_xcopy(nVar, solution->searchDir.data, tmp_data);
              solution->xstar.size[0] = b;
              if (0 <= b - 1) {
                memcpy(&solution->xstar.data[0], &tmp_data[0], b * sizeof(real_T));
              }
            }
          }

          st.site = &se_emlrtRSI;
          iterate(SD, &st, H, f_data, f_size, solution, memspace, workingset,
                  qrmanager, cholmanager, objective, options->StepTolerance,
                  options->ObjectiveLimit, runTimeOptions->MaxIterations);
        }
      }
    } else {
      st.site = &se_emlrtRSI;
      iterate(SD, &st, H, f_data, f_size, solution, memspace, workingset,
              qrmanager, cholmanager, objective, options->StepTolerance,
              options->ObjectiveLimit, runTimeOptions->MaxIterations);
    }
  }
}

/* End of code generation (driver1.c) */
