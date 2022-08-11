/*
 * state_jacob_fcn.c
 *
 * Code generation for function 'state_jacob_fcn'
 *
 */

/* Include files */
#include "state_jacob_fcn.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void state_jacob_fcn(const real_T in1[12], const real_T in2[4], real_T A[144],
                     real_T B[48])
{
  real_T A_tmp;
  real_T b_A_tmp;
  real_T c_A_tmp;
  real_T d_A_tmp;
  real_T e_A_tmp;
  real_T f_A_tmp;
  real_T g_A_tmp;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t17;
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t8;
  real_T t9;

  /* STATE_JACOB_FCN */
  /*     [A,B] = STATE_JACOB_FCN(IN1,IN2) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     01-Aug-2022 18:13:25 */
  t2 = muDoubleScalarCos(in1[6]);
  t3 = muDoubleScalarCos(in1[8]);
  t4 = muDoubleScalarCos(in1[7]);
  t5 = muDoubleScalarSin(in1[6]);
  t6 = muDoubleScalarSin(in1[8]);
  t7 = muDoubleScalarSin(in1[7]);
  t8 = muDoubleScalarTan(in1[7]);
  t9 = in1[11] * 0.79166666666666663;
  t11 = ((in2[0] + in2[1]) + in2[2]) + in2[3];
  t12 = 1.0 / t4;
  t13 = t2 * t4 * 1.333333333333333;
  t17 = t8 * t8 + 1.0;
  memset(&A[0], 0, 36U * sizeof(real_T));
  A[36] = 1.0;
  memset(&A[37], 0, 12U * sizeof(real_T));
  A[49] = 1.0;
  memset(&A[50], 0, 12U * sizeof(real_T));
  A[62] = 1.0;
  memset(&A[63], 0, 12U * sizeof(real_T));
  A_tmp = t2 * t6;
  b_A_tmp = t3 * t5;
  A[75] = t11 * (A_tmp - b_A_tmp * t7) * 1.333333333333333;
  c_A_tmp = t2 * t3;
  d_A_tmp = t5 * t6;
  A[76] = t11 * (c_A_tmp + d_A_tmp * t7) * -1.333333333333333;
  e_A_tmp = t4 * t5;
  A[77] = ((e_A_tmp * in2[0] * -1.333333333333333 - e_A_tmp * in2[1] *
            1.333333333333333) - e_A_tmp * in2[2] * 1.333333333333333) - e_A_tmp
    * in2[3] * 1.333333333333333;
  e_A_tmp = t5 * t8;
  t8 *= t2;
  A[78] = t8 * in1[10] - e_A_tmp * in1[11];
  f_A_tmp = t5 * in1[10];
  g_A_tmp = t2 * in1[11];
  A[79] = -f_A_tmp - g_A_tmp;
  A[80] = t12 * (t2 * in1[10] - t5 * in1[11]);
  A[81] = 0.0;
  A[82] = 0.0;
  A[83] = 0.0;
  A[84] = 0.0;
  A[85] = 0.0;
  A[86] = 0.0;
  A[87] = t3 * t11 * t13;
  A[88] = t6 * t11 * t13;
  t4 = t2 * t7;
  A[89] = ((t4 * in2[0] * -1.333333333333333 - t4 * in2[1] * 1.333333333333333)
           - t4 * in2[2] * 1.333333333333333) - t4 * in2[3] * 1.333333333333333;
  A[90] = t5 * t17 * in1[10] + t2 * t17 * in1[11];
  A[91] = 0.0;
  A[92] = t7 * (t12 * t12) * (f_A_tmp + g_A_tmp);
  A[93] = 0.0;
  A[94] = 0.0;
  A[95] = 0.0;
  A[96] = 0.0;
  A[97] = 0.0;
  A[98] = 0.0;
  A_tmp *= t7;
  A[99] = t11 * (b_A_tmp - A_tmp) * 1.333333333333333;
  c_A_tmp *= t7;
  A[100] = t11 * (d_A_tmp + c_A_tmp) * 1.333333333333333;
  memset(&A[101], 0, 13U * sizeof(real_T));
  A[114] = 1.0;
  A[115] = 0.0;
  A[116] = 0.0;
  A[117] = 0.0;
  A[118] = t9;
  A[119] = 0.0;
  A[120] = 0.0;
  A[121] = 0.0;
  A[122] = 0.0;
  A[123] = 0.0;
  A[124] = 0.0;
  A[125] = 0.0;
  A[126] = e_A_tmp;
  A[127] = t2;
  A[128] = t5 * t12;
  A[129] = -t9;
  memset(&A[130], 0, 8U * sizeof(real_T));
  A[138] = t8;
  A[139] = -t5;
  A[140] = t2 * t12;
  A[141] = in1[10] * -0.79166666666666663;
  A[142] = in1[9] * 0.79166666666666663;
  A[143] = 0.0;
  t8 = b_A_tmp * -1.333333333333333 + A_tmp * 1.333333333333333;
  t4 = d_A_tmp * 1.333333333333333 + c_A_tmp * 1.333333333333333;
  B[0] = 0.0;
  B[1] = 0.0;
  B[2] = 0.0;
  B[3] = t4;
  B[4] = t8;
  B[5] = t13;
  B[6] = 0.0;
  B[7] = 0.0;
  B[8] = 0.0;
  B[9] = 41.247895569215267;
  B[10] = -41.247895569215267;
  B[11] = -3.6500847066071151;
  B[12] = 0.0;
  B[13] = 0.0;
  B[14] = 0.0;
  B[15] = t4;
  B[16] = t8;
  B[17] = t13;
  B[18] = 0.0;
  B[19] = 0.0;
  B[20] = 0.0;
  B[21] = -41.247895569215267;
  B[22] = -41.247895569215267;
  B[23] = 3.6500847066071151;
  B[24] = 0.0;
  B[25] = 0.0;
  B[26] = 0.0;
  B[27] = t4;
  B[28] = t8;
  B[29] = t13;
  B[30] = 0.0;
  B[31] = 0.0;
  B[32] = 0.0;
  B[33] = -41.247895569215267;
  B[34] = 41.247895569215267;
  B[35] = -3.6500847066071151;
  B[36] = 0.0;
  B[37] = 0.0;
  B[38] = 0.0;
  B[39] = t4;
  B[40] = t8;
  B[41] = t13;
  B[42] = 0.0;
  B[43] = 0.0;
  B[44] = 0.0;
  B[45] = 41.247895569215267;
  B[46] = 41.247895569215267;
  B[47] = 3.6500847066071151;
}

/* End of code generation (state_jacob_fcn.c) */
