/*
 * sortLambdaQP.h
 *
 * Code generation for function 'sortLambdaQP'
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
void sortLambdaQP(const emlrtStack *sp, real_T lambda_data[], const int32_T
                  lambda_size[1], int32_T WorkingSet_nActiveConstr, const
                  int32_T WorkingSet_sizes[5], const int32_T
                  WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid_data[],
                  const int32_T WorkingSet_Wid_size[1], const int32_T
                  WorkingSet_Wlocalidx_data[], const int32_T
                  WorkingSet_Wlocalidx_size[1], real_T workspace_data[], const
                  int32_T workspace_size[2]);

/* End of code generation (sortLambdaQP.h) */
