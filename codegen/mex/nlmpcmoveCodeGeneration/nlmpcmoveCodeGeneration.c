/*
 * nlmpcmoveCodeGeneration.c
 *
 * Code generation for function 'nlmpcmoveCodeGeneration'
 *
 */

/* Include files */
#include "nlmpcmoveCodeGeneration.h"
#include "fmincon.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "znlmpc_confun.h"
#include "znlmpc_generateRuntimeData.h"
#include "znlmpc_getUBounds.h"
#include "znlmpc_getXUe.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 48,    /* lineNo */
  "nlmpcmoveCodeGeneration",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpc\\nlmpcmoveCodeGeneration.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 50,  /* lineNo */
  "nlmpcmoveCodeGeneration",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpc\\nlmpcmoveCodeGeneration.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 91,  /* lineNo */
  "nlmpcmoveCodeGeneration",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpc\\nlmpcmoveCodeGeneration.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 112, /* lineNo */
  "nlmpcmoveCodeGeneration",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpc\\nlmpcmoveCodeGeneration.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 132, /* lineNo */
  "nlmpcmoveCodeGeneration",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpc\\nlmpcmoveCodeGeneration.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 139, /* lineNo */
  "nlmpcmoveCodeGeneration",           /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpc\\nlmpcmoveCodeGeneration.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 117,/* lineNo */
  "@(z) znlmpc_confun(z(:), coredata, runtimedata, userdata, handles)",/* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpc\\nlmpcmoveCodeGeneration.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 20, /* lineNo */
  "znlmpc_confun",                     /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 23, /* lineNo */
  "znlmpc_confun",                     /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 26, /* lineNo */
  "znlmpc_confun",                     /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 78, /* lineNo */
  "znlmpc_confun",                     /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 80, /* lineNo */
  "znlmpc_confun",                     /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m"/* pathName */
};

/* Function Definitions */
void anon(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
          real_T runtimedata_x[12], const real_T runtimedata_OutputMin[80],
          const real_T runtimedata_OutputMax[80], const real_T z[321], real_T
          varargout_1_data[], int32_T varargout_1_size[2], real_T varargout_2
          [240], real_T varargout_3_data[], int32_T varargout_3_size[2], real_T
          varargout_4[77040])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T X[252];
  real_T c_data[160];
  real_T U[84];
  real_T e;
  int32_T Jc_size[2];
  int32_T c_size[2];
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int16_T sizes_idx_1;
  uint8_T input_sizes_idx_0;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &nb_emlrtRSI;
  znlmpc_getXUe(z, runtimedata_x, X, U, &e);
  b_st.site = &ob_emlrtRSI;
  stateEvolution(SD, &b_st, X, U, varargout_2, varargout_4);
  b_st.site = &pb_emlrtRSI;
  outputBounds(SD, &b_st, runtimedata_OutputMin, runtimedata_OutputMax, X, e,
               c_data, c_size, SD->u2.f6.Jc_data, Jc_size);
  b_st.site = &qb_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  sizes_idx_1 = (int16_T)((c_size[0] != 0) && (c_size[1] != 0));
  d_st.site = &fb_emlrtRSI;
  if ((c_size[1] != sizes_idx_1) && ((c_size[0] != 0) && (c_size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((sizes_idx_1 == 0) || ((c_size[0] != 0) && (c_size[1] != 0))) {
    input_sizes_idx_0 = (uint8_T)c_size[0];
  } else {
    input_sizes_idx_0 = 0U;
  }

  varargout_1_size[0] = input_sizes_idx_0;
  varargout_1_size[1] = sizes_idx_1;
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = input_sizes_idx_0;
    if (0 <= b_loop_ub - 1) {
      memcpy(&varargout_1_data[0], &c_data[0], b_loop_ub * sizeof(real_T));
    }
  }

  b_st.site = &rb_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  if ((Jc_size[0] != 0) && (Jc_size[1] != 0)) {
    sizes_idx_1 = (int16_T)Jc_size[0];
  } else {
    sizes_idx_1 = 0;
  }

  d_st.site = &fb_emlrtRSI;
  if ((Jc_size[0] != sizes_idx_1) && ((Jc_size[0] != 0) && (Jc_size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((sizes_idx_1 == 0) || ((Jc_size[0] != 0) && (Jc_size[1] != 0))) {
    input_sizes_idx_0 = (uint8_T)Jc_size[1];
  } else {
    input_sizes_idx_0 = 0U;
  }

  varargout_3_size[0] = sizes_idx_1;
  varargout_3_size[1] = input_sizes_idx_0;
  loop_ub = input_sizes_idx_0;
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = sizes_idx_1;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      varargout_3_data[i1 + sizes_idx_1 * i] = SD->u2.f6.Jc_data[i1 +
        sizes_idx_1 * i];
    }
  }
}

void b_anon(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
            real_T runtimedata_x[12], const real_T runtimedata_OutputMin[80],
            const real_T runtimedata_OutputMax[80], const real_T z[321], real_T
            varargout_1_data[], int32_T varargout_1_size[2], real_T varargout_2
            [240])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T X[252];
  real_T c_data[160];
  real_T U[84];
  real_T e;
  int32_T Jc_size[2];
  int32_T c_size[2];
  int32_T b_loop_ub;
  int32_T i;
  int32_T loop_ub;
  int16_T sizes_idx_1;
  uint8_T input_sizes_idx_0;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &nb_emlrtRSI;
  znlmpc_getXUe(z, runtimedata_x, X, U, &e);
  b_st.site = &ob_emlrtRSI;
  stateEvolution(SD, &b_st, X, U, varargout_2, SD->u2.f7.Jceq);
  b_st.site = &pb_emlrtRSI;
  outputBounds(SD, &b_st, runtimedata_OutputMin, runtimedata_OutputMax, X, e,
               c_data, c_size, SD->u2.f7.Jc_data, Jc_size);
  b_st.site = &qb_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  sizes_idx_1 = (int16_T)((c_size[0] != 0) && (c_size[1] != 0));
  d_st.site = &fb_emlrtRSI;
  if ((c_size[1] != sizes_idx_1) && ((c_size[0] != 0) && (c_size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((sizes_idx_1 == 0) || ((c_size[0] != 0) && (c_size[1] != 0))) {
    input_sizes_idx_0 = (uint8_T)c_size[0];
  } else {
    input_sizes_idx_0 = 0U;
  }

  varargout_1_size[0] = input_sizes_idx_0;
  varargout_1_size[1] = sizes_idx_1;
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = input_sizes_idx_0;
    if (0 <= b_loop_ub - 1) {
      memcpy(&varargout_1_data[0], &c_data[0], b_loop_ub * sizeof(real_T));
    }
  }

  b_st.site = &rb_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  d_st.site = &fb_emlrtRSI;
  if ((Jc_size[0] != 0) && (Jc_size[1] != 0)) {
    loop_ub = (int16_T)Jc_size[0];
  } else {
    loop_ub = 0;
  }

  if ((Jc_size[0] != loop_ub) && ((Jc_size[0] != 0) && (Jc_size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
}

void nlmpcmoveCodeGeneration(c_nlmpcmoveCodeGenerationStackD *SD, const
  emlrtStack *sp, const real_T x[12], const real_T lastMV[4], struct1_T
  *onlinedata, real_T mv[4], struct2_T *info)
{
  static const int8_T iv[20] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 20 };

  b_struct_T Out;
  e_struct_T CostFcn_tunableEnvironment_f2;
  emlrtStack b_st;
  emlrtStack st;
  f_struct_T runtimedata;
  real_T b_runtimedata[321];
  real_T d_runtimedata[321];
  real_T z[321];
  real_T z0[321];
  real_T B_data[320];
  real_T c_runtimedata[240];
  real_T e_runtimedata[240];
  real_T ExitFlag;
  real_T e;
  int32_T A_size[2];
  int32_T B_size[1];
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T runtimedata_tmp;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &g_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 12)) {
    if ((!muDoubleScalarIsInf(x[k])) && (!muDoubleScalarIsNaN(x[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:nlmpcmoveCodeGeneration:expectedFinite", 3, 4, 3, "\"x\"");
  }

  st.site = &b_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if ((!muDoubleScalarIsInf(lastMV[k])) && (!muDoubleScalarIsNaN(lastMV[k])))
    {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:nlmpcmoveCodeGeneration:expectedFinite", 3, 4, 8, "\"lastMV\"");
  }

  st.site = &c_emlrtRSI;
  znlmpc_generateRuntimeData(&st, x, lastMV, onlinedata->ref,
    onlinedata->MVTarget, onlinedata->X0, onlinedata->MV0, onlinedata->Slack0,
    &runtimedata, &CostFcn_tunableEnvironment_f2, z0);
  st.site = &d_emlrtRSI;
  znlmpc_getUBounds(SD, &st, &runtimedata, SD->f11.A_data, A_size, B_data,
                    B_size);
  for (i = 0; i < 20; i++) {
    for (i1 = 0; i1 < 12; i1++) {
      k = i + 20 * i1;
      runtimedata_tmp = i1 + 12 * i;
      c_runtimedata[runtimedata_tmp] = runtimedata.StateMin[k];
      e_runtimedata[runtimedata_tmp] = runtimedata.StateMax[k];
    }
  }

  memcpy(&b_runtimedata[0], &c_runtimedata[0], 240U * sizeof(real_T));
  for (i = 0; i < 80; i++) {
    b_runtimedata[i + 240] = rtMinusInf;
  }

  b_runtimedata[320] = 0.0;
  memcpy(&d_runtimedata[0], &e_runtimedata[0], 240U * sizeof(real_T));
  for (i = 0; i < 80; i++) {
    d_runtimedata[i + 240] = rtInf;
  }

  d_runtimedata[320] = rtInf;
  st.site = &e_emlrtRSI;
  fmincon(SD, &st, &runtimedata, &CostFcn_tunableEnvironment_f2, z0,
          SD->f11.A_data, A_size, B_data, B_size, b_runtimedata, d_runtimedata,
          &runtimedata, &CostFcn_tunableEnvironment_f2, z, &info->Cost,
          &ExitFlag, &Out);
  if ((ExitFlag == 0.0) && (Out.constrviolation > 1.0E-6)) {
    ExitFlag = -2.0;
  }

  st.site = &f_emlrtRSI;
  znlmpc_getXUe(z, x, info->Xopt, info->MVopt, &e);
  if (ExitFlag > 0.0) {
    mv[0] = info->MVopt[0];
    mv[1] = info->MVopt[21];
    mv[2] = info->MVopt[42];
    mv[3] = info->MVopt[63];
  } else {
    mv[0] = lastMV[0];
    mv[1] = lastMV[1];
    mv[2] = lastMV[2];
    mv[3] = lastMV[3];
  }

  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      onlinedata->X0[i1 + 20 * i] = info->Xopt[iv[i1] + 21 * i];
    }
  }

  for (k = 0; k < 21; k++) {
    /* OUTPUT_FCN */
    /*     H = OUTPUT_FCN(IN1,IN2) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
    /*     01-Jul-2022 08:01:35 */
    info->Yopt[k] = info->Xopt[k];
    info->Yopt[k + 21] = info->Xopt[k + 21];
    info->Yopt[k + 42] = info->Xopt[k + 42];
    info->Yopt[k + 63] = info->Xopt[k + 168];
    info->Topt[k] = 0.2 * (real_T)k;
  }

  info->Slack = e;
  info->ExitFlag = ExitFlag;
  info->Iterations = Out.iterations;
  for (i = 0; i < 4; i++) {
    memcpy(&onlinedata->MV0[i * 20], &info->MVopt[i * 21 + 1], 20U * sizeof
           (real_T));
  }

  onlinedata->Slack0 = muDoubleScalarMax(0.0, e);
}

/* End of code generation (nlmpcmoveCodeGeneration.c) */
