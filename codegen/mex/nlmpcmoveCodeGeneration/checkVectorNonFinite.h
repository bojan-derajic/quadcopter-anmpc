/*
 * checkVectorNonFinite.h
 *
 * Code generation for function 'checkVectorNonFinite'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
int32_T b_checkVectorNonFinite(const emlrtStack *sp, const real_T vec[240]);
int32_T checkVectorNonFinite(const emlrtStack *sp, int32_T N, const real_T
  vec_data[], const int32_T vec_size[1], int32_T iv0);

/* End of code generation (checkVectorNonFinite.h) */
