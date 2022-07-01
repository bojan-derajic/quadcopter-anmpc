/*
 * znlmpc_objfun.h
 *
 * Code generation for function 'znlmpc_objfun'
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
void quadraticObjective(const emlrtStack *sp, const real_T runtimedata_lastMV[4],
  const real_T runtimedata_ref[80], const real_T runtimedata_OutputWeights[80],
  const real_T runtimedata_MVWeights[80], const real_T
  runtimedata_MVRateWeights[80], const real_T runtimedata_MVScaledTarget[80],
  const real_T X[252], const real_T U[84], real_T e, real_T *f, real_T gfx[240],
  real_T gfu[80], real_T *gfe);

/* End of code generation (znlmpc_objfun.h) */
