/*
 * fmincon.h
 *
 * Code generation for function 'fmincon'
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
void fmincon(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp, const
             f_struct_T *fun_tunableEnvironment_f1, const e_struct_T
             *fun_tunableEnvironment_f2, const real_T x0[241], const real_T
             Aineq_data[], const int32_T Aineq_size[2], const real_T bineq_data[],
             const int32_T bineq_size[1], const real_T lb[241], const real_T ub
             [241], const f_struct_T *nonlcon_tunableEnvironment_f1, const
             e_struct_T *nonlcon_tunableEnvironment_f2, real_T x[241], real_T
             *fval, real_T *exitflag, b_struct_T *output);

/* End of code generation (fmincon.h) */
