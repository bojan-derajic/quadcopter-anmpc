/*
 * factoryConstruct.h
 *
 * Code generation for function 'factoryConstruct'
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
void factoryConstruct(const emlrtStack *sp, int32_T mIneq, int32_T mLinIneq,
                      const real_T Aineq_data[], const int32_T Aineq_size[2],
                      int32_T mLB, const int32_T indexLB[241], int32_T mUB,
                      const int32_T indexUB[241], int32_T mFixed, const int32_T
                      indexFixed[241], int32_T nVarMax, int32_T mConstrMax,
                      j_struct_T *obj);

/* End of code generation (factoryConstruct.h) */
