/*
 * relaxed.h
 *
 * Code generation for function 'relaxed'
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
void relaxed(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
             real_T Hessian[58081], const real_T grad_data[], const int32_T
             grad_size[1], g_struct_T *TrialState, k_struct_T *MeritFunction,
             d_struct_T *memspace, j_struct_T *WorkingSet, l_struct_T *QRManager,
             m_struct_T *CholManager, i_struct_T *QPObjective, c_struct_T
             *qpoptions);

/* End of code generation (relaxed.h) */
