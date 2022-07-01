/*
 * computeConstraintsAndUserJacobian_.h
 *
 * Code generation for function 'computeConstraintsAndUserJacobian_'
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
int32_T c_computeConstraintsAndUserJaco(c_nlmpcmoveCodeGenerationStackD *SD,
  const emlrtStack *sp, const real_T c_obj_nonlcon_tunableEnvironmen[12], const
  real_T d_obj_nonlcon_tunableEnvironmen[80], const real_T
  e_obj_nonlcon_tunableEnvironmen[80], int32_T obj_mCineq, const real_T x[321],
  real_T Cineq_workspace_data[], const int32_T Cineq_workspace_size[1], int32_T
  ineq0, real_T Ceq_workspace[240], real_T JacIneqTrans_workspace_data[], const
  int32_T JacIneqTrans_workspace_size[2], int32_T iJI_col, real_T
  JacEqTrans_workspace_data[], const int32_T JacEqTrans_workspace_size[2]);

/* End of code generation (computeConstraintsAndUserJacobian_.h) */
