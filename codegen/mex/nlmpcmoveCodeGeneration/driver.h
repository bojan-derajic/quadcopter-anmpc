/*
 * driver.h
 *
 * Code generation for function 'driver'
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
void driver(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, real_T
            Hessian[103041], const real_T bineq_data[], const real_T lb[321],
            const real_T ub[321], g_struct_T *TrialState, k_struct_T
            *MeritFunction, const h_struct_T *FcnEvaluator, d_struct_T *memspace,
            j_struct_T *WorkingSet, l_struct_T *QRManager, m_struct_T
            *CholManager, i_struct_T *QPObjective, const int32_T
            fscales_lineq_constraint_size[1], const int32_T
            fscales_cineq_constraint_size[1]);

/* End of code generation (driver.h) */
