/*
 * state_fcn.c
 *
 * Code generation for function 'state_fcn'
 *
 */

/* Include files */
#include "state_fcn.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void state_fcn(const real_T in1[12], const real_T in2[4], real_T f[12])
{
  real_T t10;
  real_T t12;
  real_T t13;
  real_T t14;
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t8;
  real_T t9;

  /* STATE_FCN */
  /*     F = STATE_FCN(IN1,IN2) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     01-Aug-2022 18:13:24 */
  t2 = muDoubleScalarCos(in1[6]);
  t3 = muDoubleScalarCos(in1[8]);
  t4 = muDoubleScalarCos(in1[7]);
  t5 = muDoubleScalarSin(in1[6]);
  t6 = muDoubleScalarSin(in1[8]);
  t7 = muDoubleScalarSin(in1[7]);
  t8 = muDoubleScalarTan(in1[7]);
  t9 = in2[0] * 41.247895569215267;
  t10 = in2[1] * -41.247895569215267;
  t12 = in2[2] * 41.247895569215267;
  t13 = in2[3] * 41.247895569215267;
  t14 = ((in2[0] + in2[1]) + in2[2]) + in2[3];
  f[0] = in1[3];
  f[1] = in1[4];
  f[2] = in1[5];
  f[3] = t14 * (t5 * t6 + t2 * t3 * t7) * 1.333333333333333;
  f[4] = t14 * (t3 * t5 - t2 * t6 * t7) * -1.333333333333333;
  t3 = t2 * t4;
  f[5] = (((t3 * in2[0] * 1.333333333333333 + t3 * in2[1] * 1.333333333333333) +
           t3 * in2[2] * 1.333333333333333) + t3 * in2[3] * 1.333333333333333) -
    9.81;
  f[6] = (in1[9] + t5 * t8 * in1[10]) + t2 * t8 * in1[11];
  f[7] = t2 * in1[10] - t5 * in1[11];
  f[8] = (t5 * in1[10] + t2 * in1[11]) / t4;
  f[9] = (((t9 + t10) - t12) + t13) - in1[10] * in1[11] * 0.79166666666666663;
  f[10] = (((-t9 + t10) + t12) + t13) + in1[9] * in1[11] * 0.79166666666666663;
  f[11] = ((in2[0] * -3.6500847066071151 + in2[1] * 3.6500847066071151) - in2[2]
           * 3.6500847066071151) + in2[3] * 3.6500847066071151;
}

/* End of code generation (state_fcn.c) */
