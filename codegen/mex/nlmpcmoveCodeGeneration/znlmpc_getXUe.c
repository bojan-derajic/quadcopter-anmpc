/*
 * znlmpc_getXUe.c
 *
 * Code generation for function 'znlmpc_getXUe'
 *
 */

/* Include files */
#include "znlmpc_getXUe.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void znlmpc_getXUe(const real_T z[241], const real_T x[12], real_T X[192],
                   real_T U[64], real_T *e)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T b_z[180];
  real_T Umv[64];
  real_T b_dv[60];
  real_T alpha1;
  real_T beta1;
  int32_T Umv_tmp;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  memset(&Umv[0], 0, 64U * sizeof(real_T));
  TRANSB1 = 'T';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)60;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)60;
  lda_t = (ptrdiff_t)60;
  ldb_t = (ptrdiff_t)1;
  ldc_t = (ptrdiff_t)60;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &dv[0], &lda_t, &z[180],
        &ldb_t, &beta1, &b_dv[0], &ldc_t);
  for (Umv_tmp = 0; Umv_tmp < 4; Umv_tmp++) {
    for (i = 0; i < 15; i++) {
      Umv[i + (Umv_tmp << 4)] = b_dv[Umv_tmp + (i << 2)];
    }
  }

  *e = z[240];
  memcpy(&b_z[0], &z[0], 180U * sizeof(real_T));
  for (Umv_tmp = 0; Umv_tmp < 12; Umv_tmp++) {
    for (i = 0; i < 15; i++) {
      X[(i + (Umv_tmp << 4)) + 1] = b_z[Umv_tmp + 12 * i];
    }
  }

  for (Umv_tmp = 0; Umv_tmp < 12; Umv_tmp++) {
    X[Umv_tmp << 4] = x[Umv_tmp];
  }

  for (i = 0; i < 4; i++) {
    Umv_tmp = i << 4;
    Umv[Umv_tmp + 15] = Umv[Umv_tmp + 14];
    memcpy(&U[Umv_tmp], &Umv[Umv_tmp], 16U * sizeof(real_T));
  }
}

/* End of code generation (znlmpc_getXUe.c) */
