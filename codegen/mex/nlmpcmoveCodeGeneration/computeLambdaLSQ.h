/*
 * computeLambdaLSQ.h
 *
 * Code generation for function 'computeLambdaLSQ'
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
void computeLambdaLSQ(const emlrtStack *sp, int32_T nVar, int32_T mConstr,
                      l_struct_T *QRManager, const real_T ATwset_data[], const
                      int32_T ATwset_size[2], const real_T grad_data[], real_T
                      lambdaLSQ_data[], const int32_T lambdaLSQ_size[1], real_T
                      workspace_data[]);

/* End of code generation (computeLambdaLSQ.h) */
