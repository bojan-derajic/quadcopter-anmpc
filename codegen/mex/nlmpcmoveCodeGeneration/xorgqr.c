/*
 * xorgqr.c
 *
 * Code generation for function 'xorgqr'
 *
 */

/* Include files */
#include "xorgqr.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo ee_emlrtRSI = { 60, /* lineNo */
  "ceval_xorgqr",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xorgqr.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 14, /* lineNo */
  "xorgqr",                            /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xorgqr.m"/* pathName */
};

/* Function Definitions */
void xorgqr(const emlrtStack *sp, int32_T m, int32_T n, int32_T k, real_T
            A_data[], int32_T A_size[2], int32_T lda, const real_T tau_data[])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'o', 'r', 'g', 'q', 'r' };

  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T A_idx_1;
  int32_T i;
  int32_T i1;
  int32_T info;
  boolean_T b_p;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_t = LAPACKE_dorgqr(102, (ptrdiff_t)m, (ptrdiff_t)n, (ptrdiff_t)k,
    &A_data[0], (ptrdiff_t)lda, &tau_data[0]);
  info = (int32_T)info_t;
  b_st.site = &ee_emlrtRSI;
  if (info != 0) {
    p = true;
    b_p = false;
    if (info == -7) {
      b_p = true;
    } else {
      if (info == -5) {
        b_p = true;
      }
    }

    if (!b_p) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
      }
    }
  } else {
    p = false;
  }

  if (p) {
    info = A_size[0];
    A_idx_1 = A_size[1];
    A_size[0] = info;
    A_size[1] = A_idx_1;
    for (i = 0; i < A_idx_1; i++) {
      for (i1 = 0; i1 < info; i1++) {
        A_data[i1 + A_size[0] * i] = rtNaN;
      }
    }
  }
}

/* End of code generation (xorgqr.c) */
