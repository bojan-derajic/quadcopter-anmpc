/*
 * saveJacobian.h
 *
 * Code generation for function 'saveJacobian'
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
void saveJacobian(const emlrtStack *sp, g_struct_T *obj, int32_T nVar, int32_T
                  mIneq, const real_T JacCineqTrans_data[], int32_T ineqCol0,
                  const real_T JacCeqTrans_data[], int32_T ldJ);

/* End of code generation (saveJacobian.h) */
