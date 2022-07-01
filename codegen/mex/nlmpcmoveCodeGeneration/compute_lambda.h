/*
 * compute_lambda.h
 *
 * Code generation for function 'compute_lambda'
 *
 */

#pragma once

/* Include files */
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void compute_lambda(const emlrtStack *sp, real_T workspace_data[], const int32_T
                    workspace_size[2], g_struct_T *solution, const i_struct_T
                    *objective, const l_struct_T *qrmanager);

/* End of code generation (compute_lambda.h) */
