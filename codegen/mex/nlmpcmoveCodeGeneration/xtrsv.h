/*
 * xtrsv.h
 *
 * Code generation for function 'xtrsv'
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
void b_xtrsv(int32_T n, const real_T A_data[], int32_T lda, real_T x_data[]);
void c_xtrsv(int32_T n, const real_T A_data[], int32_T lda, real_T x_data[]);
void xtrsv(int32_T n, const real_T A_data[], int32_T lda, real_T x_data[]);

/* End of code generation (xtrsv.h) */
