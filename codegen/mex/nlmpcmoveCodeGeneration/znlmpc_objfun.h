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
  const real_T runtimedata_ref[60], const real_T runtimedata_OutputWeights[60],
  const real_T runtimedata_MVWeights[60], const real_T
  runtimedata_MVRateWeights[60], const real_T runtimedata_MVScaledTarget[60],
  const real_T X[192], const real_T U[64], real_T e, real_T *f, real_T gfx[180],
  real_T gfu[60], real_T *gfe);

/* End of code generation (znlmpc_objfun.h) */
