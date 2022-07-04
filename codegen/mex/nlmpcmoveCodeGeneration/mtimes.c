/*
 * mtimes.c
 *
 * Code generation for function 'mtimes'
 *
 */

/* Include files */
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Function Definitions */
void b_mtimes(const real_T A[144], const real_T B[144], real_T C[144])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)12;
  n_t = (ptrdiff_t)12;
  k_t = (ptrdiff_t)12;
  lda_t = (ptrdiff_t)12;
  ldb_t = (ptrdiff_t)12;
  ldc_t = (ptrdiff_t)12;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A[0], &lda_t, &B[0],
        &ldb_t, &beta1, &C[0], &ldc_t);
}

void c_mtimes(const real_T A[3600], const real_T B[60], real_T C[60])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  TRANSB1 = 'N';
  TRANSA1 = 'T';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)60;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)60;
  lda_t = (ptrdiff_t)60;
  ldb_t = (ptrdiff_t)60;
  ldc_t = (ptrdiff_t)60;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A[0], &lda_t, &B[0],
        &ldb_t, &beta1, &C[0], &ldc_t);
}

void mtimes(const real_T A_data[], const int32_T A_size[2], real_T C_data[],
            int32_T C_size[2])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if (A_size[0] == 0) {
    C_size[0] = 0;
    C_size[1] = 60;
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A_size[0];
    n_t = (ptrdiff_t)60;
    k_t = (ptrdiff_t)60;
    lda_t = (ptrdiff_t)A_size[0];
    ldb_t = (ptrdiff_t)60;
    ldc_t = (ptrdiff_t)A_size[0];
    C_size[0] = A_size[0];
    C_size[1] = 60;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A_data[0], &lda_t,
          &dv[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

/* End of code generation (mtimes.c) */
