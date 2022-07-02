/*
 * nlmpcmoveCodeGeneration.h
 *
 * Code generation for function 'nlmpcmoveCodeGeneration'
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
void anon(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
          real_T runtimedata_x[12], const real_T runtimedata_OutputMin[60],
          const real_T runtimedata_OutputMax[60], const real_T z[241], real_T
          varargout_1_data[], int32_T varargout_1_size[2], real_T varargout_2
          [180], real_T varargout_3_data[], int32_T varargout_3_size[2], real_T
          varargout_4[43380]);
void nlmpcmoveCodeGeneration(c_nlmpcmoveCodeGenerationStackD *SD, const
  emlrtStack *sp, const real_T x[12], const real_T lastMV[4], struct1_T
  *onlinedata, real_T mv[4], struct2_T *info);

/* End of code generation (nlmpcmoveCodeGeneration.h) */
