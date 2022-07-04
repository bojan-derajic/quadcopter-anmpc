/*
 * xgemv.c
 *
 * Code generation for function 'xgemv'
 *
 */

/* Include files */
#include "xgemv.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (n >= 1) {
    alpha1 = -1.0;
    beta1 = 1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[0], &incx_t,
          &beta1, &y_data[0], &incy_t);
  }
}

void c_xgemv(int32_T n, const real_T A_data[], int32_T lda, const real_T x_data[],
             real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (n >= 1) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)241;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[0], &incx_t,
          &beta1, &y_data[0], &incy_t);
  }
}

void d_xgemv(int32_T m, const real_T A_data[], int32_T lda, const real_T x_data[],
             real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  alpha1 = 1.0;
  beta1 = -1.0;
  TRANSA = 'T';
  m_t = (ptrdiff_t)m;
  n_t = (ptrdiff_t)180;
  lda_t = (ptrdiff_t)lda;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[0], &incx_t,
        &beta1, &y_data[0], &incy_t);
}

void e_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (n >= 1) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[0], &incx_t,
          &beta1, &y_data[0], &incy_t);
  }
}

void f_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], int32_T ix0, real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (n >= 1) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[ix0 - 1],
          &incx_t, &beta1, &y_data[0], &incy_t);
  }
}

void g_xgemv(int32_T m, const real_T A_data[], int32_T lda, const real_T x_data[],
             int32_T ix0, real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  alpha1 = 1.0;
  beta1 = -1.0;
  TRANSA = 'T';
  m_t = (ptrdiff_t)m;
  n_t = (ptrdiff_t)180;
  lda_t = (ptrdiff_t)lda;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[ix0 - 1],
        &incx_t, &beta1, &y_data[0], &incy_t);
}

void h_xgemv(int32_T m, int32_T n, const real_T A[58081], int32_T lda, const
             real_T x_data[], real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A[0], &lda_t, &x_data[0], &incx_t,
          &beta1, &y_data[0], &incy_t);
  }
}

void i_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], int32_T ix0, real_T y_data[], int32_T iy0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[ix0 - 1],
          &incx_t, &beta1, &y_data[iy0 - 1], &incy_t);
  }
}

void j_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T ia0, int32_T
             lda, const real_T x_data[], real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (m >= 1) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[ia0 - 1], &lda_t, &x_data[0],
          &incx_t, &beta1, &y_data[0], &incy_t);
  }
}

void k_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T ia0, int32_T
             lda, const real_T x_data[], real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (m >= 1) {
    alpha1 = -1.0;
    beta1 = 0.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[ia0 - 1], &lda_t, &x_data[0],
          &incx_t, &beta1, &y_data[0], &incy_t);
  }
}

void l_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
             real_T x_data[], real_T y_data[], int32_T iy0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (n >= 1) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[0], &incx_t,
          &beta1, &y_data[iy0 - 1], &incy_t);
  }
}

void m_xgemv(int32_T m, const real_T A_data[], int32_T lda, const real_T x_data[],
             real_T y[180])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  alpha1 = 1.0;
  beta1 = 1.0;
  TRANSA = 'T';
  m_t = (ptrdiff_t)m;
  n_t = (ptrdiff_t)180;
  lda_t = (ptrdiff_t)lda;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[0], &incx_t,
        &beta1, &y[0], &incy_t);
}

void n_xgemv(c_nlmpcmoveCodeGenerationStackD *SD, int32_T m, int32_T n, const
             real_T A_data[], int32_T lda, const real_T x_data[], real_T y_data[],
             int32_T y_size[2])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  int32_T i;
  int32_T loop_ub;
  int32_T y_size_idx_0;
  int32_T y_size_idx_1;
  char_T TRANSA;
  y_size_idx_0 = y_size[0];
  y_size_idx_1 = y_size[1];
  loop_ub = y_size[0] * y_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&SD->u1.f3.y_data[0], &y_data[0], loop_ub * sizeof(real_T));
  }

  alpha1 = 1.0;
  beta1 = 1.0;
  TRANSA = 'T';
  m_t = (ptrdiff_t)m;
  n_t = (ptrdiff_t)n;
  lda_t = (ptrdiff_t)lda;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[0], &incx_t,
        &beta1, &SD->u1.f3.y_data[0], &incy_t);
  y_size[0] = y_size_idx_0;
  y_size[1] = y_size_idx_1;
  for (loop_ub = 0; loop_ub < y_size_idx_1; loop_ub++) {
    for (i = 0; i < y_size_idx_0; i++) {
      y_data[i + y_size[0] * loop_ub] = SD->u1.f3.y_data[i + y_size_idx_0 *
        loop_ub];
    }
  }
}

void xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T lda, const
           real_T x_data[], real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (m >= 1) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &x_data[0], &incx_t,
          &beta1, &y_data[0], &incy_t);
  }
}

/* End of code generation (xgemv.c) */
