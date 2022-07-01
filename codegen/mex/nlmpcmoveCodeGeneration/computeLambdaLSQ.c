/*
 * computeLambdaLSQ.c
 *
 * Code generation for function 'computeLambdaLSQ'
 *
 */

/* Include files */
#include "computeLambdaLSQ.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQRE.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xtrsv.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo od_emlrtRSI = { 1,  /* lineNo */
  "computeLambdaLSQ",                  /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeLambdaLSQ.p"/* pathName */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeLambdaLSQ",                  /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeLambdaLSQ.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void computeLambdaLSQ(const emlrtStack *sp, int32_T nVar, int32_T mConstr,
                      l_struct_T *QRManager, const real_T ATwset_data[], const
                      int32_T ATwset_size[2], const real_T grad_data[], real_T
                      lambdaLSQ_data[], const int32_T lambdaLSQ_size[1], real_T
                      workspace_data[])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T tol;
  int32_T fullRank_R;
  int32_T i;
  int32_T iQR_diag;
  int32_T rankR;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &od_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  e_xcopy(&st, mConstr, lambdaLSQ_data);
  st.site = &od_emlrtRSI;
  factorQRE(&st, QRManager, ATwset_data, ATwset_size, nVar, mConstr);
  st.site = &od_emlrtRSI;
  b_st.site = &ce_emlrtRSI;
  computeQ_(&b_st, QRManager, QRManager->mrows);
  st.site = &od_emlrtRSI;
  xgemv(nVar, nVar, QRManager->Q.data, QRManager->ldq, grad_data, workspace_data);
  tol = muDoubleScalarAbs(QRManager->QR.data[0]) * muDoubleScalarMin
    (1.4901161193847656E-8, (real_T)muIntScalarMax_sint32(nVar, mConstr) *
     2.2204460492503131E-16);
  fullRank_R = muIntScalarMin_sint32(nVar, mConstr);
  rankR = 0;
  iQR_diag = 1;
  exitg1 = false;
  while ((!exitg1) && (rankR < fullRank_R)) {
    i = QRManager->QR.size[0] * QRManager->QR.size[1];
    if ((iQR_diag < 1) || (iQR_diag > i)) {
      emlrtDynamicBoundsCheckR2012b(iQR_diag, 1, i, &cc_emlrtBCI, sp);
    }

    if (muDoubleScalarAbs(QRManager->QR.data[iQR_diag - 1]) > tol) {
      rankR++;
      iQR_diag = (iQR_diag + QRManager->ldq) + 1;
    } else {
      exitg1 = true;
    }
  }

  st.site = &od_emlrtRSI;
  xtrsv(rankR, QRManager->QR.data, QRManager->ldq, workspace_data);
  fullRank_R = muIntScalarMin_sint32(mConstr, fullRank_R);
  st.site = &od_emlrtRSI;
  if ((1 <= fullRank_R) && (fullRank_R > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (rankR = 0; rankR < fullRank_R; rankR++) {
    i = lambdaLSQ_size[0];
    if ((QRManager->jpvt.data[rankR] < 1) || (QRManager->jpvt.data[rankR] > i))
    {
      emlrtDynamicBoundsCheckR2012b(QRManager->jpvt.data[rankR], 1, i,
        &cc_emlrtBCI, sp);
    }

    lambdaLSQ_data[QRManager->jpvt.data[rankR] - 1] = workspace_data[rankR];
  }
}

/* End of code generation (computeLambdaLSQ.c) */
