/*
 * iterate.c
 *
 * Code generation for function 'iterate'
 *
 */

/* Include files */
#include "iterate.h"
#include "addBoundToActiveSetMatrix_.h"
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "feasibleratiotest.h"
#include "moveConstraint_.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xaxpy.h"
#include "xcopy.h"
#include "xnrm2.h"
#include "xrot.h"
#include "blas.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bg_emlrtRSI = { 1,  /* lineNo */
  "iterate",                           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\iterate.p"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 1,  /* lineNo */
  "deleteColMoveEnd",                  /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+QRManager\\deleteColMoveEnd.p"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 1,  /* lineNo */
  "find_neg_lambda",                   /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_neg_lambda.p"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 1,  /* lineNo */
  "checkUnboundedOrIllPosed",          /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+stopping\\checkUnboundedOrIllPosed.p"/* pathName */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "iterate",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\iterate.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "deleteColMoveEnd",                  /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+QRManager\\deleteColMoveEnd.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "find_neg_lambda",                   /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_neg_lambda.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void iterate(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
             real_T H[58081], const real_T f_data[], const int32_T f_size[1],
             g_struct_T *solution, d_struct_T *memspace, j_struct_T *workingset,
             l_struct_T *qrmanager, m_struct_T *cholmanager, i_struct_T
             *objective, real_T options_StepTolerance, real_T
             options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T tmp_data[1743];
  real_T c;
  real_T d;
  real_T normDelta;
  real_T s;
  int32_T QRk0;
  int32_T Qk0;
  int32_T TYPE;
  int32_T a;
  int32_T activeSetChangeID;
  int32_T b_i;
  int32_T endIdx;
  int32_T exitg1;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T nVar;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  nVar = workingset->nVar;
  globalActiveConstrIdx = 0;
  st.site = &bg_emlrtRSI;
  computeGrad_StoreHx(&st, objective, H, f_data, solution->xstar.data,
                      solution->xstar.size);
  st.site = &bg_emlrtRSI;
  solution->fstar = computeFval_ReuseHx(&st, objective,
    memspace->workspace_double.data, f_data, f_size, solution->xstar.data,
    solution->xstar.size);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  st.site = &bg_emlrtRSI;
  e_xcopy(&st, workingset->mConstrMax, solution->lambda.data);
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
         case 1:
          st.site = &bg_emlrtRSI;
          squareQ_appendCol(&st, qrmanager, workingset->ATwset.data,
                            workingset->ldA * (workingset->nActiveConstr - 1) +
                            1);
          break;

         case -1:
          st.site = &bg_emlrtRSI;
          i = globalActiveConstrIdx;
          if (qrmanager->usedPivoting) {
            i = 1;
            exitg2 = false;
            while ((!exitg2) && (i <= qrmanager->ncols)) {
              b_i = qrmanager->jpvt.size[0];
              if ((i < 1) || (i > b_i)) {
                emlrtDynamicBoundsCheckR2012b(i, 1, b_i, &ld_emlrtBCI, &st);
              }

              if (qrmanager->jpvt.data[i - 1] != globalActiveConstrIdx) {
                i++;
              } else {
                exitg2 = true;
              }
            }
          }

          if (i >= qrmanager->ncols) {
            qrmanager->ncols--;
          } else {
            b_i = qrmanager->jpvt.size[0];
            if ((qrmanager->ncols < 1) || (qrmanager->ncols > b_i)) {
              emlrtDynamicBoundsCheckR2012b(qrmanager->ncols, 1, b_i,
                &ld_emlrtBCI, &st);
            }

            b_i = qrmanager->jpvt.size[0];
            if ((i < 1) || (i > b_i)) {
              emlrtDynamicBoundsCheckR2012b(i, 1, b_i, &ld_emlrtBCI, &st);
            }

            qrmanager->jpvt.data[i - 1] = qrmanager->jpvt.data[qrmanager->ncols
              - 1];
            QRk0 = qrmanager->minRowCol;
            b_st.site = &jg_emlrtRSI;
            if ((1 <= qrmanager->minRowCol) && (qrmanager->minRowCol >
                 2147483646)) {
              c_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (k = 0; k < QRk0; k++) {
              b_i = qrmanager->QR.size[0];
              if ((k + 1 < 1) || (k + 1 > b_i)) {
                emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_i, &ld_emlrtBCI, &st);
              }

              b_i = qrmanager->QR.size[1];
              if ((qrmanager->ncols < 1) || (qrmanager->ncols > b_i)) {
                emlrtDynamicBoundsCheckR2012b(qrmanager->ncols, 1, b_i,
                  &ld_emlrtBCI, &st);
              }

              b_i = qrmanager->QR.size[0];
              if ((k + 1 < 1) || (k + 1 > b_i)) {
                emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_i, &ld_emlrtBCI, &st);
              }

              b_i = qrmanager->QR.size[1];
              if (i > b_i) {
                emlrtDynamicBoundsCheckR2012b(i, 1, b_i, &ld_emlrtBCI, &st);
              }

              qrmanager->QR.data[k + qrmanager->QR.size[0] * (i - 1)] =
                qrmanager->QR.data[k + qrmanager->QR.size[0] * (qrmanager->ncols
                - 1)];
            }

            qrmanager->ncols--;
            qrmanager->minRowCol = muIntScalarMin_sint32(qrmanager->mrows,
              qrmanager->ncols);
            if (i < qrmanager->mrows) {
              QRk0 = qrmanager->mrows - 1;
              endIdx = muIntScalarMin_sint32(QRk0, qrmanager->ncols);
              for (k = endIdx; k >= i; k--) {
                b_st.site = &jg_emlrtRSI;
                b_i = qrmanager->QR.size[0];
                if (k > b_i) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, b_i, &ld_emlrtBCI, &b_st);
                }

                b_i = qrmanager->QR.size[1];
                if (i > b_i) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, b_i, &ld_emlrtBCI, &b_st);
                }

                b_i = k + qrmanager->QR.size[0] * (i - 1);
                d = qrmanager->QR.data[b_i - 1];
                i1 = qrmanager->QR.size[0];
                if ((k + 1 < 1) || (k + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(k + 1, 1, i1, &ld_emlrtBCI,
                    &b_st);
                }

                i1 = qrmanager->QR.size[1];
                if (i > i1) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i1, &ld_emlrtBCI, &b_st);
                }

                normDelta = qrmanager->QR.data[b_i];
                c = 0.0;
                s = 0.0;
                drotg(&d, &normDelta, &c, &s);
                i1 = qrmanager->QR.size[0];
                if (k > i1) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, i1, &ld_emlrtBCI, &st);
                }

                i1 = qrmanager->QR.size[1];
                if (i > i1) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i1, &ld_emlrtBCI, &st);
                }

                qrmanager->QR.data[b_i - 1] = d;
                b_i = qrmanager->QR.size[0];
                if ((k + 1 < 1) || (k + 1 > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_i, &ld_emlrtBCI, &st);
                }

                b_i = qrmanager->QR.size[1];
                if (i > b_i) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, b_i, &ld_emlrtBCI, &st);
                }

                qrmanager->QR.data[k + qrmanager->QR.size[0] * (i - 1)] =
                  normDelta;
                b_i = qrmanager->QR.size[0];
                if ((k + 1 < 1) || (k + 1 > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_i, &ld_emlrtBCI, &st);
                }

                b_i = qrmanager->QR.size[1];
                if (k > b_i) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, b_i, &ld_emlrtBCI, &st);
                }

                qrmanager->QR.data[k + qrmanager->QR.size[0] * (k - 1)] = 0.0;
                QRk0 = k + qrmanager->ldq * i;
                b_st.site = &jg_emlrtRSI;
                b_xrot(qrmanager->ncols - i, qrmanager->QR.data, QRk0,
                       qrmanager->ldq, QRk0 + 1, qrmanager->ldq, c, s);
                Qk0 = qrmanager->ldq * (k - 1) + 1;
                b_st.site = &jg_emlrtRSI;
                xrot(qrmanager->mrows, qrmanager->Q.data, Qk0, qrmanager->ldq +
                     Qk0, c, s);
              }

              a = i + 1;
              b_st.site = &jg_emlrtRSI;
              if ((i + 1 <= endIdx) && (endIdx > 2147483646)) {
                c_st.site = &db_emlrtRSI;
                check_forloop_overflow_error(&c_st);
              }

              for (k = a; k <= endIdx; k++) {
                b_st.site = &jg_emlrtRSI;
                b_i = qrmanager->QR.size[0];
                if (k > b_i) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, b_i, &ld_emlrtBCI, &b_st);
                }

                b_i = qrmanager->QR.size[1];
                if (k > b_i) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, b_i, &ld_emlrtBCI, &b_st);
                }

                b_i = k + qrmanager->QR.size[0] * (k - 1);
                d = qrmanager->QR.data[b_i - 1];
                i1 = qrmanager->QR.size[0];
                if (k + 1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(k + 1, 1, i1, &ld_emlrtBCI,
                    &b_st);
                }

                i1 = qrmanager->QR.size[1];
                if (k > i1) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, i1, &ld_emlrtBCI, &b_st);
                }

                normDelta = qrmanager->QR.data[b_i];
                c = 0.0;
                s = 0.0;
                drotg(&d, &normDelta, &c, &s);
                i1 = qrmanager->QR.size[0];
                if (k > i1) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, i1, &ld_emlrtBCI, &st);
                }

                i1 = qrmanager->QR.size[1];
                if (k > i1) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, i1, &ld_emlrtBCI, &st);
                }

                qrmanager->QR.data[b_i - 1] = d;
                b_i = qrmanager->QR.size[0];
                if (k + 1 > b_i) {
                  emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_i, &ld_emlrtBCI, &st);
                }

                b_i = qrmanager->QR.size[1];
                if (k > b_i) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, b_i, &ld_emlrtBCI, &st);
                }

                qrmanager->QR.data[k + qrmanager->QR.size[0] * (k - 1)] =
                  normDelta;
                QRk0 = k * (qrmanager->ldq + 1);
                b_st.site = &jg_emlrtRSI;
                b_xrot(qrmanager->ncols - k, qrmanager->QR.data, QRk0,
                       qrmanager->ldq, QRk0 + 1, qrmanager->ldq, c, s);
                Qk0 = qrmanager->ldq * (k - 1) + 1;
                b_st.site = &jg_emlrtRSI;
                xrot(qrmanager->mrows, qrmanager->Q.data, Qk0, qrmanager->ldq +
                     Qk0, c, s);
              }
            }
          }
          break;

         default:
          st.site = &bg_emlrtRSI;
          factorQR(&st, qrmanager, workingset->ATwset.data,
                   workingset->ATwset.size, nVar, workingset->nActiveConstr);
          st.site = &bg_emlrtRSI;
          b_st.site = &ce_emlrtRSI;
          computeQ_(&b_st, qrmanager, qrmanager->mrows);
          break;
        }

        st.site = &bg_emlrtRSI;
        compute_deltax(&st, H, solution, memspace, qrmanager, cholmanager,
                       objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = xnrm2(nVar, solution->searchDir.data);
          if ((normDelta < options_StepTolerance) || (workingset->nActiveConstr >=
               nVar)) {
            guard1 = true;
          } else {
            st.site = &bg_emlrtRSI;
            feasibleratiotest(&st, solution->xstar.data, solution->xstar.size,
                              solution->searchDir.data, solution->searchDir.size,
                              memspace->workspace_double.data,
                              memspace->workspace_double.size, workingset->nVar,
                              workingset->ldA, workingset->Aineq.data,
                              workingset->bineq.data, workingset->lb.data,
                              workingset->lb.size, workingset->ub.data,
                              workingset->indexLB.data, workingset->indexLB.size,
                              workingset->indexUB.data, workingset->sizes,
                              workingset->isActiveIdx,
                              workingset->isActiveConstr.data,
                              workingset->isActiveConstr.size,
                              workingset->nWConstr, TYPE == 5, &normDelta,
                              &updateFval, &b_i, &QRk0);
            if (updateFval) {
              switch (b_i) {
               case 3:
                st.site = &bg_emlrtRSI;
                b_st.site = &ug_emlrtRSI;
                workingset->nWConstr[2]++;
                b_i = workingset->isActiveConstr.size[0];
                i1 = (workingset->isActiveIdx[2] + QRk0) - 1;
                if ((i1 < 1) || (i1 > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &ec_emlrtBCI, &b_st);
                }

                workingset->isActiveConstr.data[i1 - 1] = true;
                workingset->nActiveConstr++;
                b_i = workingset->Wid.size[0];
                if ((workingset->nActiveConstr < 1) ||
                    (workingset->nActiveConstr > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1,
                    b_i, &ec_emlrtBCI, &b_st);
                }

                workingset->Wid.data[workingset->nActiveConstr - 1] = 3;
                b_i = workingset->Wlocalidx.size[0];
                if ((workingset->nActiveConstr < 1) ||
                    (workingset->nActiveConstr > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1,
                    b_i, &ec_emlrtBCI, &b_st);
                }

                workingset->Wlocalidx.data[workingset->nActiveConstr - 1] = QRk0;
                b_st.site = &ug_emlrtRSI;
                d_xcopy(workingset->nVar, workingset->Aineq.data,
                        workingset->ldA * (QRk0 - 1) + 1,
                        workingset->ATwset.data, workingset->ldA *
                        (workingset->nActiveConstr - 1) + 1);
                b_i = workingset->bineq.size[0] * workingset->bineq.size[1];
                if ((QRk0 < 1) || (QRk0 > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(QRk0, 1, b_i, &md_emlrtBCI, &st);
                }

                b_i = workingset->bwset.size[0];
                if ((workingset->nActiveConstr < 1) ||
                    (workingset->nActiveConstr > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1,
                    b_i, &md_emlrtBCI, &st);
                }

                workingset->bwset.data[workingset->nActiveConstr - 1] =
                  workingset->bineq.data[QRk0 - 1];
                break;

               case 4:
                st.site = &bg_emlrtRSI;
                b_st.site = &me_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, 4, QRk0);
                break;

               default:
                st.site = &bg_emlrtRSI;
                b_st.site = &oe_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, 5, QRk0);
                break;
              }

              activeSetChangeID = 1;
            } else {
              st.site = &bg_emlrtRSI;
              if (objective->objtype == 5) {
                b_st.site = &vg_emlrtRSI;
                if (xnrm2(objective->nvar, solution->searchDir.data) > 100.0 *
                    (real_T)objective->nvar * 1.4901161193847656E-8) {
                  solution->state = 3;
                } else {
                  solution->state = 4;
                }
              }

              subProblemChanged = false;
              if (workingset->nActiveConstr == 0) {
                solution->state = 1;
              }
            }

            st.site = &bg_emlrtRSI;
            b_xaxpy(nVar, normDelta, solution->searchDir.data,
                    solution->xstar.data);
            st.site = &bg_emlrtRSI;
            computeGrad_StoreHx(&st, objective, H, f_data, solution->xstar.data,
                                solution->xstar.size);
            updateFval = true;
            st.site = &bg_emlrtRSI;
            checkStoppingAndUpdateFval(SD, &st, &activeSetChangeID, f_data,
              f_size, solution, memspace, objective, workingset, qrmanager,
              options_ObjectiveLimit, runTimeOptions_MaxIterations, updateFval);
          }
        }
      } else {
        QRk0 = solution->searchDir.size[0];
        Qk0 = solution->searchDir.size[0];
        if (0 <= Qk0 - 1) {
          memcpy(&tmp_data[0], &solution->searchDir.data[0], Qk0 * sizeof(real_T));
        }

        st.site = &bg_emlrtRSI;
        e_xcopy(&st, nVar, tmp_data);
        solution->searchDir.size[0] = QRk0;
        if (0 <= QRk0 - 1) {
          memcpy(&solution->searchDir.data[0], &tmp_data[0], QRk0 * sizeof
                 (real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        st.site = &bg_emlrtRSI;
        compute_lambda(&st, memspace->workspace_double.data,
                       memspace->workspace_double.size, solution, objective,
                       qrmanager);
        if (solution->state != -7) {
          st.site = &bg_emlrtRSI;
          endIdx = 0;
          normDelta = 0.0;
          a = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
          QRk0 = workingset->nActiveConstr;
          b_st.site = &sg_emlrtRSI;
          if ((a <= workingset->nActiveConstr) && (workingset->nActiveConstr >
               2147483646)) {
            c_st.site = &db_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (Qk0 = a; Qk0 <= QRk0; Qk0++) {
            b_i = solution->lambda.size[0];
            if ((Qk0 < 1) || (Qk0 > b_i)) {
              emlrtDynamicBoundsCheckR2012b(Qk0, 1, b_i, &nd_emlrtBCI, &st);
            }

            d = solution->lambda.data[Qk0 - 1];
            if (d < normDelta) {
              b_i = solution->lambda.size[0];
              if (Qk0 > b_i) {
                emlrtDynamicBoundsCheckR2012b(Qk0, 1, b_i, &nd_emlrtBCI, &st);
              }

              normDelta = d;
              endIdx = Qk0;
            }
          }

          if (endIdx == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = endIdx;
            subProblemChanged = true;
            b_i = workingset->Wid.size[0];
            if (endIdx > b_i) {
              emlrtDynamicBoundsCheckR2012b(endIdx, 1, b_i, &kd_emlrtBCI, sp);
            }

            b_i = workingset->Wlocalidx.size[0];
            if (endIdx > b_i) {
              emlrtDynamicBoundsCheckR2012b(endIdx, 1, b_i, &kd_emlrtBCI, sp);
            }

            st.site = &bg_emlrtRSI;
            b_i = workingset->Wid.size[0];
            if (endIdx > b_i) {
              emlrtDynamicBoundsCheckR2012b(endIdx, 1, b_i, &oc_emlrtBCI, &st);
            }

            QRk0 = workingset->Wid.data[endIdx - 1];
            b_i = workingset->Wlocalidx.size[0];
            if (endIdx > b_i) {
              emlrtDynamicBoundsCheckR2012b(endIdx, 1, b_i, &oc_emlrtBCI, &st);
            }

            if ((QRk0 < 1) || (QRk0 > 6)) {
              emlrtDynamicBoundsCheckR2012b(workingset->Wid.data[endIdx - 1], 1,
                6, &pc_emlrtBCI, &st);
            }

            b_i = workingset->isActiveConstr.size[0];
            i1 = (workingset->isActiveIdx[QRk0 - 1] + workingset->
                  Wlocalidx.data[endIdx - 1]) - 1;
            if ((i1 < 1) || (i1 > b_i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &oc_emlrtBCI, &st);
            }

            workingset->isActiveConstr.data[i1 - 1] = false;
            b_st.site = &af_emlrtRSI;
            moveConstraint_(&b_st, workingset, workingset->nActiveConstr, endIdx);
            workingset->nActiveConstr--;
            if (QRk0 > 5) {
              emlrtDynamicBoundsCheckR2012b(6, 1, 5, &qc_emlrtBCI, &st);
            }

            workingset->nWConstr[QRk0 - 1]--;
            b_i = solution->lambda.size[0];
            if (endIdx > b_i) {
              emlrtDynamicBoundsCheckR2012b(endIdx, 1, b_i, &kd_emlrtBCI, sp);
            }

            solution->lambda.data[endIdx - 1] = 0.0;
          }
        } else {
          endIdx = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          b_i = workingset->Wid.size[0];
          if ((workingset->nActiveConstr < 1) || (workingset->nActiveConstr >
               b_i)) {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, b_i,
              &kd_emlrtBCI, sp);
          }

          b_i = workingset->Wlocalidx.size[0];
          if ((workingset->nActiveConstr < 1) || (workingset->nActiveConstr >
               b_i)) {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, b_i,
              &kd_emlrtBCI, sp);
          }

          st.site = &bg_emlrtRSI;
          b_i = workingset->Wid.size[0];
          if ((workingset->nActiveConstr < 1) || (workingset->nActiveConstr >
               b_i)) {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, b_i,
              &oc_emlrtBCI, &st);
          }

          QRk0 = workingset->nActiveConstr - 1;
          Qk0 = workingset->Wid.data[QRk0];
          b_i = workingset->Wlocalidx.size[0];
          if ((workingset->nActiveConstr < 1) || (workingset->nActiveConstr >
               b_i)) {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, b_i,
              &oc_emlrtBCI, &st);
          }

          if ((Qk0 < 1) || (Qk0 > 6)) {
            emlrtDynamicBoundsCheckR2012b(workingset->Wid.data
              [workingset->nActiveConstr - 1], 1, 6, &pc_emlrtBCI, &st);
          }

          b_i = workingset->isActiveConstr.size[0];
          i1 = (workingset->isActiveIdx[Qk0 - 1] + workingset->
                Wlocalidx.data[QRk0]) - 1;
          if ((i1 < 1) || (i1 > b_i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &oc_emlrtBCI, &st);
          }

          workingset->isActiveConstr.data[i1 - 1] = false;
          b_st.site = &af_emlrtRSI;
          moveConstraint_(&b_st, workingset, workingset->nActiveConstr,
                          workingset->nActiveConstr);
          workingset->nActiveConstr--;
          if (Qk0 > 5) {
            emlrtDynamicBoundsCheckR2012b(6, 1, 5, &qc_emlrtBCI, &st);
          }

          workingset->nWConstr[Qk0 - 1]--;
          b_i = solution->lambda.size[0];
          if ((endIdx < 1) || (endIdx > b_i)) {
            emlrtDynamicBoundsCheckR2012b(endIdx, 1, b_i, &kd_emlrtBCI, sp);
          }

          solution->lambda.data[endIdx - 1] = 0.0;
        }

        updateFval = false;
        st.site = &bg_emlrtRSI;
        checkStoppingAndUpdateFval(SD, &st, &activeSetChangeID, f_data, f_size,
          solution, memspace, objective, workingset, qrmanager,
          options_ObjectiveLimit, runTimeOptions_MaxIterations, updateFval);
      }
    } else {
      if (!updateFval) {
        st.site = &bg_emlrtRSI;
        solution->fstar = computeFval_ReuseHx(&st, objective,
          memspace->workspace_double.data, f_data, f_size, solution->xstar.data,
          solution->xstar.size);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (iterate.c) */
