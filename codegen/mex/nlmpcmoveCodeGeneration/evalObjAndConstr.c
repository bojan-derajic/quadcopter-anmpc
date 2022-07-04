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
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "znlmpc_confun.h"
#include "znlmpc_getXUe.h"
#include "znlmpc_objfun.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo lc_emlrtRSI = { 16, /* lineNo */
  "znlmpc_objfun",                     /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_objfun.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 25, /* lineNo */
  "znlmpc_objfun",                     /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_objfun.m"/* pathName */
};

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
                      e_obj_objfun_tunableEnvironment[60], const real_T
                      f_obj_objfun_tunableEnvironment[60], const real_T
                      g_obj_objfun_tunableEnvironment[60], const real_T
                      h_obj_objfun_tunableEnvironment[60], const real_T
                      i_obj_objfun_tunableEnvironment[60], const real_T
                      c_obj_nonlcon_tunableEnvironmen[12], const real_T
                      d_obj_nonlcon_tunableEnvironmen[60], const real_T
                      e_obj_nonlcon_tunableEnvironmen[60], int32_T obj_mCineq,
                      const real_T x[241], real_T Cineq_workspace_data[], const
                      int32_T Cineq_workspace_size[1], int32_T ineq0, real_T
                      Ceq_workspace[180], real_T *fval, int32_T *status)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T X[192];
  real_T gfX[180];
  real_T c_data[120];
  real_T varargout_1_data[120];
  real_T U[64];
  real_T gfU[60];
  real_T unusedExpr[60];
  real_T e;
  real_T gfE;
  int32_T Jc_size[2];
  int32_T c_size[2];
  int32_T b_loop_ub;
  int32_T i;
  int32_T ineqEnd;
  int32_T loop_ub;
  int8_T input_sizes_idx_0;
  uint8_T sizes_idx_1;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  b_st.site = &nh_emlrtRSI;
  c_st.site = &lb_emlrtRSI;
  d_st.site = &kc_emlrtRSI;
  e_st.site = &lc_emlrtRSI;
  znlmpc_getXUe(x, c_obj_objfun_tunableEnvironment, X, U, &e);
  e_st.site = &mc_emlrtRSI;
  quadraticObjective(&e_st, d_obj_objfun_tunableEnvironment,
                     e_obj_objfun_tunableEnvironment,
                     f_obj_objfun_tunableEnvironment,
                     g_obj_objfun_tunableEnvironment,
                     h_obj_objfun_tunableEnvironment,
                     i_obj_objfun_tunableEnvironment, X, U, e, fval, gfX, gfU,
                     &gfE);
  e_st.site = &nc_emlrtRSI;
  f_st.site = &r_emlrtRSI;
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
    d_st.site = &mb_emlrtRSI;
    e_st.site = &nb_emlrtRSI;
    znlmpc_getXUe(x, c_obj_nonlcon_tunableEnvironmen, X, U, &e);
    e_st.site = &ob_emlrtRSI;
    stateEvolution(SD, &e_st, X, U, gfX, SD->u2.f6.Jceq);
    e_st.site = &pb_emlrtRSI;
    outputBounds(SD, &e_st, d_obj_nonlcon_tunableEnvironmen,
                 e_obj_nonlcon_tunableEnvironmen, X, e, c_data, c_size,
                 SD->u2.f6.Jc_data, Jc_size);
    e_st.site = &qb_emlrtRSI;
    f_st.site = &eb_emlrtRSI;
    sizes_idx_1 = (uint8_T)((c_size[0] != 0) && (c_size[1] != 0));
    g_st.site = &fb_emlrtRSI;
    if ((c_size[1] != sizes_idx_1) && ((c_size[0] != 0) && (c_size[1] != 0))) {
      emlrtErrorWithMessageIdR2018a(&g_st, &l_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if ((sizes_idx_1 == 0) || ((c_size[0] != 0) && (c_size[1] != 0))) {
      input_sizes_idx_0 = (int8_T)c_size[0];
    } else {
      input_sizes_idx_0 = 0;
    }

    loop_ub = sizes_idx_1;
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = input_sizes_idx_0;
      if (0 <= b_loop_ub - 1) {
        memcpy(&varargout_1_data[0], &c_data[0], b_loop_ub * sizeof(real_T));
      }
    }

    e_st.site = &rb_emlrtRSI;
    f_st.site = &eb_emlrtRSI;
    g_st.site = &fb_emlrtRSI;
    if ((Jc_size[0] != 0) && (Jc_size[1] != 0)) {
      loop_ub = (uint8_T)Jc_size[0];
    } else {
      loop_ub = 0;
    }

    if ((Jc_size[0] != loop_ub) && ((Jc_size[0] != 0) && (Jc_size[1] != 0))) {
      emlrtErrorWithMessageIdR2018a(&g_st, &l_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if (ineq0 > ineqEnd) {
      i = -1;
      b_loop_ub = -1;
    } else {
      i = Cineq_workspace_size[0];
      if ((ineq0 < 1) || (ineq0 > i)) {
        emlrtDynamicBoundsCheckR2012b(ineq0, 1, i, &ie_emlrtBCI, &st);
      }

      i = ineq0 - 2;
      b_loop_ub = Cineq_workspace_size[0];
      if ((ineqEnd < 1) || (ineqEnd > b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(ineqEnd, 1, b_loop_ub, &ie_emlrtBCI, &st);
      }

      b_loop_ub = ineqEnd - 1;
    }

    loop_ub = b_loop_ub - i;
    b_loop_ub = input_sizes_idx_0 * sizes_idx_1;
    if (loop_ub != b_loop_ub) {
      emlrtSubAssignSizeCheck1dR2017a(loop_ub, b_loop_ub, &emlrtECI, &st);
    }

    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      Cineq_workspace_data[(i + b_loop_ub) + 1] = varargout_1_data[b_loop_ub];
    }

    memcpy(&Ceq_workspace[0], &gfX[0], 180U * sizeof(real_T));
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
