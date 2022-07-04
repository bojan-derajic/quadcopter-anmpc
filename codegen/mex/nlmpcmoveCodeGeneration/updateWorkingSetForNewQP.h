/*
 * updateWorkingSetForNewQP.h
 *
 * Code generation for function 'updateWorkingSetForNewQP'
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
void b_updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[321],
  j_struct_T *WorkingSet, int32_T mIneq, int32_T mNonlinIneq, const real_T
  cIneq_data[], const int32_T cIneq_size[1], const real_T cEq[240], int32_T mLB,
  const real_T lb[321], int32_T mUB, const real_T ub[321], int32_T mFixed);
void updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[321],
  j_struct_T *WorkingSet, int32_T mIneq, const real_T cIneq_data[], const
  int32_T cIneq_size[1], const real_T cEq[240], int32_T mLB, const real_T lb[321],
  int32_T mUB, const real_T ub[321], int32_T mFixed);

/* End of code generation (updateWorkingSetForNewQP.h) */
