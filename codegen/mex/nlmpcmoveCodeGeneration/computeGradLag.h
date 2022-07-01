/*
 * computeGradLag.h
 *
 * Code generation for function 'computeGradLag'
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
void b_computeGradLag(const emlrtStack *sp, real_T workspace_data[], const
                      int32_T workspace_size[2], int32_T ldA, int32_T nVar,
                      const real_T grad_data[], const int32_T grad_size[1],
                      int32_T mIneq, const real_T AineqTrans_data[], const
                      real_T AeqTrans_data[], const int32_T finiteFixed_data[],
                      int32_T mFixed, const int32_T finiteLB_data[], const
                      int32_T finiteLB_size[1], int32_T mLB, const int32_T
                      finiteUB_data[], int32_T mUB, const real_T lambda_data[],
                      const int32_T lambda_size[1]);
void computeGradLag(const emlrtStack *sp, real_T workspace_data[], const int32_T
                    workspace_size[1], int32_T ldA, int32_T nVar, const real_T
                    grad_data[], const int32_T grad_size[1], int32_T mIneq,
                    const real_T AineqTrans_data[], const real_T AeqTrans_data[],
                    const int32_T finiteFixed_data[], int32_T mFixed, const
                    int32_T finiteLB_data[], const int32_T finiteLB_size[1],
                    int32_T mLB, const int32_T finiteUB_data[], int32_T mUB,
                    const real_T lambda_data[], const int32_T lambda_size[1]);

/* End of code generation (computeGradLag.h) */
