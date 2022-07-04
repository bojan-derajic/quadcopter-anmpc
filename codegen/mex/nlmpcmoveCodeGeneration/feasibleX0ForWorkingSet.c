/*
 * feasibleX0ForWorkingSet.c
 *
 * Code generation for function 'feasibleX0ForWorkingSet'
 *
 */

/* Include files */
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "maxConstraintViolation.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xcopy.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xgeqrf.h"
#include "xtrsm.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo df_emlrtRSI = { 1,  /* lineNo */
  "feasibleX0ForWorkingSet",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\feasibleX0ForWorkingSet.p"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 1,  /* lineNo */
  "computeTallQ",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+QRManager\\computeTallQ.p"/* pathName */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "feasibleX0ForWorkingSet",           /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\feasibleX0ForWorkingSet.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
boolean_T feasibleX0ForWorkingSet(c_nlmpcmoveCodeGenerationStackD *SD, const
  emlrtStack *sp, real_T workspace_data[], const int32_T workspace_size[2],
  real_T xCurrent_data[], int32_T xCurrent_size[1], j_struct_T *workingset,
  l_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T tmp_data[1743];
  real_T constrViolation_minnormX;
  real_T v;
  int32_T exitg1;
  int32_T i;
  int32_T idx;
  int32_T idx_row;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  int32_T mWConstr;
  int32_T nVar;
  boolean_T nonDegenerateWset;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  mWConstr = workingset->nActiveConstr;
  nVar = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    st.site = &df_emlrtRSI;
    if ((1 <= workingset->nActiveConstr) && (workingset->nActiveConstr >
         2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < mWConstr; idx++) {
      i = workingset->bwset.size[0];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &bd_emlrtBCI, sp);
      }

      i = workspace_size[0];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &bd_emlrtBCI, sp);
      }

      constrViolation_minnormX = workingset->bwset.data[idx];
      workspace_data[idx] = constrViolation_minnormX;
      i = workingset->bwset.size[0];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &bd_emlrtBCI, sp);
      }

      i = workspace_size[0];
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &bd_emlrtBCI, sp);
      }

      workspace_data[idx + workspace_size[0]] = constrViolation_minnormX;
    }

    st.site = &df_emlrtRSI;
    b_xgemv(workingset->nVar, workingset->nActiveConstr, workingset->ATwset.data,
            workingset->ATwset.size[0], xCurrent_data, workspace_data);
    if (workingset->nActiveConstr >= workingset->nVar) {
      st.site = &df_emlrtRSI;
      if ((1 <= workingset->nVar) && (workingset->nVar > 2147483646)) {
        b_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (mLB = 0; mLB < nVar; mLB++) {
        st.site = &df_emlrtRSI;
        if ((1 <= mWConstr) && (mWConstr > 2147483646)) {
          b_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (idx_row = 0; idx_row < mWConstr; idx_row++) {
          i = workingset->ATwset.size[0];
          if ((mLB + 1 < 1) || (mLB + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(mLB + 1, 1, i, &bd_emlrtBCI, sp);
          }

          i = workingset->ATwset.size[1];
          if ((idx_row + 1 < 1) || (idx_row + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, i, &bd_emlrtBCI, sp);
          }

          i = qrmanager->QR.size[0];
          if ((idx_row + 1 < 1) || (idx_row + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, i, &bd_emlrtBCI, sp);
          }

          qrmanager->QR.data[idx_row + qrmanager->QR.size[0] * mLB] =
            workingset->ATwset.data[mLB + workingset->ATwset.size[0] * idx_row];
        }
      }

      st.site = &df_emlrtRSI;
      mWConstr = workingset->nVar;
      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      b_st.site = &ef_emlrtRSI;
      if ((1 <= workingset->nVar) && (workingset->nVar > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < mWConstr; idx++) {
        qrmanager->jpvt.data[idx] = idx + 1;
      }

      qrmanager->minRowCol = muIntScalarMin_sint32(workingset->nActiveConstr,
        workingset->nVar);
      b_st.site = &ef_emlrtRSI;
      xgeqrf(&b_st, qrmanager->QR.data, qrmanager->QR.size,
             workingset->nActiveConstr, workingset->nVar, qrmanager->tau.data,
             qrmanager->tau.size);
      st.site = &df_emlrtRSI;
      b_st.site = &ce_emlrtRSI;
      computeQ_(&b_st, qrmanager, workingset->nActiveConstr);
      mLB = workspace_size[0] * workspace_size[1] - 1;
      if (0 <= mLB) {
        memcpy(&SD->u1.f2.workspace_data[0], &workspace_data[0], (mLB + 1) *
               sizeof(real_T));
      }

      st.site = &df_emlrtRSI;
      xgemm(workingset->nVar, workingset->nActiveConstr, qrmanager->Q.data,
            qrmanager->ldq, SD->u1.f2.workspace_data, workspace_size[0],
            workspace_data, workspace_size[0]);
      st.site = &df_emlrtRSI;
      xtrsm(workingset->nVar, qrmanager->QR.data, qrmanager->ldq, workspace_data,
            workspace_size[0]);
    } else {
      st.site = &df_emlrtRSI;
      factorQR(&st, qrmanager, workingset->ATwset.data, workingset->ATwset.size,
               workingset->nVar, workingset->nActiveConstr);
      st.site = &df_emlrtRSI;
      b_st.site = &pf_emlrtRSI;
      computeQ_(&b_st, qrmanager, qrmanager->minRowCol);
      mWConstr = workspace_size[0];
      st.site = &df_emlrtRSI;
      b_xtrsm(workingset->nActiveConstr, qrmanager->QR.data, qrmanager->ldq,
              workspace_data, workspace_size[0]);
      mLB = workspace_size[0] * workspace_size[1] - 1;
      if (0 <= mLB) {
        memcpy(&SD->u1.f2.workspace_data[0], &workspace_data[0], (mLB + 1) *
               sizeof(real_T));
      }

      st.site = &df_emlrtRSI;
      b_xgemm(workingset->nVar, workingset->nActiveConstr, qrmanager->Q.data,
              qrmanager->ldq, SD->u1.f2.workspace_data, mWConstr, workspace_data,
              mWConstr);
    }

    st.site = &df_emlrtRSI;
    if ((1 <= workingset->nVar) && (workingset->nVar > 2147483646)) {
      b_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    idx = 0;
    do {
      exitg1 = 0;
      if (idx <= nVar - 1) {
        constrViolation_minnormX = workspace_data[idx];
        if (muDoubleScalarIsInf(constrViolation_minnormX) || muDoubleScalarIsNaN
            (constrViolation_minnormX)) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          constrViolation_minnormX = workspace_data[idx + workspace_size[0]];
          if (muDoubleScalarIsInf(constrViolation_minnormX) ||
              muDoubleScalarIsNaN(constrViolation_minnormX)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            idx++;
          }
        }
      } else {
        st.site = &df_emlrtRSI;
        xaxpy(nVar, xCurrent_data, workspace_data);
        st.site = &df_emlrtRSI;
        constrViolation_minnormX = maxConstraintViolation(&st, workingset,
          workspace_data, workspace_size);
        st.site = &df_emlrtRSI;
        idx_row = workspace_size[0];
        mLB = workingset->sizes[3];
        mUB = workingset->sizes[4];
        mFixed = workingset->sizes[0];
        switch (workingset->probType) {
         case 2:
          b_st.site = &sf_emlrtRSI;
          v = 0.0;
          mWConstr = workingset->sizes[2];
          if ((workingset->Aineq.size[0] != 0) && (workingset->Aineq.size[1] !=
               0)) {
            c_st.site = &tf_emlrtRSI;
            c_xcopy(workingset->sizes[2], workingset->bineq.data,
                    workingset->maxConstrWorkspace.data);
            c_st.site = &tf_emlrtRSI;
            f_xgemv(241, workingset->sizes[2], workingset->Aineq.data,
                    workingset->ldA, workspace_data, workspace_size[0] + 1,
                    workingset->maxConstrWorkspace.data);
            c_st.site = &tf_emlrtRSI;
            if ((1 <= workingset->sizes[2]) && (workingset->sizes[2] >
                 2147483646)) {
              d_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            for (idx = 0; idx < mWConstr; idx++) {
              workingset->maxConstrWorkspace.data[idx] -= workspace_data
                [(idx_row + idx) + 241];
              v = muDoubleScalarMax(v, workingset->maxConstrWorkspace.data[idx]);
            }
          }

          c_st.site = &tf_emlrtRSI;
          memcpy(&workingset->maxConstrWorkspace.data[0], &workingset->beq[0],
                 180U * sizeof(real_T));
          c_st.site = &tf_emlrtRSI;
          g_xgemv(241, workingset->Aeq.data, workingset->ldA, workspace_data,
                  workspace_size[0] + 1, workingset->maxConstrWorkspace.data);
          c_st.site = &tf_emlrtRSI;
          for (idx = 0; idx < 180; idx++) {
            workingset->maxConstrWorkspace.data[idx] =
              (workingset->maxConstrWorkspace.data[idx] - workspace_data
               [((idx_row + mWConstr) + idx) + 241]) + workspace_data[((idx_row
              + workingset->sizes[2]) + idx) + 421];
            v = muDoubleScalarMax(v, muDoubleScalarAbs
                                  (workingset->maxConstrWorkspace.data[idx]));
          }
          break;

         default:
          b_st.site = &sf_emlrtRSI;
          v = 0.0;
          mWConstr = workingset->sizes[2];
          if ((workingset->Aineq.size[0] != 0) && (workingset->Aineq.size[1] !=
               0)) {
            c_st.site = &uf_emlrtRSI;
            c_xcopy(workingset->sizes[2], workingset->bineq.data,
                    workingset->maxConstrWorkspace.data);
            c_st.site = &uf_emlrtRSI;
            f_xgemv(workingset->nVar, workingset->sizes[2],
                    workingset->Aineq.data, workingset->ldA, workspace_data,
                    workspace_size[0] + 1, workingset->maxConstrWorkspace.data);
            c_st.site = &uf_emlrtRSI;
            if ((1 <= workingset->sizes[2]) && (workingset->sizes[2] >
                 2147483646)) {
              d_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            for (idx = 0; idx < mWConstr; idx++) {
              v = muDoubleScalarMax(v, workingset->maxConstrWorkspace.data[idx]);
            }
          }

          c_st.site = &uf_emlrtRSI;
          memcpy(&workingset->maxConstrWorkspace.data[0], &workingset->beq[0],
                 180U * sizeof(real_T));
          c_st.site = &uf_emlrtRSI;
          g_xgemv(workingset->nVar, workingset->Aeq.data, workingset->ldA,
                  workspace_data, workspace_size[0] + 1,
                  workingset->maxConstrWorkspace.data);
          c_st.site = &uf_emlrtRSI;
          for (idx = 0; idx < 180; idx++) {
            v = muDoubleScalarMax(v, muDoubleScalarAbs
                                  (workingset->maxConstrWorkspace.data[idx]));
          }
          break;
        }

        if (workingset->sizes[3] > 0) {
          b_st.site = &sf_emlrtRSI;
          if ((1 <= workingset->sizes[3]) && (workingset->sizes[3] > 2147483646))
          {
            c_st.site = &db_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx = 0; idx < mLB; idx++) {
            i = workingset->indexLB.size[0];
            if ((idx + 1 < 1) || (idx + 1 > i)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ad_emlrtBCI, &st);
            }

            i = workspace_size[0] * workspace_size[1];
            mWConstr = idx_row + workingset->indexLB.data[idx];
            if ((mWConstr < 1) || (mWConstr > i)) {
              emlrtDynamicBoundsCheckR2012b(mWConstr, 1, i, &ad_emlrtBCI, &st);
            }

            i = workingset->lb.size[0];
            if ((workingset->indexLB.data[idx] < 1) || (workingset->
                 indexLB.data[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(workingset->indexLB.data[idx], 1, i,
                &ad_emlrtBCI, &st);
            }

            v = muDoubleScalarMax(v, -workspace_data[mWConstr - 1] -
                                  workingset->lb.data[workingset->
                                  indexLB.data[idx] - 1]);
          }
        }

        if (workingset->sizes[4] > 0) {
          b_st.site = &sf_emlrtRSI;
          if ((1 <= workingset->sizes[4]) && (workingset->sizes[4] > 2147483646))
          {
            c_st.site = &db_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx = 0; idx < mUB; idx++) {
            mLB = workingset->indexUB.data[idx];
            v = muDoubleScalarMax(v, workspace_data[(idx_row + mLB) - 1] -
                                  workingset->ub.data[mLB - 1]);
          }
        }

        if (workingset->sizes[0] > 0) {
          b_st.site = &sf_emlrtRSI;
          if ((1 <= workingset->sizes[0]) && (workingset->sizes[0] > 2147483646))
          {
            c_st.site = &db_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx = 0; idx < mFixed; idx++) {
            v = muDoubleScalarMax(v, muDoubleScalarAbs(workspace_data[(idx_row +
              workingset->indexFixed.data[idx]) - 1] - workingset->
              ub.data[workingset->indexFixed.data[idx] - 1]));
          }
        }

        if ((constrViolation_minnormX <= 2.2204460492503131E-16) ||
            (constrViolation_minnormX < v)) {
          mWConstr = xCurrent_size[0];
          mLB = xCurrent_size[0];
          if (0 <= mLB - 1) {
            memcpy(&tmp_data[0], &xCurrent_data[0], mLB * sizeof(real_T));
          }

          st.site = &df_emlrtRSI;
          c_xcopy(nVar, workspace_data, tmp_data);
          xCurrent_size[0] = mWConstr;
          if (0 <= mWConstr - 1) {
            memcpy(&xCurrent_data[0], &tmp_data[0], mWConstr * sizeof(real_T));
          }
        } else {
          st.site = &df_emlrtRSI;
          g_xcopy(nVar, workspace_data, workspace_size[0] + 1, xCurrent_data);
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

/* End of code generation (feasibleX0ForWorkingSet.c) */
