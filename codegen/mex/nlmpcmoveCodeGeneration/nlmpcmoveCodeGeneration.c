/*
 * nlmpcmoveCodeGeneration.c
 *
 * Code generation for function 'nlmpcmoveCodeGeneration'
 *
 */

/* Include files */
#include "nlmpcmoveCodeGeneration.h"
#include "fmincon.h"
#include "indexShapeCheck.h"
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "znlmpc_confun.h"
#include "znlmpc_generateRuntimeData.h"
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

static emlrtRSInfo u_emlrtRSI = { 50,  /* lineNo */
  "znlmpc_getUBounds",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 65,  /* lineNo */
  "znlmpc_getUBounds",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 39,  /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtBCInfo w_emlrtBCI = { 1,   /* iFirst */
  240,                                 /* iLast */
  22,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { 1,   /* iFirst */
  240,                                 /* iLast */
  23,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  240,                                 /* iLast */
  24,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  25,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  28,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  29,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  30,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  33,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  34,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  37,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  38,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  39,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  45,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  42,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void anon(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
          real_T runtimedata_x[12], const real_T runtimedata_OutputMin[60],
          const real_T runtimedata_OutputMax[60], const real_T z[241], real_T
          varargout_1_data[], int32_T varargout_1_size[2], real_T varargout_2
          [180], real_T varargout_3_data[], int32_T varargout_3_size[2], real_T
          varargout_4[43380])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T X[192];
  real_T c_data[120];
  real_T U[64];
  real_T e;
  int32_T Jc_size[2];
  int32_T c_size[2];
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int8_T input_sizes_idx_0;
  uint8_T sizes_idx_1;
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
               c_data, c_size, SD->u2.f5.Jc_data, Jc_size);
  b_st.site = &qb_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  sizes_idx_1 = (uint8_T)((c_size[0] != 0) && (c_size[1] != 0));
  d_st.site = &fb_emlrtRSI;
  if ((c_size[1] != sizes_idx_1) && ((c_size[0] != 0) && (c_size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&d_st, &l_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((sizes_idx_1 == 0) || ((c_size[0] != 0) && (c_size[1] != 0))) {
    input_sizes_idx_0 = (int8_T)c_size[0];
  } else {
    input_sizes_idx_0 = 0;
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
    sizes_idx_1 = (uint8_T)Jc_size[0];
  } else {
    sizes_idx_1 = 0U;
  }

  d_st.site = &fb_emlrtRSI;
  if ((Jc_size[0] != sizes_idx_1) && ((Jc_size[0] != 0) && (Jc_size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&d_st, &l_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((sizes_idx_1 == 0) || ((Jc_size[0] != 0) && (Jc_size[1] != 0))) {
    input_sizes_idx_0 = (int8_T)Jc_size[1];
  } else {
    input_sizes_idx_0 = 0;
  }

  varargout_3_size[0] = sizes_idx_1;
  varargout_3_size[1] = input_sizes_idx_0;
  loop_ub = input_sizes_idx_0;
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = sizes_idx_1;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      varargout_3_data[i1 + sizes_idx_1 * i] = SD->u2.f5.Jc_data[i1 +
        sizes_idx_1 * i];
    }
  }
}

void nlmpcmoveCodeGeneration(c_nlmpcmoveCodeGenerationStackD *SD, const
  emlrtStack *sp, const real_T x[12], const real_T lastMV[4], struct1_T
  *onlinedata, real_T mv[4], struct2_T *info)
{
  static const int8_T iv[15] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    15 };

  b_struct_T Out;
  e_struct_T CostFcn_tunableEnvironment_f2;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  f_struct_T b_expl_temp;
  f_struct_T expl_temp;
  f_struct_T runtimedata;
  real_T b_runtimedata[241];
  real_T d_runtimedata[241];
  real_T z[241];
  real_T z0[241];
  real_T B_data[240];
  real_T Bu[240];
  real_T c_runtimedata[180];
  real_T e_runtimedata[180];
  real_T Bu_idx_2;
  real_T Bu_idx_3;
  real_T ExitFlag;
  real_T d;
  real_T d1;
  real_T d10;
  real_T d11;
  real_T d12;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T d7;
  real_T d8;
  real_T d9;
  real_T ic_idx_0;
  real_T ic_idx_1;
  real_T ic_idx_2;
  real_T ic_idx_3;
  int32_T A_size[2];
  int32_T ii[2];
  int32_T y_size[2];
  int32_T B_size[1];
  int32_T Au_tmp;
  int32_T b_i;
  int32_T i;
  int32_T idx;
  int32_T ii_size_idx_0;
  int32_T loop_ub;
  int8_T Au[14400];
  int8_T As[16];
  uint8_T ii_data[240];
  boolean_T icf[240];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &g_emlrtRSI;
  p = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 12)) {
    if ((!muDoubleScalarIsInf(x[idx])) && (!muDoubleScalarIsNaN(x[idx]))) {
      idx++;
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
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 4)) {
    if ((!muDoubleScalarIsInf(lastMV[idx])) && (!muDoubleScalarIsNaN(lastMV[idx])))
    {
      idx++;
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
  memset(&Au[0], 0, 14400U * sizeof(int8_T));
  memset(&Bu[0], 0, 240U * sizeof(real_T));
  memset(&icf[0], 0, 240U * sizeof(boolean_T));
  ic_idx_0 = 1.0;
  ic_idx_1 = 2.0;
  ic_idx_2 = 3.0;
  ic_idx_3 = 4.0;
  for (i = 0; i < 16; i++) {
    As[i] = 0;
  }

  As[0] = 1;
  As[5] = 1;
  As[10] = 1;
  As[15] = 1;
  for (b_i = 0; b_i < 15; b_i++) {
    ExitFlag = runtimedata.MVRateMin[b_i];
    Bu_idx_2 = runtimedata.MVRateMin[b_i + 15];
    Bu_idx_3 = runtimedata.MVRateMin[b_i + 30];
    d = runtimedata.MVRateMin[b_i + 45];
    if (((int32_T)ic_idx_0 < 1) || ((int32_T)ic_idx_0 > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ic_idx_0, 1, 240, &w_emlrtBCI, &st);
    }

    icf[(int32_T)ic_idx_0 - 1] = ((!muDoubleScalarIsInf(ExitFlag)) &&
      (!muDoubleScalarIsNaN(ExitFlag)));
    if (((int32_T)ic_idx_1 < 1) || ((int32_T)ic_idx_1 > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ic_idx_1, 1, 240, &w_emlrtBCI, &st);
    }

    icf[(int32_T)ic_idx_1 - 1] = ((!muDoubleScalarIsInf(Bu_idx_2)) &&
      (!muDoubleScalarIsNaN(Bu_idx_2)));
    if (((int32_T)ic_idx_2 < 1) || ((int32_T)ic_idx_2 > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ic_idx_2, 1, 240, &w_emlrtBCI, &st);
    }

    icf[(int32_T)ic_idx_2 - 1] = ((!muDoubleScalarIsInf(Bu_idx_3)) &&
      (!muDoubleScalarIsNaN(Bu_idx_3)));
    if (((int32_T)ic_idx_3 < 1) || ((int32_T)ic_idx_3 > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ic_idx_3, 1, 240, &w_emlrtBCI, &st);
    }

    icf[(int32_T)ic_idx_3 - 1] = ((!muDoubleScalarIsInf(d)) &&
      (!muDoubleScalarIsNaN(d)));
    d1 = runtimedata.MVRateMax[b_i];
    d2 = runtimedata.MVRateMax[b_i + 15];
    d3 = runtimedata.MVRateMax[b_i + 30];
    d4 = runtimedata.MVRateMax[b_i + 45];
    if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 240,
        &x_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_0 + 4.0) - 1] = ((!muDoubleScalarIsInf(d1)) &&
      (!muDoubleScalarIsNaN(d1)));
    if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 240,
        &x_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_1 + 4.0) - 1] = ((!muDoubleScalarIsInf(d2)) &&
      (!muDoubleScalarIsNaN(d2)));
    if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 240,
        &x_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_2 + 4.0) - 1] = ((!muDoubleScalarIsInf(d3)) &&
      (!muDoubleScalarIsNaN(d3)));
    if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 240,
        &x_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_3 + 4.0) - 1] = ((!muDoubleScalarIsInf(d4)) &&
      (!muDoubleScalarIsNaN(d4)));
    d5 = runtimedata.MVMin[b_i];
    d6 = runtimedata.MVMin[b_i + 15];
    d7 = runtimedata.MVMin[b_i + 30];
    d8 = runtimedata.MVMin[b_i + 45];
    if (((int32_T)(ic_idx_0 + 8.0) < 1) || ((int32_T)(ic_idx_0 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 8.0), 1, 240,
        &y_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_0 + 8.0) - 1] = ((!muDoubleScalarIsInf(d5)) &&
      (!muDoubleScalarIsNaN(d5)));
    if (((int32_T)(ic_idx_1 + 8.0) < 1) || ((int32_T)(ic_idx_1 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 8.0), 1, 240,
        &y_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_1 + 8.0) - 1] = ((!muDoubleScalarIsInf(d6)) &&
      (!muDoubleScalarIsNaN(d6)));
    if (((int32_T)(ic_idx_2 + 8.0) < 1) || ((int32_T)(ic_idx_2 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 8.0), 1, 240,
        &y_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_2 + 8.0) - 1] = ((!muDoubleScalarIsInf(d7)) &&
      (!muDoubleScalarIsNaN(d7)));
    if (((int32_T)(ic_idx_3 + 8.0) < 1) || ((int32_T)(ic_idx_3 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 8.0), 1, 240,
        &y_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_3 + 8.0) - 1] = ((!muDoubleScalarIsInf(d8)) &&
      (!muDoubleScalarIsNaN(d8)));
    d9 = runtimedata.MVMax[b_i];
    d10 = runtimedata.MVMax[b_i + 15];
    d11 = runtimedata.MVMax[b_i + 30];
    d12 = runtimedata.MVMax[b_i + 45];
    if (((int32_T)(ic_idx_0 + 12.0) < 1) || ((int32_T)(ic_idx_0 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 12.0), 1, 240,
        &ab_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_0 + 12.0) - 1] = ((!muDoubleScalarIsInf(d9)) &&
      (!muDoubleScalarIsNaN(d9)));
    if (((int32_T)(ic_idx_1 + 12.0) < 1) || ((int32_T)(ic_idx_1 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 12.0), 1, 240,
        &ab_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_1 + 12.0) - 1] = ((!muDoubleScalarIsInf(d10)) &&
      (!muDoubleScalarIsNaN(d10)));
    if (((int32_T)(ic_idx_2 + 12.0) < 1) || ((int32_T)(ic_idx_2 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 12.0), 1, 240,
        &ab_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_2 + 12.0) - 1] = ((!muDoubleScalarIsInf(d11)) &&
      (!muDoubleScalarIsNaN(d11)));
    if (((int32_T)(ic_idx_3 + 12.0) < 1) || ((int32_T)(ic_idx_3 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 12.0), 1, 240,
        &ab_emlrtBCI, &st);
    }

    icf[(int32_T)(ic_idx_3 + 12.0) - 1] = ((!muDoubleScalarIsInf(d12)) &&
      (!muDoubleScalarIsNaN(d12)));
    for (i = 0; i < 4; i++) {
      Au_tmp = i << 2;
      Au[(((int32_T)ic_idx_0 + 240 * i) + 960 * b_i) - 1] = (int8_T)-As[Au_tmp];
      Au[(((int32_T)ic_idx_1 + 240 * i) + 960 * b_i) - 1] = (int8_T)-As[Au_tmp +
        1];
      Au[(((int32_T)ic_idx_2 + 240 * i) + 960 * b_i) - 1] = (int8_T)-As[Au_tmp +
        2];
      Au[(((int32_T)ic_idx_3 + 240 * i) + 960 * b_i) - 1] = (int8_T)-As[Au_tmp +
        3];
    }

    for (i = 0; i < 4; i++) {
      if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 240,
          &bb_emlrtBCI, &st);
      }

      Au_tmp = i << 2;
      Au[(((int32_T)(ic_idx_0 + 4.0) + 240 * i) + 960 * b_i) - 1] = As[Au_tmp];
      if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 240,
          &bb_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_1 + 4.0) + 240 * i) + 960 * b_i) - 1] = As[Au_tmp +
        1];
      if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 240,
          &bb_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_2 + 4.0) + 240 * i) + 960 * b_i) - 1] = As[Au_tmp +
        2];
      if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 240,
          &bb_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_3 + 4.0) + 240 * i) + 960 * b_i) - 1] = As[Au_tmp +
        3];
    }

    for (i = 0; i < 4; i++) {
      if (((int32_T)(ic_idx_0 + 8.0) < 1) || ((int32_T)(ic_idx_0 + 8.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 8.0), 1, 240,
          &cb_emlrtBCI, &st);
      }

      Au_tmp = i << 2;
      Au[(((int32_T)(ic_idx_0 + 8.0) + 240 * i) + 960 * b_i) - 1] = (int8_T)
        -As[Au_tmp];
      if (((int32_T)(ic_idx_1 + 8.0) < 1) || ((int32_T)(ic_idx_1 + 8.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 8.0), 1, 240,
          &cb_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_1 + 8.0) + 240 * i) + 960 * b_i) - 1] = (int8_T)
        -As[Au_tmp + 1];
      if (((int32_T)(ic_idx_2 + 8.0) < 1) || ((int32_T)(ic_idx_2 + 8.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 8.0), 1, 240,
          &cb_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_2 + 8.0) + 240 * i) + 960 * b_i) - 1] = (int8_T)
        -As[Au_tmp + 2];
      if (((int32_T)(ic_idx_3 + 8.0) < 1) || ((int32_T)(ic_idx_3 + 8.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 8.0), 1, 240,
          &cb_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_3 + 8.0) + 240 * i) + 960 * b_i) - 1] = (int8_T)
        -As[Au_tmp + 3];
    }

    for (i = 0; i < 4; i++) {
      if (((int32_T)(ic_idx_0 + 12.0) < 1) || ((int32_T)(ic_idx_0 + 12.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 12.0), 1, 240,
          &db_emlrtBCI, &st);
      }

      Au_tmp = i << 2;
      Au[(((int32_T)(ic_idx_0 + 12.0) + 240 * i) + 960 * b_i) - 1] = As[Au_tmp];
      if (((int32_T)(ic_idx_1 + 12.0) < 1) || ((int32_T)(ic_idx_1 + 12.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 12.0), 1, 240,
          &db_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_1 + 12.0) + 240 * i) + 960 * b_i) - 1] = As[Au_tmp +
        1];
      if (((int32_T)(ic_idx_2 + 12.0) < 1) || ((int32_T)(ic_idx_2 + 12.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 12.0), 1, 240,
          &db_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_2 + 12.0) + 240 * i) + 960 * b_i) - 1] = As[Au_tmp +
        2];
      if (((int32_T)(ic_idx_3 + 12.0) < 1) || ((int32_T)(ic_idx_3 + 12.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 12.0), 1, 240,
          &db_emlrtBCI, &st);
      }

      Au[(((int32_T)(ic_idx_3 + 12.0) + 240 * i) + 960 * b_i) - 1] = As[Au_tmp +
        3];
    }

    if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 240,
        &eb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 240,
        &eb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 240,
        &eb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 240,
        &eb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_0 + 8.0) < 1) || ((int32_T)(ic_idx_0 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 8.0), 1, 240,
        &fb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_1 + 8.0) < 1) || ((int32_T)(ic_idx_1 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 8.0), 1, 240,
        &fb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_2 + 8.0) < 1) || ((int32_T)(ic_idx_2 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 8.0), 1, 240,
        &fb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_3 + 8.0) < 1) || ((int32_T)(ic_idx_3 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 8.0), 1, 240,
        &fb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_0 + 12.0) < 1) || ((int32_T)(ic_idx_0 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 12.0), 1, 240,
        &gb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_1 + 12.0) < 1) || ((int32_T)(ic_idx_1 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 12.0), 1, 240,
        &gb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_2 + 12.0) < 1) || ((int32_T)(ic_idx_2 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 12.0), 1, 240,
        &gb_emlrtBCI, &st);
    }

    if (((int32_T)(ic_idx_3 + 12.0) < 1) || ((int32_T)(ic_idx_3 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 12.0), 1, 240,
        &gb_emlrtBCI, &st);
    }

    Bu[(int32_T)ic_idx_0 - 1] = -ExitFlag;
    Bu[(int32_T)ic_idx_1 - 1] = -Bu_idx_2;
    Bu[(int32_T)ic_idx_2 - 1] = -Bu_idx_3;
    Bu[(int32_T)ic_idx_3 - 1] = -d;
    if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 240,
        &hb_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_0 + 4.0) - 1] = d1;
    if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 240,
        &hb_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_1 + 4.0) - 1] = d2;
    if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 240,
        &hb_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_2 + 4.0) - 1] = d3;
    if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 240,
        &hb_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_3 + 4.0) - 1] = d4;
    if (((int32_T)(ic_idx_0 + 8.0) < 1) || ((int32_T)(ic_idx_0 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 8.0), 1, 240,
        &ib_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_0 + 8.0) - 1] = -d5;
    if (((int32_T)(ic_idx_1 + 8.0) < 1) || ((int32_T)(ic_idx_1 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 8.0), 1, 240,
        &ib_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_1 + 8.0) - 1] = -d6;
    if (((int32_T)(ic_idx_2 + 8.0) < 1) || ((int32_T)(ic_idx_2 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 8.0), 1, 240,
        &ib_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_2 + 8.0) - 1] = -d7;
    if (((int32_T)(ic_idx_3 + 8.0) < 1) || ((int32_T)(ic_idx_3 + 8.0) > 240)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 8.0), 1, 240,
        &ib_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_3 + 8.0) - 1] = -d8;
    if (((int32_T)(ic_idx_0 + 12.0) < 1) || ((int32_T)(ic_idx_0 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 12.0), 1, 240,
        &jb_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_0 + 12.0) - 1] = d9;
    if (((int32_T)(ic_idx_1 + 12.0) < 1) || ((int32_T)(ic_idx_1 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 12.0), 1, 240,
        &jb_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_1 + 12.0) - 1] = d10;
    if (((int32_T)(ic_idx_2 + 12.0) < 1) || ((int32_T)(ic_idx_2 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 12.0), 1, 240,
        &jb_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_2 + 12.0) - 1] = d11;
    if (((int32_T)(ic_idx_3 + 12.0) < 1) || ((int32_T)(ic_idx_3 + 12.0) > 240))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 12.0), 1, 240,
        &jb_emlrtBCI, &st);
    }

    Bu[(int32_T)(ic_idx_3 + 12.0) - 1] = d12;
    if (b_i + 1 == 1) {
      ExitFlag = Bu[(int32_T)ic_idx_1 - 1] - runtimedata.lastMV[1];
      Bu_idx_2 = Bu[(int32_T)ic_idx_2 - 1] - runtimedata.lastMV[2];
      Bu_idx_3 = Bu[(int32_T)ic_idx_3 - 1] - runtimedata.lastMV[3];
      Bu[(int32_T)ic_idx_0 - 1] -= runtimedata.lastMV[0];
      Bu[(int32_T)ic_idx_1 - 1] = ExitFlag;
      Bu[(int32_T)ic_idx_2 - 1] = Bu_idx_2;
      Bu[(int32_T)ic_idx_3 - 1] = Bu_idx_3;
      if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 240,
          &lb_emlrtBCI, &st);
      }

      if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 240,
          &lb_emlrtBCI, &st);
      }

      ExitFlag = Bu[(int32_T)(ic_idx_1 + 4.0) - 1] + runtimedata.lastMV[1];
      if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 240,
          &lb_emlrtBCI, &st);
      }

      Bu_idx_2 = Bu[(int32_T)(ic_idx_2 + 4.0) - 1] + runtimedata.lastMV[2];
      if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 240,
          &lb_emlrtBCI, &st);
      }

      Bu_idx_3 = Bu[(int32_T)(ic_idx_3 + 4.0) - 1] + runtimedata.lastMV[3];
      if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 240,
          &mb_emlrtBCI, &st);
      }

      Bu[(int32_T)(ic_idx_0 + 4.0) - 1] += runtimedata.lastMV[0];
      if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 240,
          &mb_emlrtBCI, &st);
      }

      Bu[(int32_T)(ic_idx_1 + 4.0) - 1] = ExitFlag;
      if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 240,
          &mb_emlrtBCI, &st);
      }

      Bu[(int32_T)(ic_idx_2 + 4.0) - 1] = Bu_idx_2;
      if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 240))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 240,
          &mb_emlrtBCI, &st);
      }

      Bu[(int32_T)(ic_idx_3 + 4.0) - 1] = Bu_idx_3;
    } else {
      Au_tmp = 960 * (b_i - 1);
      for (i = 0; i < 4; i++) {
        idx = i << 2;
        Au[(((int32_T)ic_idx_0 + 240 * i) + Au_tmp) - 1] = As[idx];
        Au[(((int32_T)ic_idx_1 + 240 * i) + Au_tmp) - 1] = As[idx + 1];
        Au[(((int32_T)ic_idx_2 + 240 * i) + Au_tmp) - 1] = As[idx + 2];
        Au[(((int32_T)ic_idx_3 + 240 * i) + Au_tmp) - 1] = As[idx + 3];
      }

      Au_tmp = 960 * (b_i - 1);
      for (i = 0; i < 4; i++) {
        if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 240))
        {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 240,
            &kb_emlrtBCI, &st);
        }

        idx = i << 2;
        Au[(((int32_T)(ic_idx_0 + 4.0) + 240 * i) + Au_tmp) - 1] = (int8_T)
          -As[idx];
        if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 240))
        {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 240,
            &kb_emlrtBCI, &st);
        }

        Au[(((int32_T)(ic_idx_1 + 4.0) + 240 * i) + Au_tmp) - 1] = (int8_T)
          -As[idx + 1];
        if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 240))
        {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 240,
            &kb_emlrtBCI, &st);
        }

        Au[(((int32_T)(ic_idx_2 + 4.0) + 240 * i) + Au_tmp) - 1] = (int8_T)
          -As[idx + 2];
        if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 240))
        {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 240,
            &kb_emlrtBCI, &st);
        }

        Au[(((int32_T)(ic_idx_3 + 4.0) + 240 * i) + Au_tmp) - 1] = (int8_T)
          -As[idx + 3];
      }
    }

    ic_idx_0 += 16.0;
    ic_idx_1 += 16.0;
    ic_idx_2 += 16.0;
    ic_idx_3 += 16.0;
  }

  b_st.site = &u_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  idx = 0;
  Au_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (Au_tmp < 240)) {
    if (icf[Au_tmp]) {
      idx++;
      ii_data[idx - 1] = (uint8_T)(Au_tmp + 1);
      if (idx >= 240) {
        exitg1 = true;
      } else {
        Au_tmp++;
      }
    } else {
      Au_tmp++;
    }
  }

  if (1 > idx) {
    loop_ub = 0;
  } else {
    loop_ub = idx;
  }

  indexShapeCheck();
  if (1 > idx) {
    ii_size_idx_0 = 0;
  } else {
    ii_size_idx_0 = idx;
  }

  if (loop_ub > 0) {
    B_size[0] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      B_data[i] = Bu[ii_data[i] - 1];
    }

    for (idx = 0; idx < 15; idx++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        if (b_i + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, loop_ub, &nb_emlrtBCI, &st);
        }

        SD->f10.Auf_data[b_i + loop_ub * 4 * idx] = Au[(ii_data[b_i] + 960 * idx)
          - 1];
      }
    }

    for (idx = 0; idx < 15; idx++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        if (b_i + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, loop_ub, &nb_emlrtBCI, &st);
        }

        SD->f10.Auf_data[(b_i + loop_ub) + loop_ub * 4 * idx] = Au[(ii_data[b_i]
          + 960 * idx) + 239];
      }
    }

    for (idx = 0; idx < 15; idx++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        if (b_i + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, loop_ub, &nb_emlrtBCI, &st);
        }

        SD->f10.Auf_data[(b_i + loop_ub * 2) + loop_ub * 4 * idx] = Au
          [(ii_data[b_i] + 960 * idx) + 479];
      }
    }

    for (idx = 0; idx < 15; idx++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        if (b_i + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, loop_ub, &nb_emlrtBCI, &st);
        }

        SD->f10.Auf_data[(b_i + loop_ub * 3) + loop_ub * 4 * idx] = Au
          [(ii_data[b_i] + 960 * idx) + 719];
      }
    }

    b_st.site = &v_emlrtRSI;
    idx = (loop_ub << 2) * 15;
    c_st.site = &bb_emlrtRSI;
    computeDimsData(&c_st, loop_ub);
    Au_tmp = loop_ub;
    if (4 > loop_ub) {
      Au_tmp = 4;
    }

    if (15 > Au_tmp) {
      Au_tmp = 15;
    }

    if (loop_ub > muIntScalarMax_sint32(idx, Au_tmp)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (loop_ub * 60 != idx) {
      emlrtErrorWithMessageIdR2018a(&b_st, &n_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    b_st.site = &v_emlrtRSI;
    ii[0] = loop_ub;
    ii[1] = 60;
    c_st.site = &r_emlrtRSI;
    mtimes(SD->f10.Auf_data, ii, SD->f10.y_data, y_size);
    b_st.site = &v_emlrtRSI;
    c_st.site = &eb_emlrtRSI;
    d_st.site = &fb_emlrtRSI;
    if (y_size[0] != ii_size_idx_0) {
      emlrtErrorWithMessageIdR2018a(&d_st, &l_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    A_size[0] = ii_size_idx_0;
    A_size[1] = 241;
    for (i = 0; i < 180; i++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        SD->f10.A_data[b_i + ii_size_idx_0 * i] = 0.0;
      }
    }

    for (i = 0; i < 60; i++) {
      for (b_i = 0; b_i < ii_size_idx_0; b_i++) {
        SD->f10.A_data[b_i + ii_size_idx_0 * (i + 180)] = SD->f10.y_data[b_i +
          y_size[0] * i];
      }
    }

    if (0 <= loop_ub - 1) {
      memset(&SD->f10.A_data[ii_size_idx_0 * 240], 0, ((loop_ub + ii_size_idx_0 *
               240) - ii_size_idx_0 * 240) * sizeof(real_T));
    }
  } else {
    B_size[0] = 0;
    A_size[0] = 0;
    A_size[1] = 241;
  }

  memcpy(&expl_temp.MVScaledTarget[0], &runtimedata.MVScaledTarget[0], 60U *
         sizeof(real_T));
  memcpy(&expl_temp.MVRateMax[0], &runtimedata.MVRateMax[0], 60U * sizeof(real_T));
  memcpy(&expl_temp.MVRateMin[0], &runtimedata.MVRateMin[0], 60U * sizeof(real_T));
  memcpy(&expl_temp.MVMax[0], &runtimedata.MVMax[0], 60U * sizeof(real_T));
  memcpy(&expl_temp.MVMin[0], &runtimedata.MVMin[0], 60U * sizeof(real_T));
  memcpy(&expl_temp.StateMax[0], &runtimedata.StateMax[0], 180U * sizeof(real_T));
  memcpy(&expl_temp.StateMin[0], &runtimedata.StateMin[0], 180U * sizeof(real_T));
  expl_temp.ECRWeight = runtimedata.ECRWeight;
  memcpy(&expl_temp.OutputMax[0], &runtimedata.OutputMax[0], 60U * sizeof(real_T));
  memcpy(&expl_temp.OutputMin[0], &runtimedata.OutputMin[0], 60U * sizeof(real_T));
  memcpy(&expl_temp.MVRateWeights[0], &runtimedata.MVRateWeights[0], 60U *
         sizeof(real_T));
  memcpy(&expl_temp.MVWeights[0], &runtimedata.MVWeights[0], 60U * sizeof(real_T));
  memcpy(&expl_temp.OutputWeights[0], &runtimedata.OutputWeights[0], 60U *
         sizeof(real_T));
  memcpy(&expl_temp.ref[0], &runtimedata.ref[0], 60U * sizeof(real_T));
  expl_temp.lastMV[0] = runtimedata.lastMV[0];
  expl_temp.lastMV[1] = runtimedata.lastMV[1];
  expl_temp.lastMV[2] = runtimedata.lastMV[2];
  expl_temp.lastMV[3] = runtimedata.lastMV[3];
  memcpy(&expl_temp.x[0], &runtimedata.x[0], 12U * sizeof(real_T));
  memcpy(&b_expl_temp.MVScaledTarget[0], &runtimedata.MVScaledTarget[0], 60U *
         sizeof(real_T));
  memcpy(&b_expl_temp.MVRateMax[0], &runtimedata.MVRateMax[0], 60U * sizeof
         (real_T));
  memcpy(&b_expl_temp.MVRateMin[0], &runtimedata.MVRateMin[0], 60U * sizeof
         (real_T));
  memcpy(&b_expl_temp.MVMax[0], &runtimedata.MVMax[0], 60U * sizeof(real_T));
  memcpy(&b_expl_temp.MVMin[0], &runtimedata.MVMin[0], 60U * sizeof(real_T));
  memcpy(&b_expl_temp.StateMax[0], &runtimedata.StateMax[0], 180U * sizeof
         (real_T));
  memcpy(&b_expl_temp.StateMin[0], &runtimedata.StateMin[0], 180U * sizeof
         (real_T));
  b_expl_temp.ECRWeight = runtimedata.ECRWeight;
  memcpy(&b_expl_temp.OutputMax[0], &runtimedata.OutputMax[0], 60U * sizeof
         (real_T));
  memcpy(&b_expl_temp.OutputMin[0], &runtimedata.OutputMin[0], 60U * sizeof
         (real_T));
  memcpy(&b_expl_temp.MVRateWeights[0], &runtimedata.MVRateWeights[0], 60U *
         sizeof(real_T));
  memcpy(&b_expl_temp.MVWeights[0], &runtimedata.MVWeights[0], 60U * sizeof
         (real_T));
  memcpy(&b_expl_temp.OutputWeights[0], &runtimedata.OutputWeights[0], 60U *
         sizeof(real_T));
  memcpy(&b_expl_temp.ref[0], &runtimedata.ref[0], 60U * sizeof(real_T));
  b_expl_temp.lastMV[0] = runtimedata.lastMV[0];
  b_expl_temp.lastMV[1] = runtimedata.lastMV[1];
  b_expl_temp.lastMV[2] = runtimedata.lastMV[2];
  b_expl_temp.lastMV[3] = runtimedata.lastMV[3];
  memcpy(&b_expl_temp.x[0], &runtimedata.x[0], 12U * sizeof(real_T));
  for (i = 0; i < 15; i++) {
    for (b_i = 0; b_i < 12; b_i++) {
      idx = i + 15 * b_i;
      Au_tmp = b_i + 12 * i;
      c_runtimedata[Au_tmp] = runtimedata.StateMin[idx];
      e_runtimedata[Au_tmp] = runtimedata.StateMax[idx];
    }
  }

  memcpy(&b_runtimedata[0], &c_runtimedata[0], 180U * sizeof(real_T));
  for (i = 0; i < 60; i++) {
    b_runtimedata[i + 180] = rtMinusInf;
  }

  b_runtimedata[240] = 0.0;
  memcpy(&d_runtimedata[0], &e_runtimedata[0], 180U * sizeof(real_T));
  for (i = 0; i < 60; i++) {
    d_runtimedata[i + 180] = rtInf;
  }

  d_runtimedata[240] = rtInf;
  st.site = &e_emlrtRSI;
  fmincon(SD, &st, &expl_temp, &CostFcn_tunableEnvironment_f2, z0,
          SD->f10.A_data, A_size, B_data, B_size, b_runtimedata, d_runtimedata,
          &b_expl_temp, &CostFcn_tunableEnvironment_f2, z, &info->Cost,
          &ExitFlag, &Out);
  if ((ExitFlag == 0.0) && (Out.constrviolation > 1.0E-6)) {
    ExitFlag = -2.0;
  }

  st.site = &f_emlrtRSI;
  znlmpc_getXUe(z, x, info->Xopt, info->MVopt, &Bu_idx_2);
  if ((ExitFlag > 0.0) || (ExitFlag == 0.0)) {
    mv[0] = info->MVopt[0];
    mv[1] = info->MVopt[16];
    mv[2] = info->MVopt[32];
    mv[3] = info->MVopt[48];
  } else {
    mv[0] = lastMV[0];
    mv[1] = lastMV[1];
    mv[2] = lastMV[2];
    mv[3] = lastMV[3];
  }

  info->ExitFlag = ExitFlag;
  info->Iterations = Out.iterations;
  for (i = 0; i < 4; i++) {
    memcpy(&onlinedata->MV0[i * 15], &info->MVopt[i * 16 + 1], 15U * sizeof
           (real_T));
  }

  for (i = 0; i < 12; i++) {
    for (b_i = 0; b_i < 15; b_i++) {
      onlinedata->X0[b_i + 15 * i] = info->Xopt[iv[b_i] + (i << 4)];
    }
  }

  onlinedata->Slack0 = muDoubleScalarMax(0.0, Bu_idx_2);
  for (idx = 0; idx < 16; idx++) {
    /* OUTPUT_FCN */
    /*     H = OUTPUT_FCN(IN1,IN2) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
    /*     04-Jul-2022 15:43:18 */
    info->Yopt[idx] = info->Xopt[idx];
    info->Yopt[idx + 16] = info->Xopt[idx + 16];
    info->Yopt[idx + 32] = info->Xopt[idx + 32];
    info->Yopt[idx + 48] = info->Xopt[idx + 128];
    info->Topt[idx] = 0.2 * (real_T)idx;
  }

  info->Slack = Bu_idx_2;
}

/* End of code generation (nlmpcmoveCodeGeneration.c) */
