/*
 * computePrimalFeasError.h
 *
 * Code generation for function 'computePrimalFeasError'
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
real_T computePrimalFeasError(const emlrtStack *sp, const real_T x[241], int32_T
  mLinIneq, int32_T mNonlinIneq, const real_T cIneq_data[], const int32_T
  cIneq_size[1], const real_T cEq[180], const int32_T finiteLB_data[], const
  int32_T finiteLB_size[1], int32_T mLB, const real_T lb[241], const int32_T
  finiteUB_data[], int32_T mUB, const real_T ub[241]);

/* End of code generation (computePrimalFeasError.h) */
