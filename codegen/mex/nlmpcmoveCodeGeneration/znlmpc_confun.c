/*
 * znlmpc_confun.c
 *
 * Code generation for function 'znlmpc_confun'
 *
 */

/* Include files */
#include "znlmpc_confun.h"
#include "all.h"
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "state_fcn.h"
#include "state_jacob_fcn.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ec_emlrtRSI = { 25, /* lineNo */
  "znlmpc_reformJacobian",             /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_reformJacobian.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 88, /* lineNo */
  "outputBounds",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 168,/* lineNo */
  "outputBounds",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m"/* pathName */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  240,                                 /* iLast */
  215,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "stateEvolution",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  160,                                 /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "outputBounds",                      /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  160,                                 /* iLast */
  117,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "outputBounds",                      /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  160,                                 /* iLast */
  118,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "outputBounds",                      /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { 1,   /* iFirst */
  160,                                 /* iLast */
  145,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "outputBounds",                      /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { 1,   /* iFirst */
  160,                                 /* iLast */
  155,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "outputBounds",                      /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  160,                                 /* iLast */
  158,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "outputBounds",                      /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_confun.m",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void outputBounds(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
                  const real_T runtimedata_OutputMin[80], const real_T
                  runtimedata_OutputMax[80], const real_T X[252], real_T e,
                  real_T c_data[], int32_T c_size[2], real_T Jc_data[], int32_T
                  Jc_size[2])
{
  static const int8_T Ck[48] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const int8_T val[48] = { -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_c_data[160];
  real_T c[160];
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T yk_idx_0;
  real_T yk_idx_1;
  real_T yk_idx_2;
  real_T yk_idx_3;
  int32_T tmp_size[2];
  int32_T y_size[2];
  int32_T b_i;
  int32_T b_input_sizes_idx_0;
  int32_T i;
  int32_T i1;
  int32_T maxdimlen;
  int32_T nx;
  int32_T trueCount;
  int8_T Jx_data[38400];
  int8_T Je[160];
  int8_T Je_data[160];
  int8_T input_sizes_idx_0;
  int8_T sizes_idx_0;
  uint8_T b_tmp_data[160];
  uint8_T tmp_data[160];
  uint8_T ic[8];
  uint8_T ic_idx_0;
  uint8_T ic_idx_1;
  uint8_T ic_idx_2;
  uint8_T ic_idx_3;
  boolean_T icf[160];
  boolean_T bv[80];
  boolean_T x[4];
  boolean_T empty_non_axis_sizes;
  boolean_T exitg1;
  boolean_T guard1 = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  for (i = 0; i < 80; i++) {
    bv[i] = muDoubleScalarIsInf(runtimedata_OutputMin[i]);
  }

  st.site = &fc_emlrtRSI;
  b_all(bv, x);
  empty_non_axis_sizes = true;
  nx = 0;
  exitg1 = false;
  while ((!exitg1) && (nx < 4)) {
    if (!x[nx]) {
      empty_non_axis_sizes = false;
      exitg1 = true;
    } else {
      nx++;
    }
  }

  guard1 = false;
  if (empty_non_axis_sizes) {
    for (i = 0; i < 80; i++) {
      bv[i] = muDoubleScalarIsInf(runtimedata_OutputMax[i]);
    }

    st.site = &fc_emlrtRSI;
    b_all(bv, x);
    empty_non_axis_sizes = true;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 4)) {
      if (!x[nx]) {
        empty_non_axis_sizes = false;
        exitg1 = true;
      } else {
        nx++;
      }
    }

    if (empty_non_axis_sizes) {
      c_size[0] = 0;
      c_size[1] = 0;
      Jc_size[0] = 0;
      Jc_size[1] = 0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    for (b_i = 0; b_i < 160; b_i++) {
      c[b_i] = 0.0;
      icf[b_i] = true;
    }

    memset(&SD->u1.f0.Jx[0], 0, 38400U * sizeof(int8_T));
    memset(&Je[0], 0, 160U * sizeof(int8_T));
    ic_idx_0 = 1U;
    ic_idx_1 = 2U;
    ic_idx_2 = 3U;
    ic_idx_3 = 4U;
    for (b_i = 0; b_i < 20; b_i++) {
      yk_idx_0 = runtimedata_OutputMin[b_i];
      d = runtimedata_OutputMin[b_i + 20];
      d1 = runtimedata_OutputMin[b_i + 40];
      d2 = runtimedata_OutputMin[b_i + 60];
      if (ic_idx_0 > 160) {
        emlrtDynamicBoundsCheckR2012b(ic_idx_0, 1, 160, &t_emlrtBCI, sp);
      }

      icf[ic_idx_0 - 1] = ((!muDoubleScalarIsInf(yk_idx_0)) &&
                           (!muDoubleScalarIsNaN(yk_idx_0)));
      if (ic_idx_1 > 160) {
        emlrtDynamicBoundsCheckR2012b(ic_idx_1, 1, 160, &t_emlrtBCI, sp);
      }

      icf[ic_idx_1 - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      if (ic_idx_2 > 160) {
        emlrtDynamicBoundsCheckR2012b(ic_idx_2, 1, 160, &t_emlrtBCI, sp);
      }

      icf[ic_idx_2 - 1] = ((!muDoubleScalarIsInf(d1)) && (!muDoubleScalarIsNaN
        (d1)));
      if (ic_idx_3 > 160) {
        emlrtDynamicBoundsCheckR2012b(ic_idx_3, 1, 160, &t_emlrtBCI, sp);
      }

      icf[ic_idx_3 - 1] = ((!muDoubleScalarIsInf(d2)) && (!muDoubleScalarIsNaN
        (d2)));
      yk_idx_0 = runtimedata_OutputMax[b_i];
      d3 = runtimedata_OutputMax[b_i + 20];
      d4 = runtimedata_OutputMax[b_i + 40];
      d5 = runtimedata_OutputMax[b_i + 60];
      if (ic_idx_0 + 4 > 160) {
        emlrtDynamicBoundsCheckR2012b(ic_idx_0 + 4, 1, 160, &u_emlrtBCI, sp);
      }

      icf[ic_idx_0 + 3] = ((!muDoubleScalarIsInf(yk_idx_0)) &&
                           (!muDoubleScalarIsNaN(yk_idx_0)));
      if (ic_idx_1 + 4 > 160) {
        emlrtDynamicBoundsCheckR2012b(ic_idx_1 + 4, 1, 160, &u_emlrtBCI, sp);
      }

      icf[ic_idx_1 + 3] = ((!muDoubleScalarIsInf(d3)) && (!muDoubleScalarIsNaN
        (d3)));
      if (ic_idx_2 + 4 > 160) {
        emlrtDynamicBoundsCheckR2012b(ic_idx_2 + 4, 1, 160, &u_emlrtBCI, sp);
      }

      icf[ic_idx_2 + 3] = ((!muDoubleScalarIsInf(d4)) && (!muDoubleScalarIsNaN
        (d4)));
      if (ic_idx_3 + 4 > 160) {
        emlrtDynamicBoundsCheckR2012b(ic_idx_3 + 4, 1, 160, &u_emlrtBCI, sp);
      }

      icf[ic_idx_3 + 3] = ((!muDoubleScalarIsInf(d5)) && (!muDoubleScalarIsNaN
        (d5)));
      if ((int32_T)(ic_idx_0 + 4U) > 160) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_0 + 4U), 1, 160,
          &v_emlrtBCI, sp);
      }

      if ((int32_T)(ic_idx_1 + 4U) > 160) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_1 + 4U), 1, 160,
          &v_emlrtBCI, sp);
      }

      if ((int32_T)(ic_idx_2 + 4U) > 160) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_2 + 4U), 1, 160,
          &v_emlrtBCI, sp);
      }

      if ((int32_T)(ic_idx_3 + 4U) > 160) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ic_idx_3 + 4U), 1, 160,
          &v_emlrtBCI, sp);
      }

      empty_non_axis_sizes = false;
      nx = 0;
      exitg1 = false;
      while ((!exitg1) && (nx <= 7)) {
        ic[0] = (uint8_T)(ic_idx_0 - 1);
        ic[4] = (uint8_T)(ic_idx_0 + 3);
        ic[1] = (uint8_T)(ic_idx_1 - 1);
        ic[5] = (uint8_T)(ic_idx_1 + 3);
        ic[2] = (uint8_T)(ic_idx_2 - 1);
        ic[6] = (uint8_T)(ic_idx_2 + 3);
        ic[3] = (uint8_T)(ic_idx_3 - 1);
        ic[7] = (uint8_T)(ic_idx_3 + 3);
        if (!icf[ic[nx]]) {
          nx++;
        } else {
          empty_non_axis_sizes = true;
          exitg1 = true;
        }
      }

      if (empty_non_axis_sizes) {
        /* OUTPUT_FCN */
        /*     H = OUTPUT_FCN(IN1,IN2) */
        /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
        /*     01-Jul-2022 08:01:35 */
        yk_idx_0 = X[b_i + 1];
        yk_idx_1 = X[b_i + 22];
        yk_idx_2 = X[b_i + 43];
        yk_idx_3 = X[b_i + 169];
        c[ic_idx_0 - 1] = (runtimedata_OutputMin[b_i] - e) - yk_idx_0;
        c[ic_idx_1 - 1] = (d - e) - yk_idx_1;
        c[ic_idx_2 - 1] = (d1 - e) - yk_idx_2;
        c[ic_idx_3 - 1] = (d2 - e) - yk_idx_3;
        if (ic_idx_0 + 4 > 160) {
          emlrtDynamicBoundsCheckR2012b(ic_idx_0 + 4, 1, 160, &w_emlrtBCI, sp);
        }

        c[ic_idx_0 + 3] = (yk_idx_0 - runtimedata_OutputMax[b_i]) - e;
        if (ic_idx_1 + 4 > 160) {
          emlrtDynamicBoundsCheckR2012b(ic_idx_1 + 4, 1, 160, &w_emlrtBCI, sp);
        }

        c[ic_idx_1 + 3] = (yk_idx_1 - d3) - e;
        if (ic_idx_2 + 4 > 160) {
          emlrtDynamicBoundsCheckR2012b(ic_idx_2 + 4, 1, 160, &w_emlrtBCI, sp);
        }

        c[ic_idx_2 + 3] = (yk_idx_2 - d4) - e;
        if (ic_idx_3 + 4 > 160) {
          emlrtDynamicBoundsCheckR2012b(ic_idx_3 + 4, 1, 160, &w_emlrtBCI, sp);
        }

        c[ic_idx_3 + 3] = (yk_idx_3 - d5) - e;
        for (nx = 0; nx < 12; nx++) {
          maxdimlen = nx << 2;
          SD->u1.f0.Jx[((ic_idx_0 + 160 * nx) + 1920 * b_i) - 1] = val[maxdimlen];
          SD->u1.f0.Jx[((ic_idx_1 + 160 * nx) + 1920 * b_i) - 1] = val[maxdimlen
            + 1];
          SD->u1.f0.Jx[((ic_idx_2 + 160 * nx) + 1920 * b_i) - 1] = val[maxdimlen
            + 2];
          SD->u1.f0.Jx[((ic_idx_3 + 160 * nx) + 1920 * b_i) - 1] = val[maxdimlen
            + 3];
        }

        for (nx = 0; nx < 12; nx++) {
          if (ic_idx_0 + 4 > 160) {
            emlrtDynamicBoundsCheckR2012b(ic_idx_0 + 4, 1, 160, &x_emlrtBCI, sp);
          }

          maxdimlen = nx << 2;
          SD->u1.f0.Jx[((ic_idx_0 + 160 * nx) + 1920 * b_i) + 3] = Ck[maxdimlen];
          if (ic_idx_1 + 4 > 160) {
            emlrtDynamicBoundsCheckR2012b(ic_idx_1 + 4, 1, 160, &x_emlrtBCI, sp);
          }

          SD->u1.f0.Jx[((ic_idx_1 + 160 * nx) + 1920 * b_i) + 3] = Ck[maxdimlen
            + 1];
          if (ic_idx_2 + 4 > 160) {
            emlrtDynamicBoundsCheckR2012b(ic_idx_2 + 4, 1, 160, &x_emlrtBCI, sp);
          }

          SD->u1.f0.Jx[((ic_idx_2 + 160 * nx) + 1920 * b_i) + 3] = Ck[maxdimlen
            + 2];
          if (ic_idx_3 + 4 > 160) {
            emlrtDynamicBoundsCheckR2012b(ic_idx_3 + 4, 1, 160, &x_emlrtBCI, sp);
          }

          SD->u1.f0.Jx[((ic_idx_3 + 160 * nx) + 1920 * b_i) + 3] = Ck[maxdimlen
            + 3];
        }

        Je[ic_idx_0 - 1] = -1;
        Je[ic_idx_1 - 1] = -1;
        Je[ic_idx_2 - 1] = -1;
        Je[ic_idx_3 - 1] = -1;
        if (ic_idx_0 + 4 > 160) {
          emlrtDynamicBoundsCheckR2012b(ic_idx_0 + 4, 1, 160, &y_emlrtBCI, sp);
        }

        Je[ic_idx_0 + 3] = -1;
        if (ic_idx_1 + 4 > 160) {
          emlrtDynamicBoundsCheckR2012b(ic_idx_1 + 4, 1, 160, &y_emlrtBCI, sp);
        }

        Je[ic_idx_1 + 3] = -1;
        if (ic_idx_2 + 4 > 160) {
          emlrtDynamicBoundsCheckR2012b(ic_idx_2 + 4, 1, 160, &y_emlrtBCI, sp);
        }

        Je[ic_idx_2 + 3] = -1;
        if (ic_idx_3 + 4 > 160) {
          emlrtDynamicBoundsCheckR2012b(ic_idx_3 + 4, 1, 160, &y_emlrtBCI, sp);
        }

        Je[ic_idx_3 + 3] = -1;
      }

      ic_idx_0 = (uint8_T)(ic_idx_0 + 8U);
      ic_idx_1 = (uint8_T)(ic_idx_1 + 8U);
      ic_idx_2 = (uint8_T)(ic_idx_2 + 8U);
      ic_idx_3 = (uint8_T)(ic_idx_3 + 8U);
    }

    trueCount = 0;
    maxdimlen = 0;
    for (b_i = 0; b_i < 160; b_i++) {
      if (icf[b_i]) {
        trueCount++;
        tmp_data[maxdimlen] = (uint8_T)(b_i + 1);
        maxdimlen++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      b_c_data[i] = c[tmp_data[i] - 1];
    }

    c_size[0] = trueCount;
    c_size[1] = 1;
    if (0 <= trueCount - 1) {
      memcpy(&c_data[0], &b_c_data[0], trueCount * sizeof(real_T));
    }

    trueCount = 0;
    maxdimlen = 0;
    for (b_i = 0; b_i < 160; b_i++) {
      if (icf[b_i]) {
        trueCount++;
        b_tmp_data[maxdimlen] = (uint8_T)(b_i + 1);
        maxdimlen++;
      }
    }

    st.site = &gc_emlrtRSI;
    if (trueCount == 0) {
      Jc_size[0] = 0;
      Jc_size[1] = 0;
    } else {
      b_st.site = &ec_emlrtRSI;
      nx = trueCount * 12 * 20;
      c_st.site = &bb_emlrtRSI;
      computeDimsData(&c_st, trueCount);
      maxdimlen = trueCount;
      if (12 > trueCount) {
        maxdimlen = 12;
      }

      if (20 > maxdimlen) {
        maxdimlen = 20;
      }

      maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
      if (trueCount > maxdimlen) {
        emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
          "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }

      if (240 > maxdimlen) {
        emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
          "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }

      if (trueCount * 240 != nx) {
        emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
          "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
      }

      b_st.site = &ec_emlrtRSI;
      nx = (trueCount << 2) * 20;
      c_st.site = &bb_emlrtRSI;
      computeDimsData(&c_st, trueCount);
      maxdimlen = trueCount;
      if (4 > trueCount) {
        maxdimlen = 4;
      }

      if (20 > maxdimlen) {
        maxdimlen = 20;
      }

      maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
      if (trueCount > maxdimlen) {
        emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
          "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }

      if (80 > maxdimlen) {
        emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
          "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }

      if (trueCount * 80 != nx) {
        emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
          "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
      }

      b_st.site = &ec_emlrtRSI;
      tmp_size[0] = trueCount;
      tmp_size[1] = 80;
      nx = trueCount * 80;
      if (0 <= nx - 1) {
        memset(&SD->u1.f0.tmp_data[0], 0, nx * sizeof(real_T));
      }

      c_st.site = &r_emlrtRSI;
      mtimes(SD->u1.f0.tmp_data, tmp_size, SD->u1.f0.y_data, y_size);
      b_st.site = &ec_emlrtRSI;
      for (i = 0; i < 20; i++) {
        for (i1 = 0; i1 < 12; i1++) {
          for (maxdimlen = 0; maxdimlen < trueCount; maxdimlen++) {
            Jx_data[(maxdimlen + trueCount * i1) + trueCount * 12 * i] =
              SD->u1.f0.Jx[((b_tmp_data[maxdimlen] + 160 * i1) + 1920 * i) - 1];
          }
        }
      }

      for (i = 0; i < trueCount; i++) {
        for (i1 = 0; i1 < 240; i1++) {
          SD->u1.f0.Jx[i1 + 240 * i] = Jx_data[i + trueCount * i1];
        }
      }

      nx = y_size[0];
      for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < 80; i1++) {
          SD->u1.f0.varargin_2_data[i1 + 80 * i] = SD->u1.f0.y_data[i + y_size[0]
            * i1];
        }
      }

      c_st.site = &eb_emlrtRSI;
      if (trueCount != 0) {
        b_i = trueCount;
      } else if (y_size[0] != 0) {
        b_i = y_size[0];
      } else if ((uint8_T)trueCount != 0) {
        b_i = (uint8_T)trueCount;
      } else {
        b_i = 0;
        if ((uint8_T)trueCount > 0) {
          b_i = (uint8_T)trueCount;
        }
      }

      d_st.site = &fb_emlrtRSI;
      if ((trueCount != b_i) && (trueCount != 0)) {
        emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      if ((y_size[0] != b_i) && (y_size[0] != 0)) {
        emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      if (((uint8_T)trueCount != b_i) && ((uint8_T)trueCount != 0)) {
        emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      empty_non_axis_sizes = (b_i == 0);
      if (empty_non_axis_sizes || (trueCount != 0)) {
        ic_idx_0 = 240U;
      } else {
        ic_idx_0 = 0U;
      }

      if (empty_non_axis_sizes || (y_size[0] != 0)) {
        input_sizes_idx_0 = 80;
      } else {
        input_sizes_idx_0 = 0;
      }

      if (empty_non_axis_sizes || ((uint8_T)trueCount != 0)) {
        sizes_idx_0 = 1;
      } else {
        sizes_idx_0 = 0;
      }

      b_input_sizes_idx_0 = input_sizes_idx_0;
      for (i = 0; i < trueCount; i++) {
        Je_data[i] = Je[b_tmp_data[i] - 1];
      }

      maxdimlen = ic_idx_0 + input_sizes_idx_0;
      Jc_size[0] = maxdimlen + sizes_idx_0;
      Jc_size[1] = b_i;
      for (i = 0; i < b_i; i++) {
        nx = ic_idx_0;
        for (i1 = 0; i1 < nx; i1++) {
          Jc_data[i1 + Jc_size[0] * i] = SD->u1.f0.Jx[i1 + 240 * i];
        }
      }

      for (i = 0; i < b_i; i++) {
        for (i1 = 0; i1 < b_input_sizes_idx_0; i1++) {
          Jc_data[(i1 + ic_idx_0) + Jc_size[0] * i] = SD->
            u1.f0.varargin_2_data[i1 + 80 * i];
        }
      }

      for (i = 0; i < b_i; i++) {
        nx = sizes_idx_0;
        if (0 <= nx - 1) {
          Jc_data[maxdimlen + Jc_size[0] * i] = Je_data[sizes_idx_0 * i];
        }
      }
    }
  }
}

void stateEvolution(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
                    const real_T X[252], const real_T U[84], real_T c[240],
                    real_T J[77040])
{
  static const real_T a[144] = { 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1 };

  static const real_T b[144] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T Ak1[144];
  real_T val[144];
  real_T y[144];
  real_T Bk[48];
  real_T b_val[48];
  real_T b_X[12];
  real_T b_dv[12];
  real_T dv1[12];
  real_T b_U[4];
  real_T U_tmp;
  real_T alpha1;
  real_T b_U_tmp;
  real_T beta1;
  real_T c_U_tmp;
  real_T d;
  int32_T b_i;
  int32_T i;
  int32_T k;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T Ix[144];
  uint8_T ic[12];
  uint8_T u;
  memset(&SD->u1.f1.Jx[0], 0, 57600U * sizeof(real_T));
  memset(&SD->u1.f1.Jmv[0], 0, 19200U * sizeof(real_T));
  memset(&c[0], 0, 240U * sizeof(real_T));
  for (i = 0; i < 12; i++) {
    ic[i] = (uint8_T)(i + 1U);
  }

  memset(&Ix[0], 0, 144U * sizeof(int8_T));
  for (k = 0; k < 12; k++) {
    Ix[k + 12 * k] = 1;
  }

  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)12;
  n_t = (ptrdiff_t)4;
  k_t = (ptrdiff_t)12;
  lda_t = (ptrdiff_t)12;
  ldb_t = (ptrdiff_t)12;
  ldc_t = (ptrdiff_t)12;
  for (b_i = 0; b_i < 20; b_i++) {
    for (i = 0; i < 12; i++) {
      b_X[i] = X[b_i + 21 * i];
    }

    d = U[b_i];
    b_U[0] = d;
    U_tmp = U[b_i + 21];
    b_U[1] = U_tmp;
    b_U_tmp = U[b_i + 42];
    b_U[2] = b_U_tmp;
    c_U_tmp = U[b_i + 63];
    b_U[3] = c_U_tmp;
    state_jacob_fcn(b_X, b_U, val, Bk);
    for (i = 0; i < 12; i++) {
      b_X[i] = X[(b_i + 21 * i) + 1];
    }

    b_U[0] = d;
    b_U[1] = U_tmp;
    b_U[2] = b_U_tmp;
    b_U[3] = c_U_tmp;
    state_jacob_fcn(b_X, b_U, Ak1, b_val);
    for (i = 0; i < 12; i++) {
      b_X[i] = X[b_i + 21 * i];
    }

    b_U[0] = d;
    b_U[1] = U_tmp;
    b_U[2] = b_U_tmp;
    b_U[3] = c_U_tmp;
    state_fcn(b_X, b_U, b_dv);
    for (i = 0; i < 12; i++) {
      b_X[i] = X[(b_i + 21 * i) + 1];
    }

    b_U[0] = d;
    b_U[1] = U_tmp;
    b_U[2] = b_U_tmp;
    b_U[3] = c_U_tmp;
    state_fcn(b_X, b_U, dv1);
    for (i = 0; i < 12; i++) {
      u = ic[i];
      if ((u < 1) || (u > 240)) {
        emlrtDynamicBoundsCheckR2012b(u, 1, 240, &s_emlrtBCI, sp);
      }

      k = b_i + 21 * i;
      c[ic[i] - 1] = (X[k] + 0.1 * (b_dv[i] + dv1[i])) - X[k + 1];
    }

    if (b_i + 1 > 1) {
      b_mtimes(a, val, y);
      b_mtimes(y, b, val);
      for (i = 0; i < 144; i++) {
        val[i] += (real_T)Ix[i];
      }

      for (k = 0; k < 12; k++) {
        for (i = 0; i < 12; i++) {
          SD->u1.f1.Jx[((ic[i] + 240 * k) + 2880 * (b_i - 1)) - 1] = val[i + 12 *
            k];
        }
      }
    }

    b_mtimes(a, Ak1, y);
    b_mtimes(y, b, val);
    for (i = 0; i < 144; i++) {
      val[i] += -(real_T)Ix[i];
    }

    for (k = 0; k < 12; k++) {
      for (i = 0; i < 12; i++) {
        SD->u1.f1.Jx[((ic[i] + 240 * k) + 2880 * b_i) - 1] = val[i + 12 * k];
      }
    }

    for (i = 0; i < 48; i++) {
      Bk[i] += b_val[i];
    }

    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &Bk[0],
          &ldb_t, &beta1, &b_val[0], &ldc_t);
    for (k = 0; k < 4; k++) {
      for (i = 0; i < 12; i++) {
        SD->u1.f1.Jmv[((ic[i] + 240 * k) + 960 * b_i) - 1] = b_val[i + 12 * k];
      }
    }

    for (i = 0; i < 12; i++) {
      ic[i] = (uint8_T)(ic[i] + 12U);
    }
  }

  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)240;
  n_t = (ptrdiff_t)80;
  k_t = (ptrdiff_t)80;
  lda_t = (ptrdiff_t)240;
  ldb_t = (ptrdiff_t)80;
  ldc_t = (ptrdiff_t)240;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &SD->u1.f1.Jmv[0], &lda_t,
        &dv[0], &ldb_t, &beta1, &SD->u1.f1.y[0], &ldc_t);
  for (i = 0; i < 240; i++) {
    for (k = 0; k < 240; k++) {
      J[k + 321 * i] = SD->u1.f1.Jx[i + 240 * k];
    }

    for (k = 0; k < 80; k++) {
      J[(k + 321 * i) + 240] = SD->u1.f1.y[i + 240 * k];
    }

    J[321 * i + 320] = 0.0;
  }
}

/* End of code generation (znlmpc_confun.c) */
