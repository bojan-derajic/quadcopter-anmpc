/*
 * phaseone.h
 *
 * Code generation for function 'phaseone'
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
void phaseone(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
              real_T H[58081], const real_T f_data[], const int32_T f_size[1],
              g_struct_T *solution, d_struct_T *memspace, j_struct_T *workingset,
              l_struct_T *qrmanager, m_struct_T *cholmanager, i_struct_T
              *objective, c_struct_T *options, const c_struct_T *runTimeOptions);

/* End of code generation (phaseone.h) */
