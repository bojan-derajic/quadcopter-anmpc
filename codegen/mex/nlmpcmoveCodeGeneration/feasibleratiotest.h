/*
 * feasibleratiotest.h
 *
 * Code generation for function 'feasibleratiotest'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void feasibleratiotest(const emlrtStack *sp, const real_T solution_xstar_data[],
  const int32_T solution_xstar_size[1], const real_T solution_searchDir_data[],
  const int32_T solution_searchDir_size[1], real_T workspace_data[], const
  int32_T workspace_size[2], int32_T workingset_nVar, int32_T workingset_ldA,
  const real_T workingset_Aineq_data[], const real_T workingset_bineq_data[],
  const real_T workingset_lb_data[], const int32_T workingset_lb_size[1], const
  real_T workingset_ub_data[], const int32_T workingset_indexLB_data[], const
  int32_T workingset_indexLB_size[1], const int32_T workingset_indexUB_data[],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr_data[], const int32_T
  workingset_isActiveConstr_size[1], const int32_T workingset_nWConstr[5],
  boolean_T isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T
  *constrType, int32_T *constrIdx);

/* End of code generation (feasibleratiotest.h) */
