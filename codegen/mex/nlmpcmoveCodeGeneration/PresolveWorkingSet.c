/*
 * PresolveWorkingSet.c
 *
 * Code generation for function 'PresolveWorkingSet'
 *
 */

/* Include files */
#include "PresolveWorkingSet.h"
#include "RemoveDependentEq_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQRE.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "moveConstraint_.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo te_emlrtRSI = { 1,  /* lineNo */
  "PresolveWorkingSet",                /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\PresolveWorkingSet.p"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 1,  /* lineNo */
  "RemoveDependentIneq_",              /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\RemoveDependentIneq_.p"/* pathName */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "RemoveDependentIneq_",              /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\RemoveDependentIneq_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void PresolveWorkingSet(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack
  *sp, g_struct_T *solution, d_struct_T *memspace, j_struct_T *workingset,
  l_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T tol;
  int32_T i;
  int32_T idx;
  int32_T nActiveConstr;
  int32_T nDepIneq;
  int32_T nFixedConstr_tmp_tmp;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T okWorkingSet;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  solution->state = 82;
  st.site = &te_emlrtRSI;
  i = RemoveDependentEq_(&st, memspace, workingset, qrmanager);
  if (i != -1) {
    st.site = &te_emlrtRSI;
    nActiveConstr = workingset->nActiveConstr;
    nFixedConstr_tmp_tmp = workingset->nWConstr[1] + workingset->nWConstr[0];
    if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
        workingset->nWConstr[4] > 0) {
      tol = 100.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
      b_st.site = &cf_emlrtRSI;
      if ((1 <= nFixedConstr_tmp_tmp) && (nFixedConstr_tmp_tmp > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = 0; idx < nFixedConstr_tmp_tmp; idx++) {
        i = qrmanager->jpvt.size[0];
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &nc_emlrtBCI, &st);
        }

        qrmanager->jpvt.data[idx] = 1;
      }

      nDepIneq = nFixedConstr_tmp_tmp + 1;
      b_st.site = &cf_emlrtRSI;
      if ((nFixedConstr_tmp_tmp + 1 <= workingset->nActiveConstr) &&
          (workingset->nActiveConstr > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = nDepIneq; idx <= nActiveConstr; idx++) {
        i = qrmanager->jpvt.size[0];
        if ((idx < 1) || (idx > i)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &nc_emlrtBCI, &st);
        }

        qrmanager->jpvt.data[idx - 1] = 0;
      }

      b_st.site = &cf_emlrtRSI;
      factorQRE(&b_st, qrmanager, workingset->ATwset.data,
                workingset->ATwset.size, workingset->nVar,
                workingset->nActiveConstr);
      nDepIneq = 0;
      for (idx = workingset->nActiveConstr; idx > workingset->nVar; idx--) {
        nDepIneq++;
        i = qrmanager->jpvt.size[0];
        if ((idx < 1) || (idx > i)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &nc_emlrtBCI, &st);
        }

        i = memspace->workspace_int.size[0];
        if ((nDepIneq < 1) || (nDepIneq > i)) {
          emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, i, &nc_emlrtBCI, &st);
        }

        memspace->workspace_int.data[nDepIneq - 1] = qrmanager->jpvt.data[idx -
          1];
      }

      if (idx <= workingset->nVar) {
        exitg1 = false;
        while ((!exitg1) && (idx > nFixedConstr_tmp_tmp)) {
          i = qrmanager->QR.size[0];
          if ((idx < 1) || (idx > i)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i, &nc_emlrtBCI, &st);
          }

          i = qrmanager->QR.size[1];
          if (idx > i) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i, &nc_emlrtBCI, &st);
          }

          if (muDoubleScalarAbs(qrmanager->QR.data[(idx + qrmanager->QR.size[0] *
                (idx - 1)) - 1]) < tol) {
            nDepIneq++;
            i = memspace->workspace_int.size[0];
            if ((nDepIneq < 1) || (nDepIneq > i)) {
              emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, i, &nc_emlrtBCI, &st);
            }

            memspace->workspace_int.data[nDepIneq - 1] = qrmanager->
              jpvt.data[idx - 1];
            idx--;
          } else {
            exitg1 = true;
          }
        }
      }

      b_st.site = &cf_emlrtRSI;
      countsort(&b_st, memspace->workspace_int.data,
                memspace->workspace_int.size, nDepIneq,
                memspace->workspace_sort.data, memspace->workspace_sort.size,
                nFixedConstr_tmp_tmp + 1, workingset->nActiveConstr);
      for (idx = nDepIneq; idx >= 1; idx--) {
        b_st.site = &cf_emlrtRSI;
        i = memspace->workspace_int.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &nc_emlrtBCI, &b_st);
        }

        i = workingset->Wid.size[0];
        nFixedConstr_tmp_tmp = memspace->workspace_int.data[idx - 1];
        if ((nFixedConstr_tmp_tmp < 1) || (nFixedConstr_tmp_tmp > i)) {
          emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx - 1], 1,
            i, &oc_emlrtBCI, &b_st);
        }

        nActiveConstr = workingset->Wid.data[nFixedConstr_tmp_tmp - 1];
        i = workingset->Wlocalidx.size[0];
        if (nFixedConstr_tmp_tmp > i) {
          emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx - 1], 1,
            i, &oc_emlrtBCI, &b_st);
        }

        if ((nActiveConstr < 1) || (nActiveConstr > 6)) {
          emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 6, &pc_emlrtBCI, &b_st);
        }

        i = workingset->isActiveConstr.size[0];
        nFixedConstr_tmp_tmp = (workingset->isActiveIdx[nActiveConstr - 1] +
          workingset->Wlocalidx.data[nFixedConstr_tmp_tmp - 1]) - 1;
        if ((nFixedConstr_tmp_tmp < 1) || (nFixedConstr_tmp_tmp > i)) {
          emlrtDynamicBoundsCheckR2012b(nFixedConstr_tmp_tmp, 1, i, &oc_emlrtBCI,
            &b_st);
        }

        workingset->isActiveConstr.data[nFixedConstr_tmp_tmp - 1] = false;
        c_st.site = &af_emlrtRSI;
        moveConstraint_(&c_st, workingset, workingset->nActiveConstr,
                        memspace->workspace_int.data[idx - 1]);
        workingset->nActiveConstr--;
        if (nActiveConstr > 5) {
          emlrtDynamicBoundsCheckR2012b(6, 1, 5, &qc_emlrtBCI, &b_st);
        }

        workingset->nWConstr[nActiveConstr - 1]--;
      }
    }

    st.site = &te_emlrtRSI;
    okWorkingSet = feasibleX0ForWorkingSet(SD, &st,
      memspace->workspace_double.data, memspace->workspace_double.size,
      solution->xstar.data, solution->xstar.size, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      st.site = &te_emlrtRSI;
      nActiveConstr = workingset->nActiveConstr;
      i = workingset->nWConstr[1] + workingset->nWConstr[0];
      if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
          workingset->nWConstr[4] > 0) {
        tol = 1000.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
        b_st.site = &cf_emlrtRSI;
        if ((1 <= i) && (i > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx = 0; idx < i; idx++) {
          nFixedConstr_tmp_tmp = qrmanager->jpvt.size[0];
          if ((idx + 1 < 1) || (idx + 1 > nFixedConstr_tmp_tmp)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, nFixedConstr_tmp_tmp,
              &nc_emlrtBCI, &st);
          }

          qrmanager->jpvt.data[idx] = 1;
        }

        nDepIneq = i + 1;
        b_st.site = &cf_emlrtRSI;
        if ((i + 1 <= workingset->nActiveConstr) && (workingset->nActiveConstr >
             2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx = nDepIneq; idx <= nActiveConstr; idx++) {
          nFixedConstr_tmp_tmp = qrmanager->jpvt.size[0];
          if ((idx < 1) || (idx > nFixedConstr_tmp_tmp)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, nFixedConstr_tmp_tmp,
              &nc_emlrtBCI, &st);
          }

          qrmanager->jpvt.data[idx - 1] = 0;
        }

        b_st.site = &cf_emlrtRSI;
        factorQRE(&b_st, qrmanager, workingset->ATwset.data,
                  workingset->ATwset.size, workingset->nVar,
                  workingset->nActiveConstr);
        nDepIneq = 0;
        for (idx = workingset->nActiveConstr; idx > workingset->nVar; idx--) {
          nDepIneq++;
          nFixedConstr_tmp_tmp = qrmanager->jpvt.size[0];
          if ((idx < 1) || (idx > nFixedConstr_tmp_tmp)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, nFixedConstr_tmp_tmp,
              &nc_emlrtBCI, &st);
          }

          nFixedConstr_tmp_tmp = memspace->workspace_int.size[0];
          if ((nDepIneq < 1) || (nDepIneq > nFixedConstr_tmp_tmp)) {
            emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, nFixedConstr_tmp_tmp,
              &nc_emlrtBCI, &st);
          }

          memspace->workspace_int.data[nDepIneq - 1] = qrmanager->jpvt.data[idx
            - 1];
        }

        if (idx <= workingset->nVar) {
          exitg1 = false;
          while ((!exitg1) && (idx > i)) {
            nFixedConstr_tmp_tmp = qrmanager->QR.size[0];
            if ((idx < 1) || (idx > nFixedConstr_tmp_tmp)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, nFixedConstr_tmp_tmp,
                &nc_emlrtBCI, &st);
            }

            nFixedConstr_tmp_tmp = qrmanager->QR.size[1];
            if (idx > nFixedConstr_tmp_tmp) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, nFixedConstr_tmp_tmp,
                &nc_emlrtBCI, &st);
            }

            if (muDoubleScalarAbs(qrmanager->QR.data[(idx + qrmanager->QR.size[0]
                  * (idx - 1)) - 1]) < tol) {
              nDepIneq++;
              nFixedConstr_tmp_tmp = memspace->workspace_int.size[0];
              if ((nDepIneq < 1) || (nDepIneq > nFixedConstr_tmp_tmp)) {
                emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, nFixedConstr_tmp_tmp,
                  &nc_emlrtBCI, &st);
              }

              memspace->workspace_int.data[nDepIneq - 1] = qrmanager->
                jpvt.data[idx - 1];
              idx--;
            } else {
              exitg1 = true;
            }
          }
        }

        b_st.site = &cf_emlrtRSI;
        countsort(&b_st, memspace->workspace_int.data,
                  memspace->workspace_int.size, nDepIneq,
                  memspace->workspace_sort.data, memspace->workspace_sort.size,
                  i + 1, workingset->nActiveConstr);
        for (idx = nDepIneq; idx >= 1; idx--) {
          b_st.site = &cf_emlrtRSI;
          i = memspace->workspace_int.size[0];
          if (idx > i) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i, &nc_emlrtBCI, &b_st);
          }

          i = workingset->Wid.size[0];
          nFixedConstr_tmp_tmp = memspace->workspace_int.data[idx - 1];
          if ((nFixedConstr_tmp_tmp < 1) || (nFixedConstr_tmp_tmp > i)) {
            emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx - 1],
              1, i, &oc_emlrtBCI, &b_st);
          }

          nActiveConstr = workingset->Wid.data[nFixedConstr_tmp_tmp - 1];
          i = workingset->Wlocalidx.size[0];
          if (nFixedConstr_tmp_tmp > i) {
            emlrtDynamicBoundsCheckR2012b(memspace->workspace_int.data[idx - 1],
              1, i, &oc_emlrtBCI, &b_st);
          }

          if ((nActiveConstr < 1) || (nActiveConstr > 6)) {
            emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 6, &pc_emlrtBCI,
              &b_st);
          }

          i = workingset->isActiveConstr.size[0];
          nFixedConstr_tmp_tmp = (workingset->isActiveIdx[nActiveConstr - 1] +
            workingset->Wlocalidx.data[nFixedConstr_tmp_tmp - 1]) - 1;
          if ((nFixedConstr_tmp_tmp < 1) || (nFixedConstr_tmp_tmp > i)) {
            emlrtDynamicBoundsCheckR2012b(nFixedConstr_tmp_tmp, 1, i,
              &oc_emlrtBCI, &b_st);
          }

          workingset->isActiveConstr.data[nFixedConstr_tmp_tmp - 1] = false;
          c_st.site = &af_emlrtRSI;
          moveConstraint_(&c_st, workingset, workingset->nActiveConstr,
                          memspace->workspace_int.data[idx - 1]);
          workingset->nActiveConstr--;
          if (nActiveConstr > 5) {
            emlrtDynamicBoundsCheckR2012b(6, 1, 5, &qc_emlrtBCI, &b_st);
          }

          workingset->nWConstr[nActiveConstr - 1]--;
        }
      }

      st.site = &te_emlrtRSI;
      okWorkingSet = feasibleX0ForWorkingSet(SD, &st,
        memspace->workspace_double.data, memspace->workspace_double.size,
        solution->xstar.data, solution->xstar.size, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 && (workingset->nWConstr[0] + workingset->nWConstr[1] ==
                   workingset->nVar)) {
      st.site = &te_emlrtRSI;
      tol = b_maxConstraintViolation(&st, workingset, solution->xstar.data,
        solution->xstar.size);
      if (tol > 1.0E-6) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    st.site = &te_emlrtRSI;
    removeAllIneqConstr(&st, workingset);
  }
}

/* End of code generation (PresolveWorkingSet.c) */
