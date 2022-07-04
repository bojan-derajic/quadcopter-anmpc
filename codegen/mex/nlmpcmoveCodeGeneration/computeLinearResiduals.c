/*
 * computeLinearResiduals.c
 *
 * Code generation for function 'computeLinearResiduals'
 *
 */

/* Include files */
#include "computeLinearResiduals.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_computeLinearResiduals(const real_T x[241], int32_T nVar, real_T
  workspaceIneq_data[], int32_T workspaceIneq_size[1], int32_T mLinIneq, const
  real_T AineqT_data[], const real_T bineq_data[], int32_T ldAi)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T y_data[1743];
  real_T alpha1;
  real_T beta1;
  int32_T loop_ub;
  int32_T y_size_idx_0;
  char_T TRANSA;
  if (mLinIneq > 0) {
    y_size_idx_0 = workspaceIneq_size[0];
    loop_ub = workspaceIneq_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&y_data[0], &workspaceIneq_data[0], loop_ub * sizeof(real_T));
    }

    n_t = (ptrdiff_t)mLinIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &bineq_data[0], &incx_t, &y_data[0], &incy_t);
    workspaceIneq_size[0] = y_size_idx_0;
    if (0 <= y_size_idx_0 - 1) {
      memcpy(&workspaceIneq_data[0], &y_data[0], y_size_idx_0 * sizeof(real_T));
    }

    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mLinIneq;
    lda_t = (ptrdiff_t)ldAi;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &AineqT_data[0], &lda_t, &x[0], &incx_t,
          &beta1, &workspaceIneq_data[0], &incy_t);
  }
}

void computeLinearResiduals(const real_T x[241], real_T workspaceIneq_data[],
  int32_T workspaceIneq_size[1], int32_T mLinIneq, const real_T AineqT_data[],
  const real_T bineq_data[], int32_T ldAi)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T y_data[1743];
  real_T alpha1;
  real_T beta1;
  int32_T loop_ub;
  int32_T y_size_idx_0;
  char_T TRANSA;
  if (mLinIneq > 0) {
    y_size_idx_0 = workspaceIneq_size[0];
    loop_ub = workspaceIneq_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&y_data[0], &workspaceIneq_data[0], loop_ub * sizeof(real_T));
    }

    n_t = (ptrdiff_t)mLinIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &bineq_data[0], &incx_t, &y_data[0], &incy_t);
    workspaceIneq_size[0] = y_size_idx_0;
    if (0 <= y_size_idx_0 - 1) {
      memcpy(&workspaceIneq_data[0], &y_data[0], y_size_idx_0 * sizeof(real_T));
    }

    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)241;
    n_t = (ptrdiff_t)mLinIneq;
    lda_t = (ptrdiff_t)ldAi;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &AineqT_data[0], &lda_t, &x[0], &incx_t,
          &beta1, &workspaceIneq_data[0], &incy_t);
  }
}

/* End of code generation (computeLinearResiduals.c) */
