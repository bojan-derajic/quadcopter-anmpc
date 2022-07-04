/*
 * xgemv.h
 *
 * Code generation for function 'xgemv'
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
void b_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], real_T y_data[]);
void c_xgemv(int32_T n, const real_T A_data[], int32_T lda, const real_T x_data[],
             real_T y_data[]);
void d_xgemv(int32_T m, const real_T A_data[], int32_T lda, const real_T x_data[],
             real_T y_data[]);
void e_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], real_T y_data[]);
void f_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], int32_T ix0, real_T y_data[]);
void g_xgemv(int32_T m, const real_T A_data[], int32_T lda, const real_T x_data[],
             int32_T ix0, real_T y_data[]);
void h_xgemv(int32_T m, int32_T n, const real_T A[58081], int32_T lda, const
             real_T x_data[], real_T y_data[]);
void i_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], int32_T ix0, real_T y_data[], int32_T iy0);
void j_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T ia0, int32_T
             lda, const real_T x_data[], real_T y_data[]);
void k_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T ia0, int32_T
             lda, const real_T x_data[], real_T y_data[]);
void l_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], real_T y_data[], int32_T iy0);
void m_xgemv(int32_T m, const real_T A_data[], int32_T lda, const real_T x_data[],
             real_T y[180]);
void n_xgemv(c_nlmpcmoveCodeGenerationStackD *SD, int32_T m, int32_T n, const
             real_T A_data[], int32_T lda, const real_T x_data[], real_T y_data[],
             int32_T y_size[2]);
void xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
           real_T x_data[], real_T y_data[]);

/* End of code generation (xgemv.h) */
