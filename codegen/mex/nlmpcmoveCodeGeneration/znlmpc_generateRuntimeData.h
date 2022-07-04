/*
 * znlmpc_generateRuntimeData.h
 *
 * Code generation for function 'znlmpc_generateRuntimeData'
 *
 */

#pragma once

/* Include files */
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void znlmpc_generateRuntimeData(const emlrtStack *sp, const real_T x[12], const
  real_T lastMV[4], const real_T ref0[60], const real_T MVTarget0[4], const
  real_T X0[180], const real_T MV0[60], real_T Slack0, f_struct_T *runtimedata,
  e_struct_T *userdata, real_T z0[241]);

/* End of code generation (znlmpc_generateRuntimeData.h) */
