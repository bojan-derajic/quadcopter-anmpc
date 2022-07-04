/*
 * evalObjAndConstrAndDerivatives.c
 *
 * Code generation for function 'evalObjAndConstrAndDerivatives'
 *
 */

/* Include files */
#include "evalObjAndConstrAndDerivatives.h"
#include "computeConstraintsAndUserJacobian_.h"
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "znlmpc_getXUe.h"
#include "znlmpc_objfun.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 1,  /* lineNo */
  "computeObjectiveAndUserGradient_",  /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\computeObjectiveAndUserGradient_.p"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 1,  /* lineNo */
  "evalObjAndConstrAndDerivatives",    /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\evalObjAndConstrAndDerivatives.p"/* pathName */
};

/* Function Definitions */
void evalObjAndConstrAndDerivatives(c_nlmpcmoveCodeGenerationStackD *SD, const
  emlrtStack *sp, const real_T c_obj_objfun_tunableEnvironment[12], const real_T
  d_obj_objfun_tunableEnvironment[4], const real_T
  e_obj_objfun_tunableEnvironment[80], const real_T
  f_obj_objfun_tunableEnvironment[80], const real_T
  g_obj_objfun_tunableEnvironment[80], const real_T
  h_obj_objfun_tunableEnvironment[80], const real_T
  i_obj_objfun_tunableEnvironment[80], const real_T
  c_obj_nonlcon_tunableEnvironmen[12], const real_T
  d_obj_nonlcon_tunableEnvironmen[80], const real_T
  e_obj_nonlcon_tunableEnvironmen[80], int32_T obj_mCineq, const real_T x[321],
  real_T grad_workspace_data[], const int32_T grad_workspace_size[1], real_T
  Cineq_workspace_data[], const int32_T Cineq_workspace_size[1], int32_T ineq0,
  real_T Ceq_workspace[240], real_T JacIneqTrans_workspace_data[], const int32_T
  JacIneqTrans_workspace_size[2], int32_T iJI_col, real_T
  JacEqTrans_workspace_data[], const int32_T JacEqTrans_workspace_size[2],
  real_T *fval, int32_T *status)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_gfX[321];
  real_T X[252];
  real_T gfX[240];
  real_T U[84];
  real_T gfU[80];
  real_T y[80];
  real_T e;
  real_T gfE;
  int32_T i;
  int32_T idx_current;
  boolean_T allFinite;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &jc_emlrtRSI;
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
  c_mtimes(dv, gfU, y);
  memcpy(&b_gfX[0], &gfX[0], 240U * sizeof(real_T));
  memcpy(&b_gfX[240], &y[0], 80U * sizeof(real_T));
  b_gfX[320] = gfE;
  b_st.site = &jc_emlrtRSI;
  xcopy(&b_st, 321, b_gfX, grad_workspace_data);
  *status = 1;
  if (muDoubleScalarIsInf(*fval) || muDoubleScalarIsNaN(*fval)) {
    if (muDoubleScalarIsNaN(*fval)) {
      *status = -6;
    } else if (*fval < 0.0) {
      *status = -4;
    } else {
      *status = -5;
    }
  } else {
    b_st.site = &jc_emlrtRSI;
    allFinite = true;
    idx_current = 0;
    while (allFinite && (idx_current + 1 <= 321)) {
      allFinite = ((!muDoubleScalarIsInf(grad_workspace_data[idx_current])) && (
        !muDoubleScalarIsNaN(grad_workspace_data[idx_current])));
      idx_current++;
    }

    if (!allFinite) {
      i = grad_workspace_size[0];
      if ((idx_current < 1) || (idx_current > i)) {
        emlrtDynamicBoundsCheckR2012b(idx_current, 1, i, &eb_emlrtBCI, &b_st);
      }

      e = grad_workspace_data[idx_current - 1];
      if (muDoubleScalarIsNaN(e)) {
        *status = -6;
      } else if (e < 0.0) {
        *status = -4;
      } else {
        *status = -5;
      }
    }
  }

  if (*status == 1) {
    st.site = &sc_emlrtRSI;
    *status = c_computeConstraintsAndUserJaco(SD, &st,
      c_obj_nonlcon_tunableEnvironmen, d_obj_nonlcon_tunableEnvironmen,
      e_obj_nonlcon_tunableEnvironmen, obj_mCineq, x, Cineq_workspace_data,
      Cineq_workspace_size, ineq0, Ceq_workspace, JacIneqTrans_workspace_data,
      JacIneqTrans_workspace_size, iJI_col, JacEqTrans_workspace_data,
      JacEqTrans_workspace_size);
  }
}

/* End of code generation (evalObjAndConstrAndDerivatives.c) */
