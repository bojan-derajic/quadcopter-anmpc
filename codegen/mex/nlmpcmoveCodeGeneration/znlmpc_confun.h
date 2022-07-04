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
                  const real_T runtimedata_OutputMin[80], const real_T
                  runtimedata_OutputMax[80], const real_T X[252], real_T e,
                  real_T c_data[], int32_T c_size[2], real_T Jc_data[], int32_T
                  Jc_size[2]);
void stateEvolution(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
                    const real_T X[252], const real_T U[84], real_T c[240],
                    real_T J[77040]);

/* End of code generation (znlmpc_confun.h) */
