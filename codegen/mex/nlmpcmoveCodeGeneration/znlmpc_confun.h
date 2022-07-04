/*
 * znlmpc_confun.h
 *
 * Code generation for function 'znlmpc_confun'
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
void outputBounds(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
                  const real_T runtimedata_OutputMin[60], const real_T
                  runtimedata_OutputMax[60], const real_T X[192], real_T e,
                  real_T c_data[], int32_T c_size[2], real_T Jc_data[], int32_T
                  Jc_size[2]);
void stateEvolution(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
                    const real_T X[192], const real_T U[64], real_T c[180],
                    real_T J[43380]);

/* End of code generation (znlmpc_confun.h) */
