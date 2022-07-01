/*
 * test_exit.h
 *
 * Code generation for function 'test_exit'
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
void b_test_exit(const emlrtStack *sp, struct_T *Flags, d_struct_T *memspace,
                 k_struct_T *MeritFunction, const int32_T
                 fscales_lineq_constraint_size[1], const int32_T
                 fscales_cineq_constraint_size[1], j_struct_T *WorkingSet,
                 g_struct_T *TrialState, l_struct_T *QRManager, const real_T lb
                 [321], const real_T ub[321]);
void test_exit(const emlrtStack *sp, k_struct_T *MeritFunction, const int32_T
               fscales_lineq_constraint_size[1], const int32_T
               fscales_cineq_constraint_size[1], const j_struct_T *WorkingSet,
               g_struct_T *TrialState, const real_T lb[321], const real_T ub[321],
               boolean_T *Flags_gradOK, boolean_T *Flags_fevalOK, boolean_T
               *Flags_done, boolean_T *Flags_stepAccepted, boolean_T
               *Flags_failedLineSearch, int32_T *Flags_stepType);

/* End of code generation (test_exit.h) */
