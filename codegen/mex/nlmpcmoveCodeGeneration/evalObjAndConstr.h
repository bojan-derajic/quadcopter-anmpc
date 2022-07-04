/*
 * evalObjAndConstr.h
 *
 * Code generation for function 'evalObjAndConstr'
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
void evalObjAndConstr(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
                      const real_T c_obj_objfun_tunableEnvironment[12], const
                      real_T d_obj_objfun_tunableEnvironment[4], const real_T
                      e_obj_objfun_tunableEnvironment[60], const real_T
                      f_obj_objfun_tunableEnvironment[60], const real_T
                      g_obj_objfun_tunableEnvironment[60], const real_T
                      h_obj_objfun_tunableEnvironment[60], const real_T
                      i_obj_objfun_tunableEnvironment[60], const real_T
                      c_obj_nonlcon_tunableEnvironmen[12], const real_T
                      d_obj_nonlcon_tunableEnvironmen[60], const real_T
                      e_obj_nonlcon_tunableEnvironmen[60], int32_T obj_mCineq,
                      const real_T x[241], real_T Cineq_workspace_data[], const
                      int32_T Cineq_workspace_size[1], int32_T ineq0, real_T
                      Ceq_workspace[180], real_T *fval, int32_T *status);

/* End of code generation (evalObjAndConstr.h) */
