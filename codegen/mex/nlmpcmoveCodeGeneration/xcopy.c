/*
 * xcopy.c
 *
 * Code generation for function 'xcopy'
 *
 */

/* Include files */
#include "xcopy.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_xcopy(int32_T n, const real_T x_data[], real_T y_data[], int32_T iy0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dcopy(&n_t, &x_data[0], &incx_t, &y_data[iy0 - 1], &incy_t);
}

void c_xcopy(int32_T n, const real_T x_data[], real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  if (n >= 1) {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &x_data[0], &incx_t, &y_data[0], &incy_t);
  }
}

void d_xcopy(int32_T n, const real_T x_data[], int32_T ix0, real_T y_data[],
             int32_T iy0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  if (n >= 1) {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &x_data[ix0 - 1], &incx_t, &y_data[iy0 - 1], &incy_t);
  }
}

void e_xcopy(const emlrtStack *sp, int32_T n, real_T y_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &pc_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  if (0 <= n - 1) {
    memset(&y_data[0], 0, n * sizeof(real_T));
  }
}

void f_xcopy(int32_T n, const real_T x_data[], int32_T ix0, real_T y_data[],
             int32_T iy0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dcopy(&n_t, &x_data[ix0 - 1], &incx_t, &y_data[iy0 - 1], &incy_t);
}

void g_xcopy(int32_T n, const real_T x_data[], int32_T ix0, real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dcopy(&n_t, &x_data[ix0 - 1], &incx_t, &y_data[0], &incy_t);
}

void h_xcopy(const emlrtStack *sp, int32_T n, real_T y[58081], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &pc_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  if (0 <= n - 1) {
    memset(&y[iy0 + -1], 0, ((n + iy0) - iy0) * sizeof(real_T));
  }
}

void xcopy(const emlrtStack *sp, int32_T n, const real_T x[241], real_T y_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &pc_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  if (0 <= n - 1) {
    memcpy(&y_data[0], &x[0], n * sizeof(real_T));
  }
}

/* End of code generation (xcopy.c) */
