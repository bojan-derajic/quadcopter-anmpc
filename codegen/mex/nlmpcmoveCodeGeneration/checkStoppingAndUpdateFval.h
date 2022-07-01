/*
 * checkStoppingAndUpdateFval.h
 *
 * Code generation for function 'checkStoppingAndUpdateFval'
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
void checkStoppingAndUpdateFval(c_nlmpcmoveCodeGenerationStackD *SD, const
  emlrtStack *sp, int32_T *activeSetChangeID, const real_T f_data[], const
  int32_T f_size[1], g_struct_T *solution, d_struct_T *memspace, const
  i_struct_T *objective, j_struct_T *workingset, l_struct_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
  updateFval);

/* End of code generation (checkStoppingAndUpdateFval.h) */
