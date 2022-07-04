/*
 * checkLinearInputs.h
 *
 * Code generation for function 'checkLinearInputs'
 *
 */

#pragma once

/* Include files */
#include "nlmpcmoveCodeGeneration_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void checkLinearInputs(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
  const real_T x0[241], const real_T Aineq_data[], const int32_T Aineq_size[2],
  const real_T bineq_data[], const int32_T bineq_size[1], const real_T lb[241],
  const real_T ub[241]);

/* End of code generation (checkLinearInputs.h) */
