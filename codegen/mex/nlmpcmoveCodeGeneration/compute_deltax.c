/*
 * compute_deltax.c
 *
 * Code generation for function 'compute_deltax'
 *
 */

/* Include files */
#include "compute_deltax.h"
#include "eml_int_forloop_overflow_check.h"
#include "factor.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xpotrf.h"
#include "xscal.h"

/* Variable Definitions */
static emlrtRSInfo kg_emlrtRSI = { 1,  /* lineNo */
  "compute_deltax",                    /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_deltax.p"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 1,  /* lineNo */
  "computeProjectedHessian",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\computeProjectedHessian.p"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 1,  /* lineNo */
  "computeProjectedHessian_regularized",/* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\computeProjectedHessian_regularized.p"/* pathName */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compute_deltax",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_deltax.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeProjectedHessian_regularized",/* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\computeProjectedHessian_regularized.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void compute_deltax(const emlrtStack *sp, const real_T H[58081], g_struct_T
                    *solution, d_struct_T *memspace, const l_struct_T *qrmanager,
                    m_struct_T *cholmanager, const i_struct_T *objective)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T idx_col;
  int32_T idx_row;
  int32_T ldw;
  int32_T mNull_tmp;
  int32_T nVar;
  int32_T nVars;
  int32_T nullStartIdx_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nVar = qrmanager->mrows;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    st.site = &kg_emlrtRSI;
    if ((1 <= qrmanager->mrows) && (qrmanager->mrows > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (nVars = 0; nVars < nVar; nVars++) {
      i = solution->searchDir.size[0];
      if ((nVars + 1 < 1) || (nVars + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(nVars + 1, 1, i, &rd_emlrtBCI, sp);
      }

      solution->searchDir.data[nVars] = 0.0;
    }
  } else {
    st.site = &kg_emlrtRSI;
    if ((1 <= qrmanager->mrows) && (qrmanager->mrows > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (nVars = 0; nVars < nVar; nVars++) {
      i = objective->grad.size[0];
      if ((nVars + 1 < 1) || (nVars + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(nVars + 1, 1, i, &rd_emlrtBCI, sp);
      }

      i = solution->searchDir.size[0];
      if ((nVars + 1 < 1) || (nVars + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(nVars + 1, 1, i, &rd_emlrtBCI, sp);
      }

      solution->searchDir.data[nVars] = -objective->grad.data[nVars];
    }

    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
       case 5:
        break;

       case 3:
        st.site = &kg_emlrtRSI;
        factor(&st, cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &kg_emlrtRSI;
          solve(cholmanager, solution->searchDir.data);
        }
        break;

       case 4:
        st.site = &kg_emlrtRSI;
        factor(&st, cholmanager, H, objective->nvar, objective->nvar);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &kg_emlrtRSI;
          solve(cholmanager, solution->searchDir.data);
          st.site = &kg_emlrtRSI;
          xscal(qrmanager->mrows - objective->nvar, 1.0 / objective->beta,
                solution->searchDir.data, objective->nvar + 1);
        }
        break;
      }
    } else {
      nullStartIdx_tmp = qrmanager->ldq * qrmanager->ncols + 1;
      switch (objective->objtype) {
       case 5:
        st.site = &kg_emlrtRSI;
        if (mNull_tmp > 2147483646) {
          b_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (nVars = 0; nVars < mNull_tmp; nVars++) {
          i = qrmanager->Q.size[0];
          if ((nVar < 1) || (nVar > i)) {
            emlrtDynamicBoundsCheckR2012b(nVar, 1, i, &rd_emlrtBCI, sp);
          }

          i = qrmanager->Q.size[1];
          i1 = (qrmanager->ncols + nVars) + 1;
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &rd_emlrtBCI, sp);
          }

          i = memspace->workspace_double.size[0] *
            memspace->workspace_double.size[1];
          if (nVars + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(nVars + 1, 1, i, &rd_emlrtBCI, sp);
          }

          memspace->workspace_double.data[nVars] = -qrmanager->Q.data[(nVar +
            qrmanager->Q.size[0] * (i1 - 1)) - 1];
        }

        st.site = &kg_emlrtRSI;
        j_xgemv(qrmanager->mrows, mNull_tmp, qrmanager->Q.data, nullStartIdx_tmp,
                qrmanager->ldq, memspace->workspace_double.data,
                solution->searchDir.data);
        break;

       default:
        switch (objective->objtype) {
         case 3:
          st.site = &kg_emlrtRSI;
          ldw = memspace->workspace_double.size[0];
          b_st.site = &pg_emlrtRSI;
          c_xgemm(qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                  qrmanager->mrows, qrmanager->Q.data, nullStartIdx_tmp,
                  qrmanager->ldq, memspace->workspace_double.data,
                  memspace->workspace_double.size[0]);
          b_st.site = &pg_emlrtRSI;
          d_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q.data,
                  nullStartIdx_tmp, qrmanager->ldq,
                  memspace->workspace_double.data, ldw, cholmanager->FMat.data,
                  cholmanager->ldm);
          break;

         default:
          nVar = objective->nvar + 1;
          st.site = &kg_emlrtRSI;
          nVars = qrmanager->mrows;
          ldw = memspace->workspace_double.size[0];
          b_st.site = &qg_emlrtRSI;
          c_xgemm(objective->nvar, mNull_tmp, objective->nvar, H,
                  objective->nvar, qrmanager->Q.data, nullStartIdx_tmp,
                  qrmanager->ldq, memspace->workspace_double.data,
                  memspace->workspace_double.size[0]);
          b_st.site = &qg_emlrtRSI;
          if (mNull_tmp > 2147483646) {
            c_st.site = &db_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx_col = 0; idx_col < mNull_tmp; idx_col++) {
            b_st.site = &qg_emlrtRSI;
            if ((nVar <= nVars) && (nVars > 2147483646)) {
              c_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (idx_row = nVar; idx_row <= nVars; idx_row++) {
              i = qrmanager->Q.size[0];
              if ((idx_row < 1) || (idx_row > i)) {
                emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &sd_emlrtBCI, &st);
              }

              i = qrmanager->Q.size[1];
              i1 = (idx_col + qrmanager->ncols) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sd_emlrtBCI, &st);
              }

              i = memspace->workspace_double.size[0];
              if (idx_row > i) {
                emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &sd_emlrtBCI, &st);
              }

              i = memspace->workspace_double.size[1];
              if (idx_col + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &sd_emlrtBCI,
                  &st);
              }

              memspace->workspace_double.data[(idx_row +
                memspace->workspace_double.size[0] * idx_col) - 1] =
                objective->beta * qrmanager->Q.data[(idx_row + qrmanager->
                Q.size[0] * (i1 - 1)) - 1];
            }
          }

          b_st.site = &qg_emlrtRSI;
          d_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q.data,
                  nullStartIdx_tmp, qrmanager->ldq,
                  memspace->workspace_double.data, ldw, cholmanager->FMat.data,
                  cholmanager->ldm);
          break;
        }

        st.site = &kg_emlrtRSI;
        cholmanager->ndims = mNull_tmp;
        b_st.site = &lg_emlrtRSI;
        cholmanager->info = xpotrf(&b_st, mNull_tmp, cholmanager->FMat.data,
          cholmanager->ldm);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &kg_emlrtRSI;
          k_xgemv(qrmanager->mrows, mNull_tmp, qrmanager->Q.data,
                  nullStartIdx_tmp, qrmanager->ldq, objective->grad.data,
                  memspace->workspace_double.data);
          st.site = &kg_emlrtRSI;
          b_solve(cholmanager, memspace->workspace_double.data);
          st.site = &kg_emlrtRSI;
          j_xgemv(qrmanager->mrows, mNull_tmp, qrmanager->Q.data,
                  nullStartIdx_tmp, qrmanager->ldq,
                  memspace->workspace_double.data, solution->searchDir.data);
        }
        break;
      }
    }
  }
}

/* End of code generation (compute_deltax.c) */
