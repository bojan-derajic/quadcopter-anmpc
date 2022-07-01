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
  real_T X0[240], const real_T MV0[80], real_T Slack0, f_struct_T *runtimedata,
  e_struct_T *userdata, real_T z0[321])
{
  static real_T b_dv[240] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    3.1415926535897931, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static real_T dv1[240] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static real_T dv2[80] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T iv[80] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_X0[240];
  real_T b_MV0[80];
  real_T uz[80];
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
  b_dv[90U] = rtInf;
  b_dv[91U] = rtInf;
  b_dv[92U] = rtInf;
  b_dv[93U] = rtInf;
  b_dv[94U] = rtInf;
  b_dv[95U] = rtInf;
  b_dv[96U] = rtInf;
  b_dv[97U] = rtInf;
  b_dv[98U] = rtInf;
  b_dv[99U] = rtInf;
  b_dv[100U] = rtInf;
  b_dv[101U] = rtInf;
  b_dv[102U] = rtInf;
  b_dv[103U] = rtInf;
  b_dv[104U] = rtInf;
  b_dv[105U] = rtInf;
  b_dv[106U] = rtInf;
  b_dv[107U] = rtInf;
  b_dv[108U] = rtInf;
  b_dv[109U] = rtInf;
  b_dv[110U] = rtInf;
  b_dv[111U] = rtInf;
  b_dv[112U] = rtInf;
  b_dv[113U] = rtInf;
  b_dv[114U] = rtInf;
  b_dv[115U] = rtInf;
  b_dv[116U] = rtInf;
  b_dv[117U] = rtInf;
  b_dv[118U] = rtInf;
  b_dv[119U] = rtInf;
  b_dv[180U] = rtInf;
  b_dv[181U] = rtInf;
  b_dv[182U] = rtInf;
  b_dv[183U] = rtInf;
  b_dv[184U] = rtInf;
  b_dv[185U] = rtInf;
  b_dv[186U] = rtInf;
  b_dv[187U] = rtInf;
  b_dv[188U] = rtInf;
  b_dv[189U] = rtInf;
  b_dv[190U] = rtInf;
  b_dv[191U] = rtInf;
  b_dv[192U] = rtInf;
  b_dv[193U] = rtInf;
  b_dv[194U] = rtInf;
  b_dv[195U] = rtInf;
  b_dv[196U] = rtInf;
  b_dv[197U] = rtInf;
  b_dv[198U] = rtInf;
  b_dv[199U] = rtInf;
  b_dv[200U] = rtInf;
  b_dv[201U] = rtInf;
  b_dv[202U] = rtInf;
  b_dv[203U] = rtInf;
  b_dv[204U] = rtInf;
  b_dv[205U] = rtInf;
  b_dv[206U] = rtInf;
  b_dv[207U] = rtInf;
  b_dv[208U] = rtInf;
  b_dv[209U] = rtInf;
  b_dv[210U] = rtInf;
  b_dv[211U] = rtInf;
  b_dv[212U] = rtInf;
  b_dv[213U] = rtInf;
  b_dv[214U] = rtInf;
  b_dv[215U] = rtInf;
  b_dv[216U] = rtInf;
  b_dv[217U] = rtInf;
  b_dv[218U] = rtInf;
  b_dv[219U] = rtInf;
  b_dv[220U] = rtInf;
  b_dv[221U] = rtInf;
  b_dv[222U] = rtInf;
  b_dv[223U] = rtInf;
  b_dv[224U] = rtInf;
  b_dv[225U] = rtInf;
  b_dv[226U] = rtInf;
  b_dv[227U] = rtInf;
  b_dv[228U] = rtInf;
  b_dv[229U] = rtInf;
  b_dv[230U] = rtInf;
  b_dv[231U] = rtInf;
  b_dv[232U] = rtInf;
  b_dv[233U] = rtInf;
  b_dv[234U] = rtInf;
  b_dv[235U] = rtInf;
  b_dv[236U] = rtInf;
  b_dv[237U] = rtInf;
  b_dv[238U] = rtInf;
  b_dv[239U] = rtInf;
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
  dv1[90U] = rtMinusInf;
  dv1[91U] = rtMinusInf;
  dv1[92U] = rtMinusInf;
  dv1[93U] = rtMinusInf;
  dv1[94U] = rtMinusInf;
  dv1[95U] = rtMinusInf;
  dv1[96U] = rtMinusInf;
  dv1[97U] = rtMinusInf;
  dv1[98U] = rtMinusInf;
  dv1[99U] = rtMinusInf;
  dv1[100U] = rtMinusInf;
  dv1[101U] = rtMinusInf;
  dv1[102U] = rtMinusInf;
  dv1[103U] = rtMinusInf;
  dv1[104U] = rtMinusInf;
  dv1[105U] = rtMinusInf;
  dv1[106U] = rtMinusInf;
  dv1[107U] = rtMinusInf;
  dv1[108U] = rtMinusInf;
  dv1[109U] = rtMinusInf;
  dv1[110U] = rtMinusInf;
  dv1[111U] = rtMinusInf;
  dv1[112U] = rtMinusInf;
  dv1[113U] = rtMinusInf;
  dv1[114U] = rtMinusInf;
  dv1[115U] = rtMinusInf;
  dv1[116U] = rtMinusInf;
  dv1[117U] = rtMinusInf;
  dv1[118U] = rtMinusInf;
  dv1[119U] = rtMinusInf;
  dv1[180U] = rtMinusInf;
  dv1[181U] = rtMinusInf;
  dv1[182U] = rtMinusInf;
  dv1[183U] = rtMinusInf;
  dv1[184U] = rtMinusInf;
  dv1[185U] = rtMinusInf;
  dv1[186U] = rtMinusInf;
  dv1[187U] = rtMinusInf;
  dv1[188U] = rtMinusInf;
  dv1[189U] = rtMinusInf;
  dv1[190U] = rtMinusInf;
  dv1[191U] = rtMinusInf;
  dv1[192U] = rtMinusInf;
  dv1[193U] = rtMinusInf;
  dv1[194U] = rtMinusInf;
  dv1[195U] = rtMinusInf;
  dv1[196U] = rtMinusInf;
  dv1[197U] = rtMinusInf;
  dv1[198U] = rtMinusInf;
  dv1[199U] = rtMinusInf;
  dv1[200U] = rtMinusInf;
  dv1[201U] = rtMinusInf;
  dv1[202U] = rtMinusInf;
  dv1[203U] = rtMinusInf;
  dv1[204U] = rtMinusInf;
  dv1[205U] = rtMinusInf;
  dv1[206U] = rtMinusInf;
  dv1[207U] = rtMinusInf;
  dv1[208U] = rtMinusInf;
  dv1[209U] = rtMinusInf;
  dv1[210U] = rtMinusInf;
  dv1[211U] = rtMinusInf;
  dv1[212U] = rtMinusInf;
  dv1[213U] = rtMinusInf;
  dv1[214U] = rtMinusInf;
  dv1[215U] = rtMinusInf;
  dv1[216U] = rtMinusInf;
  dv1[217U] = rtMinusInf;
  dv1[218U] = rtMinusInf;
  dv1[219U] = rtMinusInf;
  dv1[220U] = rtMinusInf;
  dv1[221U] = rtMinusInf;
  dv1[222U] = rtMinusInf;
  dv1[223U] = rtMinusInf;
  dv1[224U] = rtMinusInf;
  dv1[225U] = rtMinusInf;
  dv1[226U] = rtMinusInf;
  dv1[227U] = rtMinusInf;
  dv1[228U] = rtMinusInf;
  dv1[229U] = rtMinusInf;
  dv1[230U] = rtMinusInf;
  dv1[231U] = rtMinusInf;
  dv1[232U] = rtMinusInf;
  dv1[233U] = rtMinusInf;
  dv1[234U] = rtMinusInf;
  dv1[235U] = rtMinusInf;
  dv1[236U] = rtMinusInf;
  dv1[237U] = rtMinusInf;
  dv1[238U] = rtMinusInf;
  dv1[239U] = rtMinusInf;
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
  dv2[30U] = rtMinusInf;
  dv2[31U] = rtMinusInf;
  dv2[32U] = rtMinusInf;
  dv2[33U] = rtMinusInf;
  dv2[34U] = rtMinusInf;
  dv2[35U] = rtMinusInf;
  dv2[36U] = rtMinusInf;
  dv2[37U] = rtMinusInf;
  dv2[38U] = rtMinusInf;
  dv2[39U] = rtMinusInf;
  dv2[60U] = rtMinusInf;
  dv2[61U] = rtMinusInf;
  dv2[62U] = rtMinusInf;
  dv2[63U] = rtMinusInf;
  dv2[64U] = rtMinusInf;
  dv2[65U] = rtMinusInf;
  dv2[66U] = rtMinusInf;
  dv2[67U] = rtMinusInf;
  dv2[68U] = rtMinusInf;
  dv2[69U] = rtMinusInf;
  dv2[70U] = rtMinusInf;
  dv2[71U] = rtMinusInf;
  dv2[72U] = rtMinusInf;
  dv2[73U] = rtMinusInf;
  dv2[74U] = rtMinusInf;
  dv2[75U] = rtMinusInf;
  dv2[76U] = rtMinusInf;
  dv2[77U] = rtMinusInf;
  dv2[78U] = rtMinusInf;
  dv2[79U] = rtMinusInf;
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
    userdata->References[20 * b_i] = ref0[b_i];
    for (i = 0; i < 19; i++) {
      userdata->References[(i + 20 * b_i) + 1] = ref0[b_i];
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
    userdata->MVTarget[20 * b_i] = MVTarget0[b_i];
    for (i = 0; i < 19; i++) {
      userdata->MVTarget[(i + 20 * b_i) + 1] = MVTarget0[b_i];
    }
  }

  st.site = &j_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 240)) {
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
  while ((!exitg1) && (i < 240)) {
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
  while ((!exitg1) && (i < 80)) {
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
  while ((!exitg1) && (i < 80)) {
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
  for (b_i = 0; b_i < 20; b_i++) {
    i = b_i << 2;
    b_MV0[i] = MV0[b_i];
    b_MV0[i + 1] = MV0[b_i + 20];
    b_MV0[i + 2] = MV0[b_i + 40];
    b_MV0[i + 3] = MV0[b_i + 60];
  }

  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)80;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)80;
  lda_t = (ptrdiff_t)80;
  ldb_t = (ptrdiff_t)80;
  ldc_t = (ptrdiff_t)80;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &dv[0], &lda_t, &b_MV0[0],
        &ldb_t, &beta1, &uz[0], &ldc_t);
  for (b_i = 0; b_i < 20; b_i++) {
    for (i = 0; i < 12; i++) {
      b_X0[i + 12 * b_i] = X0[b_i + 20 * i];
    }
  }

  memcpy(&z0[0], &b_X0[0], 240U * sizeof(real_T));
  memcpy(&z0[240], &uz[0], 80U * sizeof(real_T));
  z0[320] = Slack0;
  userdata->Ts = 0.2;
  userdata->PredictionHorizon = 20.0;
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
  for (b_i = 0; b_i < 80; b_i++) {
    runtimedata->ref[b_i] = userdata->References[b_i];
    runtimedata->OutputWeights[b_i] = iv[b_i];
    runtimedata->MVWeights[b_i] = 1.0;
    runtimedata->MVRateWeights[b_i] = 0.0;
    runtimedata->OutputMin[b_i] = dv2[b_i];
    runtimedata->OutputMax[b_i] = rtInf;
  }

  memcpy(&runtimedata->StateMin[0], &dv1[0], 240U * sizeof(real_T));
  memcpy(&runtimedata->StateMax[0], &b_dv[0], 240U * sizeof(real_T));
  for (b_i = 0; b_i < 80; b_i++) {
    runtimedata->MVMin[b_i] = 0.0;
    runtimedata->MVMax[b_i] = 8.5;
    runtimedata->MVRateMin[b_i] = rtMinusInf;
    runtimedata->MVRateMax[b_i] = rtInf;
    runtimedata->MVScaledTarget[b_i] = userdata->MVTarget[b_i];
  }
}

/* End of code generation (znlmpc_generateRuntimeData.c) */
