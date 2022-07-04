/*
 * xcopy.h
 *
 * Code generation for function 'xcopy'
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
void b_xcopy(int32_T n, const real_T x_data[], real_T y_data[], int32_T iy0);
void c_xcopy(int32_T n, const real_T x_data[], real_T y_data[]);
void d_xcopy(int32_T n, const real_T x_data[], int32_T ix0, real_T y_data[],
             int32_T iy0);
void e_xcopy(const emlrtStack *sp, int32_T n, real_T y_data[]);
void f_xcopy(int32_T n, const real_T x_data[], int32_T ix0, real_T y_data[],
             int32_T iy0);
void g_xcopy(int32_T n, const real_T x_data[], int32_T ix0, real_T y_data[]);
void h_xcopy(const emlrtStack *sp, int32_T n, real_T y[103041], int32_T iy0);
void xcopy(const emlrtStack *sp, int32_T n, const real_T x[321], real_T y_data[]);

/* End of code generation (xcopy.h) */
