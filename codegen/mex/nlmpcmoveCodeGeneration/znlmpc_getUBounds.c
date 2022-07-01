/*
 * znlmpc_getUBounds.c
 *
 * Code generation for function 'znlmpc_getUBounds'
 *
 */

/* Include files */
#include "znlmpc_getUBounds.h"
#include "indexShapeCheck.h"
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
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

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  22,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  23,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  24,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  25,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  28,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  29,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  30,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  33,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  34,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  37,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  38,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  39,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  45,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  42,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  320,                                 /* iLast */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "znlmpc_getUBounds",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_getUBounds.m",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void znlmpc_getUBounds(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
  const f_struct_T *runtimedata, real_T A_data[], int32_T A_size[2], real_T
  Bu_data[], int32_T Bu_size[1])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T Bu[320];
  real_T Bu_idx_1;
  real_T Bu_idx_2;
  real_T Bu_idx_3;
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
  int32_T ii[2];
  int32_T y_size[2];
  int32_T Au_tmp;
  int32_T b_i;
  int32_T i;
  int32_T idx;
  int32_T ii_size_idx_0;
  int32_T loop_ub;
  int16_T ii_data[320];
  int8_T Au[25600];
  int8_T As[16];
  boolean_T icf[320];
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  memset(&Au[0], 0, 25600U * sizeof(int8_T));
  memset(&Bu[0], 0, 320U * sizeof(real_T));
  memset(&icf[0], 0, 320U * sizeof(boolean_T));
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
  for (b_i = 0; b_i < 20; b_i++) {
    Bu_idx_1 = runtimedata->MVRateMin[b_i];
    Bu_idx_2 = runtimedata->MVRateMin[b_i + 20];
    Bu_idx_3 = runtimedata->MVRateMin[b_i + 40];
    d = runtimedata->MVRateMin[b_i + 60];
    if (((int32_T)ic_idx_0 < 1) || ((int32_T)ic_idx_0 > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ic_idx_0, 1, 320, &b_emlrtBCI, sp);
    }

    icf[(int32_T)ic_idx_0 - 1] = ((!muDoubleScalarIsInf(Bu_idx_1)) &&
      (!muDoubleScalarIsNaN(Bu_idx_1)));
    if (((int32_T)ic_idx_1 < 1) || ((int32_T)ic_idx_1 > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ic_idx_1, 1, 320, &b_emlrtBCI, sp);
    }

    icf[(int32_T)ic_idx_1 - 1] = ((!muDoubleScalarIsInf(Bu_idx_2)) &&
      (!muDoubleScalarIsNaN(Bu_idx_2)));
    if (((int32_T)ic_idx_2 < 1) || ((int32_T)ic_idx_2 > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ic_idx_2, 1, 320, &b_emlrtBCI, sp);
    }

    icf[(int32_T)ic_idx_2 - 1] = ((!muDoubleScalarIsInf(Bu_idx_3)) &&
      (!muDoubleScalarIsNaN(Bu_idx_3)));
    if (((int32_T)ic_idx_3 < 1) || ((int32_T)ic_idx_3 > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ic_idx_3, 1, 320, &b_emlrtBCI, sp);
    }

    icf[(int32_T)ic_idx_3 - 1] = ((!muDoubleScalarIsInf(d)) &&
      (!muDoubleScalarIsNaN(d)));
    d1 = runtimedata->MVRateMax[b_i];
    d2 = runtimedata->MVRateMax[b_i + 20];
    d3 = runtimedata->MVRateMax[b_i + 40];
    d4 = runtimedata->MVRateMax[b_i + 60];
    if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 320,
        &c_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_0 + 4.0) - 1] = ((!muDoubleScalarIsInf(d1)) &&
      (!muDoubleScalarIsNaN(d1)));
    if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 320,
        &c_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_1 + 4.0) - 1] = ((!muDoubleScalarIsInf(d2)) &&
      (!muDoubleScalarIsNaN(d2)));
    if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 320,
        &c_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_2 + 4.0) - 1] = ((!muDoubleScalarIsInf(d3)) &&
      (!muDoubleScalarIsNaN(d3)));
    if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 320,
        &c_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_3 + 4.0) - 1] = ((!muDoubleScalarIsInf(d4)) &&
      (!muDoubleScalarIsNaN(d4)));
    d5 = runtimedata->MVMin[b_i];
    d6 = runtimedata->MVMin[b_i + 20];
    d7 = runtimedata->MVMin[b_i + 40];
    d8 = runtimedata->MVMin[b_i + 60];
    if (((int32_T)(ic_idx_0 + 8.0) < 1) || ((int32_T)(ic_idx_0 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 8.0), 1, 320,
        &d_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_0 + 8.0) - 1] = ((!muDoubleScalarIsInf(d5)) &&
      (!muDoubleScalarIsNaN(d5)));
    if (((int32_T)(ic_idx_1 + 8.0) < 1) || ((int32_T)(ic_idx_1 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 8.0), 1, 320,
        &d_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_1 + 8.0) - 1] = ((!muDoubleScalarIsInf(d6)) &&
      (!muDoubleScalarIsNaN(d6)));
    if (((int32_T)(ic_idx_2 + 8.0) < 1) || ((int32_T)(ic_idx_2 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 8.0), 1, 320,
        &d_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_2 + 8.0) - 1] = ((!muDoubleScalarIsInf(d7)) &&
      (!muDoubleScalarIsNaN(d7)));
    if (((int32_T)(ic_idx_3 + 8.0) < 1) || ((int32_T)(ic_idx_3 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 8.0), 1, 320,
        &d_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_3 + 8.0) - 1] = ((!muDoubleScalarIsInf(d8)) &&
      (!muDoubleScalarIsNaN(d8)));
    d9 = runtimedata->MVMax[b_i];
    d10 = runtimedata->MVMax[b_i + 20];
    d11 = runtimedata->MVMax[b_i + 40];
    d12 = runtimedata->MVMax[b_i + 60];
    if (((int32_T)(ic_idx_0 + 12.0) < 1) || ((int32_T)(ic_idx_0 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 12.0), 1, 320,
        &e_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_0 + 12.0) - 1] = ((!muDoubleScalarIsInf(d9)) &&
      (!muDoubleScalarIsNaN(d9)));
    if (((int32_T)(ic_idx_1 + 12.0) < 1) || ((int32_T)(ic_idx_1 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 12.0), 1, 320,
        &e_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_1 + 12.0) - 1] = ((!muDoubleScalarIsInf(d10)) &&
      (!muDoubleScalarIsNaN(d10)));
    if (((int32_T)(ic_idx_2 + 12.0) < 1) || ((int32_T)(ic_idx_2 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 12.0), 1, 320,
        &e_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_2 + 12.0) - 1] = ((!muDoubleScalarIsInf(d11)) &&
      (!muDoubleScalarIsNaN(d11)));
    if (((int32_T)(ic_idx_3 + 12.0) < 1) || ((int32_T)(ic_idx_3 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 12.0), 1, 320,
        &e_emlrtBCI, sp);
    }

    icf[(int32_T)(ic_idx_3 + 12.0) - 1] = ((!muDoubleScalarIsInf(d12)) &&
      (!muDoubleScalarIsNaN(d12)));
    for (i = 0; i < 4; i++) {
      Au_tmp = i << 2;
      Au[(((int32_T)ic_idx_0 + 320 * i) + 1280 * b_i) - 1] = (int8_T)-As[Au_tmp];
      Au[(((int32_T)ic_idx_1 + 320 * i) + 1280 * b_i) - 1] = (int8_T)-As[Au_tmp
        + 1];
      Au[(((int32_T)ic_idx_2 + 320 * i) + 1280 * b_i) - 1] = (int8_T)-As[Au_tmp
        + 2];
      Au[(((int32_T)ic_idx_3 + 320 * i) + 1280 * b_i) - 1] = (int8_T)-As[Au_tmp
        + 3];
    }

    for (i = 0; i < 4; i++) {
      if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 320,
          &f_emlrtBCI, sp);
      }

      Au_tmp = i << 2;
      Au[(((int32_T)(ic_idx_0 + 4.0) + 320 * i) + 1280 * b_i) - 1] = As[Au_tmp];
      if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 320,
          &f_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_1 + 4.0) + 320 * i) + 1280 * b_i) - 1] = As[Au_tmp +
        1];
      if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 320,
          &f_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_2 + 4.0) + 320 * i) + 1280 * b_i) - 1] = As[Au_tmp +
        2];
      if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 320,
          &f_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_3 + 4.0) + 320 * i) + 1280 * b_i) - 1] = As[Au_tmp +
        3];
    }

    for (i = 0; i < 4; i++) {
      if (((int32_T)(ic_idx_0 + 8.0) < 1) || ((int32_T)(ic_idx_0 + 8.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 8.0), 1, 320,
          &g_emlrtBCI, sp);
      }

      Au_tmp = i << 2;
      Au[(((int32_T)(ic_idx_0 + 8.0) + 320 * i) + 1280 * b_i) - 1] = (int8_T)
        -As[Au_tmp];
      if (((int32_T)(ic_idx_1 + 8.0) < 1) || ((int32_T)(ic_idx_1 + 8.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 8.0), 1, 320,
          &g_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_1 + 8.0) + 320 * i) + 1280 * b_i) - 1] = (int8_T)
        -As[Au_tmp + 1];
      if (((int32_T)(ic_idx_2 + 8.0) < 1) || ((int32_T)(ic_idx_2 + 8.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 8.0), 1, 320,
          &g_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_2 + 8.0) + 320 * i) + 1280 * b_i) - 1] = (int8_T)
        -As[Au_tmp + 2];
      if (((int32_T)(ic_idx_3 + 8.0) < 1) || ((int32_T)(ic_idx_3 + 8.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 8.0), 1, 320,
          &g_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_3 + 8.0) + 320 * i) + 1280 * b_i) - 1] = (int8_T)
        -As[Au_tmp + 3];
    }

    for (i = 0; i < 4; i++) {
      if (((int32_T)(ic_idx_0 + 12.0) < 1) || ((int32_T)(ic_idx_0 + 12.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 12.0), 1, 320,
          &h_emlrtBCI, sp);
      }

      Au_tmp = i << 2;
      Au[(((int32_T)(ic_idx_0 + 12.0) + 320 * i) + 1280 * b_i) - 1] = As[Au_tmp];
      if (((int32_T)(ic_idx_1 + 12.0) < 1) || ((int32_T)(ic_idx_1 + 12.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 12.0), 1, 320,
          &h_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_1 + 12.0) + 320 * i) + 1280 * b_i) - 1] = As[Au_tmp
        + 1];
      if (((int32_T)(ic_idx_2 + 12.0) < 1) || ((int32_T)(ic_idx_2 + 12.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 12.0), 1, 320,
          &h_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_2 + 12.0) + 320 * i) + 1280 * b_i) - 1] = As[Au_tmp
        + 2];
      if (((int32_T)(ic_idx_3 + 12.0) < 1) || ((int32_T)(ic_idx_3 + 12.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 12.0), 1, 320,
          &h_emlrtBCI, sp);
      }

      Au[(((int32_T)(ic_idx_3 + 12.0) + 320 * i) + 1280 * b_i) - 1] = As[Au_tmp
        + 3];
    }

    if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 320,
        &i_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 320,
        &i_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 320,
        &i_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 320,
        &i_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_0 + 8.0) < 1) || ((int32_T)(ic_idx_0 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 8.0), 1, 320,
        &j_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_1 + 8.0) < 1) || ((int32_T)(ic_idx_1 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 8.0), 1, 320,
        &j_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_2 + 8.0) < 1) || ((int32_T)(ic_idx_2 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 8.0), 1, 320,
        &j_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_3 + 8.0) < 1) || ((int32_T)(ic_idx_3 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 8.0), 1, 320,
        &j_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_0 + 12.0) < 1) || ((int32_T)(ic_idx_0 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 12.0), 1, 320,
        &k_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_1 + 12.0) < 1) || ((int32_T)(ic_idx_1 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 12.0), 1, 320,
        &k_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_2 + 12.0) < 1) || ((int32_T)(ic_idx_2 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 12.0), 1, 320,
        &k_emlrtBCI, sp);
    }

    if (((int32_T)(ic_idx_3 + 12.0) < 1) || ((int32_T)(ic_idx_3 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 12.0), 1, 320,
        &k_emlrtBCI, sp);
    }

    Bu[(int32_T)ic_idx_0 - 1] = -Bu_idx_1;
    Bu[(int32_T)ic_idx_1 - 1] = -Bu_idx_2;
    Bu[(int32_T)ic_idx_2 - 1] = -Bu_idx_3;
    Bu[(int32_T)ic_idx_3 - 1] = -d;
    if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 320,
        &l_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_0 + 4.0) - 1] = d1;
    if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 320,
        &l_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_1 + 4.0) - 1] = d2;
    if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 320,
        &l_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_2 + 4.0) - 1] = d3;
    if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 320,
        &l_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_3 + 4.0) - 1] = d4;
    if (((int32_T)(ic_idx_0 + 8.0) < 1) || ((int32_T)(ic_idx_0 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 8.0), 1, 320,
        &m_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_0 + 8.0) - 1] = -d5;
    if (((int32_T)(ic_idx_1 + 8.0) < 1) || ((int32_T)(ic_idx_1 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 8.0), 1, 320,
        &m_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_1 + 8.0) - 1] = -d6;
    if (((int32_T)(ic_idx_2 + 8.0) < 1) || ((int32_T)(ic_idx_2 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 8.0), 1, 320,
        &m_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_2 + 8.0) - 1] = -d7;
    if (((int32_T)(ic_idx_3 + 8.0) < 1) || ((int32_T)(ic_idx_3 + 8.0) > 320)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 8.0), 1, 320,
        &m_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_3 + 8.0) - 1] = -d8;
    if (((int32_T)(ic_idx_0 + 12.0) < 1) || ((int32_T)(ic_idx_0 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 12.0), 1, 320,
        &n_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_0 + 12.0) - 1] = d9;
    if (((int32_T)(ic_idx_1 + 12.0) < 1) || ((int32_T)(ic_idx_1 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 12.0), 1, 320,
        &n_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_1 + 12.0) - 1] = d10;
    if (((int32_T)(ic_idx_2 + 12.0) < 1) || ((int32_T)(ic_idx_2 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 12.0), 1, 320,
        &n_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_2 + 12.0) - 1] = d11;
    if (((int32_T)(ic_idx_3 + 12.0) < 1) || ((int32_T)(ic_idx_3 + 12.0) > 320))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 12.0), 1, 320,
        &n_emlrtBCI, sp);
    }

    Bu[(int32_T)(ic_idx_3 + 12.0) - 1] = d12;
    if (b_i + 1 == 1) {
      Bu_idx_1 = Bu[(int32_T)ic_idx_1 - 1] - runtimedata->lastMV[1];
      Bu_idx_2 = Bu[(int32_T)ic_idx_2 - 1] - runtimedata->lastMV[2];
      Bu_idx_3 = Bu[(int32_T)ic_idx_3 - 1] - runtimedata->lastMV[3];
      Bu[(int32_T)ic_idx_0 - 1] -= runtimedata->lastMV[0];
      Bu[(int32_T)ic_idx_1 - 1] = Bu_idx_1;
      Bu[(int32_T)ic_idx_2 - 1] = Bu_idx_2;
      Bu[(int32_T)ic_idx_3 - 1] = Bu_idx_3;
      if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 320,
          &p_emlrtBCI, sp);
      }

      if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 320,
          &p_emlrtBCI, sp);
      }

      Bu_idx_1 = Bu[(int32_T)(ic_idx_1 + 4.0) - 1] + runtimedata->lastMV[1];
      if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 320,
          &p_emlrtBCI, sp);
      }

      Bu_idx_2 = Bu[(int32_T)(ic_idx_2 + 4.0) - 1] + runtimedata->lastMV[2];
      if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 320,
          &p_emlrtBCI, sp);
      }

      Bu_idx_3 = Bu[(int32_T)(ic_idx_3 + 4.0) - 1] + runtimedata->lastMV[3];
      if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 320,
          &q_emlrtBCI, sp);
      }

      Bu[(int32_T)(ic_idx_0 + 4.0) - 1] += runtimedata->lastMV[0];
      if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 320,
          &q_emlrtBCI, sp);
      }

      Bu[(int32_T)(ic_idx_1 + 4.0) - 1] = Bu_idx_1;
      if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 320,
          &q_emlrtBCI, sp);
      }

      Bu[(int32_T)(ic_idx_2 + 4.0) - 1] = Bu_idx_2;
      if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 320))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 320,
          &q_emlrtBCI, sp);
      }

      Bu[(int32_T)(ic_idx_3 + 4.0) - 1] = Bu_idx_3;
    } else {
      Au_tmp = 1280 * (b_i - 1);
      for (i = 0; i < 4; i++) {
        idx = i << 2;
        Au[(((int32_T)ic_idx_0 + 320 * i) + Au_tmp) - 1] = As[idx];
        Au[(((int32_T)ic_idx_1 + 320 * i) + Au_tmp) - 1] = As[idx + 1];
        Au[(((int32_T)ic_idx_2 + 320 * i) + Au_tmp) - 1] = As[idx + 2];
        Au[(((int32_T)ic_idx_3 + 320 * i) + Au_tmp) - 1] = As[idx + 3];
      }

      Au_tmp = 1280 * (b_i - 1);
      for (i = 0; i < 4; i++) {
        if (((int32_T)(ic_idx_0 + 4.0) < 1) || ((int32_T)(ic_idx_0 + 4.0) > 320))
        {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4.0), 1, 320,
            &o_emlrtBCI, sp);
        }

        idx = i << 2;
        Au[(((int32_T)(ic_idx_0 + 4.0) + 320 * i) + Au_tmp) - 1] = (int8_T)
          -As[idx];
        if (((int32_T)(ic_idx_1 + 4.0) < 1) || ((int32_T)(ic_idx_1 + 4.0) > 320))
        {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4.0), 1, 320,
            &o_emlrtBCI, sp);
        }

        Au[(((int32_T)(ic_idx_1 + 4.0) + 320 * i) + Au_tmp) - 1] = (int8_T)
          -As[idx + 1];
        if (((int32_T)(ic_idx_2 + 4.0) < 1) || ((int32_T)(ic_idx_2 + 4.0) > 320))
        {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4.0), 1, 320,
            &o_emlrtBCI, sp);
        }

        Au[(((int32_T)(ic_idx_2 + 4.0) + 320 * i) + Au_tmp) - 1] = (int8_T)
          -As[idx + 2];
        if (((int32_T)(ic_idx_3 + 4.0) < 1) || ((int32_T)(ic_idx_3 + 4.0) > 320))
        {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4.0), 1, 320,
            &o_emlrtBCI, sp);
        }

        Au[(((int32_T)(ic_idx_3 + 4.0) + 320 * i) + Au_tmp) - 1] = (int8_T)
          -As[idx + 3];
      }
    }

    ic_idx_0 += 16.0;
    ic_idx_1 += 16.0;
    ic_idx_2 += 16.0;
    ic_idx_3 += 16.0;
  }

  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  idx = 0;
  Au_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (Au_tmp < 320)) {
    if (icf[Au_tmp]) {
      idx++;
      ii_data[idx - 1] = (int16_T)(Au_tmp + 1);
      if (idx >= 320) {
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
    Bu_size[0] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      Bu_data[i] = Bu[ii_data[i] - 1];
    }

    for (idx = 0; idx < 4; idx++) {
      for (Au_tmp = 0; Au_tmp < 20; Au_tmp++) {
        for (b_i = 0; b_i < loop_ub; b_i++) {
          if (b_i + 1 > loop_ub) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, loop_ub, &emlrtBCI, sp);
          }

          SD->u1.f5.Auf_data[(b_i + loop_ub * idx) + loop_ub * 4 * Au_tmp] = Au
            [((ii_data[b_i] + 320 * idx) + 1280 * Au_tmp) - 1];
        }
      }
    }

    st.site = &v_emlrtRSI;
    idx = (loop_ub << 2) * 20;
    b_st.site = &bb_emlrtRSI;
    computeDimsData(&b_st, loop_ub);
    Au_tmp = loop_ub;
    if (4 > loop_ub) {
      Au_tmp = 4;
    }

    if (20 > Au_tmp) {
      Au_tmp = 20;
    }

    if (loop_ub > muIntScalarMax_sint32(idx, Au_tmp)) {
      emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (loop_ub * 80 != idx) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    st.site = &v_emlrtRSI;
    ii[0] = loop_ub;
    ii[1] = 80;
    b_st.site = &r_emlrtRSI;
    mtimes(SD->u1.f5.Auf_data, ii, SD->u1.f5.y_data, y_size);
    st.site = &v_emlrtRSI;
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    if (y_size[0] != ii_size_idx_0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    A_size[0] = ii_size_idx_0;
    A_size[1] = 321;
    for (i = 0; i < 240; i++) {
      for (idx = 0; idx < loop_ub; idx++) {
        A_data[idx + ii_size_idx_0 * i] = 0.0;
      }
    }

    for (i = 0; i < 80; i++) {
      for (idx = 0; idx < ii_size_idx_0; idx++) {
        A_data[idx + ii_size_idx_0 * (i + 240)] = SD->u1.f5.y_data[idx + y_size
          [0] * i];
      }
    }

    if (0 <= loop_ub - 1) {
      memset(&A_data[ii_size_idx_0 * 320], 0, ((loop_ub + ii_size_idx_0 * 320) -
              ii_size_idx_0 * 320) * sizeof(real_T));
    }
  } else {
    Bu_size[0] = 0;
    A_size[0] = 0;
    A_size[1] = 321;
  }
}

/* End of code generation (znlmpc_getUBounds.c) */
