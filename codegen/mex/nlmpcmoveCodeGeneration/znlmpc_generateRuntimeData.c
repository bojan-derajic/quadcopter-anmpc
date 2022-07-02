/*
 * znlmpc_generateRuntimeData.c
 *
 * Code generation for function 'znlmpc_generateRuntimeData'
 *
 */

/* Include files */
#include "znlmpc_generateRuntimeData.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo h_emlrtRSI = { 20,  /* lineNo */
  "znlmpc_generateRuntimeData",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 30,  /* lineNo */
  "znlmpc_generateRuntimeData",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 72,  /* lineNo */
  "znlmpc_generateRuntimeData",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 74,  /* lineNo */
  "znlmpc_generateRuntimeData",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 76,  /* lineNo */
  "znlmpc_generateRuntimeData",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 78,  /* lineNo */
  "znlmpc_generateRuntimeData",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 147, /* lineNo */
  "getInitialX",                       /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 156, /* lineNo */
  "getInitialMV",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 165, /* lineNo */
  "getInitialSlack",                   /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_generateRuntimeData.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 36,  /* lineNo */
  "znlmpc_setDecisions",               /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\mpc\\mpcutils\\znlmpc_setDecisions.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 14,  /* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnegative",               /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnegative.m"/* pName */
};

/* Function Definitions */
void znlmpc_generateRuntimeData(const emlrtStack *sp, const real_T x[12], const
  real_T lastMV[4], const real_T ref0[4], const real_T MVTarget0[4], const
  real_T X0[180], const real_T MV0[60], real_T Slack0, f_struct_T *runtimedata,
  e_struct_T *userdata, real_T z0[241])
{
  static real_T b_dv[180] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static real_T dv1[180] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static real_T dv2[60] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T iv[60] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_X0[180];
  real_T b_MV0[60];
  real_T uz[60];
  real_T alpha1;
  real_T beta1;
  int32_T b_i;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_dv[0U] = rtInf;
  b_dv[1U] = rtInf;
  b_dv[2U] = rtInf;
  b_dv[3U] = rtInf;
  b_dv[4U] = rtInf;
  b_dv[5U] = rtInf;
  b_dv[6U] = rtInf;
  b_dv[7U] = rtInf;
  b_dv[8U] = rtInf;
  b_dv[9U] = rtInf;
  b_dv[10U] = rtInf;
  b_dv[11U] = rtInf;
  b_dv[12U] = rtInf;
  b_dv[13U] = rtInf;
  b_dv[14U] = rtInf;
  b_dv[15U] = rtInf;
  b_dv[16U] = rtInf;
  b_dv[17U] = rtInf;
  b_dv[18U] = rtInf;
  b_dv[19U] = rtInf;
  b_dv[20U] = rtInf;
  b_dv[21U] = rtInf;
  b_dv[22U] = rtInf;
  b_dv[23U] = rtInf;
  b_dv[24U] = rtInf;
  b_dv[25U] = rtInf;
  b_dv[26U] = rtInf;
  b_dv[27U] = rtInf;
  b_dv[28U] = rtInf;
  b_dv[29U] = rtInf;
  b_dv[30U] = rtInf;
  b_dv[31U] = rtInf;
  b_dv[32U] = rtInf;
  b_dv[33U] = rtInf;
  b_dv[34U] = rtInf;
  b_dv[35U] = rtInf;
  b_dv[36U] = rtInf;
  b_dv[37U] = rtInf;
  b_dv[38U] = rtInf;
  b_dv[39U] = rtInf;
  b_dv[40U] = rtInf;
  b_dv[41U] = rtInf;
  b_dv[42U] = rtInf;
  b_dv[43U] = rtInf;
  b_dv[44U] = rtInf;
  b_dv[45U] = rtInf;
  b_dv[46U] = rtInf;
  b_dv[47U] = rtInf;
  b_dv[48U] = rtInf;
  b_dv[49U] = rtInf;
  b_dv[50U] = rtInf;
  b_dv[51U] = rtInf;
  b_dv[52U] = rtInf;
  b_dv[53U] = rtInf;
  b_dv[54U] = rtInf;
  b_dv[55U] = rtInf;
  b_dv[56U] = rtInf;
  b_dv[57U] = rtInf;
  b_dv[58U] = rtInf;
  b_dv[59U] = rtInf;
  b_dv[60U] = rtInf;
  b_dv[61U] = rtInf;
  b_dv[62U] = rtInf;
  b_dv[63U] = rtInf;
  b_dv[64U] = rtInf;
  b_dv[65U] = rtInf;
  b_dv[66U] = rtInf;
  b_dv[67U] = rtInf;
  b_dv[68U] = rtInf;
  b_dv[69U] = rtInf;
  b_dv[70U] = rtInf;
  b_dv[71U] = rtInf;
  b_dv[72U] = rtInf;
  b_dv[73U] = rtInf;
  b_dv[74U] = rtInf;
  b_dv[75U] = rtInf;
  b_dv[76U] = rtInf;
  b_dv[77U] = rtInf;
  b_dv[78U] = rtInf;
  b_dv[79U] = rtInf;
  b_dv[80U] = rtInf;
  b_dv[81U] = rtInf;
  b_dv[82U] = rtInf;
  b_dv[83U] = rtInf;
  b_dv[84U] = rtInf;
  b_dv[85U] = rtInf;
  b_dv[86U] = rtInf;
  b_dv[87U] = rtInf;
  b_dv[88U] = rtInf;
  b_dv[89U] = rtInf;
  b_dv[135U] = rtInf;
  b_dv[136U] = rtInf;
  b_dv[137U] = rtInf;
  b_dv[138U] = rtInf;
  b_dv[139U] = rtInf;
  b_dv[140U] = rtInf;
  b_dv[141U] = rtInf;
  b_dv[142U] = rtInf;
  b_dv[143U] = rtInf;
  b_dv[144U] = rtInf;
  b_dv[145U] = rtInf;
  b_dv[146U] = rtInf;
  b_dv[147U] = rtInf;
  b_dv[148U] = rtInf;
  b_dv[149U] = rtInf;
  b_dv[150U] = rtInf;
  b_dv[151U] = rtInf;
  b_dv[152U] = rtInf;
  b_dv[153U] = rtInf;
  b_dv[154U] = rtInf;
  b_dv[155U] = rtInf;
  b_dv[156U] = rtInf;
  b_dv[157U] = rtInf;
  b_dv[158U] = rtInf;
  b_dv[159U] = rtInf;
  b_dv[160U] = rtInf;
  b_dv[161U] = rtInf;
  b_dv[162U] = rtInf;
  b_dv[163U] = rtInf;
  b_dv[164U] = rtInf;
  b_dv[165U] = rtInf;
  b_dv[166U] = rtInf;
  b_dv[167U] = rtInf;
  b_dv[168U] = rtInf;
  b_dv[169U] = rtInf;
  b_dv[170U] = rtInf;
  b_dv[171U] = rtInf;
  b_dv[172U] = rtInf;
  b_dv[173U] = rtInf;
  b_dv[174U] = rtInf;
  b_dv[175U] = rtInf;
  b_dv[176U] = rtInf;
  b_dv[177U] = rtInf;
  b_dv[178U] = rtInf;
  b_dv[179U] = rtInf;
  dv1[0U] = rtMinusInf;
  dv1[1U] = rtMinusInf;
  dv1[2U] = rtMinusInf;
  dv1[3U] = rtMinusInf;
  dv1[4U] = rtMinusInf;
  dv1[5U] = rtMinusInf;
  dv1[6U] = rtMinusInf;
  dv1[7U] = rtMinusInf;
  dv1[8U] = rtMinusInf;
  dv1[9U] = rtMinusInf;
  dv1[10U] = rtMinusInf;
  dv1[11U] = rtMinusInf;
  dv1[12U] = rtMinusInf;
  dv1[13U] = rtMinusInf;
  dv1[14U] = rtMinusInf;
  dv1[15U] = rtMinusInf;
  dv1[16U] = rtMinusInf;
  dv1[17U] = rtMinusInf;
  dv1[18U] = rtMinusInf;
  dv1[19U] = rtMinusInf;
  dv1[20U] = rtMinusInf;
  dv1[21U] = rtMinusInf;
  dv1[22U] = rtMinusInf;
  dv1[23U] = rtMinusInf;
  dv1[24U] = rtMinusInf;
  dv1[25U] = rtMinusInf;
  dv1[26U] = rtMinusInf;
  dv1[27U] = rtMinusInf;
  dv1[28U] = rtMinusInf;
  dv1[29U] = rtMinusInf;
  dv1[30U] = rtMinusInf;
  dv1[31U] = rtMinusInf;
  dv1[32U] = rtMinusInf;
  dv1[33U] = rtMinusInf;
  dv1[34U] = rtMinusInf;
  dv1[35U] = rtMinusInf;
  dv1[36U] = rtMinusInf;
  dv1[37U] = rtMinusInf;
  dv1[38U] = rtMinusInf;
  dv1[39U] = rtMinusInf;
  dv1[40U] = rtMinusInf;
  dv1[41U] = rtMinusInf;
  dv1[42U] = rtMinusInf;
  dv1[43U] = rtMinusInf;
  dv1[44U] = rtMinusInf;
  dv1[45U] = rtMinusInf;
  dv1[46U] = rtMinusInf;
  dv1[47U] = rtMinusInf;
  dv1[48U] = rtMinusInf;
  dv1[49U] = rtMinusInf;
  dv1[50U] = rtMinusInf;
  dv1[51U] = rtMinusInf;
  dv1[52U] = rtMinusInf;
  dv1[53U] = rtMinusInf;
  dv1[54U] = rtMinusInf;
  dv1[55U] = rtMinusInf;
  dv1[56U] = rtMinusInf;
  dv1[57U] = rtMinusInf;
  dv1[58U] = rtMinusInf;
  dv1[59U] = rtMinusInf;
  dv1[60U] = rtMinusInf;
  dv1[61U] = rtMinusInf;
  dv1[62U] = rtMinusInf;
  dv1[63U] = rtMinusInf;
  dv1[64U] = rtMinusInf;
  dv1[65U] = rtMinusInf;
  dv1[66U] = rtMinusInf;
  dv1[67U] = rtMinusInf;
  dv1[68U] = rtMinusInf;
  dv1[69U] = rtMinusInf;
  dv1[70U] = rtMinusInf;
  dv1[71U] = rtMinusInf;
  dv1[72U] = rtMinusInf;
  dv1[73U] = rtMinusInf;
  dv1[74U] = rtMinusInf;
  dv1[75U] = rtMinusInf;
  dv1[76U] = rtMinusInf;
  dv1[77U] = rtMinusInf;
  dv1[78U] = rtMinusInf;
  dv1[79U] = rtMinusInf;
  dv1[80U] = rtMinusInf;
  dv1[81U] = rtMinusInf;
  dv1[82U] = rtMinusInf;
  dv1[83U] = rtMinusInf;
  dv1[84U] = rtMinusInf;
  dv1[85U] = rtMinusInf;
  dv1[86U] = rtMinusInf;
  dv1[87U] = rtMinusInf;
  dv1[88U] = rtMinusInf;
  dv1[89U] = rtMinusInf;
  dv1[135U] = rtMinusInf;
  dv1[136U] = rtMinusInf;
  dv1[137U] = rtMinusInf;
  dv1[138U] = rtMinusInf;
  dv1[139U] = rtMinusInf;
  dv1[140U] = rtMinusInf;
  dv1[141U] = rtMinusInf;
  dv1[142U] = rtMinusInf;
  dv1[143U] = rtMinusInf;
  dv1[144U] = rtMinusInf;
  dv1[145U] = rtMinusInf;
  dv1[146U] = rtMinusInf;
  dv1[147U] = rtMinusInf;
  dv1[148U] = rtMinusInf;
  dv1[149U] = rtMinusInf;
  dv1[150U] = rtMinusInf;
  dv1[151U] = rtMinusInf;
  dv1[152U] = rtMinusInf;
  dv1[153U] = rtMinusInf;
  dv1[154U] = rtMinusInf;
  dv1[155U] = rtMinusInf;
  dv1[156U] = rtMinusInf;
  dv1[157U] = rtMinusInf;
  dv1[158U] = rtMinusInf;
  dv1[159U] = rtMinusInf;
  dv1[160U] = rtMinusInf;
  dv1[161U] = rtMinusInf;
  dv1[162U] = rtMinusInf;
  dv1[163U] = rtMinusInf;
  dv1[164U] = rtMinusInf;
  dv1[165U] = rtMinusInf;
  dv1[166U] = rtMinusInf;
  dv1[167U] = rtMinusInf;
  dv1[168U] = rtMinusInf;
  dv1[169U] = rtMinusInf;
  dv1[170U] = rtMinusInf;
  dv1[171U] = rtMinusInf;
  dv1[172U] = rtMinusInf;
  dv1[173U] = rtMinusInf;
  dv1[174U] = rtMinusInf;
  dv1[175U] = rtMinusInf;
  dv1[176U] = rtMinusInf;
  dv1[177U] = rtMinusInf;
  dv1[178U] = rtMinusInf;
  dv1[179U] = rtMinusInf;
  dv2[0U] = rtMinusInf;
  dv2[1U] = rtMinusInf;
  dv2[2U] = rtMinusInf;
  dv2[3U] = rtMinusInf;
  dv2[4U] = rtMinusInf;
  dv2[5U] = rtMinusInf;
  dv2[6U] = rtMinusInf;
  dv2[7U] = rtMinusInf;
  dv2[8U] = rtMinusInf;
  dv2[9U] = rtMinusInf;
  dv2[10U] = rtMinusInf;
  dv2[11U] = rtMinusInf;
  dv2[12U] = rtMinusInf;
  dv2[13U] = rtMinusInf;
  dv2[14U] = rtMinusInf;
  dv2[15U] = rtMinusInf;
  dv2[16U] = rtMinusInf;
  dv2[17U] = rtMinusInf;
  dv2[18U] = rtMinusInf;
  dv2[19U] = rtMinusInf;
  dv2[20U] = rtMinusInf;
  dv2[21U] = rtMinusInf;
  dv2[22U] = rtMinusInf;
  dv2[23U] = rtMinusInf;
  dv2[24U] = rtMinusInf;
  dv2[25U] = rtMinusInf;
  dv2[26U] = rtMinusInf;
  dv2[27U] = rtMinusInf;
  dv2[28U] = rtMinusInf;
  dv2[29U] = rtMinusInf;
  dv2[45U] = rtMinusInf;
  dv2[46U] = rtMinusInf;
  dv2[47U] = rtMinusInf;
  dv2[48U] = rtMinusInf;
  dv2[49U] = rtMinusInf;
  dv2[50U] = rtMinusInf;
  dv2[51U] = rtMinusInf;
  dv2[52U] = rtMinusInf;
  dv2[53U] = rtMinusInf;
  dv2[54U] = rtMinusInf;
  dv2[55U] = rtMinusInf;
  dv2[56U] = rtMinusInf;
  dv2[57U] = rtMinusInf;
  dv2[58U] = rtMinusInf;
  dv2[59U] = rtMinusInf;
  st.site = &h_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    if (!muDoubleScalarIsNaN(ref0[i])) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN", "MATLAB:expectedNonNaN",
      3, 4, 5, "\"ref\"");
  }

  b_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    if ((!muDoubleScalarIsInf(ref0[i])) && (!muDoubleScalarIsNaN(ref0[i]))) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite", "MATLAB:expectedFinite",
      3, 4, 5, "\"ref\"");
  }

  for (b_i = 0; b_i < 4; b_i++) {
    userdata->References[15 * b_i] = ref0[b_i];
    for (i = 0; i < 14; i++) {
      userdata->References[(i + 15 * b_i) + 1] = ref0[b_i];
    }
  }

  st.site = &i_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    if (!muDoubleScalarIsNaN(MVTarget0[i])) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN", "MATLAB:expectedNonNaN",
      3, 4, 10, "\"MVTarget\"");
  }

  b_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    if ((!muDoubleScalarIsInf(MVTarget0[i])) && (!muDoubleScalarIsNaN
         (MVTarget0[i]))) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite", "MATLAB:expectedFinite",
      3, 4, 10, "\"MVTarget\"");
  }

  for (b_i = 0; b_i < 4; b_i++) {
    userdata->MVTarget[15 * b_i] = MVTarget0[b_i];
    for (i = 0; i < 14; i++) {
      userdata->MVTarget[(i + 15 * b_i) + 1] = MVTarget0[b_i];
    }
  }

  st.site = &j_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 180)) {
    if ((!muDoubleScalarIsInf(X0[i])) && (!muDoubleScalarIsNaN(X0[i]))) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite", "MATLAB:expectedFinite",
      3, 4, 4, "\"X0\"");
  }

  c_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 180)) {
    if (!muDoubleScalarIsNaN(X0[i])) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN", "MATLAB:expectedNonNaN",
      3, 4, 4, "\"X0\"");
  }

  st.site = &k_emlrtRSI;
  b_st.site = &o_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 60)) {
    if ((!muDoubleScalarIsInf(MV0[i])) && (!muDoubleScalarIsNaN(MV0[i]))) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite", "MATLAB:expectedFinite",
      3, 4, 5, "\"MV0\"");
  }

  c_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 60)) {
    if (!muDoubleScalarIsNaN(MV0[i])) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN", "MATLAB:expectedNonNaN",
      3, 4, 5, "\"MV0\"");
  }

  st.site = &l_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  p = ((!muDoubleScalarIsInf(Slack0)) && (!muDoubleScalarIsNaN(Slack0)));
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite", "MATLAB:expectedFinite",
      3, 4, 8, "\"Slack0\"");
  }

  c_st.site = &g_emlrtRSI;
  p = !(Slack0 < 0.0);
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonnegative",
      "MATLAB:expectedNonnegative", 3, 4, 8, "\"Slack0\"");
  }

  st.site = &m_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  for (b_i = 0; b_i < 15; b_i++) {
    i = b_i << 2;
    b_MV0[i] = MV0[b_i];
    b_MV0[i + 1] = MV0[b_i + 15];
    b_MV0[i + 2] = MV0[b_i + 30];
    b_MV0[i + 3] = MV0[b_i + 45];
  }

  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)60;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)60;
  lda_t = (ptrdiff_t)60;
  ldb_t = (ptrdiff_t)60;
  ldc_t = (ptrdiff_t)60;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &dv[0], &lda_t, &b_MV0[0],
        &ldb_t, &beta1, &uz[0], &ldc_t);
  for (b_i = 0; b_i < 15; b_i++) {
    for (i = 0; i < 12; i++) {
      b_X0[i + 12 * b_i] = X0[b_i + 15 * i];
    }
  }

  memcpy(&z0[0], &b_X0[0], 180U * sizeof(real_T));
  memcpy(&z0[180], &uz[0], 60U * sizeof(real_T));
  z0[240] = Slack0;
  userdata->Ts = 0.2;
  userdata->PredictionHorizon = 15.0;
  userdata->NumOfStates = 12.0;
  userdata->NumOfOutputs = 4.0;
  userdata->NumOfInputs = 4.0;
  userdata->LastMV[0] = lastMV[0];
  userdata->MVIndex[0] = 1.0;
  userdata->LastMV[1] = lastMV[1];
  userdata->MVIndex[1] = 2.0;
  userdata->LastMV[2] = lastMV[2];
  userdata->MVIndex[2] = 3.0;
  userdata->LastMV[3] = lastMV[3];
  userdata->MVIndex[3] = 4.0;
  for (i = 0; i < 12; i++) {
    alpha1 = x[i];
    userdata->CurrentStates[i] = alpha1;
    runtimedata->x[i] = alpha1;
  }

  runtimedata->lastMV[0] = lastMV[0];
  runtimedata->lastMV[1] = lastMV[1];
  runtimedata->lastMV[2] = lastMV[2];
  runtimedata->lastMV[3] = lastMV[3];
  runtimedata->ECRWeight = 100000.0;
  for (b_i = 0; b_i < 60; b_i++) {
    runtimedata->ref[b_i] = userdata->References[b_i];
    runtimedata->OutputWeights[b_i] = iv[b_i];
    runtimedata->MVWeights[b_i] = 1.0;
    runtimedata->MVRateWeights[b_i] = 0.0;
    runtimedata->OutputMin[b_i] = dv2[b_i];
    runtimedata->OutputMax[b_i] = rtInf;
  }

  memcpy(&runtimedata->StateMin[0], &dv1[0], 180U * sizeof(real_T));
  memcpy(&runtimedata->StateMax[0], &b_dv[0], 180U * sizeof(real_T));
  for (b_i = 0; b_i < 60; b_i++) {
    runtimedata->MVMin[b_i] = 0.0;
    runtimedata->MVMax[b_i] = 8.5;
    runtimedata->MVRateMin[b_i] = rtMinusInf;
    runtimedata->MVRateMax[b_i] = rtInf;
    runtimedata->MVScaledTarget[b_i] = userdata->MVTarget[b_i];
  }
}

/* End of code generation (znlmpc_generateRuntimeData.c) */
