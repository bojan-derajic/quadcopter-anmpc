/*
 * PresolveWorkingSet.h
 *
 * Code generation for function 'PresolveWorkingSet'
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
void PresolveWorkingSet(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack
  *sp, g_struct_T *solution, d_struct_T *memspace, j_struct_T *workingset,
  l_struct_T *qrmanager);

/* End of code generation (PresolveWorkingSet.h) */
