/*
 * mtimes.h
 *
 * Code generation for function 'mtimes'
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
void b_mtimes(const real_T A[144], const real_T B[144], real_T C[144]);
void c_mtimes(const real_T A[6400], const real_T B[80], real_T C[80]);
void mtimes(const real_T A_data[], const int32_T A_size[2], real_T C_data[],
            int32_T C_size[2]);

/* End of code generation (mtimes.h) */
