/*
 * evalObjAndConstr.c
 *
 * Code generation for function 'evalObjAndConstr'
 *
 */

/* Include files */
#include "evalObjAndConstr.h"
#include "checkVectorNonFinite.h"
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "znlmpc_getXUe.h"
#include "znlmpc_objfun.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mh_emlrtRSI = { 1,  /* lineNo */
  "evalObjAndConstr",                  /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\evalObjAndConstr.p"/* pathName */
};

static emlrtRSInfo nh_emlrtRSI = { 1,  /* lineNo */
  "computeObjective_",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\computeObjective_.p"/* pathName */
};

static emlrtRSInfo oh_emlrtRSI = { 1,  /* lineNo */
  "computeConstraints_",               /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\computeConstraints_.p"/* pathName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "computeConstraints_",               /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\computeConstraints_.p"/* pName */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeConstraints_",               /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\computeConstraints_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void evalObjAndConstr(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
                      const real_T c_obj_objfun_tunableEnvironment[12], const
                      real_T d_obj_objfun_tunableEnvironment[4], const real_T
                      e_obj_objfun_tunableEnvironment[80], const real_T
                      f_obj_objfun_tunableEnvironment[80], const real_T
                      g_obj_objfun_tunableEnvironment[80], const real_T
                      h_obj_objfun_tunableEnvironment[80], const real_T
                      i_obj_objfun_tunableEnvironment[80], const real_T
                      c_obj_nonlcon_tunableEnvironmen[12], const real_T
                      d_obj_nonlcon_tunableEnvironmen[80], const real_T
                      e_obj_nonlcon_tunableEnvironmen[80], int32_T obj_mCineq,
                      const real_T x[321], real_T Cineq_workspace_data[], const
                      int32_T Cineq_workspace_size[1], int32_T ineq0, real_T
                      Ceq_workspace[240], real_T *fval, int32_T *status)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T X[252];
  real_T gfX[240];
  real_T varargout_1_data[160];
  real_T U[84];
  real_T gfU[80];
  real_T unusedExpr[80];
  real_T e;
  real_T gfE;
  int32_T varargout_1_size[2];
  int32_T i;
  int32_T i1;
  int32_T ineqEnd;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &nh_emlrtRSI;
  c_st.site = &lb_emlrtRSI;
  d_st.site = &kc_emlrtRSI;
  znlmpc_getXUe(x, c_obj_objfun_tunableEnvironment, X, U, &e);
  e_st.site = &mc_emlrtRSI;
  quadraticObjective(&e_st, d_obj_objfun_tunableEnvironment,
                     e_obj_objfun_tunableEnvironment,
                     f_obj_objfun_tunableEnvironment,
                     g_obj_objfun_tunableEnvironment,
                     h_obj_objfun_tunableEnvironment,
                     i_obj_objfun_tunableEnvironment, X, U, e, fval, gfX, gfU,
                     &gfE);
  c_mtimes(dv, gfU, unusedExpr);
  *status = 1;
  if (muDoubleScalarIsInf(*fval) || muDoubleScalarIsNaN(*fval)) {
    if (muDoubleScalarIsNaN(*fval)) {
      *status = -6;
    } else if (*fval < 0.0) {
      *status = -4;
    } else {
      *status = -5;
    }
  }

  if (*status == 1) {
    st.site = &mh_emlrtRSI;
    ineqEnd = (ineq0 + obj_mCineq) - 1;
    b_st.site = &oh_emlrtRSI;
    c_st.site = &lb_emlrtRSI;
    b_anon(SD, &c_st, c_obj_nonlcon_tunableEnvironmen,
           d_obj_nonlcon_tunableEnvironmen, e_obj_nonlcon_tunableEnvironmen, x,
           varargout_1_data, varargout_1_size, gfX);
    if (ineq0 > ineqEnd) {
      i = -1;
      i1 = -1;
    } else {
      i = Cineq_workspace_size[0];
      if ((ineq0 < 1) || (ineq0 > i)) {
        emlrtDynamicBoundsCheckR2012b(ineq0, 1, i, &ie_emlrtBCI, &st);
      }

      i = ineq0 - 2;
      i1 = Cineq_workspace_size[0];
      if ((ineqEnd < 1) || (ineqEnd > i1)) {
        emlrtDynamicBoundsCheckR2012b(ineqEnd, 1, i1, &ie_emlrtBCI, &st);
      }

      i1 = ineqEnd - 1;
    }

    ineqEnd = i1 - i;
    i1 = varargout_1_size[0] * varargout_1_size[1];
    if (ineqEnd != i1) {
      emlrtSubAssignSizeCheck1dR2017a(ineqEnd, i1, &emlrtECI, &st);
    }

    for (i1 = 0; i1 < ineqEnd; i1++) {
      Cineq_workspace_data[(i + i1) + 1] = varargout_1_data[i1];
    }

    memcpy(&Ceq_workspace[0], &gfX[0], 240U * sizeof(real_T));
    b_st.site = &oh_emlrtRSI;
    *status = checkVectorNonFinite(&b_st, obj_mCineq, Cineq_workspace_data,
      Cineq_workspace_size, ineq0);
    if (*status == 1) {
      b_st.site = &oh_emlrtRSI;
      *status = b_checkVectorNonFinite(&b_st, Ceq_workspace);
    }
  }
}

/* End of code generation (evalObjAndConstr.c) */
